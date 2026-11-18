#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip  */
void Application::sub_4a087c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a087c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a087d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a087e  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a087f  0fa0                   -push fs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.fs;
    cpu.esp -= 4;
    // 004a0881  0fa8                   -push gs
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.gs;
    cpu.esp -= 4;
    // 004a0883  c84c0100               -enter 0x14c, 0
    {
        cpu.esp -= 4;
        app->getMemory<x86::reg32>(cpu.esp) = cpu.ebp;
        cpu.ebp = cpu.esp;
        cpu.esp -= 332;
    }
    // 004a0887  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0888  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0889  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 004a088c  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a088e  894de8                 -mov dword ptr [ebp - 0x18], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.ecx;
    // 004a0891  a803                   +test al, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 3 /*0x3*/));
    // 004a0893  7407                   -je 0x4a089c
    if (cpu.flags.zf)
    {
        goto L_0x004a089c;
    }
    // 004a0895  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004a089a  eb09                   -jmp 0x4a08a5
    goto L_0x004a08a5;
L_0x004a089c:
    // 004a089c  83fb04                 +cmp ebx, 4
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
    // 004a089f  0f97c0                 -seta al
    cpu.al = (!cpu.flags.cf && !cpu.flags.zf);
    // 004a08a2  0fb6c0                 -movzx eax, al
    cpu.eax = x86::reg32(cpu.al);
L_0x004a08a5:
    // 004a08a5  8945dc                 -mov dword ptr [ebp - 0x24], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.eax;
    // 004a08a8  6b85acfeffff03         -imul eax, dword ptr [ebp - 0x154], 3
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */))) * x86::sreg64(x86::sreg32(3 /*0x3*/)));
    // 004a08af  8945c4                 -mov dword ptr [ebp - 0x3c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.eax;
    // 004a08b2  8b85acfeffff           -mov eax, dword ptr [ebp - 0x154]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 004a08b8  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a08ba  c745e400000000         -mov dword ptr [ebp - 0x1c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = 0 /*0x0*/;
    // 004a08c1  8945bc                 -mov dword ptr [ebp - 0x44], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.eax;
L_0x004a08c4:
    // 004a08c4  83bdb0feffff01         +cmp dword ptr [ebp - 0x150], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a08cb  0f8688000000           -jbe 0x4a0959
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a0959;
    }
    // 004a08d1  83bdb0feffff10         +cmp dword ptr [ebp - 0x150], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a08d8  0f83a7000000           -jae 0x4a0985
    if (!cpu.flags.cf)
    {
        goto L_0x004a0985;
    }
    // 004a08de  8b45c4                 -mov eax, dword ptr [ebp - 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */);
    // 004a08e1  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 004a08e4  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 004a08ea  0faf85acfeffff         -imul eax, dword ptr [ebp - 0x154]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */))));
    // 004a08f1  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a08f4  01c2                   +add edx, eax
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
    // 004a08f6  8955c0                 -mov dword ptr [ebp - 0x40], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.edx;
    // 004a08f9  eb58                   -jmp 0x4a0953
    goto L_0x004a0953;
L_0x004a08fb:
    // 004a08fb  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a08fe  0345e0                 +add eax, dword ptr [ebp - 0x20]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a0901  8945d4                 -mov dword ptr [ebp - 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.eax;
    // 004a0904  eb3f                   -jmp 0x4a0945
    goto L_0x004a0945;
L_0x004a0906:
    // 004a0906  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a0908  eb20                   -jmp 0x4a092a
    goto L_0x004a092a;
L_0x004a090a:
    // 004a090a  837ddc00               +cmp dword ptr [ebp - 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a090e  740f                   -je 0x4a091f
    if (cpu.flags.zf)
    {
        goto L_0x004a091f;
    }
    // 004a0910  8b8dacfeffff           -mov ecx, dword ptr [ebp - 0x154]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 004a0916  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004a0918  e839ffffff             -call 0x4a0856
    cpu.esp -= 4;
    sub_4a0856(app, cpu);
    if (cpu.terminate) return;
    // 004a091d  eb08                   -jmp 0x4a0927
    goto L_0x004a0927;
L_0x004a091f:
    // 004a091f  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 004a0921  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a0923  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 004a0925  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x004a0927:
    // 004a0927  2b5de0                 -sub ebx, dword ptr [ebp - 0x20]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
L_0x004a092a:
    // 004a092a  3b5dfc                 +cmp ebx, dword ptr [ebp - 4]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a092d  7610                   -jbe 0x4a093f
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a093f;
    }
    // 004a092f  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a0931  2b7de0                 -sub edi, dword ptr [ebp - 0x20]
    (cpu.edi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */)));
    // 004a0934  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a0936  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a0938  ff55e8                 -call dword ptr [ebp - 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a093b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a093d  7fcb                   -jg 0x4a090a
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a090a;
    }
L_0x004a093f:
    // 004a093f  8b45e0                 -mov eax, dword ptr [ebp - 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004a0942  0145d4                 -add dword ptr [ebp - 0x2c], eax
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004a0945:
    // 004a0945  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004a0948  3b45c0                 +cmp eax, dword ptr [ebp - 0x40]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a094b  72b9                   -jb 0x4a0906
    if (cpu.flags.cf)
    {
        goto L_0x004a0906;
    }
    // 004a094d  8b45bc                 -mov eax, dword ptr [ebp - 0x44]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */);
    // 004a0950  2945e0                 -sub dword ptr [ebp - 0x20], eax
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */)) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a0953:
    // 004a0953  837de000               +cmp dword ptr [ebp - 0x20], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0957  7fa2                   -jg 0x4a08fb
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a08fb;
    }
L_0x004a0959:
    // 004a0959  837de400               +cmp dword ptr [ebp - 0x1c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a095d  0f843e030000           -je 0x4a0ca1
    if (cpu.flags.zf)
    {
        goto L_0x004a0ca1;
    }
    // 004a0963  ff4de4                 +dec dword ptr [ebp - 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a0966  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004a0969  8b9485b4feffff         -mov edx, dword ptr [ebp + eax*4 - 0x14c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-332) /* -0x14c */ + cpu.eax * 4);
    // 004a0970  8b848534ffffff         -mov eax, dword ptr [ebp + eax*4 - 0xcc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-204) /* -0xcc */ + cpu.eax * 4);
    // 004a0977  8955fc                 -mov dword ptr [ebp - 4], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004a097a  8985b0feffff           -mov dword ptr [ebp - 0x150], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */) = cpu.eax;
    // 004a0980  e93fffffff             -jmp 0x4a08c4
    goto L_0x004a08c4;
L_0x004a0985:
    // 004a0985  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 004a098b  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004a098d  0faf85acfeffff         -imul eax, dword ptr [ebp - 0x154]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */))));
    // 004a0994  8b7dfc                 -mov edi, dword ptr [ebp - 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a0997  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a0999  83bdb0feffff1d         +cmp dword ptr [ebp - 0x150], 0x1d
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(29 /*0x1d*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a09a0  0f8693000000           -jbe 0x4a0a39
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a0a39;
    }
    // 004a09a6  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a09a9  8945c8                 -mov dword ptr [ebp - 0x38], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.eax;
    // 004a09ac  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 004a09b2  48                     -dec eax
    (cpu.eax)--;
    // 004a09b3  0faf85acfeffff         -imul eax, dword ptr [ebp - 0x154]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */))));
    // 004a09ba  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a09bd  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a09bf  83bdb0feffff2a         +cmp dword ptr [ebp - 0x150], 0x2a
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(42 /*0x2a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a09c6  7660                   -jbe 0x4a0a28
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a0a28;
    }
    // 004a09c8  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 004a09ce  8b95acfeffff           -mov edx, dword ptr [ebp - 0x154]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 004a09d4  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004a09d7  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a09da  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a09dd  8955d8                 -mov dword ptr [ebp - 0x28], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.edx;
    // 004a09e0  8d0412                 -lea eax, [edx + edx]
    cpu.eax = x86::reg32(cpu.edx + cpu.edx * 1);
    // 004a09e3  8b4de8                 -mov ecx, dword ptr [ebp - 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004a09e6  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a09e9  8945b8                 -mov dword ptr [ebp - 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
    // 004a09ec  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a09ee  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a09f1  0355d8                 -add edx, dword ptr [ebp - 0x28]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */)));
    // 004a09f4  e812feffff             -call 0x4a080b
    cpu.esp -= 4;
    sub_4a080b(app, cpu);
    if (cpu.terminate) return;
    // 004a09f9  8b5dd8                 -mov ebx, dword ptr [ebp - 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004a09fc  8b4de8                 -mov ecx, dword ptr [ebp - 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004a09ff  8945c8                 -mov dword ptr [ebp - 0x38], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */) = cpu.eax;
    // 004a0a02  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004a0a04  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a0a06  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a0a08  2b45d8                 -sub eax, dword ptr [ebp - 0x28]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */)));
    // 004a0a0b  e8fbfdffff             -call 0x4a080b
    cpu.esp -= 4;
    sub_4a080b(app, cpu);
    if (cpu.terminate) return;
    // 004a0a10  8b4de8                 -mov ecx, dword ptr [ebp - 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004a0a13  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a0a15  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a0a17  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a0a19  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a0a1b  2b55d8                 -sub edx, dword ptr [ebp - 0x28]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */)));
    // 004a0a1e  2b45b8                 -sub eax, dword ptr [ebp - 0x48]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */)));
    // 004a0a21  e8e5fdffff             -call 0x4a080b
    cpu.esp -= 4;
    sub_4a080b(app, cpu);
    if (cpu.terminate) return;
    // 004a0a26  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004a0a28:
    // 004a0a28  8b4de8                 -mov ecx, dword ptr [ebp - 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004a0a2b  8b45c8                 -mov eax, dword ptr [ebp - 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-56) /* -0x38 */);
    // 004a0a2e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 004a0a30  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004a0a32  e8d4fdffff             -call 0x4a080b
    cpu.esp -= 4;
    sub_4a080b(app, cpu);
    if (cpu.terminate) return;
    // 004a0a37  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
L_0x004a0a39:
    // 004a0a39  837ddc00               +cmp dword ptr [ebp - 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0a3d  7424                   -je 0x4a0a63
    if (cpu.flags.zf)
    {
        goto L_0x004a0a63;
    }
    // 004a0a3f  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a0a42  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 004a0a45  740f                   -je 0x4a0a56
    if (cpu.flags.zf)
    {
        goto L_0x004a0a56;
    }
    // 004a0a47  8b8dacfeffff           -mov ecx, dword ptr [ebp - 0x154]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 004a0a4d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a0a4f  e802feffff             -call 0x4a0856
    cpu.esp -= 4;
    sub_4a0856(app, cpu);
    if (cpu.terminate) return;
    // 004a0a54  eb18                   -jmp 0x4a0a6e
    goto L_0x004a0a6e;
L_0x004a0a56:
    // 004a0a56  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a0a59  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a0a5b  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004a0a5d  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a0a5f  8917                   -mov dword ptr [edi], edx
    app->getMemory<x86::reg32>(cpu.edi) = cpu.edx;
    // 004a0a61  eb0b                   -jmp 0x4a0a6e
    goto L_0x004a0a6e;
L_0x004a0a63:
    // 004a0a63  8d45b4                 -lea eax, [ebp - 0x4c]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004a0a66  8945d0                 -mov dword ptr [ebp - 0x30], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.eax;
    // 004a0a69  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004a0a6b  8945b4                 -mov dword ptr [ebp - 0x4c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.eax;
L_0x004a0a6e:
    // 004a0a6e  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 004a0a74  48                     -dec eax
    (cpu.eax)--;
    // 004a0a75  0faf85acfeffff         -imul eax, dword ptr [ebp - 0x154]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */))));
    // 004a0a7c  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a0a7f  895dec                 -mov dword ptr [ebp - 0x14], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.ebx;
    // 004a0a82  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 004a0a85  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 004a0a8b  8955f0                 -mov dword ptr [ebp - 0x10], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.edx;
    // 004a0a8e  8955f8                 -mov dword ptr [ebp - 8], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.edx;
    // 004a0a91  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
L_0x004a0a94:
    // 004a0a94  837df400               +cmp dword ptr [ebp - 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0a98  7448                   -je 0x4a0ae2
    if (cpu.flags.zf)
    {
        goto L_0x004a0ae2;
    }
    // 004a0a9a  8b55d0                 -mov edx, dword ptr [ebp - 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004a0a9d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a0a9f  ff55e8                 -call dword ptr [ebp - 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a0aa2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0aa4  7f3c                   -jg 0x4a0ae2
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a0ae2;
    }
    // 004a0aa6  752f                   -jne 0x4a0ad7
    if (!cpu.flags.zf)
    {
        goto L_0x004a0ad7;
    }
    // 004a0aa8  837ddc00               +cmp dword ptr [ebp - 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0aac  7412                   -je 0x4a0ac0
    if (cpu.flags.zf)
    {
        goto L_0x004a0ac0;
    }
    // 004a0aae  8b8dacfeffff           -mov ecx, dword ptr [ebp - 0x154]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 004a0ab4  8b75ec                 -mov esi, dword ptr [ebp - 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004a0ab7  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a0ab9  e898fdffff             -call 0x4a0856
    cpu.esp -= 4;
    sub_4a0856(app, cpu);
    if (cpu.terminate) return;
    // 004a0abe  eb0e                   -jmp 0x4a0ace
    goto L_0x004a0ace;
L_0x004a0ac0:
    // 004a0ac0  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004a0ac3  8b4dec                 -mov ecx, dword ptr [ebp - 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004a0ac6  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a0ac8  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a0aca  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004a0acc  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
L_0x004a0ace:
    // 004a0ace  8b85acfeffff           -mov eax, dword ptr [ebp - 0x154]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 004a0ad4  0145ec                 -add dword ptr [ebp - 0x14], eax
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004a0ad7:
    // 004a0ad7  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 004a0ada  039dacfeffff           +add ebx, dword ptr [ebp - 0x154]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a0ae0  ebb2                   -jmp 0x4a0a94
    goto L_0x004a0a94;
L_0x004a0ae2:
    // 004a0ae2  837df400               +cmp dword ptr [ebp - 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0ae6  7453                   -je 0x4a0b3b
    if (cpu.flags.zf)
    {
        goto L_0x004a0b3b;
    }
    // 004a0ae8  8b55d0                 -mov edx, dword ptr [ebp - 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004a0aeb  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004a0aee  ff55e8                 -call dword ptr [ebp - 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a0af1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0af3  7c46                   -jl 0x4a0b3b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a0b3b;
    }
    // 004a0af5  7536                   -jne 0x4a0b2d
    if (!cpu.flags.zf)
    {
        goto L_0x004a0b2d;
    }
    // 004a0af7  837ddc00               +cmp dword ptr [ebp - 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0afb  7413                   -je 0x4a0b10
    if (cpu.flags.zf)
    {
        goto L_0x004a0b10;
    }
    // 004a0afd  8b8dacfeffff           -mov ecx, dword ptr [ebp - 0x154]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 004a0b03  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004a0b06  8b75f8                 -mov esi, dword ptr [ebp - 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004a0b09  e848fdffff             -call 0x4a0856
    cpu.esp -= 4;
    sub_4a0856(app, cpu);
    if (cpu.terminate) return;
    // 004a0b0e  eb14                   -jmp 0x4a0b24
    goto L_0x004a0b24;
L_0x004a0b10:
    // 004a0b10  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004a0b13  8b55f8                 -mov edx, dword ptr [ebp - 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004a0b16  8b4df8                 -mov ecx, dword ptr [ebp - 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004a0b19  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a0b1b  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a0b1d  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004a0b1f  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004a0b22  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x004a0b24:
    // 004a0b24  8b85acfeffff           -mov eax, dword ptr [ebp - 0x154]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 004a0b2a  2945f0                 -sub dword ptr [ebp - 0x10], eax
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a0b2d:
    // 004a0b2d  8b85acfeffff           -mov eax, dword ptr [ebp - 0x154]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 004a0b33  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 004a0b36  2945f8                 +sub dword ptr [ebp - 8], eax
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a0b39  eba7                   -jmp 0x4a0ae2
    goto L_0x004a0ae2;
L_0x004a0b3b:
    // 004a0b3b  837df400               +cmp dword ptr [ebp - 0xc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0b3f  7442                   -je 0x4a0b83
    if (cpu.flags.zf)
    {
        goto L_0x004a0b83;
    }
    // 004a0b41  837ddc00               +cmp dword ptr [ebp - 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0b45  7412                   -je 0x4a0b59
    if (cpu.flags.zf)
    {
        goto L_0x004a0b59;
    }
    // 004a0b47  8b8dacfeffff           -mov ecx, dword ptr [ebp - 0x154]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 004a0b4d  8b7df8                 -mov edi, dword ptr [ebp - 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004a0b50  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004a0b52  e8fffcffff             -call 0x4a0856
    cpu.esp -= 4;
    sub_4a0856(app, cpu);
    if (cpu.terminate) return;
    // 004a0b57  eb0e                   -jmp 0x4a0b67
    goto L_0x004a0b67;
L_0x004a0b59:
    // 004a0b59  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004a0b5c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a0b5e  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a0b60  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a0b62  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004a0b65  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
L_0x004a0b67:
    // 004a0b67  039dacfeffff           +add ebx, dword ptr [ebp - 0x154]
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a0b6d  ff4df4                 +dec dword ptr [ebp - 0xc]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a0b70  7411                   -je 0x4a0b83
    if (cpu.flags.zf)
    {
        goto L_0x004a0b83;
    }
    // 004a0b72  8b85acfeffff           -mov eax, dword ptr [ebp - 0x154]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
    // 004a0b78  ff4df4                 -dec dword ptr [ebp - 0xc]
    (app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */))--;
    // 004a0b7b  2945f8                 +sub dword ptr [ebp - 8], eax
    {
        auto tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.eax));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a0b7e  e911ffffff             -jmp 0x4a0a94
    goto L_0x004a0a94;
L_0x004a0b83:
    // 004a0b83  8b85b0feffff           -mov eax, dword ptr [ebp - 0x150]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */);
    // 004a0b89  0faf85acfeffff         -imul eax, dword ptr [ebp - 0x154]
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */))));
    // 004a0b90  8b55fc                 -mov edx, dword ptr [ebp - 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a0b93  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a0b95  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a0b97  8b45ec                 -mov eax, dword ptr [ebp - 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004a0b9a  2b4dec                 -sub ecx, dword ptr [ebp - 0x14]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 004a0b9d  2b45fc                 -sub eax, dword ptr [ebp - 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */)));
    // 004a0ba0  8955cc                 -mov dword ptr [ebp - 0x34], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */) = cpu.edx;
    // 004a0ba3  39c8                   +cmp eax, ecx
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
    // 004a0ba5  7d02                   -jge 0x4a0ba9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0ba9;
    }
    // 004a0ba7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004a0ba9:
    // 004a0ba9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a0bab  762c                   -jbe 0x4a0bd9
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a0bd9;
    }
    // 004a0bad  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a0baf  8b75fc                 -mov esi, dword ptr [ebp - 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a0bb2  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0bb4  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a0bb5  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 004a0bb6  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a0bb7  0fb6d1                 -movzx edx, cl
    cpu.edx = x86::reg32(cpu.cl);
    // 004a0bba  c1e902                 +shr ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004a0bbd  740b                   -je 0x4a0bca
    if (cpu.flags.zf)
    {
        goto L_0x004a0bca;
    }
L_0x004a0bbf:
    // 004a0bbf  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004a0bc1  8706                   -xchg dword ptr [esi], eax
    {
        x86::reg32 tmp = app->getMemory<x86::reg32>(cpu.esi);
        app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
        cpu.eax = tmp;
    }
    // 004a0bc3  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 004a0bc4  83c604                 +add esi, 4
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
    // 004a0bc7  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a0bc8  75f5                   -jne 0x4a0bbf
    if (!cpu.flags.zf)
    {
        goto L_0x004a0bbf;
    }
L_0x004a0bca:
    // 004a0bca  80e203                 +and dl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004a0bcd  7409                   -je 0x4a0bd8
    if (cpu.flags.zf)
    {
        goto L_0x004a0bd8;
    }
L_0x004a0bcf:
    // 004a0bcf  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004a0bd1  8606                   -xchg byte ptr [esi], al
    {
        x86::reg8 tmp = app->getMemory<x86::reg8>(cpu.esi);
        app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
        cpu.al = tmp;
    }
    // 004a0bd3  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 004a0bd4  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a0bd5  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a0bd6  75f7                   -jne 0x4a0bcf
    if (!cpu.flags.zf)
    {
        goto L_0x004a0bcf;
    }
L_0x004a0bd8:
    // 004a0bd8  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x004a0bd9:
    // 004a0bd9  8b45cc                 -mov eax, dword ptr [ebp - 0x34]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004a0bdc  8b4df0                 -mov ecx, dword ptr [ebp - 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004a0bdf  2b45f0                 -sub eax, dword ptr [ebp - 0x10]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */)));
    // 004a0be2  2b4df8                 -sub ecx, dword ptr [ebp - 8]
    (cpu.ecx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004a0be5  2b85acfeffff           -sub eax, dword ptr [ebp - 0x154]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */)));
    // 004a0beb  39c1                   +cmp ecx, eax
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
    // 004a0bed  7202                   -jb 0x4a0bf1
    if (cpu.flags.cf)
    {
        goto L_0x004a0bf1;
    }
    // 004a0bef  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_0x004a0bf1:
    // 004a0bf1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a0bf3  762c                   -jbe 0x4a0c21
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a0c21;
    }
    // 004a0bf5  8b7dcc                 -mov edi, dword ptr [ebp - 0x34]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004a0bf8  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004a0bfa  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0bfc  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004a0bfd  1e                     -push ds
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.ds;
    cpu.esp -= 4;
    // 004a0bfe  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004a0bff  0fb6d1                 -movzx edx, cl
    cpu.edx = x86::reg32(cpu.cl);
    // 004a0c02  c1e902                 +shr ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = (1 & (op >> (32 - 1)));
            cpu.set_szp((op >>= tmp));
        }
    }
    // 004a0c05  740b                   -je 0x4a0c12
    if (cpu.flags.zf)
    {
        goto L_0x004a0c12;
    }
L_0x004a0c07:
    // 004a0c07  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004a0c09  8706                   -xchg dword ptr [esi], eax
    {
        x86::reg32 tmp = app->getMemory<x86::reg32>(cpu.esi);
        app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
        cpu.eax = tmp;
    }
    // 004a0c0b  ab                     -stosd dword ptr es:[edi], eax
    app->getMemory<x86::reg32>(cpu.ees + cpu.edi) = cpu.eax;
    if (cpu.flags.df)
    {
        cpu.edi -= 4;
    }
    else
    {
        cpu.edi += 4;
    }
    // 004a0c0c  83c604                 +add esi, 4
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
    // 004a0c0f  49                     +dec ecx
    {
        x86::reg32& tmp = cpu.ecx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a0c10  75f5                   -jne 0x4a0c07
    if (!cpu.flags.zf)
    {
        goto L_0x004a0c07;
    }
L_0x004a0c12:
    // 004a0c12  80e203                 +and dl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.dl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004a0c15  7409                   -je 0x4a0c20
    if (cpu.flags.zf)
    {
        goto L_0x004a0c20;
    }
L_0x004a0c17:
    // 004a0c17  8a07                   -mov al, byte ptr [edi]
    cpu.al = app->getMemory<x86::reg8>(cpu.edi);
    // 004a0c19  8606                   -xchg byte ptr [esi], al
    {
        x86::reg8 tmp = app->getMemory<x86::reg8>(cpu.esi);
        app->getMemory<x86::reg8>(cpu.esi) = cpu.al;
        cpu.al = tmp;
    }
    // 004a0c1b  aa                     -stosb byte ptr es:[edi], al
    app->getMemory<x86::reg8>(cpu.ees + cpu.edi) = cpu.al;
    if (cpu.flags.df)
    {
        cpu.edi -= 1;
    }
    else
    {
        cpu.edi += 1;
    }
    // 004a0c1c  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a0c1d  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a0c1e  75f7                   -jne 0x4a0c17
    if (!cpu.flags.zf)
    {
        goto L_0x004a0c17;
    }
L_0x004a0c20:
    // 004a0c20  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x004a0c21:
    // 004a0c21  8b7df0                 -mov edi, dword ptr [ebp - 0x10]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004a0c24  8b4dcc                 -mov ecx, dword ptr [ebp - 0x34]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-52) /* -0x34 */);
    // 004a0c27  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004a0c29  8b5de4                 -mov ebx, dword ptr [ebp - 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004a0c2c  2b75ec                 -sub esi, dword ptr [ebp - 0x14]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */)));
    // 004a0c2f  2b7df8                 -sub edi, dword ptr [ebp - 8]
    (cpu.edi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */)));
    // 004a0c32  c1e302                 -shl ebx, 2
    cpu.ebx <<= 2 /*0x2*/ % 32;
    // 004a0c35  29f9                   -sub ecx, edi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004a0c37  39f7                   +cmp edi, esi
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
    // 004a0c39  7224                   -jb 0x4a0c5f
    if (cpu.flags.cf)
    {
        goto L_0x004a0c5f;
    }
    // 004a0c3b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a0c3d  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0c3f  f7b5acfeffff           -div dword ptr [ebp - 0x154]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a0c45  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0c47  89842b34ffffff         -mov dword ptr [ebx + ebp - 0xcc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-204) /* -0xcc */ + cpu.ebp * 1) = cpu.eax;
    // 004a0c4e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a0c50  f7b5acfeffff           +div dword ptr [ebp - 0x154]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a0c56  898c2bb4feffff         -mov dword ptr [ebx + ebp - 0x14c], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-332) /* -0x14c */ + cpu.ebp * 1) = cpu.ecx;
    // 004a0c5d  eb34                   -jmp 0x4a0c93
    goto L_0x004a0c93;
L_0x004a0c5f:
    // 004a0c5f  3bb5acfeffff           +cmp esi, dword ptr [ebp - 0x154]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0c65  0f86eefcffff           -jbe 0x4a0959
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a0959;
    }
    // 004a0c6b  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004a0c6e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0c70  89842bb4feffff         -mov dword ptr [ebx + ebp - 0x14c], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-332) /* -0x14c */ + cpu.ebp * 1) = cpu.eax;
    // 004a0c77  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a0c79  f7b5acfeffff           -div dword ptr [ebp - 0x154]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a0c7f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0c81  89842b34ffffff         -mov dword ptr [ebx + ebp - 0xcc], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(-204) /* -0xcc */ + cpu.ebp * 1) = cpu.eax;
    // 004a0c88  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a0c8a  f7b5acfeffff           +div dword ptr [ebp - 0x154]
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-340) /* -0x154 */);
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a0c90  894dfc                 -mov dword ptr [ebp - 4], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.ecx;
L_0x004a0c93:
    // 004a0c93  8985b0feffff           -mov dword ptr [ebp - 0x150], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-336) /* -0x150 */) = cpu.eax;
    // 004a0c99  ff45e4                 +inc dword ptr [ebp - 0x1c]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004a0c9c  e923fcffff             -jmp 0x4a08c4
    goto L_0x004a08c4;
L_0x004a0ca1:
    // 004a0ca1  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0ca2  e9a7fbffff             -jmp 0x4a084e
    return sub_4a084e(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a0cb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0cb0  a1440e5700             -mov eax, dword ptr [0x570e44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */);
    // 004a0cb5  a364ab4d00             -mov dword ptr [0x4dab64], eax
    app->getMemory<x86::reg32>(x86::reg32(5090148) /* 0x4dab64 */) = cpu.eax;
    // 004a0cba  a1400e5700             -mov eax, dword ptr [0x570e40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705280) /* 0x570e40 */);
    // 004a0cbf  a368ab4d00             -mov dword ptr [0x4dab68], eax
    app->getMemory<x86::reg32>(x86::reg32(5090152) /* 0x4dab68 */) = cpu.eax;
    // 004a0cc4  a15c0e5700             -mov eax, dword ptr [0x570e5c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705308) /* 0x570e5c */);
    // 004a0cc9  a36cab4d00             -mov dword ptr [0x4dab6c], eax
    app->getMemory<x86::reg32>(x86::reg32(5090156) /* 0x4dab6c */) = cpu.eax;
    // 004a0cce  a16cab4d00             -mov eax, dword ptr [0x4dab6c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090156) /* 0x4dab6c */);
    // 004a0cd3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0cd4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0cd4  ff05500e5700           -inc dword ptr [0x570e50]
    (app->getMemory<x86::reg32>(x86::reg32(5705296) /* 0x570e50 */))++;
    // 004a0cda  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a0cdc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0cdc  ff0d500e5700           -dec dword ptr [0x570e50]
    (app->getMemory<x86::reg32>(x86::reg32(5705296) /* 0x570e50 */))--;
    // 004a0ce2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a0ce4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  app->traceEntry(0x004a0ce4, cpu);
    // 004a0ce4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0ce5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0ce6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0ce7  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a0cec  bfdc0c4a00             -mov edi, 0x4a0cdc
    cpu.edi = 4852956 /*0x4a0cdc*/;
    // 004a0cf1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0cf3  a17cab4d00             -mov eax, dword ptr [0x4dab7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090172) /* 0x4dab7c */);
    // 004a0cf8  8915540e5700           -mov dword ptr [0x570e54], edx
    app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */) = cpu.edx;
    // 004a0cfe  a34c0e5700             -mov dword ptr [0x570e4c], eax
    app->getMemory<x86::reg32>(x86::reg32(5705292) /* 0x570e4c */) = cpu.eax;
    // 004a0d03  8915580e5700           -mov dword ptr [0x570e58], edx
    app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */) = cpu.edx;
    // 004a0d09  8915500e5700           -mov dword ptr [0x570e50], edx
    app->getMemory<x86::reg32>(x86::reg32(5705296) /* 0x570e50 */) = cpu.edx;
    // 004a0d0f  893560ab4d00           -mov dword ptr [0x4dab60], esi
    app->getMemory<x86::reg32>(x86::reg32(5090144) /* 0x4dab60 */) = cpu.esi;
    // 004a0d15  893d3cac4d00           -mov dword ptr [0x4dac3c], edi
    app->getMemory<x86::reg32>(x86::reg32(5090364) /* 0x4dac3c */) = cpu.edi;
    // 004a0d1b  893d40ac4d00           -mov dword ptr [0x4dac40], edi
    app->getMemory<x86::reg32>(x86::reg32(5090368) /* 0x4dac40 */) = cpu.edi;
    // 004a0d21  a180ab4d00             -mov eax, dword ptr [0x4dab80]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090176) /* 0x4dab80 */);
    // 004a0d26  bab00c4a00             -mov edx, 0x4a0cb0
    cpu.edx = 4852912 /*0x4a0cb0*/;
    // 004a0d2b  a3480e5700             -mov dword ptr [0x570e48], eax
    app->getMemory<x86::reg32>(x86::reg32(5705288) /* 0x570e48 */) = cpu.eax;
    // 004a0d30  b8d40c4a00             -mov eax, 0x4a0cd4
    cpu.eax = 4852948 /*0x4a0cd4*/;
    // 004a0d35  891548ac4d00           -mov dword ptr [0x4dac48], edx
    app->getMemory<x86::reg32>(x86::reg32(5090376) /* 0x4dac48 */) = cpu.edx;
    // 004a0d3b  a344ac4d00             -mov dword ptr [0x4dac44], eax
    app->getMemory<x86::reg32>(x86::reg32(5090372) /* 0x4dac44 */) = cpu.eax;
    // 004a0d40  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a0d42  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0d43  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0d44  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0d45  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a0d48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0d48  a3540e5700             -mov dword ptr [0x570e54], eax
    app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */) = cpu.eax;
    // 004a0d4d  8915580e5700           -mov dword ptr [0x570e58], edx
    app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */) = cpu.edx;
    // 004a0d53  891d4c0e5700           -mov dword ptr [0x570e4c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5705292) /* 0x570e4c */) = cpu.ebx;
    // 004a0d59  890d480e5700           -mov dword ptr [0x570e48], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705288) /* 0x570e48 */) = cpu.ecx;
    // 004a0d5f  8b1d5c0e5700           -mov ebx, dword ptr [0x570e5c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705308) /* 0x570e5c */);
    // 004a0d65  8b15400e5700           -mov edx, dword ptr [0x570e40]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5705280) /* 0x570e40 */);
    // 004a0d6b  a1440e5700             -mov eax, dword ptr [0x570e44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */);
    // 004a0d70  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0d72  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004a0d74  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0d75  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0d76  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0d77  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0d7a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a0d7c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004a0d7e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a0d81  833d60ab4d0000         +cmp dword ptr [0x4dab60], 0
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
    // 004a0d88  0f84c3000000           -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0d8e  833d38ab4d0000         +cmp dword ptr [0x4dab38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0d95  0f84b6000000           -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0d9b  8b3d540e5700           -mov edi, dword ptr [0x570e54]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */);
    // 004a0da1  39f8                   +cmp eax, edi
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
    // 004a0da3  0f8ede010000           -jle 0x4a0f87
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f87(app, cpu);
    }
    // 004a0da9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0dab  a14c0e5700             -mov eax, dword ptr [0x570e4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705292) /* 0x570e4c */);
    // 004a0db0  39c1                   +cmp ecx, eax
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
    // 004a0db2  7d10                   -jge 0x4a0dc4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0dc4;
    }
    // 004a0db4  8b0d540e5700           -mov ecx, dword ptr [0x570e54]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */);
    // 004a0dba  39ce                   +cmp esi, ecx
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
    // 004a0dbc  0f8ecc010000           -jle 0x4a0f8e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f8e(app, cpu);
    }
    // 004a0dc2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004a0dc4:
    // 004a0dc4  8b1d580e5700           -mov ebx, dword ptr [0x570e58]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */);
    // 004a0dca  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0dcc  39da                   +cmp edx, ebx
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
    // 004a0dce  0f8ec1010000           -jle 0x4a0f95
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f95(app, cpu);
    }
    // 004a0dd4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0dd6  8b3d480e5700           -mov edi, dword ptr [0x570e48]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705288) /* 0x570e48 */);
    // 004a0ddc  39f8                   +cmp eax, edi
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
    // 004a0dde  0f8dbf010000           -jge 0x4a0fa3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4a0fa3(app, cpu);
    }
    // 004a0de4  a1580e5700             -mov eax, dword ptr [0x570e58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */);
    // 004a0de9  39c2                   +cmp edx, eax
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
    // 004a0deb  0f8eab010000           -jle 0x4a0f9c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f9c(app, cpu);
    }
    // 004a0df1  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a0df3  a138ab4d00             -mov eax, dword ptr [0x4dab38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 004a0df8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a0dfa  e84991feff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004a0dff  892d5c0e5700           -mov dword ptr [0x570e5c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5705308) /* 0x570e5c */) = cpu.ebp;
    // 004a0e05  39f1                   +cmp ecx, esi
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
    // 004a0e07  0f849d010000           -je 0x4a0faa
    if (cpu.flags.zf)
    {
        return sub_4a0faa(app, cpu);
    }
    // 004a0e0d  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
    // 004a0e12  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004a0e14  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a0e16  e83513feff             -call 0x482150
    cpu.esp -= 4;
    sub_482150(app, cpu);
    if (cpu.terminate) return;
    // 004a0e1b  3b0d440e5700           +cmp ecx, dword ptr [0x570e44]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0e21  0f8490010000           -je 0x4a0fb7
    if (cpu.flags.zf)
    {
        return sub_4a0fb7(app, cpu);
    }
    // 004a0e27  890d440e5700           -mov dword ptr [0x570e44], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */) = cpu.ecx;
    // 004a0e2d  893d400e5700           -mov dword ptr [0x570e40], edi
    app->getMemory<x86::reg32>(x86::reg32(5705280) /* 0x570e40 */) = cpu.edi;
    // 004a0e33  a138ab4d00             -mov eax, dword ptr [0x4dab38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 004a0e38  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004a0e3b  e82091feff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004a0e40  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a0e42  740d                   -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0e44  833d4cac4d0000         +cmp dword ptr [0x4dac4c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090380) /* 0x4dac4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0e4b  0f8577010000           -jne 0x4a0fc8
    if (!cpu.flags.zf)
    {
        return sub_4a0fc8(app, cpu);
    }
L_0x004a0e51:
    // 004a0e51  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0e54  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e55  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0df3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a0df3;
    // 004a0d48  a3540e5700             -mov dword ptr [0x570e54], eax
    app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */) = cpu.eax;
    // 004a0d4d  8915580e5700           -mov dword ptr [0x570e58], edx
    app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */) = cpu.edx;
    // 004a0d53  891d4c0e5700           -mov dword ptr [0x570e4c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5705292) /* 0x570e4c */) = cpu.ebx;
    // 004a0d59  890d480e5700           -mov dword ptr [0x570e48], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705288) /* 0x570e48 */) = cpu.ecx;
    // 004a0d5f  8b1d5c0e5700           -mov ebx, dword ptr [0x570e5c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705308) /* 0x570e5c */);
    // 004a0d65  8b15400e5700           -mov edx, dword ptr [0x570e40]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5705280) /* 0x570e40 */);
    // 004a0d6b  a1440e5700             -mov eax, dword ptr [0x570e44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */);
    // 004a0d70  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0d72  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004a0d74  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0d75  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0d76  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0d77  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0d7a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a0d7c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004a0d7e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a0d81  833d60ab4d0000         +cmp dword ptr [0x4dab60], 0
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
    // 004a0d88  0f84c3000000           -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0d8e  833d38ab4d0000         +cmp dword ptr [0x4dab38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0d95  0f84b6000000           -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0d9b  8b3d540e5700           -mov edi, dword ptr [0x570e54]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */);
    // 004a0da1  39f8                   +cmp eax, edi
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
    // 004a0da3  0f8ede010000           -jle 0x4a0f87
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f87(app, cpu);
    }
    // 004a0da9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0dab  a14c0e5700             -mov eax, dword ptr [0x570e4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705292) /* 0x570e4c */);
    // 004a0db0  39c1                   +cmp ecx, eax
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
    // 004a0db2  7d10                   -jge 0x4a0dc4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0dc4;
    }
    // 004a0db4  8b0d540e5700           -mov ecx, dword ptr [0x570e54]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */);
    // 004a0dba  39ce                   +cmp esi, ecx
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
    // 004a0dbc  0f8ecc010000           -jle 0x4a0f8e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f8e(app, cpu);
    }
    // 004a0dc2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004a0dc4:
    // 004a0dc4  8b1d580e5700           -mov ebx, dword ptr [0x570e58]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */);
    // 004a0dca  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0dcc  39da                   +cmp edx, ebx
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
    // 004a0dce  0f8ec1010000           -jle 0x4a0f95
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f95(app, cpu);
    }
    // 004a0dd4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0dd6  8b3d480e5700           -mov edi, dword ptr [0x570e48]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705288) /* 0x570e48 */);
    // 004a0ddc  39f8                   +cmp eax, edi
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
    // 004a0dde  0f8dbf010000           -jge 0x4a0fa3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4a0fa3(app, cpu);
    }
    // 004a0de4  a1580e5700             -mov eax, dword ptr [0x570e58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */);
    // 004a0de9  39c2                   +cmp edx, eax
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
    // 004a0deb  0f8eab010000           -jle 0x4a0f9c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f9c(app, cpu);
    }
    // 004a0df1  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_entry_0x004a0df3:
    // 004a0df3  a138ab4d00             -mov eax, dword ptr [0x4dab38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 004a0df8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a0dfa  e84991feff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004a0dff  892d5c0e5700           -mov dword ptr [0x570e5c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5705308) /* 0x570e5c */) = cpu.ebp;
    // 004a0e05  39f1                   +cmp ecx, esi
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
    // 004a0e07  0f849d010000           -je 0x4a0faa
    if (cpu.flags.zf)
    {
        return sub_4a0faa(app, cpu);
    }
    // 004a0e0d  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
    // 004a0e12  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004a0e14  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a0e16  e83513feff             -call 0x482150
    cpu.esp -= 4;
    sub_482150(app, cpu);
    if (cpu.terminate) return;
    // 004a0e1b  3b0d440e5700           +cmp ecx, dword ptr [0x570e44]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0e21  0f8490010000           -je 0x4a0fb7
    if (cpu.flags.zf)
    {
        return sub_4a0fb7(app, cpu);
    }
    // 004a0e27  890d440e5700           -mov dword ptr [0x570e44], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */) = cpu.ecx;
    // 004a0e2d  893d400e5700           -mov dword ptr [0x570e40], edi
    app->getMemory<x86::reg32>(x86::reg32(5705280) /* 0x570e40 */) = cpu.edi;
    // 004a0e33  a138ab4d00             -mov eax, dword ptr [0x4dab38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 004a0e38  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004a0e3b  e82091feff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004a0e40  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a0e42  740d                   -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0e44  833d4cac4d0000         +cmp dword ptr [0x4dac4c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090380) /* 0x4dac4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0e4b  0f8577010000           -jne 0x4a0fc8
    if (!cpu.flags.zf)
    {
        return sub_4a0fc8(app, cpu);
    }
L_0x004a0e51:
    // 004a0e51  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0e54  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e55  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0dd6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a0dd6;
    // 004a0d48  a3540e5700             -mov dword ptr [0x570e54], eax
    app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */) = cpu.eax;
    // 004a0d4d  8915580e5700           -mov dword ptr [0x570e58], edx
    app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */) = cpu.edx;
    // 004a0d53  891d4c0e5700           -mov dword ptr [0x570e4c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5705292) /* 0x570e4c */) = cpu.ebx;
    // 004a0d59  890d480e5700           -mov dword ptr [0x570e48], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705288) /* 0x570e48 */) = cpu.ecx;
    // 004a0d5f  8b1d5c0e5700           -mov ebx, dword ptr [0x570e5c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705308) /* 0x570e5c */);
    // 004a0d65  8b15400e5700           -mov edx, dword ptr [0x570e40]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5705280) /* 0x570e40 */);
    // 004a0d6b  a1440e5700             -mov eax, dword ptr [0x570e44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */);
    // 004a0d70  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0d72  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004a0d74  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0d75  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0d76  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0d77  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0d7a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a0d7c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004a0d7e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a0d81  833d60ab4d0000         +cmp dword ptr [0x4dab60], 0
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
    // 004a0d88  0f84c3000000           -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0d8e  833d38ab4d0000         +cmp dword ptr [0x4dab38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0d95  0f84b6000000           -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0d9b  8b3d540e5700           -mov edi, dword ptr [0x570e54]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */);
    // 004a0da1  39f8                   +cmp eax, edi
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
    // 004a0da3  0f8ede010000           -jle 0x4a0f87
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f87(app, cpu);
    }
    // 004a0da9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0dab  a14c0e5700             -mov eax, dword ptr [0x570e4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705292) /* 0x570e4c */);
    // 004a0db0  39c1                   +cmp ecx, eax
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
    // 004a0db2  7d10                   -jge 0x4a0dc4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0dc4;
    }
    // 004a0db4  8b0d540e5700           -mov ecx, dword ptr [0x570e54]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */);
    // 004a0dba  39ce                   +cmp esi, ecx
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
    // 004a0dbc  0f8ecc010000           -jle 0x4a0f8e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f8e(app, cpu);
    }
    // 004a0dc2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004a0dc4:
    // 004a0dc4  8b1d580e5700           -mov ebx, dword ptr [0x570e58]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */);
    // 004a0dca  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0dcc  39da                   +cmp edx, ebx
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
    // 004a0dce  0f8ec1010000           -jle 0x4a0f95
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f95(app, cpu);
    }
    // 004a0dd4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_entry_0x004a0dd6:
    // 004a0dd6  8b3d480e5700           -mov edi, dword ptr [0x570e48]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705288) /* 0x570e48 */);
    // 004a0ddc  39f8                   +cmp eax, edi
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
    // 004a0dde  0f8dbf010000           -jge 0x4a0fa3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4a0fa3(app, cpu);
    }
    // 004a0de4  a1580e5700             -mov eax, dword ptr [0x570e58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */);
    // 004a0de9  39c2                   +cmp edx, eax
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
    // 004a0deb  0f8eab010000           -jle 0x4a0f9c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f9c(app, cpu);
    }
    // 004a0df1  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a0df3  a138ab4d00             -mov eax, dword ptr [0x4dab38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 004a0df8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a0dfa  e84991feff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004a0dff  892d5c0e5700           -mov dword ptr [0x570e5c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5705308) /* 0x570e5c */) = cpu.ebp;
    // 004a0e05  39f1                   +cmp ecx, esi
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
    // 004a0e07  0f849d010000           -je 0x4a0faa
    if (cpu.flags.zf)
    {
        return sub_4a0faa(app, cpu);
    }
    // 004a0e0d  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
    // 004a0e12  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004a0e14  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a0e16  e83513feff             -call 0x482150
    cpu.esp -= 4;
    sub_482150(app, cpu);
    if (cpu.terminate) return;
    // 004a0e1b  3b0d440e5700           +cmp ecx, dword ptr [0x570e44]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0e21  0f8490010000           -je 0x4a0fb7
    if (cpu.flags.zf)
    {
        return sub_4a0fb7(app, cpu);
    }
    // 004a0e27  890d440e5700           -mov dword ptr [0x570e44], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */) = cpu.ecx;
    // 004a0e2d  893d400e5700           -mov dword ptr [0x570e40], edi
    app->getMemory<x86::reg32>(x86::reg32(5705280) /* 0x570e40 */) = cpu.edi;
    // 004a0e33  a138ab4d00             -mov eax, dword ptr [0x4dab38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 004a0e38  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004a0e3b  e82091feff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004a0e40  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a0e42  740d                   -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0e44  833d4cac4d0000         +cmp dword ptr [0x4dac4c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090380) /* 0x4dac4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0e4b  0f8577010000           -jne 0x4a0fc8
    if (!cpu.flags.zf)
    {
        return sub_4a0fc8(app, cpu);
    }
L_0x004a0e51:
    // 004a0e51  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0e54  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e55  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0dc4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a0dc4;
    // 004a0d48  a3540e5700             -mov dword ptr [0x570e54], eax
    app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */) = cpu.eax;
    // 004a0d4d  8915580e5700           -mov dword ptr [0x570e58], edx
    app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */) = cpu.edx;
    // 004a0d53  891d4c0e5700           -mov dword ptr [0x570e4c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5705292) /* 0x570e4c */) = cpu.ebx;
    // 004a0d59  890d480e5700           -mov dword ptr [0x570e48], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705288) /* 0x570e48 */) = cpu.ecx;
    // 004a0d5f  8b1d5c0e5700           -mov ebx, dword ptr [0x570e5c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705308) /* 0x570e5c */);
    // 004a0d65  8b15400e5700           -mov edx, dword ptr [0x570e40]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5705280) /* 0x570e40 */);
    // 004a0d6b  a1440e5700             -mov eax, dword ptr [0x570e44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */);
    // 004a0d70  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0d72  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004a0d74  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0d75  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0d76  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0d77  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0d7a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a0d7c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004a0d7e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a0d81  833d60ab4d0000         +cmp dword ptr [0x4dab60], 0
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
    // 004a0d88  0f84c3000000           -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0d8e  833d38ab4d0000         +cmp dword ptr [0x4dab38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0d95  0f84b6000000           -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0d9b  8b3d540e5700           -mov edi, dword ptr [0x570e54]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */);
    // 004a0da1  39f8                   +cmp eax, edi
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
    // 004a0da3  0f8ede010000           -jle 0x4a0f87
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f87(app, cpu);
    }
    // 004a0da9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0dab  a14c0e5700             -mov eax, dword ptr [0x570e4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705292) /* 0x570e4c */);
    // 004a0db0  39c1                   +cmp ecx, eax
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
    // 004a0db2  7d10                   -jge 0x4a0dc4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0dc4;
    }
    // 004a0db4  8b0d540e5700           -mov ecx, dword ptr [0x570e54]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */);
    // 004a0dba  39ce                   +cmp esi, ecx
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
    // 004a0dbc  0f8ecc010000           -jle 0x4a0f8e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f8e(app, cpu);
    }
    // 004a0dc2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004a0dc4:
L_entry_0x004a0dc4:
    // 004a0dc4  8b1d580e5700           -mov ebx, dword ptr [0x570e58]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */);
    // 004a0dca  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0dcc  39da                   +cmp edx, ebx
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
    // 004a0dce  0f8ec1010000           -jle 0x4a0f95
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f95(app, cpu);
    }
    // 004a0dd4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0dd6  8b3d480e5700           -mov edi, dword ptr [0x570e48]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705288) /* 0x570e48 */);
    // 004a0ddc  39f8                   +cmp eax, edi
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
    // 004a0dde  0f8dbf010000           -jge 0x4a0fa3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4a0fa3(app, cpu);
    }
    // 004a0de4  a1580e5700             -mov eax, dword ptr [0x570e58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */);
    // 004a0de9  39c2                   +cmp edx, eax
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
    // 004a0deb  0f8eab010000           -jle 0x4a0f9c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f9c(app, cpu);
    }
    // 004a0df1  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a0df3  a138ab4d00             -mov eax, dword ptr [0x4dab38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 004a0df8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a0dfa  e84991feff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004a0dff  892d5c0e5700           -mov dword ptr [0x570e5c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5705308) /* 0x570e5c */) = cpu.ebp;
    // 004a0e05  39f1                   +cmp ecx, esi
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
    // 004a0e07  0f849d010000           -je 0x4a0faa
    if (cpu.flags.zf)
    {
        return sub_4a0faa(app, cpu);
    }
    // 004a0e0d  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
    // 004a0e12  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004a0e14  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a0e16  e83513feff             -call 0x482150
    cpu.esp -= 4;
    sub_482150(app, cpu);
    if (cpu.terminate) return;
    // 004a0e1b  3b0d440e5700           +cmp ecx, dword ptr [0x570e44]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0e21  0f8490010000           -je 0x4a0fb7
    if (cpu.flags.zf)
    {
        return sub_4a0fb7(app, cpu);
    }
    // 004a0e27  890d440e5700           -mov dword ptr [0x570e44], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */) = cpu.ecx;
    // 004a0e2d  893d400e5700           -mov dword ptr [0x570e40], edi
    app->getMemory<x86::reg32>(x86::reg32(5705280) /* 0x570e40 */) = cpu.edi;
    // 004a0e33  a138ab4d00             -mov eax, dword ptr [0x4dab38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 004a0e38  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004a0e3b  e82091feff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004a0e40  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a0e42  740d                   -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0e44  833d4cac4d0000         +cmp dword ptr [0x4dac4c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090380) /* 0x4dac4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0e4b  0f8577010000           -jne 0x4a0fc8
    if (!cpu.flags.zf)
    {
        return sub_4a0fc8(app, cpu);
    }
L_0x004a0e51:
    // 004a0e51  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0e54  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e55  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0dab(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a0dab;
    // 004a0d48  a3540e5700             -mov dword ptr [0x570e54], eax
    app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */) = cpu.eax;
    // 004a0d4d  8915580e5700           -mov dword ptr [0x570e58], edx
    app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */) = cpu.edx;
    // 004a0d53  891d4c0e5700           -mov dword ptr [0x570e4c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5705292) /* 0x570e4c */) = cpu.ebx;
    // 004a0d59  890d480e5700           -mov dword ptr [0x570e48], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705288) /* 0x570e48 */) = cpu.ecx;
    // 004a0d5f  8b1d5c0e5700           -mov ebx, dword ptr [0x570e5c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705308) /* 0x570e5c */);
    // 004a0d65  8b15400e5700           -mov edx, dword ptr [0x570e40]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5705280) /* 0x570e40 */);
    // 004a0d6b  a1440e5700             -mov eax, dword ptr [0x570e44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */);
    // 004a0d70  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0d72  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004a0d74  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0d75  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0d76  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0d77  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0d7a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a0d7c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004a0d7e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a0d81  833d60ab4d0000         +cmp dword ptr [0x4dab60], 0
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
    // 004a0d88  0f84c3000000           -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0d8e  833d38ab4d0000         +cmp dword ptr [0x4dab38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0d95  0f84b6000000           -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0d9b  8b3d540e5700           -mov edi, dword ptr [0x570e54]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */);
    // 004a0da1  39f8                   +cmp eax, edi
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
    // 004a0da3  0f8ede010000           -jle 0x4a0f87
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f87(app, cpu);
    }
    // 004a0da9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
L_entry_0x004a0dab:
    // 004a0dab  a14c0e5700             -mov eax, dword ptr [0x570e4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705292) /* 0x570e4c */);
    // 004a0db0  39c1                   +cmp ecx, eax
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
    // 004a0db2  7d10                   -jge 0x4a0dc4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0dc4;
    }
    // 004a0db4  8b0d540e5700           -mov ecx, dword ptr [0x570e54]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */);
    // 004a0dba  39ce                   +cmp esi, ecx
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
    // 004a0dbc  0f8ecc010000           -jle 0x4a0f8e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f8e(app, cpu);
    }
    // 004a0dc2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004a0dc4:
    // 004a0dc4  8b1d580e5700           -mov ebx, dword ptr [0x570e58]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */);
    // 004a0dca  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0dcc  39da                   +cmp edx, ebx
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
    // 004a0dce  0f8ec1010000           -jle 0x4a0f95
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f95(app, cpu);
    }
    // 004a0dd4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0dd6  8b3d480e5700           -mov edi, dword ptr [0x570e48]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705288) /* 0x570e48 */);
    // 004a0ddc  39f8                   +cmp eax, edi
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
    // 004a0dde  0f8dbf010000           -jge 0x4a0fa3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4a0fa3(app, cpu);
    }
    // 004a0de4  a1580e5700             -mov eax, dword ptr [0x570e58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */);
    // 004a0de9  39c2                   +cmp edx, eax
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
    // 004a0deb  0f8eab010000           -jle 0x4a0f9c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f9c(app, cpu);
    }
    // 004a0df1  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a0df3  a138ab4d00             -mov eax, dword ptr [0x4dab38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 004a0df8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a0dfa  e84991feff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004a0dff  892d5c0e5700           -mov dword ptr [0x570e5c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5705308) /* 0x570e5c */) = cpu.ebp;
    // 004a0e05  39f1                   +cmp ecx, esi
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
    // 004a0e07  0f849d010000           -je 0x4a0faa
    if (cpu.flags.zf)
    {
        return sub_4a0faa(app, cpu);
    }
    // 004a0e0d  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
    // 004a0e12  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004a0e14  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a0e16  e83513feff             -call 0x482150
    cpu.esp -= 4;
    sub_482150(app, cpu);
    if (cpu.terminate) return;
    // 004a0e1b  3b0d440e5700           +cmp ecx, dword ptr [0x570e44]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0e21  0f8490010000           -je 0x4a0fb7
    if (cpu.flags.zf)
    {
        return sub_4a0fb7(app, cpu);
    }
    // 004a0e27  890d440e5700           -mov dword ptr [0x570e44], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */) = cpu.ecx;
    // 004a0e2d  893d400e5700           -mov dword ptr [0x570e40], edi
    app->getMemory<x86::reg32>(x86::reg32(5705280) /* 0x570e40 */) = cpu.edi;
    // 004a0e33  a138ab4d00             -mov eax, dword ptr [0x4dab38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 004a0e38  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004a0e3b  e82091feff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004a0e40  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a0e42  740d                   -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0e44  833d4cac4d0000         +cmp dword ptr [0x4dac4c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090380) /* 0x4dac4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0e4b  0f8577010000           -jne 0x4a0fc8
    if (!cpu.flags.zf)
    {
        return sub_4a0fc8(app, cpu);
    }
L_0x004a0e51:
    // 004a0e51  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0e54  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e55  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0d74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a0d74;
    // 004a0d48  a3540e5700             -mov dword ptr [0x570e54], eax
    app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */) = cpu.eax;
    // 004a0d4d  8915580e5700           -mov dword ptr [0x570e58], edx
    app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */) = cpu.edx;
    // 004a0d53  891d4c0e5700           -mov dword ptr [0x570e4c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5705292) /* 0x570e4c */) = cpu.ebx;
    // 004a0d59  890d480e5700           -mov dword ptr [0x570e48], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705288) /* 0x570e48 */) = cpu.ecx;
    // 004a0d5f  8b1d5c0e5700           -mov ebx, dword ptr [0x570e5c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705308) /* 0x570e5c */);
    // 004a0d65  8b15400e5700           -mov edx, dword ptr [0x570e40]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5705280) /* 0x570e40 */);
    // 004a0d6b  a1440e5700             -mov eax, dword ptr [0x570e44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */);
    // 004a0d70  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0d72  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_entry_0x004a0d74:
    // 004a0d74  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0d75  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0d76  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0d77  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0d7a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a0d7c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004a0d7e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a0d81  833d60ab4d0000         +cmp dword ptr [0x4dab60], 0
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
    // 004a0d88  0f84c3000000           -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0d8e  833d38ab4d0000         +cmp dword ptr [0x4dab38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0d95  0f84b6000000           -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0d9b  8b3d540e5700           -mov edi, dword ptr [0x570e54]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */);
    // 004a0da1  39f8                   +cmp eax, edi
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
    // 004a0da3  0f8ede010000           -jle 0x4a0f87
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f87(app, cpu);
    }
    // 004a0da9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0dab  a14c0e5700             -mov eax, dword ptr [0x570e4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705292) /* 0x570e4c */);
    // 004a0db0  39c1                   +cmp ecx, eax
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
    // 004a0db2  7d10                   -jge 0x4a0dc4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0dc4;
    }
    // 004a0db4  8b0d540e5700           -mov ecx, dword ptr [0x570e54]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */);
    // 004a0dba  39ce                   +cmp esi, ecx
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
    // 004a0dbc  0f8ecc010000           -jle 0x4a0f8e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f8e(app, cpu);
    }
    // 004a0dc2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004a0dc4:
    // 004a0dc4  8b1d580e5700           -mov ebx, dword ptr [0x570e58]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */);
    // 004a0dca  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0dcc  39da                   +cmp edx, ebx
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
    // 004a0dce  0f8ec1010000           -jle 0x4a0f95
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f95(app, cpu);
    }
    // 004a0dd4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0dd6  8b3d480e5700           -mov edi, dword ptr [0x570e48]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705288) /* 0x570e48 */);
    // 004a0ddc  39f8                   +cmp eax, edi
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
    // 004a0dde  0f8dbf010000           -jge 0x4a0fa3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4a0fa3(app, cpu);
    }
    // 004a0de4  a1580e5700             -mov eax, dword ptr [0x570e58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */);
    // 004a0de9  39c2                   +cmp edx, eax
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
    // 004a0deb  0f8eab010000           -jle 0x4a0f9c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f9c(app, cpu);
    }
    // 004a0df1  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a0df3  a138ab4d00             -mov eax, dword ptr [0x4dab38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 004a0df8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a0dfa  e84991feff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004a0dff  892d5c0e5700           -mov dword ptr [0x570e5c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5705308) /* 0x570e5c */) = cpu.ebp;
    // 004a0e05  39f1                   +cmp ecx, esi
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
    // 004a0e07  0f849d010000           -je 0x4a0faa
    if (cpu.flags.zf)
    {
        return sub_4a0faa(app, cpu);
    }
    // 004a0e0d  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
    // 004a0e12  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004a0e14  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a0e16  e83513feff             -call 0x482150
    cpu.esp -= 4;
    sub_482150(app, cpu);
    if (cpu.terminate) return;
    // 004a0e1b  3b0d440e5700           +cmp ecx, dword ptr [0x570e44]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0e21  0f8490010000           -je 0x4a0fb7
    if (cpu.flags.zf)
    {
        return sub_4a0fb7(app, cpu);
    }
    // 004a0e27  890d440e5700           -mov dword ptr [0x570e44], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */) = cpu.ecx;
    // 004a0e2d  893d400e5700           -mov dword ptr [0x570e40], edi
    app->getMemory<x86::reg32>(x86::reg32(5705280) /* 0x570e40 */) = cpu.edi;
    // 004a0e33  a138ab4d00             -mov eax, dword ptr [0x4dab38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 004a0e38  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004a0e3b  e82091feff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004a0e40  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a0e42  740d                   -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0e44  833d4cac4d0000         +cmp dword ptr [0x4dac4c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090380) /* 0x4dac4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0e4b  0f8577010000           -jne 0x4a0fc8
    if (!cpu.flags.zf)
    {
        return sub_4a0fc8(app, cpu);
    }
L_0x004a0e51:
    // 004a0e51  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0e54  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e55  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0e33(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a0e33;
    // 004a0d48  a3540e5700             -mov dword ptr [0x570e54], eax
    app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */) = cpu.eax;
    // 004a0d4d  8915580e5700           -mov dword ptr [0x570e58], edx
    app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */) = cpu.edx;
    // 004a0d53  891d4c0e5700           -mov dword ptr [0x570e4c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5705292) /* 0x570e4c */) = cpu.ebx;
    // 004a0d59  890d480e5700           -mov dword ptr [0x570e48], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705288) /* 0x570e48 */) = cpu.ecx;
    // 004a0d5f  8b1d5c0e5700           -mov ebx, dword ptr [0x570e5c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705308) /* 0x570e5c */);
    // 004a0d65  8b15400e5700           -mov edx, dword ptr [0x570e40]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5705280) /* 0x570e40 */);
    // 004a0d6b  a1440e5700             -mov eax, dword ptr [0x570e44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */);
    // 004a0d70  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0d72  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004a0d74  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0d75  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0d76  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0d77  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0d7a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a0d7c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004a0d7e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a0d81  833d60ab4d0000         +cmp dword ptr [0x4dab60], 0
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
    // 004a0d88  0f84c3000000           -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0d8e  833d38ab4d0000         +cmp dword ptr [0x4dab38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0d95  0f84b6000000           -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0d9b  8b3d540e5700           -mov edi, dword ptr [0x570e54]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */);
    // 004a0da1  39f8                   +cmp eax, edi
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
    // 004a0da3  0f8ede010000           -jle 0x4a0f87
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f87(app, cpu);
    }
    // 004a0da9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0dab  a14c0e5700             -mov eax, dword ptr [0x570e4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705292) /* 0x570e4c */);
    // 004a0db0  39c1                   +cmp ecx, eax
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
    // 004a0db2  7d10                   -jge 0x4a0dc4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0dc4;
    }
    // 004a0db4  8b0d540e5700           -mov ecx, dword ptr [0x570e54]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */);
    // 004a0dba  39ce                   +cmp esi, ecx
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
    // 004a0dbc  0f8ecc010000           -jle 0x4a0f8e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f8e(app, cpu);
    }
    // 004a0dc2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004a0dc4:
    // 004a0dc4  8b1d580e5700           -mov ebx, dword ptr [0x570e58]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */);
    // 004a0dca  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0dcc  39da                   +cmp edx, ebx
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
    // 004a0dce  0f8ec1010000           -jle 0x4a0f95
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f95(app, cpu);
    }
    // 004a0dd4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0dd6  8b3d480e5700           -mov edi, dword ptr [0x570e48]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705288) /* 0x570e48 */);
    // 004a0ddc  39f8                   +cmp eax, edi
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
    // 004a0dde  0f8dbf010000           -jge 0x4a0fa3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4a0fa3(app, cpu);
    }
    // 004a0de4  a1580e5700             -mov eax, dword ptr [0x570e58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */);
    // 004a0de9  39c2                   +cmp edx, eax
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
    // 004a0deb  0f8eab010000           -jle 0x4a0f9c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f9c(app, cpu);
    }
    // 004a0df1  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a0df3  a138ab4d00             -mov eax, dword ptr [0x4dab38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 004a0df8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a0dfa  e84991feff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004a0dff  892d5c0e5700           -mov dword ptr [0x570e5c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5705308) /* 0x570e5c */) = cpu.ebp;
    // 004a0e05  39f1                   +cmp ecx, esi
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
    // 004a0e07  0f849d010000           -je 0x4a0faa
    if (cpu.flags.zf)
    {
        return sub_4a0faa(app, cpu);
    }
    // 004a0e0d  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
    // 004a0e12  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004a0e14  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a0e16  e83513feff             -call 0x482150
    cpu.esp -= 4;
    sub_482150(app, cpu);
    if (cpu.terminate) return;
    // 004a0e1b  3b0d440e5700           +cmp ecx, dword ptr [0x570e44]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0e21  0f8490010000           -je 0x4a0fb7
    if (cpu.flags.zf)
    {
        return sub_4a0fb7(app, cpu);
    }
    // 004a0e27  890d440e5700           -mov dword ptr [0x570e44], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */) = cpu.ecx;
    // 004a0e2d  893d400e5700           -mov dword ptr [0x570e40], edi
    app->getMemory<x86::reg32>(x86::reg32(5705280) /* 0x570e40 */) = cpu.edi;
L_entry_0x004a0e33:
    // 004a0e33  a138ab4d00             -mov eax, dword ptr [0x4dab38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 004a0e38  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004a0e3b  e82091feff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004a0e40  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a0e42  740d                   -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0e44  833d4cac4d0000         +cmp dword ptr [0x4dac4c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090380) /* 0x4dac4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0e4b  0f8577010000           -jne 0x4a0fc8
    if (!cpu.flags.zf)
    {
        return sub_4a0fc8(app, cpu);
    }
L_0x004a0e51:
    // 004a0e51  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0e54  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e55  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0e27(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a0e27;
    // 004a0d48  a3540e5700             -mov dword ptr [0x570e54], eax
    app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */) = cpu.eax;
    // 004a0d4d  8915580e5700           -mov dword ptr [0x570e58], edx
    app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */) = cpu.edx;
    // 004a0d53  891d4c0e5700           -mov dword ptr [0x570e4c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5705292) /* 0x570e4c */) = cpu.ebx;
    // 004a0d59  890d480e5700           -mov dword ptr [0x570e48], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705288) /* 0x570e48 */) = cpu.ecx;
    // 004a0d5f  8b1d5c0e5700           -mov ebx, dword ptr [0x570e5c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705308) /* 0x570e5c */);
    // 004a0d65  8b15400e5700           -mov edx, dword ptr [0x570e40]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5705280) /* 0x570e40 */);
    // 004a0d6b  a1440e5700             -mov eax, dword ptr [0x570e44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */);
    // 004a0d70  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0d72  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004a0d74  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0d75  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0d76  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0d77  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0d7a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a0d7c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004a0d7e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a0d81  833d60ab4d0000         +cmp dword ptr [0x4dab60], 0
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
    // 004a0d88  0f84c3000000           -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0d8e  833d38ab4d0000         +cmp dword ptr [0x4dab38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0d95  0f84b6000000           -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0d9b  8b3d540e5700           -mov edi, dword ptr [0x570e54]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */);
    // 004a0da1  39f8                   +cmp eax, edi
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
    // 004a0da3  0f8ede010000           -jle 0x4a0f87
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f87(app, cpu);
    }
    // 004a0da9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0dab  a14c0e5700             -mov eax, dword ptr [0x570e4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705292) /* 0x570e4c */);
    // 004a0db0  39c1                   +cmp ecx, eax
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
    // 004a0db2  7d10                   -jge 0x4a0dc4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0dc4;
    }
    // 004a0db4  8b0d540e5700           -mov ecx, dword ptr [0x570e54]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */);
    // 004a0dba  39ce                   +cmp esi, ecx
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
    // 004a0dbc  0f8ecc010000           -jle 0x4a0f8e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f8e(app, cpu);
    }
    // 004a0dc2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004a0dc4:
    // 004a0dc4  8b1d580e5700           -mov ebx, dword ptr [0x570e58]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */);
    // 004a0dca  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0dcc  39da                   +cmp edx, ebx
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
    // 004a0dce  0f8ec1010000           -jle 0x4a0f95
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f95(app, cpu);
    }
    // 004a0dd4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0dd6  8b3d480e5700           -mov edi, dword ptr [0x570e48]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705288) /* 0x570e48 */);
    // 004a0ddc  39f8                   +cmp eax, edi
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
    // 004a0dde  0f8dbf010000           -jge 0x4a0fa3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4a0fa3(app, cpu);
    }
    // 004a0de4  a1580e5700             -mov eax, dword ptr [0x570e58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */);
    // 004a0de9  39c2                   +cmp edx, eax
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
    // 004a0deb  0f8eab010000           -jle 0x4a0f9c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f9c(app, cpu);
    }
    // 004a0df1  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a0df3  a138ab4d00             -mov eax, dword ptr [0x4dab38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 004a0df8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a0dfa  e84991feff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004a0dff  892d5c0e5700           -mov dword ptr [0x570e5c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5705308) /* 0x570e5c */) = cpu.ebp;
    // 004a0e05  39f1                   +cmp ecx, esi
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
    // 004a0e07  0f849d010000           -je 0x4a0faa
    if (cpu.flags.zf)
    {
        return sub_4a0faa(app, cpu);
    }
    // 004a0e0d  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
    // 004a0e12  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004a0e14  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a0e16  e83513feff             -call 0x482150
    cpu.esp -= 4;
    sub_482150(app, cpu);
    if (cpu.terminate) return;
    // 004a0e1b  3b0d440e5700           +cmp ecx, dword ptr [0x570e44]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0e21  0f8490010000           -je 0x4a0fb7
    if (cpu.flags.zf)
    {
        return sub_4a0fb7(app, cpu);
    }
L_entry_0x004a0e27:
    // 004a0e27  890d440e5700           -mov dword ptr [0x570e44], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */) = cpu.ecx;
    // 004a0e2d  893d400e5700           -mov dword ptr [0x570e40], edi
    app->getMemory<x86::reg32>(x86::reg32(5705280) /* 0x570e40 */) = cpu.edi;
    // 004a0e33  a138ab4d00             -mov eax, dword ptr [0x4dab38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 004a0e38  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004a0e3b  e82091feff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004a0e40  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a0e42  740d                   -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0e44  833d4cac4d0000         +cmp dword ptr [0x4dac4c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090380) /* 0x4dac4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0e4b  0f8577010000           -jne 0x4a0fc8
    if (!cpu.flags.zf)
    {
        return sub_4a0fc8(app, cpu);
    }
L_0x004a0e51:
    // 004a0e51  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0e54  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e55  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0e1b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a0e1b;
    // 004a0d48  a3540e5700             -mov dword ptr [0x570e54], eax
    app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */) = cpu.eax;
    // 004a0d4d  8915580e5700           -mov dword ptr [0x570e58], edx
    app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */) = cpu.edx;
    // 004a0d53  891d4c0e5700           -mov dword ptr [0x570e4c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5705292) /* 0x570e4c */) = cpu.ebx;
    // 004a0d59  890d480e5700           -mov dword ptr [0x570e48], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705288) /* 0x570e48 */) = cpu.ecx;
    // 004a0d5f  8b1d5c0e5700           -mov ebx, dword ptr [0x570e5c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705308) /* 0x570e5c */);
    // 004a0d65  8b15400e5700           -mov edx, dword ptr [0x570e40]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5705280) /* 0x570e40 */);
    // 004a0d6b  a1440e5700             -mov eax, dword ptr [0x570e44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */);
    // 004a0d70  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0d72  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004a0d74  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0d75  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0d76  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0d77  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0d7a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a0d7c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004a0d7e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a0d81  833d60ab4d0000         +cmp dword ptr [0x4dab60], 0
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
    // 004a0d88  0f84c3000000           -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0d8e  833d38ab4d0000         +cmp dword ptr [0x4dab38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0d95  0f84b6000000           -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0d9b  8b3d540e5700           -mov edi, dword ptr [0x570e54]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */);
    // 004a0da1  39f8                   +cmp eax, edi
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
    // 004a0da3  0f8ede010000           -jle 0x4a0f87
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f87(app, cpu);
    }
    // 004a0da9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0dab  a14c0e5700             -mov eax, dword ptr [0x570e4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705292) /* 0x570e4c */);
    // 004a0db0  39c1                   +cmp ecx, eax
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
    // 004a0db2  7d10                   -jge 0x4a0dc4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0dc4;
    }
    // 004a0db4  8b0d540e5700           -mov ecx, dword ptr [0x570e54]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */);
    // 004a0dba  39ce                   +cmp esi, ecx
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
    // 004a0dbc  0f8ecc010000           -jle 0x4a0f8e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f8e(app, cpu);
    }
    // 004a0dc2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004a0dc4:
    // 004a0dc4  8b1d580e5700           -mov ebx, dword ptr [0x570e58]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */);
    // 004a0dca  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0dcc  39da                   +cmp edx, ebx
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
    // 004a0dce  0f8ec1010000           -jle 0x4a0f95
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f95(app, cpu);
    }
    // 004a0dd4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0dd6  8b3d480e5700           -mov edi, dword ptr [0x570e48]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705288) /* 0x570e48 */);
    // 004a0ddc  39f8                   +cmp eax, edi
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
    // 004a0dde  0f8dbf010000           -jge 0x4a0fa3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4a0fa3(app, cpu);
    }
    // 004a0de4  a1580e5700             -mov eax, dword ptr [0x570e58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */);
    // 004a0de9  39c2                   +cmp edx, eax
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
    // 004a0deb  0f8eab010000           -jle 0x4a0f9c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f9c(app, cpu);
    }
    // 004a0df1  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a0df3  a138ab4d00             -mov eax, dword ptr [0x4dab38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 004a0df8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a0dfa  e84991feff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004a0dff  892d5c0e5700           -mov dword ptr [0x570e5c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5705308) /* 0x570e5c */) = cpu.ebp;
    // 004a0e05  39f1                   +cmp ecx, esi
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
    // 004a0e07  0f849d010000           -je 0x4a0faa
    if (cpu.flags.zf)
    {
        return sub_4a0faa(app, cpu);
    }
    // 004a0e0d  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
    // 004a0e12  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004a0e14  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a0e16  e83513feff             -call 0x482150
    cpu.esp -= 4;
    sub_482150(app, cpu);
    if (cpu.terminate) return;
L_entry_0x004a0e1b:
    // 004a0e1b  3b0d440e5700           +cmp ecx, dword ptr [0x570e44]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0e21  0f8490010000           -je 0x4a0fb7
    if (cpu.flags.zf)
    {
        return sub_4a0fb7(app, cpu);
    }
    // 004a0e27  890d440e5700           -mov dword ptr [0x570e44], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */) = cpu.ecx;
    // 004a0e2d  893d400e5700           -mov dword ptr [0x570e40], edi
    app->getMemory<x86::reg32>(x86::reg32(5705280) /* 0x570e40 */) = cpu.edi;
    // 004a0e33  a138ab4d00             -mov eax, dword ptr [0x4dab38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 004a0e38  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004a0e3b  e82091feff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004a0e40  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a0e42  740d                   -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0e44  833d4cac4d0000         +cmp dword ptr [0x4dac4c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090380) /* 0x4dac4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0e4b  0f8577010000           -jne 0x4a0fc8
    if (!cpu.flags.zf)
    {
        return sub_4a0fc8(app, cpu);
    }
L_0x004a0e51:
    // 004a0e51  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0e54  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e55  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0e0d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a0e0d;
    // 004a0d48  a3540e5700             -mov dword ptr [0x570e54], eax
    app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */) = cpu.eax;
    // 004a0d4d  8915580e5700           -mov dword ptr [0x570e58], edx
    app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */) = cpu.edx;
    // 004a0d53  891d4c0e5700           -mov dword ptr [0x570e4c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5705292) /* 0x570e4c */) = cpu.ebx;
    // 004a0d59  890d480e5700           -mov dword ptr [0x570e48], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705288) /* 0x570e48 */) = cpu.ecx;
    // 004a0d5f  8b1d5c0e5700           -mov ebx, dword ptr [0x570e5c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705308) /* 0x570e5c */);
    // 004a0d65  8b15400e5700           -mov edx, dword ptr [0x570e40]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5705280) /* 0x570e40 */);
    // 004a0d6b  a1440e5700             -mov eax, dword ptr [0x570e44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */);
    // 004a0d70  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a0d72  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004a0d74  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0d75  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0d76  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0d77  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0d7a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a0d7c  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 004a0d7e  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a0d81  833d60ab4d0000         +cmp dword ptr [0x4dab60], 0
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
    // 004a0d88  0f84c3000000           -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0d8e  833d38ab4d0000         +cmp dword ptr [0x4dab38], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0d95  0f84b6000000           -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0d9b  8b3d540e5700           -mov edi, dword ptr [0x570e54]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */);
    // 004a0da1  39f8                   +cmp eax, edi
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
    // 004a0da3  0f8ede010000           -jle 0x4a0f87
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f87(app, cpu);
    }
    // 004a0da9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0dab  a14c0e5700             -mov eax, dword ptr [0x570e4c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705292) /* 0x570e4c */);
    // 004a0db0  39c1                   +cmp ecx, eax
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
    // 004a0db2  7d10                   -jge 0x4a0dc4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0dc4;
    }
    // 004a0db4  8b0d540e5700           -mov ecx, dword ptr [0x570e54]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */);
    // 004a0dba  39ce                   +cmp esi, ecx
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
    // 004a0dbc  0f8ecc010000           -jle 0x4a0f8e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f8e(app, cpu);
    }
    // 004a0dc2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004a0dc4:
    // 004a0dc4  8b1d580e5700           -mov ebx, dword ptr [0x570e58]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */);
    // 004a0dca  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0dcc  39da                   +cmp edx, ebx
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
    // 004a0dce  0f8ec1010000           -jle 0x4a0f95
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f95(app, cpu);
    }
    // 004a0dd4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0dd6  8b3d480e5700           -mov edi, dword ptr [0x570e48]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705288) /* 0x570e48 */);
    // 004a0ddc  39f8                   +cmp eax, edi
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
    // 004a0dde  0f8dbf010000           -jge 0x4a0fa3
    if (cpu.flags.sf == cpu.flags.of)
    {
        return sub_4a0fa3(app, cpu);
    }
    // 004a0de4  a1580e5700             -mov eax, dword ptr [0x570e58]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */);
    // 004a0de9  39c2                   +cmp edx, eax
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
    // 004a0deb  0f8eab010000           -jle 0x4a0f9c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        return sub_4a0f9c(app, cpu);
    }
    // 004a0df1  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a0df3  a138ab4d00             -mov eax, dword ptr [0x4dab38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 004a0df8  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a0dfa  e84991feff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004a0dff  892d5c0e5700           -mov dword ptr [0x570e5c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5705308) /* 0x570e5c */) = cpu.ebp;
    // 004a0e05  39f1                   +cmp ecx, esi
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
    // 004a0e07  0f849d010000           -je 0x4a0faa
    if (cpu.flags.zf)
    {
        return sub_4a0faa(app, cpu);
    }
L_entry_0x004a0e0d:
    // 004a0e0d  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
    // 004a0e12  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004a0e14  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a0e16  e83513feff             -call 0x482150
    cpu.esp -= 4;
    sub_482150(app, cpu);
    if (cpu.terminate) return;
    // 004a0e1b  3b0d440e5700           +cmp ecx, dword ptr [0x570e44]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0e21  0f8490010000           -je 0x4a0fb7
    if (cpu.flags.zf)
    {
        return sub_4a0fb7(app, cpu);
    }
    // 004a0e27  890d440e5700           -mov dword ptr [0x570e44], ecx
    app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */) = cpu.ecx;
    // 004a0e2d  893d400e5700           -mov dword ptr [0x570e40], edi
    app->getMemory<x86::reg32>(x86::reg32(5705280) /* 0x570e40 */) = cpu.edi;
    // 004a0e33  a138ab4d00             -mov eax, dword ptr [0x4dab38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090104) /* 0x4dab38 */);
    // 004a0e38  8b3424                 -mov esi, dword ptr [esp]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    // 004a0e3b  e82091feff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004a0e40  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a0e42  740d                   -je 0x4a0e51
    if (cpu.flags.zf)
    {
        goto L_0x004a0e51;
    }
    // 004a0e44  833d4cac4d0000         +cmp dword ptr [0x4dac4c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5090380) /* 0x4dac4c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0e4b  0f8577010000           -jne 0x4a0fc8
    if (!cpu.flags.zf)
    {
        return sub_4a0fc8(app, cpu);
    }
L_0x004a0e51:
    // 004a0e51  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0e54  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e55  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e56  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e57  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0e58(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0e58  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0e5a  7510                   -jne 0x4a0e6c
    if (!cpu.flags.zf)
    {
        goto L_0x004a0e6c;
    }
L_0x004a0e5c:
    // 004a0e5c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a0e5e  7407                   -je 0x4a0e67
    if (cpu.flags.zf)
    {
        goto L_0x004a0e67;
    }
    // 004a0e60  a1440e5700             -mov eax, dword ptr [0x570e44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */);
    // 004a0e65  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004a0e67:
    // 004a0e67  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a0e69  750d                   -jne 0x4a0e78
    if (!cpu.flags.zf)
    {
        goto L_0x004a0e78;
    }
    // 004a0e6b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0e6c:
    // 004a0e6c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0e6d  8b0d5c0e5700           -mov ecx, dword ptr [0x570e5c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5705308) /* 0x570e5c */);
    // 004a0e73  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004a0e75  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0e76  ebe4                   -jmp 0x4a0e5c
    goto L_0x004a0e5c;
L_0x004a0e78:
    // 004a0e78  a1400e5700             -mov eax, dword ptr [0x570e40]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5705280) /* 0x570e40 */);
    // 004a0e7d  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a0e7f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0e80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0e80  ff1548ac4d00           -call dword ptr [0x4dac48]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090376) /* 0x4dac48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a0e86  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a0e88(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0e88  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a0e89  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a0e8a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a0e8b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a0e8c  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004a0e8f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a0e91  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a0e93  e8508dfeff             -call 0x489be8
    cpu.esp -= 4;
    sub_489be8(app, cpu);
    if (cpu.terminate) return;
    // 004a0e98  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0e9a  0f85a4000000           -jne 0x4a0f44
    if (!cpu.flags.zf)
    {
        goto L_0x004a0f44;
    }
    // 004a0ea0  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 004a0ea5  e89e90feff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
L_0x004a0eaa:
    // 004a0eaa  8b1d540e5700           -mov ebx, dword ptr [0x570e54]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */);
    // 004a0eb0  39d9                   +cmp ecx, ebx
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
    // 004a0eb2  0f8e9d000000           -jle 0x4a0f55
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a0f55;
    }
    // 004a0eb8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x004a0eba:
    // 004a0eba  8b354c0e5700           -mov esi, dword ptr [0x570e4c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5705292) /* 0x570e4c */);
    // 004a0ec0  39f0                   +cmp eax, esi
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
    // 004a0ec2  0f8d9b000000           -jge 0x4a0f63
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0f63;
    }
    // 004a0ec8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a0ec9  8b3d540e5700           -mov edi, dword ptr [0x570e54]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5705300) /* 0x570e54 */);
    // 004a0ecf  39f9                   +cmp ecx, edi
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
    // 004a0ed1  0f8e85000000           -jle 0x4a0f5c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a0f5c;
    }
L_0x004a0ed7:
    // 004a0ed7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004a0ed8:
    // 004a0ed8  8b2d580e5700           -mov ebp, dword ptr [0x570e58]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */);
    // 004a0ede  39ea                   +cmp edx, ebp
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
    // 004a0ee0  0f8e84000000           -jle 0x4a0f6a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a0f6a;
    }
    // 004a0ee6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x004a0ee8:
    // 004a0ee8  8b1d480e5700           -mov ebx, dword ptr [0x570e48]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5705288) /* 0x570e48 */);
    // 004a0eee  39d8                   +cmp eax, ebx
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
    // 004a0ef0  7d0c                   -jge 0x4a0efe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a0efe;
    }
    // 004a0ef2  8b35580e5700           -mov esi, dword ptr [0x570e58]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5705304) /* 0x570e58 */);
    // 004a0ef8  39f2                   +cmp edx, esi
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
    // 004a0efa  7e75                   -jle 0x4a0f71
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a0f71;
    }
L_0x004a0efc:
    // 004a0efc  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x004a0efe:
    // 004a0efe  890d64ab4d00           -mov dword ptr [0x4dab64], ecx
    app->getMemory<x86::reg32>(x86::reg32(5090148) /* 0x4dab64 */) = cpu.ecx;
    // 004a0f04  a164ab4d00             -mov eax, dword ptr [0x4dab64]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090148) /* 0x4dab64 */);
    // 004a0f09  a3440e5700             -mov dword ptr [0x570e44], eax
    app->getMemory<x86::reg32>(x86::reg32(5705284) /* 0x570e44 */) = cpu.eax;
    // 004a0f0e  891d68ab4d00           -mov dword ptr [0x4dab68], ebx
    app->getMemory<x86::reg32>(x86::reg32(5090152) /* 0x4dab68 */) = cpu.ebx;
    // 004a0f14  a168ab4d00             -mov eax, dword ptr [0x4dab68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5090152) /* 0x4dab68 */);
    // 004a0f19  a3400e5700             -mov dword ptr [0x570e40], eax
    app->getMemory<x86::reg32>(x86::reg32(5705280) /* 0x570e40 */) = cpu.eax;
    // 004a0f1e  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a0f20  b800395600             -mov eax, 0x563900
    cpu.eax = 5650688 /*0x563900*/;
    // 004a0f25  e82612feff             -call 0x482150
    cpu.esp -= 4;
    sub_482150(app, cpu);
    if (cpu.terminate) return;
    // 004a0f2a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a0f2c  e8b78cfeff             -call 0x489be8
    cpu.esp -= 4;
    sub_489be8(app, cpu);
    if (cpu.terminate) return;
    // 004a0f31  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a0f33  7440                   -je 0x4a0f75
    if (cpu.flags.zf)
    {
        goto L_0x004a0f75;
    }
    // 004a0f35  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a0f37  e818310000             -call 0x4a4054
    cpu.esp -= 4;
    sub_4a4054(app, cpu);
    if (cpu.terminate) return;
    // 004a0f3c  83c470                 +add esp, 0x70
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(112 /*0x70*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a0f3f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0f40  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0f41  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0f42  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0f43  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a0f44:
    // 004a0f44  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a0f46  e8e5300000             -call 0x4a4030
    cpu.esp -= 4;
    sub_4a4030(app, cpu);
    if (cpu.terminate) return;
    // 004a0f4b  e86c15feff             -call 0x4824bc
    cpu.esp -= 4;
    sub_4824bc(app, cpu);
    if (cpu.terminate) return;
    // 004a0f50  e955ffffff             -jmp 0x4a0eaa
    goto L_0x004a0eaa;
L_0x004a0f55:
    // 004a0f55  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a0f57  e95effffff             -jmp 0x4a0eba
    goto L_0x004a0eba;
L_0x004a0f5c:
    // 004a0f5c  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a0f5e  e974ffffff             -jmp 0x4a0ed7
    goto L_0x004a0ed7;
L_0x004a0f63:
    // 004a0f63  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004a0f65  e96effffff             -jmp 0x4a0ed8
    goto L_0x004a0ed8;
L_0x004a0f6a:
    // 004a0f6a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a0f6c  e977ffffff             -jmp 0x4a0ee8
    goto L_0x004a0ee8;
L_0x004a0f71:
    // 004a0f71  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a0f73  eb87                   -jmp 0x4a0efc
    goto L_0x004a0efc;
L_0x004a0f75:
    // 004a0f75  a1a0b64d00             -mov eax, dword ptr [0x4db6a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093024) /* 0x4db6a0 */);
    // 004a0f7a  e8e18ffeff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004a0f7f  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004a0f82  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0f83  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0f84  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0f85  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0f86  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a0f87(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0f87  89f9                   -mov ecx, edi
    cpu.ecx = cpu.edi;
    // 004a0f89  e91dfeffff             -jmp 0x4a0dab
    return sub_4a0dab(app, cpu);
}

/* align: skip  */
void Application::sub_4a0f8e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0f8e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a0f90  e92ffeffff             -jmp 0x4a0dc4
    return sub_4a0dc4(app, cpu);
}

/* align: skip  */
void Application::sub_4a0f95(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0f95  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a0f97  e93afeffff             -jmp 0x4a0dd6
    return sub_4a0dd6(app, cpu);
}

/* align: skip  */
void Application::sub_4a0f9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0f9c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a0f9e  e950feffff             -jmp 0x4a0df3
    return sub_4a0df3(app, cpu);
}

/* align: skip  */
void Application::sub_4a0fa3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0fa3  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004a0fa5  e949feffff             -jmp 0x4a0df3
    return sub_4a0df3(app, cpu);
}

/* align: skip  */
void Application::sub_4a0faa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0faa  39d3                   +cmp ebx, edx
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
    // 004a0fac  0f855bfeffff           -jne 0x4a0e0d
    if (!cpu.flags.zf)
    {
        return sub_4a0e0d(app, cpu);
    }
    // 004a0fb2  e964feffff             -jmp 0x4a0e1b
    return sub_4a0e1b(app, cpu);
}

/* align: skip  */
void Application::sub_4a0fb7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0fb7  3b3d400e5700           +cmp edi, dword ptr [0x570e40]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5705280) /* 0x570e40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a0fbd  0f8564feffff           -jne 0x4a0e27
    if (!cpu.flags.zf)
    {
        return sub_4a0e27(app, cpu);
    }
    // 004a0fc3  e96bfeffff             -jmp 0x4a0e33
    return sub_4a0e33(app, cpu);
}

/* align: skip  */
void Application::sub_4a0fc8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0fc8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a0fca  ff154cac4d00           -call dword ptr [0x4dac4c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5090380) /* 0x4dac4c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a0fd0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a0fd3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0fd4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0fd5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0fd6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a0fe0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0fe0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0fe1  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004a0fe6  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a0fe8  e813000000             -call 0x4a1000
    cpu.esp -= 4;
    sub_4a1000(app, cpu);
    if (cpu.terminate) return;
    // 004a0fed  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0fee  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a0ff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a0ff0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a0ff1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a0ff6  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a0ff8  e803000000             -call 0x4a1000
    cpu.esp -= 4;
    sub_4a1000(app, cpu);
    if (cpu.terminate) return;
    // 004a0ffd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a0ffe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a1000(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a1000  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a1001  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a1002  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a1003  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a1004  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a1005  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a1008  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004a100b  bd02000000             -mov ebp, 2
    cpu.ebp = 2 /*0x2*/;
    // 004a1010  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a1012  83f801                 +cmp eax, 1
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
    // 004a1015  7328                   -jae 0x4a103f
    if (!cpu.flags.cf)
    {
        goto L_0x004a103f;
    }
    // 004a1017  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a1019  751b                   -jne 0x4a1036
    if (!cpu.flags.zf)
    {
        goto L_0x004a1036;
    }
    // 004a101b  b014                   -mov al, 0x14
    cpu.al = 20 /*0x14*/;
    // 004a101d  b33a                   -mov bl, 0x3a
    cpu.bl = 58 /*0x3a*/;
L_0x004a101f:
    // 004a101f  0fb6f0                 -movzx esi, al
    cpu.esi = x86::reg32(cpu.al);
    // 004a1022  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a1023  2eff15ec634c00         -call dword ptr cs:[0x4c63ec]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006316) /* 0x4c63ec */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a102a  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004a102c  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004a102e  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004a1031  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 004a1032  39d0                   +cmp eax, edx
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
    // 004a1034  7525                   -jne 0x4a105b
    if (!cpu.flags.zf)
    {
        goto L_0x004a105b;
    }
L_0x004a1036:
    // 004a1036  83c404                 +add esp, 4
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
    // 004a1039  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a103a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a103b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a103c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a103d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a103e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a103f:
    // 004a103f  7710                   -ja 0x4a1051
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a1051;
    }
    // 004a1041  b090                   -mov al, 0x90
    cpu.al = 144 /*0x90*/;
    // 004a1043  b345                   -mov bl, 0x45
    cpu.bl = 69 /*0x45*/;
    // 004a1045  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004a104a  bd03000000             -mov ebp, 3
    cpu.ebp = 3 /*0x3*/;
    // 004a104f  ebce                   -jmp 0x4a101f
    goto L_0x004a101f;
L_0x004a1051:
    // 004a1051  39e8                   +cmp eax, ebp
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
    // 004a1053  75e1                   -jne 0x4a1036
    if (!cpu.flags.zf)
    {
        goto L_0x004a1036;
    }
    // 004a1055  b091                   -mov al, 0x91
    cpu.al = 145 /*0x91*/;
    // 004a1057  b346                   -mov bl, 0x46
    cpu.bl = 70 /*0x46*/;
    // 004a1059  ebc4                   -jmp 0x4a101f
    goto L_0x004a101f;
L_0x004a105b:
    // 004a105b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a105d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a105e  0fb6fb                 -movzx edi, bl
    cpu.edi = x86::reg32(cpu.bl);
    // 004a1061  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a1062  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a1063  2eff1548644c00         -call dword ptr cs:[0x4c6448]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006408) /* 0x4c6448 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a106a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a106c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a106d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a106e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a106f  2eff1548644c00         -call dword ptr cs:[0x4c6448]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006408) /* 0x4c6448 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1076  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a1079  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a107a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a107b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a107c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a107d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a107e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4a1080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a1080  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1082  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a1090(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a1090  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a1091  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a1092  81ec00140000           -sub esp, 0x1400
    (cpu.esp) -= x86::reg32(x86::sreg32(5120 /*0x1400*/));
    // 004a1098  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a109a  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a109c  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004a109e  ff1564125700           -call dword ptr [0x571264]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706340) /* 0x571264 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a10a4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a10a6  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004a10a8  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a10aa  ff1560125700           -call dword ptr [0x571260]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706336) /* 0x571260 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a10b0  81c400140000           -add esp, 0x1400
    (cpu.esp) += x86::reg32(x86::sreg32(5120 /*0x1400*/));
    // 004a10b6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a10b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a10b8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a10bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a10bc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a10bd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a10be  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a10bf  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a10c2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a10c4  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004a10c8  895c2424               -mov dword ptr [esp + 0x24], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.ebx;
    // 004a10cc  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 004a10ce  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a10d0  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004a10d3  8a80b0d74d00           -mov al, byte ptr [eax + 0x4dd7b0]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101488) /* 0x4dd7b0 */);
    // 004a10d9  0fb62d5db24d00         -movzx ebp, byte ptr [0x4db25d]
    cpu.ebp = x86::reg32(app->getMemory<x86::reg8>(x86::reg32(5091933) /* 0x4db25d */));
    // 004a10e0  8b4118                 -mov eax, dword ptr [ecx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004a10e3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a10e5  8b5920                 -mov ebx, dword ptr [ecx + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004a10e8  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a10ec  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a10f0  891564125700           -mov dword ptr [0x571264], edx
    app->getMemory<x86::reg32>(x86::reg32(5706340) /* 0x571264 */) = cpu.edx;
    // 004a10f6  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a10f8  7402                   -je 0x4a10fc
    if (cpu.flags.zf)
    {
        goto L_0x004a10fc;
    }
    // 004a10fa  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
L_0x004a10fc:
    // 004a10fc  837c241000             +cmp dword ptr [esp + 0x10], 0
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
    // 004a1101  7540                   -jne 0x4a1143
    if (!cpu.flags.zf)
    {
        goto L_0x004a1143;
    }
    // 004a1103  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004a1105  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a110a  39e8                   +cmp eax, ebp
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
    // 004a110c  7435                   -je 0x4a1143
    if (cpu.flags.zf)
    {
        goto L_0x004a1143;
    }
    // 004a110e  837f1c02               +cmp dword ptr [edi + 0x1c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1112  0f8464020000           -je 0x4a137c
    if (cpu.flags.zf)
    {
        goto L_0x004a137c;
    }
    // 004a1118  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x004a111d:
    // 004a111d  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004a111f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a1121  e8b68effff             -call 0x499fdc
    cpu.esp -= 4;
    sub_499fdc(app, cpu);
    if (cpu.terminate) return;
    // 004a1126  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a112a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a112c  0f8451020000           -je 0x4a1383
    if (cpu.flags.zf)
    {
        goto L_0x004a1383;
    }
    // 004a1132  837f1c02               +cmp dword ptr [edi + 0x1c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1136  740b                   -je 0x4a1143
    if (cpu.flags.zf)
    {
        goto L_0x004a1143;
    }
    // 004a1138  a364125700             -mov dword ptr [0x571264], eax
    app->getMemory<x86::reg32>(x86::reg32(5706340) /* 0x571264 */) = cpu.eax;
    // 004a113d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a113f  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
L_0x004a1143:
    // 004a1143  8d4e10                 -lea ecx, [esi + 0x10]
    cpu.ecx = x86::reg32(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004a1146  8b6e02                 -mov ebp, dword ptr [esi + 2]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(2) /* 0x2 */);
    // 004a1149  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a114b  8b5604                 -mov edx, dword ptr [esi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004a114e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a1150  83e07f                 -and eax, 0x7f
    cpu.eax &= x86::reg32(x86::sreg32(127 /*0x7f*/));
    // 004a1153  8a80b0d74d00           -mov al, byte ptr [eax + 0x4dd7b0]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5101488) /* 0x4dd7b0 */);
    // 004a1159  40                     -inc eax
    (cpu.eax)++;
    // 004a115a  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004a115c  c1fd10                 -sar ebp, 0x10
    cpu.ebp = x86::reg32(x86::sreg32(cpu.ebp) >> (16 /*0x10*/ % 32));
    // 004a115f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a1161  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004a1163  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a1166  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 004a1169  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a116d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a116f  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a1173  e828850000             -call 0x4a96a0
    cpu.esp -= 4;
    sub_4a96a0(app, cpu);
    if (cpu.terminate) return;
    // 004a1178  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a117a  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a117e  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004a1182  a150b24d00             -mov eax, dword ptr [0x4db250]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091920) /* 0x4db250 */);
    // 004a1187  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a1189  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004a118c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a118e  7e15                   -jle 0x4a11a5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a11a5;
    }
    // 004a1190  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a1194  0faff0                 -imul esi, eax
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a1197  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a1199  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a119d  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a119f  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a11a1  89742424               -mov dword ptr [esp + 0x24], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.esi;
L_0x004a11a5:
    // 004a11a5  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a11a9  8b3558b24d00           -mov esi, dword ptr [0x4db258]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091928) /* 0x4db258 */);
    // 004a11af  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a11b1  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a11b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a11b5  7e02                   -jle 0x4a11b9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a11b9;
    }
    // 004a11b7  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a11b9:
    // 004a11b9  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a11bd  a14cb24d00             -mov eax, dword ptr [0x4db24c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091916) /* 0x4db24c */);
    // 004a11c2  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a11c4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a11c6  7e20                   -jle 0x4a11e8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a11e8;
    }
    // 004a11c8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a11ca  0faff3                 -imul esi, ebx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a11cd  c1fe03                 -sar esi, 3
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (3 /*0x3*/ % 32));
    // 004a11d0  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004a11d3  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a11d5  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a11d9  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a11db  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a11dd  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a11e0  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004a11e4  01442420               -add dword ptr [esp + 0x20], eax
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x004a11e8:
    // 004a11e8  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a11ec  8b3554b24d00           -mov esi, dword ptr [0x4db254]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091924) /* 0x4db254 */);
    // 004a11f2  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a11f4  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 004a11f6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a11f8  7e0e                   -jle 0x4a1208
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a1208;
    }
    // 004a11fa  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a11fc  0faff3                 -imul esi, ebx
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a11ff  c1fe03                 -sar esi, 3
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (3 /*0x3*/ % 32));
    // 004a1202  29c5                   -sub ebp, eax
    (cpu.ebp) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1204  01742420               -add dword ptr [esp + 0x20], esi
    (app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */)) += x86::reg32(x86::sreg32(cpu.esi));
L_0x004a1208:
    // 004a1208  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004a120a  0f8e59010000           -jle 0x4a1369
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a1369;
    }
    // 004a1210  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a1212  0f8e51010000           -jle 0x4a1369
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a1369;
    }
    // 004a1218  0fafdd                 -imul ebx, ebp
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004a121b  a160b24d00             -mov eax, dword ptr [0x4db260]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091936) /* 0x4db260 */);
    // 004a1220  89442434               -mov dword ptr [esp + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004a1224  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1226  a05cb24d00             -mov al, byte ptr [0x4db25c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
    // 004a122b  40                     -inc eax
    (cpu.eax)++;
    // 004a122c  24fe                   -and al, 0xfe
    cpu.al &= x86::reg8(x86::sreg8(254 /*0xfe*/));
    // 004a122e  0fafc5                 -imul eax, ebp
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 004a1231  c1fb03                 -sar ebx, 3
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (3 /*0x3*/ % 32));
    // 004a1234  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 004a1237  895c2418               -mov dword ptr [esp + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 004a123b  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004a123f  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a1243  8b1d6cb24d00           -mov ebx, dword ptr [0x4db26c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5091948) /* 0x4db26c */);
    // 004a1249  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a124c  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a124e  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a1252  8b3570b24d00           -mov esi, dword ptr [0x4db270]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5091952) /* 0x4db270 */);
    // 004a1258  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004a125b  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a125d  8b33                   -mov esi, dword ptr [ebx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a125f  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a1261  a168b24d00             -mov eax, dword ptr [0x4db268]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091944) /* 0x4db268 */);
    // 004a1266  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a1268  8b5c241c               -mov ebx, dword ptr [esp + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a126c  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a126e  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004a1272  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a1276  89542428               -mov dword ptr [esp + 0x28], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edx;
    // 004a127a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a127c  0f8542010000           -jne 0x4a13c4
    if (!cpu.flags.zf)
    {
        goto L_0x004a13c4;
    }
    // 004a1282  a05cb24d00             -mov al, byte ptr [0x4db25c]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5091932) /* 0x4db25c */);
    // 004a1287  3c0f                   +cmp al, 0xf
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
    // 004a1289  0f833e010000           -jae 0x4a13cd
    if (!cpu.flags.cf)
    {
        goto L_0x004a13cd;
    }
    // 004a128f  3c04                   +cmp al, 4
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
    // 004a1291  0f837e010000           -jae 0x4a1415
    if (!cpu.flags.cf)
    {
        goto L_0x004a1415;
    }
L_0x004a1297:
    // 004a1297  833d6412570000         +cmp dword ptr [0x571264], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5706340) /* 0x571264 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a129e  0f8592010000           -jne 0x4a1436
    if (!cpu.flags.zf)
    {
        goto L_0x004a1436;
    }
L_0x004a12a4:
    // 004a12a4  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a12a8  03442414               -add eax, dword ptr [esp + 0x14]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */)));
    // 004a12ac  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a12b0  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004a12b4  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a12b8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a12ba  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
L_0x004a12be:
    // 004a12be  8b7c2428               -mov edi, dword ptr [esp + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a12c2  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a12c4  745a                   -je 0x4a1320
    if (cpu.flags.zf)
    {
        goto L_0x004a1320;
    }
    // 004a12c6  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a12ca  a174b24d00             -mov eax, dword ptr [0x4db274]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5091956) /* 0x4db274 */);
    // 004a12cf  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 004a12d1  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a12d3  29fb                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004a12d5  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004a12d9  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004a12dd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a12df  0f8480010000           -je 0x4a1465
    if (cpu.flags.zf)
    {
        goto L_0x004a1465;
    }
    // 004a12e5  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a12e7  895c243c               -mov dword ptr [esp + 0x3c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.ebx;
L_0x004a12eb:
    // 004a12eb  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004a12ef  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004a12f1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a12f3  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a12f5  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a12f9  8b5c2430               -mov ebx, dword ptr [esp + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004a12fd  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a1301  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004a1305  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a1307  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a1309  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a130b  8b1de0ab4d00           -mov ebx, dword ptr [0x4dabe0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5090272) /* 0x4dabe0 */);
    // 004a1311  8954243c               -mov dword ptr [esp + 0x3c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.edx;
    // 004a1315  39da                   +cmp edx, ebx
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
    // 004a1317  0f8f30010000           -jg 0x4a144d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a144d;
    }
L_0x004a131d:
    // 004a131d  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a131e  75cb                   -jne 0x4a12eb
    if (!cpu.flags.zf)
    {
        goto L_0x004a12eb;
    }
L_0x004a1320:
    // 004a1320  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a1324  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a1326  7436                   -je 0x4a135e
    if (cpu.flags.zf)
    {
        goto L_0x004a135e;
    }
    // 004a1328  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004a132b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a132d  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004a1331  895c2428               -mov dword ptr [esp + 0x28], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.ebx;
    // 004a1335  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004a1337  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a1339  8b7c241c               -mov edi, dword ptr [esp + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a133d  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1341  8b442418               -mov eax, dword ptr [esp + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a1345  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a1349  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a134d  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a134f  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a1353  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a1355  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a1357  47                     -inc edi
    (cpu.edi)++;
    // 004a1358  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a135a  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
L_0x004a135e:
    // 004a135e  837c242800             +cmp dword ptr [esp + 0x28], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1363  0f8f55ffffff           -jg 0x4a12be
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a12be;
    }
L_0x004a1369:
    // 004a1369  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a136d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a136f  0f8550010000           -jne 0x4a14c5
    if (!cpu.flags.zf)
    {
        goto L_0x004a14c5;
    }
L_0x004a1375:
    // 004a1375  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a1378  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1379  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a137a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a137b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a137c:
    // 004a137c  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004a137e  e99afdffff             -jmp 0x4a111d
    goto L_0x004a111d;
L_0x004a1383:
    // 004a1383  837f1c02               +cmp dword ptr [edi + 0x1c], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1387  7421                   -je 0x4a13aa
    if (cpu.flags.zf)
    {
        goto L_0x004a13aa;
    }
    // 004a1389  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x004a138e:
    // 004a138e  8b5f1c                 -mov ebx, dword ptr [edi + 0x1c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(28) /* 0x1c */);
    // 004a1391  83fb01                 +cmp ebx, 1
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
    // 004a1394  7518                   -jne 0x4a13ae
    if (!cpu.flags.zf)
    {
        goto L_0x004a13ae;
    }
    // 004a1396  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004a1398  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a139a  e8798dffff             -call 0x49a118
    cpu.esp -= 4;
    sub_49a118(app, cpu);
    if (cpu.terminate) return;
    // 004a139f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a13a3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a13a5  e999fdffff             -jmp 0x4a1143
    goto L_0x004a1143;
L_0x004a13aa:
    // 004a13aa  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004a13ac  ebe0                   -jmp 0x4a138e
    goto L_0x004a138e;
L_0x004a13ae:
    // 004a13ae  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004a13b0  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004a13b2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a13b4  e85f8dffff             -call 0x49a118
    cpu.esp -= 4;
    sub_49a118(app, cpu);
    if (cpu.terminate) return;
    // 004a13b9  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a13bd  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a13bf  e97ffdffff             -jmp 0x4a1143
    goto L_0x004a1143;
L_0x004a13c4:
    // 004a13c4  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 004a13c8  e9d7feffff             -jmp 0x4a12a4
    goto L_0x004a12a4;
L_0x004a13cd:
    // 004a13cd  770c                   -ja 0x4a13db
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a13db;
    }
    // 004a13cf  8b4708                 -mov eax, dword ptr [edi + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 004a13d2  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 004a13d6  e9bcfeffff             -jmp 0x4a1297
    goto L_0x004a1297;
L_0x004a13db:
    // 004a13db  3c18                   +cmp al, 0x18
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
    // 004a13dd  7314                   -jae 0x4a13f3
    if (!cpu.flags.cf)
    {
        goto L_0x004a13f3;
    }
    // 004a13df  3c10                   +cmp al, 0x10
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
    // 004a13e1  0f85b0feffff           -jne 0x4a1297
    if (!cpu.flags.zf)
    {
        goto L_0x004a1297;
    }
    // 004a13e7  8b470c                 -mov eax, dword ptr [edi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(12) /* 0xc */);
    // 004a13ea  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 004a13ee  e9a4feffff             -jmp 0x4a1297
    goto L_0x004a1297;
L_0x004a13f3:
    // 004a13f3  770c                   -ja 0x4a1401
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a1401;
    }
    // 004a13f5  8b4710                 -mov eax, dword ptr [edi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(16) /* 0x10 */);
    // 004a13f8  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 004a13fc  e996feffff             -jmp 0x4a1297
    goto L_0x004a1297;
L_0x004a1401:
    // 004a1401  3c20                   +cmp al, 0x20
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
    // 004a1403  0f858efeffff           -jne 0x4a1297
    if (!cpu.flags.zf)
    {
        goto L_0x004a1297;
    }
    // 004a1409  8b4714                 -mov eax, dword ptr [edi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(20) /* 0x14 */);
    // 004a140c  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 004a1410  e982feffff             -jmp 0x4a1297
    goto L_0x004a1297;
L_0x004a1415:
    // 004a1415  770b                   -ja 0x4a1422
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a1422;
    }
    // 004a1417  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 004a1419  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 004a141d  e975feffff             -jmp 0x4a1297
    goto L_0x004a1297;
L_0x004a1422:
    // 004a1422  3c08                   +cmp al, 8
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
    // 004a1424  0f856dfeffff           -jne 0x4a1297
    if (!cpu.flags.zf)
    {
        goto L_0x004a1297;
    }
    // 004a142a  8b4704                 -mov eax, dword ptr [edi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 004a142d  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 004a1431  e961feffff             -jmp 0x4a1297
    goto L_0x004a1297;
L_0x004a1436:
    // 004a1436  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004a143a  bb90104a00             -mov ebx, 0x4a1090
    cpu.ebx = 4853904 /*0x4a1090*/;
    // 004a143f  a360125700             -mov dword ptr [0x571260], eax
    app->getMemory<x86::reg32>(x86::reg32(5706336) /* 0x571260 */) = cpu.eax;
    // 004a1444  895c2438               -mov dword ptr [esp + 0x38], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.ebx;
    // 004a1448  e957feffff             -jmp 0x4a12a4
    goto L_0x004a12a4;
L_0x004a144d:
    // 004a144d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a144f  8944243c               -mov dword ptr [esp + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 004a1453  e8702bfeff             -call 0x483fc8
    cpu.esp -= 4;
    sub_483fc8(app, cpu);
    if (cpu.terminate) return;
    // 004a1458  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a145a  0f8415ffffff           -je 0x4a1375
    if (cpu.flags.zf)
    {
        goto L_0x004a1375;
    }
    // 004a1460  e9b8feffff             -jmp 0x4a131d
    goto L_0x004a131d;
L_0x004a1465:
    // 004a1465  837c241400             +cmp dword ptr [esp + 0x14], 0
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
    // 004a146a  7422                   -je 0x4a148e
    if (cpu.flags.zf)
    {
        goto L_0x004a148e;
    }
L_0x004a146c:
    // 004a146c  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004a1470  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004a1472  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a1474  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a1476  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a147a  8b442430               -mov eax, dword ptr [esp + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004a147e  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a1482  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a1484  01d1                   +add ecx, edx
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a1486  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a1487  75e3                   -jne 0x4a146c
    if (!cpu.flags.zf)
    {
        goto L_0x004a146c;
    }
    // 004a1489  e992feffff             -jmp 0x4a1320
    goto L_0x004a1320;
L_0x004a148e:
    // 004a148e  837c242000             +cmp dword ptr [esp + 0x20], 0
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
    // 004a1493  75d7                   -jne 0x4a146c
    if (!cpu.flags.zf)
    {
        goto L_0x004a146c;
    }
    // 004a1495  817c243890104a00       +cmp dword ptr [esp + 0x38], 0x4a1090
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4853904 /*0x4a1090*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a149d  74cd                   -je 0x4a146c
    if (cpu.flags.zf)
    {
        goto L_0x004a146c;
    }
    // 004a149f  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 004a14a1  0fafdf                 -imul ebx, edi
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004a14a4  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 004a14a8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a14aa  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a14ac  ff542438               -call dword ptr [esp + 0x38]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a14b0  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a14b4  0fafc7                 -imul eax, edi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 004a14b7  0faf7c2418             -imul edi, dword ptr [esp + 0x18]
    cpu.edi = x86::reg32(x86::sreg64(x86::sreg32(cpu.edi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */))));
    // 004a14bc  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a14be  01f9                   +add ecx, edi
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a14c0  e95bfeffff             -jmp 0x4a1320
    goto L_0x004a1320;
L_0x004a14c5:
    // 004a14c5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a14c7  e83034feff             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 004a14cc  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004a14cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a14d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a14d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a14d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4a14d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a14d4  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
    // 004a14d5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a14d6  a903000000             +test eax, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 3 /*0x3*/));
    // 004a14db  0f8599000000           -jne 0x4a157a
    if (!cpu.flags.zf)
    {
        goto L_0x004a157a;
    }
L_0x004a14e1:
    // 004a14e1  83eb20                 +sub ebx, 0x20
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
    // 004a14e4  7839                   -js 0x4a151f
    if (cpu.flags.sf)
    {
        goto L_0x004a151f;
    }
L_0x004a14e6:
    // 004a14e6  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a14e8  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004a14ea  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a14ed  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a14f0  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a14f3  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004a14f6  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004a14f9  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004a14fc  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a14ff  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004a1502  8b4a14                 -mov ecx, dword ptr [edx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004a1505  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004a1508  8b4a18                 -mov ecx, dword ptr [edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004a150b  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004a150e  8b4a1c                 -mov ecx, dword ptr [edx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004a1511  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004a1514  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004a1517  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a151a  83eb20                 +sub ebx, 0x20
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
    // 004a151d  79c7                   -jns 0x4a14e6
    if (!cpu.flags.sf)
    {
        goto L_0x004a14e6;
    }
L_0x004a151f:
    // 004a151f  83c318                 +add ebx, 0x18
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
    // 004a1522  7815                   -js 0x4a1539
    if (cpu.flags.sf)
    {
        goto L_0x004a1539;
    }
L_0x004a1524:
    // 004a1524  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a1526  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004a1528  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a152b  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a152e  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a1531  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a1534  83eb08                 +sub ebx, 8
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
    // 004a1537  79eb                   -jns 0x4a1524
    if (!cpu.flags.sf)
    {
        goto L_0x004a1524;
    }
L_0x004a1539:
    // 004a1539  83c308                 +add ebx, 8
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
    // 004a153c  7502                   -jne 0x4a1540
    if (!cpu.flags.zf)
    {
        goto L_0x004a1540;
    }
    // 004a153e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a153f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a1540:
    // 004a1540  83fb04                 +cmp ebx, 4
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
    // 004a1543  720d                   -jb 0x4a1552
    if (cpu.flags.cf)
    {
        goto L_0x004a1552;
    }
    // 004a1545  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a1547  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a154a  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004a154c  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a154f  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004a1552:
    // 004a1552  83fb02                 +cmp ebx, 2
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
    // 004a1555  720f                   -jb 0x4a1566
    if (cpu.flags.cf)
    {
        goto L_0x004a1566;
    }
    // 004a1557  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004a155a  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a155d  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004a1560  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a1563  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004a1566:
    // 004a1566  83fb01                 +cmp ebx, 1
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
    // 004a1569  720d                   -jb 0x4a1578
    if (cpu.flags.cf)
    {
        goto L_0x004a1578;
    }
    // 004a156b  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a156d  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a1570  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004a1572  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a1575  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a1578:
    // 004a1578  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1579  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a157a:
    // 004a157a  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 004a157f  7412                   -je 0x4a1593
    if (cpu.flags.zf)
    {
        goto L_0x004a1593;
    }
    // 004a1581  83fb01                 +cmp ebx, 1
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
    // 004a1584  7c0d                   -jl 0x4a1593
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1593;
    }
    // 004a1586  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a1588  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a158b  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004a158d  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a1590  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a1593:
    // 004a1593  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 004a1598  7414                   -je 0x4a15ae
    if (cpu.flags.zf)
    {
        goto L_0x004a15ae;
    }
    // 004a159a  83fb02                 +cmp ebx, 2
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
    // 004a159d  7c0f                   -jl 0x4a15ae
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a15ae;
    }
    // 004a159f  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004a15a2  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a15a5  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004a15a8  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a15ab  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004a15ae:
    // 004a15ae  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 004a15b3  7412                   -je 0x4a15c7
    if (cpu.flags.zf)
    {
        goto L_0x004a15c7;
    }
    // 004a15b5  83fb04                 +cmp ebx, 4
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
    // 004a15b8  7c0d                   -jl 0x4a15c7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a15c7;
    }
    // 004a15ba  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a15bc  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a15bf  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004a15c1  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a15c4  83eb04                 +sub ebx, 4
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
L_0x004a15c7:
    // 004a15c7  e915ffffff             -jmp 0x4a14e1
    goto L_0x004a14e1;
}

/* align: skip  */
void Application::sub_4a14d5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a14d5;
    // 004a14d4  92                     -xchg edx, eax
    {
        x86::reg32 tmp = cpu.edx;
        cpu.edx = cpu.eax;
        cpu.eax = tmp;
    }
L_entry_0x004a14d5:
    // 004a14d5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a14d6  a903000000             +test eax, 3
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 3 /*0x3*/));
    // 004a14db  0f8599000000           -jne 0x4a157a
    if (!cpu.flags.zf)
    {
        goto L_0x004a157a;
    }
L_0x004a14e1:
    // 004a14e1  83eb20                 +sub ebx, 0x20
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
    // 004a14e4  7839                   -js 0x4a151f
    if (cpu.flags.sf)
    {
        goto L_0x004a151f;
    }
L_0x004a14e6:
    // 004a14e6  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a14e8  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004a14ea  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a14ed  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a14f0  8b4a08                 -mov ecx, dword ptr [edx + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a14f3  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 004a14f6  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 004a14f9  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 004a14fc  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 004a14ff  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 004a1502  8b4a14                 -mov ecx, dword ptr [edx + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    // 004a1505  894814                 -mov dword ptr [eax + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004a1508  8b4a18                 -mov ecx, dword ptr [edx + 0x18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 004a150b  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 004a150e  8b4a1c                 -mov ecx, dword ptr [edx + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(28) /* 0x1c */);
    // 004a1511  89481c                 -mov dword ptr [eax + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004a1514  8d5220                 -lea edx, [edx + 0x20]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(32) /* 0x20 */);
    // 004a1517  8d4020                 -lea eax, [eax + 0x20]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 004a151a  83eb20                 +sub ebx, 0x20
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
    // 004a151d  79c7                   -jns 0x4a14e6
    if (!cpu.flags.sf)
    {
        goto L_0x004a14e6;
    }
L_0x004a151f:
    // 004a151f  83c318                 +add ebx, 0x18
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
    // 004a1522  7815                   -js 0x4a1539
    if (cpu.flags.sf)
    {
        goto L_0x004a1539;
    }
L_0x004a1524:
    // 004a1524  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a1526  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004a1528  8b4a04                 -mov ecx, dword ptr [edx + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a152b  894804                 -mov dword ptr [eax + 4], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004a152e  8d5208                 -lea edx, [edx + 8]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 004a1531  8d4008                 -lea eax, [eax + 8]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a1534  83eb08                 +sub ebx, 8
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
    // 004a1537  79eb                   -jns 0x4a1524
    if (!cpu.flags.sf)
    {
        goto L_0x004a1524;
    }
L_0x004a1539:
    // 004a1539  83c308                 +add ebx, 8
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
    // 004a153c  7502                   -jne 0x4a1540
    if (!cpu.flags.zf)
    {
        goto L_0x004a1540;
    }
    // 004a153e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a153f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a1540:
    // 004a1540  83fb04                 +cmp ebx, 4
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
    // 004a1543  720d                   -jb 0x4a1552
    if (cpu.flags.cf)
    {
        goto L_0x004a1552;
    }
    // 004a1545  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a1547  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a154a  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004a154c  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a154f  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004a1552:
    // 004a1552  83fb02                 +cmp ebx, 2
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
    // 004a1555  720f                   -jb 0x4a1566
    if (cpu.flags.cf)
    {
        goto L_0x004a1566;
    }
    // 004a1557  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004a155a  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a155d  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004a1560  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a1563  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004a1566:
    // 004a1566  83fb01                 +cmp ebx, 1
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
    // 004a1569  720d                   -jb 0x4a1578
    if (cpu.flags.cf)
    {
        goto L_0x004a1578;
    }
    // 004a156b  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a156d  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a1570  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004a1572  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a1575  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a1578:
    // 004a1578  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1579  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a157a:
    // 004a157a  a901000000             +test eax, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 1 /*0x1*/));
    // 004a157f  7412                   -je 0x4a1593
    if (cpu.flags.zf)
    {
        goto L_0x004a1593;
    }
    // 004a1581  83fb01                 +cmp ebx, 1
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
    // 004a1584  7c0d                   -jl 0x4a1593
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1593;
    }
    // 004a1586  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004a1588  8d5201                 -lea edx, [edx + 1]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a158b  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004a158d  8d4001                 -lea eax, [eax + 1]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004a1590  83eb01                 -sub ebx, 1
    (cpu.ebx) -= x86::reg32(x86::sreg32(1 /*0x1*/));
L_0x004a1593:
    // 004a1593  a902000000             +test eax, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 2 /*0x2*/));
    // 004a1598  7414                   -je 0x4a15ae
    if (cpu.flags.zf)
    {
        goto L_0x004a15ae;
    }
    // 004a159a  83fb02                 +cmp ebx, 2
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
    // 004a159d  7c0f                   -jl 0x4a15ae
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a15ae;
    }
    // 004a159f  668b0a                 -mov cx, word ptr [edx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.edx);
    // 004a15a2  8d5202                 -lea edx, [edx + 2]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(2) /* 0x2 */);
    // 004a15a5  668908                 -mov word ptr [eax], cx
    app->getMemory<x86::reg16>(cpu.eax) = cpu.cx;
    // 004a15a8  8d4002                 -lea eax, [eax + 2]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 004a15ab  83eb02                 -sub ebx, 2
    (cpu.ebx) -= x86::reg32(x86::sreg32(2 /*0x2*/));
L_0x004a15ae:
    // 004a15ae  a904000000             +test eax, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & 4 /*0x4*/));
    // 004a15b3  7412                   -je 0x4a15c7
    if (cpu.flags.zf)
    {
        goto L_0x004a15c7;
    }
    // 004a15b5  83fb04                 +cmp ebx, 4
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
    // 004a15b8  7c0d                   -jl 0x4a15c7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a15c7;
    }
    // 004a15ba  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a15bc  8d5204                 -lea edx, [edx + 4]
    cpu.edx = x86::reg32(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a15bf  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004a15c1  8d4004                 -lea eax, [eax + 4]
    cpu.eax = x86::reg32(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a15c4  83eb04                 +sub ebx, 4
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
L_0x004a15c7:
    // 004a15c7  e915ffffff             -jmp 0x4a14e1
    goto L_0x004a14e1;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4a15d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a15d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a15d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a15d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a15d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a15d4  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 004a15d9  b868125700             -mov eax, 0x571268
    cpu.eax = 5706344 /*0x571268*/;
    // 004a15de  b980000000             -mov ecx, 0x80
    cpu.ecx = 128 /*0x80*/;
    // 004a15e3  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a15e8  bf00010000             -mov edi, 0x100
    cpu.edi = 256 /*0x100*/;
    // 004a15ed  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a15ef  bd04000000             -mov ebp, 4
    cpu.ebp = 4 /*0x4*/;
    // 004a15f4  e83610ffff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004a15f9  ba58464433             -mov edx, 0x33444658
    cpu.edx = 860112472 /*0x33444658*/;
    // 004a15fe  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 004a1603  b83bd84d00             -mov eax, 0x4dd83b
    cpu.eax = 5101627 /*0x4dd83b*/;
    // 004a1608  890d6c125700           -mov dword ptr [0x57126c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5706348) /* 0x57126c */) = cpu.ecx;
    // 004a160e  893578125700           -mov dword ptr [0x571278], esi
    app->getMemory<x86::reg32>(x86::reg32(5706360) /* 0x571278 */) = cpu.esi;
    // 004a1614  893d7c125700           -mov dword ptr [0x57127c], edi
    app->getMemory<x86::reg32>(x86::reg32(5706364) /* 0x57127c */) = cpu.edi;
    // 004a161a  893580125700           -mov dword ptr [0x571280], esi
    app->getMemory<x86::reg32>(x86::reg32(5706368) /* 0x571280 */) = cpu.esi;
    // 004a1620  893584125700           -mov dword ptr [0x571284], esi
    app->getMemory<x86::reg32>(x86::reg32(5706372) /* 0x571284 */) = cpu.esi;
    // 004a1626  893d88125700           -mov dword ptr [0x571288], edi
    app->getMemory<x86::reg32>(x86::reg32(5706376) /* 0x571288 */) = cpu.edi;
    // 004a162c  89358c125700           -mov dword ptr [0x57128c], esi
    app->getMemory<x86::reg32>(x86::reg32(5706380) /* 0x57128c */) = cpu.esi;
    // 004a1632  893590125700           -mov dword ptr [0x571290], esi
    app->getMemory<x86::reg32>(x86::reg32(5706384) /* 0x571290 */) = cpu.esi;
    // 004a1638  892d9c125700           -mov dword ptr [0x57129c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5706396) /* 0x57129c */) = cpu.ebp;
    // 004a163e  be09000000             -mov esi, 9
    cpu.esi = 9 /*0x9*/;
    // 004a1643  bf30d84d00             -mov edi, 0x4dd830
    cpu.edi = 5101616 /*0x4dd830*/;
    // 004a1648  b948d84d00             -mov ecx, 0x4dd848
    cpu.ecx = 5101640 /*0x4dd848*/;
    // 004a164d  891568125700           -mov dword ptr [0x571268], edx
    app->getMemory<x86::reg32>(x86::reg32(5706344) /* 0x571268 */) = cpu.edx;
    // 004a1653  891d70125700           -mov dword ptr [0x571270], ebx
    app->getMemory<x86::reg32>(x86::reg32(5706352) /* 0x571270 */) = cpu.ebx;
    // 004a1659  a3a0125700             -mov dword ptr [0x5712a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5706400) /* 0x5712a0 */) = cpu.eax;
    // 004a165e  668b1574125700         -mov dx, word ptr [0x571274]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5706356) /* 0x571274 */);
    // 004a1665  893594125700           -mov dword ptr [0x571294], esi
    app->getMemory<x86::reg32>(x86::reg32(5706388) /* 0x571294 */) = cpu.esi;
    // 004a166b  893d98125700           -mov dword ptr [0x571298], edi
    app->getMemory<x86::reg32>(x86::reg32(5706392) /* 0x571298 */) = cpu.edi;
    // 004a1671  890da8125700           -mov dword ptr [0x5712a8], ecx
    app->getMemory<x86::reg32>(x86::reg32(5706408) /* 0x5712a8 */) = cpu.ecx;
    // 004a1677  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a1679  bf68125700             -mov edi, 0x571268
    cpu.edi = 5706344 /*0x571268*/;
    // 004a167e  be04114d00             -mov esi, 0x4d1104
    cpu.esi = 5050628 /*0x4d1104*/;
    // 004a1683  81cadf010000           -or edx, 0x1df
    cpu.edx |= x86::reg32(x86::sreg32(479 /*0x1df*/));
    // 004a1689  891dac125700           -mov dword ptr [0x5712ac], ebx
    app->getMemory<x86::reg32>(x86::reg32(5706412) /* 0x5712ac */) = cpu.ebx;
    // 004a168f  891db0125700           -mov dword ptr [0x5712b0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5706416) /* 0x5712b0 */) = cpu.ebx;
    // 004a1695  66891574125700         -mov word ptr [0x571274], dx
    app->getMemory<x86::reg16>(x86::reg32(5706356) /* 0x571274 */) = cpu.dx;
    // 004a169c  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 004a16a1  83c74c                 -add edi, 0x4c
    (cpu.edi) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004a16a4  8915a4125700           -mov dword ptr [0x5712a4], edx
    app->getMemory<x86::reg32>(x86::reg32(5706404) /* 0x5712a4 */) = cpu.edx;
    // 004a16aa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004a16ab:
    // 004a16ab  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a16ad  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004a16af  3c00                   +cmp al, 0
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
    // 004a16b1  7410                   -je 0x4a16c3
    if (cpu.flags.zf)
    {
        goto L_0x004a16c3;
    }
    // 004a16b3  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a16b6  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a16b9  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004a16bc  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a16bf  3c00                   +cmp al, 0
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
    // 004a16c1  75e8                   -jne 0x4a16ab
    if (!cpu.flags.zf)
    {
        goto L_0x004a16ab;
    }
L_0x004a16c3:
    // 004a16c3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a16c4  b868125700             -mov eax, 0x571268
    cpu.eax = 5706344 /*0x571268*/;
    // 004a16c9  891dd4125700           -mov dword ptr [0x5712d4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5706452) /* 0x5712d4 */) = cpu.ebx;
    // 004a16cf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a16d0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a16d1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a16d2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a16d3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a16e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a16e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a16e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a16e2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a16e3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a16e4  ba52565750             -mov edx, 0x50575652
    cpu.edx = 1347901010 /*0x50575652*/;
    // 004a16e9  b980000000             -mov ecx, 0x80
    cpu.ecx = 128 /*0x80*/;
    // 004a16ee  bb64000000             -mov ebx, 0x64
    cpu.ebx = 100 /*0x64*/;
    // 004a16f3  be10000000             -mov esi, 0x10
    cpu.esi = 16 /*0x10*/;
    // 004a16f8  bf00010000             -mov edi, 0x100
    cpu.edi = 256 /*0x100*/;
    // 004a16fd  bd04000000             -mov ebp, 4
    cpu.ebp = 4 /*0x4*/;
    // 004a1702  b8cdd94d00             -mov eax, 0x4dd9cd
    cpu.eax = 5102029 /*0x4dd9cd*/;
    // 004a1707  8915f0125700           -mov dword ptr [0x5712f0], edx
    app->getMemory<x86::reg32>(x86::reg32(5706480) /* 0x5712f0 */) = cpu.edx;
    // 004a170d  890df4125700           -mov dword ptr [0x5712f4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5706484) /* 0x5712f4 */) = cpu.ecx;
    // 004a1713  891df8125700           -mov dword ptr [0x5712f8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5706488) /* 0x5712f8 */) = cpu.ebx;
    // 004a1719  893500135700           -mov dword ptr [0x571300], esi
    app->getMemory<x86::reg32>(x86::reg32(5706496) /* 0x571300 */) = cpu.esi;
    // 004a171f  893d04135700           -mov dword ptr [0x571304], edi
    app->getMemory<x86::reg32>(x86::reg32(5706500) /* 0x571304 */) = cpu.edi;
    // 004a1725  893508135700           -mov dword ptr [0x571308], esi
    app->getMemory<x86::reg32>(x86::reg32(5706504) /* 0x571308 */) = cpu.esi;
    // 004a172b  89350c135700           -mov dword ptr [0x57130c], esi
    app->getMemory<x86::reg32>(x86::reg32(5706508) /* 0x57130c */) = cpu.esi;
    // 004a1731  893d10135700           -mov dword ptr [0x571310], edi
    app->getMemory<x86::reg32>(x86::reg32(5706512) /* 0x571310 */) = cpu.edi;
    // 004a1737  893514135700           -mov dword ptr [0x571314], esi
    app->getMemory<x86::reg32>(x86::reg32(5706516) /* 0x571314 */) = cpu.esi;
    // 004a173d  892d24135700           -mov dword ptr [0x571324], ebp
    app->getMemory<x86::reg32>(x86::reg32(5706532) /* 0x571324 */) = cpu.ebp;
    // 004a1743  a328135700             -mov dword ptr [0x571328], eax
    app->getMemory<x86::reg32>(x86::reg32(5706536) /* 0x571328 */) = cpu.eax;
    // 004a1748  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 004a174d  be07000000             -mov esi, 7
    cpu.esi = 7 /*0x7*/;
    // 004a1752  bfc4d94d00             -mov edi, 0x4dd9c4
    cpu.edi = 5102020 /*0x4dd9c4*/;
    // 004a1757  668b15fc125700         -mov dx, word ptr [0x5712fc]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5706492) /* 0x5712fc */);
    // 004a175e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1760  81caff010000           -or edx, 0x1ff
    cpu.edx |= x86::reg32(x86::sreg32(511 /*0x1ff*/));
    // 004a1766  891d18135700           -mov dword ptr [0x571318], ebx
    app->getMemory<x86::reg32>(x86::reg32(5706520) /* 0x571318 */) = cpu.ebx;
    // 004a176c  89351c135700           -mov dword ptr [0x57131c], esi
    app->getMemory<x86::reg32>(x86::reg32(5706524) /* 0x57131c */) = cpu.esi;
    // 004a1772  893d20135700           -mov dword ptr [0x571320], edi
    app->getMemory<x86::reg32>(x86::reg32(5706528) /* 0x571320 */) = cpu.edi;
    // 004a1778  be10114d00             -mov esi, 0x4d1110
    cpu.esi = 5050640 /*0x4d1110*/;
    // 004a177d  8b3dc0d94d00           -mov edi, dword ptr [0x4dd9c0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5102016) /* 0x4dd9c0 */);
    // 004a1783  668915fc125700         -mov word ptr [0x5712fc], dx
    app->getMemory<x86::reg16>(x86::reg32(5706492) /* 0x5712fc */) = cpu.dx;
    // 004a178a  893d34135700           -mov dword ptr [0x571334], edi
    app->getMemory<x86::reg32>(x86::reg32(5706548) /* 0x571334 */) = cpu.edi;
    // 004a1790  bff0125700             -mov edi, 0x5712f0
    cpu.edi = 5706480 /*0x5712f0*/;
    // 004a1795  ba98d94d00             -mov edx, 0x4dd998
    cpu.edx = 5101976 /*0x4dd998*/;
    // 004a179a  83c74c                 -add edi, 0x4c
    (cpu.edi) += x86::reg32(x86::sreg32(76 /*0x4c*/));
    // 004a179d  891538135700           -mov dword ptr [0x571338], edx
    app->getMemory<x86::reg32>(x86::reg32(5706552) /* 0x571338 */) = cpu.edx;
    // 004a17a3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004a17a4:
    // 004a17a4  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 004a17a6  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 004a17a8  3c00                   +cmp al, 0
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
    // 004a17aa  7410                   -je 0x4a17bc
    if (cpu.flags.zf)
    {
        goto L_0x004a17bc;
    }
    // 004a17ac  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004a17af  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a17b2  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 004a17b5  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a17b8  3c00                   +cmp al, 0
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
    // 004a17ba  75e8                   -jne 0x4a17a4
    if (!cpu.flags.zf)
    {
        goto L_0x004a17a4;
    }
L_0x004a17bc:
    // 004a17bc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a17bd  b8f0125700             -mov eax, 0x5712f0
    cpu.eax = 5706480 /*0x5712f0*/;
    // 004a17c2  890d5c135700           -mov dword ptr [0x57135c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5706588) /* 0x57135c */) = cpu.ecx;
    // 004a17c8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a17c9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a17ca  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a17cb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a17cc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4a17d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a17d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a17d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a17d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a17d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a17d4  8b580c                 -mov ebx, dword ptr [eax + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004a17d7  8b701c                 -mov esi, dword ptr [eax + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 004a17da  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 004a17dd  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 004a17e0  8b4018                 -mov eax, dword ptr [eax + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 004a17e3  83fb10                 +cmp ebx, 0x10
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
    // 004a17e6  0f8569000000           -jne 0x4a1855
    if (!cpu.flags.zf)
    {
        goto L_0x004a1855;
    }
    // 004a17ec  81f9007c0000           +cmp ecx, 0x7c00
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(31744 /*0x7c00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a17f2  750d                   -jne 0x4a1801
    if (!cpu.flags.zf)
    {
        goto L_0x004a1801;
    }
    // 004a17f4  81fae0030000           +cmp edx, 0x3e0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(992 /*0x3e0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a17fa  7505                   -jne 0x4a1801
    if (!cpu.flags.zf)
    {
        goto L_0x004a1801;
    }
    // 004a17fc  83f81f                 +cmp eax, 0x1f
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
    // 004a17ff  7440                   -je 0x4a1841
    if (cpu.flags.zf)
    {
        goto L_0x004a1841;
    }
L_0x004a1801:
    // 004a1801  81f900f80000           +cmp ecx, 0xf800
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(63488 /*0xf800*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1807  750d                   -jne 0x4a1816
    if (!cpu.flags.zf)
    {
        goto L_0x004a1816;
    }
    // 004a1809  81fae0070000           +cmp edx, 0x7e0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2016 /*0x7e0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a180f  7505                   -jne 0x4a1816
    if (!cpu.flags.zf)
    {
        goto L_0x004a1816;
    }
    // 004a1811  83f81f                 +cmp eax, 0x1f
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
    // 004a1814  7435                   -je 0x4a184b
    if (cpu.flags.zf)
    {
        goto L_0x004a184b;
    }
L_0x004a1816:
    // 004a1816  81f9000f0000           +cmp ecx, 0xf00
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(3840 /*0xf00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a181c  0f8568000000           -jne 0x4a188a
    if (!cpu.flags.zf)
    {
        goto L_0x004a188a;
    }
    // 004a1822  81faf0000000           +cmp edx, 0xf0
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(240 /*0xf0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1828  7560                   -jne 0x4a188a
    if (!cpu.flags.zf)
    {
        goto L_0x004a188a;
    }
    // 004a182a  83f80f                 +cmp eax, 0xf
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
    // 004a182d  755b                   -jne 0x4a188a
    if (!cpu.flags.zf)
    {
        goto L_0x004a188a;
    }
    // 004a182f  81fe00f00000           +cmp esi, 0xf000
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(61440 /*0xf000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1835  7553                   -jne 0x4a188a
    if (!cpu.flags.zf)
    {
        goto L_0x004a188a;
    }
    // 004a1837  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 004a183c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a183d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a183e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a183f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1840  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a1841:
    // 004a1841  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004a1846  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1847  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1848  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1849  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a184a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a184b:
    // 004a184b  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004a1850  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1851  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1852  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1853  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1854  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a1855:
    // 004a1855  81f90000ff00           +cmp ecx, 0xff0000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16711680 /*0xff0000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a185b  752d                   -jne 0x4a188a
    if (!cpu.flags.zf)
    {
        goto L_0x004a188a;
    }
    // 004a185d  81fa00ff0000           +cmp edx, 0xff00
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65280 /*0xff00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1863  7525                   -jne 0x4a188a
    if (!cpu.flags.zf)
    {
        goto L_0x004a188a;
    }
    // 004a1865  3dff000000             +cmp eax, 0xff
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
    // 004a186a  751e                   -jne 0x4a188a
    if (!cpu.flags.zf)
    {
        goto L_0x004a188a;
    }
    // 004a186c  83fb18                 +cmp ebx, 0x18
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a186f  740f                   -je 0x4a1880
    if (cpu.flags.zf)
    {
        goto L_0x004a1880;
    }
    // 004a1871  83fb20                 +cmp ebx, 0x20
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
    // 004a1874  7514                   -jne 0x4a188a
    if (!cpu.flags.zf)
    {
        goto L_0x004a188a;
    }
    // 004a1876  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 004a187b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a187c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a187d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a187e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a187f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a1880:
    // 004a1880  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004a1885  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1886  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1887  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1888  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1889  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a188a:
    // 004a188a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a188c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a188d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a188e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a188f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1890  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a1894(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a1894  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a1895  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a1896  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a1897  81ec04020000           -sub esp, 0x204
    (cpu.esp) -= x86::reg32(x86::sreg32(516 /*0x204*/));
    // 004a189d  8b942414020000         -mov edx, dword ptr [esp + 0x214]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 004a18a4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a18a6  752f                   -jne 0x4a18d7
    if (!cpu.flags.zf)
    {
        goto L_0x004a18d7;
    }
    // 004a18a8  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004a18aa  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
L_0x004a18ad:
    // 004a18ad  e8be0a0000             -call 0x4a2370
    cpu.esp -= 4;
    sub_4a2370(app, cpu);
    if (cpu.terminate) return;
    // 004a18b2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a18b4  7448                   -je 0x4a18fe
    if (cpu.flags.zf)
    {
        goto L_0x004a18fe;
    }
    // 004a18b6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a18b7  8bb42418020000         -mov esi, dword ptr [esp + 0x218]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(536) /* 0x218 */);
    // 004a18be  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a18bf  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a18c1  ff151c145700           -call dword ptr [0x57141c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706780) /* 0x57141c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a18c7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a18cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a18cd  81c404020000           -add esp, 0x204
    (cpu.esp) += x86::reg32(x86::sreg32(516 /*0x204*/));
    // 004a18d3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a18d4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a18d5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a18d6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a18d7:
    // 004a18d7  8d842418020000         -lea eax, [esp + 0x218]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(536) /* 0x218 */);
    // 004a18de  8d9c2400020000         -lea ebx, [esp + 0x200]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(512) /* 0x200 */);
    // 004a18e5  89842400020000         -mov dword ptr [esp + 0x200], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */) = cpu.eax;
    // 004a18ec  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a18ee  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004a18f0  e88f270000             -call 0x4a4084
    cpu.esp -= 4;
    sub_4a4084(app, cpu);
    if (cpu.terminate) return;
    // 004a18f5  898c2400020000         -mov dword ptr [esp + 0x200], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(512) /* 0x200 */) = cpu.ecx;
    // 004a18fc  ebaf                   -jmp 0x4a18ad
    goto L_0x004a18ad;
L_0x004a18fe:
    // 004a18fe  8b9c2414020000         -mov ebx, dword ptr [esp + 0x214]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(532) /* 0x214 */);
    // 004a1905  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a1906  2eff1554654c00         -call dword ptr cs:[0x4c6554]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006676) /* 0x4c6554 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a190d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a190f  81c404020000           -add esp, 0x204
    (cpu.esp) += x86::reg32(x86::sreg32(516 /*0x204*/));
    // 004a1915  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1916  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1917  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1918  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a191c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a191c  681c114d00             -push 0x4d111c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5050652 /*0x4d111c*/;
    cpu.esp -= 4;
    // 004a1921  2eff1544654c00         -call dword ptr cs:[0x4c6544]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006660) /* 0x4c6544 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1928  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a192a  7501                   -jne 0x4a192d
    if (!cpu.flags.zf)
    {
        goto L_0x004a192d;
    }
    // 004a192c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a192d:
    // 004a192d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a192e  2eff159c644c00         -call dword ptr cs:[0x4c649c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006492) /* 0x4c649c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1935  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 004a193a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a193c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a193c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a193d  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a1940  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a1944  e883160000             -call 0x4a2fcc
    cpu.esp -= 4;
    sub_4a2fcc(app, cpu);
    if (cpu.terminate) return;
    // 004a1949  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a194c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a194e  0f847b000000           -je 0x4a19cf
    if (cpu.flags.zf)
    {
        goto L_0x004a19cf;
    }
    // 004a1954  83780805               +cmp dword ptr [eax + 8], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1958  7561                   -jne 0x4a19bb
    if (!cpu.flags.zf)
    {
        goto L_0x004a19bb;
    }
    // 004a195a  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
L_0x004a195f:
    // 004a195f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a1960  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a1961  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a1962  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a1965  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a1969  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a196c  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a1970  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a1972  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a1974  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a1978  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a197c  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a197f  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a1981  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004a1984  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a1986  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
L_0x004a198a:
    // 004a198a  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a198e  4f                     -dec edi
    (cpu.edi)--;
    // 004a198f  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 004a1993  83ffff                 +cmp edi, -1
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
    // 004a1996  742a                   -je 0x4a19c2
    if (cpu.flags.zf)
    {
        goto L_0x004a19c2;
    }
    // 004a1998  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004a199a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a199c  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004a199e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a199f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a19a1  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004a19a4  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a19a6  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a19a8  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004a19ab  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004a19ad  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a19ae  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a19b2  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a19b5  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a19b7  01ca                   +add edx, ecx
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
    // 004a19b9  ebcf                   -jmp 0x4a198a
    goto L_0x004a198a;
L_0x004a19bb:
    // 004a19bb  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004a19c0  eb9d                   -jmp 0x4a195f
    goto L_0x004a195f;
L_0x004a19c2:
    // 004a19c2  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a19c6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a19c7  e8e0160000             -call 0x4a30ac
    cpu.esp -= 4;
    sub_4a30ac(app, cpu);
    if (cpu.terminate) return;
    // 004a19cc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a19cd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a19ce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004a19cf:
    // 004a19cf  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a19d2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a19d3  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a19d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a19d8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a19d9  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a19dc  8b6c2414               -mov ebp, dword ptr [esp + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a19e0  e8e7150000             -call 0x4a2fcc
    cpu.esp -= 4;
    sub_4a2fcc(app, cpu);
    if (cpu.terminate) return;
    // 004a19e5  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a19e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a19ea  0f847b000000           -je 0x4a1a6b
    if (cpu.flags.zf)
    {
        goto L_0x004a1a6b;
    }
    // 004a19f0  83780805               +cmp dword ptr [eax + 8], 5
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a19f4  7561                   -jne 0x4a1a57
    if (!cpu.flags.zf)
    {
        goto L_0x004a1a57;
    }
    // 004a19f6  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
L_0x004a19fb:
    // 004a19fb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a19fc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a19fd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a19fe  0fafe8                 -imul ebp, eax
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a1a01  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a1a05  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004a1a08  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a1a0c  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a1a0e  01d3                   -add ebx, edx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edx));
    // 004a1a10  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a1a14  8b4c241c               -mov ecx, dword ptr [esp + 0x1c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a1a18  8b7204                 -mov esi, dword ptr [edx + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004a1a1b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a1a1d  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004a1a20  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a1a22  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
L_0x004a1a26:
    // 004a1a26  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a1a2a  4f                     -dec edi
    (cpu.edi)--;
    // 004a1a2b  897c2424               -mov dword ptr [esp + 0x24], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edi;
    // 004a1a2f  83ffff                 +cmp edi, -1
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
    // 004a1a32  742a                   -je 0x4a1a5e
    if (cpu.flags.zf)
    {
        goto L_0x004a1a5e;
    }
    // 004a1a34  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004a1a36  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004a1a38  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a1a3a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a1a3b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a1a3d  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004a1a40  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a1a42  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a1a44  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004a1a47  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004a1a49  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1a4a  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a1a4e  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a1a51  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004a1a53  01ca                   +add edx, ecx
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
    // 004a1a55  ebcf                   -jmp 0x4a1a26
    goto L_0x004a1a26;
L_0x004a1a57:
    // 004a1a57  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 004a1a5c  eb9d                   -jmp 0x4a19fb
    goto L_0x004a19fb;
L_0x004a1a5e:
    // 004a1a5e  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a1a62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a1a63  e844160000             -call 0x4a30ac
    cpu.esp -= 4;
    sub_4a30ac(app, cpu);
    if (cpu.terminate) return;
    // 004a1a68  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1a69  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1a6a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004a1a6b:
    // 004a1a6b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a1a6e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1a6f  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a1a80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a1a80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a1a81  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a1a82  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a1a83  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a1a84  83ec28                 -sub esp, 0x28
    (cpu.esp) -= x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004a1a87  8b5c243c               -mov ebx, dword ptr [esp + 0x3c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004a1a8b  8a634c                 -mov ah, byte ptr [ebx + 0x4c]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(76) /* 0x4c */);
    // 004a1a8e  8b7354                 -mov esi, dword ptr [ebx + 0x54]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    // 004a1a91  f6c440                 +test ah, 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 64 /*0x40*/));
    // 004a1a94  7428                   -je 0x4a1abe
    if (cpu.flags.zf)
    {
        goto L_0x004a1abe;
    }
    // 004a1a96  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004a1a9b:
    // 004a1a9b  8b7c2440               -mov edi, dword ptr [esp + 0x40]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 004a1a9f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a1aa1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a1aa3  740a                   -je 0x4a1aaf
    if (cpu.flags.zf)
    {
        goto L_0x004a1aaf;
    }
    // 004a1aa5  83fe10                 +cmp esi, 0x10
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
    // 004a1aa8  7418                   -je 0x4a1ac2
    if (cpu.flags.zf)
    {
        goto L_0x004a1ac2;
    }
    // 004a1aaa  83fe20                 +cmp esi, 0x20
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1aad  7413                   -je 0x4a1ac2
    if (cpu.flags.zf)
    {
        goto L_0x004a1ac2;
    }
L_0x004a1aaf:
    // 004a1aaf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a1ab4  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004a1ab7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1ab8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1ab9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1aba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1abb  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a1abe:
    // 004a1abe  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a1ac0  ebd9                   -jmp 0x4a1a9b
    goto L_0x004a1a9b;
L_0x004a1ac2:
    // 004a1ac2  8d4348                 -lea eax, [ebx + 0x48]
    cpu.eax = x86::reg32(cpu.ebx + x86::reg32(72) /* 0x48 */);
    // 004a1ac5  e806fdffff             -call 0x4a17d0
    cpu.esp -= 4;
    sub_4a17d0(app, cpu);
    if (cpu.terminate) return;
    // 004a1aca  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004a1ace  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a1ad0  74dd                   -je 0x4a1aaf
    if (cpu.flags.zf)
    {
        goto L_0x004a1aaf;
    }
    // 004a1ad2  8b6b0c                 -mov ebp, dword ptr [ebx + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004a1ad5  0faf6b08               -imul ebp, dword ptr [ebx + 8]
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */))));
    // 004a1ad9  0fafee                 -imul ebp, esi
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 004a1adc  a12cda4d00             -mov eax, dword ptr [0x4dda2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102124) /* 0x4dda2c */);
    // 004a1ae1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1ae3  c1ed03                 -shr ebp, 3
    cpu.ebp >>= 3 /*0x3*/ % 32;
    // 004a1ae6  f7f5                   -div ebp
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebp;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a1ae8  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004a1aea  83f802                 +cmp eax, 2
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
    // 004a1aed  7cc0                   -jl 0x4a1aaf
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a1aaf;
    }
    // 004a1aef  817b0c80020000         +cmp dword ptr [ebx + 0xc], 0x280
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(640 /*0x280*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1af6  754f                   -jne 0x4a1b47
    if (!cpu.flags.zf)
    {
        goto L_0x004a1b47;
    }
    // 004a1af8  817b08e0010000         +cmp dword ptr [ebx + 8], 0x1e0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(480 /*0x1e0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1aff  7546                   -jne 0x4a1b47
    if (!cpu.flags.zf)
    {
        goto L_0x004a1b47;
    }
    // 004a1b01  83fe10                 +cmp esi, 0x10
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
    // 004a1b04  7541                   -jne 0x4a1b47
    if (!cpu.flags.zf)
    {
        goto L_0x004a1b47;
    }
    // 004a1b06  8b0d30135700           -mov ecx, dword ptr [0x571330]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5706544) /* 0x571330 */);
    // 004a1b0c  83c118                 -add ecx, 0x18
    (cpu.ecx) += x86::reg32(x86::sreg32(24 /*0x18*/));
L_0x004a1b0f:
    // 004a1b0f  8b430c                 -mov eax, dword ptr [ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
    // 004a1b12  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 004a1b14  8b4308                 -mov eax, dword ptr [ebx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004a1b17  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a1b1b  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a1b1e  83fa03                 +cmp edx, 3
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
    // 004a1b21  7505                   -jne 0x4a1b28
    if (!cpu.flags.zf)
    {
        goto L_0x004a1b28;
    }
    // 004a1b23  be0f000000             -mov esi, 0xf
    cpu.esi = 15 /*0xf*/;
L_0x004a1b28:
    // 004a1b28  897108                 -mov dword ptr [ecx + 8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 004a1b2b  896910                 -mov dword ptr [ecx + 0x10], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.ebp;
    // 004a1b2e  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a1b32  896914                 -mov dword ptr [ecx + 0x14], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.ebp;
    // 004a1b35  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a1b38  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a1b3d  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004a1b40  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1b41  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1b42  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1b43  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1b44  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a1b47:
    // 004a1b47  817b0c20030000         +cmp dword ptr [ebx + 0xc], 0x320
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(800 /*0x320*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1b4e  7519                   -jne 0x4a1b69
    if (!cpu.flags.zf)
    {
        goto L_0x004a1b69;
    }
    // 004a1b50  817b0858020000         +cmp dword ptr [ebx + 8], 0x258
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(600 /*0x258*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1b57  7510                   -jne 0x4a1b69
    if (!cpu.flags.zf)
    {
        goto L_0x004a1b69;
    }
    // 004a1b59  83fe10                 +cmp esi, 0x10
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
    // 004a1b5c  750b                   -jne 0x4a1b69
    if (!cpu.flags.zf)
    {
        goto L_0x004a1b69;
    }
    // 004a1b5e  8b0d30135700           -mov ecx, dword ptr [0x571330]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5706544) /* 0x571330 */);
    // 004a1b64  83c130                 +add ecx, 0x30
    {
        x86::reg32& tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a1b67  eba6                   -jmp 0x4a1b0f
    goto L_0x004a1b0f;
L_0x004a1b69:
    // 004a1b69  837c242400             +cmp dword ptr [esp + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1b6e  749f                   -je 0x4a1b0f
    if (cpu.flags.zf)
    {
        goto L_0x004a1b0f;
    }
    // 004a1b70  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a1b72  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a1b73  2eff151c654c00         -call dword ptr cs:[0x4c651c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006620) /* 0x4c651c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1b7a  b918000000             -mov ecx, 0x18
    cpu.ecx = 24 /*0x18*/;
    // 004a1b7f  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a1b83  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1b85  f7f1                   -div ecx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ecx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a1b87  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 004a1b89  39d0                   +cmp eax, edx
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
    // 004a1b8b  761d                   -jbe 0x4a1baa
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a1baa;
    }
    // 004a1b8d  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
    // 004a1b94  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1b96  a130135700             -mov eax, dword ptr [0x571330]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5706544) /* 0x571330 */);
    // 004a1b9b  c1e103                 -shl ecx, 3
    cpu.ecx <<= 3 /*0x3*/ % 32;
    // 004a1b9e  01c1                   +add ecx, eax
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
    // 004a1ba0  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a1ba3  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
    // 004a1ba5  e965ffffff             -jmp 0x4a1b0f
    goto L_0x004a1b0f;
L_0x004a1baa:
    // 004a1baa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1bac  83c428                 -add esp, 0x28
    (cpu.esp) += x86::reg32(x86::sreg32(40 /*0x28*/));
    // 004a1baf  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1bb0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1bb1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1bb2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1bb3  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a1bb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a1bb8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a1bb9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a1bba  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a1bbb  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a1bbc  81ecdc020000           -sub esp, 0x2dc
    (cpu.esp) -= x86::reg32(x86::sreg32(732 /*0x2dc*/));
    // 004a1bc2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a1bc4  8d8424dc020000         -lea eax, [esp + 0x2dc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(732) /* 0x2dc */);
    // 004a1bcb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a1bcc  8b1534da4d00           -mov edx, dword ptr [0x4dda34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5102132) /* 0x4dda34 */);
    // 004a1bd2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a1bd3  e870360200             -call 0x4c5248
    cpu.esp -= 4;
    sub_4c5248(app, cpu);
    if (cpu.terminate) return;
    // 004a1bd8  a3d8d94d00             -mov dword ptr [0x4dd9d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5102040) /* 0x4dd9d8 */) = cpu.eax;
    // 004a1bdd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a1bdf  742e                   -je 0x4a1c0f
    if (cpu.flags.zf)
    {
        goto L_0x004a1c0f;
    }
L_0x004a1be1:
    // 004a1be1  8b3d28da4d00           -mov edi, dword ptr [0x4dda28]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5102120) /* 0x4dda28 */);
    // 004a1be7  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a1be8  2eff1588654c00         -call dword ptr cs:[0x4c6588]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006728) /* 0x4c6588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1bef  8b942404030000         -mov edx, dword ptr [esp + 0x304]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(772) /* 0x304 */);
    // 004a1bf6  a1d8d94d00             -mov eax, dword ptr [0x4dd9d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102040) /* 0x4dd9d8 */);
    // 004a1bfb  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a1bfd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a1c02  81c4dc020000           -add esp, 0x2dc
    (cpu.esp) += x86::reg32(x86::sreg32(732 /*0x2dc*/));
    // 004a1c08  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1c09  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1c0a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1c0b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1c0c  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004a1c0f:
    // 004a1c0f  68fcd94d00             -push 0x4dd9fc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5102076 /*0x4dd9fc*/;
    cpu.esp -= 4;
    // 004a1c14  8b8424dc020000         -mov eax, dword ptr [esp + 0x2dc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(732) /* 0x2dc */);
    // 004a1c1b  68f8274e00             -push 0x4e27f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5122040 /*0x4e27f8*/;
    cpu.esp -= 4;
    // 004a1c20  8b8c24e0020000         -mov ecx, dword ptr [esp + 0x2e0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(736) /* 0x2e0 */);
    // 004a1c27  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a1c29  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a1c2a  ff10                   -call dword ptr [eax]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1c2c  8b9c24d8020000         -mov ebx, dword ptr [esp + 0x2d8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(728) /* 0x2d8 */);
    // 004a1c33  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a1c34  a3d8d94d00             -mov dword ptr [0x4dd9d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5102040) /* 0x4dd9d8 */) = cpu.eax;
    // 004a1c39  ff1514145700           -call dword ptr [0x571414]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706772) /* 0x571414 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1c3f  8bb424d8020000         -mov esi, dword ptr [esp + 0x2d8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(728) /* 0x2d8 */);
    // 004a1c46  8b8424d8020000         -mov eax, dword ptr [esp + 0x2d8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(728) /* 0x2d8 */);
    // 004a1c4d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a1c4e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a1c50  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1c53  833dd8d94d0000         +cmp dword ptr [0x4dd9d8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102040) /* 0x4dd9d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1c5a  7585                   -jne 0x4a1be1
    if (!cpu.flags.zf)
    {
        goto L_0x004a1be1;
    }
    // 004a1c5c  8b2ddcd94d00           -mov ebp, dword ptr [0x4dd9dc]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5102044) /* 0x4dd9dc */);
    // 004a1c62  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a1c63  8b0dd4d94d00           -mov ecx, dword ptr [0x4dd9d4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5102036) /* 0x4dd9d4 */);
    // 004a1c69  a1fcd94d00             -mov eax, dword ptr [0x4dd9fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102076) /* 0x4dd9fc */);
    // 004a1c6e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a1c6f  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a1c71  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a1c72  ff5250                 -call dword ptr [edx + 0x50]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1c75  a3d8d94d00             -mov dword ptr [0x4dd9d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5102040) /* 0x4dd9d8 */) = cpu.eax;
    // 004a1c7a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a1c7c  0f855fffffff           -jne 0x4a1be1
    if (!cpu.flags.zf)
    {
        goto L_0x004a1be1;
    }
    // 004a1c82  bb6c010000             -mov ebx, 0x16c
    cpu.ebx = 364 /*0x16c*/;
    // 004a1c87  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 004a1c89  a1fcd94d00             -mov eax, dword ptr [0x4dd9fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102076) /* 0x4dd9fc */);
    // 004a1c8e  899c246c010000         -mov dword ptr [esp + 0x16c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(364) /* 0x16c */) = cpu.ebx;
    // 004a1c95  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a1c96  8d942470010000         -lea edx, [esp + 0x170]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(368) /* 0x170 */);
    // 004a1c9d  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004a1ca1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a1ca2  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a1ca4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a1ca5  ff512c                 -call dword ptr [ecx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1ca8  e934ffffff             -jmp 0x4a1be1
    goto L_0x004a1be1;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a1cb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a1cb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a1cb1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a1cb2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a1cb3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a1cb4  83ec70                 -sub esp, 0x70
    (cpu.esp) -= x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004a1cb7  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 004a1cbe  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004a1cc5  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1cc7  8b0d30135700           -mov ecx, dword ptr [0x571330]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5706544) /* 0x571330 */);
    // 004a1ccd  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004a1cd0  8bb42494000000         -mov esi, dword ptr [esp + 0x94]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 004a1cd7  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a1cd9  4e                     -dec esi
    (cpu.esi)--;
    // 004a1cda  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 004a1cdd  e8a2020000             -call 0x4a1f84
    cpu.esp -= 4;
    sub_4a1f84(app, cpu);
    if (cpu.terminate) return;
    // 004a1ce2  83fa0f                 +cmp edx, 0xf
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
    // 004a1ce5  7505                   -jne 0x4a1cec
    if (!cpu.flags.zf)
    {
        goto L_0x004a1cec;
    }
    // 004a1ce7  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
L_0x004a1cec:
    // 004a1cec  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a1cee  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a1cf0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a1cf1  8b5104                 -mov edx, dword ptr [ecx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 004a1cf4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a1cf5  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a1cf7  a1fcd94d00             -mov eax, dword ptr [0x4dd9fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102076) /* 0x4dd9fc */);
    // 004a1cfc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a1cfd  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a1cff  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a1d00  ff5354                 -call dword ptr [ebx + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1d03  a3d8d94d00             -mov dword ptr [0x4dd9d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5102040) /* 0x4dd9d8 */) = cpu.eax;
    // 004a1d08  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a1d0a  742b                   -je 0x4a1d37
    if (cpu.flags.zf)
    {
        goto L_0x004a1d37;
    }
L_0x004a1d0c:
    // 004a1d0c  8b1528da4d00           -mov edx, dword ptr [0x4dda28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5102120) /* 0x4dda28 */);
    // 004a1d12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a1d13  2eff1588654c00         -call dword ptr cs:[0x4c6588]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006728) /* 0x4c6588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1d1a  8b942498000000         -mov edx, dword ptr [esp + 0x98]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 004a1d21  a1d8d94d00             -mov eax, dword ptr [0x4dd9d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102040) /* 0x4dd9d8 */);
    // 004a1d26  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004a1d28  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a1d2d  83c470                 -add esp, 0x70
    (cpu.esp) += x86::reg32(x86::sreg32(112 /*0x70*/));
    // 004a1d30  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1d31  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1d32  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1d33  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1d34  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
L_0x004a1d37:
    // 004a1d37  bb6c000000             -mov ebx, 0x6c
    cpu.ebx = 108 /*0x6c*/;
    // 004a1d3c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a1d3e  bd6c000000             -mov ebp, 0x6c
    cpu.ebp = 108 /*0x6c*/;
    // 004a1d43  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1d45  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 004a1d47  e8e308ffff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004a1d4c  b821000000             -mov eax, 0x21
    cpu.eax = 33 /*0x21*/;
    // 004a1d51  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a1d53  ba18420000             -mov edx, 0x4218
    cpu.edx = 16920 /*0x4218*/;
    // 004a1d58  896c2404               -mov dword ptr [esp + 4], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 004a1d5c  6800da4d00             -push 0x4dda00
    app->getMemory<x86::reg32>(cpu.esp-4) = 5102080 /*0x4dda00*/;
    cpu.esp -= 4;
    // 004a1d61  8974241c               -mov dword ptr [esp + 0x1c], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.esi;
    // 004a1d65  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a1d69  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a1d6a  a1fcd94d00             -mov eax, dword ptr [0x4dd9fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102076) /* 0x4dd9fc */);
    // 004a1d6f  89542474               -mov dword ptr [esp + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 004a1d73  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a1d74  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a1d76  ff5218                 -call dword ptr [edx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1d79  a3d8d94d00             -mov dword ptr [0x4dd9d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5102040) /* 0x4dd9d8 */) = cpu.eax;
    // 004a1d7e  3d7c017688             +cmp eax, 0x8876017c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435004 /*0x8876017c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1d83  7533                   -jne 0x4a1db8
    if (!cpu.flags.zf)
    {
        goto L_0x004a1db8;
    }
L_0x004a1d85:
    // 004a1d85  837c241401             +cmp dword ptr [esp + 0x14], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1d8a  762c                   -jbe 0x4a1db8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a1db8;
    }
    // 004a1d8c  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a1d90  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a1d92  49                     -dec ecx
    (cpu.ecx)--;
    // 004a1d93  6800da4d00             -push 0x4dda00
    app->getMemory<x86::reg32>(cpu.esp-4) = 5102080 /*0x4dda00*/;
    cpu.esp -= 4;
    // 004a1d98  894c241c               -mov dword ptr [esp + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004a1d9c  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a1da0  a1fcd94d00             -mov eax, dword ptr [0x4dd9fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102076) /* 0x4dd9fc */);
    // 004a1da5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a1da6  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a1da8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a1da9  ff5218                 -call dword ptr [edx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1dac  a3d8d94d00             -mov dword ptr [0x4dd9d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5102040) /* 0x4dd9d8 */) = cpu.eax;
    // 004a1db1  3d7c017688             +cmp eax, 0x8876017c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435004 /*0x8876017c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1db6  74cd                   -je 0x4a1d85
    if (cpu.flags.zf)
    {
        goto L_0x004a1d85;
    }
L_0x004a1db8:
    // 004a1db8  8b3500da4d00           -mov esi, dword ptr [0x4dda00]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5102080) /* 0x4dda00 */);
    // 004a1dbe  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a1dc0  740f                   -je 0x4a1dd1
    if (cpu.flags.zf)
    {
        goto L_0x004a1dd1;
    }
    // 004a1dc2  6808da4d00             -push 0x4dda08
    app->getMemory<x86::reg32>(cpu.esp-4) = 5102088 /*0x4dda08*/;
    cpu.esp -= 4;
    // 004a1dc7  6808284e00             -push 0x4e2808
    app->getMemory<x86::reg32>(cpu.esp-4) = 5122056 /*0x4e2808*/;
    cpu.esp -= 4;
    // 004a1dcc  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004a1dce  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a1dcf  ff12                   -call dword ptr [edx]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004a1dd1:
    // 004a1dd1  8b3d08da4d00           -mov edi, dword ptr [0x4dda08]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5102088) /* 0x4dda08 */);
    // 004a1dd7  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a1dd9  0f842dffffff           -je 0x4a1d0c
    if (cpu.flags.zf)
    {
        goto L_0x004a1d0c;
    }
    // 004a1ddf  833d0cda4d0000         +cmp dword ptr [0x4dda0c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102092) /* 0x4dda0c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1de6  0f8520ffffff           -jne 0x4a1d0c
    if (!cpu.flags.zf)
    {
        goto L_0x004a1d0c;
    }
    // 004a1dec  680cda4d00             -push 0x4dda0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5102092 /*0x4dda0c*/;
    cpu.esp -= 4;
    // 004a1df1  8d4c2470               -lea ecx, [esp + 0x70]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(112) /* 0x70 */);
    // 004a1df5  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004a1dfa  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a1dfb  89442474               -mov dword ptr [esp + 0x74], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.eax;
    // 004a1dff  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a1e00  8b17                   -mov edx, dword ptr [edi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi);
    // 004a1e02  ff5230                 -call dword ptr [edx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1e05  a3d8d94d00             -mov dword ptr [0x4dd9d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5102040) /* 0x4dd9d8 */) = cpu.eax;
    // 004a1e0a  e9fdfeffff             -jmp 0x4a1d0c
    goto L_0x004a1d0c;
}

/* align: skip 0x90 */
void Application::sub_4a1e10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a1e10  e86f010000             -call 0x4a1f84
    cpu.esp -= 4;
    sub_4a1f84(app, cpu);
    if (cpu.terminate) return;
    // 004a1e15  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a1e17  ff1514145700           -call dword ptr [0x571414]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706772) /* 0x571414 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1e1d  a1fcd94d00             -mov eax, dword ptr [0x4dd9fc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102076) /* 0x4dd9fc */);
    // 004a1e22  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a1e23  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a1e25  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1e28  8b0d28da4d00           -mov ecx, dword ptr [0x4dda28]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5102120) /* 0x4dda28 */);
    // 004a1e2e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a1e30  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a1e31  8915fcd94d00           -mov dword ptr [0x4dd9fc], edx
    app->getMemory<x86::reg32>(x86::reg32(5102076) /* 0x4dd9fc */) = cpu.edx;
    // 004a1e37  2eff1588654c00         -call dword ptr cs:[0x4c6588]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006728) /* 0x4c6588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1e3e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a1e43  c21800                 -ret 0x18
    cpu.esp += 4+24 /*0x18*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a1e48(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a1e48  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a1e49  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a1e4a  8b1528da4d00           -mov edx, dword ptr [0x4dda28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5102120) /* 0x4dda28 */);
    // 004a1e50  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a1e52  7510                   -jne 0x4a1e64
    if (!cpu.flags.zf)
    {
        goto L_0x004a1e64;
    }
    // 004a1e54  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a1e55  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a1e56  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a1e57  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a1e58  2eff1558644c00         -call dword ptr cs:[0x4c6458]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006424) /* 0x4c6458 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1e5f  a328da4d00             -mov dword ptr [0x4dda28], eax
    app->getMemory<x86::reg32>(x86::reg32(5102120) /* 0x4dda28 */) = cpu.eax;
L_0x004a1e64:
    // 004a1e64  ff1508145700           -call dword ptr [0x571408]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706760) /* 0x571408 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1e6a  a3d4d94d00             -mov dword ptr [0x4dd9d4], eax
    app->getMemory<x86::reg32>(x86::reg32(5102036) /* 0x4dd9d4 */) = cpu.eax;
    // 004a1e6f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a1e71  7512                   -jne 0x4a1e85
    if (!cpu.flags.zf)
    {
        goto L_0x004a1e85;
    }
    // 004a1e73  c705d8d94d0078050000   -mov dword ptr [0x4dd9d8], 0x578
    app->getMemory<x86::reg32>(x86::reg32(5102040) /* 0x4dd9d8 */) = 1400 /*0x578*/;
    // 004a1e7d  a1d8d94d00             -mov eax, dword ptr [0x4dd9d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102040) /* 0x4dd9d8 */);
    // 004a1e82  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1e83  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1e84  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a1e85:
    // 004a1e85  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a1e86  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a1e87  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a1e88  68b81b4a00             -push 0x4a1bb8
    app->getMemory<x86::reg32>(cpu.esp-4) = 4856760 /*0x4a1bb8*/;
    cpu.esp -= 4;
    // 004a1e8d  6864040000             -push 0x464
    app->getMemory<x86::reg32>(cpu.esp-4) = 1124 /*0x464*/;
    cpu.esp -= 4;
    // 004a1e92  ff150c145700           -call dword ptr [0x57140c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706764) /* 0x57140c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1e98  68101e4a00             -push 0x4a1e10
    app->getMemory<x86::reg32>(cpu.esp-4) = 4857360 /*0x4a1e10*/;
    cpu.esp -= 4;
    // 004a1e9d  6868040000             -push 0x468
    app->getMemory<x86::reg32>(cpu.esp-4) = 1128 /*0x468*/;
    cpu.esp -= 4;
    // 004a1ea2  ff150c145700           -call dword ptr [0x57140c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706764) /* 0x57140c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1ea8  68b01c4a00             -push 0x4a1cb0
    app->getMemory<x86::reg32>(cpu.esp-4) = 4857008 /*0x4a1cb0*/;
    cpu.esp -= 4;
    // 004a1ead  6865040000             -push 0x465
    app->getMemory<x86::reg32>(cpu.esp-4) = 1125 /*0x465*/;
    cpu.esp -= 4;
    // 004a1eb2  ff150c145700           -call dword ptr [0x57140c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706764) /* 0x57140c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1eb8  8a25dcd94d00           -mov ah, byte ptr [0x4dd9dc]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5102044) /* 0x4dd9dc */);
    // 004a1ebe  80e4e6                 -and ah, 0xe6
    cpu.ah &= x86::reg8(x86::sreg8(230 /*0xe6*/));
    // 004a1ec1  8b1dd4d94d00           -mov ebx, dword ptr [0x4dd9d4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5102036) /* 0x4dd9d4 */);
    // 004a1ec7  88e2                   -mov dl, ah
    cpu.dl = cpu.ah;
    // 004a1ec9  8825dcd94d00           -mov byte ptr [0x4dd9dc], ah
    app->getMemory<x86::reg8>(x86::reg32(5102044) /* 0x4dd9dc */) = cpu.ah;
    // 004a1ecf  80ca11                 -or dl, 0x11
    cpu.dl |= x86::reg8(x86::sreg8(17 /*0x11*/));
    // 004a1ed2  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a1ed3  8815dcd94d00           -mov byte ptr [0x4dd9dc], dl
    app->getMemory<x86::reg8>(x86::reg32(5102044) /* 0x4dd9dc */) = cpu.dl;
    // 004a1ed9  2eff1528644c00         -call dword ptr cs:[0x4c6428]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006376) /* 0x4c6428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1ee0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a1ee2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a1ee4  6864040000             -push 0x464
    app->getMemory<x86::reg32>(cpu.esp-4) = 1124 /*0x464*/;
    cpu.esp -= 4;
    // 004a1ee9  8b35d4d94d00           -mov esi, dword ptr [0x4dd9d4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5102036) /* 0x4dd9d4 */);
    // 004a1eef  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a1ef0  2eff1508644c00         -call dword ptr cs:[0x4c6408]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006344) /* 0x4c6408 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1ef7  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004a1ef9  8b3d28da4d00           -mov edi, dword ptr [0x4dda28]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5102120) /* 0x4dda28 */);
    // 004a1eff  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a1f00  2eff15d8654c00         -call dword ptr cs:[0x4c65d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006808) /* 0x4c65d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1f07  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1f08  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1f09  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1f0a  a1d8d94d00             -mov eax, dword ptr [0x4dd9d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102040) /* 0x4dd9d8 */);
    // 004a1f0f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1f10  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1f11  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a1f14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a1f14  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a1f15  833dfcd94d0000         +cmp dword ptr [0x4dd9fc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102076) /* 0x4dd9fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1f1c  7504                   -jne 0x4a1f22
    if (!cpu.flags.zf)
    {
        goto L_0x004a1f22;
    }
    // 004a1f1e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a1f20  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1f21  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a1f22:
    // 004a1f22  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a1f23  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a1f24  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a1f25  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a1f26  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a1f27  8b0dd4d94d00           -mov ecx, dword ptr [0x4dd9d4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5102036) /* 0x4dd9d4 */);
    // 004a1f2d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a1f2e  2eff1528644c00         -call dword ptr cs:[0x4c6428]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006376) /* 0x4c6428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1f35  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a1f37  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a1f39  6868040000             -push 0x468
    app->getMemory<x86::reg32>(cpu.esp-4) = 1128 /*0x468*/;
    cpu.esp -= 4;
    // 004a1f3e  8b1dd4d94d00           -mov ebx, dword ptr [0x4dd9d4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5102036) /* 0x4dd9d4 */);
    // 004a1f44  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a1f45  2eff1508644c00         -call dword ptr cs:[0x4c6408]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006344) /* 0x4c6408 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1f4c  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004a1f4e  8b3528da4d00           -mov esi, dword ptr [0x4dda28]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5102120) /* 0x4dda28 */);
    // 004a1f54  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a1f55  2eff15d8654c00         -call dword ptr cs:[0x4c65d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006808) /* 0x4c65d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1f5c  8b3d28da4d00           -mov edi, dword ptr [0x4dda28]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5102120) /* 0x4dda28 */);
    // 004a1f62  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a1f63  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a1f65  2eff1554644c00         -call dword ptr cs:[0x4c6454]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006420) /* 0x4c6454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1f6c  a1d8d94d00             -mov eax, dword ptr [0x4dd9d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102040) /* 0x4dd9d8 */);
    // 004a1f71  892d28da4d00           -mov dword ptr [0x4dda28], ebp
    app->getMemory<x86::reg32>(x86::reg32(5102120) /* 0x4dda28 */) = cpu.ebp;
    // 004a1f77  892dd4d94d00           -mov dword ptr [0x4dd9d4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5102036) /* 0x4dd9d4 */) = cpu.ebp;
    // 004a1f7d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1f7e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1f7f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1f80  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1f81  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1f82  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1f83  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a1f84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a1f84  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a1f85  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a1f86  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a1f87  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a1f88  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
L_0x004a1f8d:
    // 004a1f8d  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a1f90  83fbfc                 +cmp ebx, -4
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-4 /*-0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a1f93  741a                   -je 0x4a1faf
    if (cpu.flags.zf)
    {
        goto L_0x004a1faf;
    }
    // 004a1f95  8b8b04da4d00           -mov ecx, dword ptr [ebx + 0x4dda04]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5102084) /* 0x4dda04 */);
    // 004a1f9b  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a1f9d  74ee                   -je 0x4a1f8d
    if (cpu.flags.zf)
    {
        goto L_0x004a1f8d;
    }
    // 004a1f9f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a1fa0  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a1fa2  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004a1fa4  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1fa7  89b304da4d00           -mov dword ptr [ebx + 0x4dda04], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5102084) /* 0x4dda04 */) = cpu.esi;
    // 004a1fad  ebde                   -jmp 0x4a1f8d
    goto L_0x004a1f8d;
L_0x004a1faf:
    // 004a1faf  8b1500da4d00           -mov edx, dword ptr [0x4dda00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5102080) /* 0x4dda00 */);
    // 004a1fb5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a1fb7  7505                   -jne 0x4a1fbe
    if (!cpu.flags.zf)
    {
        goto L_0x004a1fbe;
    }
    // 004a1fb9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1fba  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1fbb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1fbc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1fbd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a1fbe:
    // 004a1fbe  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a1fc0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a1fc1  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 004a1fc3  ff5208                 -call dword ptr [edx + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1fc6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1fc7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1fc8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1fc9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a1fca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a1fcc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a1fcc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a1fcd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a1fce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a1fcf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a1fd0  83ec34                 -sub esp, 0x34
    (cpu.esp) -= x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004a1fd3  8b1520145700           -mov edx, dword ptr [0x571420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5706784) /* 0x571420 */);
    // 004a1fd9  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a1fde  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a1fe0  0f8591010000           -jne 0x4a2177
    if (!cpu.flags.zf)
    {
        goto L_0x004a2177;
    }
    // 004a1fe6  6824114d00             -push 0x4d1124
    app->getMemory<x86::reg32>(cpu.esp-4) = 5050660 /*0x4d1124*/;
    cpu.esp -= 4;
    // 004a1feb  2eff1544654c00         -call dword ptr cs:[0x4c6544]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006660) /* 0x4c6544 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a1ff2  a320145700             -mov dword ptr [0x571420], eax
    app->getMemory<x86::reg32>(x86::reg32(5706784) /* 0x571420 */) = cpu.eax;
    // 004a1ff7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a1ff9  0f8405020000           -je 0x4a2204
    if (cpu.flags.zf)
    {
        goto L_0x004a2204;
    }
    // 004a1fff  682c114d00             -push 0x4d112c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5050668 /*0x4d112c*/;
    cpu.esp -= 4;
    // 004a2004  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a2005  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a200c  6844114d00             -push 0x4d1144
    app->getMemory<x86::reg32>(cpu.esp-4) = 5050692 /*0x4d1144*/;
    cpu.esp -= 4;
    // 004a2011  8b0d20145700           -mov ecx, dword ptr [0x571420]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5706784) /* 0x571420 */);
    // 004a2017  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2018  a324145700             -mov dword ptr [0x571424], eax
    app->getMemory<x86::reg32>(x86::reg32(5706788) /* 0x571424 */) = cpu.eax;
    // 004a201d  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2024  6860114d00             -push 0x4d1160
    app->getMemory<x86::reg32>(cpu.esp-4) = 5050720 /*0x4d1160*/;
    cpu.esp -= 4;
    // 004a2029  8b1d20145700           -mov ebx, dword ptr [0x571420]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5706784) /* 0x571420 */);
    // 004a202f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2030  a328145700             -mov dword ptr [0x571428], eax
    app->getMemory<x86::reg32>(x86::reg32(5706792) /* 0x571428 */) = cpu.eax;
    // 004a2035  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a203c  6874114d00             -push 0x4d1174
    app->getMemory<x86::reg32>(cpu.esp-4) = 5050740 /*0x4d1174*/;
    cpu.esp -= 4;
    // 004a2041  8b3d20145700           -mov edi, dword ptr [0x571420]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5706784) /* 0x571420 */);
    // 004a2047  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2048  a32c145700             -mov dword ptr [0x57142c], eax
    app->getMemory<x86::reg32>(x86::reg32(5706796) /* 0x57142c */) = cpu.eax;
    // 004a204d  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2054  6890114d00             -push 0x4d1190
    app->getMemory<x86::reg32>(cpu.esp-4) = 5050768 /*0x4d1190*/;
    cpu.esp -= 4;
    // 004a2059  8b2d20145700           -mov ebp, dword ptr [0x571420]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5706784) /* 0x571420 */);
    // 004a205f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a2060  a330145700             -mov dword ptr [0x571430], eax
    app->getMemory<x86::reg32>(x86::reg32(5706800) /* 0x571430 */) = cpu.eax;
    // 004a2065  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a206c  68a4114d00             -push 0x4d11a4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5050788 /*0x4d11a4*/;
    cpu.esp -= 4;
    // 004a2071  a334145700             -mov dword ptr [0x571434], eax
    app->getMemory<x86::reg32>(x86::reg32(5706804) /* 0x571434 */) = cpu.eax;
    // 004a2076  a120145700             -mov eax, dword ptr [0x571420]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5706784) /* 0x571420 */);
    // 004a207b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a207c  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2083  68b4114d00             -push 0x4d11b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5050804 /*0x4d11b4*/;
    cpu.esp -= 4;
    // 004a2088  8b1520145700           -mov edx, dword ptr [0x571420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5706784) /* 0x571420 */);
    // 004a208e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a208f  a338145700             -mov dword ptr [0x571438], eax
    app->getMemory<x86::reg32>(x86::reg32(5706808) /* 0x571438 */) = cpu.eax;
    // 004a2094  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a209b  68cc114d00             -push 0x4d11cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5050828 /*0x4d11cc*/;
    cpu.esp -= 4;
    // 004a20a0  8b0d20145700           -mov ecx, dword ptr [0x571420]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5706784) /* 0x571420 */);
    // 004a20a6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a20a7  a33c145700             -mov dword ptr [0x57143c], eax
    app->getMemory<x86::reg32>(x86::reg32(5706812) /* 0x57143c */) = cpu.eax;
    // 004a20ac  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a20b3  68e0114d00             -push 0x4d11e0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5050848 /*0x4d11e0*/;
    cpu.esp -= 4;
    // 004a20b8  8b1d20145700           -mov ebx, dword ptr [0x571420]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5706784) /* 0x571420 */);
    // 004a20be  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a20bf  a340145700             -mov dword ptr [0x571440], eax
    app->getMemory<x86::reg32>(x86::reg32(5706816) /* 0x571440 */) = cpu.eax;
    // 004a20c4  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a20cb  68f4114d00             -push 0x4d11f4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5050868 /*0x4d11f4*/;
    cpu.esp -= 4;
    // 004a20d0  8b3d20145700           -mov edi, dword ptr [0x571420]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5706784) /* 0x571420 */);
    // 004a20d6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a20d7  a344145700             -mov dword ptr [0x571444], eax
    app->getMemory<x86::reg32>(x86::reg32(5706820) /* 0x571444 */) = cpu.eax;
    // 004a20dc  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a20e3  6804124d00             -push 0x4d1204
    app->getMemory<x86::reg32>(cpu.esp-4) = 5050884 /*0x4d1204*/;
    cpu.esp -= 4;
    // 004a20e8  8b2d20145700           -mov ebp, dword ptr [0x571420]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5706784) /* 0x571420 */);
    // 004a20ee  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a20ef  a348145700             -mov dword ptr [0x571448], eax
    app->getMemory<x86::reg32>(x86::reg32(5706824) /* 0x571448 */) = cpu.eax;
    // 004a20f4  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a20fb  681c124d00             -push 0x4d121c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5050908 /*0x4d121c*/;
    cpu.esp -= 4;
    // 004a2100  a34c145700             -mov dword ptr [0x57144c], eax
    app->getMemory<x86::reg32>(x86::reg32(5706828) /* 0x57144c */) = cpu.eax;
    // 004a2105  a120145700             -mov eax, dword ptr [0x571420]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5706784) /* 0x571420 */);
    // 004a210a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a210b  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2112  6830124d00             -push 0x4d1230
    app->getMemory<x86::reg32>(cpu.esp-4) = 5050928 /*0x4d1230*/;
    cpu.esp -= 4;
    // 004a2117  8b1520145700           -mov edx, dword ptr [0x571420]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5706784) /* 0x571420 */);
    // 004a211d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a211e  a350145700             -mov dword ptr [0x571450], eax
    app->getMemory<x86::reg32>(x86::reg32(5706832) /* 0x571450 */) = cpu.eax;
    // 004a2123  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a212a  a354145700             -mov dword ptr [0x571454], eax
    app->getMemory<x86::reg32>(x86::reg32(5706836) /* 0x571454 */) = cpu.eax;
    // 004a212f  6840124d00             -push 0x4d1240
    app->getMemory<x86::reg32>(cpu.esp-4) = 5050944 /*0x4d1240*/;
    cpu.esp -= 4;
    // 004a2134  8b0d20145700           -mov ecx, dword ptr [0x571420]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5706784) /* 0x571420 */);
    // 004a213a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a213b  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2142  6850124d00             -push 0x4d1250
    app->getMemory<x86::reg32>(cpu.esp-4) = 5050960 /*0x4d1250*/;
    cpu.esp -= 4;
    // 004a2147  8b1d20145700           -mov ebx, dword ptr [0x571420]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5706784) /* 0x571420 */);
    // 004a214d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a214e  a358145700             -mov dword ptr [0x571458], eax
    app->getMemory<x86::reg32>(x86::reg32(5706840) /* 0x571458 */) = cpu.eax;
    // 004a2153  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a215a  6860124d00             -push 0x4d1260
    app->getMemory<x86::reg32>(cpu.esp-4) = 5050976 /*0x4d1260*/;
    cpu.esp -= 4;
    // 004a215f  8b3d20145700           -mov edi, dword ptr [0x571420]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5706784) /* 0x571420 */);
    // 004a2165  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2166  a35c145700             -mov dword ptr [0x57145c], eax
    app->getMemory<x86::reg32>(x86::reg32(5706844) /* 0x57145c */) = cpu.eax;
    // 004a216b  2eff1514654c00         -call dword ptr cs:[0x4c6514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006612) /* 0x4c6514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2172  a360145700             -mov dword ptr [0x571460], eax
    app->getMemory<x86::reg32>(x86::reg32(5706848) /* 0x571460 */) = cpu.eax;
L_0x004a2177:
    // 004a2177  bb90000000             -mov ebx, 0x90
    cpu.ebx = 144 /*0x90*/;
    // 004a217c  b870135700             -mov eax, 0x571370
    cpu.eax = 5706608 /*0x571370*/;
    // 004a2181  bd01000000             -mov ebp, 1
    cpu.ebp = 1 /*0x1*/;
    // 004a2186  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a2188  b90000803f             -mov ecx, 0x3f800000
    cpu.ecx = 1065353216 /*0x3f800000*/;
    // 004a218d  e89d04ffff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004a2192  ba11000800             -mov edx, 0x80011
    cpu.edx = 524305 /*0x80011*/;
    // 004a2197  892d94135700           -mov dword ptr [0x571394], ebp
    app->getMemory<x86::reg32>(x86::reg32(5706644) /* 0x571394 */) = cpu.ebp;
    // 004a219d  890d74135700           -mov dword ptr [0x571374], ecx
    app->getMemory<x86::reg32>(x86::reg32(5706612) /* 0x571374 */) = cpu.ecx;
    // 004a21a3  890d78135700           -mov dword ptr [0x571378], ecx
    app->getMemory<x86::reg32>(x86::reg32(5706616) /* 0x571378 */) = cpu.ecx;
    // 004a21a9  890d7c135700           -mov dword ptr [0x57137c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5706620) /* 0x57137c */) = cpu.ecx;
    // 004a21af  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a21b1  8b0d30135700           -mov ecx, dword ptr [0x571330]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5706544) /* 0x571330 */);
    // 004a21b7  a384135700             -mov dword ptr [0x571384], eax
    app->getMemory<x86::reg32>(x86::reg32(5706628) /* 0x571384 */) = cpu.eax;
    // 004a21bc  891588135700           -mov dword ptr [0x571388], edx
    app->getMemory<x86::reg32>(x86::reg32(5706632) /* 0x571388 */) = cpu.edx;
    // 004a21c2  a398135700             -mov dword ptr [0x571398], eax
    app->getMemory<x86::reg32>(x86::reg32(5706648) /* 0x571398 */) = cpu.eax;
    // 004a21c7  a39c135700             -mov dword ptr [0x57139c], eax
    app->getMemory<x86::reg32>(x86::reg32(5706652) /* 0x57139c */) = cpu.eax;
    // 004a21cc  a3a0135700             -mov dword ptr [0x5713a0], eax
    app->getMemory<x86::reg32>(x86::reg32(5706656) /* 0x5713a0 */) = cpu.eax;
    // 004a21d1  a3a4135700             -mov dword ptr [0x5713a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5706660) /* 0x5713a4 */) = cpu.eax;
    // 004a21d6  a3d8135700             -mov dword ptr [0x5713d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5706712) /* 0x5713d8 */) = cpu.eax;
    // 004a21db  a3ac135700             -mov dword ptr [0x5713ac], eax
    app->getMemory<x86::reg32>(x86::reg32(5706668) /* 0x5713ac */) = cpu.eax;
    // 004a21e0  a3b0135700             -mov dword ptr [0x5713b0], eax
    app->getMemory<x86::reg32>(x86::reg32(5706672) /* 0x5713b0 */) = cpu.eax;
    // 004a21e5  a3b4135700             -mov dword ptr [0x5713b4], eax
    app->getMemory<x86::reg32>(x86::reg32(5706676) /* 0x5713b4 */) = cpu.eax;
    // 004a21ea  a3dc135700             -mov dword ptr [0x5713dc], eax
    app->getMemory<x86::reg32>(x86::reg32(5706716) /* 0x5713dc */) = cpu.eax;
    // 004a21ef  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a21f1  7504                   -jne 0x4a21f7
    if (!cpu.flags.zf)
    {
        goto L_0x004a21f7;
    }
    // 004a21f3  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a21f5  7514                   -jne 0x4a220b
    if (!cpu.flags.zf)
    {
        goto L_0x004a220b;
    }
L_0x004a21f7:
    // 004a21f7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a21fc  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004a21ff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2200  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2201  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2202  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2203  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2204:
    // 004a2204  31f6                   +xor esi, esi
    cpu.clear_co();
    cpu.set_szp((cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi))));
    // 004a2206  e96cffffff             -jmp 0x4a2177
    goto L_0x004a2177;
L_0x004a220b:
    // 004a220b  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 004a220f  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004a2213  8944242c               -mov dword ptr [esp + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004a2217  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a2219  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a221a  2eff151c654c00         -call dword ptr cs:[0x4c651c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006620) /* 0x4c651c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2221  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004a2223  6800300000             -push 0x3000
    app->getMemory<x86::reg32>(cpu.esp-4) = 12288 /*0x3000*/;
    cpu.esp -= 4;
    // 004a2228  8b6c240c               -mov ebp, dword ptr [esp + 0xc]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a222c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a222d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a222f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2230  2eff15c4654c00         -call dword ptr cs:[0x4c65c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006788) /* 0x4c65c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2237  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a223b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a223d  a330135700             -mov dword ptr [0x571330], eax
    app->getMemory<x86::reg32>(x86::reg32(5706544) /* 0x571330 */) = cpu.eax;
    // 004a2242  e8e803ffff             -call 0x49262f
    cpu.esp -= 4;
    sub_49262f(app, cpu);
    if (cpu.terminate) return;
    // 004a2247  a130135700             -mov eax, dword ptr [0x571330]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5706544) /* 0x571330 */);
    // 004a224c  c7401880020000         -mov dword ptr [eax + 0x18], 0x280
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 640 /*0x280*/;
    // 004a2253  c7401ce0010000         -mov dword ptr [eax + 0x1c], 0x1e0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 480 /*0x1e0*/;
    // 004a225a  c7402010000000         -mov dword ptr [eax + 0x20], 0x10
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 16 /*0x10*/;
    // 004a2261  c7402404000000         -mov dword ptr [eax + 0x24], 4
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = 4 /*0x4*/;
    // 004a2268  c7402801000000         -mov dword ptr [eax + 0x28], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 1 /*0x1*/;
    // 004a226f  c7402c01000000         -mov dword ptr [eax + 0x2c], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(44) /* 0x2c */) = 1 /*0x1*/;
    // 004a2276  c7403020030000         -mov dword ptr [eax + 0x30], 0x320
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */) = 800 /*0x320*/;
    // 004a227d  c7403458020000         -mov dword ptr [eax + 0x34], 0x258
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */) = 600 /*0x258*/;
    // 004a2284  c7403810000000         -mov dword ptr [eax + 0x38], 0x10
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(56) /* 0x38 */) = 16 /*0x10*/;
    // 004a228b  c7403c04000000         -mov dword ptr [eax + 0x3c], 4
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */) = 4 /*0x4*/;
    // 004a2292  c7404001000000         -mov dword ptr [eax + 0x40], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = 1 /*0x1*/;
    // 004a2299  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a229b  c7404401000000         -mov dword ptr [eax + 0x44], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */) = 1 /*0x1*/;
    // 004a22a2  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 004a22a7  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a22a8  a32c135700             -mov dword ptr [0x57132c], eax
    app->getMemory<x86::reg32>(x86::reg32(5706540) /* 0x57132c */) = cpu.eax;
    // 004a22ad  8d44242c               -lea eax, [esp + 0x2c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a22b1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a22b2  8b1534da4d00           -mov edx, dword ptr [0x4dda34]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5102132) /* 0x4dda34 */);
    // 004a22b8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a22b9  e88a2f0200             -call 0x4c5248
    cpu.esp -= 4;
    sub_4c5248(app, cpu);
    if (cpu.terminate) return;
    // 004a22be  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a22c2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a22c4  0f847f000000           -je 0x4a2349
    if (cpu.flags.zf)
    {
        goto L_0x004a2349;
    }
    // 004a22ca  8d44242c               -lea eax, [esp + 0x2c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a22ce  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a22cf  68f8274e00             -push 0x4e27f8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5122040 /*0x4e27f8*/;
    cpu.esp -= 4;
    // 004a22d4  8b31                   -mov esi, dword ptr [ecx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a22d6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a22d7  ff16                   -call dword ptr [esi]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a22d9  8b74242c               -mov esi, dword ptr [esp + 0x2c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a22dd  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a22df  745a                   -je 0x4a233b
    if (cpu.flags.zf)
    {
        goto L_0x004a233b;
    }
    // 004a22e1  682cda4d00             -push 0x4dda2c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5102124 /*0x4dda2c*/;
    cpu.esp -= 4;
    // 004a22e6  8d442428               -lea eax, [esp + 0x28]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a22ea  bf00400000             -mov edi, 0x4000
    cpu.edi = 16384 /*0x4000*/;
    // 004a22ef  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a22f0  8d442438               -lea eax, [esp + 0x38]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004a22f4  897c2438               -mov dword ptr [esp + 0x38], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.edi;
    // 004a22f8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a22f9  8b6c2438               -mov ebp, dword ptr [esp + 0x38]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004a22fd  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 004a22ff  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a2300  ff565c                 -call dword ptr [esi + 0x5c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(92) /* 0x5c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2303  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a2305  740a                   -je 0x4a2311
    if (cpu.flags.zf)
    {
        goto L_0x004a2311;
    }
    // 004a2307  c7052cda4d0000002000   -mov dword ptr [0x4dda2c], 0x200000
    app->getMemory<x86::reg32>(x86::reg32(5102124) /* 0x4dda2c */) = 2097152 /*0x200000*/;
L_0x004a2311:
    // 004a2311  68801a4a00             -push 0x4a1a80
    app->getMemory<x86::reg32>(cpu.esp-4) = 4856448 /*0x4a1a80*/;
    cpu.esp -= 4;
    // 004a2316  682c135700             -push 0x57132c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706540 /*0x57132c*/;
    cpu.esp -= 4;
    // 004a231b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a231d  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 004a2321  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a2323  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 004a2327  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a2329  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a232a  ff5020                 -call dword ptr [eax + 0x20]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a232d  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a2331  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a2335  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2336  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a2338  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004a233b:
    // 004a233b  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a233f  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a2343  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2344  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a2346  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004a2349:
    // 004a2349  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a234d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a234e  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004a2350  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a2354  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2355  8b3d30135700           -mov edi, dword ptr [0x571330]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5706544) /* 0x571330 */);
    // 004a235b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a235c  2eff15cc654c00         -call dword ptr cs:[0x4c65cc]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006796) /* 0x4c65cc */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2363  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a2368  83c434                 -add esp, 0x34
    (cpu.esp) += x86::reg32(x86::sreg32(52 /*0x34*/));
    // 004a236b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a236c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a236d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a236e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a236f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2370  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2371  833d00da4d0000         +cmp dword ptr [0x4dda00], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102080) /* 0x4dda00 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2378  7547                   -jne 0x4a23c1
    if (!cpu.flags.zf)
    {
        goto L_0x004a23c1;
    }
L_0x004a237a:
    // 004a237a  8b0d30da4d00           -mov ecx, dword ptr [0x4dda30]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5102128) /* 0x4dda30 */);
    // 004a2380  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a2382  7414                   -je 0x4a2398
    if (cpu.flags.zf)
    {
        goto L_0x004a2398;
    }
    // 004a2384  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2385  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2386  ff152c145700           -call dword ptr [0x57142c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706796) /* 0x57142c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a238c  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a238e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a2391  893530da4d00           -mov dword ptr [0x4dda30], esi
    app->getMemory<x86::reg32>(x86::reg32(5102128) /* 0x4dda30 */) = cpu.esi;
    // 004a2397  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004a2398:
    // 004a2398  8b3d20145700           -mov edi, dword ptr [0x571420]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5706784) /* 0x571420 */);
    // 004a239e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a23a0  740f                   -je 0x4a23b1
    if (cpu.flags.zf)
    {
        goto L_0x004a23b1;
    }
    // 004a23a2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a23a3  2eff159c644c00         -call dword ptr cs:[0x4c649c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006492) /* 0x4c649c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a23aa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a23ac  a320145700             -mov dword ptr [0x571420], eax
    app->getMemory<x86::reg32>(x86::reg32(5706784) /* 0x571420 */) = cpu.eax;
L_0x004a23b1:
    // 004a23b1  e85efbffff             -call 0x4a1f14
    cpu.esp -= 4;
    sub_4a1f14(app, cpu);
    if (cpu.terminate) return;
    // 004a23b6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a23b8  7515                   -jne 0x4a23cf
    if (!cpu.flags.zf)
    {
        goto L_0x004a23cf;
    }
    // 004a23ba  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a23bf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a23c0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a23c1:
    // 004a23c1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a23c3  e8700a0000             -call 0x4a2e38
    cpu.esp -= 4;
    sub_4a2e38(app, cpu);
    if (cpu.terminate) return;
    // 004a23c8  e8e3090000             -call 0x4a2db0
    cpu.esp -= 4;
    sub_4a2db0(app, cpu);
    if (cpu.terminate) return;
    // 004a23cd  ebab                   -jmp 0x4a237a
    goto L_0x004a237a;
L_0x004a23cf:
    // 004a23cf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a23d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a23d2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a23d4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a23d4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a23d9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4a23dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a23dc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a23dd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a23de  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a23df  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004a23e2  8b74247c               -mov esi, dword ptr [esp + 0x7c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 004a23e6  833dfcd94d0000         +cmp dword ptr [0x4dd9fc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102076) /* 0x4dd9fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a23ed  0f840f010000           -je 0x4a2502
    if (cpu.flags.zf)
    {
        goto L_0x004a2502;
    }
    // 004a23f3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a23f5  e83e0a0000             -call 0x4a2e38
    cpu.esp -= 4;
    sub_4a2e38(app, cpu);
    if (cpu.terminate) return;
    // 004a23fa  8b0d30da4d00           -mov ecx, dword ptr [0x4dda30]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5102128) /* 0x4dda30 */);
    // 004a2400  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2401  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a2403  ff152c145700           -call dword ptr [0x57142c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706796) /* 0x57142c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2409  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a240c  893d30da4d00           -mov dword ptr [0x4dda30], edi
    app->getMemory<x86::reg32>(x86::reg32(5102128) /* 0x4dda30 */) = cpu.edi;
L_0x004a2412:
    // 004a2412  833dfcd94d0000         +cmp dword ptr [0x4dd9fc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102076) /* 0x4dd9fc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2419  0f840f010000           -je 0x4a252e
    if (cpu.flags.zf)
    {
        goto L_0x004a252e;
    }
    // 004a241f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a2421  7505                   -jne 0x4a2428
    if (!cpu.flags.zf)
    {
        goto L_0x004a2428;
    }
    // 004a2423  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
L_0x004a2428:
    // 004a2428  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2429  a1d4d94d00             -mov eax, dword ptr [0x4dd9d4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102036) /* 0x4dd9d4 */);
    // 004a242e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a242f  2eff1528644c00         -call dword ptr cs:[0x4c6428]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006376) /* 0x4c6428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2436  8b942484000000         -mov edx, dword ptr [esp + 0x84]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 004a243d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a243e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a243f  6865040000             -push 0x465
    app->getMemory<x86::reg32>(cpu.esp-4) = 1125 /*0x465*/;
    cpu.esp -= 4;
    // 004a2444  8b0dd4d94d00           -mov ecx, dword ptr [0x4dd9d4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5102036) /* 0x4dd9d4 */);
    // 004a244a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a244b  2eff1508644c00         -call dword ptr cs:[0x4c6408]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006344) /* 0x4c6408 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2452  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004a2454  8b3528da4d00           -mov esi, dword ptr [0x4dda28]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5102120) /* 0x4dda28 */);
    // 004a245a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a245b  2eff15d8654c00         -call dword ptr cs:[0x4c65d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006808) /* 0x4c65d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2462  833dd8d94d0000         +cmp dword ptr [0x4dd9d8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102040) /* 0x4dd9d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2469  0f857b000000           -jne 0x4a24ea
    if (!cpu.flags.zf)
    {
        goto L_0x004a24ea;
    }
    // 004a246f  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a2473  bd6c000000             -mov ebp, 0x6c
    cpu.ebp = 108 /*0x6c*/;
    // 004a2478  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a2479  a108da4d00             -mov eax, dword ptr [0x4dda08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102088) /* 0x4dda08 */);
    // 004a247e  896c2408               -mov dword ptr [esp + 8], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebp;
    // 004a2482  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a2483  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a2485  ff5158                 -call dword ptr [ecx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2488  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004a248c  83f810                 +cmp eax, 0x10
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
    // 004a248f  0f8377000000           -jae 0x4a250c
    if (!cpu.flags.cf)
    {
        goto L_0x004a250c;
    }
L_0x004a2495:
    // 004a2495  8b742458               -mov esi, dword ptr [esp + 0x58]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004a2499  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a249a  6870124d00             -push 0x4d1270
    app->getMemory<x86::reg32>(cpu.esp-4) = 5050992 /*0x4d1270*/;
    cpu.esp -= 4;
    // 004a249f  e8f0f3ffff             -call 0x4a1894
    cpu.esp -= 4;
    sub_4a1894(app, cpu);
    if (cpu.terminate) return;
    // 004a24a4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x004a24a7:
    // 004a24a7  6800145700             -push 0x571400
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706752 /*0x571400*/;
    cpu.esp -= 4;
    // 004a24ac  68402b4a00             -push 0x4a2b40
    app->getMemory<x86::reg32>(cpu.esp-4) = 4860736 /*0x4a2b40*/;
    cpu.esp -= 4;
    // 004a24b1  ff1524145700           -call dword ptr [0x571424]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706788) /* 0x571424 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a24b7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a24ba  a3d8d94d00             -mov dword ptr [0x4dd9d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5102040) /* 0x4dd9d8 */) = cpu.eax;
    // 004a24bf  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a24c1  7527                   -jne 0x4a24ea
    if (!cpu.flags.zf)
    {
        goto L_0x004a24ea;
    }
    // 004a24c3  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a24c5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a24c6  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a24ca  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a24cb  8b6c241c               -mov ebp, dword ptr [esp + 0x1c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a24cf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a24d0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a24d1  ff1528145700           -call dword ptr [0x571428]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706792) /* 0x571428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a24d7  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a24da  a330da4d00             -mov dword ptr [0x4dda30], eax
    app->getMemory<x86::reg32>(x86::reg32(5102128) /* 0x4dda30 */) = cpu.eax;
    // 004a24df  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a24e1  7c02                   -jl 0x4a24e5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a24e5;
    }
    // 004a24e3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a24e5:
    // 004a24e5  a3d8d94d00             -mov dword ptr [0x4dd9d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5102040) /* 0x4dd9d8 */) = cpu.eax;
L_0x004a24ea:
    // 004a24ea  833dd8d94d0000         +cmp dword ptr [0x4dd9d8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102040) /* 0x4dd9d8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a24f1  752f                   -jne 0x4a2522
    if (!cpu.flags.zf)
    {
        goto L_0x004a2522;
    }
    // 004a24f3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a24f8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a24f9  83c46c                 +add esp, 0x6c
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
    // 004a24fc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a24fd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a24fe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a24ff  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a2502:
    // 004a2502  e841f9ffff             -call 0x4a1e48
    cpu.esp -= 4;
    sub_4a1e48(app, cpu);
    if (cpu.terminate) return;
    // 004a2507  e906ffffff             -jmp 0x4a2412
    goto L_0x004a2412;
L_0x004a250c:
    // 004a250c  7704                   -ja 0x4a2512
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a2512;
    }
    // 004a250e  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004a2510  eb95                   -jmp 0x4a24a7
    goto L_0x004a24a7;
L_0x004a2512:
    // 004a2512  83f820                 +cmp eax, 0x20
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
    // 004a2515  0f857affffff           -jne 0x4a2495
    if (!cpu.flags.zf)
    {
        goto L_0x004a2495;
    }
    // 004a251b  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004a2520  eb85                   -jmp 0x4a24a7
    goto L_0x004a24a7;
L_0x004a2522:
    // 004a2522  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2524  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2525  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004a2528  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2529  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a252a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a252b  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a252e:
    // 004a252e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2530  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004a2533  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2534  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2535  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2536  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a2540(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2540  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 004a2542  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004a2544  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 004a2546  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004a2548  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 004a254a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004a254c  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 004a254e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004a2550  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 004a2552  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004a2554  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 004a2556  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004a2558  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 004a255a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004a255c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a255d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a255e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a255f  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004a2562  8b3538da4d00           -mov esi, dword ptr [0x4dda38]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5102136) /* 0x4dda38 */);
    // 004a2568  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a256a  741e                   -je 0x4a258a
    if (cpu.flags.zf)
    {
        goto L_0x004a258a;
    }
L_0x004a256c:
    // 004a256c  8b1d3cda4d00           -mov ebx, dword ptr [0x4dda3c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5102140) /* 0x4dda3c */);
    // 004a2572  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a2574  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 004a2576  a33cda4d00             -mov dword ptr [0x4dda3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5102140) /* 0x4dda3c */) = cpu.eax;
    // 004a257b  893538da4d00           -mov dword ptr [0x4dda38], esi
    app->getMemory<x86::reg32>(x86::reg32(5102136) /* 0x4dda38 */) = cpu.esi;
    // 004a2581  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004a2583  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004a2586  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2587  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2588  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2589  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a258a:
    // 004a258a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a258b  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a258f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a2590  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 004a2595  2eff151c654c00         -call dword ptr cs:[0x4c651c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006620) /* 0x4c651c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a259c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a25a0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a25a2  f7f3                   +div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a25a4  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004a25a6  6800300000             -push 0x3000
    app->getMemory<x86::reg32>(cpu.esp-4) = 12288 /*0x3000*/;
    cpu.esp -= 4;
    // 004a25ab  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a25af  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a25b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a25b1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a25b3  2eff15c4654c00         -call dword ptr cs:[0x4c65c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006788) /* 0x4c65c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a25ba  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a25bc  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a25c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004a25c3:
    // 004a25c3  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a25c4  74a6                   -je 0x4a256c
    if (cpu.flags.zf)
    {
        goto L_0x004a256c;
    }
    // 004a25c6  83c60c                 +add esi, 0xc
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a25c9  8d56f4                 -lea edx, [esi - 0xc]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(-12) /* -0xc */);
    // 004a25cc  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004a25ce  ebf3                   -jmp 0x4a25c3
    goto L_0x004a25c3;
}

/* align: skip  */
void Application::sub_4a255c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a255c;
    // 004a2540  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 004a2542  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004a2544  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 004a2546  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004a2548  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 004a254a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004a254c  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 004a254e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004a2550  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 004a2552  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004a2554  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 004a2556  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004a2558  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 004a255a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
L_entry_0x004a255c:
    // 004a255c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a255d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a255e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a255f  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004a2562  8b3538da4d00           -mov esi, dword ptr [0x4dda38]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5102136) /* 0x4dda38 */);
    // 004a2568  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a256a  741e                   -je 0x4a258a
    if (cpu.flags.zf)
    {
        goto L_0x004a258a;
    }
L_0x004a256c:
    // 004a256c  8b1d3cda4d00           -mov ebx, dword ptr [0x4dda3c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5102140) /* 0x4dda3c */);
    // 004a2572  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a2574  8b36                   -mov esi, dword ptr [esi]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi);
    // 004a2576  a33cda4d00             -mov dword ptr [0x4dda3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5102140) /* 0x4dda3c */) = cpu.eax;
    // 004a257b  893538da4d00           -mov dword ptr [0x4dda38], esi
    app->getMemory<x86::reg32>(x86::reg32(5102136) /* 0x4dda38 */) = cpu.esi;
    // 004a2581  8918                   -mov dword ptr [eax], ebx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ebx;
    // 004a2583  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 004a2586  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2587  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2588  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2589  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a258a:
    // 004a258a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a258b  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a258f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a2590  bb0c000000             -mov ebx, 0xc
    cpu.ebx = 12 /*0xc*/;
    // 004a2595  2eff151c654c00         -call dword ptr cs:[0x4c651c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006620) /* 0x4c651c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a259c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a25a0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a25a2  f7f3                   +div ebx
    {
        x86::reg64 tmp = cpu.edx_eax;
        x86::reg32 d = cpu.ebx;
        cpu.edx_eax /= d;
        cpu.edx = tmp % d;
    }
    // 004a25a4  6a04                   -push 4
    app->getMemory<x86::reg32>(cpu.esp-4) = 4 /*0x4*/;
    cpu.esp -= 4;
    // 004a25a6  6800300000             -push 0x3000
    app->getMemory<x86::reg32>(cpu.esp-4) = 12288 /*0x3000*/;
    cpu.esp -= 4;
    // 004a25ab  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a25af  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a25b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a25b1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a25b3  2eff15c4654c00         -call dword ptr cs:[0x4c65c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006788) /* 0x4c65c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a25ba  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a25bc  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 004a25c2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004a25c3:
    // 004a25c3  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a25c4  74a6                   -je 0x4a256c
    if (cpu.flags.zf)
    {
        goto L_0x004a256c;
    }
    // 004a25c6  83c60c                 +add esi, 0xc
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(12 /*0xc*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a25c9  8d56f4                 -lea edx, [esi - 0xc]
    cpu.edx = x86::reg32(cpu.esi + x86::reg32(-12) /* -0xc */);
    // 004a25cc  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 004a25ce  ebf3                   -jmp 0x4a25c3
    goto L_0x004a25c3;
}

/* align: skip  */
void Application::sub_4a25d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a25d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a25d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a25d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a25d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a25d4  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a25d7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a25d9  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004a25db  0fafdb                 -imul ebx, ebx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a25de  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
L_0x004a25e2:
    // 004a25e2  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a25e6  4a                     -dec edx
    (cpu.edx)--;
    // 004a25e7  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004a25eb  83faff                 +cmp edx, -1
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
    // 004a25ee  746d                   -je 0x4a265d
    if (cpu.flags.zf)
    {
        goto L_0x004a265d;
    }
    // 004a25f0  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004a25f2  be40254a00             -mov esi, 0x4a2540
    cpu.esi = 4859200 /*0x4a2540*/;
    // 004a25f7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a25f9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a25fa  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a25fb  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a25fc  be1f000000             -mov esi, 0x1f
    cpu.esi = 31 /*0x1f*/;
L_0x004a2601:
    // 004a2601  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 004a2604  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 004a2605  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a2607  c1fb0a                 -sar ebx, 0xa
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (10 /*0xa*/ % 32));
    // 004a260a  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004a260d  21f3                   -and ebx, esi
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.esi));
    // 004a260f  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a2612  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a2614  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a2616  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004a2619  c1fb05                 -sar ebx, 5
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (5 /*0x5*/ % 32));
    // 004a261c  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a2620  21f3                   -and ebx, esi
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.esi));
    // 004a2622  21f0                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
    // 004a2624  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a2626  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a262a  42                     -inc edx
    (cpu.edx)++;
    // 004a262b  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a262d  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004a2631  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004a2635  83fa04                 +cmp edx, 4
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
    // 004a2638  7cc7                   -jl 0x4a2601
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a2601;
    }
    // 004a263a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a263c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a263e:
    // 004a263e  8b1c04                 -mov ebx, dword ptr [esp + eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + cpu.eax * 1);
    // 004a2641  0fbfd2                 -movsx edx, dx
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 004a2644  c1fb02                 -sar ebx, 2
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (2 /*0x2*/ % 32));
    // 004a2647  c1e205                 -shl edx, 5
    cpu.edx <<= 5 /*0x5*/ % 32;
    // 004a264a  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a264d  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a264f  83f80c                 +cmp eax, 0xc
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
    // 004a2652  75ea                   -jne 0x4a263e
    if (!cpu.flags.zf)
    {
        goto L_0x004a263e;
    }
    // 004a2654  83c502                 +add ebp, 2
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
    // 004a2657  668955fe               -mov word ptr [ebp - 2], dx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-2) /* -0x2 */) = cpu.dx;
    // 004a265b  eb85                   -jmp 0x4a25e2
    goto L_0x004a25e2;
L_0x004a265d:
    // 004a265d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a2660  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2661  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2662  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2663  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2664  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a2668(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2668  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2669  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a266a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a266b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a266c  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a266f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a2671  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 004a2673  0fafdb                 -imul ebx, ebx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004a2676  895c2410               -mov dword ptr [esp + 0x10], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.ebx;
L_0x004a267a:
    // 004a267a  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a267e  4a                     -dec edx
    (cpu.edx)--;
    // 004a267f  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004a2683  83faff                 +cmp edx, -1
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
    // 004a2686  0f8482000000           -je 0x4a270e
    if (cpu.flags.zf)
    {
        goto L_0x004a270e;
    }
    // 004a268c  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004a268e  be4c254a00             -mov esi, 0x4a254c
    cpu.esi = 4859212 /*0x4a254c*/;
    // 004a2693  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a2695  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a2696  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a2697  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a2698  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a2699  be0f000000             -mov esi, 0xf
    cpu.esi = 15 /*0xf*/;
L_0x004a269e:
    // 004a269e  668b01                 -mov ax, word ptr [ecx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ecx);
    // 004a26a1  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 004a26a2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a26a4  c1fb0c                 -sar ebx, 0xc
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (12 /*0xc*/ % 32));
    // 004a26a7  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004a26aa  21f3                   -and ebx, esi
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.esi));
    // 004a26ac  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a26ae  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a26b0  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 004a26b3  c1fb08                 -sar ebx, 8
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (8 /*0x8*/ % 32));
    // 004a26b6  8b7c2404               -mov edi, dword ptr [esp + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a26ba  21f3                   -and ebx, esi
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.esi));
    // 004a26bc  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a26bf  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a26c1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a26c3  897c2404               -mov dword ptr [esp + 4], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edi;
    // 004a26c7  c1fb04                 -sar ebx, 4
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (4 /*0x4*/ % 32));
    // 004a26ca  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a26ce  21f3                   -and ebx, esi
    cpu.ebx &= x86::reg32(x86::sreg32(cpu.esi));
    // 004a26d0  21f0                   -and eax, esi
    cpu.eax &= x86::reg32(x86::sreg32(cpu.esi));
    // 004a26d2  01df                   -add edi, ebx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004a26d4  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a26d8  42                     -inc edx
    (cpu.edx)++;
    // 004a26d9  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a26db  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004a26df  895c240c               -mov dword ptr [esp + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004a26e3  83fa04                 +cmp edx, 4
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
    // 004a26e6  7cb6                   -jl 0x4a269e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a269e;
    }
    // 004a26e8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a26ea  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a26ec:
    // 004a26ec  8b1c04                 -mov ebx, dword ptr [esp + eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + cpu.eax * 1);
    // 004a26ef  0fbfd2                 -movsx edx, dx
    cpu.edx = x86::reg32(static_cast<x86::sreg16>(cpu.dx));
    // 004a26f2  c1fb02                 -sar ebx, 2
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (2 /*0x2*/ % 32));
    // 004a26f5  c1e204                 -shl edx, 4
    cpu.edx <<= 4 /*0x4*/ % 32;
    // 004a26f8  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a26fb  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a26fd  83f810                 +cmp eax, 0x10
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
    // 004a2700  75ea                   -jne 0x4a26ec
    if (!cpu.flags.zf)
    {
        goto L_0x004a26ec;
    }
    // 004a2702  83c502                 +add ebp, 2
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
    // 004a2705  668955fe               -mov word ptr [ebp - 2], dx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-2) /* -0x2 */) = cpu.dx;
    // 004a2709  e96cffffff             -jmp 0x4a267a
    goto L_0x004a267a;
L_0x004a270e:
    // 004a270e  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a2711  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2712  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2713  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2714  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2715  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a2718(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2718  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2719  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a271a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a271b  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004a271e  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a2722  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004a2726  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 004a272a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a272f  88d9                   -mov cl, bl
    cpu.cl = cpu.bl;
    // 004a2731  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 004a2733  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a2737  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004a273b  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a273d  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a273f  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a2742  bdaaaa0000             -mov ebp, 0xaaaa
    cpu.ebp = 43690 /*0xaaaa*/;
L_0x004a2747:
    // 004a2747  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a274b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a274d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a274f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a2751  7e2e                   -jle 0x4a2781
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a2781;
    }
    // 004a2753  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
L_0x004a2757:
    // 004a2757  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a275b  668b19                 -mov bx, word ptr [ecx]
    cpu.bx = app->getMemory<x86::reg16>(cpu.ecx);
    // 004a275e  31f3                   -xor ebx, esi
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a2760  89fe                   -mov esi, edi
    cpu.esi = cpu.edi;
    // 004a2762  09d6                   -or esi, edx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.edx));
    // 004a2764  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a2766  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a2769  0374240c               -add esi, dword ptr [esp + 0xc]
    (cpu.esi) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004a276d  40                     -inc eax
    (cpu.eax)++;
    // 004a276e  81c257550000           -add edx, 0x5557
    (cpu.edx) += x86::reg32(x86::sreg32(21847 /*0x5557*/));
    // 004a2774  66891e                 -mov word ptr [esi], bx
    app->getMemory<x86::reg16>(cpu.esi) = cpu.bx;
    // 004a2777  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a277b  21ea                   -and edx, ebp
    cpu.edx &= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a277d  39d8                   +cmp eax, ebx
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
    // 004a277f  7cd6                   -jl 0x4a2757
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a2757;
    }
L_0x004a2781:
    // 004a2781  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004a2784  81c7abaa0000           -add edi, 0xaaab
    (cpu.edi) += x86::reg32(x86::sreg32(43691 /*0xaaab*/));
    // 004a278a  8b742404               -mov esi, dword ptr [esp + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a278e  81e755550000           -and edi, 0x5555
    cpu.edi &= x86::reg32(x86::sreg32(21845 /*0x5555*/));
    // 004a2794  01c6                   +add esi, eax
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
    // 004a2796  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a279a  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004a279e  48                     +dec eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a279f  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a27a3  75a2                   -jne 0x4a2747
    if (!cpu.flags.zf)
    {
        goto L_0x004a2747;
    }
    // 004a27a5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a27a7  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004a27aa  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a27ab  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a27ac  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a27ad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a27b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a27b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a27b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a27b2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a27b3  88d1                   -mov cl, dl
    cpu.cl = cpu.dl;
    // 004a27b5  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004a27ba  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004a27bc  0fafd2                 -imul edx, edx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edx)));
L_0x004a27bf:
    // 004a27bf  4a                     -dec edx
    (cpu.edx)--;
    // 004a27c0  83faff                 +cmp edx, -1
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
    // 004a27c3  7425                   -je 0x4a27ea
    if (cpu.flags.zf)
    {
        goto L_0x004a27ea;
    }
    // 004a27c5  668b18                 -mov bx, word ptr [eax]
    cpu.bx = app->getMemory<x86::reg16>(cpu.eax);
    // 004a27c8  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004a27ca  80e1c0                 -and cl, 0xc0
    cpu.cl &= x86::reg8(x86::sreg8(192 /*0xc0*/));
    // 004a27cd  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 004a27cf  30ff                   -xor bh, bh
    cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh));
    // 004a27d1  81e6ffff0000           -and esi, 0xffff
    cpu.esi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a27d7  80e31f                 -and bl, 0x1f
    cpu.bl &= x86::reg8(x86::sreg8(31 /*0x1f*/));
    // 004a27da  d1fe                   -sar esi, 1
    cpu.esi = x86::reg32(x86::sreg32(cpu.esi) >> (1 /*0x1*/ % 32));
    // 004a27dc  0fbfcb                 -movsx ecx, bx
    cpu.ecx = x86::reg32(static_cast<x86::sreg16>(cpu.bx));
    // 004a27df  83c002                 -add eax, 2
    (cpu.eax) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004a27e2  09f1                   +or ecx, esi
    cpu.clear_co();
    cpu.set_szp((cpu.ecx |= x86::reg32(x86::sreg32(cpu.esi))));
    // 004a27e4  668948fe               -mov word ptr [eax - 2], cx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(-2) /* -0x2 */) = cpu.cx;
    // 004a27e8  ebd5                   -jmp 0x4a27bf
    goto L_0x004a27bf;
L_0x004a27ea:
    // 004a27ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a27eb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a27ec  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a27ed  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a2804(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004a2804  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2805  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2806  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a2809  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a280d  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a2811  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a2813  39d0                   +cmp eax, edx
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
    // 004a2815  0f85a0000000           -jne 0x4a28bb
    if (!cpu.flags.zf)
    {
        goto L_0x004a28bb;
    }
    // 004a281b  83fa40                 +cmp edx, 0x40
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
    // 004a281e  0f83a1000000           -jae 0x4a28c5
    if (!cpu.flags.cf)
    {
        goto L_0x004a28c5;
    }
    // 004a2824  83fa20                 +cmp edx, 0x20
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
    // 004a2827  0f858e000000           -jne 0x4a28bb
    if (!cpu.flags.zf)
    {
        goto L_0x004a28bb;
    }
    // 004a282d  89742410               -mov dword ptr [esp + 0x10], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.esi;
L_0x004a2831:
    // 004a2831  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a2835  83e803                 -sub eax, 3
    (cpu.eax) -= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004a2838  83f804                 +cmp eax, 4
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
    // 004a283b  0f877a000000           -ja 0x4a28bb
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a28bb;
    }
    // 004a2841  ff2485f0274a00         -jmp dword ptr [eax*4 + 0x4a27f0]
    cpu.ip = app->getMemory<x86::reg32>(4859888 + cpu.eax * 4); goto dynamic_jump;
  case 0x004a2848:
    // 004a2848  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004a284a:
    // 004a284a  837c243000             +cmp dword ptr [esp + 0x30], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a284f  7401                   -je 0x4a2852
    if (cpu.flags.zf)
    {
        goto L_0x004a2852;
    }
    // 004a2851  43                     -inc ebx
    (cpu.ebx)++;
L_0x004a2852:
    // 004a2852  c6042450               -mov byte ptr [esp], 0x50
    app->getMemory<x86::reg8>(cpu.esp) = 80 /*0x50*/;
    // 004a2856  8a442410               -mov al, byte ptr [esp + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a285a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a285c  88442407               -mov byte ptr [esp + 7], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */) = cpu.al;
    // 004a2860  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a2864  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a2865  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a2867  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a2869  b254                   -mov dl, 0x54
    cpu.dl = 84 /*0x54*/;
    // 004a286b  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a286d  88542415               -mov byte ptr [esp + 0x15], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(21) /* 0x15 */) = cpu.dl;
    // 004a2871  ba70145700             -mov edx, 0x571470
    cpu.edx = 5706864 /*0x571470*/;
    // 004a2876  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a2878  885c241a               -mov byte ptr [esp + 0x1a], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(26) /* 0x1a */) = cpu.bl;
    // 004a287c  89542424               -mov dword ptr [esp + 0x24], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.edx;
    // 004a2880  ff1534145700           -call dword ptr [0x571434]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706804) /* 0x571434 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2886  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004a2888  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004a288b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a288d  7422                   -je 0x4a28b1
    if (cpu.flags.zf)
    {
        goto L_0x004a28b1;
    }
    // 004a288f  e8c8fcffff             -call 0x4a255c
    cpu.esp -= 4;
    sub_4a255c(app, cpu);
    if (cpu.terminate) return;
    // 004a2894  895004                 -mov dword ptr [eax + 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004a2897  885808                 -mov byte ptr [eax + 8], bl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.bl;
    // 004a289a  8a542410               -mov dl, byte ptr [esp + 0x10]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a289e  885009                 -mov byte ptr [eax + 9], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(9) /* 0x9 */) = cpu.dl;
    // 004a28a1  8a542428               -mov dl, byte ptr [esp + 0x28]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a28a5  88500a                 -mov byte ptr [eax + 0xa], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10) /* 0xa */) = cpu.dl;
    // 004a28a8  8a542430               -mov dl, byte ptr [esp + 0x30]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 004a28ac  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a28ae  88500b                 -mov byte ptr [eax + 0xb], dl
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11) /* 0xb */) = cpu.dl;
L_0x004a28b1:
    // 004a28b1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a28b3  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a28b6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a28b7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a28b8  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x004a28bb:
    // 004a28bb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a28bd  83c414                 +add esp, 0x14
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(20 /*0x14*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a28c0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a28c1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a28c2  c21400                 -ret 0x14
    cpu.esp += 4+20 /*0x14*/;
    return;
L_0x004a28c5:
    // 004a28c5  770d                   -ja 0x4a28d4
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a28d4;
    }
    // 004a28c7  c744241001000000       -mov dword ptr [esp + 0x10], 1
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 1 /*0x1*/;
    // 004a28cf  e95dffffff             -jmp 0x4a2831
    goto L_0x004a2831;
L_0x004a28d4:
    // 004a28d4  81fa80000000           +cmp edx, 0x80
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(128 /*0x80*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a28da  72df                   -jb 0x4a28bb
    if (cpu.flags.cf)
    {
        goto L_0x004a28bb;
    }
    // 004a28dc  770d                   -ja 0x4a28eb
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a28eb;
    }
    // 004a28de  c744241002000000       -mov dword ptr [esp + 0x10], 2
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 2 /*0x2*/;
    // 004a28e6  e946ffffff             -jmp 0x4a2831
    goto L_0x004a2831;
L_0x004a28eb:
    // 004a28eb  81fa00010000           +cmp edx, 0x100
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a28f1  75c8                   -jne 0x4a28bb
    if (!cpu.flags.zf)
    {
        goto L_0x004a28bb;
    }
    // 004a28f3  c744241003000000       -mov dword ptr [esp + 0x10], 3
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = 3 /*0x3*/;
    // 004a28fb  e931ffffff             -jmp 0x4a2831
    goto L_0x004a2831;
  case 0x004a2900:
    // 004a2900  bb03000000             -mov ebx, 3
    cpu.ebx = 3 /*0x3*/;
    // 004a2905  e940ffffff             -jmp 0x4a284a
    goto L_0x004a284a;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a2920(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004a2920  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2921  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2922  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2923  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a2924  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004a2926  83ec30                 -sub esp, 0x30
    (cpu.esp) -= x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004a2929  8b7d18                 -mov edi, dword ptr [ebp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(24) /* 0x18 */);
    // 004a292c  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a292f  8945e4                 -mov dword ptr [ebp - 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */) = cpu.eax;
    // 004a2932  8a400a                 -mov al, byte ptr [eax + 0xa]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10) /* 0xa */);
    // 004a2935  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a2937  2c03                   -sub al, 3
    (cpu.al) -= x86::reg8(x86::sreg8(3 /*0x3*/));
    // 004a2939  668955fc               -mov word ptr [ebp - 4], dx
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.dx;
    // 004a293d  3c04                   +cmp al, 4
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
    // 004a293f  0f87a7010000           -ja 0x4a2aec
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a2aec;
    }
    // 004a2945  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004a294a  ff24850c294a00         -jmp dword ptr [eax*4 + 0x4a290c]
    cpu.ip = app->getMemory<x86::reg32>(4860172 + cpu.eax * 4); goto dynamic_jump;
  case 0x004a2951:
    // 004a2951  66c745fc00f0           -mov word ptr [ebp - 4], 0xf000
    app->getMemory<x86::reg16>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = 61440 /*0xf000*/;
  [[fallthrough]];
  case 0x004a2957:
    // 004a2957  8b55e4                 -mov edx, dword ptr [ebp - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004a295a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a295c  8a4209                 -mov al, byte ptr [edx + 9]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(9) /* 0x9 */);
    // 004a295f  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a2961  83c005                 -add eax, 5
    (cpu.eax) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 004a2964  8a7a0b                 -mov bh, byte ptr [edx + 0xb]
    cpu.bh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11) /* 0xb */);
    // 004a2967  8945e0                 -mov dword ptr [ebp - 0x20], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.eax;
    // 004a296a  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 004a296c  7407                   -je 0x4a2975
    if (cpu.flags.zf)
    {
        goto L_0x004a2975;
    }
    // 004a296e  8b348540da4d00         -mov esi, dword ptr [eax*4 + 0x4dda40]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5102144) /* 0x4dda40 */ + cpu.eax * 4);
L_0x004a2975:
    // 004a2975  c645d050               -mov byte ptr [ebp - 0x30], 0x50
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = 80 /*0x50*/;
    // 004a2979  b554                   -mov ch, 0x54
    cpu.ch = 84 /*0x54*/;
    // 004a297b  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004a297e  886dd1                 -mov byte ptr [ebp - 0x2f], ch
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-47) /* -0x2f */) = cpu.ch;
    // 004a2981  8a4008                 -mov al, byte ptr [eax + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004a2984  ba70145700             -mov edx, 0x571470
    cpu.edx = 5706864 /*0x571470*/;
    // 004a2989  8845d2                 -mov byte ptr [ebp - 0x2e], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-46) /* -0x2e */) = cpu.al;
    // 004a298c  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004a298f  8b5de0                 -mov ebx, dword ptr [ebp - 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004a2992  8b4dfa                 -mov ecx, dword ptr [ebp - 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 004a2995  8a4009                 -mov al, byte ptr [eax + 9]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(9) /* 0x9 */);
    // 004a2998  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004a299b  8845d3                 -mov byte ptr [ebp - 0x2d], al
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-45) /* -0x2d */) = cpu.al;
    // 004a299e  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 004a29a1  8955dc                 -mov dword ptr [ebp - 0x24], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edx;
    // 004a29a4  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a29a6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a29a8  8955e8                 -mov dword ptr [ebp - 0x18], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.edx;
    // 004a29ab  e868fdffff             -call 0x4a2718
    cpu.esp -= 4;
    sub_4a2718(app, cpu);
    if (cpu.terminate) return;
    // 004a29b0  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a29b2  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004a29b5  80780a04               +cmp byte ptr [eax + 0xa], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10) /* 0xa */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a29b9  750b                   -jne 0x4a29c6
    if (!cpu.flags.zf)
    {
        goto L_0x004a29c6;
    }
    // 004a29bb  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004a29be  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 004a29c1  e8eafdffff             -call 0x4a27b0
    cpu.esp -= 4;
    sub_4a27b0(app, cpu);
    if (cpu.terminate) return;
L_0x004a29c6:
    // 004a29c6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a29c8  0f84ea000000           -je 0x4a2ab8
    if (cpu.flags.zf)
    {
        goto L_0x004a2ab8;
    }
    // 004a29ce  8b55e4                 -mov edx, dword ptr [ebp - 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004a29d1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a29d3  8a420b                 -mov al, byte ptr [edx + 0xb]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(11) /* 0xb */);
    // 004a29d6  48                     -dec eax
    (cpu.eax)--;
    // 004a29d7  8a720a                 -mov dh, byte ptr [edx + 0xa]
    cpu.dh = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10) /* 0xa */);
    // 004a29da  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 004a29dd  80fe07                 +cmp dh, 7
    {
        x86::reg8 tmp1 = cpu.dh;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(7 /*0x7*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a29e0  756f                   -jne 0x4a2a51
    if (!cpu.flags.zf)
    {
        goto L_0x004a2a51;
    }
    // 004a29e2  c745ec68264a00         -mov dword ptr [ebp - 0x14], 0x4a2668
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 4859496 /*0x4a2668*/;
L_0x004a29e9:
    // 004a29e9  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004a29ec  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004a29ef  8955f4                 -mov dword ptr [ebp - 0xc], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.edx;
L_0x004a29f2:
    // 004a29f2  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004a29f5  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004a29f8  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a29fb  4a                     -dec edx
    (cpu.edx)--;
    // 004a29fc  8945f4                 -mov dword ptr [ebp - 0xc], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.eax;
    // 004a29ff  8955e0                 -mov dword ptr [ebp - 0x20], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */) = cpu.edx;
    // 004a2a02  83faff                 +cmp edx, -1
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
    // 004a2a05  0f84ad000000           -je 0x4a2ab8
    if (cpu.flags.zf)
    {
        goto L_0x004a2ab8;
    }
    // 004a2a0b  8b5df8                 -mov ebx, dword ptr [ebp - 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
    // 004a2a0e  8b8040da4d00           -mov eax, dword ptr [eax + 0x4dda40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5102144) /* 0x4dda40 */);
    // 004a2a14  01f6                   -add esi, esi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.esi));
    // 004a2a16  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004a2a19  81c670145700           -add esi, 0x571470
    (cpu.esi) += x86::reg32(x86::sreg32(5706864 /*0x571470*/));
    // 004a2a1f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a2a21  7e37                   -jle 0x4a2a5a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a2a5a;
    }
    // 004a2a23  8b4dfa                 -mov ecx, dword ptr [ebp - 6]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-6) /* -0x6 */);
    // 004a2a26  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a2a28  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a2a2a  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004a2a2d  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a2a2f  e8e4fcffff             -call 0x4a2718
    cpu.esp -= 4;
    sub_4a2718(app, cpu);
    if (cpu.terminate) return;
    // 004a2a34  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a2a36  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004a2a39  80780a04               +cmp byte ptr [eax + 0xa], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(10) /* 0xa */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004a2a3d  750a                   -jne 0x4a2a49
    if (!cpu.flags.zf)
    {
        goto L_0x004a2a49;
    }
    // 004a2a3f  8b55e0                 -mov edx, dword ptr [ebp - 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004a2a42  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a2a44  e867fdffff             -call 0x4a27b0
    cpu.esp -= 4;
    sub_4a27b0(app, cpu);
    if (cpu.terminate) return;
L_0x004a2a49:
    // 004a2a49  ff4df8                 +dec dword ptr [ebp - 8]
    {
        auto tmp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004a2a4c  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004a2a4f  eba1                   -jmp 0x4a29f2
    goto L_0x004a29f2;
L_0x004a2a51:
    // 004a2a51  c745ecd0254a00         -mov dword ptr [ebp - 0x14], 0x4a25d0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = 4859344 /*0x4a25d0*/;
    // 004a2a58  eb8f                   -jmp 0x4a29e9
    goto L_0x004a29e9;
L_0x004a2a5a:
    // 004a2a5a  8a4de0                 -mov cl, byte ptr [ebp - 0x20]
    cpu.cl = app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004a2a5d  8d1400                 -lea edx, [eax + eax]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 004a2a60  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004a2a65  81c270145700           -add edx, 0x571470
    (cpu.edx) += x86::reg32(x86::sreg32(5706864 /*0x571470*/));
    // 004a2a6b  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a2a6d  d3e3                   +shl ebx, cl
    {
        x86::reg8 tmp = cpu.cl % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004a2a6f  ff55ec                 -call dword ptr [ebp - 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2a72  8b75f0                 -mov esi, dword ptr [ebp - 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004a2a75  e978ffffff             -jmp 0x4a29f2
    goto L_0x004a29f2;
  case 0x004a2a7a:
    // 004a2a7a  b449                   -mov ah, 0x49
    cpu.ah = 73 /*0x49*/;
    // 004a2a7c  b24d                   -mov dl, 0x4d
    cpu.dl = 77 /*0x4d*/;
    // 004a2a7e  b350                   -mov bl, 0x50
    cpu.bl = 80 /*0x50*/;
    // 004a2a80  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a2a82  8865d0                 -mov byte ptr [ebp - 0x30], ah
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-48) /* -0x30 */) = cpu.ah;
    // 004a2a85  8855d1                 -mov byte ptr [ebp - 0x2f], dl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-47) /* -0x2f */) = cpu.dl;
    // 004a2a88  b641                   -mov dh, 0x41
    cpu.dh = 65 /*0x41*/;
    // 004a2a8a  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004a2a8d  885dd3                 -mov byte ptr [ebp - 0x2d], bl
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-45) /* -0x2d */) = cpu.bl;
    // 004a2a90  8875d2                 -mov byte ptr [ebp - 0x2e], dh
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-46) /* -0x2e */) = cpu.dh;
    // 004a2a93  8a4809                 -mov cl, byte ptr [eax + 9]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(9) /* 0x9 */);
    // 004a2a96  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004a2a9b  83c105                 -add ecx, 5
    (cpu.ecx) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 004a2a9e  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004a2aa0  8955d4                 -mov dword ptr [ebp - 0x2c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */) = cpu.edx;
    // 004a2aa3  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a2aa5  8a4809                 -mov cl, byte ptr [eax + 9]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(9) /* 0x9 */);
    // 004a2aa8  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004a2aad  83c105                 -add ecx, 5
    (cpu.ecx) += x86::reg32(x86::sreg32(5 /*0x5*/));
    // 004a2ab0  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 004a2ab2  897ddc                 -mov dword ptr [ebp - 0x24], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */) = cpu.edi;
    // 004a2ab5  8955d8                 -mov dword ptr [ebp - 0x28], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */) = cpu.edx;
L_0x004a2ab8:
    // 004a2ab8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a2aba  8d45d0                 -lea eax, [ebp - 0x30]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004a2abd  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a2abe  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004a2ac1  8a780b                 -mov bh, byte ptr [eax + 0xb]
    cpu.bh = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(11) /* 0xb */);
    // 004a2ac4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a2ac6  84ff                   +test bh, bh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & cpu.bh));
    // 004a2ac8  7426                   -je 0x4a2af0
    if (cpu.flags.zf)
    {
        goto L_0x004a2af0;
    }
    // 004a2aca  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004a2acf:
    // 004a2acf  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a2ad0  8b45e4                 -mov eax, dword ptr [ebp - 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-28) /* -0x1c */);
    // 004a2ad3  8b7804                 -mov edi, dword ptr [eax + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a2ad6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2ad7  ff1538145700           -call dword ptr [0x571438]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706808) /* 0x571438 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2add  8b4514                 -mov eax, dword ptr [ebp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 004a2ae0  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
L_0x004a2ae3:
    // 004a2ae3  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004a2ae5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2ae6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2ae7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2ae8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2ae9  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a2aec:
    // 004a2aec  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a2aee  ebf3                   -jmp 0x4a2ae3
    goto L_0x004a2ae3;
L_0x004a2af0:
    // 004a2af0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004a2af2  ebdb                   -jmp 0x4a2acf
    goto L_0x004a2acf;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_4a2af4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2af4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2af5  8b1d3cda4d00           -mov ebx, dword ptr [0x4dda3c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5102140) /* 0x4dda3c */);
    // 004a2afb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a2afd  7431                   -je 0x4a2b30
    if (cpu.flags.zf)
    {
        goto L_0x004a2b30;
    }
L_0x004a2aff:
    // 004a2aff  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a2b01  8b1538da4d00           -mov edx, dword ptr [0x4dda38]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5102136) /* 0x4dda38 */);
    // 004a2b07  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a2b09  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004a2b0b  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a2b0e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a2b0f  a338da4d00             -mov dword ptr [0x4dda38], eax
    app->getMemory<x86::reg32>(x86::reg32(5102136) /* 0x4dda38 */) = cpu.eax;
    // 004a2b14  891d3cda4d00           -mov dword ptr [0x4dda3c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5102140) /* 0x4dda3c */) = cpu.ebx;
    // 004a2b1a  ff1540145700           -call dword ptr [0x571440]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706816) /* 0x571440 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2b20  8b1d3cda4d00           -mov ebx, dword ptr [0x4dda3c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5102140) /* 0x4dda3c */);
    // 004a2b26  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a2b29  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a2b2b  75d2                   -jne 0x4a2aff
    if (!cpu.flags.zf)
    {
        goto L_0x004a2aff;
    }
    // 004a2b2d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004a2b30:
    // 004a2b30  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a2b35  891d3cda4d00           -mov dword ptr [0x4dda3c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5102140) /* 0x4dda3c */) = cpu.ebx;
    // 004a2b3b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2b3c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4a2b40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2b40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2b41  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a2b42  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004a2b45  8b5c2478               -mov ebx, dword ptr [esp + 0x78]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004a2b49  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a2b4b  ff1518145700           -call dword ptr [0x571418]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706776) /* 0x571418 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2b51  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a2b53  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 004a2b58  6a21                   -push 0x21
    app->getMemory<x86::reg32>(cpu.esp-4) = 33 /*0x21*/;
    cpu.esp -= 4;
    // 004a2b5a  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004a2b5e  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a2b62  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a2b63  a124da4d00             -mov eax, dword ptr [0x4dda24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102116) /* 0x4dda24 */);
    // 004a2b68  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a2b6a  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a2b6c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a2b6d  a364da4d00             -mov dword ptr [0x4dda64], eax
    app->getMemory<x86::reg32>(x86::reg32(5102180) /* 0x4dda64 */) = cpu.eax;
    // 004a2b72  ff5164                 -call dword ptr [ecx + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2b75  a3d8d94d00             -mov dword ptr [0x4dd9d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5102040) /* 0x4dd9d8 */) = cpu.eax;
    // 004a2b7a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a2b7c  7549                   -jne 0x4a2bc7
    if (!cpu.flags.zf)
    {
        goto L_0x004a2bc7;
    }
    // 004a2b7e  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a2b82  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004a2b84  a34cbf5900             -mov dword ptr [0x59bf4c], eax
    app->getMemory<x86::reg32>(x86::reg32(5881676) /* 0x59bf4c */) = cpu.eax;
    // 004a2b89  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a2b8d  66894304               -mov word ptr [ebx + 4], ax
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 004a2b91  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004a2b96  a350bf5900             -mov dword ptr [0x59bf50], eax
    app->getMemory<x86::reg32>(x86::reg32(5881680) /* 0x59bf50 */) = cpu.eax;
    // 004a2b9b  8a442454               -mov al, byte ptr [esp + 0x54]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004a2b9f  884306                 -mov byte ptr [ebx + 6], al
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = cpu.al;
    // 004a2ba2  3c10                   +cmp al, 0x10
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
    // 004a2ba4  7534                   -jne 0x4a2bda
    if (!cpu.flags.zf)
    {
        goto L_0x004a2bda;
    }
    // 004a2ba6  817c245ce0070000       +cmp dword ptr [esp + 0x5c], 0x7e0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2016 /*0x7e0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2bae  741e                   -je 0x4a2bce
    if (cpu.flags.zf)
    {
        goto L_0x004a2bce;
    }
    // 004a2bb0  bd03000000             -mov ebp, 3
    cpu.ebp = 3 /*0x3*/;
    // 004a2bb5  c643060f               -mov byte ptr [ebx + 6], 0xf
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(6) /* 0x6 */) = 15 /*0xf*/;
    // 004a2bb9  892d54bf5900           -mov dword ptr [0x59bf54], ebp
    app->getMemory<x86::reg32>(x86::reg32(5881684) /* 0x59bf54 */) = cpu.ebp;
L_0x004a2bbf:
    // 004a2bbf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a2bc1:
    // 004a2bc1  83c46c                 +add esp, 0x6c
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
    // 004a2bc4  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2bc5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2bc6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2bc7:
    // 004a2bc7  b80dfcffff             -mov eax, 0xfffffc0d
    cpu.eax = 4294966285 /*0xfffffc0d*/;
    // 004a2bcc  ebf3                   -jmp 0x4a2bc1
    goto L_0x004a2bc1;
L_0x004a2bce:
    // 004a2bce  c70554bf590004000000   -mov dword ptr [0x59bf54], 4
    app->getMemory<x86::reg32>(x86::reg32(5881684) /* 0x59bf54 */) = 4 /*0x4*/;
    // 004a2bd8  ebe5                   -jmp 0x4a2bbf
    goto L_0x004a2bbf;
L_0x004a2bda:
    // 004a2bda  3c20                   +cmp al, 0x20
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
    // 004a2bdc  75e1                   -jne 0x4a2bbf
    if (!cpu.flags.zf)
    {
        goto L_0x004a2bbf;
    }
    // 004a2bde  c70554bf590005000000   -mov dword ptr [0x59bf54], 5
    app->getMemory<x86::reg32>(x86::reg32(5881684) /* 0x59bf54 */) = 5 /*0x5*/;
    // 004a2be8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2bea  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004a2bed  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2bee  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2bef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2bf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2bf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2bf1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a2bf2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a2bf3  e8b8010000             -call 0x4a2db0
    cpu.esp -= 4;
    sub_4a2db0(app, cpu);
    if (cpu.terminate) return;
    // 004a2bf8  833d44bf590000         +cmp dword ptr [0x59bf44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881668) /* 0x59bf44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2bff  7404                   -je 0x4a2c05
    if (cpu.flags.zf)
    {
        goto L_0x004a2c05;
    }
    // 004a2c01  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2c02  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2c03  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2c04  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2c05:
    // 004a2c05  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a2c0a  ff1544145700           -call dword ptr [0x571444]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706820) /* 0x571444 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2c10  a1b8135700             -mov eax, dword ptr [0x5713b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5706680) /* 0x5713b8 */);
    // 004a2c15  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004a2c1a  a330bf5900             -mov dword ptr [0x59bf30], eax
    app->getMemory<x86::reg32>(x86::reg32(5881648) /* 0x59bf30 */) = cpu.eax;
    // 004a2c1f  a1bc135700             -mov eax, dword ptr [0x5713bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5706684) /* 0x5713bc */);
    // 004a2c24  8b1d6cda4d00           -mov ebx, dword ptr [0x4dda6c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5102188) /* 0x4dda6c */);
    // 004a2c2a  a334bf5900             -mov dword ptr [0x59bf34], eax
    app->getMemory<x86::reg32>(x86::reg32(5881652) /* 0x59bf34 */) = cpu.eax;
    // 004a2c2f  a1c0135700             -mov eax, dword ptr [0x5713c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5706688) /* 0x5713c0 */);
    // 004a2c34  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a2c37  a338bf5900             -mov dword ptr [0x59bf38], eax
    app->getMemory<x86::reg32>(x86::reg32(5881656) /* 0x59bf38 */) = cpu.eax;
    // 004a2c3c  a1c4135700             -mov eax, dword ptr [0x5713c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5706692) /* 0x5713c4 */);
    // 004a2c41  890d44bf5900           -mov dword ptr [0x59bf44], ecx
    app->getMemory<x86::reg32>(x86::reg32(5881668) /* 0x59bf44 */) = cpu.ecx;
    // 004a2c47  a33cbf5900             -mov dword ptr [0x59bf3c], eax
    app->getMemory<x86::reg32>(x86::reg32(5881660) /* 0x59bf3c */) = cpu.eax;
    // 004a2c4c  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a2c4e  742c                   -je 0x4a2c7c
    if (cpu.flags.zf)
    {
        goto L_0x004a2c7c;
    }
    // 004a2c50  a120bf5900             -mov eax, dword ptr [0x59bf20]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5881632) /* 0x59bf20 */);
    // 004a2c55  a3b8135700             -mov dword ptr [0x5713b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5706680) /* 0x5713b8 */) = cpu.eax;
    // 004a2c5a  a124bf5900             -mov eax, dword ptr [0x59bf24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5881636) /* 0x59bf24 */);
    // 004a2c5f  a3bc135700             -mov dword ptr [0x5713bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5706684) /* 0x5713bc */) = cpu.eax;
    // 004a2c64  a128bf5900             -mov eax, dword ptr [0x59bf28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5881640) /* 0x59bf28 */);
    // 004a2c69  a3c0135700             -mov dword ptr [0x5713c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5706688) /* 0x5713c0 */) = cpu.eax;
    // 004a2c6e  a12cbf5900             -mov eax, dword ptr [0x59bf2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5881644) /* 0x59bf2c */);
    // 004a2c73  a3c4135700             -mov dword ptr [0x5713c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5706692) /* 0x5713c4 */) = cpu.eax;
    // 004a2c78  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2c79  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2c7a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2c7b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2c7c:
    // 004a2c7c  a1b8135700             -mov eax, dword ptr [0x5713b8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5706680) /* 0x5713b8 */);
    // 004a2c81  a320bf5900             -mov dword ptr [0x59bf20], eax
    app->getMemory<x86::reg32>(x86::reg32(5881632) /* 0x59bf20 */) = cpu.eax;
    // 004a2c86  a1bc135700             -mov eax, dword ptr [0x5713bc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5706684) /* 0x5713bc */);
    // 004a2c8b  a324bf5900             -mov dword ptr [0x59bf24], eax
    app->getMemory<x86::reg32>(x86::reg32(5881636) /* 0x59bf24 */) = cpu.eax;
    // 004a2c90  a1c0135700             -mov eax, dword ptr [0x5713c0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5706688) /* 0x5713c0 */);
    // 004a2c95  a328bf5900             -mov dword ptr [0x59bf28], eax
    app->getMemory<x86::reg32>(x86::reg32(5881640) /* 0x59bf28 */) = cpu.eax;
    // 004a2c9a  a1c4135700             -mov eax, dword ptr [0x5713c4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5706692) /* 0x5713c4 */);
    // 004a2c9f  a32cbf5900             -mov dword ptr [0x59bf2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5881644) /* 0x59bf2c */) = cpu.eax;
    // 004a2ca4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2ca5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2ca6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2ca7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2ca8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2ca8  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a2cac  8b149504da4d00         -mov edx, dword ptr [edx*4 + 0x4dda04]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5102084) /* 0x4dda04 */ + cpu.edx * 4);
    // 004a2cb3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a2cb5  740e                   -je 0x4a2cc5
    if (cpu.flags.zf)
    {
        goto L_0x004a2cc5;
    }
    // 004a2cb7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a2cbc  891524da4d00           -mov dword ptr [0x4dda24], edx
    app->getMemory<x86::reg32>(x86::reg32(5102116) /* 0x4dda24 */) = cpu.edx;
    // 004a2cc2  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004a2cc5:
    // 004a2cc5  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2cc7  891524da4d00           -mov dword ptr [0x4dda24], edx
    app->getMemory<x86::reg32>(x86::reg32(5102116) /* 0x4dda24 */) = cpu.edx;
    // 004a2ccd  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4a2cd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2cd0  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2cd1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a2cd2  833d24da4d0000         +cmp dword ptr [0x4dda24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102116) /* 0x4dda24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2cd9  0f84a2000000           -je 0x4a2d81
    if (cpu.flags.zf)
    {
        goto L_0x004a2d81;
    }
L_0x004a2cdf:
    // 004a2cdf  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a2ce1  e852010000             -call 0x4a2e38
    cpu.esp -= 4;
    sub_4a2e38(app, cpu);
    if (cpu.terminate) return;
    // 004a2ce6  833d68da4d0000         +cmp dword ptr [0x4dda68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102184) /* 0x4dda68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2ced  740d                   -je 0x4a2cfc
    if (cpu.flags.zf)
    {
        goto L_0x004a2cfc;
    }
    // 004a2cef  68ec124d00             -push 0x4d12ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5051116 /*0x4d12ec*/;
    cpu.esp -= 4;
    // 004a2cf4  e89bebffff             -call 0x4a1894
    cpu.esp -= 4;
    sub_4a1894(app, cpu);
    if (cpu.terminate) return;
    // 004a2cf9  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004a2cfc:
    // 004a2cfc  833d64da4d0000         +cmp dword ptr [0x4dda64], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102180) /* 0x4dda64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2d03  740d                   -je 0x4a2d12
    if (cpu.flags.zf)
    {
        goto L_0x004a2d12;
    }
    // 004a2d05  6838134d00             -push 0x4d1338
    app->getMemory<x86::reg32>(cpu.esp-4) = 5051192 /*0x4d1338*/;
    cpu.esp -= 4;
    // 004a2d0a  e885ebffff             -call 0x4a1894
    cpu.esp -= 4;
    sub_4a1894(app, cpu);
    if (cpu.terminate) return;
    // 004a2d0f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004a2d12:
    // 004a2d12  833d44bf590000         +cmp dword ptr [0x59bf44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881668) /* 0x59bf44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2d19  7478                   -je 0x4a2d93
    if (cpu.flags.zf)
    {
        goto L_0x004a2d93;
    }
    // 004a2d1b  a130bf5900             -mov eax, dword ptr [0x59bf30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5881648) /* 0x59bf30 */);
    // 004a2d20  a3b8135700             -mov dword ptr [0x5713b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5706680) /* 0x5713b8 */) = cpu.eax;
    // 004a2d25  a320bf5900             -mov dword ptr [0x59bf20], eax
    app->getMemory<x86::reg32>(x86::reg32(5881632) /* 0x59bf20 */) = cpu.eax;
    // 004a2d2a  a134bf5900             -mov eax, dword ptr [0x59bf34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5881652) /* 0x59bf34 */);
    // 004a2d2f  a3bc135700             -mov dword ptr [0x5713bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5706684) /* 0x5713bc */) = cpu.eax;
    // 004a2d34  a324bf5900             -mov dword ptr [0x59bf24], eax
    app->getMemory<x86::reg32>(x86::reg32(5881636) /* 0x59bf24 */) = cpu.eax;
    // 004a2d39  a138bf5900             -mov eax, dword ptr [0x59bf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5881656) /* 0x59bf38 */);
    // 004a2d3e  a3c0135700             -mov dword ptr [0x5713c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5706688) /* 0x5713c0 */) = cpu.eax;
    // 004a2d43  a328bf5900             -mov dword ptr [0x59bf28], eax
    app->getMemory<x86::reg32>(x86::reg32(5881640) /* 0x59bf28 */) = cpu.eax;
    // 004a2d48  a13cbf5900             -mov eax, dword ptr [0x59bf3c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5881660) /* 0x59bf3c */);
    // 004a2d4d  a3c4135700             -mov dword ptr [0x5713c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5706692) /* 0x5713c4 */) = cpu.eax;
    // 004a2d52  a32cbf5900             -mov dword ptr [0x59bf2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5881644) /* 0x59bf2c */) = cpu.eax;
L_0x004a2d57:
    // 004a2d57  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a2d5c  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004a2d61  ff1548145700           -call dword ptr [0x571448]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706824) /* 0x571448 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2d67  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a2d69  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a2d6c  893d40bf5900           -mov dword ptr [0x59bf40], edi
    app->getMemory<x86::reg32>(x86::reg32(5881664) /* 0x59bf40 */) = cpu.edi;
    // 004a2d72  892d44bf5900           -mov dword ptr [0x59bf44], ebp
    app->getMemory<x86::reg32>(x86::reg32(5881668) /* 0x59bf44 */) = cpu.ebp;
    // 004a2d78  892d6cda4d00           -mov dword ptr [0x4dda6c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5102188) /* 0x4dda6c */) = cpu.ebp;
    // 004a2d7e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2d7f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2d80  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2d81:
    // 004a2d81  68b4124d00             -push 0x4d12b4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5051060 /*0x4d12b4*/;
    cpu.esp -= 4;
    // 004a2d86  e809ebffff             -call 0x4a1894
    cpu.esp -= 4;
    sub_4a1894(app, cpu);
    if (cpu.terminate) return;
    // 004a2d8b  83c404                 +add esp, 4
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
    // 004a2d8e  e94cffffff             -jmp 0x4a2cdf
    goto L_0x004a2cdf;
L_0x004a2d93:
    // 004a2d93  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a2d98  ff1544145700           -call dword ptr [0x571444]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706820) /* 0x571444 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2d9e  83c404                 +add esp, 4
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
    // 004a2da1  ebb4                   -jmp 0x4a2d57
    goto L_0x004a2d57;
}

/* align: skip 0x90 */
void Application::sub_4a2da4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2da4  c70548bf590001000000   -mov dword ptr [0x59bf48], 1
    app->getMemory<x86::reg32>(x86::reg32(5881672) /* 0x59bf48 */) = 1 /*0x1*/;
    // 004a2dae  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004a2db0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2db1  833d40bf590000         +cmp dword ptr [0x59bf40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881664) /* 0x59bf40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2db8  751d                   -jne 0x4a2dd7
    if (!cpu.flags.zf)
    {
        goto L_0x004a2dd7;
    }
L_0x004a2dba:
    // 004a2dba  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a2dbc  8b1d64da4d00           -mov ebx, dword ptr [0x4dda64]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5102180) /* 0x4dda64 */);
    // 004a2dc2  890d40bf5900           -mov dword ptr [0x59bf40], ecx
    app->getMemory<x86::reg32>(x86::reg32(5881664) /* 0x59bf40 */) = cpu.ecx;
    // 004a2dc8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a2dca  7521                   -jne 0x4a2ded
    if (!cpu.flags.zf)
    {
        goto L_0x004a2ded;
    }
    // 004a2dcc  833d48bf590000         +cmp dword ptr [0x59bf48], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881672) /* 0x59bf48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2dd3  7546                   -jne 0x4a2e1b
    if (!cpu.flags.zf)
    {
        goto L_0x004a2e1b;
    }
    // 004a2dd5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2dd6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2dd7:
    // 004a2dd7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a2dd9  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a2dde  ff154c145700           -call dword ptr [0x57144c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706828) /* 0x57144c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2de4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a2de7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a2de9  74cf                   -je 0x4a2dba
    if (cpu.flags.zf)
    {
        goto L_0x004a2dba;
    }
    // 004a2deb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2dec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2ded:
    // 004a2ded  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2dee  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2def  8b354cbf5900           -mov esi, dword ptr [0x59bf4c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5881676) /* 0x59bf4c */);
    // 004a2df5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2df6  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a2df8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2df9  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a2dfb  ff9280000000           -call dword ptr [edx + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2e01  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2e02  893d64da4d00           -mov dword ptr [0x4dda64], edi
    app->getMemory<x86::reg32>(x86::reg32(5102180) /* 0x4dda64 */) = cpu.edi;
    // 004a2e08  ff1518145700           -call dword ptr [0x571418]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706776) /* 0x571418 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2e0e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2e0f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2e10  833d48bf590000         +cmp dword ptr [0x59bf48], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881672) /* 0x59bf48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2e17  7502                   -jne 0x4a2e1b
    if (!cpu.flags.zf)
    {
        goto L_0x004a2e1b;
    }
    // 004a2e19  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2e1a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2e1b:
    // 004a2e1b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a2e1d  a100da4d00             -mov eax, dword ptr [0x4dda00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102080) /* 0x4dda00 */);
    // 004a2e22  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a2e24  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a2e26  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a2e27  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2e2a  a3d8d94d00             -mov dword ptr [0x4dd9d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5102040) /* 0x4dd9d8 */) = cpu.eax;
    // 004a2e2f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2e31  a348bf5900             -mov dword ptr [0x59bf48], eax
    app->getMemory<x86::reg32>(x86::reg32(5881672) /* 0x59bf48 */) = cpu.eax;
    // 004a2e36  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2e37  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2db0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a2db0;
    // 004a2da4  c70548bf590001000000   -mov dword ptr [0x59bf48], 1
    app->getMemory<x86::reg32>(x86::reg32(5881672) /* 0x59bf48 */) = 1 /*0x1*/;
    // 004a2dae  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
L_entry_0x004a2db0:
    // 004a2db0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2db1  833d40bf590000         +cmp dword ptr [0x59bf40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881664) /* 0x59bf40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2db8  751d                   -jne 0x4a2dd7
    if (!cpu.flags.zf)
    {
        goto L_0x004a2dd7;
    }
L_0x004a2dba:
    // 004a2dba  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a2dbc  8b1d64da4d00           -mov ebx, dword ptr [0x4dda64]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5102180) /* 0x4dda64 */);
    // 004a2dc2  890d40bf5900           -mov dword ptr [0x59bf40], ecx
    app->getMemory<x86::reg32>(x86::reg32(5881664) /* 0x59bf40 */) = cpu.ecx;
    // 004a2dc8  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a2dca  7521                   -jne 0x4a2ded
    if (!cpu.flags.zf)
    {
        goto L_0x004a2ded;
    }
    // 004a2dcc  833d48bf590000         +cmp dword ptr [0x59bf48], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881672) /* 0x59bf48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2dd3  7546                   -jne 0x4a2e1b
    if (!cpu.flags.zf)
    {
        goto L_0x004a2e1b;
    }
    // 004a2dd5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2dd6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2dd7:
    // 004a2dd7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a2dd9  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a2dde  ff154c145700           -call dword ptr [0x57144c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706828) /* 0x57144c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2de4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a2de7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a2de9  74cf                   -je 0x4a2dba
    if (cpu.flags.zf)
    {
        goto L_0x004a2dba;
    }
    // 004a2deb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2dec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2ded:
    // 004a2ded  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2dee  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2def  8b354cbf5900           -mov esi, dword ptr [0x59bf4c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5881676) /* 0x59bf4c */);
    // 004a2df5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2df6  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a2df8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2df9  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004a2dfb  ff9280000000           -call dword ptr [edx + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2e01  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2e02  893d64da4d00           -mov dword ptr [0x4dda64], edi
    app->getMemory<x86::reg32>(x86::reg32(5102180) /* 0x4dda64 */) = cpu.edi;
    // 004a2e08  ff1518145700           -call dword ptr [0x571418]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706776) /* 0x571418 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2e0e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2e0f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2e10  833d48bf590000         +cmp dword ptr [0x59bf48], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881672) /* 0x59bf48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2e17  7502                   -jne 0x4a2e1b
    if (!cpu.flags.zf)
    {
        goto L_0x004a2e1b;
    }
    // 004a2e19  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2e1a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a2e1b:
    // 004a2e1b  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a2e1d  a100da4d00             -mov eax, dword ptr [0x4dda00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102080) /* 0x4dda00 */);
    // 004a2e22  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a2e24  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a2e26  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a2e27  ff522c                 -call dword ptr [edx + 0x2c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(44) /* 0x2c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2e2a  a3d8d94d00             -mov dword ptr [0x4dd9d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5102040) /* 0x4dd9d8 */) = cpu.eax;
    // 004a2e2f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a2e31  a348bf5900             -mov dword ptr [0x59bf48], eax
    app->getMemory<x86::reg32>(x86::reg32(5881672) /* 0x59bf48 */) = cpu.eax;
    // 004a2e36  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2e37  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a2e38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2e38  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2e39  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2e3a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2e3b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a2e3c  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a2e40  8b1500da4d00           -mov edx, dword ptr [0x4dda00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5102080) /* 0x4dda00 */);
    // 004a2e46  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a2e48  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a2e4a  743f                   -je 0x4a2e8b
    if (cpu.flags.zf)
    {
        goto L_0x004a2e8b;
    }
    // 004a2e4c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
L_0x004a2e4e:
    // 004a2e4e  3b3d48bf5900           +cmp edi, dword ptr [0x59bf48]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5881672) /* 0x59bf48 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2e54  743e                   -je 0x4a2e94
    if (cpu.flags.zf)
    {
        goto L_0x004a2e94;
    }
L_0x004a2e56:
    // 004a2e56  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004a2e5b:
    // 004a2e5b  8b2d40bf5900           -mov ebp, dword ptr [0x59bf40]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5881664) /* 0x59bf40 */);
    // 004a2e61  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a2e63  39ef                   +cmp edi, ebp
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
    // 004a2e65  7545                   -jne 0x4a2eac
    if (!cpu.flags.zf)
    {
        goto L_0x004a2eac;
    }
L_0x004a2e67:
    // 004a2e67  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004a2e69:
    // 004a2e69  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a2e6b  a168da4d00             -mov eax, dword ptr [0x4dda68]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102184) /* 0x4dda68 */);
    // 004a2e70  39c7                   +cmp edi, eax
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
    // 004a2e72  7552                   -jne 0x4a2ec6
    if (!cpu.flags.zf)
    {
        goto L_0x004a2ec6;
    }
    // 004a2e74  3b0564da4d00           +cmp eax, dword ptr [0x4dda64]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5102180) /* 0x4dda64 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2e7a  744a                   -je 0x4a2ec6
    if (cpu.flags.zf)
    {
        goto L_0x004a2ec6;
    }
    // 004a2e7c  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004a2e81:
    // 004a2e81  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a2e83  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a2e85  7504                   -jne 0x4a2e8b
    if (!cpu.flags.zf)
    {
        goto L_0x004a2e8b;
    }
    // 004a2e87  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a2e89  753f                   -jne 0x4a2eca
    if (!cpu.flags.zf)
    {
        goto L_0x004a2eca;
    }
L_0x004a2e8b:
    // 004a2e8b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a2e8d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2e8e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2e8f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2e90  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2e91  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004a2e94:
    // 004a2e94  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 004a2e96  a100da4d00             -mov eax, dword ptr [0x4dda00]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102080) /* 0x4dda00 */);
    // 004a2e9b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a2e9c  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a2e9e  ff5348                 -call dword ptr [ebx + 0x48]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2ea1  3d1c027688             +cmp eax, 0x8876021c
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2289435164 /*0x8876021c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2ea6  74ae                   -je 0x4a2e56
    if (cpu.flags.zf)
    {
        goto L_0x004a2e56;
    }
    // 004a2ea8  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a2eaa  ebaf                   -jmp 0x4a2e5b
    goto L_0x004a2e5b;
L_0x004a2eac:
    // 004a2eac  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2ead  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a2eb2  ff154c145700           -call dword ptr [0x57144c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706828) /* 0x57144c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2eb8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a2ebb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a2ebd  74a8                   -je 0x4a2e67
    if (cpu.flags.zf)
    {
        goto L_0x004a2e67;
    }
    // 004a2ebf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a2ec4  eba3                   -jmp 0x4a2e69
    goto L_0x004a2e69;
L_0x004a2ec6:
    // 004a2ec6  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004a2ec8  ebb7                   -jmp 0x4a2e81
    goto L_0x004a2e81;
L_0x004a2eca:
    // 004a2eca  ff1504145700           -call dword ptr [0x571404]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706756) /* 0x571404 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a2ed0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a2ed2  0f8d76ffffff           -jge 0x4a2e4e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a2e4e;
    }
    // 004a2ed8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a2eda  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2edb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2edc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2edd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2ede  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a2ee4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2ee4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a2ee5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2ee6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a2ee7  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a2eea  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a2eee  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a2ef2  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a2ef6  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a2efa  d905c8135700           -fld dword ptr [0x5713c8]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5706696) /* 0x5713c8 */)));
    // 004a2f00  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004a2f02  def1                   -fdivrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004a2f04  e82736feff             -call 0x486530
    cpu.esp -= 4;
    sub_486530(app, cpu);
    if (cpu.terminate) return;
    // 004a2f09  db1c24                 -fistp dword ptr [esp]
    app->getMemory<x86::reg32>(cpu.esp) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004a2f0c  d905cc135700           -fld dword ptr [0x5713cc]
    cpu.fpu.push(x86::Float(app->getMemory<float>(x86::reg32(5706700) /* 0x5713cc */)));
    // 004a2f12  d9e8                   -fld1 
    cpu.fpu.push(1.0);
    // 004a2f14  def1                   -fdivrp st(1)
    cpu.fpu.st(1) = cpu.fpu.st(0) / x86::Float(cpu.fpu.st(1));
    cpu.fpu.pop();
    // 004a2f16  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a2f18  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a2f1b  8b3c24                 -mov edi, dword ptr [esp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    // 004a2f1e  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a2f20  a3b8135700             -mov dword ptr [0x5713b8], eax
    app->getMemory<x86::reg32>(x86::reg32(5706680) /* 0x5713b8 */) = cpu.eax;
    // 004a2f25  a320bf5900             -mov dword ptr [0x59bf20], eax
    app->getMemory<x86::reg32>(x86::reg32(5881632) /* 0x59bf20 */) = cpu.eax;
    // 004a2f2a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 004a2f2c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a2f2e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a2f31  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a2f33  e8f835feff             -call 0x486530
    cpu.esp -= 4;
    sub_486530(app, cpu);
    if (cpu.terminate) return;
    // 004a2f38  db5c2404               -fistp dword ptr [esp + 4]
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = x86::reg32(x86::sreg32(cpu.fpu.rndint()));
    cpu.fpu.pop();
    // 004a2f3c  8b4c2404               -mov ecx, dword ptr [esp + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a2f40  48                     -dec eax
    (cpu.eax)--;
    // 004a2f41  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a2f43  a3bc135700             -mov dword ptr [0x5713bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5706684) /* 0x5713bc */) = cpu.eax;
    // 004a2f48  a324bf5900             -mov dword ptr [0x59bf24], eax
    app->getMemory<x86::reg32>(x86::reg32(5881636) /* 0x59bf24 */) = cpu.eax;
    // 004a2f4d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a2f50  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a2f52  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a2f54  a3c0135700             -mov dword ptr [0x5713c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5706688) /* 0x5713c0 */) = cpu.eax;
    // 004a2f59  a328bf5900             -mov dword ptr [0x59bf28], eax
    app->getMemory<x86::reg32>(x86::reg32(5881640) /* 0x59bf28 */) = cpu.eax;
    // 004a2f5e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004a2f60  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a2f62  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004a2f65  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 004a2f67  48                     -dec eax
    (cpu.eax)--;
    // 004a2f68  8b3530bf5900           -mov esi, dword ptr [0x59bf30]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5881648) /* 0x59bf30 */);
    // 004a2f6e  a3c4135700             -mov dword ptr [0x5713c4], eax
    app->getMemory<x86::reg32>(x86::reg32(5706692) /* 0x5713c4 */) = cpu.eax;
    // 004a2f73  a32cbf5900             -mov dword ptr [0x59bf2c], eax
    app->getMemory<x86::reg32>(x86::reg32(5881644) /* 0x59bf2c */) = cpu.eax;
    // 004a2f78  3b3520bf5900           +cmp esi, dword ptr [0x59bf20]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5881632) /* 0x59bf20 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2f7e  7529                   -jne 0x4a2fa9
    if (!cpu.flags.zf)
    {
        goto L_0x004a2fa9;
    }
    // 004a2f80  a124bf5900             -mov eax, dword ptr [0x59bf24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5881636) /* 0x59bf24 */);
    // 004a2f85  3b0534bf5900           +cmp eax, dword ptr [0x59bf34]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5881652) /* 0x59bf34 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2f8b  751c                   -jne 0x4a2fa9
    if (!cpu.flags.zf)
    {
        goto L_0x004a2fa9;
    }
    // 004a2f8d  a128bf5900             -mov eax, dword ptr [0x59bf28]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5881640) /* 0x59bf28 */);
    // 004a2f92  3b0538bf5900           +cmp eax, dword ptr [0x59bf38]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5881656) /* 0x59bf38 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2f98  750f                   -jne 0x4a2fa9
    if (!cpu.flags.zf)
    {
        goto L_0x004a2fa9;
    }
    // 004a2f9a  a12cbf5900             -mov eax, dword ptr [0x59bf2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5881644) /* 0x59bf2c */);
    // 004a2f9f  8b153cbf5900           -mov edx, dword ptr [0x59bf3c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5881660) /* 0x59bf3c */);
    // 004a2fa5  39d0                   +cmp eax, edx
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
    // 004a2fa7  7413                   -je 0x4a2fbc
    if (cpu.flags.zf)
    {
        goto L_0x004a2fbc;
    }
L_0x004a2fa9:
    // 004a2fa9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a2fae  a36cda4d00             -mov dword ptr [0x4dda6c], eax
    app->getMemory<x86::reg32>(x86::reg32(5102188) /* 0x4dda6c */) = cpu.eax;
    // 004a2fb3  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a2fb6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2fb7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2fb8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2fb9  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004a2fbc:
    // 004a2fbc  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a2fbe  a36cda4d00             -mov dword ptr [0x4dda6c], eax
    app->getMemory<x86::reg32>(x86::reg32(5102188) /* 0x4dda6c */) = cpu.eax;
    // 004a2fc3  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a2fc6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2fc7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2fc8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a2fc9  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip  */
void Application::sub_4a2fcc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a2fcc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a2fcd  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004a2fd0  833d64da4d0000         +cmp dword ptr [0x4dda64], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102180) /* 0x4dda64 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2fd7  0f8498000000           -je 0x4a3075
    if (cpu.flags.zf)
    {
        goto L_0x004a3075;
    }
L_0x004a2fdd:
    // 004a2fdd  833d68da4d0000         +cmp dword ptr [0x4dda68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102184) /* 0x4dda68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a2fe4  740d                   -je 0x4a2ff3
    if (cpu.flags.zf)
    {
        goto L_0x004a2ff3;
    }
    // 004a2fe6  6878134d00             -push 0x4d1378
    app->getMemory<x86::reg32>(cpu.esp-4) = 5051256 /*0x4d1378*/;
    cpu.esp -= 4;
    // 004a2feb  e8a4e8ffff             -call 0x4a1894
    cpu.esp -= 4;
    sub_4a1894(app, cpu);
    if (cpu.terminate) return;
    // 004a2ff0  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
L_0x004a2ff3:
    // 004a2ff3  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a2ff5  e83efeffff             -call 0x4a2e38
    cpu.esp -= 4;
    sub_4a2e38(app, cpu);
    if (cpu.terminate) return;
L_0x004a2ffa:
    // 004a2ffa  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a2ffc  ff1518145700           -call dword ptr [0x571418]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706776) /* 0x571418 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3002  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a3004  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a3006  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a300a  be6c000000             -mov esi, 0x6c
    cpu.esi = 108 /*0x6c*/;
    // 004a300f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a3010  a124da4d00             -mov eax, dword ptr [0x4dda24]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102116) /* 0x4dda24 */);
    // 004a3015  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 004a3019  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a301b  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a301d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a301e  a364da4d00             -mov dword ptr [0x4dda64], eax
    app->getMemory<x86::reg32>(x86::reg32(5102180) /* 0x4dda64 */) = cpu.eax;
    // 004a3023  ff5264                 -call dword ptr [edx + 0x64]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(100) /* 0x64 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3026  a3d8d94d00             -mov dword ptr [0x4dd9d8], eax
    app->getMemory<x86::reg32>(x86::reg32(5102040) /* 0x4dd9d8 */) = cpu.eax;
    // 004a302b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a302d  7558                   -jne 0x4a3087
    if (!cpu.flags.zf)
    {
        goto L_0x004a3087;
    }
    // 004a302f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a3030  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004a3034  a34cbf5900             -mov dword ptr [0x59bf4c], eax
    app->getMemory<x86::reg32>(x86::reg32(5881676) /* 0x59bf4c */) = cpu.eax;
    // 004a3039  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a303d  8b7c2458               -mov edi, dword ptr [esp + 0x58]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 004a3041  a350bf5900             -mov dword ptr [0x59bf50], eax
    app->getMemory<x86::reg32>(x86::reg32(5881680) /* 0x59bf50 */) = cpu.eax;
    // 004a3046  83ff10                 +cmp edi, 0x10
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3049  754f                   -jne 0x4a309a
    if (!cpu.flags.zf)
    {
        goto L_0x004a309a;
    }
    // 004a304b  817c2460e0070000       +cmp dword ptr [esp + 0x60], 0x7e0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2016 /*0x7e0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3053  7439                   -je 0x4a308e
    if (cpu.flags.zf)
    {
        goto L_0x004a308e;
    }
    // 004a3055  c70554bf590003000000   -mov dword ptr [0x59bf54], 3
    app->getMemory<x86::reg32>(x86::reg32(5881684) /* 0x59bf54 */) = 3 /*0x3*/;
L_0x004a305f:
    // 004a305f  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a3064  b84cbf5900             -mov eax, 0x59bf4c
    cpu.eax = 5881676 /*0x59bf4c*/;
    // 004a3069  893568da4d00           -mov dword ptr [0x4dda68], esi
    app->getMemory<x86::reg32>(x86::reg32(5102184) /* 0x4dda68 */) = cpu.esi;
    // 004a306f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3070  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004a3073  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3074  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a3075:
    // 004a3075  833d48bf590000         +cmp dword ptr [0x59bf48], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881672) /* 0x59bf48 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a307c  0f855bffffff           -jne 0x4a2fdd
    if (!cpu.flags.zf)
    {
        goto L_0x004a2fdd;
    }
    // 004a3082  e973ffffff             -jmp 0x4a2ffa
    goto L_0x004a2ffa;
L_0x004a3087:
    // 004a3087  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a3089  83c46c                 +add esp, 0x6c
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
    // 004a308c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a308d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a308e:
    // 004a308e  c70554bf590004000000   -mov dword ptr [0x59bf54], 4
    app->getMemory<x86::reg32>(x86::reg32(5881684) /* 0x59bf54 */) = 4 /*0x4*/;
    // 004a3098  ebc5                   -jmp 0x4a305f
    goto L_0x004a305f;
L_0x004a309a:
    // 004a309a  83ff20                 +cmp edi, 0x20
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
    // 004a309d  75c0                   -jne 0x4a305f
    if (!cpu.flags.zf)
    {
        goto L_0x004a305f;
    }
    // 004a309f  c70554bf590005000000   -mov dword ptr [0x59bf54], 5
    app->getMemory<x86::reg32>(x86::reg32(5881684) /* 0x59bf54 */) = 5 /*0x5*/;
    // 004a30a9  ebb4                   -jmp 0x4a305f
    goto L_0x004a305f;
}

/* align: skip 0x90 */
void Application::sub_4a30ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a30ac  833d68da4d0000         +cmp dword ptr [0x4dda68], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102184) /* 0x4dda68 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a30b3  743d                   -je 0x4a30f2
    if (cpu.flags.zf)
    {
        goto L_0x004a30f2;
    }
    // 004a30b5  8b0d64da4d00           -mov ecx, dword ptr [0x4dda64]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5102180) /* 0x4dda64 */);
    // 004a30bb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a30bd  7433                   -je 0x4a30f2
    if (cpu.flags.zf)
    {
        goto L_0x004a30f2;
    }
    // 004a30bf  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a30c0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a30c1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a30c3  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a30c5  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a30c9  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004a30cb  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a30cc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a30cd  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a30cf  ff9280000000           -call dword ptr [edx + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a30d5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a30d6  893564da4d00           -mov dword ptr [0x4dda64], esi
    app->getMemory<x86::reg32>(x86::reg32(5102180) /* 0x4dda64 */) = cpu.esi;
    // 004a30dc  893568da4d00           -mov dword ptr [0x4dda68], esi
    app->getMemory<x86::reg32>(x86::reg32(5102184) /* 0x4dda68 */) = cpu.esi;
    // 004a30e2  ff1518145700           -call dword ptr [0x571418]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706776) /* 0x571418 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a30e8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a30ed  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a30ee  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a30ef  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004a30f2:
    // 004a30f2  68a8134d00             -push 0x4d13a8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5051304 /*0x4d13a8*/;
    cpu.esp -= 4;
    // 004a30f7  e898e7ffff             -call 0x4a1894
    cpu.esp -= 4;
    sub_4a1894(app, cpu);
    if (cpu.terminate) return;
    // 004a30fc  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a30ff  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a3101  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a3110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3110  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a3111  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a3112  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3115  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a3119  8b742414               -mov esi, dword ptr [esp + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a311d  83f90a                 +cmp ecx, 0xa
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(10 /*0xa*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3120  7329                   -jae 0x4a314b
    if (!cpu.flags.cf)
    {
        goto L_0x004a314b;
    }
    // 004a3122  83f904                 +cmp ecx, 4
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
    // 004a3125  0f8364010000           -jae 0x4a328f
    if (!cpu.flags.cf)
    {
        goto L_0x004a328f;
    }
    // 004a312b  83f901                 +cmp ecx, 1
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
    // 004a312e  0f8316020000           -jae 0x4a334a
    if (!cpu.flags.cf)
    {
        goto L_0x004a334a;
    }
    // 004a3134  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a3136  0f85c5010000           -jne 0x4a3301
    if (!cpu.flags.zf)
    {
        goto L_0x004a3301;
    }
L_0x004a313c:
    // 004a313c  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a3141  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a3143  83c404                 +add esp, 4
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
    // 004a3146  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3147  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3148  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a314b:
    // 004a314b  771e                   -ja 0x4a316b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a316b;
    }
    // 004a314d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a314f  0f85cf020000           -jne 0x4a3424
    if (!cpu.flags.zf)
    {
        goto L_0x004a3424;
    }
    // 004a3155  800d8913570020         -or byte ptr [0x571389], 0x20
    app->getMemory<x86::reg8>(x86::reg32(5706633) /* 0x571389 */) |= x86::reg8(x86::sreg8(32 /*0x20*/));
    // 004a315c  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a3161  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a3163  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3166  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3167  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3168  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a316b:
    // 004a316b  81f9ca000000           +cmp ecx, 0xca
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(202 /*0xca*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3171  7327                   -jae 0x4a319a
    if (!cpu.flags.cf)
    {
        goto L_0x004a319a;
    }
    // 004a3173  83f911                 +cmp ecx, 0x11
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(17 /*0x11*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3176  0f83b5000000           -jae 0x4a3231
    if (!cpu.flags.cf)
    {
        goto L_0x004a3231;
    }
    // 004a317c  83f910                 +cmp ecx, 0x10
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a317f  0f857c010000           -jne 0x4a3301
    if (!cpu.flags.zf)
    {
        goto L_0x004a3301;
    }
    // 004a3185  8935e0135700           -mov dword ptr [0x5713e0], esi
    app->getMemory<x86::reg32>(x86::reg32(5706720) /* 0x5713e0 */) = cpu.esi;
    // 004a318b  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a3190  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a3192  83c404                 +add esp, 4
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
    // 004a3195  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3196  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3197  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a319a:
    // 004a319a  7722                   -ja 0x4a31be
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a31be;
    }
    // 004a319c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a319e  0f8496020000           -je 0x4a343a
    if (cpu.flags.zf)
    {
        goto L_0x004a343a;
    }
    // 004a31a4  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
L_0x004a31a9:
    // 004a31a9  890da4135700           -mov dword ptr [0x5713a4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5706660) /* 0x5713a4 */) = cpu.ecx;
    // 004a31af  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a31b4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a31b6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a31b9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a31ba  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a31bb  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a31be:
    // 004a31be  81f9cc000000           +cmp ecx, 0xcc
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(204 /*0xcc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a31c4  7315                   -jae 0x4a31db
    if (!cpu.flags.cf)
    {
        goto L_0x004a31db;
    }
    // 004a31c6  8935e8d94d00           -mov dword ptr [0x4dd9e8], esi
    app->getMemory<x86::reg32>(x86::reg32(5102056) /* 0x4dd9e8 */) = cpu.esi;
    // 004a31cc  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a31d1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a31d3  83c404                 +add esp, 4
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
    // 004a31d6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a31d7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a31d8  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a31db:
    // 004a31db  0f8660020000           -jbe 0x4a3441
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a3441;
    }
    // 004a31e1  81f9cd000000           +cmp ecx, 0xcd
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(205 /*0xcd*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a31e7  771e                   -ja 0x4a3207
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a3207;
    }
    // 004a31e9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a31eb  0f8479020000           -je 0x4a346a
    if (cpu.flags.zf)
    {
        goto L_0x004a346a;
    }
    // 004a31f1  800d8a13570004         -or byte ptr [0x57138a], 4
    app->getMemory<x86::reg8>(x86::reg32(5706634) /* 0x57138a */) |= x86::reg8(x86::sreg8(4 /*0x4*/));
    // 004a31f8  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a31fd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a31ff  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3202  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3203  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3204  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a3207:
    // 004a3207  81f9ce000000           +cmp ecx, 0xce
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(206 /*0xce*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a320d  0f85ee000000           -jne 0x4a3301
    if (!cpu.flags.zf)
    {
        goto L_0x004a3301;
    }
    // 004a3213  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a3215  0f8465020000           -je 0x4a3480
    if (cpu.flags.zf)
    {
        goto L_0x004a3480;
    }
    // 004a321b  800d8913570002         -or byte ptr [0x571389], 2
    app->getMemory<x86::reg8>(x86::reg32(5706633) /* 0x571389 */) |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 004a3222  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a3227  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a3229  83c404                 +add esp, 4
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
    // 004a322c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a322d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a322e  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a3231:
    // 004a3231  7715                   -ja 0x4a3248
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a3248;
    }
    // 004a3233  8935e4d94d00           -mov dword ptr [0x4dd9e4], esi
    app->getMemory<x86::reg32>(x86::reg32(5102052) /* 0x4dd9e4 */) = cpu.esi;
    // 004a3239  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a323e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a3240  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3243  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3244  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3245  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a3248:
    // 004a3248  83f913                 +cmp ecx, 0x13
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19 /*0x13*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a324b  0f82b0000000           -jb 0x4a3301
    if (cpu.flags.cf)
    {
        goto L_0x004a3301;
    }
    // 004a3251  771b                   -ja 0x4a326e
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a326e;
    }
    // 004a3253  b907000000             -mov ecx, 7
    cpu.ecx = 7 /*0x7*/;
    // 004a3258  bf04145700             -mov edi, 0x571404
    cpu.edi = 5706756 /*0x571404*/;
    // 004a325d  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a325f  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a3264  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a3266  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3269  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a326a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a326b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a326e:
    // 004a326e  81f9c9000000           +cmp ecx, 0xc9
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(201 /*0xc9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3274  0f8587000000           -jne 0x4a3301
    if (!cpu.flags.zf)
    {
        goto L_0x004a3301;
    }
    // 004a327a  8935dc135700           -mov dword ptr [0x5713dc], esi
    app->getMemory<x86::reg32>(x86::reg32(5706716) /* 0x5713dc */) = cpu.esi;
    // 004a3280  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a3285  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a3287  83c404                 +add esp, 4
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
    // 004a328a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a328b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a328c  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a328f:
    // 004a328f  775d                   -ja 0x4a32ee
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a32ee;
    }
    // 004a3291  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004a3293  c1f910                 -sar ecx, 0x10
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (16 /*0x10*/ % 32));
    // 004a3296  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a329c  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a329f  89f1                   -mov ecx, esi
    cpu.ecx = cpu.esi;
    // 004a32a1  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004a32a4  c1f908                 -sar ecx, 8
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (8 /*0x8*/ % 32));
    // 004a32a7  dd05f0134d00           -fld qword ptr [0x4d13f0]
    cpu.fpu.push(x86::Float(app->getMemory<double>(x86::reg32(5051376) /* 0x4d13f0 */)));
    // 004a32ad  d9c9                   -fxch st(1)
    {
        x86::Float tmp = cpu.fpu.st(0);
        cpu.fpu.st(0) = cpu.fpu.st(1);
        cpu.fpu.st(1) = tmp;
    }
    // 004a32af  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a32b1  81e1ff000000           -and ecx, 0xff
    cpu.ecx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a32b7  81e6ff000000           -and esi, 0xff
    cpu.esi &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004a32bd  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 004a32c0  d91d98135700           -fstp dword ptr [0x571398]
    app->getMemory<float>(x86::reg32(5706648) /* 0x571398 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a32c6  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004a32c9  d8c9                   -fmul st(1)
    cpu.fpu.st(0) *= x86::Float(cpu.fpu.st(1));
    // 004a32cb  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004a32ce  d91d9c135700           -fstp dword ptr [0x57139c]
    app->getMemory<float>(x86::reg32(5706652) /* 0x57139c */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a32d4  db0424                 -fild dword ptr [esp]
    cpu.fpu.push(x86::Float(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp))));
    // 004a32d7  dec9                   -fmulp st(1)
    cpu.fpu.st(1) *= cpu.fpu.st(0);
    cpu.fpu.pop();
    // 004a32d9  d91da0135700           -fstp dword ptr [0x5713a0]
    app->getMemory<float>(x86::reg32(5706656) /* 0x5713a0 */) = float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004a32df  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a32e4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a32e6  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a32e9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a32ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a32eb  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a32ee:
    // 004a32ee  83f907                 +cmp ecx, 7
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
    // 004a32f1  731a                   -jae 0x4a330d
    if (!cpu.flags.cf)
    {
        goto L_0x004a330d;
    }
    // 004a32f3  83f906                 +cmp ecx, 6
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a32f6  7509                   -jne 0x4a3301
    if (!cpu.flags.zf)
    {
        goto L_0x004a3301;
    }
    // 004a32f8  83fe01                 +cmp esi, 1
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
    // 004a32fb  0f843bfeffff           -je 0x4a313c
    if (cpu.flags.zf)
    {
        goto L_0x004a313c;
    }
L_0x004a3301:
    // 004a3301  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a3303  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a3305  83c404                 +add esp, 4
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
    // 004a3308  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3309  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a330a  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a330d:
    // 004a330d  0f8729feffff           -ja 0x4a313c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a313c;
    }
    // 004a3313  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a3315  0f84d4000000           -je 0x4a33ef
    if (cpu.flags.zf)
    {
        goto L_0x004a33ef;
    }
    // 004a331b  83fe01                 +cmp esi, 1
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
    // 004a331e  0f85e1000000           -jne 0x4a3405
    if (!cpu.flags.zf)
    {
        goto L_0x004a3405;
    }
    // 004a3324  a088135700             -mov al, byte ptr [0x571388]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5706632) /* 0x571388 */);
    // 004a3329  0c01                   -or al, 1
    cpu.al |= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004a332b  a288135700             -mov byte ptr [0x571388], al
    app->getMemory<x86::reg8>(x86::reg32(5706632) /* 0x571388 */) = cpu.al;
    // 004a3330  88c4                   -mov ah, al
    cpu.ah = cpu.al;
    // 004a3332  80e4fb                 -and ah, 0xfb
    cpu.ah &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 004a3335  882588135700           -mov byte ptr [0x571388], ah
    app->getMemory<x86::reg8>(x86::reg32(5706632) /* 0x571388 */) = cpu.ah;
    // 004a333b  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a3340  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a3342  83c404                 +add esp, 4
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
    // 004a3345  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3346  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3347  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a334a:
    // 004a334a  761e                   -jbe 0x4a336a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004a336a;
    }
    // 004a334c  83f902                 +cmp ecx, 2
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
    // 004a334f  7765                   -ja 0x4a33b6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004a33b6;
    }
    // 004a3351  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a3353  752a                   -jne 0x4a337f
    if (!cpu.flags.zf)
    {
        goto L_0x004a337f;
    }
    // 004a3355  893584135700           -mov dword ptr [0x571384], esi
    app->getMemory<x86::reg32>(x86::reg32(5706628) /* 0x571384 */) = cpu.esi;
    // 004a335b  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a3360  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a3362  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3365  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3366  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3367  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a336a:
    // 004a336a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a336b  e828010000             -call 0x4a3498
    cpu.esp -= 4;
    sub_4a3498(app, cpu);
    if (cpu.terminate) return;
    // 004a3370  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a3375  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a3377  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a337a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a337b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a337c  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a337f:
    // 004a337f  83fe01                 +cmp esi, 1
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
    // 004a3382  7515                   -jne 0x4a3399
    if (!cpu.flags.zf)
    {
        goto L_0x004a3399;
    }
    // 004a3384  893584135700           -mov dword ptr [0x571384], esi
    app->getMemory<x86::reg32>(x86::reg32(5706628) /* 0x571384 */) = cpu.esi;
    // 004a338a  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a338f  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a3391  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3394  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3395  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3396  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a3399:
    // 004a3399  83fe02                 +cmp esi, 2
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
    // 004a339c  0f855fffffff           -jne 0x4a3301
    if (!cpu.flags.zf)
    {
        goto L_0x004a3301;
    }
    // 004a33a2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a33a4  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004a33a6  891584135700           -mov dword ptr [0x571384], edx
    app->getMemory<x86::reg32>(x86::reg32(5706628) /* 0x571384 */) = cpu.edx;
    // 004a33ac  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a33ae  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a33b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a33b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a33b3  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a33b6:
    // 004a33b6  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a33b8  7516                   -jne 0x4a33d0
    if (!cpu.flags.zf)
    {
        goto L_0x004a33d0;
    }
    // 004a33ba  80258a135700f7         -and byte ptr [0x57138a], 0xf7
    app->getMemory<x86::reg8>(x86::reg32(5706634) /* 0x57138a */) &= x86::reg8(x86::sreg8(247 /*0xf7*/));
    // 004a33c1  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a33c6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a33c8  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a33cb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a33cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a33cd  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a33d0:
    // 004a33d0  83fe01                 +cmp esi, 1
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
    // 004a33d3  0f8528ffffff           -jne 0x4a3301
    if (!cpu.flags.zf)
    {
        goto L_0x004a3301;
    }
    // 004a33d9  800d8a13570008         -or byte ptr [0x57138a], 8
    app->getMemory<x86::reg8>(x86::reg32(5706634) /* 0x57138a */) |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 004a33e0  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a33e5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a33e7  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a33ea  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a33eb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a33ec  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a33ef:
    // 004a33ef  802588135700fa         -and byte ptr [0x571388], 0xfa
    app->getMemory<x86::reg8>(x86::reg32(5706632) /* 0x571388 */) &= x86::reg8(x86::sreg8(250 /*0xfa*/));
    // 004a33f6  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a33fb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a33fd  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3400  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3401  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3402  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a3405:
    // 004a3405  83fe02                 +cmp esi, 2
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
    // 004a3408  0f85f3feffff           -jne 0x4a3301
    if (!cpu.flags.zf)
    {
        goto L_0x004a3301;
    }
    // 004a340e  800d8813570005         -or byte ptr [0x571388], 5
    app->getMemory<x86::reg8>(x86::reg32(5706632) /* 0x571388 */) |= x86::reg8(x86::sreg8(5 /*0x5*/));
    // 004a3415  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a341a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a341c  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a341f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3420  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3421  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a3424:
    // 004a3424  802589135700df         -and byte ptr [0x571389], 0xdf
    app->getMemory<x86::reg8>(x86::reg32(5706633) /* 0x571389 */) &= x86::reg8(x86::sreg8(223 /*0xdf*/));
    // 004a342b  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a3430  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a3432  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3435  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3436  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3437  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a343a:
    // 004a343a  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004a343c  e968fdffff             -jmp 0x4a31a9
    goto L_0x004a31a9;
L_0x004a3441:
    // 004a3441  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 004a3446  bfecd94d00             -mov edi, 0x4dd9ec
    cpu.edi = 5102060 /*0x4dd9ec*/;
    // 004a344b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a344c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a344e  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004a3451  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a3453  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004a3455  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004a3458  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004a345a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a345b  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a3460  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a3462  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3465  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3466  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3467  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a346a:
    // 004a346a  80258a135700fb         -and byte ptr [0x57138a], 0xfb
    app->getMemory<x86::reg8>(x86::reg32(5706634) /* 0x57138a */) &= x86::reg8(x86::sreg8(251 /*0xfb*/));
    // 004a3471  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a3476  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a3478  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a347b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a347c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a347d  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a3480:
    // 004a3480  802589135700fd         -and byte ptr [0x571389], 0xfd
    app->getMemory<x86::reg8>(x86::reg32(5706633) /* 0x571389 */) &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 004a3487  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 004a348c  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a348e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3491  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3492  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3493  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a3498(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3498  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a349c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a349e  742c                   -je 0x4a34cc
    if (cpu.flags.zf)
    {
        goto L_0x004a34cc;
    }
    // 004a34a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a34a1  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004a34a6  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004a34a9  8a1588135700           -mov dl, byte ptr [0x571388]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5706632) /* 0x571388 */);
    // 004a34af  a38c135700             -mov dword ptr [0x57138c], eax
    app->getMemory<x86::reg32>(x86::reg32(5706636) /* 0x57138c */) = cpu.eax;
    // 004a34b4  80ca02                 -or dl, 2
    cpu.dl |= x86::reg8(x86::sreg8(2 /*0x2*/));
    // 004a34b7  891db4135700           -mov dword ptr [0x5713b4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5706676) /* 0x5713b4 */) = cpu.ebx;
    // 004a34bd  881588135700           -mov byte ptr [0x571388], dl
    app->getMemory<x86::reg8>(x86::reg32(5706632) /* 0x571388 */) = cpu.dl;
    // 004a34c3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a34c4  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a34c9  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004a34cc:
    // 004a34cc  a38c135700             -mov dword ptr [0x57138c], eax
    app->getMemory<x86::reg32>(x86::reg32(5706636) /* 0x57138c */) = cpu.eax;
    // 004a34d1  a3b4135700             -mov dword ptr [0x5713b4], eax
    app->getMemory<x86::reg32>(x86::reg32(5706676) /* 0x5713b4 */) = cpu.eax;
    // 004a34d6  802588135700fd         -and byte ptr [0x571388], 0xfd
    app->getMemory<x86::reg8>(x86::reg32(5706632) /* 0x571388 */) &= x86::reg8(x86::sreg8(253 /*0xfd*/));
    // 004a34dd  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a34e2  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a34f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a34f0  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004a34f2  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004a34f4  0100                   -add dword ptr [eax], eax
    (app->getMemory<x86::reg32>(cpu.eax)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a34f6  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004a34f8  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 004a34fa  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004a34fc  0300                   -add eax, dword ptr [eax]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
    // 004a34fe  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004a3500  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004a3502  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004a3504  0100                   -add dword ptr [eax], eax
    (app->getMemory<x86::reg32>(cpu.eax)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a3506  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004a3508  0200                   -add al, byte ptr [eax]
    (cpu.al) += x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(cpu.eax)));
    // 004a350a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004a350c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 004a350e  0100                   -add dword ptr [eax], eax
    (app->getMemory<x86::reg32>(cpu.eax)) += x86::reg32(x86::sreg32(cpu.eax));
    // 004a3510  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a3511  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a3512  81ec90000000           -sub esp, 0x90
    (cpu.esp) -= x86::reg32(x86::sreg32(144 /*0x90*/));
    // 004a3518  8dbc2480000000         -lea edi, [esp + 0x80]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 004a351f  bef0344a00             -mov esi, 0x4a34f0
    cpu.esi = 4863216 /*0x4a34f0*/;
    // 004a3524  8b1544bf5900           -mov edx, dword ptr [0x59bf44]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5881668) /* 0x59bf44 */);
    // 004a352a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a352b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a352c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a352d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a352e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a3530  0f8489000000           -je 0x4a35bf
    if (cpu.flags.zf)
    {
        goto L_0x004a35bf;
    }
    // 004a3536  833d40bf590000         +cmp dword ptr [0x59bf40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881664) /* 0x59bf40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a353d  756c                   -jne 0x4a35ab
    if (!cpu.flags.zf)
    {
        goto L_0x004a35ab;
    }
L_0x004a353f:
    // 004a353f  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004a3544  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004a3546  8bb4249c000000         -mov esi, dword ptr [esp + 0x9c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 004a354d  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a354f  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a3551  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004a3556  8d7c2420               -lea edi, [esp + 0x20]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a355a  8bb424a0000000         -mov esi, dword ptr [esp + 0xa0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 004a3561  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3562  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a3564  8d842484000000         -lea eax, [esp + 0x84]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 004a356b  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004a3570  8d7c2444               -lea edi, [esp + 0x44]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004a3574  8bb424a8000000         -mov esi, dword ptr [esp + 0xa8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 004a357b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a357c  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a357e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a3580  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004a3585  8d7c246c               -lea edi, [esp + 0x6c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 004a3589  8bb424b4000000         -mov esi, dword ptr [esp + 0xb4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 004a3590  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a3595  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a3597  ff1554145700           -call dword ptr [0x571454]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706836) /* 0x571454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a359d  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a35a0  81c490000000           -add esp, 0x90
    (cpu.esp) += x86::reg32(x86::sreg32(144 /*0x90*/));
    // 004a35a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a35a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a35a8  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x004a35ab:
    // 004a35ab  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a35ad  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a35b2  ff154c145700           -call dword ptr [0x57144c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706828) /* 0x57144c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a35b8  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a35bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a35bd  7580                   -jne 0x4a353f
    if (!cpu.flags.zf)
    {
        goto L_0x004a353f;
    }
L_0x004a35bf:
    // 004a35bf  e82cf6ffff             -call 0x4a2bf0
    cpu.esp -= 4;
    sub_4a2bf0(app, cpu);
    if (cpu.terminate) return;
    // 004a35c4  e976ffffff             -jmp 0x4a353f
    goto L_0x004a353f;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a35cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a35cc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a35cd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a35ce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a35cf  833d44bf590000         +cmp dword ptr [0x59bf44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881668) /* 0x59bf44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a35d6  7440                   -je 0x4a3618
    if (cpu.flags.zf)
    {
        goto L_0x004a3618;
    }
    // 004a35d8  833d40bf590000         +cmp dword ptr [0x59bf40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881664) /* 0x59bf40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a35df  7523                   -jne 0x4a3604
    if (!cpu.flags.zf)
    {
        goto L_0x004a3604;
    }
L_0x004a35e1:
    // 004a35e1  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a35e5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a35e6  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a35ea  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a35eb  8b7c2418               -mov edi, dword ptr [esp + 0x18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a35ef  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a35f0  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a35f5  ff1554145700           -call dword ptr [0x571454]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706836) /* 0x571454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a35fb  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a35fe  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a35ff  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3600  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3601  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a3604:
    // 004a3604  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a3606  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a360b  ff154c145700           -call dword ptr [0x57144c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706828) /* 0x57144c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3611  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a3614  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a3616  75c9                   -jne 0x4a35e1
    if (!cpu.flags.zf)
    {
        goto L_0x004a35e1;
    }
L_0x004a3618:
    // 004a3618  e8d3f5ffff             -call 0x4a2bf0
    cpu.esp -= 4;
    sub_4a2bf0(app, cpu);
    if (cpu.terminate) return;
    // 004a361d  ebc2                   -jmp 0x4a35e1
    goto L_0x004a35e1;
}

/* align: skip 0x90 */
void Application::sub_4a3620(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3620  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a3621  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a3622  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a3623  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a3624  81ec00100000           -sub esp, 0x1000
    (cpu.esp) -= x86::reg32(x86::sreg32(4096 /*0x1000*/));
    // 004a362a  8bb42414100000         -mov esi, dword ptr [esp + 0x1014]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4116) /* 0x1014 */);
    // 004a3631  8bac2418100000         -mov ebp, dword ptr [esp + 0x1018]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4120) /* 0x1018 */);
    // 004a3638  8b9c241c100000         -mov ebx, dword ptr [esp + 0x101c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4124) /* 0x101c */);
    // 004a363f  833d44bf590000         +cmp dword ptr [0x59bf44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881668) /* 0x59bf44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3646  0f84ba000000           -je 0x4a3706
    if (cpu.flags.zf)
    {
        goto L_0x004a3706;
    }
    // 004a364c  833d40bf590000         +cmp dword ptr [0x59bf40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881664) /* 0x59bf40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3653  0f8595000000           -jne 0x4a36ee
    if (!cpu.flags.zf)
    {
        goto L_0x004a36ee;
    }
L_0x004a3659:
    // 004a3659  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a365b  0f84b6000000           -je 0x4a3717
    if (cpu.flags.zf)
    {
        goto L_0x004a3717;
    }
    // 004a3661  81fe00010000           +cmp esi, 0x100
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3667  0f8ea3000000           -jle 0x4a3710
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a3710;
    }
    // 004a366d  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
L_0x004a3672:
    // 004a3672  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a3674  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3677  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004a367a  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a367c  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a367f  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 004a3683  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a3685  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3688  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004a368c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a368e  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a3690  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3693  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 004a3697  83fa01                 +cmp edx, 1
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
    // 004a369a  7e33                   -jle 0x4a36cf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a36cf;
    }
    // 004a369c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a369e  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 004a36a3  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
L_0x004a36a6:
    // 004a36a6  8b5404f4               -mov edx, dword ptr [esp + eax - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-12) /* -0xc */ + cpu.eax * 1);
    // 004a36aa  891404                 -mov dword ptr [esp + eax], edx
    app->getMemory<x86::reg32>(cpu.esp + cpu.eax * 1) = cpu.edx;
    // 004a36ad  8b13                   -mov edx, dword ptr [ebx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a36af  89540404               -mov dword ptr [esp + eax + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */ + cpu.eax * 1) = cpu.edx;
    // 004a36b3  83c010                 -add eax, 0x10
    (cpu.eax) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a36b6  8b5304                 -mov edx, dword ptr [ebx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004a36b9  895404f8               -mov dword ptr [esp + eax - 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-8) /* -0x8 */ + cpu.eax * 1) = cpu.edx;
    // 004a36bd  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a36c0  8b5404e8               -mov edx, dword ptr [esp + eax - 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-24) /* -0x18 */ + cpu.eax * 1);
    // 004a36c4  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a36c7  895404fc               -mov dword ptr [esp + eax - 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1) = cpu.edx;
    // 004a36cb  39c8                   +cmp eax, ecx
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
    // 004a36cd  7cd7                   -jl 0x4a36a6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a36a6;
    }
L_0x004a36cf:
    // 004a36cf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a36d0  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a36d4  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a36d5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a36d6  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a36db  83eb08                 -sub ebx, 8
    (cpu.ebx) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a36de  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004a36e0  ff1554145700           -call dword ptr [0x571454]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706836) /* 0x571454 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a36e6  83c410                 +add esp, 0x10
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
    // 004a36e9  e96bffffff             -jmp 0x4a3659
    goto L_0x004a3659;
L_0x004a36ee:
    // 004a36ee  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a36f0  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a36f5  ff154c145700           -call dword ptr [0x57144c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706828) /* 0x57144c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a36fb  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a36fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a3700  0f8553ffffff           -jne 0x4a3659
    if (!cpu.flags.zf)
    {
        goto L_0x004a3659;
    }
L_0x004a3706:
    // 004a3706  e8e5f4ffff             -call 0x4a2bf0
    cpu.esp -= 4;
    sub_4a2bf0(app, cpu);
    if (cpu.terminate) return;
    // 004a370b  e949ffffff             -jmp 0x4a3659
    goto L_0x004a3659;
L_0x004a3710:
    // 004a3710  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a3712  e95bffffff             -jmp 0x4a3672
    goto L_0x004a3672;
L_0x004a3717:
    // 004a3717  81c400100000           -add esp, 0x1000
    (cpu.esp) += x86::reg32(x86::sreg32(4096 /*0x1000*/));
    // 004a371d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a371e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a371f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3720  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3721  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4a3724(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3724  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a3725  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a3726  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004a3729  8d7c2460               -lea edi, [esp + 0x60]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004a372d  be00354a00             -mov esi, 0x4a3500
    cpu.esi = 4863232 /*0x4a3500*/;
    // 004a3732  8b1544bf5900           -mov edx, dword ptr [0x59bf44]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5881668) /* 0x59bf44 */);
    // 004a3738  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a3739  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a373a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a373b  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a373d  746b                   -je 0x4a37aa
    if (cpu.flags.zf)
    {
        goto L_0x004a37aa;
    }
    // 004a373f  833d40bf590000         +cmp dword ptr [0x59bf40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881664) /* 0x59bf40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3746  754e                   -jne 0x4a3796
    if (!cpu.flags.zf)
    {
        goto L_0x004a3796;
    }
L_0x004a3748:
    // 004a3748  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004a374d  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004a374f  8b742478               -mov esi, dword ptr [esp + 0x78]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 004a3753  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a3755  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a3757  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004a375c  8d7c2420               -lea edi, [esp + 0x20]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a3760  8b74247c               -mov esi, dword ptr [esp + 0x7c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 004a3764  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3765  8d442464               -lea eax, [esp + 0x64]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 004a3769  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a376b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a376c  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004a3771  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a3773  8d7c244c               -lea edi, [esp + 0x4c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 004a3777  8bb4248c000000         -mov esi, dword ptr [esp + 0x8c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 004a377e  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a3783  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a3785  ff1550145700           -call dword ptr [0x571450]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706832) /* 0x571450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a378b  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a378e  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 004a3791  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3792  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3793  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a3796:
    // 004a3796  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a3798  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a379d  ff154c145700           -call dword ptr [0x57144c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706828) /* 0x57144c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a37a3  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a37a6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a37a8  759e                   -jne 0x4a3748
    if (!cpu.flags.zf)
    {
        goto L_0x004a3748;
    }
L_0x004a37aa:
    // 004a37aa  e841f4ffff             -call 0x4a2bf0
    cpu.esp -= 4;
    sub_4a2bf0(app, cpu);
    if (cpu.terminate) return;
    // 004a37af  eb97                   -jmp 0x4a3748
    goto L_0x004a3748;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a37b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a37b4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a37b5  833d44bf590000         +cmp dword ptr [0x59bf44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881668) /* 0x59bf44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a37bc  741d                   -je 0x4a37db
    if (cpu.flags.zf)
    {
        goto L_0x004a37db;
    }
    // 004a37be  833d40bf590000         +cmp dword ptr [0x59bf40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881664) /* 0x59bf40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a37c5  7419                   -je 0x4a37e0
    if (cpu.flags.zf)
    {
        goto L_0x004a37e0;
    }
    // 004a37c7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a37c9  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a37ce  ff154c145700           -call dword ptr [0x57144c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706828) /* 0x57144c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a37d4  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a37d7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a37d9  7505                   -jne 0x4a37e0
    if (!cpu.flags.zf)
    {
        goto L_0x004a37e0;
    }
L_0x004a37db:
    // 004a37db  e810f4ffff             -call 0x4a2bf0
    cpu.esp -= 4;
    sub_4a2bf0(app, cpu);
    if (cpu.terminate) return;
L_0x004a37e0:
    // 004a37e0  833de8d94d0000         +cmp dword ptr [0x4dd9e8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5102056) /* 0x4dd9e8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a37e7  7521                   -jne 0x4a380a
    if (!cpu.flags.zf)
    {
        goto L_0x004a380a;
    }
    // 004a37e9  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004a37ed  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a37ee  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a37f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a37f3  8b4c2410               -mov ecx, dword ptr [esp + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a37f7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a37f8  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a37fd  ff1550145700           -call dword ptr [0x571450]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706832) /* 0x571450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3803  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a3806  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3807  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a380a:
    // 004a380a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a380b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a380c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a380d  68ecd94d00             -push 0x4dd9ec
    app->getMemory<x86::reg32>(cpu.esp-4) = 5102060 /*0x4dd9ec*/;
    cpu.esp -= 4;
    // 004a3812  8b74241c               -mov esi, dword ptr [esp + 0x1c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004a3816  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a3817  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004a381b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a381c  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004a3820  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a3821  a1e8d94d00             -mov eax, dword ptr [0x4dd9e8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102056) /* 0x4dd9e8 */);
    // 004a3826  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a382b  8b1da4135700           -mov ebx, dword ptr [0x5713a4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5706660) /* 0x5713a4 */);
    // 004a3831  a3a4135700             -mov dword ptr [0x5713a4], eax
    app->getMemory<x86::reg32>(x86::reg32(5706660) /* 0x5713a4 */) = cpu.eax;
    // 004a3836  ff1560145700           -call dword ptr [0x571460]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706848) /* 0x571460 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a383c  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 004a383f  891da4135700           -mov dword ptr [0x5713a4], ebx
    app->getMemory<x86::reg32>(x86::reg32(5706660) /* 0x5713a4 */) = cpu.ebx;
    // 004a3845  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3846  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3847  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3848  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3849  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4a384c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a384c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a384d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a384e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a384f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a3850  81ec00080000           -sub esp, 0x800
    (cpu.esp) -= x86::reg32(x86::sreg32(2048 /*0x800*/));
    // 004a3856  8bbc2414080000         -mov edi, dword ptr [esp + 0x814]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2068) /* 0x814 */);
    // 004a385d  8bac2418080000         -mov ebp, dword ptr [esp + 0x818]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2072) /* 0x818 */);
    // 004a3864  8b9c241c080000         -mov ebx, dword ptr [esp + 0x81c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2076) /* 0x81c */);
    // 004a386b  833d44bf590000         +cmp dword ptr [0x59bf44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881668) /* 0x59bf44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3872  741d                   -je 0x4a3891
    if (cpu.flags.zf)
    {
        goto L_0x004a3891;
    }
    // 004a3874  833d40bf590000         +cmp dword ptr [0x59bf40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881664) /* 0x59bf40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a387b  7419                   -je 0x4a3896
    if (cpu.flags.zf)
    {
        goto L_0x004a3896;
    }
    // 004a387d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a387f  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a3884  ff154c145700           -call dword ptr [0x57144c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706828) /* 0x57144c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a388a  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a388d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a388f  7505                   -jne 0x4a3896
    if (!cpu.flags.zf)
    {
        goto L_0x004a3896;
    }
L_0x004a3891:
    // 004a3891  e85af3ffff             -call 0x4a2bf0
    cpu.esp -= 4;
    sub_4a2bf0(app, cpu);
    if (cpu.terminate) return;
L_0x004a3896:
    // 004a3896  800d8913570018         -or byte ptr [0x571389], 0x18
    app->getMemory<x86::reg8>(x86::reg32(5706633) /* 0x571389 */) |= x86::reg8(x86::sreg8(24 /*0x18*/));
    // 004a389d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a389f  0f84bd000000           -je 0x4a3962
    if (cpu.flags.zf)
    {
        goto L_0x004a3962;
    }
L_0x004a38a5:
    // 004a38a5  81ff00010000           +cmp edi, 0x100
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
    // 004a38ab  0f8ec5000000           -jle 0x4a3976
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a3976;
    }
    // 004a38b1  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
L_0x004a38b6:
    // 004a38b6  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 004a38b9  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a38bc  66890424               -mov word ptr [esp], ax
    app->getMemory<x86::reg16>(cpu.esp) = cpu.ax;
    // 004a38c0  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004a38c2  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 004a38c5  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a38c8  6689442402             -mov word ptr [esp + 2], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 004a38cd  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004a38cf  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 004a38d2  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a38d5  6689442404             -mov word ptr [esp + 4], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 004a38da  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004a38df  66894c2406             -mov word ptr [esp + 6], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(6) /* 0x6 */) = cpu.cx;
    // 004a38e4  39c2                   +cmp edx, eax
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
    // 004a38e6  7e5a                   -jle 0x4a3942
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a3942;
    }
    // 004a38e8  ba1f000000             -mov edx, 0x1f
    cpu.edx = 31 /*0x1f*/;
L_0x004a38ed:
    // 004a38ed  668b4cc4fc             -mov cx, word ptr [esp + eax*8 - 4]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 8);
    // 004a38f2  66890cc4               -mov word ptr [esp + eax*8], cx
    app->getMemory<x86::reg16>(cpu.esp + cpu.eax * 8) = cpu.cx;
    // 004a38f6  668b4cc4fa             -mov cx, word ptr [esp + eax*8 - 6]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-6) /* -0x6 */ + cpu.eax * 8);
    // 004a38fb  66894cc402             -mov word ptr [esp + eax*8 + 2], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.eax * 8) = cpu.cx;
    // 004a3900  40                     -inc eax
    (cpu.eax)++;
    // 004a3901  668b0b                 -mov cx, word ptr [ebx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebx);
    // 004a3904  66894cc4fc             -mov word ptr [esp + eax*8 - 4], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 8) = cpu.cx;
    // 004a3909  b91e000000             -mov ecx, 0x1e
    cpu.ecx = 30 /*0x1e*/;
    // 004a390e  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3911  66894cc4fe             -mov word ptr [esp + eax*8 - 2], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-2) /* -0x2 */ + cpu.eax * 8) = cpu.cx;
    // 004a3916  39f0                   +cmp eax, esi
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
    // 004a3918  7d28                   -jge 0x4a3942
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a3942;
    }
    // 004a391a  668b4cc4f8             -mov cx, word ptr [esp + eax*8 - 8]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-8) /* -0x8 */ + cpu.eax * 8);
    // 004a391f  66890cc4               -mov word ptr [esp + eax*8], cx
    app->getMemory<x86::reg16>(cpu.esp + cpu.eax * 8) = cpu.cx;
    // 004a3923  668b4cc4fc             -mov cx, word ptr [esp + eax*8 - 4]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 8);
    // 004a3928  66894cc402             -mov word ptr [esp + eax*8 + 2], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.eax * 8) = cpu.cx;
    // 004a392d  40                     -inc eax
    (cpu.eax)++;
    // 004a392e  668b0b                 -mov cx, word ptr [ebx]
    cpu.cx = app->getMemory<x86::reg16>(cpu.ebx);
    // 004a3931  66894cc4fc             -mov word ptr [esp + eax*8 - 4], cx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 8) = cpu.cx;
    // 004a3936  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3939  668954c4fe             -mov word ptr [esp + eax*8 - 2], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-2) /* -0x2 */ + cpu.eax * 8) = cpu.dx;
    // 004a393e  39f0                   +cmp eax, esi
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
    // 004a3940  7cab                   -jl 0x4a38ed
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a38ed;
    }
L_0x004a3942:
    // 004a3942  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a3943  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a3947  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3948  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a3949  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a394e  83eb08                 -sub ebx, 8
    (cpu.ebx) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a3951  ff1550145700           -call dword ptr [0x571450]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706832) /* 0x571450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3957  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a395a  29f7                   +sub edi, esi
    {
        x86::reg32& tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.esi));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a395c  0f8543ffffff           -jne 0x4a38a5
    if (!cpu.flags.zf)
    {
        goto L_0x004a38a5;
    }
L_0x004a3962:
    // 004a3962  802589135700e7         -and byte ptr [0x571389], 0xe7
    app->getMemory<x86::reg8>(x86::reg32(5706633) /* 0x571389 */) &= x86::reg8(x86::sreg8(231 /*0xe7*/));
    // 004a3969  81c400080000           +add esp, 0x800
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2048 /*0x800*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 004a396f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3970  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3971  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3972  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3973  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a3976:
    // 004a3976  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004a3978  e939ffffff             -jmp 0x4a38b6
    goto L_0x004a38b6;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a3980(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3980  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a3981  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a3982  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a3983  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a3984  81ec00080000           -sub esp, 0x800
    (cpu.esp) -= x86::reg32(x86::sreg32(2048 /*0x800*/));
    // 004a398a  8bb42414080000         -mov esi, dword ptr [esp + 0x814]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2068) /* 0x814 */);
    // 004a3991  8b9c241c080000         -mov ebx, dword ptr [esp + 0x81c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2076) /* 0x81c */);
    // 004a3998  833d44bf590000         +cmp dword ptr [0x59bf44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881668) /* 0x59bf44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a399f  741d                   -je 0x4a39be
    if (cpu.flags.zf)
    {
        goto L_0x004a39be;
    }
    // 004a39a1  833d40bf590000         +cmp dword ptr [0x59bf40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881664) /* 0x59bf40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a39a8  7419                   -je 0x4a39c3
    if (cpu.flags.zf)
    {
        goto L_0x004a39c3;
    }
    // 004a39aa  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a39ac  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a39b1  ff154c145700           -call dword ptr [0x57144c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706828) /* 0x57144c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a39b7  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a39ba  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a39bc  7505                   -jne 0x4a39c3
    if (!cpu.flags.zf)
    {
        goto L_0x004a39c3;
    }
L_0x004a39be:
    // 004a39be  e82df2ffff             -call 0x4a2bf0
    cpu.esp -= 4;
    sub_4a2bf0(app, cpu);
    if (cpu.terminate) return;
L_0x004a39c3:
    // 004a39c3  800d8913570018         -or byte ptr [0x571389], 0x18
    app->getMemory<x86::reg8>(x86::reg32(5706633) /* 0x571389 */) |= x86::reg8(x86::sreg8(24 /*0x18*/));
    // 004a39ca  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 004a39cd  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a39d0  66890424               -mov word ptr [esp], ax
    app->getMemory<x86::reg16>(cpu.esp) = cpu.ax;
    // 004a39d4  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 004a39d7  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a39da  6689442402             -mov word ptr [esp + 2], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 004a39df  8b3de4d94d00           -mov edi, dword ptr [0x4dd9e4]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5102052) /* 0x4dd9e4 */);
    // 004a39e5  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 004a39e8  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a39eb  6689442404             -mov word ptr [esp + 4], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ax;
    // 004a39f0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004a39f2  0f848c000000           -je 0x4a3a84
    if (cpu.flags.zf)
    {
        goto L_0x004a3a84;
    }
    // 004a39f8  83fe1e                 +cmp esi, 0x1e
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(30 /*0x1e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a39fb  0f8f83000000           -jg 0x4a3a84
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004a3a84;
    }
    // 004a3a01  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004a3a03  48                     -dec eax
    (cpu.eax)--;
    // 004a3a04  6689442406             -mov word ptr [esp + 6], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(6) /* 0x6 */) = cpu.ax;
L_0x004a3a09:
    // 004a3a09  83fe01                 +cmp esi, 1
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
    // 004a3a0c  7e3e                   -jle 0x4a3a4c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a3a4c;
    }
    // 004a3a0e  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 004a3a13  bf1f000000             -mov edi, 0x1f
    cpu.edi = 31 /*0x1f*/;
    // 004a3a18  8d0cf500000000         -lea ecx, [esi*8]
    cpu.ecx = x86::reg32(cpu.esi * 8);
L_0x004a3a1f:
    // 004a3a1f  668b5404f8             -mov dx, word ptr [esp + eax - 8]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-8) /* -0x8 */ + cpu.eax * 1);
    // 004a3a24  66891404               -mov word ptr [esp + eax], dx
    app->getMemory<x86::reg16>(cpu.esp + cpu.eax * 1) = cpu.dx;
    // 004a3a28  668b5404fc             -mov dx, word ptr [esp + eax - 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1);
    // 004a3a2d  6689540402             -mov word ptr [esp + eax + 2], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.eax * 1) = cpu.dx;
    // 004a3a32  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a3a35  668b13                 -mov dx, word ptr [ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx);
    // 004a3a38  66895404fc             -mov word ptr [esp + eax - 4], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-4) /* -0x4 */ + cpu.eax * 1) = cpu.dx;
    // 004a3a3d  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3a40  66897c04fe             -mov word ptr [esp + eax - 2], di
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-2) /* -0x2 */ + cpu.eax * 1) = cpu.di;
    // 004a3a45  39c8                   +cmp eax, ecx
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
    // 004a3a47  7cd6                   -jl 0x4a3a1f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a3a1f;
    }
    // 004a3a49  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x004a3a4c:
    // 004a3a4c  8bac2418080000         -mov ebp, dword ptr [esp + 0x818]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(2072) /* 0x818 */);
    // 004a3a53  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a3a54  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a3a58  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3a59  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a3a5a  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a3a5f  ff1550145700           -call dword ptr [0x571450]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706832) /* 0x571450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3a65  8a1589135700           -mov dl, byte ptr [0x571389]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5706633) /* 0x571389 */);
    // 004a3a6b  80e2e7                 -and dl, 0xe7
    cpu.dl &= x86::reg8(x86::sreg8(231 /*0xe7*/));
    // 004a3a6e  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a3a71  881589135700           -mov byte ptr [0x571389], dl
    app->getMemory<x86::reg8>(x86::reg32(5706633) /* 0x571389 */) = cpu.dl;
    // 004a3a77  81c400080000           -add esp, 0x800
    (cpu.esp) += x86::reg32(x86::sreg32(2048 /*0x800*/));
    // 004a3a7d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3a7e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3a7f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3a80  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3a81  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a3a84:
    // 004a3a84  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004a3a86  6689542406             -mov word ptr [esp + 6], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(6) /* 0x6 */) = cpu.dx;
    // 004a3a8b  e979ffffff             -jmp 0x4a3a09
    goto L_0x004a3a09;
}

/* align: skip  */
void Application::sub_4a3a90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3a90  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a3a91  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a3a92  83ec44                 -sub esp, 0x44
    (cpu.esp) -= x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004a3a95  a10c354a00             -mov eax, dword ptr [0x4a350c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(4863244) /* 0x4a350c */);
    // 004a3a9a  8b1544bf5900           -mov edx, dword ptr [0x59bf44]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5881668) /* 0x59bf44 */);
    // 004a3aa0  89442440               -mov dword ptr [esp + 0x40], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 004a3aa4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a3aa6  7459                   -je 0x4a3b01
    if (cpu.flags.zf)
    {
        goto L_0x004a3b01;
    }
    // 004a3aa8  833d40bf590000         +cmp dword ptr [0x59bf40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881664) /* 0x59bf40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3aaf  753c                   -jne 0x4a3aed
    if (!cpu.flags.zf)
    {
        goto L_0x004a3aed;
    }
L_0x004a3ab1:
    // 004a3ab1  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004a3ab6  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004a3ab8  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004a3aba  8b742450               -mov esi, dword ptr [esp + 0x50]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */);
    // 004a3abe  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3abf  8d442444               -lea eax, [esp + 0x44]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 004a3ac3  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a3ac5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3ac6  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 004a3acb  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a3acd  8d7c242c               -lea edi, [esp + 0x2c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004a3ad1  8b742460               -mov esi, dword ptr [esp + 0x60]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 004a3ad5  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a3ada  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a3adc  ff155c145700           -call dword ptr [0x57145c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706844) /* 0x57145c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3ae2  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004a3ae5  83c444                 -add esp, 0x44
    (cpu.esp) += x86::reg32(x86::sreg32(68 /*0x44*/));
    // 004a3ae8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3ae9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3aea  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a3aed:
    // 004a3aed  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a3aef  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a3af4  ff154c145700           -call dword ptr [0x57144c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706828) /* 0x57144c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3afa  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a3afd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a3aff  75b0                   -jne 0x4a3ab1
    if (!cpu.flags.zf)
    {
        goto L_0x004a3ab1;
    }
L_0x004a3b01:
    // 004a3b01  e8eaf0ffff             -call 0x4a2bf0
    cpu.esp -= 4;
    sub_4a2bf0(app, cpu);
    if (cpu.terminate) return;
    // 004a3b06  eba9                   -jmp 0x4a3ab1
    goto L_0x004a3ab1;
}

/* align: skip  */
void Application::sub_4a3b08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3b08  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a3b09  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a3b0a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a3b0b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a3b0c  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004a3b12  8bb42414040000         -mov esi, dword ptr [esp + 0x414]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1044) /* 0x414 */);
    // 004a3b19  8bac2418040000         -mov ebp, dword ptr [esp + 0x418]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1048) /* 0x418 */);
    // 004a3b20  8b9c241c040000         -mov ebx, dword ptr [esp + 0x41c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1052) /* 0x41c */);
    // 004a3b27  833d44bf590000         +cmp dword ptr [0x59bf44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881668) /* 0x59bf44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3b2e  0f8476000000           -je 0x4a3baa
    if (cpu.flags.zf)
    {
        goto L_0x004a3baa;
    }
    // 004a3b34  833d40bf590000         +cmp dword ptr [0x59bf40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881664) /* 0x59bf40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3b3b  7559                   -jne 0x4a3b96
    if (!cpu.flags.zf)
    {
        goto L_0x004a3b96;
    }
L_0x004a3b3d:
    // 004a3b3d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a3b3f  0f8470000000           -je 0x4a3bb5
    if (cpu.flags.zf)
    {
        goto L_0x004a3bb5;
    }
    // 004a3b45  81fe00010000           +cmp esi, 0x100
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3b4b  7e64                   -jle 0x4a3bb1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a3bb1;
    }
    // 004a3b4d  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
L_0x004a3b52:
    // 004a3b52  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a3b54  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a3b56  7e25                   -jle 0x4a3b7d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a3b7d;
    }
    // 004a3b58  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
    // 004a3b5f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a3b61:
    // 004a3b61  668b13                 -mov dx, word ptr [ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx);
    // 004a3b64  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3b67  66891404               -mov word ptr [esp + eax], dx
    app->getMemory<x86::reg16>(cpu.esp + cpu.eax * 1) = cpu.dx;
    // 004a3b6b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3b6e  668b13                 -mov dx, word ptr [ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx);
    // 004a3b71  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3b74  66895404fe             -mov word ptr [esp + eax - 2], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-2) /* -0x2 */ + cpu.eax * 1) = cpu.dx;
    // 004a3b79  39c8                   +cmp eax, ecx
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
    // 004a3b7b  7ce4                   -jl 0x4a3b61
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a3b61;
    }
L_0x004a3b7d:
    // 004a3b7d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a3b7e  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a3b82  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3b83  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a3b84  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a3b89  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004a3b8b  ff155c145700           -call dword ptr [0x57145c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706844) /* 0x57145c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3b91  83c410                 +add esp, 0x10
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
    // 004a3b94  eba7                   -jmp 0x4a3b3d
    goto L_0x004a3b3d;
L_0x004a3b96:
    // 004a3b96  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a3b98  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a3b9d  ff154c145700           -call dword ptr [0x57144c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706828) /* 0x57144c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3ba3  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a3ba6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a3ba8  7593                   -jne 0x4a3b3d
    if (!cpu.flags.zf)
    {
        goto L_0x004a3b3d;
    }
L_0x004a3baa:
    // 004a3baa  e841f0ffff             -call 0x4a2bf0
    cpu.esp -= 4;
    sub_4a2bf0(app, cpu);
    if (cpu.terminate) return;
    // 004a3baf  eb8c                   -jmp 0x4a3b3d
    goto L_0x004a3b3d;
L_0x004a3bb1:
    // 004a3bb1  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a3bb3  eb9d                   -jmp 0x4a3b52
    goto L_0x004a3b52;
L_0x004a3bb5:
    // 004a3bb5  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004a3bbb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3bbc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3bbd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3bbe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3bbf  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip  */
void Application::sub_4a3bb5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    goto L_entry_0x004a3bb5;
    // 004a3b08  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a3b09  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a3b0a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a3b0b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a3b0c  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004a3b12  8bb42414040000         -mov esi, dword ptr [esp + 0x414]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1044) /* 0x414 */);
    // 004a3b19  8bac2418040000         -mov ebp, dword ptr [esp + 0x418]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1048) /* 0x418 */);
    // 004a3b20  8b9c241c040000         -mov ebx, dword ptr [esp + 0x41c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1052) /* 0x41c */);
    // 004a3b27  833d44bf590000         +cmp dword ptr [0x59bf44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881668) /* 0x59bf44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3b2e  0f8476000000           -je 0x4a3baa
    if (cpu.flags.zf)
    {
        goto L_0x004a3baa;
    }
    // 004a3b34  833d40bf590000         +cmp dword ptr [0x59bf40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881664) /* 0x59bf40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3b3b  7559                   -jne 0x4a3b96
    if (!cpu.flags.zf)
    {
        goto L_0x004a3b96;
    }
L_0x004a3b3d:
    // 004a3b3d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a3b3f  0f8470000000           -je 0x4a3bb5
    if (cpu.flags.zf)
    {
        goto L_0x004a3bb5;
    }
    // 004a3b45  81fe00010000           +cmp esi, 0x100
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3b4b  7e64                   -jle 0x4a3bb1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a3bb1;
    }
    // 004a3b4d  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
L_0x004a3b52:
    // 004a3b52  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a3b54  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a3b56  7e25                   -jle 0x4a3b7d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a3b7d;
    }
    // 004a3b58  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
    // 004a3b5f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a3b61:
    // 004a3b61  668b13                 -mov dx, word ptr [ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx);
    // 004a3b64  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3b67  66891404               -mov word ptr [esp + eax], dx
    app->getMemory<x86::reg16>(cpu.esp + cpu.eax * 1) = cpu.dx;
    // 004a3b6b  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3b6e  668b13                 -mov dx, word ptr [ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx);
    // 004a3b71  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3b74  66895404fe             -mov word ptr [esp + eax - 2], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-2) /* -0x2 */ + cpu.eax * 1) = cpu.dx;
    // 004a3b79  39c8                   +cmp eax, ecx
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
    // 004a3b7b  7ce4                   -jl 0x4a3b61
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a3b61;
    }
L_0x004a3b7d:
    // 004a3b7d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a3b7e  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a3b82  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3b83  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a3b84  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a3b89  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004a3b8b  ff155c145700           -call dword ptr [0x57145c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706844) /* 0x57145c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3b91  83c410                 +add esp, 0x10
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
    // 004a3b94  eba7                   -jmp 0x4a3b3d
    goto L_0x004a3b3d;
L_0x004a3b96:
    // 004a3b96  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a3b98  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a3b9d  ff154c145700           -call dword ptr [0x57144c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706828) /* 0x57144c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3ba3  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a3ba6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a3ba8  7593                   -jne 0x4a3b3d
    if (!cpu.flags.zf)
    {
        goto L_0x004a3b3d;
    }
L_0x004a3baa:
    // 004a3baa  e841f0ffff             -call 0x4a2bf0
    cpu.esp -= 4;
    sub_4a2bf0(app, cpu);
    if (cpu.terminate) return;
    // 004a3baf  eb8c                   -jmp 0x4a3b3d
    goto L_0x004a3b3d;
L_0x004a3bb1:
    // 004a3bb1  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a3bb3  eb9d                   -jmp 0x4a3b52
    goto L_0x004a3b52;
L_0x004a3bb5:
L_entry_0x004a3bb5:
    // 004a3bb5  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004a3bbb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3bbc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3bbd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3bbe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3bbf  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a3bc4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3bc4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a3bc5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a3bc6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a3bc7  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a3bc8  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 004a3bce  8bb42414040000         -mov esi, dword ptr [esp + 0x414]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1044) /* 0x414 */);
    // 004a3bd5  8bac2418040000         -mov ebp, dword ptr [esp + 0x418]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1048) /* 0x418 */);
    // 004a3bdc  8b9c241c040000         -mov ebx, dword ptr [esp + 0x41c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(1052) /* 0x41c */);
    // 004a3be3  833d44bf590000         +cmp dword ptr [0x59bf44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881668) /* 0x59bf44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3bea  0f8499000000           -je 0x4a3c89
    if (cpu.flags.zf)
    {
        goto L_0x004a3c89;
    }
    // 004a3bf0  833d40bf590000         +cmp dword ptr [0x59bf40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881664) /* 0x59bf40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3bf7  0f8574000000           -jne 0x4a3c71
    if (!cpu.flags.zf)
    {
        goto L_0x004a3c71;
    }
L_0x004a3bfd:
    // 004a3bfd  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a3bff  74b4                   -je 0x4a3bb5
    if (cpu.flags.zf)
    {
        return sub_4a3bb5(app, cpu);
    }
    // 004a3c01  81fe00010000           +cmp esi, 0x100
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(256 /*0x100*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3c07  0f8e86000000           -jle 0x4a3c93
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a3c93;
    }
    // 004a3c0d  ba00010000             -mov edx, 0x100
    cpu.edx = 256 /*0x100*/;
L_0x004a3c12:
    // 004a3c12  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 004a3c15  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3c18  66890424               -mov word ptr [esp], ax
    app->getMemory<x86::reg16>(cpu.esp) = cpu.ax;
    // 004a3c1c  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004a3c1e  668b03                 -mov ax, word ptr [ebx]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx);
    // 004a3c21  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3c24  6689442402             -mov word ptr [esp + 2], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 004a3c29  83fa01                 +cmp edx, 1
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
    // 004a3c2c  7e27                   -jle 0x4a3c55
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004a3c55;
    }
    // 004a3c2e  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004a3c33  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
L_0x004a3c3a:
    // 004a3c3a  668b5404fe             -mov dx, word ptr [esp + eax - 2]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-2) /* -0x2 */ + cpu.eax * 1);
    // 004a3c3f  66891404               -mov word ptr [esp + eax], dx
    app->getMemory<x86::reg16>(cpu.esp + cpu.eax * 1) = cpu.dx;
    // 004a3c43  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3c46  668b13                 -mov dx, word ptr [ebx]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ebx);
    // 004a3c49  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3c4c  66895404fe             -mov word ptr [esp + eax - 2], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(-2) /* -0x2 */ + cpu.eax * 1) = cpu.dx;
    // 004a3c51  39c8                   +cmp eax, ecx
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
    // 004a3c53  7ce5                   -jl 0x4a3c3a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a3c3a;
    }
L_0x004a3c55:
    // 004a3c55  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a3c56  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004a3c5a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3c5b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a3c5c  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a3c61  83eb04                 -sub ebx, 4
    (cpu.ebx) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3c64  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004a3c66  ff155c145700           -call dword ptr [0x57145c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706844) /* 0x57145c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3c6c  83c410                 +add esp, 0x10
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
    // 004a3c6f  eb8c                   -jmp 0x4a3bfd
    goto L_0x004a3bfd;
L_0x004a3c71:
    // 004a3c71  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a3c73  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a3c78  ff154c145700           -call dword ptr [0x57144c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706828) /* 0x57144c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3c7e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a3c81  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a3c83  0f8574ffffff           -jne 0x4a3bfd
    if (!cpu.flags.zf)
    {
        goto L_0x004a3bfd;
    }
L_0x004a3c89:
    // 004a3c89  e862efffff             -call 0x4a2bf0
    cpu.esp -= 4;
    sub_4a2bf0(app, cpu);
    if (cpu.terminate) return;
    // 004a3c8e  e96affffff             -jmp 0x4a3bfd
    goto L_0x004a3bfd;
L_0x004a3c93:
    // 004a3c93  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 004a3c95  e978ffffff             -jmp 0x4a3c12
    goto L_0x004a3c12;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a3c9c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3c9c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a3c9d  833d44bf590000         +cmp dword ptr [0x59bf44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881668) /* 0x59bf44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3ca4  7436                   -je 0x4a3cdc
    if (cpu.flags.zf)
    {
        goto L_0x004a3cdc;
    }
    // 004a3ca6  833d40bf590000         +cmp dword ptr [0x59bf40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881664) /* 0x59bf40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3cad  7519                   -jne 0x4a3cc8
    if (!cpu.flags.zf)
    {
        goto L_0x004a3cc8;
    }
L_0x004a3caf:
    // 004a3caf  8b5c2408               -mov ebx, dword ptr [esp + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004a3cb3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a3cb4  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a3cb6  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a3cbb  ff1558145700           -call dword ptr [0x571458]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706840) /* 0x571458 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3cc1  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a3cc4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3cc5  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004a3cc8:
    // 004a3cc8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a3cca  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a3ccf  ff154c145700           -call dword ptr [0x57144c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706828) /* 0x57144c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3cd5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a3cd8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a3cda  75d3                   -jne 0x4a3caf
    if (!cpu.flags.zf)
    {
        goto L_0x004a3caf;
    }
L_0x004a3cdc:
    // 004a3cdc  e80fefffff             -call 0x4a2bf0
    cpu.esp -= 4;
    sub_4a2bf0(app, cpu);
    if (cpu.terminate) return;
    // 004a3ce1  ebcc                   -jmp 0x4a3caf
    goto L_0x004a3caf;
}

/* align: skip 0x90 */
void Application::sub_4a3ce4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3ce4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a3ce5  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a3ce6  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a3ce7  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a3ceb  8b7c2414               -mov edi, dword ptr [esp + 0x14]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 004a3cef  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004a3cf3  833d44bf590000         +cmp dword ptr [0x59bf44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881668) /* 0x59bf44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3cfa  7429                   -je 0x4a3d25
    if (cpu.flags.zf)
    {
        goto L_0x004a3d25;
    }
    // 004a3cfc  833d40bf590000         +cmp dword ptr [0x59bf40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881664) /* 0x59bf40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3d03  750c                   -jne 0x4a3d11
    if (!cpu.flags.zf)
    {
        goto L_0x004a3d11;
    }
L_0x004a3d05:
    // 004a3d05  4e                     -dec esi
    (cpu.esi)--;
    // 004a3d06  83feff                 +cmp esi, -1
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
    // 004a3d09  752b                   -jne 0x4a3d36
    if (!cpu.flags.zf)
    {
        goto L_0x004a3d36;
    }
    // 004a3d0b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3d0c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3d0d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3d0e  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a3d11:
    // 004a3d11  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a3d13  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a3d18  ff154c145700           -call dword ptr [0x57144c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706828) /* 0x57144c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3d1e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a3d21  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a3d23  75e0                   -jne 0x4a3d05
    if (!cpu.flags.zf)
    {
        goto L_0x004a3d05;
    }
L_0x004a3d25:
    // 004a3d25  e8c6eeffff             -call 0x4a2bf0
    cpu.esp -= 4;
    sub_4a2bf0(app, cpu);
    if (cpu.terminate) return;
    // 004a3d2a  4e                     -dec esi
    (cpu.esi)--;
    // 004a3d2b  83feff                 +cmp esi, -1
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
    // 004a3d2e  7506                   -jne 0x4a3d36
    if (!cpu.flags.zf)
    {
        goto L_0x004a3d36;
    }
    // 004a3d30  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3d31  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3d32  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3d33  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
L_0x004a3d36:
    // 004a3d36  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004a3d38  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 004a3d3b  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 004a3d3d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004a3d3e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004a3d40  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a3d45  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3d48  ff1558145700           -call dword ptr [0x571458]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706840) /* 0x571458 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3d4e  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a3d51  4e                     -dec esi
    (cpu.esi)--;
    // 004a3d52  83feff                 +cmp esi, -1
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
    // 004a3d55  75df                   -jne 0x4a3d36
    if (!cpu.flags.zf)
    {
        goto L_0x004a3d36;
    }
    // 004a3d57  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3d58  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3d59  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3d5a  c20c00                 -ret 0xc
    cpu.esp += 4+12 /*0xc*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a3d60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3d60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a3d61  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a3d62  833d44bf590000         +cmp dword ptr [0x59bf44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881668) /* 0x59bf44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3d69  743a                   -je 0x4a3da5
    if (cpu.flags.zf)
    {
        goto L_0x004a3da5;
    }
    // 004a3d6b  833d40bf590000         +cmp dword ptr [0x59bf40], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881664) /* 0x59bf40 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3d72  751d                   -jne 0x4a3d91
    if (!cpu.flags.zf)
    {
        goto L_0x004a3d91;
    }
L_0x004a3d74:
    // 004a3d74  8b5c2410               -mov ebx, dword ptr [esp + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a3d78  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a3d79  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004a3d7d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a3d7e  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a3d83  ff1558145700           -call dword ptr [0x571458]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706840) /* 0x571458 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3d89  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 004a3d8c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3d8d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3d8e  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x004a3d91:
    // 004a3d91  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004a3d93  6870135700             -push 0x571370
    app->getMemory<x86::reg32>(cpu.esp-4) = 5706608 /*0x571370*/;
    cpu.esp -= 4;
    // 004a3d98  ff154c145700           -call dword ptr [0x57144c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5706828) /* 0x57144c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3d9e  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004a3da1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a3da3  75cf                   -jne 0x4a3d74
    if (!cpu.flags.zf)
    {
        goto L_0x004a3d74;
    }
L_0x004a3da5:
    // 004a3da5  e846eeffff             -call 0x4a2bf0
    cpu.esp -= 4;
    sub_4a2bf0(app, cpu);
    if (cpu.terminate) return;
    // 004a3daa  ebc8                   -jmp 0x4a3d74
    goto L_0x004a3d74;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_4a3db0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3db0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a3db1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a3db2  2eff1524654c00         -call dword ptr cs:[0x4c6524]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(5006628) /* 0x4c6524 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3db9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3dba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3dbb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a3dbc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3dbc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a3dbd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a3dbe  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a3dbf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a3dc0  e84760feff             -call 0x489e0c
    cpu.esp -= 4;
    sub_489e0c(app, cpu);
    if (cpu.terminate) return;
    // 004a3dc5  8b1594bf5900           -mov edx, dword ptr [0x59bf94]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5881748) /* 0x59bf94 */);
    // 004a3dcb  a370da4d00             -mov dword ptr [0x4dda70], eax
    app->getMemory<x86::reg32>(x86::reg32(5102192) /* 0x4dda70 */) = cpu.eax;
    // 004a3dd0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a3dd2  7453                   -je 0x4a3e27
    if (cpu.flags.zf)
    {
        goto L_0x004a3e27;
    }
L_0x004a3dd4:
    // 004a3dd4  a170da4d00             -mov eax, dword ptr [0x4dda70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102192) /* 0x4dda70 */);
    // 004a3dd9  e87e60feff             -call 0x489e5c
    cpu.esp -= 4;
    sub_489e5c(app, cpu);
    if (cpu.terminate) return;
    // 004a3dde  8b1d94bf5900           -mov ebx, dword ptr [0x59bf94]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5881748) /* 0x59bf94 */);
    // 004a3de4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004a3de6  7436                   -je 0x4a3e1e
    if (cpu.flags.zf)
    {
        goto L_0x004a3e1e;
    }
    // 004a3de8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004a3dea  e85961feff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004a3def  8b3560bf5900           -mov esi, dword ptr [0x59bf60]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5881696) /* 0x59bf60 */);
    // 004a3df5  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a3df7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004a3df9  7419                   -je 0x4a3e14
    if (cpu.flags.zf)
    {
        goto L_0x004a3e14;
    }
L_0x004a3dfb:
    // 004a3dfb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a3dfd  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3e00  ff9060bf5900           -call dword ptr [eax + 0x59bf60]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5881696) /* 0x59bf60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004a3e06  83fa20                 +cmp edx, 0x20
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
    // 004a3e09  7d09                   -jge 0x4a3e14
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a3e14;
    }
    // 004a3e0b  83ba60bf590000         +cmp dword ptr [edx + 0x59bf60], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5881696) /* 0x59bf60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3e12  75e7                   -jne 0x4a3dfb
    if (!cpu.flags.zf)
    {
        goto L_0x004a3dfb;
    }
L_0x004a3e14:
    // 004a3e14  a194bf5900             -mov eax, dword ptr [0x59bf94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5881748) /* 0x59bf94 */);
    // 004a3e19  e84261feff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
L_0x004a3e1e:
    // 004a3e1e  833d94bf590000         +cmp dword ptr [0x59bf94], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881748) /* 0x59bf94 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3e25  75ad                   -jne 0x4a3dd4
    if (!cpu.flags.zf)
    {
        goto L_0x004a3dd4;
    }
L_0x004a3e27:
    // 004a3e27  a170da4d00             -mov eax, dword ptr [0x4dda70]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5102192) /* 0x4dda70 */);
    // 004a3e2c  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a3e2e  e8b560feff             -call 0x489ee8
    cpu.esp -= 4;
    sub_489ee8(app, cpu);
    if (cpu.terminate) return;
    // 004a3e33  892d70da4d00           -mov dword ptr [0x4dda70], ebp
    app->getMemory<x86::reg32>(x86::reg32(5102192) /* 0x4dda70 */) = cpu.ebp;
    // 004a3e39  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3e3a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3e3b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3e3c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3e3d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4a3e40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3e40  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a3e41  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a3e42  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a3e43  8b1594bf5900           -mov edx, dword ptr [0x59bf94]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5881748) /* 0x59bf94 */);
    // 004a3e49  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a3e4b  7504                   -jne 0x4a3e51
    if (!cpu.flags.zf)
    {
        goto L_0x004a3e51;
    }
L_0x004a3e4d:
    // 004a3e4d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3e4e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3e4f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3e50  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a3e51:
    // 004a3e51  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a3e53  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004a3e55  e8ee60feff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004a3e5a  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004a3e5c  b880bf5900             -mov eax, 0x59bf80
    cpu.eax = 5881728 /*0x59bf80*/;
    // 004a3e61  8b1570da4d00           -mov edx, dword ptr [0x4dda70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5102192) /* 0x4dda70 */);
    // 004a3e67  891d94bf5900           -mov dword ptr [0x59bf94], ebx
    app->getMemory<x86::reg32>(x86::reg32(5881748) /* 0x59bf94 */) = cpu.ebx;
    // 004a3e6d  e8ae5ffeff             -call 0x489e20
    cpu.esp -= 4;
    sub_489e20(app, cpu);
    if (cpu.terminate) return;
    // 004a3e72  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a3e74  e8e760feff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004a3e79  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004a3e7b  e8f460feff             -call 0x489f74
    cpu.esp -= 4;
    sub_489f74(app, cpu);
    if (cpu.terminate) return;
    // 004a3e80  b880bf5900             -mov eax, 0x59bf80
    cpu.eax = 5881728 /*0x59bf80*/;
    // 004a3e85  e85e5dfeff             -call 0x489be8
    cpu.esp -= 4;
    sub_489be8(app, cpu);
    if (cpu.terminate) return;
    // 004a3e8a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a3e8c  75bf                   -jne 0x4a3e4d
    if (!cpu.flags.zf)
    {
        goto L_0x004a3e4d;
    }
    // 004a3e8e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004a3e90:
    // 004a3e90  3b1570da4d00           +cmp edx, dword ptr [0x4dda70]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5102192) /* 0x4dda70 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3e96  74b5                   -je 0x4a3e4d
    if (cpu.flags.zf)
    {
        goto L_0x004a3e4d;
    }
    // 004a3e98  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a3e9a  e8fd5cfeff             -call 0x489b9c
    cpu.esp -= 4;
    sub_489b9c(app, cpu);
    if (cpu.terminate) return;
    // 004a3e9f  ebef                   -jmp 0x4a3e90
    goto L_0x004a3e90;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a3ea4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3ea4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a3ea5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a3ea6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a3ea7  b8403e4a00             -mov eax, 0x4a3e40
    cpu.eax = 4865600 /*0x4a3e40*/;
    // 004a3eac  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004a3eb1  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 004a3eb6  e8e56effff             -call 0x49ada0
    cpu.esp -= 4;
    sub_49ada0(app, cpu);
    if (cpu.terminate) return;
    // 004a3ebb  e83860feff             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 004a3ec0  a394bf5900             -mov dword ptr [0x59bf94], eax
    app->getMemory<x86::reg32>(x86::reg32(5881748) /* 0x59bf94 */) = cpu.eax;
    // 004a3ec5  e87e60feff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004a3eca  6880bf5900             -push 0x59bf80
    app->getMemory<x86::reg32>(cpu.esp-4) = 5881728 /*0x59bf80*/;
    cpu.esp -= 4;
    // 004a3ecf  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a3ed1  b8bc3d4a00             -mov eax, 0x4a3dbc
    cpu.eax = 4865468 /*0x4a3dbc*/;
    // 004a3ed6  e8055cfeff             -call 0x489ae0
    cpu.esp -= 4;
    sub_489ae0(app, cpu);
    if (cpu.terminate) return;
    // 004a3edb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004a3edd  7516                   -jne 0x4a3ef5
    if (!cpu.flags.zf)
    {
        goto L_0x004a3ef5;
    }
    // 004a3edf  a194bf5900             -mov eax, dword ptr [0x59bf94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5881748) /* 0x59bf94 */);
    // 004a3ee4  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a3ee6  e88960feff             -call 0x489f74
    cpu.esp -= 4;
    sub_489f74(app, cpu);
    if (cpu.terminate) return;
    // 004a3eeb  891594bf5900           -mov dword ptr [0x59bf94], edx
    app->getMemory<x86::reg32>(x86::reg32(5881748) /* 0x59bf94 */) = cpu.edx;
    // 004a3ef1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3ef2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3ef3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3ef4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a3ef5:
    // 004a3ef5  a194bf5900             -mov eax, dword ptr [0x59bf94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5881748) /* 0x59bf94 */);
    // 004a3efa  e86160feff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004a3eff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3f00  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3f01  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3f02  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a3f04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3f04  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a3f05  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a3f06  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a3f07  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004a3f09  8b1594bf5900           -mov edx, dword ptr [0x59bf94]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5881748) /* 0x59bf94 */);
    // 004a3f0f  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 004a3f14  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a3f16  7446                   -je 0x4a3f5e
    if (cpu.flags.zf)
    {
        goto L_0x004a3f5e;
    }
L_0x004a3f18:
    // 004a3f18  a194bf5900             -mov eax, dword ptr [0x59bf94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5881748) /* 0x59bf94 */);
    // 004a3f1d  e82660feff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004a3f22  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a3f24  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x004a3f26:
    // 004a3f26  83ba60bf590000         +cmp dword ptr [edx + 0x59bf60], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5881696) /* 0x59bf60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3f2d  7504                   -jne 0x4a3f33
    if (!cpu.flags.zf)
    {
        goto L_0x004a3f33;
    }
    // 004a3f2f  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004a3f31  7c32                   -jl 0x4a3f65
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a3f65;
    }
L_0x004a3f33:
    // 004a3f33  3b9a60bf5900           +cmp ebx, dword ptr [edx + 0x59bf60]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5881696) /* 0x59bf60 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3f39  7415                   -je 0x4a3f50
    if (cpu.flags.zf)
    {
        goto L_0x004a3f50;
    }
L_0x004a3f3b:
    // 004a3f3b  40                     -inc eax
    (cpu.eax)++;
    // 004a3f3c  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3f3f  83f808                 +cmp eax, 8
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
    // 004a3f42  7ce2                   -jl 0x4a3f26
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a3f26;
    }
    // 004a3f44  83f9ff                 +cmp ecx, -1
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
    // 004a3f47  7407                   -je 0x4a3f50
    if (cpu.flags.zf)
    {
        goto L_0x004a3f50;
    }
    // 004a3f49  891c8d60bf5900         -mov dword ptr [ecx*4 + 0x59bf60], ebx
    app->getMemory<x86::reg32>(x86::reg32(5881696) /* 0x59bf60 */ + cpu.ecx * 4) = cpu.ebx;
L_0x004a3f50:
    // 004a3f50  a194bf5900             -mov eax, dword ptr [0x59bf94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5881748) /* 0x59bf94 */);
    // 004a3f55  e80660feff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004a3f5a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3f5b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3f5c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3f5d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a3f5e:
    // 004a3f5e  e841ffffff             -call 0x4a3ea4
    cpu.esp -= 4;
    sub_4a3ea4(app, cpu);
    if (cpu.terminate) return;
    // 004a3f63  ebb3                   -jmp 0x4a3f18
    goto L_0x004a3f18;
L_0x004a3f65:
    // 004a3f65  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a3f67  ebd2                   -jmp 0x4a3f3b
    goto L_0x004a3f3b;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a3f6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a3f6c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a3f6d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a3f6e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a3f6f  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004a3f70  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004a3f72  8b1594bf5900           -mov edx, dword ptr [0x59bf94]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5881748) /* 0x59bf94 */);
    // 004a3f78  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a3f7a  7505                   -jne 0x4a3f81
    if (!cpu.flags.zf)
    {
        goto L_0x004a3f81;
    }
L_0x004a3f7c:
    // 004a3f7c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3f7d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3f7e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3f7f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a3f80  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a3f81:
    // 004a3f81  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004a3f83  e8c05ffeff             -call 0x489f48
    cpu.esp -= 4;
    sub_489f48(app, cpu);
    if (cpu.terminate) return;
    // 004a3f88  8b1d60bf5900           -mov ebx, dword ptr [0x59bf60]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5881696) /* 0x59bf60 */);
    // 004a3f8e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004a3f90  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a3f92  39d9                   +cmp ecx, ebx
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
    // 004a3f94  7411                   -je 0x4a3fa7
    if (cpu.flags.zf)
    {
        goto L_0x004a3fa7;
    }
L_0x004a3f96:
    // 004a3f96  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3f99  42                     -inc edx
    (cpu.edx)++;
    // 004a3f9a  83f820                 +cmp eax, 0x20
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
    // 004a3f9d  7d08                   -jge 0x4a3fa7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a3fa7;
    }
    // 004a3f9f  3b8860bf5900           +cmp ecx, dword ptr [eax + 0x59bf60]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5881696) /* 0x59bf60 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3fa5  75ef                   -jne 0x4a3f96
    if (!cpu.flags.zf)
    {
        goto L_0x004a3f96;
    }
L_0x004a3fa7:
    // 004a3fa7  83fa08                 +cmp edx, 8
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
    // 004a3faa  7d30                   -jge 0x4a3fdc
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a3fdc;
    }
    // 004a3fac  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004a3fb3  3b8860bf5900           +cmp ecx, dword ptr [eax + 0x59bf60]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5881696) /* 0x59bf60 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a3fb9  7521                   -jne 0x4a3fdc
    if (!cpu.flags.zf)
    {
        goto L_0x004a3fdc;
    }
    // 004a3fbb  83fa07                 +cmp edx, 7
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
    // 004a3fbe  7d14                   -jge 0x4a3fd4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a3fd4;
    }
L_0x004a3fc0:
    // 004a3fc0  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3fc3  8b9060bf5900           -mov edx, dword ptr [eax + 0x59bf60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5881696) /* 0x59bf60 */);
    // 004a3fc9  89905cbf5900           -mov dword ptr [eax + 0x59bf5c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5881692) /* 0x59bf5c */) = cpu.edx;
    // 004a3fcf  83f81c                 +cmp eax, 0x1c
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
    // 004a3fd2  7cec                   -jl 0x4a3fc0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004a3fc0;
    }
L_0x004a3fd4:
    // 004a3fd4  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004a3fd6  892d7cbf5900           -mov dword ptr [0x59bf7c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5881724) /* 0x59bf7c */) = cpu.ebp;
L_0x004a3fdc:
    // 004a3fdc  a194bf5900             -mov eax, dword ptr [0x59bf94]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5881748) /* 0x59bf94 */);
    // 004a3fe1  e87a5ffeff             -call 0x489f60
    cpu.esp -= 4;
    sub_489f60(app, cpu);
    if (cpu.terminate) return;
    // 004a3fe6  8b1560bf5900           -mov edx, dword ptr [0x59bf60]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5881696) /* 0x59bf60 */);
    // 004a3fec  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004a3fee  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
L_0x004a3ff0:
    // 004a3ff0  758a                   -jne 0x4a3f7c
    if (!cpu.flags.zf)
    {
        goto L_0x004a3f7c;
    }
    // 004a3ff2  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004a3ff5  83f820                 +cmp eax, 0x20
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
    // 004a3ff8  7d09                   -jge 0x4a4003
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004a4003;
    }
    // 004a3ffa  83b860bf590000         +cmp dword ptr [eax + 0x59bf60], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5881696) /* 0x59bf60 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a4001  ebed                   -jmp 0x4a3ff0
    goto L_0x004a3ff0;
L_0x004a4003:
    // 004a4003  e838feffff             -call 0x4a3e40
    cpu.esp -= 4;
    sub_4a3e40(app, cpu);
    if (cpu.terminate) return;
    // 004a4008  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4009  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a400a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a400b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a400c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4a4010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4010  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004a4011  8b1570da4d00           -mov edx, dword ptr [0x4dda70]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5102192) /* 0x4dda70 */);
    // 004a4017  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004a4019  7502                   -jne 0x4a401d
    if (!cpu.flags.zf)
    {
        goto L_0x004a401d;
    }
    // 004a401b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a401c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a401d:
    // 004a401d  b880bf5900             -mov eax, 0x59bf80
    cpu.eax = 5881728 /*0x59bf80*/;
    // 004a4022  e8f95dfeff             -call 0x489e20
    cpu.esp -= 4;
    sub_489e20(app, cpu);
    if (cpu.terminate) return;
    // 004a4027  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4028  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a4030(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4030  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a4031  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a4032  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a4033  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004a4038  be40b24d00             -mov esi, 0x4db240
    cpu.esi = 5091904 /*0x4db240*/;
    // 004a403d  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004a403f  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a4041  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004a4046  be78b24d00             -mov esi, 0x4db278
    cpu.esi = 5091960 /*0x4db278*/;
    // 004a404b  8d7838                 -lea edi, [eax + 0x38]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(56) /* 0x38 */);
    // 004a404e  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a4050  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4051  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4052  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4053  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a4054(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4054  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a4055  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a4056  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004a4057  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a4059  b90e000000             -mov ecx, 0xe
    cpu.ecx = 14 /*0xe*/;
    // 004a405e  bf78b24d00             -mov edi, 0x4db278
    cpu.edi = 5091960 /*0x4db278*/;
    // 004a4063  e834e5fdff             -call 0x48259c
    cpu.esp -= 4;
    sub_48259c(app, cpu);
    if (cpu.terminate) return;
    // 004a4068  8d7638                 -lea esi, [esi + 0x38]
    cpu.esi = x86::reg32(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 004a406b  f3a5                   -rep movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004a406d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a406e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a406f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4070  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a4071(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4071  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004a4072  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a4073  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004a4075  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004a4077  8d4a01                 -lea ecx, [edx + 1]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 004a407a  8908                   -mov dword ptr [eax], ecx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.ecx;
    // 004a407c  881a                   -mov byte ptr [edx], bl
    app->getMemory<x86::reg8>(cpu.edx) = cpu.bl;
    // 004a407e  ff4010                 -inc dword ptr [eax + 0x10]
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */))++;
    // 004a4081  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4082  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4083  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4a4084(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a4084  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004a4085  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004a4086  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004a4088  b971404a00             -mov ecx, 0x4a4071
    cpu.ecx = 4866161 /*0x4a4071*/;
    // 004a408d  e866f10000             -call 0x4b31f8
    cpu.esp -= 4;
    sub_4b31f8(app, cpu);
    if (cpu.terminate) return;
    // 004a4092  c6040600               -mov byte ptr [esi + eax], 0
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 0 /*0x0*/;
    // 004a4096  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4097  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004a4098  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4a40a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a40a0  833d98bf590000         +cmp dword ptr [0x59bf98], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5881752) /* 0x59bf98 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004a40a7  7406                   -je 0x4a40af
    if (cpu.flags.zf)
    {
        goto L_0x004a40af;
    }
    // 004a40a9  b898bf5900             -mov eax, 0x59bf98
    cpu.eax = 5881752 /*0x59bf98*/;
    // 004a40ae  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004a40af:
    // 004a40af  e8445efeff             -call 0x489ef8
    cpu.esp -= 4;
    sub_489ef8(app, cpu);
    if (cpu.terminate) return;
    // 004a40b4  a398bf5900             -mov dword ptr [0x59bf98], eax
    app->getMemory<x86::reg32>(x86::reg32(5881752) /* 0x59bf98 */) = cpu.eax;
    // 004a40b9  b898bf5900             -mov eax, 0x59bf98
    cpu.eax = 5881752 /*0x59bf98*/;
    // 004a40be  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4a40c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004a40c0  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004a40c2  e9815efeff             -jmp 0x489f48
    return sub_489f48(app, cpu);
}

}
