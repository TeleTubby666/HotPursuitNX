#include "nfs2se.h"
#include <lib/thread.h>

namespace nfs2se
{

/* align: skip 0x8b 0xc0 */
void Application::sub_488718(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488718  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488719  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048871a  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048871d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048871f  7505                   -jne 0x488726
    if (!cpu.flags.zf)
    {
        goto L_0x00488726;
    }
    // 00488721  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
L_0x00488726:
    // 00488726  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00488728  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048872a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048872b  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 0048872d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048872e  ff5144                 -call dword ptr [ecx + 0x44]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(68) /* 0x44 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488731  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00488734  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488737  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488738  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488739  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48873c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048873c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048873d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048873f  7505                   -jne 0x488746
    if (!cpu.flags.zf)
    {
        goto L_0x00488746;
    }
    // 00488741  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
L_0x00488746:
    // 00488746  83fa02                 +cmp edx, 2
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
    // 00488749  7512                   -jne 0x48875d
    if (!cpu.flags.zf)
    {
        goto L_0x0048875d;
    }
    // 0048874b  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00488750  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00488752  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00488754  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488755  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00488757  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488758  ff5158                 -call dword ptr [ecx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048875b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048875c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048875d:
    // 0048875d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00488762  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00488764  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00488766  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488767  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00488769  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048876a  ff5158                 -call dword ptr [ecx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048876d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048876e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_488770(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488770  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488771  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00488773  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488775  7505                   -jne 0x48877c
    if (!cpu.flags.zf)
    {
        goto L_0x0048877c;
    }
    // 00488777  bb70d35100             -mov ebx, 0x51d370
    cpu.ebx = 5362544 /*0x51d370*/;
L_0x0048877c:
    // 0048877c  837b2400               +cmp dword ptr [ebx + 0x24], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488780  0f8476000000           -je 0x4887fc
    if (cpu.flags.zf)
    {
        goto L_0x004887fc;
    }
    // 00488786  837b1c08               +cmp dword ptr [ebx + 0x1c], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048878a  7f70                   -jg 0x4887fc
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x004887fc;
    }
    // 0048878c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048878d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048878e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048878f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488790  8b832e040000           -mov eax, dword ptr [ebx + 0x42e]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1070) /* 0x42e */);
    // 00488796  8b9330040000           -mov edx, dword ptr [ebx + 0x430]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1072) /* 0x430 */);
    // 0048879c  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0048879f  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 004887a2  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004887a4  42                     -inc edx
    (cpu.edx)++;
    // 004887a5  3d00010000             +cmp eax, 0x100
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
    // 004887aa  7d3a                   -jge 0x4887e6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004887e6;
    }
    // 004887ac  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004887ae  7e36                   -jle 0x4887e6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004887e6;
    }
    // 004887b0  8d348500000000         -lea esi, [eax*4]
    cpu.esi = x86::reg32(cpu.eax * 4);
    // 004887b7  8d4b30                 -lea ecx, [ebx + 0x30]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(48) /* 0x30 */);
    // 004887ba  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004887bc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004887bd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004887be  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004887bf  8b4b24                 -mov ecx, dword ptr [ebx + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 004887c2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004887c4  8b39                   -mov edi, dword ptr [ecx]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx);
    // 004887c6  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004887c7  ff5718                 -call dword ptr [edi + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004887ca  80bb5d04000000         +cmp byte ptr [ebx + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004887d1  7513                   -jne 0x4887e6
    if (!cpu.flags.zf)
    {
        goto L_0x004887e6;
    }
    // 004887d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004887d4  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 004887d9  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004887db  8b4324                 -mov eax, dword ptr [ebx + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(36) /* 0x24 */);
    // 004887de  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004887e0  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 004887e2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004887e3  ff5210                 -call dword ptr [edx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004887e6:
    // 004887e6  66c783300400000001     -mov word ptr [ebx + 0x430], 0x100
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(1072) /* 0x430 */) = 256 /*0x100*/;
    // 004887ef  66c78332040000ffff     -mov word ptr [ebx + 0x432], 0xffff
    app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(1074) /* 0x432 */) = 65535 /*0xffff*/;
    // 004887f8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004887f9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004887fa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004887fb  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004887fc:
    // 004887fc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004887fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_488800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488800  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488801  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488802  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00488803  81ec00040000           -sub esp, 0x400
    (cpu.esp) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00488809  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0048880b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048880d  7505                   -jne 0x488814
    if (!cpu.flags.zf)
    {
        goto L_0x00488814;
    }
    // 0048880f  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
L_0x00488814:
    // 00488814  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 00488817  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00488819  7454                   -je 0x48886f
    if (cpu.flags.zf)
    {
        goto L_0x0048886f;
    }
    // 0048881b  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0048881d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048881e  6800010000             -push 0x100
    app->getMemory<x86::reg32>(cpu.esp-4) = 256 /*0x100*/;
    cpu.esp -= 4;
    // 00488823  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00488825  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00488827  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00488829  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048882b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048882c  ff5210                 -call dword ptr [edx + 0x10]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048882f  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 00488831  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00488833:
    // 00488833  0fb63484               -movzx esi, byte ptr [esp + eax*4]
    cpu.esi = x86::reg32(app->getMemory<x86::reg8>(cpu.esp + cpu.eax * 4));
    // 00488837  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488839  c1e610                 -shl esi, 0x10
    cpu.esi <<= 16 /*0x10*/ % 32;
    // 0048883c  8a5c8401               -mov bl, byte ptr [esp + eax*4 + 1]
    cpu.bl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(1) /* 0x1 */ + cpu.eax * 4);
    // 00488840  81ce000000ff           -or esi, 0xff000000
    cpu.esi |= x86::reg32(x86::sreg32(4278190080 /*0xff000000*/));
    // 00488846  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 00488849  8a548402               -mov dl, byte ptr [esp + eax*4 + 2]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(2) /* 0x2 */ + cpu.eax * 4);
    // 0048884d  09de                   -or esi, ebx
    cpu.esi |= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048884f  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00488855  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488858  09f2                   -or edx, esi
    cpu.edx |= x86::reg32(x86::sreg32(cpu.esi));
    // 0048885a  40                     -inc eax
    (cpu.eax)++;
    // 0048885b  8951fc                 -mov dword ptr [ecx - 4], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 0048885e  3d00010000             +cmp eax, 0x100
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
    // 00488863  7cce                   -jl 0x488833
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00488833;
    }
    // 00488865  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0048886b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048886c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048886d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048886e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048886f:
    // 0048886f  ba00040000             -mov edx, 0x400
    cpu.edx = 1024 /*0x400*/;
    // 00488874  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00488876  e82184ffff             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 0048887b  81c400040000           -add esp, 0x400
    (cpu.esp) += x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 00488881  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488882  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488883  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488884  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_488888(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488888  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488889  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048888a  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048888b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048888c  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 0048888f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00488891  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00488893  89dd                   -mov ebp, ebx
    cpu.ebp = cpu.ebx;
    // 00488895  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488897  7505                   -jne 0x48889e
    if (!cpu.flags.zf)
    {
        goto L_0x0048889e;
    }
    // 00488899  be70d35100             -mov esi, 0x51d370
    cpu.esi = 5362544 /*0x51d370*/;
L_0x0048889e:
    // 0048889e  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004888a0  7408                   -je 0x4888aa
    if (cpu.flags.zf)
    {
        goto L_0x004888aa;
    }
    // 004888a2  3bbe3c040000           +cmp edi, dword ptr [esi + 0x43c]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004888a8  7429                   -je 0x4888d3
    if (cpu.flags.zf)
    {
        goto L_0x004888d3;
    }
L_0x004888aa:
    // 004888aa  83be3c04000000         +cmp dword ptr [esi + 0x43c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004888b1  7407                   -je 0x4888ba
    if (cpu.flags.zf)
    {
        goto L_0x004888ba;
    }
    // 004888b3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004888b5  e822010000             -call 0x4889dc
    cpu.esp -= 4;
    sub_4889dc(app, cpu);
    if (cpu.terminate) return;
L_0x004888ba:
    // 004888ba  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004888bc  751c                   -jne 0x4888da
    if (!cpu.flags.zf)
    {
        goto L_0x004888da;
    }
L_0x004888be:
    // 004888be  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 004888c0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004888c5  892d30a44c00           -mov dword ptr [0x4ca430], ebp
    app->getMemory<x86::reg32>(x86::reg32(5022768) /* 0x4ca430 */) = cpu.ebp;
L_0x004888cb:
    // 004888cb  83c46c                 +add esp, 0x6c
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
    // 004888ce  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004888cf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004888d0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004888d1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004888d2  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004888d3:
    // 004888d3  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004888d8  ebf1                   -jmp 0x4888cb
    goto L_0x004888cb;
L_0x004888da:
    // 004888da  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 004888df  e8e482ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 004888e4  80be5d04000000         +cmp byte ptr [esi + 0x45d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004888eb  756c                   -jne 0x488959
    if (!cpu.flags.zf)
    {
        goto L_0x00488959;
    }
L_0x004888ed:
    // 004888ed  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004888ef  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004888f1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004888f3  e8c0eaffff             -call 0x4873b8
    cpu.esp -= 4;
    sub_4873b8(app, cpu);
    if (cpu.terminate) return;
    // 004888f8  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004888fa:
    // 004888fa  2eff1520754b00         -call dword ptr cs:[0x4b7520]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945184) /* 0x4b7520 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488901  a3c8b34c00             -mov dword ptr [0x4cb3c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5026760) /* 0x4cb3c8 */) = cpu.eax;
    // 00488906  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00488908  745f                   -je 0x488969
    if (cpu.flags.zf)
    {
        goto L_0x00488969;
    }
    // 0048890a  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048890f  8b15c4b34c00           -mov edx, dword ptr [0x4cb3c4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5026756) /* 0x4cb3c4 */);
    // 00488915  a3bcb34c00             -mov dword ptr [0x4cb3bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5026748) /* 0x4cb3bc */) = cpu.eax;
    // 0048891a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048891c  7408                   -je 0x488926
    if (cpu.flags.zf)
    {
        goto L_0x00488926;
    }
    // 0048891e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00488920  890dc4b34c00           -mov dword ptr [0x4cb3c4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5026756) /* 0x4cb3c4 */) = cpu.ecx;
L_0x00488926:
    // 00488926  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0048892b  c7864004000000000000   -mov dword ptr [esi + 0x440], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1088) /* 0x440 */) = 0 /*0x0*/;
    // 00488935  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 0048893a  c7863c04000000000000   -mov dword ptr [esi + 0x43c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */) = 0 /*0x0*/;
    // 00488944  e89782ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00488949  891d30a44c00           -mov dword ptr [0x4ca430], ebx
    app->getMemory<x86::reg32>(x86::reg32(5022768) /* 0x4ca430 */) = cpu.ebx;
    // 0048894f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488951  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00488954  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488955  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488956  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488957  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488958  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488959:
    // 00488959  e83a14ffff             -call 0x479d98
    cpu.esp -= 4;
    sub_479d98(app, cpu);
    if (cpu.terminate) return;
    // 0048895e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488960  758b                   -jne 0x4888ed
    if (!cpu.flags.zf)
    {
        goto L_0x004888ed;
    }
    // 00488962  bbadcbea00             -mov ebx, 0xeacbad
    cpu.ebx = 15387565 /*0xeacbad*/;
    // 00488967  eb91                   -jmp 0x4888fa
    goto L_0x004888fa;
L_0x00488969:
    // 00488969  833dc4b34c0000         +cmp dword ptr [0x4cb3c4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5026756) /* 0x4cb3c4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488970  750a                   -jne 0x48897c
    if (!cpu.flags.zf)
    {
        goto L_0x0048897c;
    }
    // 00488972  c705c4b34c0001000000   -mov dword ptr [0x4cb3c4], 1
    app->getMemory<x86::reg32>(x86::reg32(5026756) /* 0x4cb3c4 */) = 1 /*0x1*/;
L_0x0048897c:
    // 0048897c  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00488980  898640040000           -mov dword ptr [esi + 0x440], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1088) /* 0x440 */) = cpu.eax;
    // 00488986  89be3c040000           -mov dword ptr [esi + 0x43c], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */) = cpu.edi;
    // 0048898c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0048898e  0f842affffff           -je 0x4888be
    if (cpu.flags.zf)
    {
        goto L_0x004888be;
    }
    // 00488994  8b5c2424               -mov ebx, dword ptr [esp + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00488998  8a8e5d040000           -mov cl, byte ptr [esi + 0x45d]
    cpu.cl = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1117) /* 0x45d */);
    // 0048899e  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004889a2  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004889a4  7529                   -jne 0x4889cf
    if (!cpu.flags.zf)
    {
        goto L_0x004889cf;
    }
    // 004889a6  3bbe44040000           +cmp edi, dword ptr [esi + 0x444]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004889ac  7521                   -jne 0x4889cf
    if (!cpu.flags.zf)
    {
        goto L_0x004889cf;
    }
    // 004889ae  8b442454               -mov eax, dword ptr [esp + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 004889b2  8b9e64040000           -mov ebx, dword ptr [esi + 0x464]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1124) /* 0x464 */);
    // 004889b8  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004889bb  0fafd8                 -imul ebx, eax
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 004889be  8b8668040000           -mov eax, dword ptr [esi + 0x468]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1128) /* 0x468 */);
    // 004889c4  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004889c7  8b7c2424               -mov edi, dword ptr [esp + 0x24]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004889cb  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004889cd  01fb                   +add ebx, edi
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edi));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
L_0x004889cf:
    // 004889cf  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004889d1  e83e6e0100             -call 0x49f814
    cpu.esp -= 4;
    sub_49f814(app, cpu);
    if (cpu.terminate) return;
    // 004889d6  e9e3feffff             -jmp 0x4888be
    goto L_0x004888be;
}

/* align: skip 0x90 */
void Application::sub_4889dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004889dc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004889dd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004889de  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004889df  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004889e1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004889e3  7505                   -jne 0x4889ea
    if (!cpu.flags.zf)
    {
        goto L_0x004889ea;
    }
    // 004889e5  bb70d35100             -mov ebx, 0x51d370
    cpu.ebx = 5362544 /*0x51d370*/;
L_0x004889ea:
    // 004889ea  8b933c040000           -mov edx, dword ptr [ebx + 0x43c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1084) /* 0x43c */);
    // 004889f0  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004889f2  750c                   -jne 0x488a00
    if (!cpu.flags.zf)
    {
        goto L_0x00488a00;
    }
    // 004889f4  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004889f6  893530a44c00           -mov dword ptr [0x4ca430], esi
    app->getMemory<x86::reg32>(x86::reg32(5022768) /* 0x4ca430 */) = cpu.esi;
    // 004889fc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004889fd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004889fe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004889ff  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488a00:
    // 00488a00  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488a01  8b8b40040000           -mov ecx, dword ptr [ebx + 0x440]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1088) /* 0x440 */);
    // 00488a07  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488a08  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00488a0a  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00488a0c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488a0d  ff9280000000           -call dword ptr [edx + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488a13  c7833c04000000000000   -mov dword ptr [ebx + 0x43c], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1084) /* 0x43c */) = 0 /*0x0*/;
    // 00488a1d  c7834004000000000000   -mov dword ptr [ebx + 0x440], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(1088) /* 0x440 */) = 0 /*0x0*/;
    // 00488a27  2eff1520754b00         -call dword ptr cs:[0x4b7520]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945184) /* 0x4b7520 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488a2e  8b1dc8b34c00           -mov ebx, dword ptr [0x4cb3c8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5026760) /* 0x4cb3c8 */);
    // 00488a34  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488a36  8b1dc0b34c00           -mov ebx, dword ptr [0x4cb3c0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5026752) /* 0x4cb3c0 */);
    // 00488a3c  a3bcb34c00             -mov dword ptr [0x4cb3bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5026748) /* 0x4cb3bc */) = cpu.eax;
    // 00488a41  39d8                   +cmp eax, ebx
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
    // 00488a43  7e05                   -jle 0x488a4a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00488a4a;
    }
    // 00488a45  a3c0b34c00             -mov dword ptr [0x4cb3c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5026752) /* 0x4cb3c0 */) = cpu.eax;
L_0x00488a4a:
    // 00488a4a  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 00488a4f  e88c81ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00488a54  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488a55  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00488a57  893530a44c00           -mov dword ptr [0x4ca430], esi
    app->getMemory<x86::reg32>(x86::reg32(5022768) /* 0x4ca430 */) = cpu.esi;
    // 00488a5d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488a5e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488a5f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488a60  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_488a64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488a64  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488a65  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488a66  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488a67  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00488a68  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488a69  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00488a6a  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00488a6d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00488a6f  8b903c040000           -mov edx, dword ptr [eax + 0x43c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1084) /* 0x43c */);
    // 00488a75  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00488a77  750f                   -jne 0x488a88
    if (!cpu.flags.zf)
    {
        goto L_0x00488a88;
    }
    // 00488a79  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00488a7e  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00488a81  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488a82  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488a83  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488a84  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488a85  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488a86  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488a87  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488a88:
    // 00488a88  8b8e40040000           -mov ecx, dword ptr [esi + 0x440]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1088) /* 0x440 */);
    // 00488a8e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488a8f  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00488a91  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488a92  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00488a94  ff9080000000           -call dword ptr [eax + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488a9a  2eff1520754b00         -call dword ptr cs:[0x4b7520]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945184) /* 0x4b7520 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488aa1  8b1dc8b34c00           -mov ebx, dword ptr [0x4cb3c8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5026760) /* 0x4cb3c8 */);
    // 00488aa7  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00488aa9  8b1dc0b34c00           -mov ebx, dword ptr [0x4cb3c0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5026752) /* 0x4cb3c0 */);
    // 00488aaf  a3bcb34c00             -mov dword ptr [0x4cb3bc], eax
    app->getMemory<x86::reg32>(x86::reg32(5026748) /* 0x4cb3bc */) = cpu.eax;
    // 00488ab4  39d8                   +cmp eax, ebx
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
    // 00488ab6  7e05                   -jle 0x488abd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00488abd;
    }
    // 00488ab8  a3c0b34c00             -mov dword ptr [0x4cb3c0], eax
    app->getMemory<x86::reg32>(x86::reg32(5026752) /* 0x4cb3c0 */) = cpu.eax;
L_0x00488abd:
    // 00488abd  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 00488ac2  e81981ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00488ac7  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 00488acc  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00488ace  e8f580ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00488ad3  2eff1520754b00         -call dword ptr cs:[0x4b7520]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4945184) /* 0x4b7520 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488ada  a3c8b34c00             -mov dword ptr [0x4cb3c8], eax
    app->getMemory<x86::reg32>(x86::reg32(5026760) /* 0x4cb3c8 */) = cpu.eax;
    // 00488adf  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 00488ae1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00488ae3  e8d0e8ffff             -call 0x4873b8
    cpu.esp -= 4;
    sub_4873b8(app, cpu);
    if (cpu.terminate) return;
    // 00488ae8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488aea  7516                   -jne 0x488b02
    if (!cpu.flags.zf)
    {
        goto L_0x00488b02;
    }
    // 00488aec  8b6c2424               -mov ebp, dword ptr [esp + 0x24]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00488af0  3bae40040000           +cmp ebp, dword ptr [esi + 0x440]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1088) /* 0x440 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488af6  743e                   -je 0x488b36
    if (cpu.flags.zf)
    {
        goto L_0x00488b36;
    }
    // 00488af8  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00488af9  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00488afb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488afc  ff9080000000           -call dword ptr [eax + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00488b02:
    // 00488b02  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00488b04  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 00488b09  898e40040000           -mov dword ptr [esi + 0x440], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1088) /* 0x440 */) = cpu.ecx;
    // 00488b0f  890dbcb34c00           -mov dword ptr [0x4cb3bc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5026748) /* 0x4cb3bc */) = cpu.ecx;
    // 00488b15  898e3c040000           -mov dword ptr [esi + 0x43c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */) = cpu.ecx;
    // 00488b1b  e8c080ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00488b20  a138a44c00             -mov eax, dword ptr [0x4ca438]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5022776) /* 0x4ca438 */);
    // 00488b25  e8def4feff             -call 0x478008
    cpu.esp -= 4;
    sub_478008(app, cpu);
    if (cpu.terminate) return;
    // 00488b2a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488b2c  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00488b2f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b30  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b31  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b32  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b33  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b34  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b35  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488b36:
    // 00488b36  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00488b3b  89be3c040000           -mov dword ptr [esi + 0x43c], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1084) /* 0x43c */) = cpu.edi;
    // 00488b41  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00488b44  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b45  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b46  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b47  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b48  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b49  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b4a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_488b4c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488b4c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488b4d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488b4e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488b4f  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00488b52  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00488b54  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00488b56  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00488b58  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488b5a  e859e8ffff             -call 0x4873b8
    cpu.esp -= 4;
    sub_4873b8(app, cpu);
    if (cpu.terminate) return;
    // 00488b5f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488b61  7507                   -jne 0x488b6a
    if (!cpu.flags.zf)
    {
        goto L_0x00488b6a;
    }
    // 00488b63  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00488b66  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b67  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b68  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b69  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488b6a:
    // 00488b6a  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00488b6e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488b6f  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 00488b71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488b72  ff9080000000           -call dword ptr [eax + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488b78  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00488b7d  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00488b80  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b81  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b82  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488b83  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488b84(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488b84  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00488b85  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488b86  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00488b87  83ec7c                 -sub esp, 0x7c
    (cpu.esp) -= x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 00488b8a  8b8c248c000000         -mov ecx, dword ptr [esp + 0x8c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(140) /* 0x8c */);
    // 00488b91  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00488b93  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00488b95  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00488b97  8b9c2494000000         -mov ebx, dword ptr [esp + 0x94]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(148) /* 0x94 */);
    // 00488b9e  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00488ba0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00488ba2  89442478               -mov dword ptr [esp + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 00488ba6  89542474               -mov dword ptr [esp + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 00488baa  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 00488baf  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00488bb1  e8e680ffff             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 00488bb6  b86c000000             -mov eax, 0x6c
    cpu.eax = 108 /*0x6c*/;
    // 00488bbb  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00488bc0  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00488bc3  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00488bc7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00488bc9  7e10                   -jle 0x488bdb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00488bdb;
    }
    // 00488bcb  b821000000             -mov eax, 0x21
    cpu.eax = 33 /*0x21*/;
    // 00488bd0  894c2414               -mov dword ptr [esp + 0x14], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.ecx;
    // 00488bd4  80cb18                 -or bl, 0x18
    cpu.bl |= x86::reg8(x86::sreg8(24 /*0x18*/));
    // 00488bd7  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
L_0x00488bdb:
    // 00488bdb  f6c702                 +test bh, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 2 /*0x2*/));
    // 00488bde  7443                   -je 0x488c23
    if (cpu.flags.zf)
    {
        goto L_0x00488c23;
    }
L_0x00488be0:
    // 00488be0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00488be2  8d442478               -lea eax, [esp + 0x78]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00488be6  895c246c               -mov dword ptr [esp + 0x6c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.ebx;
    // 00488bea  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488beb  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00488bef  8b9c2480000000         -mov ebx, dword ptr [esp + 0x80]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00488bf6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488bf7  8bac2484000000         -mov ebp, dword ptr [esp + 0x84]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00488bfe  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 00488c00  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00488c01  ff5318                 -call dword ptr [ebx + 0x18]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(24) /* 0x18 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488c04  25ffff0000             +and eax, 0xffff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/))));
    // 00488c09  0f8548010000           -jne 0x488d57
    if (!cpu.flags.zf)
    {
        goto L_0x00488d57;
    }
    // 00488c0f  837c247400             +cmp dword ptr [esp + 0x74], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488c14  755c                   -jne 0x488c72
    if (!cpu.flags.zf)
    {
        goto L_0x00488c72;
    }
    // 00488c16  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00488c1a  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 00488c1d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488c1e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488c1f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488c20  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00488c23:
    // 00488c23  f6c704                 +test bh, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bh & 4 /*0x4*/));
    // 00488c26  75b8                   -jne 0x488be0
    if (!cpu.flags.zf)
    {
        goto L_0x00488be0;
    }
    // 00488c28  8a642404               -mov ah, byte ptr [esp + 4]
    cpu.ah = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00488c2c  8b942490000000         -mov edx, dword ptr [esp + 0x90]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(144) /* 0x90 */);
    // 00488c33  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 00488c37  80cc06                 -or ah, 6
    cpu.ah |= x86::reg8(x86::sreg8(6 /*0x6*/));
    // 00488c3a  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 00488c3e  88642404               -mov byte ptr [esp + 4], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ah;
    // 00488c42  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00488c44  7f9a                   -jg 0x488be0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00488be0;
    }
    // 00488c46  7598                   -jne 0x488be0
    if (!cpu.flags.zf)
    {
        goto L_0x00488be0;
    }
    // 00488c48  8a542405               -mov dl, byte ptr [esp + 5]
    cpu.dl = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */);
    // 00488c4c  bf20000000             -mov edi, 0x20
    cpu.edi = 32 /*0x20*/;
    // 00488c51  8d6c2448               -lea ebp, [esp + 0x48]
    cpu.ebp = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00488c55  80ca10                 +or dl, 0x10
    cpu.clear_co();
    cpu.set_szp((cpu.dl |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 00488c58  897c2448               -mov dword ptr [esp + 0x48], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.edi;
    // 00488c5c  88542405               -mov byte ptr [esp + 5], dl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(5) /* 0x5 */) = cpu.dl;
    // 00488c60  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00488c61  8b8644040000           -mov eax, dword ptr [esi + 0x444]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1092) /* 0x444 */);
    // 00488c67  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488c68  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 00488c6a  ff5754                 -call dword ptr [edi + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488c6d  e96effffff             -jmp 0x488be0
    goto L_0x00488be0;
L_0x00488c72:
    // 00488c72  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 00488c77  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00488c79  e84a7fffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00488c7e  8b542474               -mov edx, dword ptr [esp + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00488c82  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488c84  e82fe7ffff             -call 0x4873b8
    cpu.esp -= 4;
    sub_4873b8(app, cpu);
    if (cpu.terminate) return;
    // 00488c89  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00488c8b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488c8d  7516                   -jne 0x488ca5
    if (!cpu.flags.zf)
    {
        goto L_0x00488ca5;
    }
    // 00488c8f  8b4c2424               -mov ecx, dword ptr [esp + 0x24]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00488c93  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00488c97  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488c98  8b7c2478               -mov edi, dword ptr [esp + 0x78]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00488c9c  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00488c9e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488c9f  ff9080000000           -call dword ptr [eax + 0x80]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00488ca5:
    // 00488ca5  a138af4c00             -mov eax, dword ptr [0x4caf38]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5025592) /* 0x4caf38 */);
    // 00488caa  e8317fffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00488caf  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00488cb1  0f8585000000           -jne 0x488d3c
    if (!cpu.flags.zf)
    {
        goto L_0x00488d3c;
    }
L_0x00488cb7:
    // 00488cb7  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 00488cbc  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00488cc0  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00488cc3  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00488cc5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00488cc7  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488cc8  8b4c2478               -mov ecx, dword ptr [esp + 0x78]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00488ccc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488ccd  ff5358                 -call dword ptr [ebx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488cd0  bb20000000             -mov ebx, 0x20
    cpu.ebx = 32 /*0x20*/;
    // 00488cd5  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00488cd9  895c2448               -mov dword ptr [esp + 0x48], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.ebx;
    // 00488cdd  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00488cdf  8d442448               -lea eax, [esp + 0x48]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 00488ce3  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488ce4  8b742478               -mov esi, dword ptr [esp + 0x78]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00488ce8  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00488ce9  ff5354                 -call dword ptr [ebx + 0x54]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488cec  837c245408             +cmp dword ptr [esp + 0x54], 8
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(8 /*0x8*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488cf1  7777                   -ja 0x488d6a
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00488d6a;
    }
    // 00488cf3  baff000000             -mov edx, 0xff
    cpu.edx = 255 /*0xff*/;
    // 00488cf8  8b9c2498000000         -mov ebx, dword ptr [esp + 0x98]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(152) /* 0x98 */);
    // 00488cff  8954246c               -mov dword ptr [esp + 0x6c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.edx;
    // 00488d03  89542470               -mov dword ptr [esp + 0x70], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.edx;
    // 00488d07  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00488d09  740f                   -je 0x488d1a
    if (cpu.flags.zf)
    {
        goto L_0x00488d1a;
    }
    // 00488d0b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488d0c  8b7c2478               -mov edi, dword ptr [esp + 0x78]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00488d10  8b442478               -mov eax, dword ptr [esp + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */);
    // 00488d14  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488d15  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00488d17  ff507c                 -call dword ptr [eax + 0x7c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(124) /* 0x7c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00488d1a:
    // 00488d1a  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00488d1e  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00488d20  8d44246c               -lea eax, [esp + 0x6c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 00488d24  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488d25  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 00488d27  8b6c247c               -mov ebp, dword ptr [esp + 0x7c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00488d2b  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00488d2c  ff5374                 -call dword ptr [ebx + 0x74]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(116) /* 0x74 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488d2f  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00488d33  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 00488d36  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488d37  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488d38  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488d39  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00488d3c:
    // 00488d3c  80be5f04000000         +cmp byte ptr [esi + 0x45f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1119) /* 0x45f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00488d43  0f856effffff           -jne 0x488cb7
    if (!cpu.flags.zf)
    {
        goto L_0x00488cb7;
    }
    // 00488d49  8b6c2474               -mov ebp, dword ptr [esp + 0x74]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00488d4d  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00488d51  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00488d52  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00488d54  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x00488d57:
    // 00488d57  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488d59  89442474               -mov dword ptr [esp + 0x74], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.eax;
    // 00488d5d  8b442474               -mov eax, dword ptr [esp + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00488d61  83c47c                 -add esp, 0x7c
    (cpu.esp) += x86::reg32(x86::sreg32(124 /*0x7c*/));
    // 00488d64  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488d65  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488d66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488d67  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00488d6a:
    // 00488d6a  31ed                   +xor ebp, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp))));
    // 00488d6c  896c246c               -mov dword ptr [esp + 0x6c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.ebp;
    // 00488d70  896c2470               -mov dword ptr [esp + 0x70], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.ebp;
    // 00488d74  eba4                   -jmp 0x488d1a
    goto L_0x00488d1a;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_488d78(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488d78  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488d79  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00488d7b  7505                   -jne 0x488d82
    if (!cpu.flags.zf)
    {
        goto L_0x00488d82;
    }
    // 00488d7d  b870d35100             -mov eax, 0x51d370
    cpu.eax = 5362544 /*0x51d370*/;
L_0x00488d82:
    // 00488d82  3b903c040000           +cmp edx, dword ptr [eax + 0x43c]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1084) /* 0x43c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488d88  7408                   -je 0x488d92
    if (cpu.flags.zf)
    {
        goto L_0x00488d92;
    }
    // 00488d8a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488d8b  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00488d8d  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488d90  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488d91  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488d92:
    // 00488d92  e845fcffff             -call 0x4889dc
    cpu.esp -= 4;
    sub_4889dc(app, cpu);
    if (cpu.terminate) return;
    // 00488d97  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488d98  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00488d9a  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488d9d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488d9e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_488da0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488da0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488da1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488da2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488da3  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00488da5  ff5260                 -call dword ptr [edx + 0x60]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488da8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488da9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488daa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_488dac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488dac  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488dad  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488dae  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00488db1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00488db3  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00488db6  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00488db8  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00488dbd  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488dbe  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00488dc2  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00488dc6  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488dc7  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00488dc9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488dca  ff5130                 -call dword ptr [ecx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488dcd  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00488dd0  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00488dd3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488dd4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488dd5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_488dd8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488dd8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488dd9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488dda  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00488ddd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00488ddf  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00488de2  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00488de4  b902000000             -mov ecx, 2
    cpu.ecx = 2 /*0x2*/;
    // 00488de9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488dea  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00488dee  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00488df2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488df3  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00488df5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488df6  ff5130                 -call dword ptr [ecx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488df9  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00488dfc  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00488dff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e00  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e01  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_488e04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488e04  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488e05  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488e06  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00488e09  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00488e0b  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00488e0e  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00488e10  b900000200             -mov ecx, 0x20000
    cpu.ecx = 131072 /*0x20000*/;
    // 00488e15  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488e16  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00488e1a  894c2408               -mov dword ptr [esp + 8], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 00488e1e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488e1f  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00488e21  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488e22  ff5130                 -call dword ptr [ecx + 0x30]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488e25  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00488e28  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00488e2b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e2c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e2d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_488e30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488e30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488e31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488e32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488e33  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x00488e35:
    // 00488e35  6a02                   -push 2
    app->getMemory<x86::reg32>(cpu.esp-4) = 2 /*0x2*/;
    cpu.esp -= 4;
    // 00488e37  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 00488e39  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488e3a  ff5034                 -call dword ptr [eax + 0x34]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(52) /* 0x34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488e3d  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00488e42  3d1c027688             +cmp eax, 0x8876021c
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
    // 00488e47  74ec                   -je 0x488e35
    if (cpu.flags.zf)
    {
        goto L_0x00488e35;
    }
    // 00488e49  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e4a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e4b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488e4c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_488e50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488e50  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00488e51  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488e52  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00488e53  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00488e56  8bac2480000000         -mov ebp, dword ptr [esp + 0x80]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00488e5d  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00488e5f  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00488e61  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00488e63  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00488e65  ba6c000000             -mov edx, 0x6c
    cpu.edx = 108 /*0x6c*/;
    // 00488e6a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488e6b  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00488e6f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488e70  8b10                   -mov edx, dword ptr [eax]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax);
    // 00488e72  ff5258                 -call dword ptr [edx + 0x58]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488e75  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 00488e79  0f8575000000           -jne 0x488ef4
    if (!cpu.flags.zf)
    {
        goto L_0x00488ef4;
    }
    // 00488e7f  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00488e81  7406                   -je 0x488e89
    if (cpu.flags.zf)
    {
        goto L_0x00488e89;
    }
    // 00488e83  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00488e87  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x00488e89:
    // 00488e89  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00488e8b  7406                   -je 0x488e93
    if (cpu.flags.zf)
    {
        goto L_0x00488e93;
    }
    // 00488e8d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00488e91  8907                   -mov dword ptr [edi], eax
    app->getMemory<x86::reg32>(cpu.edi) = cpu.eax;
L_0x00488e93:
    // 00488e93  8b74247c               -mov esi, dword ptr [esp + 0x7c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00488e97  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00488e99  7406                   -je 0x488ea1
    if (cpu.flags.zf)
    {
        goto L_0x00488ea1;
    }
    // 00488e9b  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00488e9f  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
L_0x00488ea1:
    // 00488ea1  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00488ea3  7407                   -je 0x488eac
    if (cpu.flags.zf)
    {
        goto L_0x00488eac;
    }
    // 00488ea5  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00488ea9  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
L_0x00488eac:
    // 00488eac  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00488eae  740f                   -je 0x488ebf
    if (cpu.flags.zf)
    {
        goto L_0x00488ebf;
    }
    // 00488eb0  837c245410             +cmp dword ptr [esp + 0x54], 0x10
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(84) /* 0x54 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(16 /*0x10*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00488eb5  7411                   -je 0x488ec8
    if (cpu.flags.zf)
    {
        goto L_0x00488ec8;
    }
    // 00488eb7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00488eb9  8a442454               -mov al, byte ptr [esp + 0x54]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(84) /* 0x54 */);
    // 00488ebd  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x00488ebf:
    // 00488ebf  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00488ec2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ec3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ec4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ec5  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00488ec8:
    // 00488ec8  8b442458               -mov eax, dword ptr [esp + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(88) /* 0x58 */);
    // 00488ecc  e893e6ffff             -call 0x487564
    cpu.esp -= 4;
    sub_487564(app, cpu);
    if (cpu.terminate) return;
    // 00488ed1  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00488ed3  8b44245c               -mov eax, dword ptr [esp + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(92) /* 0x5c */);
    // 00488ed7  e888e6ffff             -call 0x487564
    cpu.esp -= 4;
    sub_487564(app, cpu);
    if (cpu.terminate) return;
    // 00488edc  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00488ede  8b442460               -mov eax, dword ptr [esp + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00488ee2  e87de6ffff             -call 0x487564
    cpu.esp -= 4;
    sub_487564(app, cpu);
    if (cpu.terminate) return;
    // 00488ee7  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 00488ee9  8933                   -mov dword ptr [ebx], esi
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.esi;
    // 00488eeb  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00488eee  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488eef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ef0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488ef1  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00488ef4:
    // 00488ef4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 00488ef6  7406                   -je 0x488efe
    if (cpu.flags.zf)
    {
        goto L_0x00488efe;
    }
    // 00488ef8  c70600000000           -mov dword ptr [esi], 0
    app->getMemory<x86::reg32>(cpu.esi) = 0 /*0x0*/;
L_0x00488efe:
    // 00488efe  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00488f00  7406                   -je 0x488f08
    if (cpu.flags.zf)
    {
        goto L_0x00488f08;
    }
    // 00488f02  c70700000000           -mov dword ptr [edi], 0
    app->getMemory<x86::reg32>(cpu.edi) = 0 /*0x0*/;
L_0x00488f08:
    // 00488f08  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00488f0a  7406                   -je 0x488f12
    if (cpu.flags.zf)
    {
        goto L_0x00488f12;
    }
    // 00488f0c  c70300000000           -mov dword ptr [ebx], 0
    app->getMemory<x86::reg32>(cpu.ebx) = 0 /*0x0*/;
L_0x00488f12:
    // 00488f12  8b4c247c               -mov ecx, dword ptr [esp + 0x7c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */);
    // 00488f16  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00488f18  7406                   -je 0x488f20
    if (cpu.flags.zf)
    {
        goto L_0x00488f20;
    }
    // 00488f1a  c70100000000           -mov dword ptr [ecx], 0
    app->getMemory<x86::reg32>(cpu.ecx) = 0 /*0x0*/;
L_0x00488f20:
    // 00488f20  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00488f22  749b                   -je 0x488ebf
    if (cpu.flags.zf)
    {
        goto L_0x00488ebf;
    }
    // 00488f24  c7450000000000         -mov dword ptr [ebp], 0
    app->getMemory<x86::reg32>(cpu.ebp) = 0 /*0x0*/;
    // 00488f2b  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00488f2e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488f2f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488f30  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488f31  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_488f34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488f34  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488f35  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488f36  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488f39  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00488f3b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488f3c  68a0184d00             -push 0x4d18a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5052576 /*0x4d18a0*/;
    cpu.esp -= 4;
    // 00488f41  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00488f43  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488f44  ff11                   -call dword ptr [ecx]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488f46  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00488f49  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00488f4b  7506                   -jne 0x488f53
    if (!cpu.flags.zf)
    {
        goto L_0x00488f53;
    }
    // 00488f4d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488f50  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488f51  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488f52  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488f53:
    // 00488f53  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488f54  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00488f56  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00488f58  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488f59  ff9094000000           -call dword ptr [eax + 0x94]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488f5f  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00488f63  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00488f67  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488f68  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00488f6a  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488f6d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488f6e  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488f71  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488f72  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488f73  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488f74(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488f74  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00488f75  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488f76  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488f79  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00488f7b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488f7c  68a0184d00             -push 0x4d18a0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5052576 /*0x4d18a0*/;
    cpu.esp -= 4;
    // 00488f81  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 00488f83  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488f84  ff11                   -call dword ptr [ecx]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecx);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488f86  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00488f89  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00488f8b  7506                   -jne 0x488f93
    if (!cpu.flags.zf)
    {
        goto L_0x00488f93;
    }
    // 00488f8d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488f90  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488f91  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488f92  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00488f93:
    // 00488f93  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488f94  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00488f96  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00488f98  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00488f99  ff9098000000           -call dword ptr [eax + 0x98]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488f9f  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00488fa3  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00488fa7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00488fa8  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 00488faa  ff5008                 -call dword ptr [eax + 8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 00488fad  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488fae  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00488fb1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488fb2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00488fb3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_488fb4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00488fb4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00488fb5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00488fb6  83ec74                 -sub esp, 0x74
    (cpu.esp) -= x86::reg32(x86::sreg32(116 /*0x74*/));
    // 00488fb9  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00488fbb  bf64000000             -mov edi, 0x64
    cpu.edi = 100 /*0x64*/;
    // 00488fc0  8b842484000000         -mov eax, dword ptr [esp + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00488fc7  895c2468               -mov dword ptr [esp + 0x68], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.ebx;
    // 00488fcb  89542464               -mov dword ptr [esp + 0x64], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.edx;
    // 00488fcf  89442450               -mov dword ptr [esp + 0x50], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.eax;
    // 00488fd3  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00488fd5  8b842480000000         -mov eax, dword ptr [esp + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */);
    // 00488fdc  8954246c               -mov dword ptr [esp + 0x6c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.edx;
    // 00488fe0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00488fe2  8d542464               -lea edx, [esp + 0x64]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00488fe6  89442470               -mov dword ptr [esp + 0x70], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.eax;
    // 00488fea  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00488fec  893c24                 -mov dword ptr [esp], edi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edi;
    // 00488fef  e828e5ffff             -call 0x48751c
    cpu.esp -= 4;
    sub_48751c(app, cpu);
    if (cpu.terminate) return;
    // 00488ff4  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00488ff6  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00488ff7  6800040001             -push 0x1000400
    app->getMemory<x86::reg32>(cpu.esp-4) = 16778240 /*0x1000400*/;
    cpu.esp -= 4;
    // 00488ffc  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00488ffe  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489000  8d442474               -lea eax, [esp + 0x74]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00489004  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489005  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 00489007  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489008  ff5214                 -call dword ptr [edx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048900b  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 0048900f  750d                   -jne 0x48901e
    if (!cpu.flags.zf)
    {
        goto L_0x0048901e;
    }
    // 00489011  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00489016  83c474                 -add esp, 0x74
    (cpu.esp) += x86::reg32(x86::sreg32(116 /*0x74*/));
    // 00489019  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048901a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048901b  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x0048901e:
    // 0048901e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489020  83c474                 -add esp, 0x74
    (cpu.esp) += x86::reg32(x86::sreg32(116 /*0x74*/));
    // 00489023  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489024  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489025  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_489028(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489028  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489029  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048902a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048902b  81ec8c000000           -sub esp, 0x8c
    (cpu.esp) -= x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 00489031  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00489033  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00489035  898c2484000000         -mov dword ptr [esp + 0x84], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */) = cpu.ecx;
    // 0048903c  8b8424b4000000         -mov eax, dword ptr [esp + 0xb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00489043  8bac249c000000         -mov ebp, dword ptr [esp + 0x9c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(156) /* 0x9c */);
    // 0048904a  897c2468               -mov dword ptr [esp + 0x68], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */) = cpu.edi;
    // 0048904e  01fd                   -add ebp, edi
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edi));
    // 00489050  8bbc2484000000         -mov edi, dword ptr [esp + 0x84]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00489057  89542464               -mov dword ptr [esp + 0x64], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */) = cpu.edx;
    // 0048905b  01d7                   -add edi, edx
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048905d  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 00489064  897c246c               -mov dword ptr [esp + 0x6c], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(108) /* 0x6c */) = cpu.edi;
    // 00489068  89542478               -mov dword ptr [esp + 0x78], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(120) /* 0x78 */) = cpu.edx;
    // 0048906c  8b9424a4000000         -mov edx, dword ptr [esp + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 00489073  8bbc24b0000000         -mov edi, dword ptr [esp + 0xb0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 0048907a  89542474               -mov dword ptr [esp + 0x74], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 0048907e  8b9424a8000000         -mov edx, dword ptr [esp + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(168) /* 0xa8 */);
    // 00489085  896c2470               -mov dword ptr [esp + 0x70], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(112) /* 0x70 */) = cpu.ebp;
    // 00489089  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048908b  8bac24ac000000         -mov ebp, dword ptr [esp + 0xac]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(172) /* 0xac */);
    // 00489092  89942480000000         -mov dword ptr [esp + 0x80], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(128) /* 0x80 */) = cpu.edx;
    // 00489099  8b9424a4000000         -mov edx, dword ptr [esp + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(164) /* 0xa4 */);
    // 004890a0  01ea                   -add edx, ebp
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004890a2  bb00000001             -mov ebx, 0x1000000
    cpu.ebx = 16777216 /*0x1000000*/;
    // 004890a7  8954247c               -mov dword ptr [esp + 0x7c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(124) /* 0x7c */) = cpu.edx;
    // 004890ab  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004890ad  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004890af  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 004890b2  898c2488000000         -mov dword ptr [esp + 0x88], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.ecx;
    // 004890b9  83fa03                 +cmp edx, 3
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
    // 004890bc  0f859f000000           -jne 0x489161
    if (!cpu.flags.zf)
    {
        goto L_0x00489161;
    }
    // 004890c2  b920000000             -mov ecx, 0x20
    cpu.ecx = 32 /*0x20*/;
L_0x004890c7:
    // 004890c7  a804                   +test al, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 4 /*0x4*/));
    // 004890c9  7403                   -je 0x4890ce
    if (cpu.flags.zf)
    {
        goto L_0x004890ce;
    }
    // 004890cb  80c902                 -or cl, 2
    cpu.cl |= x86::reg8(x86::sreg8(2 /*0x2*/));
L_0x004890ce:
    // 004890ce  a808                   +test al, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 8 /*0x8*/));
    // 004890d0  7403                   -je 0x4890d5
    if (cpu.flags.zf)
    {
        goto L_0x004890d5;
    }
    // 004890d2  80c904                 -or cl, 4
    cpu.cl |= x86::reg8(x86::sreg8(4 /*0x4*/));
L_0x004890d5:
    // 004890d5  a810                   +test al, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 16 /*0x10*/));
    // 004890d7  7403                   -je 0x4890dc
    if (cpu.flags.zf)
    {
        goto L_0x004890dc;
    }
    // 004890d9  80cf80                 -or bh, 0x80
    cpu.bh |= x86::reg8(x86::sreg8(128 /*0x80*/));
L_0x004890dc:
    // 004890dc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004890de  7424                   -je 0x489104
    if (cpu.flags.zf)
    {
        goto L_0x00489104;
    }
    // 004890e0  ba64000000             -mov edx, 0x64
    cpu.edx = 100 /*0x64*/;
    // 004890e5  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004890e7  e8b07bffff             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 004890ec  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 004890f1  80cf08                 -or bh, 8
    cpu.bh |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 004890f4  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 004890f7  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004890f9  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 004890fd  89842488000000         -mov dword ptr [esp + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */) = cpu.eax;
L_0x00489104:
    // 00489104  8d542464               -lea edx, [esp + 0x64]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00489108  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048910a  e80de4ffff             -call 0x48751c
    cpu.esp -= 4;
    sub_48751c(app, cpu);
    if (cpu.terminate) return;
    // 0048910f  8d542474               -lea edx, [esp + 0x74]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(116) /* 0x74 */);
    // 00489113  8b8424a0000000         -mov eax, dword ptr [esp + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(160) /* 0xa0 */);
    // 0048911a  8b8c2488000000         -mov ecx, dword ptr [esp + 0x88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(136) /* 0x88 */);
    // 00489121  e8f6e3ffff             -call 0x48751c
    cpu.esp -= 4;
    sub_48751c(app, cpu);
    if (cpu.terminate) return;
    // 00489126  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489127  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489128  8d44246c               -lea eax, [esp + 0x6c]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(108) /* 0x6c */);
    // 0048912c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048912d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048912e  8d842484000000         -lea eax, [esp + 0x84]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(132) /* 0x84 */);
    // 00489135  8b9424b0000000         -mov edx, dword ptr [esp + 0xb0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(176) /* 0xb0 */);
    // 0048913c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048913d  8b9c24b4000000         -mov ebx, dword ptr [esp + 0xb4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(180) /* 0xb4 */);
    // 00489144  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00489146  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489147  ff5214                 -call dword ptr [edx + 0x14]
    cpu.ip = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048914a  66a9ffff               +test ax, 0xffff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 65535 /*0xffff*/));
    // 0048914e  7531                   -jne 0x489181
    if (!cpu.flags.zf)
    {
        goto L_0x00489181;
    }
    // 00489150  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00489155  81c48c000000           -add esp, 0x8c
    (cpu.esp) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 0048915b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048915c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048915d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048915e  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
L_0x00489161:
    // 00489161  a802                   +test al, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 2 /*0x2*/));
    // 00489163  740a                   -je 0x48916f
    if (cpu.flags.zf)
    {
        goto L_0x0048916f;
    }
    // 00489165  b910000000             -mov ecx, 0x10
    cpu.ecx = 16 /*0x10*/;
    // 0048916a  e958ffffff             -jmp 0x4890c7
    goto L_0x004890c7;
L_0x0048916f:
    // 0048916f  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 00489171  0f8450ffffff           -je 0x4890c7
    if (cpu.flags.zf)
    {
        goto L_0x004890c7;
    }
    // 00489177  b940000000             -mov ecx, 0x40
    cpu.ecx = 64 /*0x40*/;
    // 0048917c  e946ffffff             -jmp 0x4890c7
    goto L_0x004890c7;
L_0x00489181:
    // 00489181  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00489183  81c48c000000           -add esp, 0x8c
    (cpu.esp) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 00489189  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048918a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048918b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048918c  c21c00                 -ret 0x1c
    cpu.esp += 4+28 /*0x1c*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_489190(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489190  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489191  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489192  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489193  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00489196  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0048919a  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0048919e  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 004891a0  be90724800             -mov esi, 0x487290
    cpu.esi = 4747920 /*0x487290*/;
    // 004891a5  8b4c242c               -mov ecx, dword ptr [esp + 0x2c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 004891a9  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004891aa  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004891ab  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004891ac  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004891ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004891af  7502                   -jne 0x4891b3
    if (!cpu.flags.zf)
    {
        goto L_0x004891b3;
    }
    // 004891b1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
L_0x004891b3:
    // 004891b3  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 004891b7  ffd1                   -call ecx
    cpu.ip = cpu.ecx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004891b9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004891be  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004891c1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004891c2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004891c3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004891c4  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
}

/* align: skip 0x90 */
void Application::sub_4891c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004891c8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004891c9  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004891ca  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004891ce  8b5354                 -mov edx, dword ptr [ebx + 0x54]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(84) /* 0x54 */);
    // 004891d1  8b742410               -mov esi, dword ptr [esp + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004891d5  83fa10                 +cmp edx, 0x10
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
    // 004891d8  744a                   -je 0x489224
    if (cpu.flags.zf)
    {
        goto L_0x00489224;
    }
    // 004891da  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004891dc  8a4354                 -mov al, byte ptr [ebx + 0x54]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(84) /* 0x54 */);
L_0x004891df:
    // 004891df  83f810                 +cmp eax, 0x10
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
    // 004891e2  7360                   -jae 0x489244
    if (!cpu.flags.cf)
    {
        goto L_0x00489244;
    }
    // 004891e4  83f808                 +cmp eax, 8
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
    // 004891e7  0f8380000000           -jae 0x48926d
    if (!cpu.flags.cf)
    {
        goto L_0x0048926d;
    }
L_0x004891ed:
    // 004891ed  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004891ef  7429                   -je 0x48921a
    if (cpu.flags.zf)
    {
        goto L_0x0048921a;
    }
    // 004891f1  837e1000               +cmp dword ptr [esi + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004891f5  0f8495000000           -je 0x489290
    if (cpu.flags.zf)
    {
        goto L_0x00489290;
    }
    // 004891fb  a1c8df5100             -mov eax, dword ptr [0x51dfc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365704) /* 0x51dfc8 */);
    // 00489200  3b4608                 +cmp eax, dword ptr [esi + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489203  0f8d87000000           -jge 0x489290
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00489290;
    }
    // 00489209  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048920b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048920d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048920f  e870e3ffff             -call 0x487584
    cpu.esp -= 4;
    sub_487584(app, cpu);
    if (cpu.terminate) return;
L_0x00489214:
    // 00489214  ff05c8df5100           -inc dword ptr [0x51dfc8]
    (app->getMemory<x86::reg32>(x86::reg32(5365704) /* 0x51dfc8 */))++;
L_0x0048921a:
    // 0048921a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048921f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489220  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489221  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00489224:
    // 00489224  8b4358                 -mov eax, dword ptr [ebx + 0x58]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(88) /* 0x58 */);
    // 00489227  e838e3ffff             -call 0x487564
    cpu.esp -= 4;
    sub_487564(app, cpu);
    if (cpu.terminate) return;
    // 0048922c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048922e  8b435c                 -mov eax, dword ptr [ebx + 0x5c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(92) /* 0x5c */);
    // 00489231  e82ee3ffff             -call 0x487564
    cpu.esp -= 4;
    sub_487564(app, cpu);
    if (cpu.terminate) return;
    // 00489236  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00489238  8b4360                 -mov eax, dword ptr [ebx + 0x60]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(96) /* 0x60 */);
    // 0048923b  e824e3ffff             -call 0x487564
    cpu.esp -= 4;
    sub_487564(app, cpu);
    if (cpu.terminate) return;
    // 00489240  01d0                   +add eax, edx
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
    // 00489242  eb9b                   -jmp 0x4891df
    goto L_0x004891df;
L_0x00489244:
    // 00489244  7709                   -ja 0x48924f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048924f;
    }
    // 00489246  800dc0df510004         +or byte ptr [0x51dfc0], 4
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(5365696) /* 0x51dfc0 */) |= x86::reg8(x86::sreg8(4 /*0x4*/))));
    // 0048924d  eb9e                   -jmp 0x4891ed
    goto L_0x004891ed;
L_0x0048924f:
    // 0048924f  83f818                 +cmp eax, 0x18
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(24 /*0x18*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489252  7299                   -jb 0x4891ed
    if (cpu.flags.cf)
    {
        goto L_0x004891ed;
    }
    // 00489254  7709                   -ja 0x48925f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048925f;
    }
    // 00489256  800dc0df510008         +or byte ptr [0x51dfc0], 8
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(5365696) /* 0x51dfc0 */) |= x86::reg8(x86::sreg8(8 /*0x8*/))));
    // 0048925d  eb8e                   -jmp 0x4891ed
    goto L_0x004891ed;
L_0x0048925f:
    // 0048925f  83f820                 +cmp eax, 0x20
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
    // 00489262  7589                   -jne 0x4891ed
    if (!cpu.flags.zf)
    {
        goto L_0x004891ed;
    }
    // 00489264  800dc0df510010         +or byte ptr [0x51dfc0], 0x10
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(5365696) /* 0x51dfc0 */) |= x86::reg8(x86::sreg8(16 /*0x10*/))));
    // 0048926b  eb80                   -jmp 0x4891ed
    goto L_0x004891ed;
L_0x0048926d:
    // 0048926d  770c                   -ja 0x48927b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048927b;
    }
    // 0048926f  800dc0df510001         +or byte ptr [0x51dfc0], 1
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(5365696) /* 0x51dfc0 */) |= x86::reg8(x86::sreg8(1 /*0x1*/))));
    // 00489276  e972ffffff             -jmp 0x4891ed
    goto L_0x004891ed;
L_0x0048927b:
    // 0048927b  83f80f                 +cmp eax, 0xf
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
    // 0048927e  0f8569ffffff           -jne 0x4891ed
    if (!cpu.flags.zf)
    {
        goto L_0x004891ed;
    }
    // 00489284  800dc0df510002         +or byte ptr [0x51dfc0], 2
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(x86::reg32(5365696) /* 0x51dfc0 */) |= x86::reg8(x86::sreg8(2 /*0x2*/))));
    // 0048928b  e95dffffff             -jmp 0x4891ed
    goto L_0x004891ed;
L_0x00489290:
    // 00489290  837e1000               +cmp dword ptr [esi + 0x10], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00489294  0f847affffff           -je 0x489214
    if (cpu.flags.zf)
    {
        goto L_0x00489214;
    }
    // 0048929a  a1c8df5100             -mov eax, dword ptr [0x51dfc8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5365704) /* 0x51dfc8 */);
    // 0048929f  3b4608                 +cmp eax, dword ptr [esi + 8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004892a2  0f8c6cffffff           -jl 0x489214
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489214;
    }
    // 004892a8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004892aa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004892ab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004892ac  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
}

/* align: skip  */
void Application::sub_4892af(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004892af  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004892b0  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004892b2  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004892b3  88d6                   -mov dh, dl
    cpu.dh = cpu.dl;
    // 004892b5  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004892b8  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 004892ba  c1e208                 -shl edx, 8
    cpu.edx <<= 8 /*0x8*/ % 32;
    // 004892bd  88f2                   -mov dl, dh
    cpu.dl = cpu.dh;
    // 004892bf  e8ec660100             -call 0x49f9b0
    cpu.esp -= 4;
    sub_49f9b0(app, cpu);
    if (cpu.terminate) return;
    // 004892c4  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004892c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004892c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4892d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004892d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004892d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004892d2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004892d3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004892d4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004892d6  8d3c9500000000         -lea edi, [edx*4]
    cpu.edi = x86::reg32(cpu.edx * 4);
    // 004892dd  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x004892df:
    // 004892df  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004892e1  8d4b20                 -lea ecx, [ebx + 0x20]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(32) /* 0x20 */);
L_0x004892e4:
    // 004892e4  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004892e7  8b157c1a4d00           -mov edx, dword ptr [0x4d1a7c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5053052) /* 0x4d1a7c */);
    // 004892ed  8950fc                 -mov dword ptr [eax - 4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-4) /* -0x4 */) = cpu.edx;
    // 004892f0  39c8                   +cmp eax, ecx
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
    // 004892f2  75f0                   -jne 0x4892e4
    if (!cpu.flags.zf)
    {
        goto L_0x004892e4;
    }
    // 004892f4  46                     -inc esi
    (cpu.esi)++;
    // 004892f5  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004892f7  83fe08                 +cmp esi, 8
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
    // 004892fa  7ce3                   -jl 0x4892df
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004892df;
    }
    // 004892fc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004892fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004892fe  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004892ff  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489300  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489304(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489304  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489305  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489306  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489307  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489308  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048930b  b880ffffff             -mov eax, 0xffffff80
    cpu.eax = 4294967168 /*0xffffff80*/;
    // 00489310  b9c0ffffff             -mov ecx, 0xffffffc0
    cpu.ecx = 4294967232 /*0xffffffc0*/;
    // 00489315  be3f000000             -mov esi, 0x3f
    cpu.esi = 63 /*0x3f*/;
L_0x0048931a:
    // 0048931a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048931c  83f8c0                 +cmp eax, -0x40
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
    // 0048931f  0f8d2e010000           -jge 0x489453
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00489453;
    }
    // 00489325  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
L_0x00489327:
    // 00489327  88d3                   -mov bl, dl
    cpu.bl = cpu.dl;
    // 00489329  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048932b  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 00489331  80c340                 -add bl, 0x40
    (cpu.bl) += x86::reg8(x86::sreg8(64 /*0x40*/));
    // 00489334  40                     -inc eax
    (cpu.eax)++;
    // 00489335  889acc6a5200           -mov byte ptr [edx + 0x526acc], bl
    app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5401292) /* 0x526acc */) = cpu.bl;
    // 0048933b  83f87f                 +cmp eax, 0x7f
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
    // 0048933e  7cda                   -jl 0x48931a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048931a;
    }
    // 00489340  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00489342  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x00489344:
    // 00489344  668b83ccb34c00         -mov ax, word ptr [ebx + 0x4cb3cc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(5026764) /* 0x4cb3cc */);
    // 0048934b  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048934d  6689442402             -mov word ptr [esp + 2], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 00489352  ba0d000000             -mov edx, 0xd
    cpu.edx = 13 /*0xd*/;
    // 00489357  668b4c2402             -mov cx, word ptr [esp + 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 0048935c  668b83d0b34c00         -mov ax, word ptr [ebx + 0x4cb3d0]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(5026768) /* 0x4cb3d0 */);
    // 00489363  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489365  66890424               -mov word ptr [esp], ax
    app->getMemory<x86::reg16>(cpu.esp) = cpu.ax;
    // 00489369  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048936b  8b83d8b34c00           -mov eax, dword ptr [ebx + 0x4cb3d8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5026776) /* 0x4cb3d8 */);
    // 00489371  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00489376  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 00489379  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 0048937b  83fe17                 +cmp esi, 0x17
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
    // 0048937e  7507                   -jne 0x489387
    if (!cpu.flags.zf)
    {
        goto L_0x00489387;
    }
    // 00489380  66c74424022100         -mov word ptr [esp + 2], 0x21
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = 33 /*0x21*/;
L_0x00489387:
    // 00489387  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00489389  7e1e                   -jle 0x4893a9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004893a9;
    }
    // 0048938b  8d0c8500000000         -lea ecx, [eax*4]
    cpu.ecx = x86::reg32(cpu.eax * 4);
    // 00489392  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00489395  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489397  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00489399  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
L_0x0048939c:
    // 0048939c  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048939f  8988c8e15100           -mov dword ptr [eax + 0x51e1c8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5366216) /* 0x51e1c8 */) = cpu.ecx;
    // 004893a5  39d0                   +cmp eax, edx
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
    // 004893a7  7cf3                   -jl 0x48939c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048939c;
    }
L_0x004893a9:
    // 004893a9  46                     -inc esi
    (cpu.esi)++;
    // 004893aa  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004893ad  83fe60                 +cmp esi, 0x60
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
    // 004893b0  7c92                   -jl 0x489344
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489344;
    }
    // 004893b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004893b3  be20000000             -mov esi, 0x20
    cpu.esi = 32 /*0x20*/;
    // 004893b8  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 004893ba  6689742406             -mov word ptr [esp + 6], si
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(6) /* 0x6 */) = cpu.si;
    // 004893bf  66897c2404             -mov word ptr [esp + 4], di
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.di;
    // 004893c4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004893c6  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004893ca  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x004893cb:
    // 004893cb  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004893ce  8990c8e15100           -mov dword ptr [eax + 0x51e1c8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5366216) /* 0x51e1c8 */) = cpu.edx;
    // 004893d4  3d80000000             +cmp eax, 0x80
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
    // 004893d9  75f0                   -jne 0x4893cb
    if (!cpu.flags.zf)
    {
        goto L_0x004893cb;
    }
    // 004893db  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004893dd:
    // 004893dd  668b83ccb94c00         -mov ax, word ptr [ebx + 0x4cb9cc]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(5028300) /* 0x4cb9cc */);
    // 004893e4  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004893e6  6689442402             -mov word ptr [esp + 2], ax
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */) = cpu.ax;
    // 004893eb  ba09000000             -mov edx, 9
    cpu.edx = 9 /*0x9*/;
    // 004893f0  668b4c2402             -mov cx, word ptr [esp + 2]
    cpu.cx = app->getMemory<x86::reg16>(cpu.esp + x86::reg32(2) /* 0x2 */);
    // 004893f5  668b83d0b94c00         -mov ax, word ptr [ebx + 0x4cb9d0]
    cpu.ax = app->getMemory<x86::reg16>(cpu.ebx + x86::reg32(5028304) /* 0x4cb9d0 */);
    // 004893fc  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004893fe  66890424               -mov word ptr [esp], ax
    app->getMemory<x86::reg16>(cpu.esp) = cpu.ax;
    // 00489402  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00489404  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 00489409  8b83d8b94c00           -mov eax, dword ptr [ebx + 0x4cb9d8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5028312) /* 0x4cb9d8 */);
    // 0048940f  d3e2                   -shl edx, cl
    cpu.edx <<= cpu.cl % 32;
    // 00489411  c1e807                 -shr eax, 7
    cpu.eax >>= 7 /*0x7*/ % 32;
    // 00489414  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00489416  7e1e                   -jle 0x489436
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00489436;
    }
    // 00489418  8b0c24                 -mov ecx, dword ptr [esp]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048941b  8d348500000000         -lea esi, [eax*4]
    cpu.esi = x86::reg32(cpu.eax * 4);
    // 00489422  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00489425  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00489427  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
L_0x00489429:
    // 00489429  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048942c  8988c8615200           -mov dword ptr [eax + 0x5261c8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5398984) /* 0x5261c8 */) = cpu.ecx;
    // 00489432  39d0                   +cmp eax, edx
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
    // 00489434  7cf3                   -jl 0x489429
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489429;
    }
L_0x00489436:
    // 00489436  83c310                 -add ebx, 0x10
    (cpu.ebx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00489439  81fb00080000           +cmp ebx, 0x800
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
    // 0048943f  759c                   -jne 0x4893dd
    if (!cpu.flags.zf)
    {
        goto L_0x004893dd;
    }
    // 00489441  c705cc6f520001000000   -mov dword ptr [0x526fcc], 1
    app->getMemory<x86::reg32>(x86::reg32(5402572) /* 0x526fcc */) = 1 /*0x1*/;
    // 0048944b  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048944e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048944f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489450  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489451  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489452  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489453:
    // 00489453  83f83f                 +cmp eax, 0x3f
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
    // 00489456  0f8ecbfeffff           -jle 0x489327
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00489327;
    }
    // 0048945c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048945e  e9c4feffff             -jmp 0x489327
    goto L_0x00489327;
}

/* align: skip 0x90 */
void Application::sub_489464(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489464  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489465  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489466  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489467  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00489469  a17c1b4d00             -mov eax, dword ptr [0x4d1b7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5053308) /* 0x4d1b7c */);
    // 0048946e  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 00489473  a3cc695200             -mov dword ptr [0x5269cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5401036) /* 0x5269cc */) = cpu.eax;
L_0x00489478:
    // 00489478  8b81ccc14c00           -mov eax, dword ptr [ecx + 0x4cc1cc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5030348) /* 0x4cc1cc */);
    // 0048947e  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00489481  8b917c1b4d00           -mov edx, dword ptr [ecx + 0x4d1b7c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5053308) /* 0x4d1b7c */);
    // 00489487  c1e00c                 -shl eax, 0xc
    cpu.eax <<= 12 /*0xc*/ % 32;
    // 0048948a  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048948d  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0048948f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00489492  c1e810                 +shr eax, 0x10
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
    // 00489495  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00489497  8981c8695200           -mov dword ptr [ecx + 0x5269c8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5401032) /* 0x5269c8 */) = cpu.eax;
    // 0048949d  81f900010000           +cmp ecx, 0x100
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
    // 004894a3  75d3                   -jne 0x489478
    if (!cpu.flags.zf)
    {
        goto L_0x00489478;
    }
    // 004894a5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004894a6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004894a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004894a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4894ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004894ac  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004894ad  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004894af  833dcc6f520000         +cmp dword ptr [0x526fcc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5402572) /* 0x526fcc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004894b6  7409                   -je 0x4894c1
    if (cpu.flags.zf)
    {
        goto L_0x004894c1;
    }
    // 004894b8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004894ba  e88d690100             -call 0x49fe4c
    cpu.esp -= 4;
    sub_49fe4c(app, cpu);
    if (cpu.terminate) return;
    // 004894bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004894c0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004894c1:
    // 004894c1  e83efeffff             -call 0x489304
    cpu.esp -= 4;
    sub_489304(app, cpu);
    if (cpu.terminate) return;
    // 004894c6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004894c8  e87f690100             -call 0x49fe4c
    cpu.esp -= 4;
    sub_49fe4c(app, cpu);
    if (cpu.terminate) return;
    // 004894cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004894ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4894d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004894d0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004894d1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004894d2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004894d3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004894d4  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004894d7  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004894d9  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004894db  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 004894de  833dcc6f520000         +cmp dword ptr [0x526fcc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5402572) /* 0x526fcc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004894e5  0f842d020000           -je 0x489718
    if (cpu.flags.zf)
    {
        goto L_0x00489718;
    }
L_0x004894eb:
    // 004894eb  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 004894ed  e86a6a0100             -call 0x49ff5c
    cpu.esp -= 4;
    sub_49ff5c(app, cpu);
    if (cpu.terminate) return;
    // 004894f2  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004894f4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004894f6  83f802                 +cmp eax, 2
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
    // 004894f9  0f8523020000           -jne 0x489722
    if (!cpu.flags.zf)
    {
        goto L_0x00489722;
    }
    // 004894ff  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 00489504  b8ccdf5100             -mov eax, 0x51dfcc
    cpu.eax = 5365708 /*0x51dfcc*/;
    // 00489509  e8c2fdffff             -call 0x4892d0
    cpu.esp -= 4;
    sub_4892d0(app, cpu);
    if (cpu.terminate) return;
L_0x0048950e:
    // 0048950e  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00489510  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 00489513  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00489515  e8426a0100             -call 0x49ff5c
    cpu.esp -= 4;
    sub_49ff5c(app, cpu);
    if (cpu.terminate) return;
    // 0048951a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048951c  83f802                 +cmp eax, 2
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
    // 0048951f  0f8511020000           -jne 0x489736
    if (!cpu.flags.zf)
    {
        goto L_0x00489736;
    }
    // 00489525  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0048952a  b8cce05100             -mov eax, 0x51e0cc
    cpu.eax = 5365964 /*0x51e0cc*/;
    // 0048952f  e89cfdffff             -call 0x4892d0
    cpu.esp -= 4;
    sub_4892d0(app, cpu);
    if (cpu.terminate) return;
L_0x00489534:
    // 00489534  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00489536  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 00489539  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048953b  e81c6a0100             -call 0x49ff5c
    cpu.esp -= 4;
    sub_49ff5c(app, cpu);
    if (cpu.terminate) return;
    // 00489540  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00489542  83f802                 +cmp eax, 2
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
    // 00489545  0f85ff010000           -jne 0x48974a
    if (!cpu.flags.zf)
    {
        goto L_0x0048974a;
    }
    // 0048954b  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00489550  b8cc6b5200             -mov eax, 0x526bcc
    cpu.eax = 5401548 /*0x526bcc*/;
    // 00489555  e876fdffff             -call 0x4892d0
    cpu.esp -= 4;
    sub_4892d0(app, cpu);
    if (cpu.terminate) return;
L_0x0048955a:
    // 0048955a  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048955c  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 0048955f  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00489561  e8f6690100             -call 0x49ff5c
    cpu.esp -= 4;
    sub_49ff5c(app, cpu);
    if (cpu.terminate) return;
    // 00489566  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00489568  83f802                 +cmp eax, 2
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
    // 0048956b  0f85ed010000           -jne 0x48975e
    if (!cpu.flags.zf)
    {
        goto L_0x0048975e;
    }
    // 00489571  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00489576  b8ec6b5200             -mov eax, 0x526bec
    cpu.eax = 5401580 /*0x526bec*/;
    // 0048957b  e850fdffff             -call 0x4892d0
    cpu.esp -= 4;
    sub_4892d0(app, cpu);
    if (cpu.terminate) return;
L_0x00489580:
    // 00489580  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 00489582  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 00489585  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 00489587  e8d0690100             -call 0x49ff5c
    cpu.esp -= 4;
    sub_49ff5c(app, cpu);
    if (cpu.terminate) return;
    // 0048958c  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048958e  83f802                 +cmp eax, 2
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
    // 00489591  0f85db010000           -jne 0x489772
    if (!cpu.flags.zf)
    {
        goto L_0x00489772;
    }
    // 00489597  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0048959c  b8cc6d5200             -mov eax, 0x526dcc
    cpu.eax = 5402060 /*0x526dcc*/;
    // 004895a1  e82afdffff             -call 0x4892d0
    cpu.esp -= 4;
    sub_4892d0(app, cpu);
    if (cpu.terminate) return;
L_0x004895a6:
    // 004895a6  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004895a8  8d0436                 -lea eax, [esi + esi]
    cpu.eax = x86::reg32(cpu.esi + cpu.esi * 1);
    // 004895ab  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 004895ad  e8aa690100             -call 0x49ff5c
    cpu.esp -= 4;
    sub_49ff5c(app, cpu);
    if (cpu.terminate) return;
    // 004895b2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004895b4  83f802                 +cmp eax, 2
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
    // 004895b7  0f85c9010000           -jne 0x489786
    if (!cpu.flags.zf)
    {
        goto L_0x00489786;
    }
    // 004895bd  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 004895c2  b8ec6d5200             -mov eax, 0x526dec
    cpu.eax = 5402092 /*0x526dec*/;
    // 004895c7  e804fdffff             -call 0x4892d0
    cpu.esp -= 4;
    sub_4892d0(app, cpu);
    if (cpu.terminate) return;
L_0x004895cc:
    // 004895cc  baccdf5100             -mov edx, 0x51dfcc
    cpu.edx = 5365708 /*0x51dfcc*/;
    // 004895d1  b8cc6b5200             -mov eax, 0x526bcc
    cpu.eax = 5401548 /*0x526bcc*/;
    // 004895d6  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004895d8  e8116a0100             -call 0x49ffee
    cpu.esp -= 4;
    sub_49ffee(app, cpu);
    if (cpu.terminate) return;
    // 004895dd  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004895e0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004895e2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004895e5  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004895e7  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 004895e9  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 004895eb  8d3c8500000000         -lea edi, [eax*4]
    cpu.edi = x86::reg32(cpu.eax * 4);
    // 004895f2  baccdf5100             -mov edx, 0x51dfcc
    cpu.edx = 5365708 /*0x51dfcc*/;
    // 004895f7  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004895f9  b80c6c5200             -mov eax, 0x526c0c
    cpu.eax = 5401612 /*0x526c0c*/;
    // 004895fe  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00489600  e8e9690100             -call 0x49ffee
    cpu.esp -= 4;
    sub_49ffee(app, cpu);
    if (cpu.terminate) return;
    // 00489605  baecdf5100             -mov edx, 0x51dfec
    cpu.edx = 5365740 /*0x51dfec*/;
    // 0048960a  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048960c  b84c6c5200             -mov eax, 0x526c4c
    cpu.eax = 5401676 /*0x526c4c*/;
    // 00489611  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00489613  e8d6690100             -call 0x49ffee
    cpu.esp -= 4;
    sub_49ffee(app, cpu);
    if (cpu.terminate) return;
    // 00489618  baecdf5100             -mov edx, 0x51dfec
    cpu.edx = 5365740 /*0x51dfec*/;
    // 0048961d  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048961f  b88c6c5200             -mov eax, 0x526c8c
    cpu.eax = 5401740 /*0x526c8c*/;
    // 00489624  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00489626  e8c3690100             -call 0x49ffee
    cpu.esp -= 4;
    sub_49ffee(app, cpu);
    if (cpu.terminate) return;
    // 0048962b  ba0ce05100             -mov edx, 0x51e00c
    cpu.edx = 5365772 /*0x51e00c*/;
    // 00489630  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00489632  b8cc6c5200             -mov eax, 0x526ccc
    cpu.eax = 5401804 /*0x526ccc*/;
    // 00489637  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00489639  e8b0690100             -call 0x49ffee
    cpu.esp -= 4;
    sub_49ffee(app, cpu);
    if (cpu.terminate) return;
    // 0048963e  ba0ce05100             -mov edx, 0x51e00c
    cpu.edx = 5365772 /*0x51e00c*/;
    // 00489643  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00489645  b80c6d5200             -mov eax, 0x526d0c
    cpu.eax = 5401868 /*0x526d0c*/;
    // 0048964a  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048964c  e89d690100             -call 0x49ffee
    cpu.esp -= 4;
    sub_49ffee(app, cpu);
    if (cpu.terminate) return;
    // 00489651  ba2ce05100             -mov edx, 0x51e02c
    cpu.edx = 5365804 /*0x51e02c*/;
    // 00489656  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00489658  b84c6d5200             -mov eax, 0x526d4c
    cpu.eax = 5401932 /*0x526d4c*/;
    // 0048965d  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0048965f  e88a690100             -call 0x49ffee
    cpu.esp -= 4;
    sub_49ffee(app, cpu);
    if (cpu.terminate) return;
    // 00489664  ba2ce05100             -mov edx, 0x51e02c
    cpu.edx = 5365804 /*0x51e02c*/;
    // 00489669  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048966b  b88c6d5200             -mov eax, 0x526d8c
    cpu.eax = 5401996 /*0x526d8c*/;
    // 00489670  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00489672  e877690100             -call 0x49ffee
    cpu.esp -= 4;
    sub_49ffee(app, cpu);
    if (cpu.terminate) return;
    // 00489677  ba4ce05100             -mov edx, 0x51e04c
    cpu.edx = 5365836 /*0x51e04c*/;
    // 0048967c  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048967e  b8cc6d5200             -mov eax, 0x526dcc
    cpu.eax = 5402060 /*0x526dcc*/;
    // 00489683  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00489685  e864690100             -call 0x49ffee
    cpu.esp -= 4;
    sub_49ffee(app, cpu);
    if (cpu.terminate) return;
    // 0048968a  ba4ce05100             -mov edx, 0x51e04c
    cpu.edx = 5365836 /*0x51e04c*/;
    // 0048968f  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00489691  b80c6e5200             -mov eax, 0x526e0c
    cpu.eax = 5402124 /*0x526e0c*/;
    // 00489696  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00489698  e851690100             -call 0x49ffee
    cpu.esp -= 4;
    sub_49ffee(app, cpu);
    if (cpu.terminate) return;
    // 0048969d  ba6ce05100             -mov edx, 0x51e06c
    cpu.edx = 5365868 /*0x51e06c*/;
    // 004896a2  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004896a4  b84c6e5200             -mov eax, 0x526e4c
    cpu.eax = 5402188 /*0x526e4c*/;
    // 004896a9  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004896ab  e83e690100             -call 0x49ffee
    cpu.esp -= 4;
    sub_49ffee(app, cpu);
    if (cpu.terminate) return;
    // 004896b0  ba6ce05100             -mov edx, 0x51e06c
    cpu.edx = 5365868 /*0x51e06c*/;
    // 004896b5  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004896b7  b88c6e5200             -mov eax, 0x526e8c
    cpu.eax = 5402252 /*0x526e8c*/;
    // 004896bc  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004896be  e82b690100             -call 0x49ffee
    cpu.esp -= 4;
    sub_49ffee(app, cpu);
    if (cpu.terminate) return;
    // 004896c3  ba8ce05100             -mov edx, 0x51e08c
    cpu.edx = 5365900 /*0x51e08c*/;
    // 004896c8  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004896ca  b8cc6e5200             -mov eax, 0x526ecc
    cpu.eax = 5402316 /*0x526ecc*/;
    // 004896cf  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004896d1  e818690100             -call 0x49ffee
    cpu.esp -= 4;
    sub_49ffee(app, cpu);
    if (cpu.terminate) return;
    // 004896d6  ba8ce05100             -mov edx, 0x51e08c
    cpu.edx = 5365900 /*0x51e08c*/;
    // 004896db  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004896dd  b80c6f5200             -mov eax, 0x526f0c
    cpu.eax = 5402380 /*0x526f0c*/;
    // 004896e2  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004896e4  e805690100             -call 0x49ffee
    cpu.esp -= 4;
    sub_49ffee(app, cpu);
    if (cpu.terminate) return;
    // 004896e9  baace05100             -mov edx, 0x51e0ac
    cpu.edx = 5365932 /*0x51e0ac*/;
    // 004896ee  01f9                   -add ecx, edi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004896f0  b84c6f5200             -mov eax, 0x526f4c
    cpu.eax = 5402444 /*0x526f4c*/;
    // 004896f5  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 004896f7  e8f2680100             -call 0x49ffee
    cpu.esp -= 4;
    sub_49ffee(app, cpu);
    if (cpu.terminate) return;
    // 004896fc  baace05100             -mov edx, 0x51e0ac
    cpu.edx = 5365932 /*0x51e0ac*/;
    // 00489701  b88c6f5200             -mov eax, 0x526f8c
    cpu.eax = 5402508 /*0x526f8c*/;
    // 00489706  8d1c39                 -lea ebx, [ecx + edi]
    cpu.ebx = x86::reg32(cpu.ecx + cpu.edi * 1);
    // 00489709  e8e0680100             -call 0x49ffee
    cpu.esp -= 4;
    sub_49ffee(app, cpu);
    if (cpu.terminate) return;
    // 0048970e  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00489710  83c404                 +add esp, 4
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
    // 00489713  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489714  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489715  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489716  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489717  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489718:
    // 00489718  e8e7fbffff             -call 0x489304
    cpu.esp -= 4;
    sub_489304(app, cpu);
    if (cpu.terminate) return;
    // 0048971d  e9c9fdffff             -jmp 0x4894eb
    goto L_0x004894eb;
L_0x00489722:
    // 00489722  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 00489727  b8ccdf5100             -mov eax, 0x51dfcc
    cpu.eax = 5365708 /*0x51dfcc*/;
    // 0048972c  e890650100             -call 0x49fcc1
    cpu.esp -= 4;
    sub_49fcc1(app, cpu);
    if (cpu.terminate) return;
    // 00489731  e9d8fdffff             -jmp 0x48950e
    goto L_0x0048950e;
L_0x00489736:
    // 00489736  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 0048973b  b8cce05100             -mov eax, 0x51e0cc
    cpu.eax = 5365964 /*0x51e0cc*/;
    // 00489740  e87c650100             -call 0x49fcc1
    cpu.esp -= 4;
    sub_49fcc1(app, cpu);
    if (cpu.terminate) return;
    // 00489745  e9eafdffff             -jmp 0x489534
    goto L_0x00489534;
L_0x0048974a:
    // 0048974a  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0048974f  b8cc6b5200             -mov eax, 0x526bcc
    cpu.eax = 5401548 /*0x526bcc*/;
    // 00489754  e868650100             -call 0x49fcc1
    cpu.esp -= 4;
    sub_49fcc1(app, cpu);
    if (cpu.terminate) return;
    // 00489759  e9fcfdffff             -jmp 0x48955a
    goto L_0x0048955a;
L_0x0048975e:
    // 0048975e  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00489763  b8ec6b5200             -mov eax, 0x526bec
    cpu.eax = 5401580 /*0x526bec*/;
    // 00489768  e854650100             -call 0x49fcc1
    cpu.esp -= 4;
    sub_49fcc1(app, cpu);
    if (cpu.terminate) return;
    // 0048976d  e90efeffff             -jmp 0x489580
    goto L_0x00489580;
L_0x00489772:
    // 00489772  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 00489777  b8cc6d5200             -mov eax, 0x526dcc
    cpu.eax = 5402060 /*0x526dcc*/;
    // 0048977c  e840650100             -call 0x49fcc1
    cpu.esp -= 4;
    sub_49fcc1(app, cpu);
    if (cpu.terminate) return;
    // 00489781  e920feffff             -jmp 0x4895a6
    goto L_0x004895a6;
L_0x00489786:
    // 00489786  ba10000000             -mov edx, 0x10
    cpu.edx = 16 /*0x10*/;
    // 0048978b  b8ec6d5200             -mov eax, 0x526dec
    cpu.eax = 5402092 /*0x526dec*/;
    // 00489790  e82c650100             -call 0x49fcc1
    cpu.esp -= 4;
    sub_49fcc1(app, cpu);
    if (cpu.terminate) return;
    // 00489795  e932feffff             -jmp 0x4895cc
    goto L_0x004895cc;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4897a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004897a0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004897a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_4897a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004897a4  a3ccc24c00             -mov dword ptr [0x4cc2cc], eax
    app->getMemory<x86::reg32>(x86::reg32(5030604) /* 0x4cc2cc */) = cpu.eax;
    // 004897a9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4897ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004897ac  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004897ad  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004897af  8b15ccc24c00           -mov edx, dword ptr [0x4cc2cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030604) /* 0x4cc2cc */);
    // 004897b5  a3e4c24c00             -mov dword ptr [0x4cc2e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */) = cpu.eax;
    // 004897ba  a3e0c24c00             -mov dword ptr [0x4cc2e0], eax
    app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */) = cpu.eax;
    // 004897bf  05c0000000             -add eax, 0xc0
    (cpu.eax) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 004897c4  e80f210000             -call 0x48b8d8
    cpu.esp -= 4;
    sub_48b8d8(app, cpu);
    if (cpu.terminate) return;
    // 004897c9  8b8684000000           -mov eax, dword ptr [esi + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 004897cf  89463c                 -mov dword ptr [esi + 0x3c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(60) /* 0x3c */) = cpu.eax;
    // 004897d2  8b8688000000           -mov eax, dword ptr [esi + 0x88]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 004897d8  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004897db  8b9688000000           -mov edx, dword ptr [esi + 0x88]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 004897e1  8b8684000000           -mov eax, dword ptr [esi + 0x84]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */);
    // 004897e7  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004897e9  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 004897ec  894e2c                 -mov dword ptr [esi + 0x2c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(44) /* 0x2c */) = cpu.ecx;
    // 004897ef  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004897f2  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004897f5  8b4618                 -mov eax, dword ptr [esi + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004897f8  894614                 -mov dword ptr [esi + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 004897fb  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004897fe  89460c                 -mov dword ptr [esi + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00489801  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00489804  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00489807  c7462800000000         -mov dword ptr [esi + 0x28], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 0048980e  895e40                 -mov dword ptr [esi + 0x40], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(64) /* 0x40 */) = cpu.ebx;
    // 00489811  c7461c00000000         -mov dword ptr [esi + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 00489818  c7467000000000         -mov dword ptr [esi + 0x70], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(112) /* 0x70 */) = 0 /*0x0*/;
    // 0048981f  c7467800000000         -mov dword ptr [esi + 0x78], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = 0 /*0x0*/;
    // 00489826  8b4678                 -mov eax, dword ptr [esi + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 00489829  89467c                 -mov dword ptr [esi + 0x7c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.eax;
    // 0048982c  c7462007000000         -mov dword ptr [esi + 0x20], 7
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 00489833  c7462400000000         -mov dword ptr [esi + 0x24], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 0 /*0x0*/;
    // 0048983a  c7463800000000         -mov dword ptr [esi + 0x38], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */) = 0 /*0x0*/;
    // 00489841  8b4638                 -mov eax, dword ptr [esi + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(56) /* 0x38 */);
    // 00489844  894634                 -mov dword ptr [esi + 0x34], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 00489847  c786bc00000000000000   -mov dword ptr [esi + 0xbc], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */) = 0 /*0x0*/;
    // 00489851  8b86bc000000           -mov eax, dword ptr [esi + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(188) /* 0xbc */);
    // 00489857  8986b8000000           -mov dword ptr [esi + 0xb8], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(184) /* 0xb8 */) = cpu.eax;
    // 0048985d  c7463000000000         -mov dword ptr [esi + 0x30], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 00489864  e82372ffff             -call 0x480a8c
    cpu.esp -= 4;
    sub_480a8c(app, cpu);
    if (cpu.terminate) return;
    // 00489869  8986a4000000           -mov dword ptr [esi + 0xa4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(164) /* 0xa4 */) = cpu.eax;
    // 0048986f  e80473ffff             -call 0x480b78
    cpu.esp -= 4;
    sub_480b78(app, cpu);
    if (cpu.terminate) return;
    // 00489874  8986ac000000           -mov dword ptr [esi + 0xac], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */) = cpu.eax;
    // 0048987a  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 0048987f  8d868c000000           -lea eax, [esi + 0x8c]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 00489885  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0048988a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048988b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048988d  b858a24800             -mov eax, 0x48a258
    cpu.eax = 4760152 /*0x48a258*/;
    // 00489892  e8c96effff             -call 0x480760
    cpu.esp -= 4;
    sub_480760(app, cpu);
    if (cpu.terminate) return;
    // 00489897  8b86a4000000           -mov eax, dword ptr [esi + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(164) /* 0xa4 */);
    // 0048989d  e83a72ffff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 004898a2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004898a4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4898a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004898a8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004898a9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004898ab  e8fcfeffff             -call 0x4897ac
    cpu.esp -= 4;
    sub_4897ac(app, cpu);
    if (cpu.terminate) return;
    // 004898b0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4898b4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004898b4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004898b5  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004898ba  e8edfeffff             -call 0x4897ac
    cpu.esp -= 4;
    sub_4897ac(app, cpu);
    if (cpu.terminate) return;
    // 004898bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004898c0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_4898c4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004898c4  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004898c5  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004898c6  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004898c7  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004898ca  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004898ce  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004898d0  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004898d2  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004898d4  66a9ff0f               +test ax, 0xfff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.ax & 4095 /*0xfff*/));
    // 004898d8  740c                   -je 0x4898e6
    if (cpu.flags.zf)
    {
        goto L_0x004898e6;
    }
    // 004898da  8db800100000           -lea edi, [eax + 0x1000]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(4096) /* 0x1000 */);
    // 004898e0  81e700f0ff7f           -and edi, 0x7ffff000
    cpu.edi &= x86::reg32(x86::sreg32(2147479552 /*0x7ffff000*/));
L_0x004898e6:
    // 004898e6  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 004898eb  b8180a4c00             -mov eax, 0x4c0a18
    cpu.eax = 4983320 /*0x4c0a18*/;
    // 004898f0  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 004898f2  e84909ffff             -call 0x47a240
    cpu.esp -= 4;
    sub_47a240(app, cpu);
    if (cpu.terminate) return;
    // 004898f7  8b15ccc24c00           -mov edx, dword ptr [0x4cc2cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030604) /* 0x4cc2cc */);
    // 004898fd  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00489900  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00489907  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00489909  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048990c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048990e  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00489915  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 00489917  83c20f                 -add edx, 0xf
    (cpu.edx) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0048991a  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0048991c  81e2f0ff0000           -and edx, 0xfff0
    cpu.edx &= x86::reg32(x86::sreg32(65520 /*0xfff0*/));
    // 00489922  b8400a4c00             -mov eax, 0x4c0a40
    cpu.eax = 4983360 /*0x4c0a40*/;
    // 00489927  81c2c0000000           -add edx, 0xc0
    (cpu.edx) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 0048992d  e82209ffff             -call 0x47a254
    cpu.esp -= 4;
    sub_47a254(app, cpu);
    if (cpu.terminate) return;
    // 00489932  8b15ccc24c00           -mov edx, dword ptr [0x4cc2cc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030604) /* 0x4cc2cc */);
    // 00489938  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048993a  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00489941  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00489943  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00489946  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00489948  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 0048994f  83c20f                 -add edx, 0xf
    (cpu.edx) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 00489952  81e2f0ff0000           -and edx, 0xfff0
    cpu.edx &= x86::reg32(x86::sreg32(65520 /*0xfff0*/));
    // 00489958  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048995a  81c2c0000000           -add edx, 0xc0
    (cpu.edx) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 00489960  e83773ffff             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 00489965  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00489968  898688000000           -mov dword ptr [esi + 0x88], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */) = cpu.eax;
    // 0048996e  89be84000000           -mov dword ptr [esi + 0x84], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.edi;
    // 00489974  bb00100000             -mov ebx, 0x1000
    cpu.ebx = 4096 /*0x1000*/;
    // 00489979  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048997b  e880b90000             -call 0x495300
    cpu.esp -= 4;
    sub_495300(app, cpu);
    if (cpu.terminate) return;
    // 00489980  8b3dccc24c00           -mov edi, dword ptr [0x4cc2cc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5030604) /* 0x4cc2cc */);
    // 00489986  8d14bd00000000         -lea edx, [edi*4]
    cpu.edx = x86::reg32(cpu.edi * 4);
    // 0048998d  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048998f  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 00489992  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00489994  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00489997  83c20f                 -add edx, 0xf
    (cpu.edx) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0048999a  bb00100000             -mov ebx, 0x1000
    cpu.ebx = 4096 /*0x1000*/;
    // 0048999f  81e2f0ff0000           -and edx, 0xfff0
    cpu.edx &= x86::reg32(x86::sreg32(65520 /*0xfff0*/));
    // 004899a5  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004899a7  81c2c0000000           -add edx, 0xc0
    (cpu.edx) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 004899ad  e84eb90000             -call 0x495300
    cpu.esp -= 4;
    sub_495300(app, cpu);
    if (cpu.terminate) return;
    // 004899b2  8b3dccc24c00           -mov edi, dword ptr [0x4cc2cc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5030604) /* 0x4cc2cc */);
    // 004899b8  8d14bd00000000         -lea edx, [edi*4]
    cpu.edx = x86::reg32(cpu.edi * 4);
    // 004899bf  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 004899c1  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 004899c4  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004899c6  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004899c9  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 004899cb  83c20f                 -add edx, 0xf
    (cpu.edx) += x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004899ce  8b5c2404               -mov ebx, dword ptr [esp + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004899d2  81e2f0ff0000           -and edx, 0xfff0
    cpu.edx &= x86::reg32(x86::sreg32(65520 /*0xfff0*/));
    // 004899d8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004899da  81c2c0000000           -add edx, 0xc0
    (cpu.edx) += x86::reg32(x86::sreg32(192 /*0xc0*/));
    // 004899e0  e8c7fdffff             -call 0x4897ac
    cpu.esp -= 4;
    sub_4897ac(app, cpu);
    if (cpu.terminate) return;
    // 004899e5  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004899e8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004899e9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004899ea  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004899eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4899ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004899ec  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004899ed  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004899ef  e8d0feffff             -call 0x4898c4
    cpu.esp -= 4;
    sub_4898c4(app, cpu);
    if (cpu.terminate) return;
    // 004899f4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004899f5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_4899f8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004899f8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004899f9  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004899fe  e8c1feffff             -call 0x4898c4
    cpu.esp -= 4;
    sub_4898c4(app, cpu);
    if (cpu.terminate) return;
    // 00489a03  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489a04  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489a08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489a08  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489a09  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489a0a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489a0b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489a0c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00489a0d  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00489a10  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00489a12  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00489a14  e897fafeff             -call 0x4794b0
    cpu.esp -= 4;
    sub_4794b0(app, cpu);
    if (cpu.terminate) return;
    // 00489a19  8d4c2408               -lea ecx, [esp + 8]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00489a1d  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00489a1f  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 00489a23  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00489a27  8d5c2410               -lea ebx, [esp + 0x10]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00489a2b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489a2c  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00489a30  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00489a32  e849680100             -call 0x4a0280
    cpu.esp -= 4;
    sub_4a0280(app, cpu);
    if (cpu.terminate) return;
    // 00489a37  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00489a39  0f8590000000           -jne 0x489acf
    if (!cpu.flags.zf)
    {
        goto L_0x00489acf;
    }
    // 00489a3f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00489a42  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00489a46  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00489a4a  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 00489a4e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00489a52  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00489a56:
    // 00489a56  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00489a5a  2d00200000             -sub eax, 0x2000
    (cpu.eax) -= x86::reg32(x86::sreg32(8192 /*0x2000*/));
    // 00489a5f  662500e0               -and ax, 0xe000
    cpu.ax &= x86::reg16(x86::sreg16(57344 /*0xe000*/));
    // 00489a63  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00489a67  3d00000400             +cmp eax, 0x40000
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
    // 00489a6c  0f8f7a000000           -jg 0x489aec
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00489aec;
    }
L_0x00489a72:
    // 00489a72  ba00200000             -mov edx, 0x2000
    cpu.edx = 8192 /*0x2000*/;
    // 00489a77  b8ac0a4c00             -mov eax, 0x4c0aac
    cpu.eax = 4983468 /*0x4c0aac*/;
    // 00489a7c  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00489a7e  e8a507ffff             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 00489a83  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00489a85  b800200000             -mov eax, 0x2000
    cpu.eax = 8192 /*0x2000*/;
    // 00489a8a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489a8c  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00489a90  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00489a93  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00489a95  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x00489a97:
    // 00489a97  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00489a9a  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00489a9c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00489a9e  e869680100             -call 0x4a030c
    cpu.esp -= 4;
    sub_4a030c(app, cpu);
    if (cpu.terminate) return;
    // 00489aa3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489aa5  74f0                   -je 0x489a97
    if (cpu.flags.zf)
    {
        goto L_0x00489a97;
    }
    // 00489aa7  e8cbf3feff             -call 0x478e77
    cpu.esp -= 4;
    sub_478e77(app, cpu);
    if (cpu.terminate) return;
    // 00489aac  8b7c2408               -mov edi, dword ptr [esp + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00489ab0  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00489ab2  7e4f                   -jle 0x489b03
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00489b03;
    }
    // 00489ab4  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00489ab6:
    // 00489ab6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00489ab9  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00489abb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00489abd  e84a680100             -call 0x4a030c
    cpu.esp -= 4;
    sub_4a030c(app, cpu);
    if (cpu.terminate) return;
    // 00489ac2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489ac4  7533                   -jne 0x489af9
    if (!cpu.flags.zf)
    {
        goto L_0x00489af9;
    }
    // 00489ac6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00489ac8  e87301ffff             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 00489acd  ebe7                   -jmp 0x489ab6
    goto L_0x00489ab6;
L_0x00489acf:
    // 00489acf  8d442418               -lea eax, [esp + 0x18]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00489ad3  8d4c240c               -lea ecx, [esp + 0xc]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00489ad7  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00489adb  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00489adc  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00489ae0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00489ae2  e899670100             -call 0x4a0280
    cpu.esp -= 4;
    sub_4a0280(app, cpu);
    if (cpu.terminate) return;
    // 00489ae7  e96affffff             -jmp 0x489a56
    goto L_0x00489a56;
L_0x00489aec:
    // 00489aec  c744240800000400       -mov dword ptr [esp + 8], 0x40000
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = 262144 /*0x40000*/;
    // 00489af4  e979ffffff             -jmp 0x489a72
    goto L_0x00489a72;
L_0x00489af9:
    // 00489af9  81ef00200000           -sub edi, 0x2000
    (cpu.edi) -= x86::reg32(x86::sreg32(8192 /*0x2000*/));
    // 00489aff  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00489b01  7fb3                   -jg 0x489ab6
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00489ab6;
    }
L_0x00489b03:
    // 00489b03  e86ff3feff             -call 0x478e77
    cpu.esp -= 4;
    sub_478e77(app, cpu);
    if (cpu.terminate) return;
    // 00489b08  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00489b0a  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x00489b0c:
    // 00489b0c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00489b10  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 00489b12  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00489b14  e8f3670100             -call 0x4a030c
    cpu.esp -= 4;
    sub_4a030c(app, cpu);
    if (cpu.terminate) return;
    // 00489b19  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489b1b  7509                   -jne 0x489b26
    if (!cpu.flags.zf)
    {
        goto L_0x00489b26;
    }
    // 00489b1d  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00489b1f  e81c01ffff             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 00489b24  ebe6                   -jmp 0x489b0c
    goto L_0x00489b0c;
L_0x00489b26:
    // 00489b26  e84cf3feff             -call 0x478e77
    cpu.esp -= 4;
    sub_478e77(app, cpu);
    if (cpu.terminate) return;
    // 00489b2b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00489b2d  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00489b30  e877670100             -call 0x4a02ac
    cpu.esp -= 4;
    sub_4a02ac(app, cpu);
    if (cpu.terminate) return;
    // 00489b35  837c241c00             +cmp dword ptr [esp + 0x1c], 0
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
    // 00489b3a  7409                   -je 0x489b45
    if (cpu.flags.zf)
    {
        goto L_0x00489b45;
    }
    // 00489b3c  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00489b40  e867670100             -call 0x4a02ac
    cpu.esp -= 4;
    sub_4a02ac(app, cpu);
    if (cpu.terminate) return;
L_0x00489b45:
    // 00489b45  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489b47  e8400bffff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00489b4c  8d04bd00000000         -lea eax, [edi*4]
    cpu.eax = x86::reg32(cpu.edi * 4);
    // 00489b53  8d1407                 -lea edx, [edi + eax]
    cpu.edx = x86::reg32(cpu.edi + cpu.eax * 1);
    // 00489b56  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00489b58  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00489b5b  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00489b5f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489b61  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00489b64  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00489b66  a3d06f5200             -mov dword ptr [0x526fd0], eax
    app->getMemory<x86::reg32>(x86::reg32(5402576) /* 0x526fd0 */) = cpu.eax;
    // 00489b6b  83f801                 +cmp eax, 1
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
    // 00489b6e  7d0a                   -jge 0x489b7a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00489b7a;
    }
    // 00489b70  c705d06f520001000000   -mov dword ptr [0x526fd0], 1
    app->getMemory<x86::reg32>(x86::reg32(5402576) /* 0x526fd0 */) = 1 /*0x1*/;
L_0x00489b7a:
    // 00489b7a  b80000e803             -mov eax, 0x3e80000
    cpu.eax = 65536000 /*0x3e80000*/;
    // 00489b7f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489b81  8b0dd06f5200           -mov ecx, dword ptr [0x526fd0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5402576) /* 0x526fd0 */);
    // 00489b87  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00489b8a  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00489b8c  8b4c2408               -mov ecx, dword ptr [esp + 8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00489b90  8d14bd00000000         -lea edx, [edi*4]
    cpu.edx = x86::reg32(cpu.edi * 4);
    // 00489b97  a3d46f5200             -mov dword ptr [0x526fd4], eax
    app->getMemory<x86::reg32>(x86::reg32(5402580) /* 0x526fd4 */) = cpu.eax;
    // 00489b9c  01fa                   -add edx, edi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00489b9e  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00489ba2  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00489ba4  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 00489ba7  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00489baa  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00489bac  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489bae  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00489bb1  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00489bb3  a3d0c24c00             -mov dword ptr [0x4cc2d0], eax
    app->getMemory<x86::reg32>(x86::reg32(5030608) /* 0x4cc2d0 */) = cpu.eax;
    // 00489bb8  3dda000000             +cmp eax, 0xda
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
    // 00489bbd  7f25                   -jg 0x489be4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00489be4;
    }
    // 00489bbf  3da3000000             +cmp eax, 0xa3
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
    // 00489bc4  7c2a                   -jl 0x489bf0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00489bf0;
    }
L_0x00489bc6:
    // 00489bc6  8d049d00000000         -lea eax, [ebx*4]
    cpu.eax = x86::reg32(cpu.ebx * 4);
    // 00489bcd  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00489bcf  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00489bd1  a3d4c24c00             -mov dword ptr [0x4cc2d4], eax
    app->getMemory<x86::reg32>(x86::reg32(5030612) /* 0x4cc2d4 */) = cpu.eax;
    // 00489bd6  a1d46f5200             -mov eax, dword ptr [0x526fd4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5402580) /* 0x526fd4 */);
    // 00489bdb  83c420                 +add esp, 0x20
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
    // 00489bde  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489bdf  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489be0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489be1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489be2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489be3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489be4:
    // 00489be4  c705d0c24c00da000000   -mov dword ptr [0x4cc2d0], 0xda
    app->getMemory<x86::reg32>(x86::reg32(5030608) /* 0x4cc2d0 */) = 218 /*0xda*/;
    // 00489bee  ebd6                   -jmp 0x489bc6
    goto L_0x00489bc6;
L_0x00489bf0:
    // 00489bf0  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00489bf5  890d08ca4c00           -mov dword ptr [0x4cca08], ecx
    app->getMemory<x86::reg32>(x86::reg32(5032456) /* 0x4cca08 */) = cpu.ecx;
    // 00489bfb  890dd0c24c00           -mov dword ptr [0x4cc2d0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5030608) /* 0x4cc2d0 */) = cpu.ecx;
    // 00489c01  ebc3                   -jmp 0x489bc6
    goto L_0x00489bc6;
}

/* align: skip 0x90 */
void Application::sub_489c04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489c04  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489c05  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489c06  bada000000             -mov edx, 0xda
    cpu.edx = 218 /*0xda*/;
    // 00489c0b  b92c010000             -mov ecx, 0x12c
    cpu.ecx = 300 /*0x12c*/;
    // 00489c10  8915d0c24c00           -mov dword ptr [0x4cc2d0], edx
    app->getMemory<x86::reg32>(x86::reg32(5030608) /* 0x4cc2d0 */) = cpu.edx;
    // 00489c16  890dd4c24c00           -mov dword ptr [0x4cc2d4], ecx
    app->getMemory<x86::reg32>(x86::reg32(5030612) /* 0x4cc2d4 */) = cpu.ecx;
    // 00489c1c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489c1d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489c1e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_489c20(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489c20  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489c21  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489c22  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00489c24  8b15e0c24c00           -mov edx, dword ptr [0x4cc2e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 00489c2a  39d0                   +cmp eax, edx
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
    // 00489c2c  7403                   -je 0x489c31
    if (cpu.flags.zf)
    {
        goto L_0x00489c31;
    }
    // 00489c2e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489c2f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489c30  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489c31:
    // 00489c31  c7422408000000         -mov dword ptr [edx + 0x24], 8
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(36) /* 0x24 */) = 8 /*0x8*/;
    // 00489c38  8b92a8000000           -mov edx, dword ptr [edx + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */);
    // 00489c3e  058c000000             -add eax, 0x8c
    (cpu.eax) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 00489c43  e8586effff             -call 0x480aa0
    cpu.esp -= 4;
    sub_480aa0(app, cpu);
    if (cpu.terminate) return;
    // 00489c48  8b81a4000000           -mov eax, dword ptr [ecx + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(164) /* 0xa4 */);
    // 00489c4e  e8896effff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 00489c53  8b81a4000000           -mov eax, dword ptr [ecx + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(164) /* 0xa4 */);
    // 00489c59  e80a6fffff             -call 0x480b68
    cpu.esp -= 4;
    sub_480b68(app, cpu);
    if (cpu.terminate) return;
    // 00489c5e  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 00489c64  e88b6fffff             -call 0x480bf4
    cpu.esp -= 4;
    sub_480bf4(app, cpu);
    if (cpu.terminate) return;
    // 00489c69  c781ac00000000000000   -mov dword ptr [ecx + 0xac], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */) = 0 /*0x0*/;
    // 00489c73  8d818c000000           -lea eax, [ecx + 0x8c]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(140) /* 0x8c */);
    // 00489c79  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489c7b  e8706bffff             -call 0x4807f0
    cpu.esp -= 4;
    sub_4807f0(app, cpu);
    if (cpu.terminate) return;
    // 00489c80  890de0c24c00           -mov dword ptr [0x4cc2e0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */) = cpu.ecx;
    // 00489c86  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489c87  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489c88  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489c8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489c8c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489c8d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00489c8e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00489c8f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00489c91  8b0de0c24c00           -mov ecx, dword ptr [0x4cc2e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 00489c97  39c8                   +cmp eax, ecx
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
    // 00489c99  7440                   -je 0x489cdb
    if (cpu.flags.zf)
    {
        goto L_0x00489cdb;
    }
    // 00489c9b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489c9d  83797000               +cmp dword ptr [ecx + 0x70], 0
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
    // 00489ca1  740e                   -je 0x489cb1
    if (cpu.flags.zf)
    {
        goto L_0x00489cb1;
    }
L_0x00489ca3:
    // 00489ca3  3b5070                 +cmp edx, dword ptr [eax + 0x70]
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
    // 00489ca6  7409                   -je 0x489cb1
    if (cpu.flags.zf)
    {
        goto L_0x00489cb1;
    }
    // 00489ca8  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 00489cab  83787000               +cmp dword ptr [eax + 0x70], 0
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
    // 00489caf  75f2                   -jne 0x489ca3
    if (!cpu.flags.zf)
    {
        goto L_0x00489ca3;
    }
L_0x00489cb1:
    // 00489cb1  8b4a70                 -mov ecx, dword ptr [edx + 0x70]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(112) /* 0x70 */);
    // 00489cb4  894870                 -mov dword ptr [eax + 0x70], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */) = cpu.ecx;
    // 00489cb7  8b8288000000           -mov eax, dword ptr [edx + 0x88]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(136) /* 0x88 */);
    // 00489cbd  e8ca09ffff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00489cc2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489cc4  e8c309ffff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00489cc9  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00489ccb  892de4c24c00           -mov dword ptr [0x4cc2e4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */) = cpu.ebp;
    // 00489cd1  892de0c24c00           -mov dword ptr [0x4cc2e0], ebp
    app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */) = cpu.ebp;
    // 00489cd7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cd8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cd9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489cda  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00489cdb:
    // 00489cdb  e840ffffff             -call 0x489c20
    cpu.esp -= 4;
    sub_489c20(app, cpu);
    if (cpu.terminate) return;
L_0x00489ce0:
    // 00489ce0  8b4970                 -mov ecx, dword ptr [ecx + 0x70]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(112) /* 0x70 */);
    // 00489ce3  8b8288000000           -mov eax, dword ptr [edx + 0x88]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(136) /* 0x88 */);
    // 00489ce9  e89e09ffff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00489cee  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00489cf0  e89709ffff             -call 0x47a68c
    cpu.esp -= 4;
    sub_47a68c(app, cpu);
    if (cpu.terminate) return;
    // 00489cf5  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00489cf7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00489cf9  75e5                   -jne 0x489ce0
    if (!cpu.flags.zf)
    {
        goto L_0x00489ce0;
    }
    // 00489cfb  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
    // 00489cfd  892de4c24c00           -mov dword ptr [0x4cc2e4], ebp
    app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */) = cpu.ebp;
    // 00489d03  892de0c24c00           -mov dword ptr [0x4cc2e0], ebp
    app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */) = cpu.ebp;
    // 00489d09  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489d0a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489d0b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489d0c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489d10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489d10  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489d11  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489d12  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00489d13  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00489d15  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00489d17  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00489d19  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00489d1d  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00489d23  e8a06effff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00489d28  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489d2a  e8c51c0000             -call 0x48b9f4
    cpu.esp -= 4;
    sub_48b9f4(app, cpu);
    if (cpu.terminate) return;
    // 00489d2f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00489d31  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00489d33  746a                   -je 0x489d9f
    if (cpu.flags.zf)
    {
        goto L_0x00489d9f;
    }
    // 00489d35  bb8f000000             -mov ebx, 0x8f
    cpu.ebx = 143 /*0x8f*/;
    // 00489d3a  e87d22ffff             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
    // 00489d3f  c6818e00000000         -mov byte ptr [ecx + 0x8e], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(142) /* 0x8e */) = 0 /*0x0*/;
    // 00489d46  89b994000000           -mov dword ptr [ecx + 0x94], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(148) /* 0x94 */) = cpu.edi;
    // 00489d4c  89a990000000           -mov dword ptr [ecx + 0x90], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */) = cpu.ebp;
    // 00489d52  837e7c00               +cmp dword ptr [esi + 0x7c], 0
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
    // 00489d56  7456                   -je 0x489dae
    if (cpu.flags.zf)
    {
        goto L_0x00489dae;
    }
    // 00489d58  8b467c                 -mov eax, dword ptr [esi + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 00489d5b  898898000000           -mov dword ptr [eax + 0x98], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */) = cpu.ecx;
    // 00489d61  894e7c                 -mov dword ptr [esi + 0x7c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.ecx;
L_0x00489d64:
    // 00489d64  837c241000             +cmp dword ptr [esp + 0x10], 0
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
    // 00489d69  740d                   -je 0x489d78
    if (cpu.flags.zf)
    {
        goto L_0x00489d78;
    }
    // 00489d6b  837e2400               +cmp dword ptr [esi + 0x24], 0
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
    // 00489d6f  7507                   -jne 0x489d78
    if (!cpu.flags.zf)
    {
        goto L_0x00489d78;
    }
    // 00489d71  c746240f000000         -mov dword ptr [esi + 0x24], 0xf
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 15 /*0xf*/;
L_0x00489d78:
    // 00489d78  8b86ac000000           -mov eax, dword ptr [esi + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */);
    // 00489d7e  e85d6effff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00489d83  8b96a8000000           -mov edx, dword ptr [esi + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(168) /* 0xa8 */);
    // 00489d89  8d868c000000           -lea eax, [esi + 0x8c]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 00489d8f  e80c6dffff             -call 0x480aa0
    cpu.esp -= 4;
    sub_480aa0(app, cpu);
    if (cpu.terminate) return;
    // 00489d94  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x00489d99:
    // 00489d99  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489d9a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489d9b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489d9c  c20800                 -ret 8
    cpu.esp += 4+8 /*0x8*/;
    return;
L_0x00489d9f:
    // 00489d9f  8b86ac000000           -mov eax, dword ptr [esi + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */);
    // 00489da5  e8366effff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00489daa  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00489dac  ebeb                   -jmp 0x489d99
    goto L_0x00489d99;
L_0x00489dae:
    // 00489dae  894e7c                 -mov dword ptr [esi + 0x7c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.ecx;
    // 00489db1  8b467c                 -mov eax, dword ptr [esi + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 00489db4  894678                 -mov dword ptr [esi + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 00489db7  ebab                   -jmp 0x489d64
    goto L_0x00489d64;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489dbc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489dbc  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00489dbd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00489dbe  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00489dbf  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00489dc2  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00489dc4  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00489dc6  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00489dc8  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 00489dcb  8b4c2414               -mov ecx, dword ptr [esp + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00489dcf  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 00489dd5  e8ee6dffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 00489dda  837e7800               +cmp dword ptr [esi + 0x78], 0
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
    // 00489dde  7418                   -je 0x489df8
    if (cpu.flags.zf)
    {
        goto L_0x00489df8;
    }
L_0x00489de0:
    // 00489de0  8b4678                 -mov eax, dword ptr [esi + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */);
    // 00489de3  8b9098000000           -mov edx, dword ptr [eax + 0x98]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */);
    // 00489de9  895678                 -mov dword ptr [esi + 0x78], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = cpu.edx;
    // 00489dec  e8231b0000             -call 0x48b914
    cpu.esp -= 4;
    sub_48b914(app, cpu);
    if (cpu.terminate) return;
    // 00489df1  837e7800               +cmp dword ptr [esi + 0x78], 0
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
    // 00489df5  75e9                   -jne 0x489de0
    if (!cpu.flags.zf)
    {
        goto L_0x00489de0;
    }
    // 00489df7  90                     -nop 
    ;
L_0x00489df8:
    // 00489df8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00489dfa  bb8f000000             -mov ebx, 0x8f
    cpu.ebx = 143 /*0x8f*/;
    // 00489dff  e8f01b0000             -call 0x48b9f4
    cpu.esp -= 4;
    sub_48b9f4(app, cpu);
    if (cpu.terminate) return;
    // 00489e04  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00489e06  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00489e08  e8af21ffff             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
    // 00489e0d  c6818e00000000         -mov byte ptr [ecx + 0x8e], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(142) /* 0x8e */) = 0 /*0x0*/;
    // 00489e14  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00489e17  89b994000000           -mov dword ptr [ecx + 0x94], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(148) /* 0x94 */) = cpu.edi;
    // 00489e1d  898190000000           -mov dword ptr [ecx + 0x90], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(144) /* 0x90 */) = cpu.eax;
    // 00489e23  894e7c                 -mov dword ptr [esi + 0x7c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */) = cpu.ecx;
    // 00489e26  8b467c                 -mov eax, dword ptr [esi + 0x7c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(124) /* 0x7c */);
    // 00489e29  894678                 -mov dword ptr [esi + 0x78], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(120) /* 0x78 */) = cpu.eax;
    // 00489e2c  837e1c00               +cmp dword ptr [esi + 0x1c], 0
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
    // 00489e30  740d                   -je 0x489e3f
    if (cpu.flags.zf)
    {
        goto L_0x00489e3f;
    }
    // 00489e32  837e2400               +cmp dword ptr [esi + 0x24], 0
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
    // 00489e36  7507                   -jne 0x489e3f
    if (!cpu.flags.zf)
    {
        goto L_0x00489e3f;
    }
    // 00489e38  c746240f000000         -mov dword ptr [esi + 0x24], 0xf
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(36) /* 0x24 */) = 15 /*0xf*/;
L_0x00489e3f:
    // 00489e3f  8b86ac000000           -mov eax, dword ptr [esi + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */);
    // 00489e45  e8966dffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 00489e4a  8b96a8000000           -mov edx, dword ptr [esi + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(168) /* 0xa8 */);
    // 00489e50  8d868c000000           -lea eax, [esi + 0x8c]
    cpu.eax = x86::reg32(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 00489e56  e8456cffff             -call 0x480aa0
    cpu.esp -= 4;
    sub_480aa0(app, cpu);
    if (cpu.terminate) return;
    // 00489e5b  83ff0b                 +cmp edi, 0xb
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
    // 00489e5e  7418                   -je 0x489e78
    if (cpu.flags.zf)
    {
        goto L_0x00489e78;
    }
    // 00489e60  83ff0d                 +cmp edi, 0xd
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
    // 00489e63  7413                   -je 0x489e78
    if (cpu.flags.zf)
    {
        goto L_0x00489e78;
    }
    // 00489e65  83ff14                 +cmp edi, 0x14
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
    // 00489e68  740e                   -je 0x489e78
    if (cpu.flags.zf)
    {
        goto L_0x00489e78;
    }
    // 00489e6a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00489e6f  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00489e72  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e73  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e74  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e75  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00489e78:
    // 00489e78  8b86a4000000           -mov eax, dword ptr [esi + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(164) /* 0xa4 */);
    // 00489e7e  e8596cffff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 00489e83  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00489e88  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00489e8b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e8c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e8d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489e8e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489e94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489e94  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489e95  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489e96  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00489e98  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00489e9d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489e9f  e818ffffff             -call 0x489dbc
    cpu.esp -= 4;
    sub_489dbc(app, cpu);
    if (cpu.terminate) return;
    // 00489ea4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489ea5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489ea6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_489ea8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489ea8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489ea9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489eaa  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489eac  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 00489eb1  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489eb3  e804ffffff             -call 0x489dbc
    cpu.esp -= 4;
    sub_489dbc(app, cpu);
    if (cpu.terminate) return;
    // 00489eb8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489eb9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489eba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_489ebc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489ebc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489ebd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489ebe  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00489ec0  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489ec2  bb11000000             -mov ebx, 0x11
    cpu.ebx = 17 /*0x11*/;
    // 00489ec7  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489ec9  e842feffff             -call 0x489d10
    cpu.esp -= 4;
    sub_489d10(app, cpu);
    if (cpu.terminate) return;
    // 00489ece  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489ecf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489ed0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489ed4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489ed4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489ed5  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489ed6  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489ed8  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489eda  bb11000000             -mov ebx, 0x11
    cpu.ebx = 17 /*0x11*/;
    // 00489edf  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489ee1  e82afeffff             -call 0x489d10
    cpu.esp -= 4;
    sub_489d10(app, cpu);
    if (cpu.terminate) return;
    // 00489ee6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489ee7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489ee8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489eec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489eec  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489eed  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489eee  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00489ef0  bb0d000000             -mov ebx, 0xd
    cpu.ebx = 13 /*0xd*/;
    // 00489ef5  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489ef7  e8c0feffff             -call 0x489dbc
    cpu.esp -= 4;
    sub_489dbc(app, cpu);
    if (cpu.terminate) return;
    // 00489efc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489efd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489efe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_489f00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489f00  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489f01  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489f02  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489f04  bb0d000000             -mov ebx, 0xd
    cpu.ebx = 13 /*0xd*/;
    // 00489f09  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489f0b  e8acfeffff             -call 0x489dbc
    cpu.esp -= 4;
    sub_489dbc(app, cpu);
    if (cpu.terminate) return;
    // 00489f10  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f11  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f12  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_489f14(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489f14  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489f15  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489f16  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00489f18  bb12000000             -mov ebx, 0x12
    cpu.ebx = 18 /*0x12*/;
    // 00489f1d  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489f1f  e898feffff             -call 0x489dbc
    cpu.esp -= 4;
    sub_489dbc(app, cpu);
    if (cpu.terminate) return;
    // 00489f24  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f25  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f26  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_489f28(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489f28  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489f29  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489f2a  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489f2c  bb12000000             -mov ebx, 0x12
    cpu.ebx = 18 /*0x12*/;
    // 00489f31  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489f33  e884feffff             -call 0x489dbc
    cpu.esp -= 4;
    sub_489dbc(app, cpu);
    if (cpu.terminate) return;
    // 00489f38  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f39  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f3a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_489f3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489f3c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489f3d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489f3e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00489f40  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489f42  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
    // 00489f47  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489f49  e8c2fdffff             -call 0x489d10
    cpu.esp -= 4;
    sub_489d10(app, cpu);
    if (cpu.terminate) return;
    // 00489f4e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f4f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f50  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489f54(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489f54  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489f55  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489f56  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489f58  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489f5a  bb13000000             -mov ebx, 0x13
    cpu.ebx = 19 /*0x13*/;
    // 00489f5f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489f61  e8aafdffff             -call 0x489d10
    cpu.esp -= 4;
    sub_489d10(app, cpu);
    if (cpu.terminate) return;
    // 00489f66  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f67  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f68  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_489f6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489f6c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489f6d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489f6e  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00489f70  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00489f75  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489f77  e840feffff             -call 0x489dbc
    cpu.esp -= 4;
    sub_489dbc(app, cpu);
    if (cpu.terminate) return;
    // 00489f7c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f7d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f7e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_489f80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489f80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489f81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489f82  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489f84  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 00489f89  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00489f8b  e82cfeffff             -call 0x489dbc
    cpu.esp -= 4;
    sub_489dbc(app, cpu);
    if (cpu.terminate) return;
    // 00489f90  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f91  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489f92  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_489f94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489f94  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489f95  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489f96  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00489f98  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00489f9d  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00489f9f  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00489fa1  bad40a4c00             -mov edx, 0x4c0ad4
    cpu.edx = 4983508 /*0x4c0ad4*/;
    // 00489fa6  e865fdffff             -call 0x489d10
    cpu.esp -= 4;
    sub_489d10(app, cpu);
    if (cpu.terminate) return;
    // 00489fab  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489fac  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489fad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_489fb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489fb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489fb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489fb2  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489fb4  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00489fb9  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00489fbb  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00489fbd  bad40a4c00             -mov edx, 0x4c0ad4
    cpu.edx = 4983508 /*0x4c0ad4*/;
    // 00489fc2  e849fdffff             -call 0x489d10
    cpu.esp -= 4;
    sub_489d10(app, cpu);
    if (cpu.terminate) return;
    // 00489fc7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489fc8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489fc9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_489fcc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489fcc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489fcd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489fce  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00489fd0  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00489fd5  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489fd7  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00489fd9  bad40a4c00             -mov edx, 0x4c0ad4
    cpu.edx = 4983508 /*0x4c0ad4*/;
    // 00489fde  e82dfdffff             -call 0x489d10
    cpu.esp -= 4;
    sub_489d10(app, cpu);
    if (cpu.terminate) return;
    // 00489fe3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489fe4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00489fe5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_489fe8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00489fe8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00489fe9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00489fea  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489fec  bb10000000             -mov ebx, 0x10
    cpu.ebx = 16 /*0x10*/;
    // 00489ff1  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 00489ff3  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00489ff5  bad40a4c00             -mov edx, 0x4c0ad4
    cpu.edx = 4983508 /*0x4c0ad4*/;
    // 00489ffa  e811fdffff             -call 0x489d10
    cpu.esp -= 4;
    sub_489d10(app, cpu);
    if (cpu.terminate) return;
    // 00489fff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a000  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a001  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48a004(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a004  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a005  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a006  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0048a008  bb0b000000             -mov ebx, 0xb
    cpu.ebx = 11 /*0xb*/;
    // 0048a00d  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048a00f  bad40a4c00             -mov edx, 0x4c0ad4
    cpu.edx = 4983508 /*0x4c0ad4*/;
    // 0048a014  e8a3fdffff             -call 0x489dbc
    cpu.esp -= 4;
    sub_489dbc(app, cpu);
    if (cpu.terminate) return;
    // 0048a019  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a01a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a01b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a01c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a01c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a01d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a01e  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 0048a020  bb0b000000             -mov ebx, 0xb
    cpu.ebx = 11 /*0xb*/;
    // 0048a025  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048a027  bad40a4c00             -mov edx, 0x4c0ad4
    cpu.edx = 4983508 /*0x4c0ad4*/;
    // 0048a02c  e88bfdffff             -call 0x489dbc
    cpu.esp -= 4;
    sub_489dbc(app, cpu);
    if (cpu.terminate) return;
    // 0048a031  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a032  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a033  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48a034(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a034  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a035  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a036  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a037  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048a039  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a03b  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048a041  e8826bffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048a046  837a7800               +cmp dword ptr [edx + 0x78], 0
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
    // 0048a04a  7418                   -je 0x48a064
    if (cpu.flags.zf)
    {
        goto L_0x0048a064;
    }
L_0x0048a04c:
    // 0048a04c  41                     -inc ecx
    (cpu.ecx)++;
    // 0048a04d  8b4278                 -mov eax, dword ptr [edx + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */);
    // 0048a050  8b9898000000           -mov ebx, dword ptr [eax + 0x98]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */);
    // 0048a056  895a78                 -mov dword ptr [edx + 0x78], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */) = cpu.ebx;
    // 0048a059  e8b6180000             -call 0x48b914
    cpu.esp -= 4;
    sub_48b914(app, cpu);
    if (cpu.terminate) return;
    // 0048a05e  837a7800               +cmp dword ptr [edx + 0x78], 0
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
    // 0048a062  75e8                   -jne 0x48a04c
    if (!cpu.flags.zf)
    {
        goto L_0x0048a04c;
    }
L_0x0048a064:
    // 0048a064  8b4278                 -mov eax, dword ptr [edx + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(120) /* 0x78 */);
    // 0048a067  89427c                 -mov dword ptr [edx + 0x7c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(124) /* 0x7c */) = cpu.eax;
    // 0048a06a  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 0048a070  e86b6bffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048a075  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a077  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a078  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a079  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a07a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48a07c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a07c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a07d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a07e  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048a080  8bb084000000           -mov esi, dword ptr [eax + 0x84]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */);
    // 0048a086  89703c                 -mov dword ptr [eax + 0x3c], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(60) /* 0x3c */) = cpu.esi;
    // 0048a089  8bb088000000           -mov esi, dword ptr [eax + 0x88]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(136) /* 0x88 */);
    // 0048a08f  897004                 -mov dword ptr [eax + 4], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 0048a092  8bb088000000           -mov esi, dword ptr [eax + 0x88]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(136) /* 0x88 */);
    // 0048a098  8bb884000000           -mov edi, dword ptr [eax + 0x84]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(132) /* 0x84 */);
    // 0048a09e  01fe                   -add esi, edi
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edi));
    // 0048a0a0  897008                 -mov dword ptr [eax + 8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.esi;
    // 0048a0a3  8b7004                 -mov esi, dword ptr [eax + 4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048a0a6  897018                 -mov dword ptr [eax + 0x18], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.esi;
    // 0048a0a9  8b7018                 -mov esi, dword ptr [eax + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048a0ac  897014                 -mov dword ptr [eax + 0x14], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.esi;
    // 0048a0af  8b7014                 -mov esi, dword ptr [eax + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0048a0b2  89700c                 -mov dword ptr [eax + 0xc], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0048a0b5  8b700c                 -mov esi, dword ptr [eax + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048a0b8  897010                 -mov dword ptr [eax + 0x10], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.esi;
    // 0048a0bb  c780bc00000000000000   -mov dword ptr [eax + 0xbc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */) = 0 /*0x0*/;
    // 0048a0c5  8bb0bc000000           -mov esi, dword ptr [eax + 0xbc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */);
    // 0048a0cb  89b0b8000000           -mov dword ptr [eax + 0xb8], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */) = cpu.esi;
    // 0048a0d1  c7402800000000         -mov dword ptr [eax + 0x28], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(40) /* 0x28 */) = 0 /*0x0*/;
    // 0048a0d8  c7404000000000         -mov dword ptr [eax + 0x40], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */) = 0 /*0x0*/;
    // 0048a0df  c7405c00000000         -mov dword ptr [eax + 0x5c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */) = 0 /*0x0*/;
    // 0048a0e6  c7405401000000         -mov dword ptr [eax + 0x54], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = 1 /*0x1*/;
    // 0048a0ed  89586c                 -mov dword ptr [eax + 0x6c], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */) = cpu.ebx;
    // 0048a0f0  895068                 -mov dword ptr [eax + 0x68], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */) = cpu.edx;
    // 0048a0f3  8b15e0c24c00           -mov edx, dword ptr [0x4cc2e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a0f9  8b9aac000000           -mov ebx, dword ptr [edx + 0xac]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 0048a0ff  8998ac000000           -mov dword ptr [eax + 0xac], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */) = cpu.ebx;
    // 0048a105  8b9aa8000000           -mov ebx, dword ptr [edx + 0xa8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */);
    // 0048a10b  8998a8000000           -mov dword ptr [eax + 0xa8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */) = cpu.ebx;
    // 0048a111  8db88c000000           -lea edi, [eax + 0x8c]
    cpu.edi = x86::reg32(cpu.eax + x86::reg32(140) /* 0x8c */);
    // 0048a117  8db28c000000           -lea esi, [edx + 0x8c]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(140) /* 0x8c */);
    // 0048a11d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048a11e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048a11f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048a120  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048a121  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048a122  8b9aa4000000           -mov ebx, dword ptr [edx + 0xa4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(164) /* 0xa4 */);
    // 0048a128  8998a4000000           -mov dword ptr [eax + 0xa4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */) = cpu.ebx;
    // 0048a12e  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 0048a134  e88f6affff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048a139  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a13e  83787000               +cmp dword ptr [eax + 0x70], 0
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
    // 0048a142  740c                   -je 0x48a150
    if (cpu.flags.zf)
    {
        goto L_0x0048a150;
    }
L_0x0048a144:
    // 0048a144  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 0048a147  83787000               +cmp dword ptr [eax + 0x70], 0
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
    // 0048a14b  75f7                   -jne 0x48a144
    if (!cpu.flags.zf)
    {
        goto L_0x0048a144;
    }
    // 0048a14d  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0048a150:
    // 0048a150  894870                 -mov dword ptr [eax + 0x70], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */) = cpu.ecx;
    // 0048a153  c7417000000000         -mov dword ptr [ecx + 0x70], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(112) /* 0x70 */) = 0 /*0x0*/;
    // 0048a15a  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a15f  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048a165  e8766affff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048a16a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a16c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a16d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a16e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48a170(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048a170  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a171  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a172  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048a173  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a176  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0048a179  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 0048a17b  89ce                   -mov esi, ecx
    cpu.esi = cpu.ecx;
    // 0048a17d  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 0048a17f  66f7c3ff0f             +test bx, 0xfff
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg16>(cpu.bx & 4095 /*0xfff*/));
    // 0048a184  740c                   -je 0x48a192
    if (cpu.flags.zf)
    {
        goto L_0x0048a192;
    }
    // 0048a186  8d8b00100000           -lea ecx, [ebx + 0x1000]
    cpu.ecx = x86::reg32(cpu.ebx + x86::reg32(4096) /* 0x1000 */);
    // 0048a18c  81e100f0ff7f           -and ecx, 0x7ffff000
    cpu.ecx &= x86::reg32(x86::sreg32(2147479552 /*0x7ffff000*/));
L_0x0048a192:
    // 0048a192  bb00030000             -mov ebx, 0x300
    cpu.ebx = 768 /*0x300*/;
    // 0048a197  b8180a4c00             -mov eax, 0x4c0a18
    cpu.eax = 4983320 /*0x4c0a18*/;
    // 0048a19c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048a19e  e89d00ffff             -call 0x47a240
    cpu.esp -= 4;
    sub_47a240(app, cpu);
    if (cpu.terminate) return;
    // 0048a1a3  bac0000000             -mov edx, 0xc0
    cpu.edx = 192 /*0xc0*/;
    // 0048a1a8  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048a1aa  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0048a1ac  b8d80a4c00             -mov eax, 0x4c0ad8
    cpu.eax = 4983512 /*0x4c0ad8*/;
    // 0048a1b1  e87200ffff             -call 0x47a228
    cpu.esp -= 4;
    sub_47a228(app, cpu);
    if (cpu.terminate) return;
    // 0048a1b6  bac0000000             -mov edx, 0xc0
    cpu.edx = 192 /*0xc0*/;
    // 0048a1bb  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048a1bd  e8da6affff             -call 0x480c9c
    cpu.esp -= 4;
    sub_480c9c(app, cpu);
    if (cpu.terminate) return;
    // 0048a1c2  89be88000000           -mov dword ptr [esi + 0x88], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */) = cpu.edi;
    // 0048a1c8  898e84000000           -mov dword ptr [esi + 0x84], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(132) /* 0x84 */) = cpu.ecx;
    // 0048a1ce  bb00100000             -mov ebx, 0x1000
    cpu.ebx = 4096 /*0x1000*/;
    // 0048a1d3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048a1d5  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048a1d7  e824b10000             -call 0x495300
    cpu.esp -= 4;
    sub_495300(app, cpu);
    if (cpu.terminate) return;
    // 0048a1dc  bb00100000             -mov ebx, 0x1000
    cpu.ebx = 4096 /*0x1000*/;
    // 0048a1e1  bac0000000             -mov edx, 0xc0
    cpu.edx = 192 /*0xc0*/;
    // 0048a1e6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048a1e8  b9c0000000             -mov ecx, 0xc0
    cpu.ecx = 192 /*0xc0*/;
    // 0048a1ed  e80eb10000             -call 0x495300
    cpu.esp -= 4;
    sub_495300(app, cpu);
    if (cpu.terminate) return;
    // 0048a1f2  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048a1f5  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0048a1f7  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0048a1f9  e87efeffff             -call 0x48a07c
    cpu.esp -= 4;
    sub_48a07c(app, cpu);
    if (cpu.terminate) return;
    // 0048a1fe  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a201  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a202  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a203  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a204  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48a258(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 0048a258  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048a259  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048a25a  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048a25b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048a25c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048a25d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048a25e  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0048a261  e82668ffff             -call 0x480a8c
    cpu.esp -= 4;
    sub_480a8c(app, cpu);
    if (cpu.terminate) return;
    // 0048a266  8b15e0c24c00           -mov edx, dword ptr [0x4cc2e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a26c  8982a8000000           -mov dword ptr [edx + 0xa8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 0048a272  8b92a4000000           -mov edx, dword ptr [edx + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(164) /* 0xa4 */);
    // 0048a278  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a27a  e82168ffff             -call 0x480aa0
    cpu.esp -= 4;
    sub_480aa0(app, cpu);
    if (cpu.terminate) return;
    // 0048a27f  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 0048a284  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
  [[fallthrough]];
  case 0x0048a286:
L_0x0048a286:
    // 0048a286  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a28b  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048a291  e83269ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048a296  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a29b  8b5024                 -mov edx, dword ptr [eax + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0048a29e  83fa08                 +cmp edx, 8
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
    // 0048a2a1  0f848f000000           -je 0x48a336
    if (cpu.flags.zf)
    {
        goto L_0x0048a336;
    }
    // 0048a2a7  8378240f               +cmp dword ptr [eax + 0x24], 0xf
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
    // 0048a2ab  7507                   -jne 0x48a2b4
    if (!cpu.flags.zf)
    {
        goto L_0x0048a2b4;
    }
    // 0048a2ad  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
L_0x0048a2b4:
    // 0048a2b4  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a2b9  896824                 -mov dword ptr [eax + 0x24], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */) = cpu.ebp;
    // 0048a2bc  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048a2c2  e81969ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048a2c7  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a2cc  8b5020                 -mov edx, dword ptr [eax + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0048a2cf  4a                     -dec edx
    (cpu.edx)--;
    // 0048a2d0  83fa13                 +cmp edx, 0x13
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
    // 0048a2d3  77b1                   -ja 0x48a286
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048a286;
    }
    // 0048a2d5  ff249508a24800         -jmp dword ptr [edx*4 + 0x48a208]
    cpu.ip = app->getMemory<x86::reg32>(4760072 + cpu.edx * 4); goto dynamic_jump;
  case 0x0048a2dc:
    // 0048a2dc  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a2e1  3b681c                 +cmp ebp, dword ptr [eax + 0x1c]
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
    // 0048a2e4  7408                   -je 0x48a2ee
    if (cpu.flags.zf)
    {
        goto L_0x0048a2ee;
    }
    // 0048a2e6  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048a2e9  e8be5f0100             -call 0x4a02ac
    cpu.esp -= 4;
    sub_4a02ac(app, cpu);
    if (cpu.terminate) return;
L_0x0048a2ee:
    // 0048a2ee  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048a2f0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048a2f1  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a2f6  8d4858                 -lea ecx, [eax + 0x58]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(88) /* 0x58 */);
    // 0048a2f9  8d5850                 -lea ebx, [eax + 0x50]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 0048a2fc  8d501c                 -lea edx, [eax + 0x1c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048a2ff  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0048a305  e8765f0100             -call 0x4a0280
    cpu.esp -= 4;
    sub_4a0280(app, cpu);
    if (cpu.terminate) return;
    // 0048a30a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a30c  0f8539010000           -jne 0x48a44b
    if (!cpu.flags.zf)
    {
        goto L_0x0048a44b;
    }
L_0x0048a312:
    // 0048a312  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a317  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0048a31d  e8f2150000             -call 0x48b914
    cpu.esp -= 4;
    sub_48b914(app, cpu);
    if (cpu.terminate) return;
    // 0048a322  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a327  89681c                 -mov dword ptr [eax + 0x1c], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.ebp;
    // 0048a32a  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 0048a331  e950ffffff             -jmp 0x48a286
    goto L_0x0048a286;
L_0x0048a336:
    // 0048a336  895020                 -mov dword ptr [eax + 0x20], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 0048a339  e976ffffff             -jmp 0x48a2b4
    goto L_0x0048a2b4;
  case 0x0048a33e:
    // 0048a33e  e8a9120000             -call 0x48b5ec
    cpu.esp -= 4;
    sub_48b5ec(app, cpu);
    if (cpu.terminate) return;
    // 0048a343  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a348  3b6878                 +cmp ebp, dword ptr [eax + 0x78]
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
    // 0048a34b  752e                   -jne 0x48a37b
    if (!cpu.flags.zf)
    {
        goto L_0x0048a37b;
    }
    // 0048a34d  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048a350  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048a352  e8e9defbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048a357  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a35c  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048a362  e87567ffff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 0048a367  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a36c  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048a36f  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048a371  e8cadefbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048a376  e90bffffff             -jmp 0x48a286
    goto L_0x0048a286;
L_0x0048a37b:
    // 0048a37b  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048a381  e84268ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048a386  8b0de0c24c00           -mov ecx, dword ptr [0x4cc2e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a38c  8b4178                 -mov eax, dword ptr [ecx + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */);
    // 0048a38f  8b5178                 -mov edx, dword ptr [ecx + 0x78]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */);
    // 0048a392  8b9298000000           -mov edx, dword ptr [edx + 0x98]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(152) /* 0x98 */);
    // 0048a398  895178                 -mov dword ptr [ecx + 0x78], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */) = cpu.edx;
    // 0048a39b  898180000000           -mov dword ptr [ecx + 0x80], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(128) /* 0x80 */) = cpu.eax;
    // 0048a3a1  8b5978                 -mov ebx, dword ptr [ecx + 0x78]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(120) /* 0x78 */);
    // 0048a3a4  39dd                   +cmp ebp, ebx
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
    // 0048a3a6  7503                   -jne 0x48a3ab
    if (!cpu.flags.zf)
    {
        goto L_0x0048a3ab;
    }
    // 0048a3a8  89597c                 -mov dword ptr [ecx + 0x7c], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(124) /* 0x7c */) = cpu.ebx;
L_0x0048a3ab:
    // 0048a3ab  8b15e0c24c00           -mov edx, dword ptr [0x4cc2e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a3b1  8b8894000000           -mov ecx, dword ptr [eax + 0x94]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */);
    // 0048a3b7  894a20                 -mov dword ptr [edx + 0x20], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = cpu.ecx;
    // 0048a3ba  8b4a50                 -mov ecx, dword ptr [edx + 0x50]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */);
    // 0048a3bd  8bb090000000           -mov esi, dword ptr [eax + 0x90]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(144) /* 0x90 */);
    // 0048a3c3  01f1                   -add ecx, esi
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0048a3c5  894a60                 -mov dword ptr [edx + 0x60], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(96) /* 0x60 */) = cpu.ecx;
    // 0048a3c8  8b9094000000           -mov edx, dword ptr [eax + 0x94]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */);
    // 0048a3ce  83fa0d                 +cmp edx, 0xd
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
    // 0048a3d1  7515                   -jne 0x48a3e8
    if (!cpu.flags.zf)
    {
        goto L_0x0048a3e8;
    }
L_0x0048a3d3:
    // 0048a3d3  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a3d8  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048a3de  e8fd67ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048a3e3  e99efeffff             -jmp 0x48a286
    goto L_0x0048a286;
L_0x0048a3e8:
    // 0048a3e8  83fa14                 +cmp edx, 0x14
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
    // 0048a3eb  74e6                   -je 0x48a3d3
    if (cpu.flags.zf)
    {
        goto L_0x0048a3d3;
    }
    // 0048a3ed  39d7                   +cmp edi, edx
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
    // 0048a3ef  74e2                   -je 0x48a3d3
    if (cpu.flags.zf)
    {
        goto L_0x0048a3d3;
    }
    // 0048a3f1  83fa11                 +cmp edx, 0x11
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
    // 0048a3f4  74dd                   -je 0x48a3d3
    if (cpu.flags.zf)
    {
        goto L_0x0048a3d3;
    }
    // 0048a3f6  83fa12                 +cmp edx, 0x12
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
    // 0048a3f9  74d8                   -je 0x48a3d3
    if (cpu.flags.zf)
    {
        goto L_0x0048a3d3;
    }
    // 0048a3fb  83fa13                 +cmp edx, 0x13
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
    // 0048a3fe  74d3                   -je 0x48a3d3
    if (cpu.flags.zf)
    {
        goto L_0x0048a3d3;
    }
    // 0048a400  e80f150000             -call 0x48b914
    cpu.esp -= 4;
    sub_48b914(app, cpu);
    if (cpu.terminate) return;
    // 0048a405  ebcc                   -jmp 0x48a3d3
    goto L_0x0048a3d3;
  case 0x0048a407:
    // 0048a407  83781c00               +cmp dword ptr [eax + 0x1c], 0
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
    // 0048a40b  7534                   -jne 0x48a441
    if (!cpu.flags.zf)
    {
        goto L_0x0048a441;
    }
L_0x0048a40d:
    // 0048a40d  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a412  c7401c00000000         -mov dword ptr [eax + 0x1c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 0 /*0x0*/;
    // 0048a419  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048a41f  e84467ffff             -call 0x480b68
    cpu.esp -= 4;
    sub_480b68(app, cpu);
    if (cpu.terminate) return;
    // 0048a424  8b15e0c24c00           -mov edx, dword ptr [0x4cc2e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a42a  8b92a4000000           -mov edx, dword ptr [edx + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(164) /* 0xa4 */);
    // 0048a430  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048a432  e86966ffff             -call 0x480aa0
    cpu.esp -= 4;
    sub_480aa0(app, cpu);
    if (cpu.terminate) return;
    // 0048a437  83c404                 +add esp, 4
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
    // 0048a43a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a43b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a43c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a43d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a43e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a43f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048a440  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048a441:
    // 0048a441  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048a444  e8635e0100             -call 0x4a02ac
    cpu.esp -= 4;
    sub_4a02ac(app, cpu);
    if (cpu.terminate) return;
    // 0048a449  ebc2                   -jmp 0x48a40d
    goto L_0x0048a40d;
L_0x0048a44b:
    // 0048a44b  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a450  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0048a456  e8b9140000             -call 0x48b914
    cpu.esp -= 4;
    sub_48b914(app, cpu);
    if (cpu.terminate) return;
    // 0048a45b  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a460  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048a466  e85d67ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048a46b  8b0de0c24c00           -mov ecx, dword ptr [0x4cc2e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a471  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048a474  3b4140                 +cmp eax, dword ptr [ecx + 0x40]
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
    // 0048a477  7e67                   -jle 0x48a4e0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048a4e0;
    }
    // 0048a479  89b9a0000000           -mov dword ptr [ecx + 0xa0], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.edi;
L_0x0048a47f:
    // 0048a47f  894140                 -mov dword ptr [ecx + 0x40], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0048a482  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a487  8b5050                 -mov edx, dword ptr [eax + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 0048a48a  895060                 -mov dword ptr [eax + 0x60], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */) = cpu.edx;
    // 0048a48d  8b5050                 -mov edx, dword ptr [eax + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 0048a490  8b4858                 -mov ecx, dword ptr [eax + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */);
    // 0048a493  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a495  895054                 -mov dword ptr [eax + 0x54], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 0048a498  3b7820                 +cmp edi, dword ptr [eax + 0x20]
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
    // 0048a49b  7567                   -jne 0x48a504
    if (!cpu.flags.zf)
    {
        goto L_0x0048a504;
    }
L_0x0048a49d:
    // 0048a49d  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a4a2  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0048a4a5  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048a4a8  89a8b8000000           -mov dword ptr [eax + 0xb8], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */) = cpu.ebp;
L_0x0048a4ae:
    // 0048a4ae  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a4b3  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048a4b6  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048a4b9  83782013               +cmp dword ptr [eax + 0x20], 0x13
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
    // 0048a4bd  754d                   -jne 0x48a50c
    if (!cpu.flags.zf)
    {
        goto L_0x0048a50c;
    }
L_0x0048a4bf:
    // 0048a4bf  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a4c4  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
L_0x0048a4cb:
    // 0048a4cb  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a4d0  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048a4d6  e80567ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048a4db  e9a6fdffff             -jmp 0x48a286
    goto L_0x0048a286;
L_0x0048a4e0:
    // 0048a4e0  8b4140                 -mov eax, dword ptr [ecx + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 0048a4e3  8b5140                 -mov edx, dword ptr [ecx + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 0048a4e6  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048a4e9  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048a4ec  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048a4ee  8981a0000000           -mov dword ptr [ecx + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 0048a4f4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048a4f6  8bb1a0000000           -mov esi, dword ptr [ecx + 0xa0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */);
    // 0048a4fc  0fafc6                 +imul eax, esi
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 0048a4ff  e97bffffff             -jmp 0x48a47f
    goto L_0x0048a47f;
L_0x0048a504:
    // 0048a504  83782012               +cmp dword ptr [eax + 0x20], 0x12
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
    // 0048a508  7493                   -je 0x48a49d
    if (cpu.flags.zf)
    {
        goto L_0x0048a49d;
    }
    // 0048a50a  eba2                   -jmp 0x48a4ae
    goto L_0x0048a4ae;
L_0x0048a50c:
    // 0048a50c  83782012               +cmp dword ptr [eax + 0x20], 0x12
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
    // 0048a510  74ad                   -je 0x48a4bf
    if (cpu.flags.zf)
    {
        goto L_0x0048a4bf;
    }
    // 0048a512  c7402010000000         -mov dword ptr [eax + 0x20], 0x10
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 16 /*0x10*/;
    // 0048a519  ebb0                   -jmp 0x48a4cb
    goto L_0x0048a4cb;
  case 0x0048a51b:
    // 0048a51b  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a520  3b681c                 +cmp ebp, dword ptr [eax + 0x1c]
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
    // 0048a523  7408                   -je 0x48a52d
    if (cpu.flags.zf)
    {
        goto L_0x0048a52d;
    }
    // 0048a525  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048a528  e87f5d0100             -call 0x4a02ac
    cpu.esp -= 4;
    sub_4a02ac(app, cpu);
    if (cpu.terminate) return;
L_0x0048a52d:
    // 0048a52d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0048a52f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0048a530  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a535  8d4858                 -lea ecx, [eax + 0x58]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(88) /* 0x58 */);
    // 0048a538  8d5850                 -lea ebx, [eax + 0x50]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 0048a53b  8d501c                 -lea edx, [eax + 0x1c]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048a53e  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0048a544  e8375d0100             -call 0x4a0280
    cpu.esp -= 4;
    sub_4a0280(app, cpu);
    if (cpu.terminate) return;
    // 0048a549  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a54b  0f84c1fdffff           -je 0x48a312
    if (cpu.flags.zf)
    {
        goto L_0x0048a312;
    }
    // 0048a551  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a556  8b8080000000           -mov eax, dword ptr [eax + 0x80]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(128) /* 0x80 */);
    // 0048a55c  e8b3130000             -call 0x48b914
    cpu.esp -= 4;
    sub_48b914(app, cpu);
    if (cpu.terminate) return;
    // 0048a561  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a566  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048a56c  e85766ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048a571  8b0de0c24c00           -mov ecx, dword ptr [0x4cc2e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a577  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0048a57a  3b4140                 +cmp eax, dword ptr [ecx + 0x40]
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
    // 0048a57d  0f8eb8010000           -jle 0x48a73b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048a73b;
    }
    // 0048a583  89b9a0000000           -mov dword ptr [ecx + 0xa0], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.edi;
L_0x0048a589:
    // 0048a589  894140                 -mov dword ptr [ecx + 0x40], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */) = cpu.eax;
    // 0048a58c  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a591  8b5050                 -mov edx, dword ptr [eax + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 0048a594  895060                 -mov dword ptr [eax + 0x60], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */) = cpu.edx;
    // 0048a597  8b5050                 -mov edx, dword ptr [eax + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(80) /* 0x50 */);
    // 0048a59a  8b4858                 -mov ecx, dword ptr [eax + 0x58]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(88) /* 0x58 */);
    // 0048a59d  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a59f  895054                 -mov dword ptr [eax + 0x54], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 0048a5a2  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048a5a8  e83366ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
  [[fallthrough]];
  case 0x0048a5ad:
    // 0048a5ad  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a5b2  a3e4c24c00             -mov dword ptr [0x4cc2e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */) = cpu.eax;
    // 0048a5b7  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048a5bd  e80666ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048a5c2  3b2de4c24c00           +cmp ebp, dword ptr [0x4cc2e4]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048a5c8  743b                   -je 0x48a605
    if (cpu.flags.zf)
    {
        goto L_0x0048a605;
    }
L_0x0048a5ca:
    // 0048a5ca  a1e4c24c00             -mov eax, dword ptr [0x4cc2e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048a5cf  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048a5d2  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0048a5d5  8b5018                 -mov edx, dword ptr [eax + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */);
    // 0048a5d8  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0048a5db  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0048a5de  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048a5e1  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048a5e4  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048a5e7  89a8bc000000           -mov dword ptr [eax + 0xbc], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */) = cpu.ebp;
    // 0048a5ed  8b90bc000000           -mov edx, dword ptr [eax + 0xbc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */);
    // 0048a5f3  8990b8000000           -mov dword ptr [eax + 0xb8], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */) = cpu.edx;
    // 0048a5f9  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 0048a5fc  a3e4c24c00             -mov dword ptr [0x4cc2e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */) = cpu.eax;
    // 0048a601  39c5                   +cmp ebp, eax
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
    // 0048a603  75c5                   -jne 0x48a5ca
    if (!cpu.flags.zf)
    {
        goto L_0x0048a5ca;
    }
L_0x0048a605:
    // 0048a605  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a60a  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048a610  e8cb65ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048a615  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a61a  83782014               +cmp dword ptr [eax + 0x20], 0x14
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
    // 0048a61e  0f843b010000           -je 0x48a75f
    if (cpu.flags.zf)
    {
        goto L_0x0048a75f;
    }
    // 0048a624  c7402002000000         -mov dword ptr [eax + 0x20], 2
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 2 /*0x2*/;
    // 0048a62b  8b90a4000000           -mov edx, dword ptr [eax + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
    // 0048a631  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048a633  e86864ffff             -call 0x480aa0
    cpu.esp -= 4;
    sub_480aa0(app, cpu);
    if (cpu.terminate) return;
  [[fallthrough]];
  case 0x0048a638:
    // 0048a638  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a63d  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048a643  e88065ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048a648  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a64d  83782002               +cmp dword ptr [eax + 0x20], 2
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
    // 0048a651  0f8521010000           -jne 0x48a778
    if (!cpu.flags.zf)
    {
        goto L_0x0048a778;
    }
    // 0048a657  8b5014                 -mov edx, dword ptr [eax + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0048a65a  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048a65d  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048a660  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048a663  89a8b8000000           -mov dword ptr [eax + 0xb8], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */) = cpu.ebp;
L_0x0048a669:
    // 0048a669  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a66e  8b5060                 -mov edx, dword ptr [eax + 0x60]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(96) /* 0x60 */);
    // 0048a671  89505c                 -mov dword ptr [eax + 0x5c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */) = cpu.edx;
    // 0048a674  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048a67a  e86165ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048a67f  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a684  8b505c                 -mov edx, dword ptr [eax + 0x5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 0048a687  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048a68a  e8ad5c0100             -call 0x4a033c
    cpu.esp -= 4;
    sub_4a033c(app, cpu);
    if (cpu.terminate) return;
    // 0048a68f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048a691  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a696  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048a69c  e82765ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048a6a1  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a6a6  8b485c                 -mov ecx, dword ptr [eax + 0x5c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 0048a6a9  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a6ab  8988b0000000           -mov dword ptr [eax + 0xb0], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(176) /* 0xb0 */) = cpu.ecx;
    // 0048a6b1  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0048a6b4  8b88b0000000           -mov ecx, dword ptr [eax + 0xb0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(176) /* 0xb0 */);
    // 0048a6ba  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a6bc  89504c                 -mov dword ptr [eax + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 0048a6bf  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048a6c5  e81665ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048a6ca  8b15e0c24c00           -mov edx, dword ptr [0x4cc2e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a6d0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048a6d2  e8150f0000             -call 0x48b5ec
    cpu.esp -= 4;
    sub_48b5ec(app, cpu);
    if (cpu.terminate) return;
    // 0048a6d7  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048a6da  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0048a6dd  3b4240                 +cmp eax, dword ptr [edx + 0x40]
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
    // 0048a6e0  0f8f4e010000           -jg 0x48a834
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048a834;
    }
L_0x0048a6e6:
    // 0048a6e6  8b0de0c24c00           -mov ecx, dword ptr [0x4cc2e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a6ec  3b6924                 +cmp ebp, dword ptr [ecx + 0x24]
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
    // 0048a6ef  0f858e000000           -jne 0x48a783
    if (!cpu.flags.zf)
    {
        goto L_0x0048a783;
    }
    // 0048a6f5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a6f7  e8f00e0000             -call 0x48b5ec
    cpu.esp -= 4;
    sub_48b5ec(app, cpu);
    if (cpu.terminate) return;
    // 0048a6fc  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048a6ff  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0048a702  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a704  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048a706  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a70b  e8500f0000             -call 0x48b660
    cpu.esp -= 4;
    sub_48b660(app, cpu);
    if (cpu.terminate) return;
    // 0048a710  39c2                   +cmp edx, eax
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
    // 0048a712  746f                   -je 0x48a783
    if (cpu.flags.zf)
    {
        goto L_0x0048a783;
    }
    // 0048a714  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a719  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048a71f  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048a722  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048a724  e817dbfbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048a729  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a72e  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048a734  e8a363ffff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 0048a739  ebab                   -jmp 0x48a6e6
    goto L_0x0048a6e6;
L_0x0048a73b:
    // 0048a73b  8b4140                 -mov eax, dword ptr [ecx + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 0048a73e  8b5140                 -mov edx, dword ptr [ecx + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(64) /* 0x40 */);
    // 0048a741  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 0048a744  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048a747  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048a749  8981a0000000           -mov dword ptr [ecx + 0xa0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */) = cpu.eax;
    // 0048a74f  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048a751  8bb1a0000000           -mov esi, dword ptr [ecx + 0xa0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */);
    // 0048a757  0fafc6                 +imul eax, esi
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi));
        cpu.eax = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.eax)));
    }
    // 0048a75a  e92afeffff             -jmp 0x48a589
    goto L_0x0048a589;
L_0x0048a75f:
    // 0048a75f  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 0048a766  8b90a4000000           -mov edx, dword ptr [eax + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
    // 0048a76c  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048a76e  e82d63ffff             -call 0x480aa0
    cpu.esp -= 4;
    sub_480aa0(app, cpu);
    if (cpu.terminate) return;
    // 0048a773  e90efbffff             -jmp 0x48a286
    goto L_0x0048a286;
L_0x0048a778:
    // 0048a778  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048a77b  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048a77e  e9e6feffff             -jmp 0x48a669
    goto L_0x0048a669;
L_0x0048a783:
    // 0048a783  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a788  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048a78e  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048a791  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048a793  e8a8dafbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048a798  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a79d  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048a7a0  0f85e0faffff           -jne 0x48a286
    if (!cpu.flags.zf)
    {
        goto L_0x0048a286;
    }
L_0x0048a7a6:
    // 0048a7a6  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a7ab  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048a7ae  7531                   -jne 0x48a7e1
    if (!cpu.flags.zf)
    {
        goto L_0x0048a7e1;
    }
    // 0048a7b0  e8eb0e0000             -call 0x48b6a0
    cpu.esp -= 4;
    sub_48b6a0(app, cpu);
    if (cpu.terminate) return;
    // 0048a7b5  3b0424                 +cmp eax, dword ptr [esp]
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
    // 0048a7b8  7f27                   -jg 0x48a7e1
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048a7e1;
    }
    // 0048a7ba  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a7bf  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048a7c5  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048a7c8  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048a7ca  e871dafbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048a7cf  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a7d4  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048a7da  e8fd62ffff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 0048a7df  ebc5                   -jmp 0x48a7a6
    goto L_0x0048a7a6;
L_0x0048a7e1:
    // 0048a7e1  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a7e6  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048a7ec  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048a7ef  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048a7f1  e84adafbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048a7f6  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a7fb  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048a7fe  0f8582faffff           -jne 0x48a286
    if (!cpu.flags.zf)
    {
        goto L_0x0048a286;
    }
    // 0048a804  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048a80a  e8b963ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048a80f  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a814  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048a817  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 0048a81d  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048a820  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048a823  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048a826  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048a829  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048a82f  e8ac63ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
L_0x0048a834:
    // 0048a834  8b0de0c24c00           -mov ecx, dword ptr [0x4cc2e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a83a  3b6924                 +cmp ebp, dword ptr [ecx + 0x24]
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
    // 0048a83d  7533                   -jne 0x48a872
    if (!cpu.flags.zf)
    {
        goto L_0x0048a872;
    }
    // 0048a83f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a841  e81a0e0000             -call 0x48b660
    cpu.esp -= 4;
    sub_48b660(app, cpu);
    if (cpu.terminate) return;
    // 0048a846  3b4140                 +cmp eax, dword ptr [ecx + 0x40]
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
    // 0048a849  7f27                   -jg 0x48a872
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048a872;
    }
    // 0048a84b  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a850  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048a856  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048a859  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048a85b  e8e0d9fbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048a860  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a865  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048a86b  e86c62ffff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 0048a870  ebc2                   -jmp 0x48a834
    goto L_0x0048a834;
L_0x0048a872:
    // 0048a872  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a877  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048a87d  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048a880  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048a882  e8b9d9fbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048a887  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a88c  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048a88f  0f85f1f9ffff           -jne 0x48a286
    if (!cpu.flags.zf)
    {
        goto L_0x0048a286;
    }
L_0x0048a895:
    // 0048a895  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a89a  8b98a0000000           -mov ebx, dword ptr [eax + 0xa0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */);
    // 0048a8a0  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048a8a3  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048a8a6  e8615a0100             -call 0x4a030c
    cpu.esp -= 4;
    sub_4a030c(app, cpu);
    if (cpu.terminate) return;
    // 0048a8ab  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048a8ad  7509                   -jne 0x48a8b8
    if (!cpu.flags.zf)
    {
        goto L_0x0048a8b8;
    }
    // 0048a8af  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048a8b1  e8665fffff             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 0048a8b6  ebdd                   -jmp 0x48a895
    goto L_0x0048a895;
L_0x0048a8b8:
    // 0048a8b8  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a8bd  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048a8c3  e80063ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048a8c8  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a8cd  8b504c                 -mov edx, dword ptr [eax + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0048a8d0  01505c                 -add dword ptr [eax + 0x5c], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048a8d3  3ba8b0000000           +cmp ebp, dword ptr [eax + 0xb0]
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
    // 0048a8d9  7416                   -je 0x48a8f1
    if (cpu.flags.zf)
    {
        goto L_0x0048a8f1;
    }
    // 0048a8db  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0048a8de  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048a8e1  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048a8e4  8b80b0000000           -mov eax, dword ptr [eax + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(176) /* 0xb0 */);
    // 0048a8ea  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048a8ec  e80f6dffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
L_0x0048a8f1:
    // 0048a8f1  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a8f6  8b504c                 -mov edx, dword ptr [eax + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0048a8f9  01500c                 -add dword ptr [eax + 0xc], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048a8fc  c7402003000000         -mov dword ptr [eax + 0x20], 3
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 3 /*0x3*/;
    // 0048a903  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048a909  e8d262ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
  [[fallthrough]];
  case 0x0048a90e:
    // 0048a90e  8b15e0c24c00           -mov edx, dword ptr [0x4cc2e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a914  837a4c08               +cmp dword ptr [edx + 0x4c], 8
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
    // 0048a918  0f83ed010000           -jae 0x48ab0b
    if (!cpu.flags.cf)
    {
        goto L_0x0048ab0b;
    }
    // 0048a91e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048a920  e8c70c0000             -call 0x48b5ec
    cpu.esp -= 4;
    sub_48b5ec(app, cpu);
    if (cpu.terminate) return;
    // 0048a925  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048a928  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0048a92b  3b4240                 +cmp eax, dword ptr [edx + 0x40]
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
    // 0048a92e  0f8f21010000           -jg 0x48aa55
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048aa55;
    }
L_0x0048a934:
    // 0048a934  8b0de0c24c00           -mov ecx, dword ptr [0x4cc2e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a93a  3b6924                 +cmp ebp, dword ptr [ecx + 0x24]
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
    // 0048a93d  7546                   -jne 0x48a985
    if (!cpu.flags.zf)
    {
        goto L_0x0048a985;
    }
    // 0048a93f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048a941  e8a60c0000             -call 0x48b5ec
    cpu.esp -= 4;
    sub_48b5ec(app, cpu);
    if (cpu.terminate) return;
    // 0048a946  8b4108                 -mov eax, dword ptr [ecx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048a949  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0048a94c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048a94e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048a950  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a955  e8060d0000             -call 0x48b660
    cpu.esp -= 4;
    sub_48b660(app, cpu);
    if (cpu.terminate) return;
    // 0048a95a  39c2                   +cmp edx, eax
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
    // 0048a95c  7427                   -je 0x48a985
    if (cpu.flags.zf)
    {
        goto L_0x0048a985;
    }
    // 0048a95e  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a963  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048a969  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048a96c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048a96e  e8cdd8fbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048a973  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a978  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048a97e  e85961ffff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 0048a983  ebaf                   -jmp 0x48a934
    goto L_0x0048a934;
L_0x0048a985:
    // 0048a985  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a98a  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048a990  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048a993  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048a995  e8a6d8fbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048a99a  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a99f  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048a9a2  0f85def8ffff           -jne 0x48a286
    if (!cpu.flags.zf)
    {
        goto L_0x0048a286;
    }
L_0x0048a9a8:
    // 0048a9a8  8b15e0c24c00           -mov edx, dword ptr [0x4cc2e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a9ae  3b6a24                 +cmp ebp, dword ptr [edx + 0x24]
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
    // 0048a9b1  7536                   -jne 0x48a9e9
    if (!cpu.flags.zf)
    {
        goto L_0x0048a9e9;
    }
    // 0048a9b3  a1e4c24c00             -mov eax, dword ptr [0x4cc2e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048a9b8  e8e30c0000             -call 0x48b6a0
    cpu.esp -= 4;
    sub_48b6a0(app, cpu);
    if (cpu.terminate) return;
    // 0048a9bd  3b424c                 +cmp eax, dword ptr [edx + 0x4c]
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
    // 0048a9c0  7f27                   -jg 0x48a9e9
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048a9e9;
    }
    // 0048a9c2  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a9c7  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048a9cd  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048a9d0  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048a9d2  e869d8fbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048a9d7  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a9dc  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048a9e2  e8f560ffff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 0048a9e7  ebbf                   -jmp 0x48a9a8
    goto L_0x0048a9a8;
L_0x0048a9e9:
    // 0048a9e9  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048a9ee  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048a9f4  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048a9f7  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048a9f9  e842d8fbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048a9fe  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048aa03  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048aa06  0f857af8ffff           -jne 0x48a286
    if (!cpu.flags.zf)
    {
        goto L_0x0048a286;
    }
    // 0048aa0c  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048aa12  e8b161ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048aa17  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048aa1c  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0048aa1f  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048aa22  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048aa25  e8d66bffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0048aa2a  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048aa2f  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048aa32  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 0048aa38  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048aa3b  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048aa3e  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048aa41  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048aa44  8b504c                 -mov edx, dword ptr [eax + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0048aa47  01500c                 -add dword ptr [eax + 0xc], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048aa4a  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048aa50  e88b61ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
L_0x0048aa55:
    // 0048aa55  8b0de0c24c00           -mov ecx, dword ptr [0x4cc2e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048aa5b  3b6924                 +cmp ebp, dword ptr [ecx + 0x24]
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
    // 0048aa5e  7533                   -jne 0x48aa93
    if (!cpu.flags.zf)
    {
        goto L_0x0048aa93;
    }
    // 0048aa60  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048aa62  e8f90b0000             -call 0x48b660
    cpu.esp -= 4;
    sub_48b660(app, cpu);
    if (cpu.terminate) return;
    // 0048aa67  3b4140                 +cmp eax, dword ptr [ecx + 0x40]
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
    // 0048aa6a  7f27                   -jg 0x48aa93
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048aa93;
    }
    // 0048aa6c  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048aa71  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048aa77  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048aa7a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048aa7c  e8bfd7fbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048aa81  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048aa86  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048aa8c  e84b60ffff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 0048aa91  ebc2                   -jmp 0x48aa55
    goto L_0x0048aa55;
L_0x0048aa93:
    // 0048aa93  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048aa98  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048aa9e  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048aaa1  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048aaa3  e898d7fbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048aaa8  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048aaad  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048aab0  0f85d0f7ffff           -jne 0x48a286
    if (!cpu.flags.zf)
    {
        goto L_0x0048a286;
    }
L_0x0048aab6:
    // 0048aab6  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048aabb  8b98a0000000           -mov ebx, dword ptr [eax + 0xa0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */);
    // 0048aac1  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048aac4  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048aac7  e840580100             -call 0x4a030c
    cpu.esp -= 4;
    sub_4a030c(app, cpu);
    if (cpu.terminate) return;
    // 0048aacc  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048aace  7509                   -jne 0x48aad9
    if (!cpu.flags.zf)
    {
        goto L_0x0048aad9;
    }
    // 0048aad0  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048aad2  e8455dffff             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 0048aad7  ebdd                   -jmp 0x48aab6
    goto L_0x0048aab6;
L_0x0048aad9:
    // 0048aad9  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048aade  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048aae4  e8df60ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048aae9  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048aaee  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0048aaf1  01500c                 -add dword ptr [eax + 0xc], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048aaf4  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0048aaf7  01505c                 -add dword ptr [eax + 0x5c], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048aafa  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0048aafd  01504c                 -add dword ptr [eax + 0x4c], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048ab00  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048ab06  e8d560ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
L_0x0048ab0b:
    // 0048ab0b  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048ab10  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048ab13  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048ab18  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048ab1a  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048ab1c  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048ab1e  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048ab25  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048ab27  3d6c454353             +cmp eax, 0x5343456c
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
    // 0048ab2c  7516                   -jne 0x48ab44
    if (!cpu.flags.zf)
    {
        goto L_0x0048ab44;
    }
    // 0048ab2e  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048ab33  3b6878                 +cmp ebp, dword ptr [eax + 0x78]
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
    // 0048ab36  740c                   -je 0x48ab44
    if (cpu.flags.zf)
    {
        goto L_0x0048ab44;
    }
    // 0048ab38  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 0048ab3f  e942f7ffff             -jmp 0x48a286
    goto L_0x0048a286;
L_0x0048ab44:
    // 0048ab44  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048ab49  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048ab4f  e87460ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048ab54  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048ab59  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048ab5c  8b5204                 -mov edx, dword ptr [edx + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048ab5f  895048                 -mov dword ptr [eax + 0x48], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */) = cpu.edx;
    // 0048ab62  8b5048                 -mov edx, dword ptr [eax + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0048ab65  8b484c                 -mov ecx, dword ptr [eax + 0x4c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0048ab68  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048ab6a  895044                 -mov dword ptr [eax + 0x44], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */) = cpu.edx;
    // 0048ab6d  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 0048ab70  a3e4c24c00             -mov dword ptr [0x4cc2e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */) = cpu.eax;
    // 0048ab75  39c5                   +cmp ebp, eax
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
    // 0048ab77  742f                   -je 0x48aba8
    if (cpu.flags.zf)
    {
        goto L_0x0048aba8;
    }
L_0x0048ab79:
    // 0048ab79  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048ab7e  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048ab81  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048ab86  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048ab88  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048ab8a  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048ab8c  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048ab93  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048ab95  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048ab97  a1e4c24c00             -mov eax, dword ptr [0x4cc2e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048ab9c  23506c                 -and edx, dword ptr [eax + 0x6c]
    cpu.edx &= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(108) /* 0x6c */)));
    // 0048ab9f  3b5068                 +cmp edx, dword ptr [eax + 0x68]
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
    // 0048aba2  0f85a3000000           -jne 0x48ac4b
    if (!cpu.flags.zf)
    {
        goto L_0x0048ac4b;
    }
L_0x0048aba8:
    // 0048aba8  3b2de4c24c00           +cmp ebp, dword ptr [0x4cc2e4]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048abae  750a                   -jne 0x48abba
    if (!cpu.flags.zf)
    {
        goto L_0x0048abba;
    }
    // 0048abb0  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048abb5  a3e4c24c00             -mov dword ptr [0x4cc2e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */) = cpu.eax;
L_0x0048abba:
    // 0048abba  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048abbf  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048abc5  e81660ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048abca  8b0de0c24c00           -mov ecx, dword ptr [0x4cc2e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048abd0  83794808               +cmp dword ptr [ecx + 0x48], 8
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
    // 0048abd4  0f8386000000           -jae 0x48ac60
    if (!cpu.flags.cf)
    {
        goto L_0x0048ac60;
    }
L_0x0048abda:
    // 0048abda  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048abdf  3b682c                 +cmp ebp, dword ptr [eax + 0x2c]
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
    // 0048abe2  0f8594000000           -jne 0x48ac7c
    if (!cpu.flags.zf)
    {
        goto L_0x0048ac7c;
    }
    // 0048abe8  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048abee  e8d55fffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048abf3  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048abf8  a3e4c24c00             -mov dword ptr [0x4cc2e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */) = cpu.eax;
L_0x0048abfd:
    // 0048abfd  a1e4c24c00             -mov eax, dword ptr [0x4cc2e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048ac02  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048ac05  8b4868                 -mov ecx, dword ptr [eax + 0x68]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(104) /* 0x68 */);
    // 0048ac08  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
    // 0048ac0a  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048ac0d  c7420408000000         -mov dword ptr [edx + 4], 8
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 8 /*0x8*/;
    // 0048ac14  83401008               -add dword ptr [eax + 0x10], 8
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048ac18  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048ac1b  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048ac1e  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 0048ac21  a3e4c24c00             -mov dword ptr [0x4cc2e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */) = cpu.eax;
    // 0048ac26  39c5                   +cmp ebp, eax
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
    // 0048ac28  75d3                   -jne 0x48abfd
    if (!cpu.flags.zf)
    {
        goto L_0x0048abfd;
    }
    // 0048ac2a  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048ac2f  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048ac35  e8a65fffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048ac3a  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048ac3f  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 0048ac46  e93bf6ffff             -jmp 0x48a286
    goto L_0x0048a286;
L_0x0048ac4b:
    // 0048ac4b  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 0048ac4e  a3e4c24c00             -mov dword ptr [0x4cc2e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */) = cpu.eax;
    // 0048ac53  39c5                   +cmp ebp, eax
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
    // 0048ac55  0f851effffff           -jne 0x48ab79
    if (!cpu.flags.zf)
    {
        goto L_0x0048ab79;
    }
    // 0048ac5b  e948ffffff             -jmp 0x48aba8
    goto L_0x0048aba8;
L_0x0048ac60:
    // 0048ac60  8b15e4c24c00           -mov edx, dword ptr [0x4cc2e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048ac66  8b423c                 -mov eax, dword ptr [edx + 0x3c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */);
    // 0048ac69  8b523c                 -mov edx, dword ptr [edx + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(60) /* 0x3c */);
    // 0048ac6c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048ac6f  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048ac71  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0048ac73  3b4148                 +cmp eax, dword ptr [ecx + 0x48]
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
    // 0048ac76  0f8c5effffff           -jl 0x48abda
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048abda;
    }
L_0x0048ac7c:
    // 0048ac7c  a1e4c24c00             -mov eax, dword ptr [0x4cc2e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048ac81  8b1de0c24c00           -mov ebx, dword ptr [0x4cc2e0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048ac87  39d8                   +cmp eax, ebx
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
    // 0048ac89  0f848e030000           -je 0x48b01d
    if (cpu.flags.zf)
    {
        goto L_0x0048b01d;
    }
    // 0048ac8f  89ee                   -mov esi, ebp
    cpu.esi = cpu.ebp;
    // 0048ac91  8b4348                 -mov eax, dword ptr [ebx + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(72) /* 0x48 */);
    // 0048ac94  034340                 -add eax, dword ptr [ebx + 0x40]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(64) /* 0x40 */)));
    // 0048ac97  8b15e4c24c00           -mov edx, dword ptr [0x4cc2e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048ac9d  8d4808                 -lea ecx, [eax + 8]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048aca0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048aca2  e845090000             -call 0x48b5ec
    cpu.esp -= 4;
    sub_48b5ec(app, cpu);
    if (cpu.terminate) return;
    // 0048aca7  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048acaa  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0048acad  39c8                   +cmp eax, ecx
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
    // 0048acaf  0f877a010000           -ja 0x48ae2f
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048ae2f;
    }
L_0x0048acb5:
    // 0048acb5  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048acba  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048acbd  754a                   -jne 0x48ad09
    if (!cpu.flags.zf)
    {
        goto L_0x0048ad09;
    }
    // 0048acbf  8b0de4c24c00           -mov ecx, dword ptr [0x4cc2e4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048acc5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048acc7  e820090000             -call 0x48b5ec
    cpu.esp -= 4;
    sub_48b5ec(app, cpu);
    if (cpu.terminate) return;
    // 0048accc  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048accf  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0048acd2  a1e4c24c00             -mov eax, dword ptr [0x4cc2e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048acd7  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048acd9  e882090000             -call 0x48b660
    cpu.esp -= 4;
    sub_48b660(app, cpu);
    if (cpu.terminate) return;
    // 0048acde  39c2                   +cmp edx, eax
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
    // 0048ace0  7427                   -je 0x48ad09
    if (cpu.flags.zf)
    {
        goto L_0x0048ad09;
    }
    // 0048ace2  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048ace7  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048aced  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048acf0  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048acf2  e849d5fbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048acf7  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048acfc  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048ad02  e8d55dffff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 0048ad07  ebac                   -jmp 0x48acb5
    goto L_0x0048acb5;
L_0x0048ad09:
    // 0048ad09  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048ad0e  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048ad14  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048ad17  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048ad19  e822d5fbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048ad1e  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048ad23  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048ad26  0f855af5ffff           -jne 0x48a286
    if (!cpu.flags.zf)
    {
        goto L_0x0048a286;
    }
L_0x0048ad2c:
    // 0048ad2c  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048ad31  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048ad34  7536                   -jne 0x48ad6c
    if (!cpu.flags.zf)
    {
        goto L_0x0048ad6c;
    }
    // 0048ad36  a1e4c24c00             -mov eax, dword ptr [0x4cc2e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048ad3b  e820090000             -call 0x48b660
    cpu.esp -= 4;
    sub_48b660(app, cpu);
    if (cpu.terminate) return;
    // 0048ad40  83f808                 +cmp eax, 8
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
    // 0048ad43  7727                   -ja 0x48ad6c
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048ad6c;
    }
    // 0048ad45  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048ad4a  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048ad50  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048ad53  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048ad55  e8e6d4fbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048ad5a  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048ad5f  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048ad65  e8725dffff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 0048ad6a  ebc0                   -jmp 0x48ad2c
    goto L_0x0048ad2c;
L_0x0048ad6c:
    // 0048ad6c  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048ad71  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048ad77  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048ad7a  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048ad7c  e8bfd4fbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048ad81  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048ad86  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048ad89  0f85f7f4ffff           -jne 0x48a286
    if (!cpu.flags.zf)
    {
        goto L_0x0048a286;
    }
L_0x0048ad8f:
    // 0048ad8f  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048ad94  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048ad97  753e                   -jne 0x48add7
    if (!cpu.flags.zf)
    {
        goto L_0x0048add7;
    }
    // 0048ad99  8b4848                 -mov ecx, dword ptr [eax + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0048ad9c  034840                 -add ecx, dword ptr [eax + 0x40]
    (cpu.ecx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */)));
    // 0048ad9f  a1e4c24c00             -mov eax, dword ptr [0x4cc2e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048ada4  8d5108                 -lea edx, [ecx + 8]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048ada7  e8f4080000             -call 0x48b6a0
    cpu.esp -= 4;
    sub_48b6a0(app, cpu);
    if (cpu.terminate) return;
    // 0048adac  39d0                   +cmp eax, edx
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
    // 0048adae  7727                   -ja 0x48add7
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048add7;
    }
    // 0048adb0  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048adb5  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048adbb  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048adbe  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048adc0  e87bd4fbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048adc5  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048adca  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048add0  e8075dffff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 0048add5  ebb8                   -jmp 0x48ad8f
    goto L_0x0048ad8f;
L_0x0048add7:
    // 0048add7  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048addc  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048ade2  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048ade5  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048ade7  e854d4fbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048adec  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048adf1  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048adf4  0f858cf4ffff           -jne 0x48a286
    if (!cpu.flags.zf)
    {
        goto L_0x0048a286;
    }
    // 0048adfa  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048ae00  e8c35dffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048ae05  a1e4c24c00             -mov eax, dword ptr [0x4cc2e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048ae0a  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048ae0d  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 0048ae13  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048ae16  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048ae19  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048ae1c  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048ae1f  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048ae24  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048ae2a  e8b15dffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
L_0x0048ae2f:
    // 0048ae2f  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048ae34  3b6844                 +cmp ebp, dword ptr [eax + 0x44]
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
    // 0048ae37  0f8f17010000           -jg 0x48af54
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048af54;
    }
L_0x0048ae3d:
    // 0048ae3d  8b15e0c24c00           -mov edx, dword ptr [0x4cc2e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048ae43  3b6a24                 +cmp ebp, dword ptr [edx + 0x24]
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
    // 0048ae46  7536                   -jne 0x48ae7e
    if (!cpu.flags.zf)
    {
        goto L_0x0048ae7e;
    }
    // 0048ae48  a1e4c24c00             -mov eax, dword ptr [0x4cc2e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048ae4d  e80e080000             -call 0x48b660
    cpu.esp -= 4;
    sub_48b660(app, cpu);
    if (cpu.terminate) return;
    // 0048ae52  3b424c                 +cmp eax, dword ptr [edx + 0x4c]
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
    // 0048ae55  7f27                   -jg 0x48ae7e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048ae7e;
    }
    // 0048ae57  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048ae5c  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048ae62  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048ae65  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048ae67  e8d4d3fbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048ae6c  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048ae71  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048ae77  e8605cffff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 0048ae7c  ebbf                   -jmp 0x48ae3d
    goto L_0x0048ae3d;
L_0x0048ae7e:
    // 0048ae7e  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048ae83  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048ae89  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048ae8c  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048ae8e  e8add3fbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048ae93  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048ae98  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048ae9b  0f85e5f3ffff           -jne 0x48a286
    if (!cpu.flags.zf)
    {
        goto L_0x0048a286;
    }
    // 0048aea1  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048aea7  e81c5dffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048aeac  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048aeb1  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0048aeb4  8b15e4c24c00           -mov edx, dword ptr [0x4cc2e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048aeba  8b5210                 -mov edx, dword ptr [edx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048aebd  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048aec0  e83b67ffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0048aec5  8b15e4c24c00           -mov edx, dword ptr [0x4cc2e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048aecb  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048aed0  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048aed3  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0048aed6  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048aed8  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0048aedb  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048aede  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048aee1  89684c                 -mov dword ptr [eax + 0x4c], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.ebp;
L_0x0048aee4:
    // 0048aee4  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048aeea  e8f15cffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
L_0x0048aeef:
    // 0048aeef  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048aef4  3b6844                 +cmp ebp, dword ptr [eax + 0x44]
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
    // 0048aef7  0f8c50010000           -jl 0x48b04d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048b04d;
    }
L_0x0048aefd:
    // 0048aefd  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048af02  3b6844                 +cmp ebp, dword ptr [eax + 0x44]
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
    // 0048af05  0f8d1f030000           -jge 0x48b22a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048b22a;
    }
L_0x0048af0b:
    // 0048af0b  8b15e0c24c00           -mov edx, dword ptr [0x4cc2e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048af11  3b6a24                 +cmp ebp, dword ptr [edx + 0x24]
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
    // 0048af14  0f858b020000           -jne 0x48b1a5
    if (!cpu.flags.zf)
    {
        goto L_0x0048b1a5;
    }
    // 0048af1a  a1e4c24c00             -mov eax, dword ptr [0x4cc2e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048af1f  e83c070000             -call 0x48b660
    cpu.esp -= 4;
    sub_48b660(app, cpu);
    if (cpu.terminate) return;
    // 0048af24  3b4240                 +cmp eax, dword ptr [edx + 0x40]
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
    // 0048af27  0f8f78020000           -jg 0x48b1a5
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048b1a5;
    }
    // 0048af2d  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048af32  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048af38  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048af3b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048af3d  e8fed2fbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048af42  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048af47  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048af4d  e88a5bffff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 0048af52  ebb7                   -jmp 0x48af0b
    goto L_0x0048af0b;
L_0x0048af54:
    // 0048af54  8b15e0c24c00           -mov edx, dword ptr [0x4cc2e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048af5a  3b6a24                 +cmp ebp, dword ptr [edx + 0x24]
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
    // 0048af5d  7536                   -jne 0x48af95
    if (!cpu.flags.zf)
    {
        goto L_0x0048af95;
    }
    // 0048af5f  a1e4c24c00             -mov eax, dword ptr [0x4cc2e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048af64  e8f7060000             -call 0x48b660
    cpu.esp -= 4;
    sub_48b660(app, cpu);
    if (cpu.terminate) return;
    // 0048af69  3b4248                 +cmp eax, dword ptr [edx + 0x48]
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
    // 0048af6c  7f27                   -jg 0x48af95
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048af95;
    }
    // 0048af6e  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048af73  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048af79  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048af7c  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048af7e  e8bdd2fbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048af83  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048af88  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048af8e  e8495bffff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 0048af93  ebbf                   -jmp 0x48af54
    goto L_0x0048af54;
L_0x0048af95:
    // 0048af95  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048af9a  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048afa0  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048afa3  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048afa5  e896d2fbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048afaa  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048afaf  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048afb2  0f85cef2ffff           -jne 0x48a286
    if (!cpu.flags.zf)
    {
        goto L_0x0048a286;
    }
    // 0048afb8  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048afbe  e8055cffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048afc3  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048afc8  8b5848                 -mov ebx, dword ptr [eax + 0x48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0048afcb  8b15e4c24c00           -mov edx, dword ptr [0x4cc2e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048afd1  8b5210                 -mov edx, dword ptr [edx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048afd4  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048afd7  e82466ffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0048afdc  8b15e4c24c00           -mov edx, dword ptr [0x4cc2e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048afe2  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048afe7  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048afea  8b5848                 -mov ebx, dword ptr [eax + 0x48]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0048afed  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048afef  894a0c                 -mov dword ptr [edx + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0048aff2  8b5044                 -mov edx, dword ptr [eax + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 0048aff5  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0048aff7  89504c                 -mov dword ptr [eax + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 0048affa  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0048affd  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048b000  8b4810                 -mov ecx, dword ptr [eax + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048b003  8b4048                 -mov eax, dword ptr [eax + 0x48]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0048b006  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b008  e8f365ffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0048b00d  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b012  8b5048                 -mov edx, dword ptr [eax + 0x48]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(72) /* 0x48 */);
    // 0048b015  29500c                 +sub dword ptr [eax + 0xc], edx
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
    // 0048b018  e9c7feffff             -jmp 0x48aee4
    goto L_0x0048aee4;
L_0x0048b01d:
    // 0048b01d  8b4310                 -mov eax, dword ptr [ebx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(16) /* 0x10 */);
    // 0048b020  b904000000             -mov ecx, 4
    cpu.ecx = 4 /*0x4*/;
    // 0048b025  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048b027  0fc8                   -bswap eax
    {
        x86::reg32& tmp = cpu.eax;
        tmp = ( tmp               << 16) ^  (tmp >> 16);
        tmp = ((tmp & 0x00ff00ff) <<  8) ^ ((tmp >>  8) & 0x00ff00ff);
    }
    // 0048b029  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0048b02b  8d0ccd20000000         -lea ecx, [ecx*8 + 0x20]
    cpu.ecx = x86::reg32(x86::reg32(32) /* 0x20 */ + cpu.ecx * 8);
    // 0048b032  d3e8                   -shr eax, cl
    cpu.eax >>= cpu.cl % 32;
    // 0048b034  3d6c454353             +cmp eax, 0x5343456c
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
    // 0048b039  7509                   -jne 0x48b044
    if (!cpu.flags.zf)
    {
        goto L_0x0048b044;
    }
    // 0048b03b  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048b03d  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048b03f  e9abfeffff             -jmp 0x48aeef
    goto L_0x0048aeef;
L_0x0048b044:
    // 0048b044  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0048b046  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0048b048  e9a2feffff             -jmp 0x48aeef
    goto L_0x0048aeef;
L_0x0048b04d:
    // 0048b04d  8b5044                 -mov edx, dword ptr [eax + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(68) /* 0x44 */);
    // 0048b050  035040                 -add edx, dword ptr [eax + 0x40]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */)));
    // 0048b053  8d4a08                 -lea ecx, [edx + 8]
    cpu.ecx = x86::reg32(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048b056  8b15e4c24c00           -mov edx, dword ptr [0x4cc2e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048b05c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b05e  e889050000             -call 0x48b5ec
    cpu.esp -= 4;
    sub_48b5ec(app, cpu);
    if (cpu.terminate) return;
    // 0048b063  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048b066  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0048b069  39c8                   +cmp eax, ecx
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
    // 0048b06b  0f878cfeffff           -ja 0x48aefd
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048aefd;
    }
L_0x0048b071:
    // 0048b071  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b076  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048b079  754a                   -jne 0x48b0c5
    if (!cpu.flags.zf)
    {
        goto L_0x0048b0c5;
    }
    // 0048b07b  8b0de4c24c00           -mov ecx, dword ptr [0x4cc2e4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048b081  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048b083  e864050000             -call 0x48b5ec
    cpu.esp -= 4;
    sub_48b5ec(app, cpu);
    if (cpu.terminate) return;
    // 0048b088  8b5108                 -mov edx, dword ptr [ecx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048b08b  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0048b08e  a1e4c24c00             -mov eax, dword ptr [0x4cc2e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048b093  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048b095  e8c6050000             -call 0x48b660
    cpu.esp -= 4;
    sub_48b660(app, cpu);
    if (cpu.terminate) return;
    // 0048b09a  39c2                   +cmp edx, eax
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
    // 0048b09c  7427                   -je 0x48b0c5
    if (cpu.flags.zf)
    {
        goto L_0x0048b0c5;
    }
    // 0048b09e  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b0a3  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048b0a9  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048b0ac  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048b0ae  e88dd1fbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048b0b3  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b0b8  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048b0be  e8195affff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 0048b0c3  ebac                   -jmp 0x48b071
    goto L_0x0048b071;
L_0x0048b0c5:
    // 0048b0c5  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b0ca  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048b0d0  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048b0d3  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048b0d5  e866d1fbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048b0da  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b0df  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048b0e2  0f859ef1ffff           -jne 0x48a286
    if (!cpu.flags.zf)
    {
        goto L_0x0048a286;
    }
L_0x0048b0e8:
    // 0048b0e8  8b15e0c24c00           -mov edx, dword ptr [0x4cc2e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b0ee  3b6a24                 +cmp ebp, dword ptr [edx + 0x24]
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
    // 0048b0f1  7536                   -jne 0x48b129
    if (!cpu.flags.zf)
    {
        goto L_0x0048b129;
    }
    // 0048b0f3  a1e4c24c00             -mov eax, dword ptr [0x4cc2e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048b0f8  e8a3050000             -call 0x48b6a0
    cpu.esp -= 4;
    sub_48b6a0(app, cpu);
    if (cpu.terminate) return;
    // 0048b0fd  3b424c                 +cmp eax, dword ptr [edx + 0x4c]
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
    // 0048b100  7f27                   -jg 0x48b129
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048b129;
    }
    // 0048b102  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b107  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048b10d  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048b110  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048b112  e829d1fbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048b117  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b11c  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048b122  e8b559ffff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 0048b127  ebbf                   -jmp 0x48b0e8
    goto L_0x0048b0e8;
L_0x0048b129:
    // 0048b129  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b12e  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048b134  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048b137  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048b139  e802d1fbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048b13e  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b143  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048b146  0f853af1ffff           -jne 0x48a286
    if (!cpu.flags.zf)
    {
        goto L_0x0048a286;
    }
    // 0048b14c  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048b152  e8715affff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048b157  8b1de0c24c00           -mov ebx, dword ptr [0x4cc2e0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b15d  8b5b4c                 -mov ebx, dword ptr [ebx + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(76) /* 0x4c */);
    // 0048b160  a1e4c24c00             -mov eax, dword ptr [0x4cc2e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048b165  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048b168  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048b16b  e89064ffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0048b170  a1e4c24c00             -mov eax, dword ptr [0x4cc2e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048b175  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048b178  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 0048b17e  8b15e0c24c00           -mov edx, dword ptr [0x4cc2e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b184  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048b187  8b5a4c                 -mov ebx, dword ptr [edx + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */);
    // 0048b18a  01d9                   +add ecx, ebx
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
    // 0048b18c  89480c                 -mov dword ptr [eax + 0xc], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ecx;
    // 0048b18f  8b4804                 -mov ecx, dword ptr [eax + 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048b192  894810                 -mov dword ptr [eax + 0x10], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.ecx;
    // 0048b195  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 0048b19b  e8405affff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048b1a0  e958fdffff             -jmp 0x48aefd
    goto L_0x0048aefd;
L_0x0048b1a5:
    // 0048b1a5  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b1aa  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048b1b0  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048b1b3  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048b1b5  e886d0fbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048b1ba  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b1bf  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048b1c2  7566                   -jne 0x48b22a
    if (!cpu.flags.zf)
    {
        goto L_0x0048b22a;
    }
L_0x0048b1c4:
    // 0048b1c4  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b1c9  8b98a0000000           -mov ebx, dword ptr [eax + 0xa0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */);
    // 0048b1cf  8b15e4c24c00           -mov edx, dword ptr [0x4cc2e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048b1d5  8b520c                 -mov edx, dword ptr [edx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048b1d8  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048b1db  e82c510100             -call 0x4a030c
    cpu.esp -= 4;
    sub_4a030c(app, cpu);
    if (cpu.terminate) return;
    // 0048b1e0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b1e2  7509                   -jne 0x48b1ed
    if (!cpu.flags.zf)
    {
        goto L_0x0048b1ed;
    }
    // 0048b1e4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048b1e6  e83156ffff             -call 0x48081c
    cpu.esp -= 4;
    sub_48081c(app, cpu);
    if (cpu.terminate) return;
    // 0048b1eb  ebd7                   -jmp 0x48b1c4
    goto L_0x0048b1c4;
L_0x0048b1ed:
    // 0048b1ed  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b1f2  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048b1f8  e8cb59ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048b1fd  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b202  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0048b205  01505c                 -add dword ptr [eax + 0x5c], edx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048b208  8b15e4c24c00           -mov edx, dword ptr [0x4cc2e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048b20e  8b4840                 -mov ecx, dword ptr [eax + 0x40]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0048b211  014a0c                 -add dword ptr [edx + 0xc], ecx
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b214  8b5040                 -mov edx, dword ptr [eax + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(64) /* 0x40 */);
    // 0048b217  295044                 +sub dword ptr [eax + 0x44], edx
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
    // 0048b21a  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048b220  e8bb59ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048b225  e9d3fcffff             -jmp 0x48aefd
    goto L_0x0048aefd;
L_0x0048b22a:
    // 0048b22a  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b22f  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048b232  0f854ef0ffff           -jne 0x48a286
    if (!cpu.flags.zf)
    {
        goto L_0x0048a286;
    }
    // 0048b238  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048b23e  e88559ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048b243  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048b245  0f85bc000000           -jne 0x48b307
    if (!cpu.flags.zf)
    {
        goto L_0x0048b307;
    }
    // 0048b24b  8b15e0c24c00           -mov edx, dword ptr [0x4cc2e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b251  a1e4c24c00             -mov eax, dword ptr [0x4cc2e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048b256  8b4a48                 -mov ecx, dword ptr [edx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 0048b259  014810                 -add dword ptr [eax + 0x10], ecx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b25c  8b4a48                 -mov ecx, dword ptr [edx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 0048b25f  83e908                 -sub ecx, 8
    (cpu.ecx) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048b262  0188b8000000           -add dword ptr [eax + 0xb8], ecx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b268  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 0048b26e  e86d59ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048b273  a1e4c24c00             -mov eax, dword ptr [0x4cc2e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048b278  8b35e0c24c00           -mov esi, dword ptr [0x4cc2e0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b27e  39f0                   +cmp eax, esi
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
    // 0048b280  0f849d020000           -je 0x48b523
    if (cpu.flags.zf)
    {
        goto L_0x0048b523;
    }
    // 0048b286  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048b288  3b6e4c                 +cmp ebp, dword ptr [esi + 0x4c]
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
    // 0048b28b  0f852a020000           -jne 0x48b4bb
    if (!cpu.flags.zf)
    {
        goto L_0x0048b4bb;
    }
    // 0048b291  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048b293  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0048b296  8b7110                 -mov esi, dword ptr [ecx + 0x10]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0048b299  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048b29b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b29d  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0048b29f  e848030000             -call 0x48b5ec
    cpu.esp -= 4;
    sub_48b5ec(app, cpu);
    if (cpu.terminate) return;
    // 0048b2a4  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048b2a7  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0048b2aa  39c8                   +cmp eax, ecx
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
    // 0048b2ac  0f8f45010000           -jg 0x48b3f7
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048b3f7;
    }
L_0x0048b2b2:
    // 0048b2b2  8b15e0c24c00           -mov edx, dword ptr [0x4cc2e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b2b8  3b6a24                 +cmp ebp, dword ptr [edx + 0x24]
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
    // 0048b2bb  0f857a000000           -jne 0x48b33b
    if (!cpu.flags.zf)
    {
        goto L_0x0048b33b;
    }
    // 0048b2c1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b2c3  e824030000             -call 0x48b5ec
    cpu.esp -= 4;
    sub_48b5ec(app, cpu);
    if (cpu.terminate) return;
    // 0048b2c8  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048b2cb  8b4a0c                 -mov ecx, dword ptr [edx + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048b2ce  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b2d0  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b2d5  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b2d7  e884030000             -call 0x48b660
    cpu.esp -= 4;
    sub_48b660(app, cpu);
    if (cpu.terminate) return;
    // 0048b2dc  39c2                   +cmp edx, eax
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
    // 0048b2de  745b                   -je 0x48b33b
    if (cpu.flags.zf)
    {
        goto L_0x0048b33b;
    }
    // 0048b2e0  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b2e5  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048b2eb  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048b2ee  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048b2f0  e84bcffbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048b2f5  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b2fa  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048b300  e8d757ffff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 0048b305  ebab                   -jmp 0x48b2b2
    goto L_0x0048b2b2;
L_0x0048b307:
    // 0048b307  8b15e0c24c00           -mov edx, dword ptr [0x4cc2e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b30d  a1e4c24c00             -mov eax, dword ptr [0x4cc2e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048b312  8b4a48                 -mov ecx, dword ptr [edx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 0048b315  014810                 -add dword ptr [eax + 0x10], ecx
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b318  8b4a48                 -mov ecx, dword ptr [edx + 0x48]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(72) /* 0x48 */);
    // 0048b31b  83e908                 -sub ecx, 8
    (cpu.ecx) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048b31e  0188b8000000           +add dword ptr [eax + 0xb8], ecx
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
    // 0048b324  c7422007000000         -mov dword ptr [edx + 0x20], 7
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 0048b32b  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 0048b331  e8aa58ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048b336  e94befffff             -jmp 0x48a286
    goto L_0x0048a286;
L_0x0048b33b:
    // 0048b33b  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b340  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048b346  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048b349  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048b34b  e8f0cefbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048b350  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b355  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048b358  0f8528efffff           -jne 0x48a286
    if (!cpu.flags.zf)
    {
        goto L_0x0048a286;
    }
L_0x0048b35e:
    // 0048b35e  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b363  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048b366  753c                   -jne 0x48b3a4
    if (!cpu.flags.zf)
    {
        goto L_0x0048b3a4;
    }
    // 0048b368  8b0de4c24c00           -mov ecx, dword ptr [0x4cc2e4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048b36e  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0048b371  2b5110                 -sub edx, dword ptr [ecx + 0x10]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
    // 0048b374  e827030000             -call 0x48b6a0
    cpu.esp -= 4;
    sub_48b6a0(app, cpu);
    if (cpu.terminate) return;
    // 0048b379  39d0                   +cmp eax, edx
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
    // 0048b37b  7f27                   -jg 0x48b3a4
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048b3a4;
    }
    // 0048b37d  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b382  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048b388  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048b38b  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048b38d  e8aecefbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048b392  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b397  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048b39d  e83a57ffff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 0048b3a2  ebba                   -jmp 0x48b35e
    goto L_0x0048b35e;
L_0x0048b3a4:
    // 0048b3a4  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b3a9  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048b3af  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048b3b2  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048b3b4  e887cefbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048b3b9  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b3be  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048b3c1  0f85bfeeffff           -jne 0x48a286
    if (!cpu.flags.zf)
    {
        goto L_0x0048a286;
    }
    // 0048b3c7  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048b3cd  e8f657ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048b3d2  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b3d7  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048b3da  c702ffffffff           -mov dword ptr [edx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx) = 4294967295 /*0xffffffff*/;
    // 0048b3e0  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048b3e3  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0048b3e6  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048b3e9  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048b3ec  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048b3f2  e8e957ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
L_0x0048b3f7:
    // 0048b3f7  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b3fc  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048b3ff  753c                   -jne 0x48b43d
    if (!cpu.flags.zf)
    {
        goto L_0x0048b43d;
    }
    // 0048b401  8b0de4c24c00           -mov ecx, dword ptr [0x4cc2e4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048b407  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 0048b40a  2b5110                 -sub edx, dword ptr [ecx + 0x10]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */)));
    // 0048b40d  e84e020000             -call 0x48b660
    cpu.esp -= 4;
    sub_48b660(app, cpu);
    if (cpu.terminate) return;
    // 0048b412  39d0                   +cmp eax, edx
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
    // 0048b414  7f27                   -jg 0x48b43d
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048b43d;
    }
    // 0048b416  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b41b  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048b421  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048b424  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048b426  e815cefbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048b42b  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b430  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048b436  e8a156ffff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 0048b43b  ebba                   -jmp 0x48b3f7
    goto L_0x0048b3f7;
L_0x0048b43d:
    // 0048b43d  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b442  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048b448  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048b44b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048b44d  e8eecdfbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048b452  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b457  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048b45a  0f8526eeffff           -jne 0x48a286
    if (!cpu.flags.zf)
    {
        goto L_0x0048a286;
    }
    // 0048b460  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048b466  e85d57ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048b46b  8b15e4c24c00           -mov edx, dword ptr [0x4cc2e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048b471  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048b474  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048b477  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048b479  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048b47b  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b480  89484c                 -mov dword ptr [eax + 0x4c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.ecx;
    // 0048b483  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0048b486  8b4010                 -mov eax, dword ptr [eax + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048b489  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048b48c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b48e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048b490  e86b61ffff             -call 0x481600
    cpu.esp -= 4;
    sub_481600(app, cpu);
    if (cpu.terminate) return;
    // 0048b495  a1e4c24c00             -mov eax, dword ptr [0x4cc2e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048b49a  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048b49d  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048b4a0  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b4a5  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048b4a8  8b584c                 -mov ebx, dword ptr [eax + 0x4c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */);
    // 0048b4ab  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048b4ad  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
L_0x0048b4b0:
    // 0048b4b0  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048b4b6  e82557ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
L_0x0048b4bb:
    // 0048b4bb  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b4c0  8b505c                 -mov edx, dword ptr [eax + 0x5c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(92) /* 0x5c */);
    // 0048b4c3  2b504c                 -sub edx, dword ptr [eax + 0x4c]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */)));
    // 0048b4c6  3b5054                 +cmp edx, dword ptr [eax + 0x54]
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
    // 0048b4c9  0f8cb7edffff           -jl 0x48a286
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048a286;
    }
    // 0048b4cf  3b6878                 +cmp ebp, dword ptr [eax + 0x78]
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
    // 0048b4d2  0f85ec000000           -jne 0x48b5c4
    if (!cpu.flags.zf)
    {
        goto L_0x0048b5c4;
    }
    // 0048b4d8  a3e4c24c00             -mov dword ptr [0x4cc2e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */) = cpu.eax;
L_0x0048b4dd:
    // 0048b4dd  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b4e2  3b6824                 +cmp ebp, dword ptr [eax + 0x24]
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
    // 0048b4e5  7564                   -jne 0x48b54b
    if (!cpu.flags.zf)
    {
        goto L_0x0048b54b;
    }
    // 0048b4e7  8b15e4c24c00           -mov edx, dword ptr [0x4cc2e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048b4ed  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b4ef  e86c010000             -call 0x48b660
    cpu.esp -= 4;
    sub_48b660(app, cpu);
    if (cpu.terminate) return;
    // 0048b4f4  03424c                 -add eax, dword ptr [edx + 0x4c]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(76) /* 0x4c */)));
    // 0048b4f7  83f808                 +cmp eax, 8
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
    // 0048b4fa  774f                   -ja 0x48b54b
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048b54b;
    }
    // 0048b4fc  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b501  89b8b4000000           -mov dword ptr [eax + 0xb4], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.edi;
    // 0048b507  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048b50a  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0048b50c  e82fcdfbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048b511  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b516  8b80a8000000           -mov eax, dword ptr [eax + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(168) /* 0xa8 */);
    // 0048b51c  e8bb55ffff             -call 0x480adc
    cpu.esp -= 4;
    sub_480adc(app, cpu);
    if (cpu.terminate) return;
    // 0048b521  ebba                   -jmp 0x48b4dd
    goto L_0x0048b4dd;
L_0x0048b523:
    // 0048b523  8b86ac000000           -mov eax, dword ptr [esi + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */);
    // 0048b529  e89a56ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048b52e  8b15e4c24c00           -mov edx, dword ptr [0x4cc2e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048b534  8b420c                 -mov eax, dword ptr [edx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */);
    // 0048b537  8b4a10                 -mov ecx, dword ptr [edx + 0x10]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */);
    // 0048b53a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b53c  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b541  29ca                   +sub edx, ecx
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
    // 0048b543  89504c                 -mov dword ptr [eax + 0x4c], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(76) /* 0x4c */) = cpu.edx;
    // 0048b546  e965ffffff             -jmp 0x48b4b0
    goto L_0x0048b4b0;
L_0x0048b54b:
    // 0048b54b  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b550  89a8b4000000           -mov dword ptr [eax + 0xb4], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */) = cpu.ebp;
    // 0048b556  8b401c                 -mov eax, dword ptr [eax + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048b559  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048b55b  e8e0ccfbff             -call 0x448240
    cpu.esp -= 4;
    sub_448240(app, cpu);
    if (cpu.terminate) return;
    // 0048b560  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b565  8b5824                 -mov ebx, dword ptr [eax + 0x24]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(36) /* 0x24 */);
    // 0048b568  39dd                   +cmp ebp, ebx
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
    // 0048b56a  7469                   -je 0x48b5d5
    if (cpu.flags.zf)
    {
        goto L_0x0048b5d5;
    }
L_0x0048b56c:
    // 0048b56c  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b571  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048b577  e84c56ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048b57c  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b581  a3e4c24c00             -mov dword ptr [0x4cc2e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */) = cpu.eax;
L_0x0048b586:
    // 0048b586  a1e4c24c00             -mov eax, dword ptr [0x4cc2e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048b58b  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048b58e  c702fdffffff           -mov dword ptr [edx], 0xfffffffd
    app->getMemory<x86::reg32>(cpu.edx) = 4294967293 /*0xfffffffd*/;
    // 0048b594  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048b597  c7420408000000         -mov dword ptr [edx + 4], 8
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = 8 /*0x8*/;
    // 0048b59e  83401008               -add dword ptr [eax + 0x10], 8
    (app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */)) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048b5a2  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0048b5a5  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 0048b5a8  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 0048b5ab  a3e4c24c00             -mov dword ptr [0x4cc2e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */) = cpu.eax;
    // 0048b5b0  39c5                   +cmp ebp, eax
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
    // 0048b5b2  75d2                   -jne 0x48b586
    if (!cpu.flags.zf)
    {
        goto L_0x0048b586;
    }
    // 0048b5b4  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b5b9  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048b5bf  e81c56ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
L_0x0048b5c4:
    // 0048b5c4  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b5c9  c7402007000000         -mov dword ptr [eax + 0x20], 7
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 7 /*0x7*/;
    // 0048b5d0  e9b1ecffff             -jmp 0x48a286
    goto L_0x0048a286;
L_0x0048b5d5:
    // 0048b5d5  a1e4c24c00             -mov eax, dword ptr [0x4cc2e4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */);
    // 0048b5da  8b4070                 -mov eax, dword ptr [eax + 0x70]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(112) /* 0x70 */);
    // 0048b5dd  a3e4c24c00             -mov dword ptr [0x4cc2e4], eax
    app->getMemory<x86::reg32>(x86::reg32(5030628) /* 0x4cc2e4 */) = cpu.eax;
    // 0048b5e2  39c3                   +cmp ebx, eax
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
    // 0048b5e4  0f85f3feffff           -jne 0x48b4dd
    if (!cpu.flags.zf)
    {
        goto L_0x0048b4dd;
    }
    // 0048b5ea  eb80                   -jmp 0x48b56c
    goto L_0x0048b56c;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_48b5ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b5ec  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b5ed  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b5ef  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048b5f5  e8ce55ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048b5fa  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048b5fd  3b4214                 +cmp eax, dword ptr [edx + 0x14]
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
    // 0048b600  7430                   -je 0x48b632
    if (cpu.flags.zf)
    {
        goto L_0x0048b632;
    }
L_0x0048b602:
    // 0048b602  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048b605  3b4210                 +cmp eax, dword ptr [edx + 0x10]
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
    // 0048b608  7428                   -je 0x48b632
    if (cpu.flags.zf)
    {
        goto L_0x0048b632;
    }
    // 0048b60a  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048b60d  8338fe                 +cmp dword ptr [eax], -2
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
    // 0048b610  752d                   -jne 0x48b63f
    if (!cpu.flags.zf)
    {
        goto L_0x0048b63f;
    }
    // 0048b612  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048b615  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048b618  83e808                 -sub eax, 8
    (cpu.eax) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0048b61b  2982bc000000           -sub dword ptr [edx + 0xbc], eax
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(188) /* 0xbc */)) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b621  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048b624  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048b627  014218                 -add dword ptr [edx + 0x18], eax
    (app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */)) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0048b62a:
    // 0048b62a  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048b62d  3b4214                 +cmp eax, dword ptr [edx + 0x14]
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
    // 0048b630  75d0                   -jne 0x48b602
    if (!cpu.flags.zf)
    {
        goto L_0x0048b602;
    }
L_0x0048b632:
    // 0048b632  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 0048b638  e8a355ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048b63d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b63e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b63f:
    // 0048b63f  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048b642  8338ff                 +cmp dword ptr [eax], -1
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
    // 0048b645  75eb                   -jne 0x48b632
    if (!cpu.flags.zf)
    {
        goto L_0x0048b632;
    }
    // 0048b647  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048b64a  3b4214                 +cmp eax, dword ptr [edx + 0x14]
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
    // 0048b64d  7506                   -jne 0x48b655
    if (!cpu.flags.zf)
    {
        goto L_0x0048b655;
    }
    // 0048b64f  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048b652  894214                 -mov dword ptr [edx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(20) /* 0x14 */) = cpu.eax;
L_0x0048b655:
    // 0048b655  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 0048b658  894218                 -mov dword ptr [edx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0048b65b  ebcd                   -jmp 0x48b62a
    goto L_0x0048b62a;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48b660(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b660  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b661  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b663  e884ffffff             -call 0x48b5ec
    cpu.esp -= 4;
    sub_48b5ec(app, cpu);
    if (cpu.terminate) return;
    // 0048b668  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048b66b  3b420c                 +cmp eax, dword ptr [edx + 0xc]
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
    // 0048b66e  7210                   -jb 0x48b680
    if (cpu.flags.cf)
    {
        goto L_0x0048b680;
    }
    // 0048b670  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048b673  3b420c                 +cmp eax, dword ptr [edx + 0xc]
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
    // 0048b676  7510                   -jne 0x48b688
    if (!cpu.flags.zf)
    {
        goto L_0x0048b688;
    }
    // 0048b678  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048b67b  3b4214                 +cmp eax, dword ptr [edx + 0x14]
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
    // 0048b67e  7508                   -jne 0x48b688
    if (!cpu.flags.zf)
    {
        goto L_0x0048b688;
    }
L_0x0048b680:
    // 0048b680  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048b683  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0048b686  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b687  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b688:
    // 0048b688  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048b68b  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0048b68e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b68f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48b690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b690  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b691  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b693  e854ffffff             -call 0x48b5ec
    cpu.esp -= 4;
    sub_48b5ec(app, cpu);
    if (cpu.terminate) return;
    // 0048b698  8b4208                 -mov eax, dword ptr [edx + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048b69b  2b420c                 -sub eax, dword ptr [edx + 0xc]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */)));
    // 0048b69e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b69f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48b6a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b6a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b6a1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b6a3  e844ffffff             -call 0x48b5ec
    cpu.esp -= 4;
    sub_48b5ec(app, cpu);
    if (cpu.terminate) return;
    // 0048b6a8  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048b6ab  3b420c                 +cmp eax, dword ptr [edx + 0xc]
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
    // 0048b6ae  7708                   -ja 0x48b6b8
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048b6b8;
    }
    // 0048b6b0  8b4218                 -mov eax, dword ptr [edx + 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(24) /* 0x18 */);
    // 0048b6b3  2b4204                 -sub eax, dword ptr [edx + 4]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */)));
    // 0048b6b6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b6b7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b6b8:
    // 0048b6b8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b6ba  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b6bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48b6bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b6bc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b6bd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b6be  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b6bf  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048b6c0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048b6c2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b6c4  7437                   -je 0x48b6fd
    if (cpu.flags.zf)
    {
        goto L_0x0048b6fd;
    }
    // 0048b6c6  83787800               +cmp dword ptr [eax + 0x78], 0
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
    // 0048b6ca  7413                   -je 0x48b6df
    if (cpu.flags.zf)
    {
        goto L_0x0048b6df;
    }
    // 0048b6cc  8b4078                 -mov eax, dword ptr [eax + 0x78]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(120) /* 0x78 */);
    // 0048b6cf  8b8094000000           -mov eax, dword ptr [eax + 0x94]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(148) /* 0x94 */);
    // 0048b6d5  83f80d                 +cmp eax, 0xd
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
    // 0048b6d8  7328                   -jae 0x48b702
    if (!cpu.flags.cf)
    {
        goto L_0x0048b702;
    }
    // 0048b6da  83f80b                 +cmp eax, 0xb
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
    // 0048b6dd  7431                   -je 0x48b710
    if (cpu.flags.zf)
    {
        goto L_0x0048b710;
    }
L_0x0048b6df:
    // 0048b6df  83792002               +cmp dword ptr [ecx + 0x20], 2
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
    // 0048b6e3  742b                   -je 0x48b710
    if (cpu.flags.zf)
    {
        goto L_0x0048b710;
    }
    // 0048b6e5  83792001               +cmp dword ptr [ecx + 0x20], 1
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
    // 0048b6e9  7425                   -je 0x48b710
    if (cpu.flags.zf)
    {
        goto L_0x0048b710;
    }
    // 0048b6eb  8379200e               +cmp dword ptr [ecx + 0x20], 0xe
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
    // 0048b6ef  7426                   -je 0x48b717
    if (cpu.flags.zf)
    {
        goto L_0x0048b717;
    }
    // 0048b6f1  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0048b6f4  8b6914                 -mov ebp, dword ptr [ecx + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0048b6f7  39e8                   +cmp eax, ebp
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
    // 0048b6f9  7526                   -jne 0x48b721
    if (!cpu.flags.zf)
    {
        goto L_0x0048b721;
    }
    // 0048b6fb  31e8                   +xor eax, ebp
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.ebp))));
L_0x0048b6fd:
    // 0048b6fd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b6fe  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b6ff  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b700  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b701  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b702:
    // 0048b702  760c                   -jbe 0x48b710
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048b710;
    }
    // 0048b704  83f814                 +cmp eax, 0x14
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
    // 0048b707  72d6                   -jb 0x48b6df
    if (cpu.flags.cf)
    {
        goto L_0x0048b6df;
    }
    // 0048b709  7605                   -jbe 0x48b710
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0048b710;
    }
    // 0048b70b  83f817                 +cmp eax, 0x17
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
    // 0048b70e  75cf                   -jne 0x48b6df
    if (!cpu.flags.zf)
    {
        goto L_0x0048b6df;
    }
L_0x0048b710:
    // 0048b710  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b712  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b713  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b714  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b715  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b716  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b717:
    // 0048b717  b8feffffff             -mov eax, 0xfffffffe
    cpu.eax = 4294967294 /*0xfffffffe*/;
    // 0048b71c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b71d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b71e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b71f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b720  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b721:
    // 0048b721  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0048b727  e89c54ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048b72c  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0048b72f  8338ff                 +cmp dword ptr [eax], -1
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
    // 0048b732  750e                   -jne 0x48b742
    if (!cpu.flags.zf)
    {
        goto L_0x0048b742;
    }
    // 0048b734  8b4104                 -mov eax, dword ptr [ecx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 0048b737  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0048b73a  8b4110                 -mov eax, dword ptr [ecx + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0048b73d  3b4114                 +cmp eax, dword ptr [ecx + 0x14]
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
    // 0048b740  7466                   -je 0x48b7a8
    if (cpu.flags.zf)
    {
        goto L_0x0048b7a8;
    }
L_0x0048b742:
    // 0048b742  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0048b745  8b4004                 -mov eax, dword ptr [eax + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048b748  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0048b74b  3b5114                 +cmp edx, dword ptr [ecx + 0x14]
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
    // 0048b74e  736a                   -jae 0x48b7ba
    if (!cpu.flags.cf)
    {
        goto L_0x0048b7ba;
    }
    // 0048b750  8b5908                 -mov ebx, dword ptr [ecx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 0048b753  2b5914                 -sub ebx, dword ptr [ecx + 0x14]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */)));
    // 0048b756  39c3                   +cmp ebx, eax
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
    // 0048b758  7c4e                   -jl 0x48b7a8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048b7a8;
    }
L_0x0048b75a:
    // 0048b75a  8b5914                 -mov ebx, dword ptr [ecx + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0048b75d  8d50f8                 -lea edx, [eax - 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 0048b760  2991b8000000           -sub dword ptr [ecx + 0xb8], edx
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(184) /* 0xb8 */)) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048b766  0191bc000000           -add dword ptr [ecx + 0xbc], edx
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(188) /* 0xbc */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048b76c  014114                 -add dword ptr [ecx + 0x14], eax
    (app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */)) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048b76f  833bfd                 +cmp dword ptr [ebx], -3
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
    // 0048b772  7522                   -jne 0x48b796
    if (!cpu.flags.zf)
    {
        goto L_0x0048b796;
    }
    // 0048b774  3b5918                 +cmp ebx, dword ptr [ecx + 0x18]
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
    // 0048b777  755d                   -jne 0x48b7d6
    if (!cpu.flags.zf)
    {
        goto L_0x0048b7d6;
    }
    // 0048b779  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0048b77c  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
L_0x0048b77f:
    // 0048b77f  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b784  058c000000             -add eax, 0x8c
    (cpu.eax) += x86::reg32(x86::sreg32(140 /*0x8c*/));
    // 0048b789  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 0048b78e  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048b791  e80a53ffff             -call 0x480aa0
    cpu.esp -= 4;
    sub_480aa0(app, cpu);
    if (cpu.terminate) return;
L_0x0048b796:
    // 0048b796  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0048b79c  e83f54ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048b7a1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048b7a3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b7a4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b7a5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b7a6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b7a7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b7a8:
    // 0048b7a8  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0048b7ae  e82d54ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048b7b3  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b7b5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b7b6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b7b7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b7b8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b7b9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b7ba:
    // 0048b7ba  8b5910                 -mov ebx, dword ptr [ecx + 0x10]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 0048b7bd  2b5914                 -sub ebx, dword ptr [ecx + 0x14]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */)));
    // 0048b7c0  39c3                   +cmp ebx, eax
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
    // 0048b7c2  7d96                   -jge 0x48b75a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048b75a;
    }
    // 0048b7c4  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0048b7ca  e81154ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048b7cf  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048b7d1  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b7d2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b7d3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b7d4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b7d5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b7d6:
    // 0048b7d6  c703feffffff           -mov dword ptr [ebx], 0xfffffffe
    app->getMemory<x86::reg32>(cpu.ebx) = 4294967294 /*0xfffffffe*/;
    // 0048b7dc  eba1                   -jmp 0x48b77f
    goto L_0x0048b77f;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48b7e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b7e0  058c000000             +add eax, 0x8c
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
    // 0048b7e5  c702feffffff           -mov dword ptr [edx], 0xfffffffe
    app->getMemory<x86::reg32>(cpu.edx) = 4294967294 /*0xfffffffe*/;
    // 0048b7eb  8b501c                 -mov edx, dword ptr [eax + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */);
    // 0048b7ee  e9ad52ffff             -jmp 0x480aa0
    return sub_480aa0(app, cpu);
}

/* align: skip 0x90 */
void Application::sub_48b7f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b7f4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b7f6  7406                   -je 0x48b7fe
    if (cpu.flags.zf)
    {
        goto L_0x0048b7fe;
    }
    // 0048b7f8  8b80b8000000           -mov eax, dword ptr [eax + 0xb8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(184) /* 0xb8 */);
L_0x0048b7fe:
    // 0048b7fe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48b800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b800  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b802  7406                   -je 0x48b80a
    if (cpu.flags.zf)
    {
        goto L_0x0048b80a;
    }
    // 0048b804  8b80bc000000           -mov eax, dword ptr [eax + 0xbc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */);
L_0x0048b80a:
    // 0048b80a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48b80c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b80c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b80d  8b15e0c24c00           -mov edx, dword ptr [0x4cc2e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b813  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048b815  7412                   -je 0x48b829
    if (cpu.flags.zf)
    {
        goto L_0x0048b829;
    }
    // 0048b817  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b819  837a2007               +cmp dword ptr [edx + 0x20], 7
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
    // 0048b81d  7506                   -jne 0x48b825
    if (!cpu.flags.zf)
    {
        goto L_0x0048b825;
    }
    // 0048b81f  837a7800               +cmp dword ptr [edx + 0x78], 0
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
    // 0048b823  7404                   -je 0x48b829
    if (cpu.flags.zf)
    {
        goto L_0x0048b829;
    }
L_0x0048b825:
    // 0048b825  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b827  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b828  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b829:
    // 0048b829  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048b82e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b82f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48b830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b830  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b831  8b15e0c24c00           -mov edx, dword ptr [0x4cc2e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b837  8b82ac000000           -mov eax, dword ptr [edx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(172) /* 0xac */);
    // 0048b83d  e88653ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048b842  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0048b844:
    // 0048b844  8982b4000000           -mov dword ptr [edx + 0xb4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(180) /* 0xb4 */) = cpu.eax;
    // 0048b84a  8b5270                 -mov edx, dword ptr [edx + 0x70]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(112) /* 0x70 */);
    // 0048b84d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048b84f  75f3                   -jne 0x48b844
    if (!cpu.flags.zf)
    {
        goto L_0x0048b844;
    }
    // 0048b851  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b856  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048b85c  e87f53ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048b861  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b862  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48b864(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b864  8b80b4000000           -mov eax, dword ptr [eax + 0xb4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(180) /* 0xb4 */);
    // 0048b86a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48b86c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b86c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b86d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048b86f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b871  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048b873  83f8ff                 +cmp eax, -1
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
    // 0048b876  7408                   -je 0x48b880
    if (cpu.flags.zf)
    {
        goto L_0x0048b880;
    }
    // 0048b878  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b87a  740d                   -je 0x48b889
    if (cpu.flags.zf)
    {
        goto L_0x0048b889;
    }
L_0x0048b87c:
    // 0048b87c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b87e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b87f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b880:
    // 0048b880  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048b885  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b887  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b888  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b889:
    // 0048b889  e87effffff             -call 0x48b80c
    cpu.esp -= 4;
    sub_48b80c(app, cpu);
    if (cpu.terminate) return;
    // 0048b88e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b890  74ea                   -je 0x48b87c
    if (cpu.flags.zf)
    {
        goto L_0x0048b87c;
    }
    // 0048b892  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048b894  e85bffffff             -call 0x48b7f4
    cpu.esp -= 4;
    sub_48b7f4(app, cpu);
    if (cpu.terminate) return;
    // 0048b899  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b89b  75df                   -jne 0x48b87c
    if (!cpu.flags.zf)
    {
        goto L_0x0048b87c;
    }
    // 0048b89d  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0048b8a2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b8a4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b8a5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48b8a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b8a8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b8a9  8b15e0c24c00           -mov edx, dword ptr [0x4cc2e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b8af  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048b8b1  7502                   -jne 0x48b8b5
    if (!cpu.flags.zf)
    {
        goto L_0x0048b8b5;
    }
    // 0048b8b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b8b4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b8b5:
    // 0048b8b5  c7423001000000         -mov dword ptr [edx + 0x30], 1
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */) = 1 /*0x1*/;
    // 0048b8bc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b8bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48b8c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b8c0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b8c1  8b15e0c24c00           -mov edx, dword ptr [0x4cc2e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b8c7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048b8c9  7502                   -jne 0x48b8cd
    if (!cpu.flags.zf)
    {
        goto L_0x0048b8cd;
    }
    // 0048b8cb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b8cc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b8cd:
    // 0048b8cd  c7423000000000         -mov dword ptr [edx + 0x30], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */) = 0 /*0x0*/;
    // 0048b8d4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b8d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48b8d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b8d8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b8d9  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0048b8db  8b15e0c24c00           -mov edx, dword ptr [0x4cc2e0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b8e1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048b8e3  742a                   -je 0x48b90f
    if (cpu.flags.zf)
    {
        goto L_0x0048b90f;
    }
    // 0048b8e5  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048b8e6  894274                 -mov dword ptr [edx + 0x74], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(116) /* 0x74 */) = cpu.eax;
    // 0048b8e9  49                     -dec ecx
    (cpu.ecx)--;
    // 0048b8ea  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048b8ec  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048b8ee  7e14                   -jle 0x48b904
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048b904;
    }
L_0x0048b8f0:
    // 0048b8f0  8d989c000000           -lea ebx, [eax + 0x9c]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(156) /* 0x9c */);
    // 0048b8f6  42                     -inc edx
    (cpu.edx)++;
    // 0048b8f7  899898000000           -mov dword ptr [eax + 0x98], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */) = cpu.ebx;
    // 0048b8fd  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048b8ff  39ca                   +cmp edx, ecx
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
    // 0048b901  7ced                   -jl 0x48b8f0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048b8f0;
    }
    // 0048b903  90                     -nop 
    ;
L_0x0048b904:
    // 0048b904  c7809800000000000000   -mov dword ptr [eax + 0x98], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */) = 0 /*0x0*/;
    // 0048b90e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048b90f:
    // 0048b90f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b910  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48b914(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b914  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b915  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b916  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b918  8b0de0c24c00           -mov ecx, dword ptr [0x4cc2e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b91e  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048b920  7503                   -jne 0x48b925
    if (!cpu.flags.zf)
    {
        goto L_0x0048b925;
    }
    // 0048b922  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b923  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b924  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b925:
    // 0048b925  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0048b92b  e89852ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048b930  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b935  8b4874                 -mov ecx, dword ptr [eax + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 0048b938  898a98000000           -mov dword ptr [edx + 0x98], ecx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(152) /* 0x98 */) = cpu.ecx;
    // 0048b93e  895074                 -mov dword ptr [eax + 0x74], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */) = cpu.edx;
    // 0048b941  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048b947  e89452ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048b94c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b94d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b94e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48b950(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b950  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b951  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b952  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b954  8b0de0c24c00           -mov ecx, dword ptr [0x4cc2e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b95a  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048b95c  7505                   -jne 0x48b963
    if (!cpu.flags.zf)
    {
        goto L_0x0048b963;
    }
L_0x0048b95e:
    // 0048b95e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b960  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b961  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b962  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b963:
    // 0048b963  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0048b969  e85a52ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048b96e  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b973  8b4074                 -mov eax, dword ptr [eax + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 0048b976  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048b978  740d                   -je 0x48b987
    if (cpu.flags.zf)
    {
        goto L_0x0048b987;
    }
L_0x0048b97a:
    // 0048b97a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b97c  7409                   -je 0x48b987
    if (cpu.flags.zf)
    {
        goto L_0x0048b987;
    }
    // 0048b97e  8b8098000000           -mov eax, dword ptr [eax + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */);
    // 0048b984  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0048b985  75f3                   -jne 0x48b97a
    if (!cpu.flags.zf)
    {
        goto L_0x0048b97a;
    }
L_0x0048b987:
    // 0048b987  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b98c  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048b992  e84952ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048b997  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048b999  75c3                   -jne 0x48b95e
    if (!cpu.flags.zf)
    {
        goto L_0x0048b95e;
    }
    // 0048b99b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048b9a0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b9a1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b9a2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48b9a4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b9a4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b9a5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b9a6  8b0de0c24c00           -mov ecx, dword ptr [0x4cc2e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b9ac  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048b9ae  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048b9b0  7505                   -jne 0x48b9b7
    if (!cpu.flags.zf)
    {
        goto L_0x0048b9b7;
    }
    // 0048b9b2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048b9b4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b9b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b9b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048b9b7:
    // 0048b9b7  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0048b9bd  e80652ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048b9c2  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b9c7  8b4074                 -mov eax, dword ptr [eax + 0x74]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 0048b9ca  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b9cc  740e                   -je 0x48b9dc
    if (cpu.flags.zf)
    {
        goto L_0x0048b9dc;
    }
L_0x0048b9ce:
    // 0048b9ce  8b8098000000           -mov eax, dword ptr [eax + 0x98]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(152) /* 0x98 */);
    // 0048b9d4  42                     -inc edx
    (cpu.edx)++;
    // 0048b9d5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048b9d7  75f5                   -jne 0x48b9ce
    if (!cpu.flags.zf)
    {
        goto L_0x0048b9ce;
    }
    // 0048b9d9  8d4000                 -lea eax, [eax]
    cpu.eax = x86::reg32(cpu.eax);
L_0x0048b9dc:
    // 0048b9dc  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b9e1  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048b9e7  e8f451ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048b9ec  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048b9ee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b9ef  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048b9f0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48b9f4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048b9f4  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048b9f5  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048b9f6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048b9f8  8b0de0c24c00           -mov ecx, dword ptr [0x4cc2e0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048b9fe  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0048ba00  7505                   -jne 0x48ba07
    if (!cpu.flags.zf)
    {
        goto L_0x0048ba07;
    }
    // 0048ba02  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ba04  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba05  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba06  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ba07:
    // 0048ba07  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0048ba0d  e8b651ffff             -call 0x480bc8
    cpu.esp -= 4;
    sub_480bc8(app, cpu);
    if (cpu.terminate) return;
    // 0048ba12  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048ba17  83787400               +cmp dword ptr [eax + 0x74], 0
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
    // 0048ba1b  7504                   -jne 0x48ba21
    if (!cpu.flags.zf)
    {
        goto L_0x0048ba21;
    }
    // 0048ba1d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048ba1f  742e                   -je 0x48ba4f
    if (cpu.flags.zf)
    {
        goto L_0x0048ba4f;
    }
L_0x0048ba21:
    // 0048ba21  a1e0c24c00             -mov eax, dword ptr [0x4cc2e0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030624) /* 0x4cc2e0 */);
    // 0048ba26  8b5074                 -mov edx, dword ptr [eax + 0x74]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 0048ba29  8b4874                 -mov ecx, dword ptr [eax + 0x74]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */);
    // 0048ba2c  8b8998000000           -mov ecx, dword ptr [ecx + 0x98]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(152) /* 0x98 */);
    // 0048ba32  894874                 -mov dword ptr [eax + 0x74], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(116) /* 0x74 */) = cpu.ecx;
    // 0048ba35  c7829800000000000000   -mov dword ptr [edx + 0x98], 0
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(152) /* 0x98 */) = 0 /*0x0*/;
    // 0048ba3f  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048ba45  e89651ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048ba4a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048ba4c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba4d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba4e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048ba4f:
    // 0048ba4f  8b80ac000000           -mov eax, dword ptr [eax + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(172) /* 0xac */);
    // 0048ba55  e88651ffff             -call 0x480be0
    cpu.esp -= 4;
    sub_480be0(app, cpu);
    if (cpu.terminate) return;
    // 0048ba5a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048ba5c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba5d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba5e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_48ba60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048ba60  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048ba61  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048ba62  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0048ba64  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048ba66  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048ba6d  7421                   -je 0x48ba90
    if (cpu.flags.zf)
    {
        goto L_0x0048ba90;
    }
    // 0048ba6f  833dcccd4c0000         +cmp dword ptr [0x4ccdcc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5033420) /* 0x4ccdcc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048ba76  7522                   -jne 0x48ba9a
    if (!cpu.flags.zf)
    {
        goto L_0x0048ba9a;
    }
    // 0048ba78  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048ba7a  7e28                   -jle 0x48baa4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048baa4;
    }
    // 0048ba7c  8a156dc34c00           -mov dl, byte ptr [0x4cc36d]
    cpu.dl = app->getMemory<x86::reg8>(x86::reg32(5030765) /* 0x4cc36d */);
    // 0048ba82  84d2                   +test dl, dl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dl & cpu.dl));
    // 0048ba84  7428                   -je 0x48baae
    if (cpu.flags.zf)
    {
        goto L_0x0048baae;
    }
    // 0048ba86  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x0048ba8b:
    // 0048ba8b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba8c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba8d  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048ba90:
    // 0048ba90  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0048ba95  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba96  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048ba97  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048ba9a:
    // 0048ba9a  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 0048ba9f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048baa0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048baa1  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048baa4:
    // 0048baa4  b8f8ffffff             -mov eax, 0xfffffff8
    cpu.eax = 4294967288 /*0xfffffff8*/;
    // 0048baa9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048baaa  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048baab  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0048baae:
    // 0048baae  e8fd3cffff             -call 0x47f7b0
    cpu.esp -= 4;
    sub_47f7b0(app, cpu);
    if (cpu.terminate) return;
    // 0048bab3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bab5  7cd4                   -jl 0x48ba8b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048ba8b;
    }
    // 0048bab7  e8700e0000             -call 0x48c92c
    cpu.esp -= 4;
    sub_48c92c(app, cpu);
    if (cpu.terminate) return;
    // 0048babc  881570c34c00           -mov byte ptr [0x4cc370], dl
    app->getMemory<x86::reg8>(x86::reg32(5030768) /* 0x4cc370 */) = cpu.dl;
    // 0048bac2  8a44240c               -mov al, byte ptr [esp + 0xc]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048bac6  a26ec34c00             -mov byte ptr [0x4cc36e], al
    app->getMemory<x86::reg8>(x86::reg32(5030766) /* 0x4cc36e */) = cpu.al;
    // 0048bacb  893decc24c00           -mov dword ptr [0x4cc2ec], edi
    app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */) = cpu.edi;
    // 0048bad1  88156cc34c00           -mov byte ptr [0x4cc36c], dl
    app->getMemory<x86::reg8>(x86::reg32(5030764) /* 0x4cc36c */) = cpu.dl;
    // 0048bad7  881579c34c00           -mov byte ptr [0x4cc379], dl
    app->getMemory<x86::reg8>(x86::reg32(5030777) /* 0x4cc379 */) = cpu.dl;
    // 0048badd  88157ac34c00           -mov byte ptr [0x4cc37a], dl
    app->getMemory<x86::reg8>(x86::reg32(5030778) /* 0x4cc37a */) = cpu.dl;
    // 0048bae3  893584c34c00           -mov dword ptr [0x4cc384], esi
    app->getMemory<x86::reg32>(x86::reg32(5030788) /* 0x4cc384 */) = cpu.esi;
    // 0048bae9  890dfcc24c00           -mov dword ptr [0x4cc2fc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5030652) /* 0x4cc2fc */) = cpu.ecx;
    // 0048baef  c6056dc34c0001         -mov byte ptr [0x4cc36d], 1
    app->getMemory<x86::reg8>(x86::reg32(5030765) /* 0x4cc36d */) = 1 /*0x1*/;
    // 0048baf6  c6057bc34c00ff         -mov byte ptr [0x4cc37b], 0xff
    app->getMemory<x86::reg8>(x86::reg32(5030779) /* 0x4cc37b */) = 255 /*0xff*/;
    // 0048bafd  8b0d28ae5200           -mov ecx, dword ptr [0x52ae28]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5418536) /* 0x52ae28 */);
    // 0048bb03  01d9                   -add ecx, ebx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0048bb05  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0048bb07:
    // 0048bb07  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048bb09  e832e1feff             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 0048bb0e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0048bb10  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048bb12  e8dd0a0000             -call 0x48c5f4
    cpu.esp -= 4;
    sub_48c5f4(app, cpu);
    if (cpu.terminate) return;
    // 0048bb17  3b3580c34c00           +cmp esi, dword ptr [0x4cc380]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5030784) /* 0x4cc380 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048bb1d  7e08                   -jle 0x48bb27
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048bb27;
    }
    // 0048bb1f  3b0d28ae5200           +cmp ecx, dword ptr [0x52ae28]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5418536) /* 0x52ae28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048bb25  77e0                   -ja 0x48bb07
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x0048bb07;
    }
L_0x0048bb27:
    // 0048bb27  a180c34c00             -mov eax, dword ptr [0x4cc380]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030784) /* 0x4cc380 */);
    // 0048bb2c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bb2d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bb2e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48bb34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bb34  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048bb3b  740f                   -je 0x48bb4c
    if (cpu.flags.zf)
    {
        goto L_0x0048bb4c;
    }
    // 0048bb3d  803d6dc34c0002         +cmp byte ptr [0x4cc36d], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030765) /* 0x4cc36d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048bb44  750c                   -jne 0x48bb52
    if (!cpu.flags.zf)
    {
        goto L_0x0048bb52;
    }
    // 0048bb46  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 0048bb4b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bb4c:
    // 0048bb4c  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0048bb51  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bb52:
    // 0048bb52  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bb53  a26fc34c00             -mov byte ptr [0x4cc36f], al
    app->getMemory<x86::reg8>(x86::reg32(5030767) /* 0x4cc36f */) = cpu.al;
    // 0048bb58  881572c34c00           -mov byte ptr [0x4cc372], dl
    app->getMemory<x86::reg8>(x86::reg32(5030770) /* 0x4cc372 */) = cpu.dl;
    // 0048bb5e  b1ff                   -mov cl, 0xff
    cpu.cl = 255 /*0xff*/;
    // 0048bb60  880d73c34c00           -mov byte ptr [0x4cc373], cl
    app->getMemory<x86::reg8>(x86::reg32(5030771) /* 0x4cc373 */) = cpu.cl;
    // 0048bb66  880d74c34c00           -mov byte ptr [0x4cc374], cl
    app->getMemory<x86::reg8>(x86::reg32(5030772) /* 0x4cc374 */) = cpu.cl;
    // 0048bb6c  880d75c34c00           -mov byte ptr [0x4cc375], cl
    app->getMemory<x86::reg8>(x86::reg32(5030773) /* 0x4cc375 */) = cpu.cl;
    // 0048bb72  e8690e0000             -call 0x48c9e0
    cpu.esp -= 4;
    sub_48c9e0(app, cpu);
    if (cpu.terminate) return;
    // 0048bb77  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bb78  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48bb80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bb80  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048bb87  740f                   -je 0x48bb98
    if (cpu.flags.zf)
    {
        goto L_0x0048bb98;
    }
    // 0048bb89  803d6dc34c0000         +cmp byte ptr [0x4cc36d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030765) /* 0x4cc36d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048bb90  750c                   -jne 0x48bb9e
    if (!cpu.flags.zf)
    {
        goto L_0x0048bb9e;
    }
    // 0048bb92  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 0048bb97  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bb98:
    // 0048bb98  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0048bb9d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bb9e:
    // 0048bb9e  a104c34c00             -mov eax, dword ptr [0x4cc304]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030660) /* 0x4cc304 */);
    // 0048bba3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_48bbb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bbb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048bbb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bbb2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0048bbb4  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048bbbb  7411                   -je 0x48bbce
    if (cpu.flags.zf)
    {
        goto L_0x0048bbce;
    }
    // 0048bbbd  833dcccd4c0000         +cmp dword ptr [0x4ccdcc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5033420) /* 0x4ccdcc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048bbc4  7410                   -je 0x48bbd6
    if (cpu.flags.zf)
    {
        goto L_0x0048bbd6;
    }
    // 0048bbc6  b8f0ffffff             -mov eax, 0xfffffff0
    cpu.eax = 4294967280 /*0xfffffff0*/;
    // 0048bbcb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bbcc  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bbcd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bbce:
    // 0048bbce  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0048bbd3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bbd4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bbd5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bbd6:
    // 0048bbd6  e8d5d10000             -call 0x498db0
    cpu.esp -= 4;
    sub_498db0(app, cpu);
    if (cpu.terminate) return;
    // 0048bbdb  e8d03bffff             -call 0x47f7b0
    cpu.esp -= 4;
    sub_47f7b0(app, cpu);
    if (cpu.terminate) return;
    // 0048bbe0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048bbe2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bbe4  7c7d                   -jl 0x48bc63
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048bc63;
    }
    // 0048bbe6  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048bbe7  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 0048bbe9  a2f0c34c00             -mov byte ptr [0x4cc3f0], al
    app->getMemory<x86::reg8>(x86::reg32(5030896) /* 0x4cc3f0 */) = cpu.al;
    // 0048bbee  c60570c34c0001         -mov byte ptr [0x4cc370], 1
    app->getMemory<x86::reg8>(x86::reg32(5030768) /* 0x4cc370 */) = 1 /*0x1*/;
    // 0048bbf5  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048bbf7  8935fcc24c00           -mov dword ptr [0x4cc2fc], esi
    app->getMemory<x86::reg32>(x86::reg32(5030652) /* 0x4cc2fc */) = cpu.esi;
    // 0048bbfd  8a4208                 -mov al, byte ptr [edx + 8]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 0048bc00  a272c34c00             -mov byte ptr [0x4cc372], al
    app->getMemory<x86::reg8>(x86::reg32(5030770) /* 0x4cc372 */) = cpu.al;
    // 0048bc05  8a4207                 -mov al, byte ptr [edx + 7]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(7) /* 0x7 */);
    // 0048bc08  a273c34c00             -mov byte ptr [0x4cc373], al
    app->getMemory<x86::reg8>(x86::reg32(5030771) /* 0x4cc373 */) = cpu.al;
    // 0048bc0d  8a4209                 -mov al, byte ptr [edx + 9]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(9) /* 0x9 */);
    // 0048bc10  a274c34c00             -mov byte ptr [0x4cc374], al
    app->getMemory<x86::reg8>(x86::reg32(5030772) /* 0x4cc374 */) = cpu.al;
    // 0048bc15  8a420a                 -mov al, byte ptr [edx + 0xa]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(10) /* 0xa */);
    // 0048bc18  a275c34c00             -mov byte ptr [0x4cc375], al
    app->getMemory<x86::reg8>(x86::reg32(5030773) /* 0x4cc375 */) = cpu.al;
    // 0048bc1d  891decc24c00           -mov dword ptr [0x4cc2ec], ebx
    app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */) = cpu.ebx;
    // 0048bc23  30d2                   -xor dl, dl
    cpu.dl ^= x86::reg8(x86::sreg8(cpu.dl));
    // 0048bc25  88156cc34c00           -mov byte ptr [0x4cc36c], dl
    app->getMemory<x86::reg8>(x86::reg32(5030764) /* 0x4cc36c */) = cpu.dl;
    // 0048bc2b  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 0048bc2d  883579c34c00           -mov byte ptr [0x4cc379], dh
    app->getMemory<x86::reg8>(x86::reg32(5030777) /* 0x4cc379 */) = cpu.dh;
    // 0048bc33  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0048bc35  881d7ac34c00           -mov byte ptr [0x4cc37a], bl
    app->getMemory<x86::reg8>(x86::reg32(5030778) /* 0x4cc37a */) = cpu.bl;
    // 0048bc3b  c70584c34c000f000000   -mov dword ptr [0x4cc384], 0xf
    app->getMemory<x86::reg32>(x86::reg32(5030788) /* 0x4cc384 */) = 15 /*0xf*/;
    // 0048bc45  c6057bc34c00ff         -mov byte ptr [0x4cc37b], 0xff
    app->getMemory<x86::reg8>(x86::reg32(5030779) /* 0x4cc37b */) = 255 /*0xff*/;
    // 0048bc4c  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 0048bc4e  a27cc34c00             -mov byte ptr [0x4cc37c], al
    app->getMemory<x86::reg8>(x86::reg32(5030780) /* 0x4cc37c */) = cpu.al;
    // 0048bc53  e8d40c0000             -call 0x48c92c
    cpu.esp -= 4;
    sub_48c92c(app, cpu);
    if (cpu.terminate) return;
    // 0048bc58  e867d10000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048bc5d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048bc5f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc60  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc61  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc62  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bc63:
    // 0048bc63  e85cd10000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048bc68  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048bc6a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc6b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc6c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48bc70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bc70  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048bc71  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048bc73  e838ce0000             -call 0x498ab0
    cpu.esp -= 4;
    sub_498ab0(app, cpu);
    if (cpu.terminate) return;
    // 0048bc78  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048bc7f  7410                   -je 0x48bc91
    if (cpu.flags.zf)
    {
        goto L_0x0048bc91;
    }
    // 0048bc81  833dcccd4c0000         +cmp dword ptr [0x4ccdcc], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5033420) /* 0x4ccdcc */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048bc88  750e                   -jne 0x48bc98
    if (!cpu.flags.zf)
    {
        goto L_0x0048bc98;
    }
    // 0048bc8a  b8f2ffffff             -mov eax, 0xfffffff2
    cpu.eax = 4294967282 /*0xfffffff2*/;
    // 0048bc8f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc90  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bc91:
    // 0048bc91  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0048bc96  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bc97  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bc98:
    // 0048bc98  e86f010000             -call 0x48be0c
    cpu.esp -= 4;
    sub_48be0c(app, cpu);
    if (cpu.terminate) return;
    // 0048bc9d  803d78c34c0000         +cmp byte ptr [0x4cc378], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030776) /* 0x4cc378 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048bca4  7412                   -je 0x48bcb8
    if (cpu.flags.zf)
    {
        goto L_0x0048bcb8;
    }
    // 0048bca6  b8f4c54800             -mov eax, 0x48c5f4
    cpu.eax = 4769268 /*0x48c5f4*/;
    // 0048bcab  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 0048bcad  e842dffeff             -call 0x479bf4
    cpu.esp -= 4;
    sub_479bf4(app, cpu);
    if (cpu.terminate) return;
    // 0048bcb2  883578c34c00           -mov byte ptr [0x4cc378], dh
    app->getMemory<x86::reg8>(x86::reg32(5030776) /* 0x4cc378 */) = cpu.dh;
L_0x0048bcb8:
    // 0048bcb8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bcb9  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048bcbb  890dcccd4c00           -mov dword ptr [0x4ccdcc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5033420) /* 0x4ccdcc */) = cpu.ecx;
    // 0048bcc1  e8ea3affff             -call 0x47f7b0
    cpu.esp -= 4;
    sub_47f7b0(app, cpu);
    if (cpu.terminate) return;
    // 0048bcc6  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048bcc8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bcc9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bcca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48bccc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bccc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bccd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048bcce  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048bccf  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048bcd1  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0048bcd3  8a25b0cd4c00           -mov ah, byte ptr [0x4ccdb0]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
    // 0048bcd9  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0048bcdb  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0048bcdd  750b                   -jne 0x48bcea
    if (!cpu.flags.zf)
    {
        goto L_0x0048bcea;
    }
    // 0048bcdf  bff6ffffff             -mov edi, 0xfffffff6
    cpu.edi = 4294967286 /*0xfffffff6*/;
    // 0048bce4  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048bce6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bce7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bce8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bce9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bcea:
    // 0048bcea  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048bceb  e8c0d00000             -call 0x498db0
    cpu.esp -= 4;
    sub_498db0(app, cpu);
    if (cpu.terminate) return;
    // 0048bcf0  803d6dc34c0000         +cmp byte ptr [0x4cc36d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030765) /* 0x4cc36d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048bcf7  7567                   -jne 0x48bd60
    if (!cpu.flags.zf)
    {
        goto L_0x0048bd60;
    }
    // 0048bcf9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048bcfb  7549                   -jne 0x48bd46
    if (!cpu.flags.zf)
    {
        goto L_0x0048bd46;
    }
    // 0048bcfd  a1ecc24c00             -mov eax, dword ptr [0x4cc2ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048bd02  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048bd04  e8e3e1ffff             -call 0x489eec
    cpu.esp -= 4;
    sub_489eec(app, cpu);
    if (cpu.terminate) return;
L_0x0048bd09:
    // 0048bd09  b601                   -mov dh, 1
    cpu.dh = 1 /*0x1*/;
    // 0048bd0b  e81c0c0000             -call 0x48c92c
    cpu.esp -= 4;
    sub_48c92c(app, cpu);
    if (cpu.terminate) return;
    // 0048bd10  88356dc34c00           -mov byte ptr [0x4cc36d], dh
    app->getMemory<x86::reg8>(x86::reg32(5030765) /* 0x4cc36d */) = cpu.dh;
L_0x0048bd16:
    // 0048bd16  a079c34c00             -mov al, byte ptr [0x4cc379]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5030777) /* 0x4cc379 */);
    // 0048bd1b  fe0579c34c00           -inc byte ptr [0x4cc379]
    (app->getMemory<x86::reg8>(x86::reg32(5030777) /* 0x4cc379 */))++;
    // 0048bd21  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 0048bd26  b8f0c34c00             -mov eax, 0x4cc3f0
    cpu.eax = 5030896 /*0x4cc3f0*/;
    // 0048bd2b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048bd2d  e88a02ffff             -call 0x47bfbc
    cpu.esp -= 4;
    sub_47bfbc(app, cpu);
    if (cpu.terminate) return;
    // 0048bd32  30ff                   +xor bh, bh
    cpu.clear_co();
    cpu.set_szp((cpu.bh ^= x86::reg8(x86::sreg8(cpu.bh))));
    // 0048bd34  883d6fc44c00           -mov byte ptr [0x4cc46f], bh
    app->getMemory<x86::reg8>(x86::reg32(5031023) /* 0x4cc46f */) = cpu.bh;
    // 0048bd3a  e885d00000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048bd3f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd40  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048bd42  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd43  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd45  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bd46:
    // 0048bd46  a1ecc24c00             -mov eax, dword ptr [0x4cc2ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048bd4b  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048bd4d  e81ae2ffff             -call 0x489f6c
    cpu.esp -= 4;
    sub_489f6c(app, cpu);
    if (cpu.terminate) return;
    // 0048bd52  a1ecc24c00             -mov eax, dword ptr [0x4cc2ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048bd57  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048bd59  e86ee2ffff             -call 0x489fcc
    cpu.esp -= 4;
    sub_489fcc(app, cpu);
    if (cpu.terminate) return;
    // 0048bd5e  eba9                   -jmp 0x48bd09
    goto L_0x0048bd09;
L_0x0048bd60:
    // 0048bd60  0fbe1579c34c00         -movsx edx, byte ptr [0x4cc379]
    cpu.edx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5030777) /* 0x4cc379 */)));
    // 0048bd67  0fbe057ac34c00         -movsx eax, byte ptr [0x4cc37a]
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5030778) /* 0x4cc37a */)));
    // 0048bd6e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048bd70  83f813                 +cmp eax, 0x13
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
    // 0048bd73  7c11                   -jl 0x48bd86
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048bd86;
    }
    // 0048bd75  bff3ffffff             -mov edi, 0xfffffff3
    cpu.edi = 4294967283 /*0xfffffff3*/;
    // 0048bd7a  e845d00000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048bd7f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd80  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048bd82  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd83  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd84  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bd85  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bd86:
    // 0048bd86  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0048bd88  7530                   -jne 0x48bdba
    if (!cpu.flags.zf)
    {
        goto L_0x0048bdba;
    }
    // 0048bd8a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048bd8f  e8bcfbffff             -call 0x48b950
    cpu.esp -= 4;
    sub_48b950(app, cpu);
    if (cpu.terminate) return;
    // 0048bd94  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bd96  7511                   -jne 0x48bda9
    if (!cpu.flags.zf)
    {
        goto L_0x0048bda9;
    }
    // 0048bd98  bff3ffffff             -mov edi, 0xfffffff3
    cpu.edi = 4294967283 /*0xfffffff3*/;
    // 0048bd9d  e822d00000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048bda2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bda3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048bda5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bda6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bda7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bda8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bda9:
    // 0048bda9  a1ecc24c00             -mov eax, dword ptr [0x4cc2ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048bdae  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048bdb0  e807e1ffff             -call 0x489ebc
    cpu.esp -= 4;
    sub_489ebc(app, cpu);
    if (cpu.terminate) return;
    // 0048bdb5  e95cffffff             -jmp 0x48bd16
    goto L_0x0048bd16;
L_0x0048bdba:
    // 0048bdba  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0048bdbf  e88cfbffff             -call 0x48b950
    cpu.esp -= 4;
    sub_48b950(app, cpu);
    if (cpu.terminate) return;
    // 0048bdc4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bdc6  7511                   -jne 0x48bdd9
    if (!cpu.flags.zf)
    {
        goto L_0x0048bdd9;
    }
    // 0048bdc8  bff3ffffff             -mov edi, 0xfffffff3
    cpu.edi = 4294967283 /*0xfffffff3*/;
    // 0048bdcd  e8f2cf0000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048bdd2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bdd3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048bdd5  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bdd6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bdd7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bdd8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bdd9:
    // 0048bdd9  bb80000000             -mov ebx, 0x80
    cpu.ebx = 128 /*0x80*/;
    // 0048bdde  b8f0c34c00             -mov eax, 0x4cc3f0
    cpu.eax = 5030896 /*0x4cc3f0*/;
    // 0048bde3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048bde5  e8d667ffff             -call 0x4825c0
    cpu.esp -= 4;
    sub_4825c0(app, cpu);
    if (cpu.terminate) return;
    // 0048bdea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bdec  740c                   -je 0x48bdfa
    if (cpu.flags.zf)
    {
        goto L_0x0048bdfa;
    }
    // 0048bdee  a1ecc24c00             -mov eax, dword ptr [0x4cc2ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048bdf3  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048bdf5  e842e1ffff             -call 0x489f3c
    cpu.esp -= 4;
    sub_489f3c(app, cpu);
    if (cpu.terminate) return;
L_0x0048bdfa:
    // 0048bdfa  a1ecc24c00             -mov eax, dword ptr [0x4cc2ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048bdff  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0048be01  e8c6e1ffff             -call 0x489fcc
    cpu.esp -= 4;
    sub_489fcc(app, cpu);
    if (cpu.terminate) return;
    // 0048be06  e90bffffff             -jmp 0x48bd16
    goto L_0x0048bd16;
}

/* align: skip 0x90 */
void Application::sub_48be0c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048be0c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048be0d  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048be14  7507                   -jne 0x48be1d
    if (!cpu.flags.zf)
    {
        goto L_0x0048be1d;
    }
    // 0048be16  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0048be1b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048be1c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048be1d:
    // 0048be1d  a100c34c00             -mov eax, dword ptr [0x4cc300]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030656) /* 0x4cc300 */);
    // 0048be22  e89946ffff             -call 0x4804c0
    cpu.esp -= 4;
    sub_4804c0(app, cpu);
    if (cpu.terminate) return;
    // 0048be27  8b1528ae5200           -mov edx, dword ptr [0x52ae28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5418536) /* 0x52ae28 */);
    // 0048be2d  81c2c8000000           -add edx, 0xc8
    (cpu.edx) += x86::reg32(x86::sreg32(200 /*0xc8*/));
L_0x0048be33:
    // 0048be33  a100c34c00             -mov eax, dword ptr [0x4cc300]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030656) /* 0x4cc300 */);
    // 0048be38  e8e3fcfeff             -call 0x47bb20
    cpu.esp -= 4;
    sub_47bb20(app, cpu);
    if (cpu.terminate) return;
    // 0048be3d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048be3f  7516                   -jne 0x48be57
    if (!cpu.flags.zf)
    {
        goto L_0x0048be57;
    }
    // 0048be41  3b1528ae5200           +cmp edx, dword ptr [0x52ae28]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5418536) /* 0x52ae28 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048be47  7207                   -jb 0x48be50
    if (cpu.flags.cf)
    {
        goto L_0x0048be50;
    }
    // 0048be49  e8f2ddfeff             -call 0x479c40
    cpu.esp -= 4;
    sub_479c40(app, cpu);
    if (cpu.terminate) return;
    // 0048be4e  ebe3                   -jmp 0x48be33
    goto L_0x0048be33;
L_0x0048be50:
    // 0048be50  b8efffffff             -mov eax, 0xffffffef
    cpu.eax = 4294967279 /*0xffffffef*/;
    // 0048be55  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048be56  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048be57:
    // 0048be57  e854cf0000             -call 0x498db0
    cpu.esp -= 4;
    sub_498db0(app, cpu);
    if (cpu.terminate) return;
    // 0048be5c  b2ff                   -mov dl, 0xff
    cpu.dl = 255 /*0xff*/;
    // 0048be5e  e869020000             -call 0x48c0cc
    cpu.esp -= 4;
    sub_48c0cc(app, cpu);
    if (cpu.terminate) return;
    // 0048be63  88157bc34c00           -mov byte ptr [0x4cc37b], dl
    app->getMemory<x86::reg8>(x86::reg32(5030779) /* 0x4cc37b */) = cpu.dl;
    // 0048be69  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 0048be6b  88357cc34c00           -mov byte ptr [0x4cc37c], dh
    app->getMemory<x86::reg8>(x86::reg32(5030780) /* 0x4cc37c */) = cpu.dh;
    // 0048be71  883579c34c00           -mov byte ptr [0x4cc379], dh
    app->getMemory<x86::reg8>(x86::reg32(5030777) /* 0x4cc379 */) = cpu.dh;
    // 0048be77  88357ac34c00           -mov byte ptr [0x4cc37a], dh
    app->getMemory<x86::reg8>(x86::reg32(5030778) /* 0x4cc37a */) = cpu.dh;
    // 0048be7d  88356dc34c00           -mov byte ptr [0x4cc36d], dh
    app->getMemory<x86::reg8>(x86::reg32(5030765) /* 0x4cc36d */) = cpu.dh;
    // 0048be83  8835f0c34c00           -mov byte ptr [0x4cc3f0], dh
    app->getMemory<x86::reg8>(x86::reg32(5030896) /* 0x4cc3f0 */) = cpu.dh;
    // 0048be89  88356cc34c00           -mov byte ptr [0x4cc36c], dh
    app->getMemory<x86::reg8>(x86::reg32(5030764) /* 0x4cc36c */) = cpu.dh;
    // 0048be8f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048be91  e81acc0000             -call 0x498ab0
    cpu.esp -= 4;
    sub_498ab0(app, cpu);
    if (cpu.terminate) return;
    // 0048be96  803d78c34c0000         +cmp byte ptr [0x4cc378], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030776) /* 0x4cc378 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048be9d  7410                   -je 0x48beaf
    if (cpu.flags.zf)
    {
        goto L_0x0048beaf;
    }
    // 0048be9f  b8f4c54800             -mov eax, 0x48c5f4
    cpu.eax = 4769268 /*0x48c5f4*/;
    // 0048bea4  e84bddfeff             -call 0x479bf4
    cpu.esp -= 4;
    sub_479bf4(app, cpu);
    if (cpu.terminate) return;
    // 0048bea9  883578c34c00           -mov byte ptr [0x4cc378], dh
    app->getMemory<x86::reg8>(x86::reg32(5030776) /* 0x4cc378 */) = cpu.dh;
L_0x0048beaf:
    // 0048beaf  e810cf0000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048beb4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048beb6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048beb7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48beb8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048beb8  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048beb9  8a25b0cd4c00           -mov ah, byte ptr [0x4ccdb0]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
    // 0048bebf  baf2ffffff             -mov edx, 0xfffffff2
    cpu.edx = 4294967282 /*0xfffffff2*/;
    // 0048bec4  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0048bec6  7509                   -jne 0x48bed1
    if (!cpu.flags.zf)
    {
        goto L_0x0048bed1;
    }
    // 0048bec8  baf6ffffff             -mov edx, 0xfffffff6
    cpu.edx = 4294967286 /*0xfffffff6*/;
    // 0048becd  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048becf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bed0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bed1:
    // 0048bed1  e8dace0000             -call 0x498db0
    cpu.esp -= 4;
    sub_498db0(app, cpu);
    if (cpu.terminate) return;
    // 0048bed6  803d6dc34c0000         +cmp byte ptr [0x4cc36d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030765) /* 0x4cc36d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048bedd  741e                   -je 0x48befd
    if (cpu.flags.zf)
    {
        goto L_0x0048befd;
    }
    // 0048bedf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0048bee1  a06fc34c00             -mov al, byte ptr [0x4cc36f]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5030767) /* 0x4cc36f */);
    // 0048bee6  e8c538ffff             -call 0x47f7b0
    cpu.esp -= 4;
    sub_47f7b0(app, cpu);
    if (cpu.terminate) return;
    // 0048beeb  8b1508c34c00           -mov edx, dword ptr [0x4cc308]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030664) /* 0x4cc308 */);
    // 0048bef1  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048bef3  803d7dc34c0002         +cmp byte ptr [0x4cc37d], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030781) /* 0x4cc37d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048befa  7501                   -jne 0x48befd
    if (!cpu.flags.zf)
    {
        goto L_0x0048befd;
    }
    // 0048befc  4a                     -dec edx
    (cpu.edx)--;
L_0x0048befd:
    // 0048befd  e8c2ce0000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048bf02  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048bf04  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bf05  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48bf08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bf08  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048bf0f  7506                   -jne 0x48bf17
    if (!cpu.flags.zf)
    {
        goto L_0x0048bf17;
    }
    // 0048bf11  b8f6ffffff             -mov eax, 0xfffffff6
    cpu.eax = 4294967286 /*0xfffffff6*/;
    // 0048bf16  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bf17:
    // 0048bf17  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048bf18  e893ce0000             -call 0x498db0
    cpu.esp -= 4;
    sub_498db0(app, cpu);
    if (cpu.terminate) return;
    // 0048bf1d  803d6dc34c0000         +cmp byte ptr [0x4cc36d], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030765) /* 0x4cc36d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048bf24  750e                   -jne 0x48bf34
    if (!cpu.flags.zf)
    {
        goto L_0x0048bf34;
    }
L_0x0048bf26:
    // 0048bf26  baf2ffffff             -mov edx, 0xfffffff2
    cpu.edx = 4294967282 /*0xfffffff2*/;
    // 0048bf2b  e894ce0000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048bf30  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048bf32  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bf33  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bf34:
    // 0048bf34  803d6dc34c0001         +cmp byte ptr [0x4cc36d], 1
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030765) /* 0x4cc36d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(1 /*0x1*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048bf3b  74e9                   -je 0x48bf26
    if (cpu.flags.zf)
    {
        goto L_0x0048bf26;
    }
    // 0048bf3d  803d6fc34c0000         +cmp byte ptr [0x4cc36f], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030767) /* 0x4cc36f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048bf44  750e                   -jne 0x48bf54
    if (!cpu.flags.zf)
    {
        goto L_0x0048bf54;
    }
    // 0048bf46  baf9ffffff             -mov edx, 0xfffffff9
    cpu.edx = 4294967289 /*0xfffffff9*/;
    // 0048bf4b  e874ce0000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048bf50  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048bf52  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bf53  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bf54:
    // 0048bf54  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048bf55  e85effffff             -call 0x48beb8
    cpu.esp -= 4;
    sub_48beb8(app, cpu);
    if (cpu.terminate) return;
    // 0048bf5a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048bf5c  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048bf5f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0048bf61  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048bf64  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048bf66  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0048bf69  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048bf6b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0048bf6e  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0048bf70  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0048bf72  8a0d6fc34c00           -mov cl, byte ptr [0x4cc36f]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5030767) /* 0x4cc36f */);
    // 0048bf78  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048bf7a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0048bf7d  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0048bf7f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048bf81  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bf82  e83dce0000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048bf87  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048bf89  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bf8a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48bf8c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048bf8c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048bf8d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048bf8f  803db0cd4c0000         +cmp byte ptr [0x4ccdb0], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048bf96  7404                   -je 0x48bf9c
    if (cpu.flags.zf)
    {
        goto L_0x0048bf9c;
    }
    // 0048bf98  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0048bf9a  7f02                   -jg 0x48bf9e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0048bf9e;
    }
L_0x0048bf9c:
    // 0048bf9c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bf9d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bf9e:
    // 0048bf9e  e865ddfeff             -call 0x479d08
    cpu.esp -= 4;
    sub_479d08(app, cpu);
    if (cpu.terminate) return;
    // 0048bfa3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bfa5  7509                   -jne 0x48bfb0
    if (!cpu.flags.zf)
    {
        goto L_0x0048bfb0;
    }
    // 0048bfa7  e85cffffff             -call 0x48bf08
    cpu.esp -= 4;
    sub_48bf08(app, cpu);
    if (cpu.terminate) return;
    // 0048bfac  39d0                   +cmp eax, edx
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
    // 0048bfae  7d47                   -jge 0x48bff7
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0048bff7;
    }
L_0x0048bfb0:
    // 0048bfb0  e857f8ffff             -call 0x48b80c
    cpu.esp -= 4;
    sub_48b80c(app, cpu);
    if (cpu.terminate) return;
    // 0048bfb5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bfb7  753e                   -jne 0x48bff7
    if (!cpu.flags.zf)
    {
        goto L_0x0048bff7;
    }
    // 0048bfb9  a1ecc24c00             -mov eax, dword ptr [0x4cc2ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048bfbe  e8a1f8ffff             -call 0x48b864
    cpu.esp -= 4;
    sub_48b864(app, cpu);
    if (cpu.terminate) return;
    // 0048bfc3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bfc5  7417                   -je 0x48bfde
    if (cpu.flags.zf)
    {
        goto L_0x0048bfde;
    }
    // 0048bfc7  a1ecc24c00             -mov eax, dword ptr [0x4cc2ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048bfcc  e823f8ffff             -call 0x48b7f4
    cpu.esp -= 4;
    sub_48b7f4(app, cpu);
    if (cpu.terminate) return;
    // 0048bfd1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bfd3  7509                   -jne 0x48bfde
    if (!cpu.flags.zf)
    {
        goto L_0x0048bfde;
    }
    // 0048bfd5  e82eddfeff             -call 0x479d08
    cpu.esp -= 4;
    sub_479d08(app, cpu);
    if (cpu.terminate) return;
    // 0048bfda  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048bfdc  741e                   -je 0x48bffc
    if (cpu.flags.zf)
    {
        goto L_0x0048bffc;
    }
L_0x0048bfde:
    // 0048bfde  8915dcc34c00           -mov dword ptr [0x4cc3dc], edx
    app->getMemory<x86::reg32>(x86::reg32(5030876) /* 0x4cc3dc */) = cpu.edx;
    // 0048bfe4  833d74c44c0000         +cmp dword ptr [0x4cc474], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5031028) /* 0x4cc474 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048bfeb  74af                   -je 0x48bf9c
    if (cpu.flags.zf)
    {
        goto L_0x0048bf9c;
    }
    // 0048bfed  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048bfef  ff1574c44c00           -call dword ptr [0x4cc474]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5031028) /* 0x4cc474 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 0048bff5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048bff6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048bff7:
    // 0048bff7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0048bffc:
    // 0048bffc  e847cb0000             -call 0x498b48
    cpu.esp -= 4;
    sub_498b48(app, cpu);
    if (cpu.terminate) return;
    // 0048c001  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c002  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48c004(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c004  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c005  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c006  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048c008  8a25b0cd4c00           -mov ah, byte ptr [0x4ccdb0]
    cpu.ah = app->getMemory<x86::reg8>(x86::reg32(5033392) /* 0x4ccdb0 */);
    // 0048c00e  b9f1ffffff             -mov ecx, 0xfffffff1
    cpu.ecx = 4294967281 /*0xfffffff1*/;
    // 0048c013  84e4                   +test ah, ah
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & cpu.ah));
    // 0048c015  750a                   -jne 0x48c021
    if (!cpu.flags.zf)
    {
        goto L_0x0048c021;
    }
    // 0048c017  b9f6ffffff             -mov ecx, 0xfffffff6
    cpu.ecx = 4294967286 /*0xfffffff6*/;
    // 0048c01c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048c01e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c01f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c020  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c021:
    // 0048c021  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c022  e889cd0000             -call 0x498db0
    cpu.esp -= 4;
    sub_498db0(app, cpu);
    if (cpu.terminate) return;
    // 0048c027  8b1a                   -mov ebx, dword ptr [edx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048c029  81fb5343446c           +cmp ebx, 0x6c444353
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
    // 0048c02f  7514                   -jne 0x48c045
    if (!cpu.flags.zf)
    {
        goto L_0x0048c045;
    }
    // 0048c031  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048c033  e814010000             -call 0x48c14c
    cpu.esp -= 4;
    sub_48c14c(app, cpu);
    if (cpu.terminate) return;
    // 0048c038  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048c03a  e885cd0000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048c03f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c040  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048c042  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c043  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c044  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c045:
    // 0048c045  81fb5343486c           +cmp ebx, 0x6c484353
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
    // 0048c04b  742c                   -je 0x48c079
    if (cpu.flags.zf)
    {
        goto L_0x0048c079;
    }
    // 0048c04d  81fb5343436c           +cmp ebx, 0x6c434353
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
    // 0048c053  7438                   -je 0x48c08d
    if (cpu.flags.zf)
    {
        goto L_0x0048c08d;
    }
    // 0048c055  81fb53434c6c           +cmp ebx, 0x6c4c4353
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
    // 0048c05b  7444                   -je 0x48c0a1
    if (cpu.flags.zf)
    {
        goto L_0x0048c0a1;
    }
    // 0048c05d  81fb5343456c           +cmp ebx, 0x6c454353
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
    // 0048c063  7550                   -jne 0x48c0b5
    if (!cpu.flags.zf)
    {
        goto L_0x0048c0b5;
    }
    // 0048c065  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048c067  e8d0020000             -call 0x48c33c
    cpu.esp -= 4;
    sub_48c33c(app, cpu);
    if (cpu.terminate) return;
    // 0048c06c  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048c06e  e851cd0000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048c073  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c074  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048c076  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c077  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c078  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c079:
    // 0048c079  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048c07b  e820010000             -call 0x48c1a0
    cpu.esp -= 4;
    sub_48c1a0(app, cpu);
    if (cpu.terminate) return;
    // 0048c080  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048c082  e83dcd0000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048c087  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c088  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048c08a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c08b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c08c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c08d:
    // 0048c08d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048c08f  e814020000             -call 0x48c2a8
    cpu.esp -= 4;
    sub_48c2a8(app, cpu);
    if (cpu.terminate) return;
    // 0048c094  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048c096  e829cd0000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048c09b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c09c  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048c09e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c09f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c0a0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c0a1:
    // 0048c0a1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0048c0a3  e86c020000             -call 0x48c314
    cpu.esp -= 4;
    sub_48c314(app, cpu);
    if (cpu.terminate) return;
    // 0048c0a8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048c0aa  e815cd0000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048c0af  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c0b0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048c0b2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c0b3  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c0b4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c0b5:
    // 0048c0b5  a1ecc24c00             -mov eax, dword ptr [0x4cc2ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048c0ba  e821f7ffff             -call 0x48b7e0
    cpu.esp -= 4;
    sub_48b7e0(app, cpu);
    if (cpu.terminate) return;
    // 0048c0bf  e800cd0000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048c0c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c0c5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048c0c7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c0c8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c0c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48c0cc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c0cc  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c0cd  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048c0ce  e8ddcc0000             -call 0x498db0
    cpu.esp -= 4;
    sub_498db0(app, cpu);
    if (cpu.terminate) return;
    // 0048c0d3  833df0c24c0000         +cmp dword ptr [0x4cc2f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5030640) /* 0x4cc2f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c0da  7454                   -je 0x48c130
    if (cpu.flags.zf)
    {
        goto L_0x0048c130;
    }
L_0x0048c0dc:
    // 0048c0dc  a1f0c24c00             -mov eax, dword ptr [0x4cc2f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030640) /* 0x4cc2f0 */);
    // 0048c0e1  3b05f4c24c00           +cmp eax, dword ptr [0x4cc2f4]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5030644) /* 0x4cc2f4 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c0e7  741e                   -je 0x48c107
    if (cpu.flags.zf)
    {
        goto L_0x0048c107;
    }
    // 0048c0e9  8b15f0c24c00           -mov edx, dword ptr [0x4cc2f0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030640) /* 0x4cc2f0 */);
    // 0048c0ef  a1f0c24c00             -mov eax, dword ptr [0x4cc2f0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030640) /* 0x4cc2f0 */);
    // 0048c0f4  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0048c0f6  a3f0c24c00             -mov dword ptr [0x4cc2f0], eax
    app->getMemory<x86::reg32>(x86::reg32(5030640) /* 0x4cc2f0 */) = cpu.eax;
    // 0048c0fb  a1ecc24c00             -mov eax, dword ptr [0x4cc2ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048c100  e8dbf6ffff             -call 0x48b7e0
    cpu.esp -= 4;
    sub_48b7e0(app, cpu);
    if (cpu.terminate) return;
    // 0048c105  ebd5                   -jmp 0x48c0dc
    goto L_0x0048c0dc;
L_0x0048c107:
    // 0048c107  8b15f0c24c00           -mov edx, dword ptr [0x4cc2f0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030640) /* 0x4cc2f0 */);
    // 0048c10d  a1ecc24c00             -mov eax, dword ptr [0x4cc2ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048c112  e8c9f6ffff             -call 0x48b7e0
    cpu.esp -= 4;
    sub_48b7e0(app, cpu);
    if (cpu.terminate) return;
    // 0048c117  833df8c24c0000         +cmp dword ptr [0x4cc2f8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5030648) /* 0x4cc2f8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c11e  7410                   -je 0x48c130
    if (cpu.flags.zf)
    {
        goto L_0x0048c130;
    }
    // 0048c120  8b15f8c24c00           -mov edx, dword ptr [0x4cc2f8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030648) /* 0x4cc2f8 */);
    // 0048c126  a1ecc24c00             -mov eax, dword ptr [0x4cc2ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048c12b  e8b0f6ffff             -call 0x48b7e0
    cpu.esp -= 4;
    sub_48b7e0(app, cpu);
    if (cpu.terminate) return;
L_0x0048c130:
    // 0048c130  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0048c132  8935f0c24c00           -mov dword ptr [0x4cc2f0], esi
    app->getMemory<x86::reg32>(x86::reg32(5030640) /* 0x4cc2f0 */) = cpu.esi;
    // 0048c138  8935f4c24c00           -mov dword ptr [0x4cc2f4], esi
    app->getMemory<x86::reg32>(x86::reg32(5030644) /* 0x4cc2f4 */) = cpu.esi;
    // 0048c13e  8935f8c24c00           -mov dword ptr [0x4cc2f8], esi
    app->getMemory<x86::reg32>(x86::reg32(5030648) /* 0x4cc2f8 */) = cpu.esi;
    // 0048c144  e87bcc0000             -call 0x498dc4
    cpu.esp -= 4;
    sub_498dc4(app, cpu);
    if (cpu.terminate) return;
    // 0048c149  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c14a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c14b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_48c14c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c14c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c14d  8b1508c34c00           -mov edx, dword ptr [0x4cc308]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030664) /* 0x4cc308 */);
    // 0048c153  ff0508c34c00           -inc dword ptr [0x4cc308]
    (app->getMemory<x86::reg32>(x86::reg32(5030664) /* 0x4cc308 */))++;
    // 0048c159  8b5004                 -mov edx, dword ptr [eax + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 0048c15c  01150cc34c00           -add dword ptr [0x4cc30c], edx
    (app->getMemory<x86::reg32>(x86::reg32(5030668) /* 0x4cc30c */)) += x86::reg32(x86::sreg32(cpu.edx));
    // 0048c162  8338ff                 +cmp dword ptr [eax], -1
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
    // 0048c165  751a                   -jne 0x48c181
    if (!cpu.flags.zf)
    {
        goto L_0x0048c181;
    }
L_0x0048c167:
    // 0048c167  833df0c24c0000         +cmp dword ptr [0x4cc2f0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5030640) /* 0x4cc2f0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c16e  7519                   -jne 0x48c189
    if (!cpu.flags.zf)
    {
        goto L_0x0048c189;
    }
    // 0048c170  a3f0c24c00             -mov dword ptr [0x4cc2f0], eax
    app->getMemory<x86::reg32>(x86::reg32(5030640) /* 0x4cc2f0 */) = cpu.eax;
    // 0048c175  a3f4c24c00             -mov dword ptr [0x4cc2f4], eax
    app->getMemory<x86::reg32>(x86::reg32(5030644) /* 0x4cc2f4 */) = cpu.eax;
    // 0048c17a  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0048c17f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c180  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c181:
    // 0048c181  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 0048c187  ebde                   -jmp 0x48c167
    goto L_0x0048c167;
L_0x0048c189:
    // 0048c189  8b15f4c24c00           -mov edx, dword ptr [0x4cc2f4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5030644) /* 0x4cc2f4 */);
    // 0048c18f  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0048c191  a3f4c24c00             -mov dword ptr [0x4cc2f4], eax
    app->getMemory<x86::reg32>(x86::reg32(5030644) /* 0x4cc2f4 */) = cpu.eax;
    // 0048c196  b803000000             -mov eax, 3
    cpu.eax = 3 /*0x3*/;
    // 0048c19b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c19c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8d 0x40 0x00 */
void Application::sub_48c1a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c1a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c1a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c1a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c1a3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0048c1a4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c1a5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0048c1a6  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048c1a9  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0048c1ab  bb08000000             -mov ebx, 8
    cpu.ebx = 8 /*0x8*/;
    // 0048c1b0  803d7bc34c0000         +cmp byte ptr [0x4cc37b], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030779) /* 0x4cc37b */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c1b7  7e0b                   -jle 0x48c1c4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048c1c4;
    }
    // 0048c1b9  a07bc34c00             -mov al, byte ptr [0x4cc37b]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5030779) /* 0x4cc37b */);
    // 0048c1be  fe0d7bc34c00           -dec byte ptr [0x4cc37b]
    (app->getMemory<x86::reg8>(x86::reg32(5030779) /* 0x4cc37b */))--;
L_0x0048c1c4:
    // 0048c1c4  8b4504                 -mov eax, dword ptr [ebp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(4) /* 0x4 */);
    // 0048c1c7  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0048c1c9  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0048c1cd  01eb                   -add ebx, ebp
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0048c1cf  803d70c34c0000         +cmp byte ptr [0x4cc370], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030768) /* 0x4cc370 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c1d6  7551                   -jne 0x48c229
    if (!cpu.flags.zf)
    {
        goto L_0x0048c229;
    }
L_0x0048c1d8:
    // 0048c1d8  8b4c240c               -mov ecx, dword ptr [esp + 0xc]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0048c1dc  bf10c34c00             -mov edi, 0x4cc310
    cpu.edi = 5030672 /*0x4cc310*/;
    // 0048c1e1  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0048c1e3  baffffffff             -mov edx, 0xffffffff
    cpu.edx = 4294967295 /*0xffffffff*/;
    // 0048c1e8  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0048c1e9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048c1eb  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 0048c1ee  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048c1f0  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 0048c1f2  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 0048c1f5  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 0048c1f7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c1f8  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 0048c1fa  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0048c1fd  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0048c1ff  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0048c201  b501                   -mov ch, 1
    cpu.ch = 1 /*0x1*/;
    // 0048c203  e868c40000             -call 0x498670
    cpu.esp -= 4;
    sub_498670(app, cpu);
    if (cpu.terminate) return;
    // 0048c208  882d6cc34c00           -mov byte ptr [0x4cc36c], ch
    app->getMemory<x86::reg8>(x86::reg32(5030764) /* 0x4cc36c */) = cpu.ch;
    // 0048c20e  a1ecc24c00             -mov eax, dword ptr [0x4cc2ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048c213  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0048c215  e8c6f5ffff             -call 0x48b7e0
    cpu.esp -= 4;
    sub_48b7e0(app, cpu);
    if (cpu.terminate) return;
    // 0048c21a  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0048c21f  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 0048c222  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c223  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c224  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c225  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c226  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c227  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c228  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0048c229:
    // 0048c229  a07ac34c00             -mov al, byte ptr [0x4cc37a]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5030778) /* 0x4cc37a */);
    // 0048c22e  fe057ac34c00           -inc byte ptr [0x4cc37a]
    (app->getMemory<x86::reg8>(x86::reg32(5030778) /* 0x4cc37a */))++;
    // 0048c234  a079c34c00             -mov al, byte ptr [0x4cc379]
    cpu.al = app->getMemory<x86::reg8>(x86::reg32(5030777) /* 0x4cc379 */);
    // 0048c239  fe0d79c34c00           -dec byte ptr [0x4cc379]
    (app->getMemory<x86::reg8>(x86::reg32(5030777) /* 0x4cc379 */))--;
    // 0048c23f  bfe0c34c00             -mov edi, 0x4cc3e0
    cpu.edi = 5030880 /*0x4cc3e0*/;
    // 0048c244  bee8c34c00             -mov esi, 0x4cc3e8
    cpu.esi = 5030888 /*0x4cc3e8*/;
    // 0048c249  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048c24a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0048c24b  bae8c34c00             -mov edx, 0x4cc3e8
    cpu.edx = 5030888 /*0x4cc3e8*/;
    // 0048c250  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0048c252  e849410100             -call 0x4a03a0
    cpu.esp -= 4;
    sub_4a03a0(app, cpu);
    if (cpu.terminate) return;
    // 0048c257  803d7cc34c0000         +cmp byte ptr [0x4cc37c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030780) /* 0x4cc37c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c25e  743c                   -je 0x48c29c
    if (cpu.flags.zf)
    {
        goto L_0x0048c29c;
    }
    // 0048c260  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0048c265  bfe0c34c00             -mov edi, 0x4cc3e0
    cpu.edi = 5030880 /*0x4cc3e0*/;
    // 0048c26a  bee8c34c00             -mov esi, 0x4cc3e8
    cpu.esi = 5030888 /*0x4cc3e8*/;
    // 0048c26f  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0048c271  f3a6                   +repe cmpsb byte ptr [esi], byte ptr es:[edi]
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
    // 0048c273  7405                   -je 0x48c27a
    if (cpu.flags.zf)
    {
        goto L_0x0048c27a;
    }
    // 0048c275  19c0                   +sbb eax, eax
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
    // 0048c277  83d8ff                 -sbb eax, -1
    (cpu.eax) -= x86::reg32(x86::sreg32(-1 /*-0x1*/) + cpu.flags.cf);
L_0x0048c27a:
    // 0048c27a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0048c27c  741e                   -je 0x48c29c
    if (cpu.flags.zf)
    {
        goto L_0x0048c29c;
    }
    // 0048c27e  803d6dc34c0002         +cmp byte ptr [0x4cc36d], 2
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030765) /* 0x4cc36d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(2 /*0x2*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c285  740e                   -je 0x48c295
    if (cpu.flags.zf)
    {
        goto L_0x0048c295;
    }
    // 0048c287  803d6dc34c0003         +cmp byte ptr [0x4cc36d], 3
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030765) /* 0x4cc36d */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(3 /*0x3*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c28e  7405                   -je 0x48c295
    if (cpu.flags.zf)
    {
        goto L_0x0048c295;
    }
    // 0048c290  e84b070000             -call 0x48c9e0
    cpu.esp -= 4;
    sub_48c9e0(app, cpu);
    if (cpu.terminate) return;
L_0x0048c295:
    // 0048c295  c6056dc34c0003         -mov byte ptr [0x4cc36d], 3
    app->getMemory<x86::reg8>(x86::reg32(5030765) /* 0x4cc36d */) = 3 /*0x3*/;
L_0x0048c29c:
    // 0048c29c  c6057cc34c0001         -mov byte ptr [0x4cc37c], 1
    app->getMemory<x86::reg8>(x86::reg32(5030780) /* 0x4cc37c */) = 1 /*0x1*/;
    // 0048c2a3  e930ffffff             -jmp 0x48c1d8
    goto L_0x0048c1d8;
}

/* align: skip  */
void Application::sub_48c2a8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c2a8  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c2a9  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c2aa  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048c2ad  8a0d7ec34c00           -mov cl, byte ptr [0x4cc37e]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5030782) /* 0x4cc37e */);
    // 0048c2b3  3a0d7fc34c00           +cmp cl, byte ptr [0x4cc37f]
    {
        x86::reg8 tmp1 = cpu.cl;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(app->getMemory<x86::reg8>(x86::reg32(5030783) /* 0x4cc37f */)));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c2b9  7511                   -jne 0x48c2cc
    if (!cpu.flags.zf)
    {
        goto L_0x0048c2cc;
    }
    // 0048c2bb  0fbe0d7ec34c00         -movsx ecx, byte ptr [0x4cc37e]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5030782) /* 0x4cc37e */)));
    // 0048c2c2  833c8d8cc34c0000       +cmp dword ptr [ecx*4 + 0x4cc38c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5030796) /* 0x4cc38c */ + cpu.ecx * 4);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0048c2ca  7e0c                   -jle 0x48c2d8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0048c2d8;
    }
L_0x0048c2cc:
    // 0048c2cc  8a0d7fc34c00           -mov cl, byte ptr [0x4cc37f]
    cpu.cl = app->getMemory<x86::reg8>(x86::reg32(5030783) /* 0x4cc37f */);
    // 0048c2d2  fe057fc34c00           -inc byte ptr [0x4cc37f]
    (app->getMemory<x86::reg8>(x86::reg32(5030783) /* 0x4cc37f */))++;
L_0x0048c2d8:
    // 0048c2d8  803d7fc34c0014         +cmp byte ptr [0x4cc37f], 0x14
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030783) /* 0x4cc37f */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(20 /*0x14*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c2df  7c0a                   -jl 0x48c2eb
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0048c2eb;
    }
    // 0048c2e1  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0048c2e2  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 0048c2e4  881d7fc34c00           -mov byte ptr [0x4cc37f], bl
    app->getMemory<x86::reg8>(x86::reg32(5030783) /* 0x4cc37f */) = cpu.bl;
    // 0048c2ea  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0048c2eb:
    // 0048c2eb  0fbe0d7fc34c00         -movsx ecx, byte ptr [0x4cc37f]
    cpu.ecx = x86::reg32(static_cast<x86::sreg8>(app->getMemory<x86::reg8>(x86::reg32(5030783) /* 0x4cc37f */)));
    // 0048c2f2  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048c2f4  89148d8cc34c00         -mov dword ptr [ecx*4 + 0x4cc38c], edx
    app->getMemory<x86::reg32>(x86::reg32(5030796) /* 0x4cc38c */ + cpu.ecx * 4) = cpu.edx;
    // 0048c2fb  8b0decc24c00           -mov ecx, dword ptr [0x4cc2ec]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048c301  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048c303  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048c305  e8d6f4ffff             -call 0x48b7e0
    cpu.esp -= 4;
    sub_48b7e0(app, cpu);
    if (cpu.terminate) return;
    // 0048c30a  b802000000             -mov eax, 2
    cpu.eax = 2 /*0x2*/;
    // 0048c30f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c310  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c311  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x8b 0xc0 */
void Application::sub_48c314(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c314  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c315  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c316  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0048c318  8d5008                 -lea edx, [eax + 8]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 0048c31b  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0048c31d  a1ecc24c00             -mov eax, dword ptr [0x4cc2ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048c322  e86ddcffff             -call 0x489f94
    cpu.esp -= 4;
    sub_489f94(app, cpu);
    if (cpu.terminate) return;
    // 0048c327  a1ecc24c00             -mov eax, dword ptr [0x4cc2ec]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048c32c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0048c32e  e8adf4ffff             -call 0x48b7e0
    cpu.esp -= 4;
    sub_48b7e0(app, cpu);
    if (cpu.terminate) return;
    // 0048c333  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 0048c338  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c339  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c33a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x90 */
void Application::sub_48c33c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0048c33c  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0048c33d  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0048c33e  ff05e8c24c00           -inc dword ptr [0x4cc2e8]
    (app->getMemory<x86::reg32>(x86::reg32(5030632) /* 0x4cc2e8 */))++;
    // 0048c344  803d6ec34c0000         +cmp byte ptr [0x4cc36e], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5030766) /* 0x4cc36e */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0048c34b  750c                   -jne 0x48c359
    if (!cpu.flags.zf)
    {
        goto L_0x0048c359;
    }
    // 0048c34d  8b0df4c24c00           -mov ecx, dword ptr [0x4cc2f4]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5030644) /* 0x4cc2f4 */);
    // 0048c353  c701ffffffff           -mov dword ptr [ecx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ecx) = 4294967295 /*0xffffffff*/;
L_0x0048c359:
    // 0048c359  8b0decc24c00           -mov ecx, dword ptr [0x4cc2ec]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5030636) /* 0x4cc2ec */);
    // 0048c35f  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0048c361  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0048c363  e878f4ffff             -call 0x48b7e0
    cpu.esp -= 4;
    sub_48b7e0(app, cpu);
    if (cpu.terminate) return;
    // 0048c368  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0048c36d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c36e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0048c36f  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
