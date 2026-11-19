#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip  */
void Application::sub_4b6404(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6404);
    // 004b6404  b8747a5b00             -mov eax, 0x5b7a74
    cpu.eax = 5995124 /*0x5b7a74*/;
    // 004b6409  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b640a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b640b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b640c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b640d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b640f  2eff15a0444c00         -call dword ptr cs:[0x4c44a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998304) /* 0x4c44a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6416  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b6419  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b641b  39d0                   +cmp eax, edx
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
    // 004b641d  7443                   -je 0x4b6462
    if (cpu.flags.zf)
    {
        goto L_0x004b6462;
    }
    // 004b641f  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 004b6423  7530                   -jne 0x4b6455
    if (!cpu.flags.zf)
    {
        goto L_0x004b6455;
    }
    // 004b6425  b8547a5b00             -mov eax, 0x5b7a54
    cpu.eax = 5995092 /*0x5b7a54*/;
    // 004b642a  e8daffffff             -call 0x4b6409
    cpu.esp -= 4;
    sub_4b6409(app, cpu);
    if (cpu.terminate) return;
    // 004b642f  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 004b6433  7516                   -jne 0x4b644b
    if (!cpu.flags.zf)
    {
        goto L_0x004b644b;
    }
    // 004b6435  e8c6feffff             -call 0x4b6300
    cpu.esp -= 4;
    sub_4b6300(app, cpu);
    if (cpu.terminate) return;
    // 004b643a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b643b  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004b643d  2eff1510454c00         -call dword ptr cs:[0x4c4510]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998416) /* 0x4c4510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6444  c7430401000000         -mov dword ptr [ebx + 4], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
L_0x004b644b:
    // 004b644b  b8547a5b00             -mov eax, 0x5b7a54
    cpu.eax = 5995092 /*0x5b7a54*/;
    // 004b6450  e81a000000             -call 0x4b646f
    cpu.esp -= 4;
    sub_4b646f(app, cpu);
    if (cpu.terminate) return;
L_0x004b6455:
    // 004b6455  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b6457  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b6458  2eff1550444c00         -call dword ptr cs:[0x4c4450]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998224) /* 0x4c4450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b645f  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x004b6462:
    // 004b6462  ff430c                 -inc dword ptr [ebx + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */))++;
    // 004b6465  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6466  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6467  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6468  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6469  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6409(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6409);
    goto L_entry_0x004b6409;
    // 004b6404  b8747a5b00             -mov eax, 0x5b7a74
    cpu.eax = 5995124 /*0x5b7a74*/;
L_entry_0x004b6409:
    // 004b6409  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b640a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b640b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b640c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b640d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b640f  2eff15a0444c00         -call dword ptr cs:[0x4c44a0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998304) /* 0x4c44a0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6416  8b5308                 -mov edx, dword ptr [ebx + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b6419  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b641b  39d0                   +cmp eax, edx
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
    // 004b641d  7443                   -je 0x4b6462
    if (cpu.flags.zf)
    {
        goto L_0x004b6462;
    }
    // 004b641f  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 004b6423  7530                   -jne 0x4b6455
    if (!cpu.flags.zf)
    {
        goto L_0x004b6455;
    }
    // 004b6425  b8547a5b00             -mov eax, 0x5b7a54
    cpu.eax = 5995092 /*0x5b7a54*/;
    // 004b642a  e8daffffff             -call 0x4b6409
    cpu.esp -= 4;
    sub_4b6409(app, cpu);
    if (cpu.terminate) return;
    // 004b642f  837b0400               +cmp dword ptr [ebx + 4], 0
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
    // 004b6433  7516                   -jne 0x4b644b
    if (!cpu.flags.zf)
    {
        goto L_0x004b644b;
    }
    // 004b6435  e8c6feffff             -call 0x4b6300
    cpu.esp -= 4;
    sub_4b6300(app, cpu);
    if (cpu.terminate) return;
    // 004b643a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b643b  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 004b643d  2eff1510454c00         -call dword ptr cs:[0x4c4510]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998416) /* 0x4c4510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6444  c7430401000000         -mov dword ptr [ebx + 4], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */) = 1 /*0x1*/;
L_0x004b644b:
    // 004b644b  b8547a5b00             -mov eax, 0x5b7a54
    cpu.eax = 5995092 /*0x5b7a54*/;
    // 004b6450  e81a000000             -call 0x4b646f
    cpu.esp -= 4;
    sub_4b646f(app, cpu);
    if (cpu.terminate) return;
L_0x004b6455:
    // 004b6455  8b03                   -mov eax, dword ptr [ebx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b6457  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b6458  2eff1550444c00         -call dword ptr cs:[0x4c4450]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998224) /* 0x4c4450 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b645f  897308                 -mov dword ptr [ebx + 8], esi
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */) = cpu.esi;
L_0x004b6462:
    // 004b6462  ff430c                 -inc dword ptr [ebx + 0xc]
    (app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(12) /* 0xc */))++;
    // 004b6465  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6466  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6467  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6468  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6469  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b646a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b646a);
    // 004b646a  b8747a5b00             -mov eax, 0x5b7a74
    cpu.eax = 5995124 /*0x5b7a74*/;
    // 004b646f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6470  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6471  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6472  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6473  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004b6476  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b6478  7617                   -jbe 0x4b6491
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b6491;
    }
    // 004b647a  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004b647d  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004b6480  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b6482  750d                   -jne 0x4b6491
    if (!cpu.flags.zf)
    {
        goto L_0x004b6491;
    }
    // 004b6484  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004b6486  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6487  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004b648a  2eff1514454c00         -call dword ptr cs:[0x4c4514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998420) /* 0x4c4514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b6491:
    // 004b6491  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6492  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6493  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6494  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6495  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b646f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b646f);
    goto L_entry_0x004b646f;
    // 004b646a  b8747a5b00             -mov eax, 0x5b7a74
    cpu.eax = 5995124 /*0x5b7a74*/;
L_entry_0x004b646f:
    // 004b646f  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6470  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6471  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6472  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6473  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004b6476  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b6478  7617                   -jbe 0x4b6491
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b6491;
    }
    // 004b647a  8d5aff                 -lea ebx, [edx - 1]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-1) /* -0x1 */);
    // 004b647d  89580c                 -mov dword ptr [eax + 0xc], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.ebx;
    // 004b6480  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b6482  750d                   -jne 0x4b6491
    if (!cpu.flags.zf)
    {
        goto L_0x004b6491;
    }
    // 004b6484  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004b6486  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6487  895808                 -mov dword ptr [eax + 8], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 004b648a  2eff1514454c00         -call dword ptr cs:[0x4c4514]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998420) /* 0x4c4514 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b6491:
    // 004b6491  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6492  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6493  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6494  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6495  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6496(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6496);
    // 004b6496  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6497  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6498  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6499  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b649a  2eff15c4444c00         -call dword ptr cs:[0x4c44c4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998340) /* 0x4c44c4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b64a1  8b1518cb4d00           -mov edx, dword ptr [0x4dcb18]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5098264) /* 0x4dcb18 */);
    // 004b64a7  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b64a8  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b64aa  2eff1588454c00         -call dword ptr cs:[0x4c4588]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998536) /* 0x4c4588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b64b1  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b64b3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b64b5  7507                   -jne 0x4b64be
    if (!cpu.flags.zf)
    {
        goto L_0x004b64be;
    }
    // 004b64b7  e8c06a0000             -call 0x4bcf7c
    cpu.esp -= 4;
    sub_4bcf7c(app, cpu);
    if (cpu.terminate) return;
    // 004b64bc  eb0b                   -jmp 0x4b64c9
    goto L_0x004b64c9;
L_0x004b64be:
    // 004b64be  80785300               +cmp byte ptr [eax + 0x53], 0
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
    // 004b64c2  7407                   -je 0x4b64cb
    if (cpu.flags.zf)
    {
        goto L_0x004b64cb;
    }
    // 004b64c4  e8ec6a0000             -call 0x4bcfb5
    cpu.esp -= 4;
    sub_4bcfb5(app, cpu);
    if (cpu.terminate) return;
L_0x004b64c9:
    // 004b64c9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004b64cb:
    // 004b64cb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b64cc  2eff1568454c00         -call dword ptr cs:[0x4c4568]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998504) /* 0x4c4568 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b64d3  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b64d5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b64d6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b64d7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b64d8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b64d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b64da(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b64da);
    // 004b64da  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b64db  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b64dc  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b64de  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b64e0  7526                   -jne 0x4b6508
    if (!cpu.flags.zf)
    {
        goto L_0x004b6508;
    }
    // 004b64e2  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b64e7  8b157ce74d00           -mov edx, dword ptr [0x4de77c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5105532) /* 0x4de77c */);
    // 004b64ed  e8726a0000             -call 0x4bcf64
    cpu.esp -= 4;
    sub_4bcf64(app, cpu);
    if (cpu.terminate) return;
    // 004b64f2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b64f4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b64f6  7410                   -je 0x4b6508
    if (cpu.flags.zf)
    {
        goto L_0x004b6508;
    }
    // 004b64f8  8b1d7ce74d00           -mov ebx, dword ptr [0x4de77c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5105532) /* 0x4de77c */);
    // 004b64fe  c6405201               -mov byte ptr [eax + 0x52], 1
    app->getMemory<x86::reg8>(cpu.eax + x86::reg32(82) /* 0x52 */) = 1 /*0x1*/;
    // 004b6502  8998f0000000           -mov dword ptr [eax + 0xf0], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(240) /* 0xf0 */) = cpu.ebx;
L_0x004b6508:
    // 004b6508  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b650a  e8716c0000             -call 0x4bd180
    cpu.esp -= 4;
    sub_4bd180(app, cpu);
    if (cpu.terminate) return;
    // 004b650f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b6511  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6512  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6513  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6514(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6514);
    // 004b6514  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6515  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6516  2eff1580454c00         -call dword ptr cs:[0x4c4580]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998528) /* 0x4c4580 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b651d  668b15d1b84d00         -mov dx, word ptr [0x4db8d1]
    cpu.dx = app->getMemory<x86::reg16>(x86::reg32(5093585) /* 0x4db8d1 */);
    // 004b6524  a318cb4d00             -mov dword ptr [0x4dcb18], eax
    app->getMemory<x86::reg32>(x86::reg32(5098264) /* 0x4dcb18 */) = cpu.eax;
    // 004b6529  6681fa0080             +cmp dx, 0x8000
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
    // 004b652e  7227                   -jb 0x4b6557
    if (cpu.flags.cf)
    {
        goto L_0x004b6557;
    }
    // 004b6530  803dcfb84d0004         +cmp byte ptr [0x4db8cf], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5093583) /* 0x4db8cf */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b6537  731e                   -jae 0x4b6557
    if (!cpu.flags.cf)
    {
        goto L_0x004b6557;
    }
L_0x004b6539:
    // 004b6539  8b1518cb4d00           -mov edx, dword ptr [0x4dcb18]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5098264) /* 0x4dcb18 */);
    // 004b653f  83faff                 +cmp edx, -1
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
    // 004b6542  7413                   -je 0x4b6557
    if (cpu.flags.zf)
    {
        goto L_0x004b6557;
    }
    // 004b6544  83fa02                 +cmp edx, 2
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
    // 004b6547  770e                   -ja 0x4b6557
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b6557;
    }
    // 004b6549  2eff1580454c00         -call dword ptr cs:[0x4c4580]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998528) /* 0x4c4580 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6550  a318cb4d00             -mov dword ptr [0x4dcb18], eax
    app->getMemory<x86::reg32>(x86::reg32(5098264) /* 0x4dcb18 */) = cpu.eax;
    // 004b6555  ebe2                   -jmp 0x4b6539
    goto L_0x004b6539;
L_0x004b6557:
    // 004b6557  833d18cb4d00ff         +cmp dword ptr [0x4dcb18], -1
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
    // 004b655e  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004b6561  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b6566  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6567  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6568  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6569(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6569);
    // 004b6569  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b656a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b656b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b656c  833d18cb4d00ff         +cmp dword ptr [0x4dcb18], -1
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
    // 004b6573  7506                   -jne 0x4b657b
    if (!cpu.flags.zf)
    {
        goto L_0x004b657b;
    }
L_0x004b6575:
    // 004b6575  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b6577  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6578  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6579  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b657a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b657b:
    // 004b657b  e85affffff             -call 0x4b64da
    cpu.esp -= 4;
    sub_4b64da(app, cpu);
    if (cpu.terminate) return;
    // 004b6580  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b6582  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b6584  742e                   -je 0x4b65b4
    if (cpu.flags.zf)
    {
        goto L_0x004b65b4;
    }
    // 004b6586  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b6588  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 004b658e  e8f66a0000             -call 0x4bd089
    cpu.esp -= 4;
    sub_4bd089(app, cpu);
    if (cpu.terminate) return;
    // 004b6593  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b6595  7509                   -jne 0x4b65a0
    if (!cpu.flags.zf)
    {
        goto L_0x004b65a0;
    }
    // 004b6597  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b6599  e81a0bffff             -call 0x4a70b8
    cpu.esp -= 4;
    sub_4a70b8(app, cpu);
    if (cpu.terminate) return;
    // 004b659e  ebd5                   -jmp 0x4b6575
    goto L_0x004b6575;
L_0x004b65a0:
    // 004b65a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b65a1  8b1d18cb4d00           -mov ebx, dword ptr [0x4dcb18]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5098264) /* 0x4dcb18 */);
    // 004b65a7  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b65a8  2eff158c454c00         -call dword ptr cs:[0x4c458c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998540) /* 0x4c458c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b65af  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004b65b4:
    // 004b65b4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b65b5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b65b6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b65b7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b65b8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b65b8);
    // 004b65b8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b65b9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b65ba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b65bb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b65bc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b65bd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b65bf  8b1518cb4d00           -mov edx, dword ptr [0x4dcb18]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5098264) /* 0x4dcb18 */);
    // 004b65c5  83faff                 +cmp edx, -1
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
    // 004b65c8  743d                   -je 0x4b6607
    if (cpu.flags.zf)
    {
        goto L_0x004b6607;
    }
    // 004b65ca  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b65cb  2eff1588454c00         -call dword ptr cs:[0x4c4588]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998536) /* 0x4c4588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b65d2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b65d4  7431                   -je 0x4b6607
    if (cpu.flags.zf)
    {
        goto L_0x004b6607;
    }
    // 004b65d6  8bb0de000000           -mov esi, dword ptr [eax + 0xde]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(222) /* 0xde */);
    // 004b65dc  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 004b65e2  e8036b0000             -call 0x4bd0ea
    cpu.esp -= 4;
    sub_4bd0ea(app, cpu);
    if (cpu.terminate) return;
    // 004b65e7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b65e9  8b3d18cb4d00           -mov edi, dword ptr [0x4dcb18]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5098264) /* 0x4dcb18 */);
    // 004b65ef  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b65f0  2eff158c454c00         -call dword ptr cs:[0x4c458c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998540) /* 0x4c458c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b65f7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b65f9  740c                   -je 0x4b6607
    if (cpu.flags.zf)
    {
        goto L_0x004b6607;
    }
    // 004b65fb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b65fd  7408                   -je 0x4b6607
    if (cpu.flags.zf)
    {
        goto L_0x004b6607;
    }
    // 004b65ff  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6600  2eff1528444c00         -call dword ptr cs:[0x4c4428]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998184) /* 0x4c4428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b6607:
    // 004b6607  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6608  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6609  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b660a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b660b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b660c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6607(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6607);
    goto L_entry_0x004b6607;
    // 004b65b8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b65b9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b65ba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b65bb  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b65bc  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b65bd  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b65bf  8b1518cb4d00           -mov edx, dword ptr [0x4dcb18]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5098264) /* 0x4dcb18 */);
    // 004b65c5  83faff                 +cmp edx, -1
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
    // 004b65c8  743d                   -je 0x4b6607
    if (cpu.flags.zf)
    {
        goto L_0x004b6607;
    }
    // 004b65ca  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b65cb  2eff1588454c00         -call dword ptr cs:[0x4c4588]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998536) /* 0x4c4588 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b65d2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b65d4  7431                   -je 0x4b6607
    if (cpu.flags.zf)
    {
        goto L_0x004b6607;
    }
    // 004b65d6  8bb0de000000           -mov esi, dword ptr [eax + 0xde]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(222) /* 0xde */);
    // 004b65dc  8b80da000000           -mov eax, dword ptr [eax + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(218) /* 0xda */);
    // 004b65e2  e8036b0000             -call 0x4bd0ea
    cpu.esp -= 4;
    sub_4bd0ea(app, cpu);
    if (cpu.terminate) return;
    // 004b65e7  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b65e9  8b3d18cb4d00           -mov edi, dword ptr [0x4dcb18]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5098264) /* 0x4dcb18 */);
    // 004b65ef  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b65f0  2eff158c454c00         -call dword ptr cs:[0x4c458c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998540) /* 0x4c458c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b65f7  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b65f9  740c                   -je 0x4b6607
    if (cpu.flags.zf)
    {
        goto L_0x004b6607;
    }
    // 004b65fb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b65fd  7408                   -je 0x4b6607
    if (cpu.flags.zf)
    {
        goto L_0x004b6607;
    }
    // 004b65ff  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6600  2eff1528444c00         -call dword ptr cs:[0x4c4428]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998184) /* 0x4c4428 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b6607:
L_entry_0x004b6607:
    // 004b6607  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6608  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6609  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b660a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b660b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b660c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b660d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b660d);
    // 004b660d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b6612  e8a1ffffff             -call 0x4b65b8
    cpu.esp -= 4;
    sub_4b65b8(app, cpu);
    if (cpu.terminate) return;
    // 004b6617  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6618  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6619  8b1518cb4d00           -mov edx, dword ptr [0x4dcb18]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5098264) /* 0x4dcb18 */);
    // 004b661f  83faff                 +cmp edx, -1
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
    // 004b6622  7412                   -je 0x4b6636
    if (cpu.flags.zf)
    {
        goto L_0x004b6636;
    }
    // 004b6624  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6625  2eff1584454c00         -call dword ptr cs:[0x4c4584]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998532) /* 0x4c4584 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b662c  c70518cb4d00ffffffff   -mov dword ptr [0x4dcb18], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5098264) /* 0x4dcb18 */) = 4294967295 /*0xffffffff*/;
L_0x004b6636:
    // 004b6636  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6637  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6638  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6617(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6617);
    goto L_entry_0x004b6617;
    // 004b660d  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b6612  e8a1ffffff             -call 0x4b65b8
    cpu.esp -= 4;
    sub_4b65b8(app, cpu);
    if (cpu.terminate) return;
L_entry_0x004b6617:
    // 004b6617  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6618  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6619  8b1518cb4d00           -mov edx, dword ptr [0x4dcb18]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5098264) /* 0x4dcb18 */);
    // 004b661f  83faff                 +cmp edx, -1
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
    // 004b6622  7412                   -je 0x4b6636
    if (cpu.flags.zf)
    {
        goto L_0x004b6636;
    }
    // 004b6624  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6625  2eff1584454c00         -call dword ptr cs:[0x4c4584]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998532) /* 0x4c4584 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b662c  c70518cb4d00ffffffff   -mov dword ptr [0x4dcb18], 0xffffffff
    app->getMemory<x86::reg32>(x86::reg32(5098264) /* 0x4dcb18 */) = 4294967295 /*0xffffffff*/;
L_0x004b6636:
    // 004b6636  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6637  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6638  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6639(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6639);
    // 004b6639  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b663a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b663b  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b663c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b663d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b663e  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b663f  ba96634b00             -mov edx, 0x4b6396
    cpu.edx = 4940694 /*0x4b6396*/;
    // 004b6644  bba3634b00             -mov ebx, 0x4b63a3
    cpu.ebx = 4940707 /*0x4b63a3*/;
    // 004b6649  b9b3634b00             -mov ecx, 0x4b63b3
    cpu.ecx = 4940723 /*0x4b63b3*/;
    // 004b664e  beb8634b00             -mov esi, 0x4b63b8
    cpu.esi = 4940728 /*0x4b63b8*/;
    // 004b6653  bf82634b00             -mov edi, 0x4b6382
    cpu.edi = 4940674 /*0x4b6382*/;
    // 004b6658  bd8c634b00             -mov ebp, 0x4b638c
    cpu.ebp = 4940684 /*0x4b638c*/;
    // 004b665d  b8f6634b00             -mov eax, 0x4b63f6
    cpu.eax = 4940790 /*0x4b63f6*/;
    // 004b6662  891520cb4d00           -mov dword ptr [0x4dcb20], edx
    app->getMemory<x86::reg32>(x86::reg32(5098272) /* 0x4dcb20 */) = cpu.edx;
    // 004b6668  891d24cb4d00           -mov dword ptr [0x4dcb24], ebx
    app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */) = cpu.ebx;
    // 004b666e  890d28cb4d00           -mov dword ptr [0x4dcb28], ecx
    app->getMemory<x86::reg32>(x86::reg32(5098280) /* 0x4dcb28 */) = cpu.ecx;
    // 004b6674  89352ccb4d00           -mov dword ptr [0x4dcb2c], esi
    app->getMemory<x86::reg32>(x86::reg32(5098284) /* 0x4dcb2c */) = cpu.esi;
    // 004b667a  893d30cb4d00           -mov dword ptr [0x4dcb30], edi
    app->getMemory<x86::reg32>(x86::reg32(5098288) /* 0x4dcb30 */) = cpu.edi;
    // 004b6680  892d34cb4d00           -mov dword ptr [0x4dcb34], ebp
    app->getMemory<x86::reg32>(x86::reg32(5098292) /* 0x4dcb34 */) = cpu.ebp;
    // 004b6686  a348cb4d00             -mov dword ptr [0x4dcb48], eax
    app->getMemory<x86::reg32>(x86::reg32(5098312) /* 0x4dcb48 */) = cpu.eax;
    // 004b668b  bafd634b00             -mov edx, 0x4b63fd
    cpu.edx = 4940797 /*0x4b63fd*/;
    // 004b6690  bb09644b00             -mov ebx, 0x4b6409
    cpu.ebx = 4940809 /*0x4b6409*/;
    // 004b6695  b96f644b00             -mov ecx, 0x4b646f
    cpu.ecx = 4940911 /*0x4b646f*/;
    // 004b669a  be54634b00             -mov esi, 0x4b6354
    cpu.esi = 4940628 /*0x4b6354*/;
    // 004b669f  bfd4634b00             -mov edi, 0x4b63d4
    cpu.edi = 4940756 /*0x4b63d4*/;
    // 004b66a4  bde5634b00             -mov ebp, 0x4b63e5
    cpu.ebp = 4940773 /*0x4b63e5*/;
    // 004b66a9  b8db634b00             -mov eax, 0x4b63db
    cpu.eax = 4940763 /*0x4b63db*/;
    // 004b66ae  89154ccb4d00           -mov dword ptr [0x4dcb4c], edx
    app->getMemory<x86::reg32>(x86::reg32(5098316) /* 0x4dcb4c */) = cpu.edx;
    // 004b66b4  891d40e54d00           -mov dword ptr [0x4de540], ebx
    app->getMemory<x86::reg32>(x86::reg32(5104960) /* 0x4de540 */) = cpu.ebx;
    // 004b66ba  890d44e54d00           -mov dword ptr [0x4de544], ecx
    app->getMemory<x86::reg32>(x86::reg32(5104964) /* 0x4de544 */) = cpu.ecx;
    // 004b66c0  893548e54d00           -mov dword ptr [0x4de548], esi
    app->getMemory<x86::reg32>(x86::reg32(5104968) /* 0x4de548 */) = cpu.esi;
    // 004b66c6  893d38cb4d00           -mov dword ptr [0x4dcb38], edi
    app->getMemory<x86::reg32>(x86::reg32(5098296) /* 0x4dcb38 */) = cpu.edi;
    // 004b66cc  892d3ccb4d00           -mov dword ptr [0x4dcb3c], ebp
    app->getMemory<x86::reg32>(x86::reg32(5098300) /* 0x4dcb3c */) = cpu.ebp;
    // 004b66d2  a340cb4d00             -mov dword ptr [0x4dcb40], eax
    app->getMemory<x86::reg32>(x86::reg32(5098304) /* 0x4dcb40 */) = cpu.eax;
    // 004b66d7  baec634b00             -mov edx, 0x4b63ec
    cpu.edx = 4940780 /*0x4b63ec*/;
    // 004b66dc  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 004b66e1  be6a644b00             -mov esi, 0x4b646a
    cpu.esi = 4940906 /*0x4b646a*/;
    // 004b66e6  891544cb4d00           -mov dword ptr [0x4dcb44], edx
    app->getMemory<x86::reg32>(x86::reg32(5098308) /* 0x4dcb44 */) = cpu.edx;
    // 004b66ec  e80ffcffff             -call 0x4b6300
    cpu.esp -= 4;
    sub_4b6300(app, cpu);
    if (cpu.terminate) return;
    // 004b66f1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b66f2  bf0d664b00             -mov edi, 0x4b660d
    cpu.edi = 4941325 /*0x4b660d*/;
    // 004b66f7  a3547a5b00             -mov dword ptr [0x5b7a54], eax
    app->getMemory<x86::reg32>(x86::reg32(5995092) /* 0x5b7a54 */) = cpu.eax;
    // 004b66fc  2eff1510454c00         -call dword ptr cs:[0x4c4510]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998416) /* 0x4c4510 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6703  b904644b00             -mov ecx, 0x4b6404
    cpu.ecx = 4940804 /*0x4b6404*/;
    // 004b6708  8b15f0435b00           -mov edx, dword ptr [0x5b43f0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5981168) /* 0x5b43f0 */);
    // 004b670e  891d587a5b00           -mov dword ptr [0x5b7a58], ebx
    app->getMemory<x86::reg32>(x86::reg32(5995096) /* 0x5b7a58 */) = cpu.ebx;
    // 004b6714  893554cb4d00           -mov dword ptr [0x4dcb54], esi
    app->getMemory<x86::reg32>(x86::reg32(5098324) /* 0x4dcb54 */) = cpu.esi;
    // 004b671a  893d58cb4d00           -mov dword ptr [0x4dcb58], edi
    app->getMemory<x86::reg32>(x86::reg32(5098328) /* 0x4dcb58 */) = cpu.edi;
    // 004b6720  8b82da000000           -mov eax, dword ptr [edx + 0xda]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(218) /* 0xda */);
    // 004b6726  890d50cb4d00           -mov dword ptr [0x4dcb50], ecx
    app->getMemory<x86::reg32>(x86::reg32(5098320) /* 0x4dcb50 */) = cpu.ecx;
    // 004b672c  e858690000             -call 0x4bd089
    cpu.esp -= 4;
    sub_4bd089(app, cpu);
    if (cpu.terminate) return;
    // 004b6731  8b2df0435b00           -mov ebp, dword ptr [0x5b43f0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5981168) /* 0x5b43f0 */);
    // 004b6737  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b6738  a118cb4d00             -mov eax, dword ptr [0x4dcb18]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5098264) /* 0x4dcb18 */);
    // 004b673d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b673e  2eff158c454c00         -call dword ptr cs:[0x4c458c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998540) /* 0x4c458c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6745  c7051ccb4d0096644b00   -mov dword ptr [0x4dcb1c], 0x4b6496
    app->getMemory<x86::reg32>(x86::reg32(5098268) /* 0x4dcb1c */) = 4940950 /*0x4b6496*/;
    // 004b674f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6750  e9b2feffff             -jmp 0x4b6607
    return sub_4b6607(app, cpu);
}

/* align: skip  */
void Application::sub_4b6755(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6755);
    // 004b6755  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6756  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6757  b824795b00             -mov eax, 0x5b7924
    cpu.eax = 5994788 /*0x5b7924*/;
    // 004b675c  ba44795b00             -mov edx, 0x5b7944
    cpu.edx = 5994820 /*0x5b7944*/;
    // 004b6761  ff1548e54d00           -call dword ptr [0x4de548]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5104968) /* 0x4de548 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6767  8d9a00010000           -lea ebx, [edx + 0x100]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(256) /* 0x100 */);
L_0x004b676d:
    // 004b676d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b676f  83c210                 -add edx, 0x10
    (cpu.edx) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004b6772  ff1548e54d00           -call dword ptr [0x4de548]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5104968) /* 0x4de548 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6778  39da                   +cmp edx, ebx
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
    // 004b677a  75f1                   -jne 0x4b676d
    if (!cpu.flags.zf)
    {
        goto L_0x004b676d;
    }
    // 004b677c  b8747a5b00             -mov eax, 0x5b7a74
    cpu.eax = 5995124 /*0x5b7a74*/;
    // 004b6781  ff1548e54d00           -call dword ptr [0x4de548]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5104968) /* 0x4de548 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6787  e81c6a0000             -call 0x4bd1a8
    cpu.esp -= 4;
    sub_4bd1a8(app, cpu);
    if (cpu.terminate) return;
    // 004b678c  b8447a5b00             -mov eax, 0x5b7a44
    cpu.eax = 5995076 /*0x5b7a44*/;
    // 004b6791  ff1548e54d00           -call dword ptr [0x4de548]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5104968) /* 0x4de548 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6797  b834795b00             -mov eax, 0x5b7934
    cpu.eax = 5994804 /*0x5b7934*/;
    // 004b679c  ff1548e54d00           -call dword ptr [0x4de548]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5104968) /* 0x4de548 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b67a2  b8647a5b00             -mov eax, 0x5b7a64
    cpu.eax = 5995108 /*0x5b7a64*/;
    // 004b67a7  ff1548e54d00           -call dword ptr [0x4de548]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5104968) /* 0x4de548 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b67ad  b8547a5b00             -mov eax, 0x5b7a54
    cpu.eax = 5995092 /*0x5b7a54*/;
    // 004b67b2  ff1548e54d00           -call dword ptr [0x4de548]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5104968) /* 0x4de548 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b67b8  e85afeffff             -call 0x4b6617
    cpu.esp -= 4;
    sub_4b6617(app, cpu);
    if (cpu.terminate) return;
    // 004b67bd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b67be  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b67bf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b67c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b67c0);
    // 004b67c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b67c1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b67c2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b67c3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b67c4  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b67c6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b67c8  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b67c9  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b67cb  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b67cd  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b67cf  49                     -dec ecx
    (cpu.ecx)--;
    // 004b67d0  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b67d2  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004b67d4  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004b67d6  49                     -dec ecx
    (cpu.ecx)--;
    // 004b67d7  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b67d8  41                     -inc ecx
    (cpu.ecx)++;
    // 004b67d9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b67db  e853b9feff             -call 0x4a2133
    cpu.esp -= 4;
    sub_4a2133(app, cpu);
    if (cpu.terminate) return;
    // 004b67e0  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b67e2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b67e4  7418                   -je 0x4b67fe
    if (cpu.flags.zf)
    {
        goto L_0x004b67fe;
    }
    // 004b67e6  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b67e8  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b67e9  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b67eb  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b67ed  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b67ee  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b67f0  c1e902                 -shr ecx, 2
    cpu.ecx >>= 2 /*0x2*/ % 32;
    // 004b67f3  f2a5                   -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 004b67f5  8ac8                   -mov cl, al
    cpu.cl = cpu.al;
    // 004b67f7  80e103                 +and cl, 3
    cpu.clear_co();
    cpu.set_szp((cpu.cl &= x86::reg8(x86::sreg8(3 /*0x3*/))));
    // 004b67fa  f2a4                   -repne movsb byte ptr es:[edi], byte ptr [esi]
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
    // 004b67fc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b67fd  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
L_0x004b67fe:
    // 004b67fe  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b6800  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6801  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6802  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6803  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6804  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6805(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6805);
    // 004b6805  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6806  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6807  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b6808  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b6809  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b680b  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b680d  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004b680f  2eff1500454c00         -call dword ptr cs:[0x4c4500]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998400) /* 0x4c4500 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6816  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 004b6819  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004b681e  663d0080               +cmp ax, 0x8000
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
    // 004b6822  730f                   -jae 0x4b6833
    if (!cpu.flags.cf)
    {
        goto L_0x004b6833;
    }
    // 004b6824  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6825  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6826  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b6827  2eff15d8444c00         -call dword ptr cs:[0x4c44d8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998360) /* 0x4c44d8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b682e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b682f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6830  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6831  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6832  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b6833:
    // 004b6833  b808020000             -mov eax, 0x208
    cpu.eax = 520 /*0x208*/;
    // 004b6838  e8f6b8feff             -call 0x4a2133
    cpu.esp -= 4;
    sub_4a2133(app, cpu);
    if (cpu.terminate) return;
    // 004b683d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b683f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b6841  744d                   -je 0x4b6890
    if (cpu.flags.zf)
    {
        goto L_0x004b6890;
    }
    // 004b6843  6808020000             -push 0x208
    app->getMemory<x86::reg32>(cpu.esp-4) = 520 /*0x208*/;
    cpu.esp -= 4;
    // 004b6848  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b6849  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b684a  2eff15d4444c00         -call dword ptr cs:[0x4c44d4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998356) /* 0x4c44d4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6851  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b6853  750e                   -jne 0x4b6863
    if (!cpu.flags.zf)
    {
        goto L_0x004b6863;
    }
    // 004b6855  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b6857  e85c08ffff             -call 0x4a70b8
    cpu.esp -= 4;
    sub_4a70b8(app, cpu);
    if (cpu.terminate) return;
L_0x004b685c:
    // 004b685c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b685e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b685f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6860  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6861  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6862  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b6863:
    // 004b6863  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b6864  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6865  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004b6867  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6868  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004b686a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004b686c  2eff1524454c00         -call dword ptr cs:[0x4c4524]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998436) /* 0x4c4524 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6873  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 004b6875  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b6877  e83c08ffff             -call 0x4a70b8
    cpu.esp -= 4;
    sub_4a70b8(app, cpu);
    if (cpu.terminate) return;
    // 004b687c  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004b687e  74dc                   -je 0x4b685c
    if (cpu.flags.zf)
    {
        goto L_0x004b685c;
    }
    // 004b6880  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b6882  66c74446fe0000         -mov word ptr [esi + eax*2 - 2], 0
    app->getMemory<x86::reg16>(cpu.esi + x86::reg32(-2) /* -0x2 */ + cpu.eax * 2) = 0 /*0x0*/;
    // 004b6889  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b688b  e884270000             -call 0x4b9014
    cpu.esp -= 4;
    sub_4b9014(app, cpu);
    if (cpu.terminate) return;
L_0x004b6890:
    // 004b6890  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6891  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6892  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6893  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6894  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6895(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6895);
    // 004b6895  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6896  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6897  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6898  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b689a  e875270000             -call 0x4b9014
    cpu.esp -= 4;
    sub_4b9014(app, cpu);
    if (cpu.terminate) return;
    // 004b689f  8d5801                 -lea ebx, [eax + 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b68a2  01db                   -add ebx, ebx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b68a4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b68a6  e888b8feff             -call 0x4a2133
    cpu.esp -= 4;
    sub_4a2133(app, cpu);
    if (cpu.terminate) return;
    // 004b68ab  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b68ad  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b68af  7405                   -je 0x4b68b6
    if (cpu.flags.zf)
    {
        goto L_0x004b68b6;
    }
    // 004b68b1  e827280000             -call 0x4b90dd
    cpu.esp -= 4;
    sub_4b90dd(app, cpu);
    if (cpu.terminate) return;
L_0x004b68b6:
    // 004b68b6  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b68b8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b68b9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b68ba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b68bb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b68bc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b68bc);
    // 004b68bc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b68bd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b68be  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b68bf  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004b68c2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b68c4  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 004b68c6  6a1c                   -push 0x1c
    app->getMemory<x86::reg32>(cpu.esp-4) = 28 /*0x1c*/;
    cpu.esp -= 4;
    // 004b68c8  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b68cc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b68cd  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004b68d1  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b68d2  2eff15a4454c00         -call dword ptr cs:[0x4c45a4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998564) /* 0x4c45a4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b68d9  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004b68dc  0354240c               -add edx, dword ptr [esp + 0xc]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */)));
    // 004b68e0  668b0dd1b84d00         -mov cx, word ptr [0x4db8d1]
    cpu.cx = app->getMemory<x86::reg16>(x86::reg32(5093585) /* 0x4db8d1 */);
    // 004b68e7  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004b68eb  6681f90080             +cmp cx, 0x8000
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
    // 004b68f0  7307                   -jae 0x4b68f9
    if (!cpu.flags.cf)
    {
        goto L_0x004b68f9;
    }
    // 004b68f2  0500300000             +add eax, 0x3000
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
    // 004b68f7  eb17                   -jmp 0x4b6910
    goto L_0x004b6910;
L_0x004b68f9:
    // 004b68f9  7210                   -jb 0x4b690b
    if (cpu.flags.cf)
    {
        goto L_0x004b690b;
    }
    // 004b68fb  803dcfb84d0004         +cmp byte ptr [0x4db8cf], 4
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5093583) /* 0x4db8cf */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(4 /*0x4*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b6902  7307                   -jae 0x4b690b
    if (!cpu.flags.cf)
    {
        goto L_0x004b690b;
    }
    // 004b6904  0500200100             +add eax, 0x12000
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
    // 004b6909  eb05                   -jmp 0x4b6910
    goto L_0x004b6910;
L_0x004b690b:
    // 004b690b  0500300100             -add eax, 0x13000
    (cpu.eax) += x86::reg32(x86::sreg32(77824 /*0x13000*/));
L_0x004b6910:
    // 004b6910  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b6912  7402                   -je 0x4b6916
    if (cpu.flags.zf)
    {
        goto L_0x004b6916;
    }
    // 004b6914  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
L_0x004b6916:
    // 004b6916  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b6918  7402                   -je 0x4b691c
    if (cpu.flags.zf)
    {
        goto L_0x004b691c;
    }
    // 004b691a  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
L_0x004b691c:
    // 004b691c  83c420                 -add esp, 0x20
    (cpu.esp) += x86::reg32(x86::sreg32(32 /*0x20*/));
    // 004b691f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6920  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6921  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6922  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6923(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6923);
    // 004b6923  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6924  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6925  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6926  68c8f74c00             -push 0x4cf7c8
    app->getMemory<x86::reg32>(cpu.esp-4) = 5044168 /*0x4cf7c8*/;
    cpu.esp -= 4;
    // 004b692b  2eff1518454c00         -call dword ptr cs:[0x4c4518]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998424) /* 0x4c4518 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6932  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b6934  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b6936  7417                   -je 0x4b694f
    if (cpu.flags.zf)
    {
        goto L_0x004b694f;
    }
    // 004b6938  68d3f74c00             -push 0x4cf7d3
    app->getMemory<x86::reg32>(cpu.esp-4) = 5044179 /*0x4cf7d3*/;
    cpu.esp -= 4;
    // 004b693d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b693e  2eff15e8444c00         -call dword ptr cs:[0x4c44e8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998376) /* 0x4c44e8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6945  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b6947  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b6949  7404                   -je 0x4b694f
    if (cpu.flags.zf)
    {
        goto L_0x004b694f;
    }
    // 004b694b  ffd2                   -call edx
    cpu.ip = cpu.edx;
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b694d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004b694f:
    // 004b694f  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b6951  0f95c0                 -setne al
    cpu.al = !cpu.flags.zf;
    // 004b6954  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b6959  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b695a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b695b  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b695c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b695d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b695d);
    // 004b695d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b695e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b695f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b6960  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 004b6962  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x004b6964:
    // 004b6964  803800                 +cmp byte ptr [eax], 0
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
    // 004b6967  7403                   -je 0x4b696c
    if (cpu.flags.zf)
    {
        goto L_0x004b696c;
    }
    // 004b6969  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b696a  ebf8                   -jmp 0x4b6964
    goto L_0x004b6964;
L_0x004b696c:
    // 004b696c  8d7009                 -lea esi, [eax + 9]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(9) /* 0x9 */);
L_0x004b696f:
    // 004b696f  8a0a                   -mov cl, byte ptr [edx]
    cpu.cl = app->getMemory<x86::reg8>(cpu.edx);
    // 004b6971  8808                   -mov byte ptr [eax], cl
    app->getMemory<x86::reg8>(cpu.eax) = cpu.cl;
    // 004b6973  84c9                   +test cl, cl
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & cpu.cl));
    // 004b6975  7412                   -je 0x4b6989
    if (cpu.flags.zf)
    {
        goto L_0x004b6989;
    }
    // 004b6977  80f930                 +cmp cl, 0x30
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
    // 004b697a  7508                   -jne 0x4b6984
    if (!cpu.flags.zf)
    {
        goto L_0x004b6984;
    }
    // 004b697c  807a0178               +cmp byte ptr [edx + 1], 0x78
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
    // 004b6980  7502                   -jne 0x4b6984
    if (!cpu.flags.zf)
    {
        goto L_0x004b6984;
    }
    // 004b6982  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
L_0x004b6984:
    // 004b6984  46                     +inc esi
    {
        x86::reg32& tmp = cpu.esi;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b6985  40                     +inc eax
    {
        x86::reg32& tmp = cpu.eax;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b6986  42                     +inc edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = ~(1 & (tmp >> 31));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 31);
        cpu.set_szp(tmp);
    }
    // 004b6987  ebe6                   -jmp 0x4b696f
    goto L_0x004b696f;
L_0x004b6989:
    // 004b6989  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b698b  7419                   -je 0x4b69a6
    if (cpu.flags.zf)
    {
        goto L_0x004b69a6;
    }
    // 004b698d  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x004b698f:
    // 004b698f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b6991  7413                   -je 0x4b69a6
    if (cpu.flags.zf)
    {
        goto L_0x004b69a6;
    }
    // 004b6993  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b6995  83e20f                 -and edx, 0xf
    cpu.edx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 004b6998  8a9254e54d00           -mov dl, byte ptr [edx + 0x4de554]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(5104980) /* 0x4de554 */);
    // 004b699e  c1e804                 +shr eax, 4
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
    // 004b69a1  8813                   -mov byte ptr [ebx], dl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.dl;
    // 004b69a3  4b                     +dec ebx
    {
        x86::reg32& tmp = cpu.ebx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 004b69a4  ebe9                   -jmp 0x4b698f
    goto L_0x004b698f;
L_0x004b69a6:
    // 004b69a6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b69a7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b69a8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b69a9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b69aa(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b69aa);
    // 004b69aa  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b69ab  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b69ac  81ec04010000           -sub esp, 0x104
    (cpu.esp) -= x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004b69b2  8b9c2410010000         -mov ebx, dword ptr [esp + 0x110]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(272) /* 0x110 */);
    // 004b69b9  8b0b                   -mov ecx, dword ptr [ebx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx);
    // 004b69bb  8b5b04                 -mov ebx, dword ptr [ebx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */);
    // 004b69be  e860ffffff             -call 0x4b6923
    cpu.esp -= 4;
    sub_4b6923(app, cpu);
    if (cpu.terminate) return;
    // 004b69c3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b69c5  750a                   -jne 0x4b69d1
    if (!cpu.flags.zf)
    {
        goto L_0x004b69d1;
    }
    // 004b69c7  e87e680000             -call 0x4bd24a
    cpu.esp -= 4;
    sub_4bd24a(app, cpu);
    if (cpu.terminate) return;
    // 004b69cc  83f8ff                 +cmp eax, -1
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
    // 004b69cf  7507                   -jne 0x4b69d8
    if (!cpu.flags.zf)
    {
        goto L_0x004b69d8;
    }
L_0x004b69d1:
    // 004b69d1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b69d3  e97e010000             -jmp 0x4b6b56
    goto L_0x004b6b56;
L_0x004b69d8:
    // 004b69d8  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 004b69da  882424                 -mov byte ptr [esp], ah
    app->getMemory<x86::reg8>(cpu.esp) = cpu.ah;
    // 004b69dd  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 004b69df  3d900000c0             +cmp eax, 0xc0000090
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
    // 004b69e4  724d                   -jb 0x4b6a33
    if (cpu.flags.cf)
    {
        goto L_0x004b6a33;
    }
    // 004b69e6  0f86b5000000           -jbe 0x4b6aa1
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b6aa1;
    }
    // 004b69ec  3d930000c0             +cmp eax, 0xc0000093
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
    // 004b69f1  7233                   -jb 0x4b6a26
    if (cpu.flags.cf)
    {
        goto L_0x004b6a26;
    }
    // 004b69f3  0f86a1000000           -jbe 0x4b6a9a
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b6a9a;
    }
    // 004b69f9  3d960000c0             +cmp eax, 0xc0000096
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
    // 004b69fe  7216                   -jb 0x4b6a16
    if (cpu.flags.cf)
    {
        goto L_0x004b6a16;
    }
    // 004b6a00  0f86d8000000           -jbe 0x4b6ade
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b6ade;
    }
    // 004b6a06  3dfd0000c0             +cmp eax, 0xc00000fd
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
    // 004b6a0b  0f84e5000000           -je 0x4b6af6
    if (cpu.flags.zf)
    {
        goto L_0x004b6af6;
    }
    // 004b6a11  e9ea000000             -jmp 0x4b6b00
    goto L_0x004b6b00;
L_0x004b6a16:
    // 004b6a16  3d940000c0             +cmp eax, 0xc0000094
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
    // 004b6a1b  0f84cb000000           -je 0x4b6aec
    if (cpu.flags.zf)
    {
        goto L_0x004b6aec;
    }
    // 004b6a21  e9da000000             -jmp 0x4b6b00
    goto L_0x004b6b00;
L_0x004b6a26:
    // 004b6a26  3d910000c0             +cmp eax, 0xc0000091
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
    // 004b6a2b  0f8662000000           -jbe 0x4b6a93
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b6a93;
    }
    // 004b6a31  eb2f                   -jmp 0x4b6a62
    goto L_0x004b6a62;
L_0x004b6a33:
    // 004b6a33  3d8d0000c0             +cmp eax, 0xc000008d
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
    // 004b6a38  720b                   -jb 0x4b6a45
    if (cpu.flags.cf)
    {
        goto L_0x004b6a45;
    }
    // 004b6a3a  7642                   -jbe 0x4b6a7e
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b6a7e;
    }
    // 004b6a3c  3d8e0000c0             +cmp eax, 0xc000008e
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
    // 004b6a41  7642                   -jbe 0x4b6a85
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b6a85;
    }
    // 004b6a43  eb47                   -jmp 0x4b6a8c
    goto L_0x004b6a8c;
L_0x004b6a45:
    // 004b6a45  3d050000c0             +cmp eax, 0xc0000005
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
    // 004b6a4a  0f82b0000000           -jb 0x4b6b00
    if (cpu.flags.cf)
    {
        goto L_0x004b6b00;
    }
    // 004b6a50  7656                   -jbe 0x4b6aa8
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b6aa8;
    }
    // 004b6a52  3d1d0000c0             +cmp eax, 0xc000001d
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
    // 004b6a57  0f8488000000           -je 0x4b6ae5
    if (cpu.flags.zf)
    {
        goto L_0x004b6ae5;
    }
    // 004b6a5d  e99e000000             -jmp 0x4b6b00
    goto L_0x004b6b00;
L_0x004b6a62:
    // 004b6a62  f6432102               +test byte ptr [ebx + 0x21], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(33) /* 0x21 */) & 2 /*0x2*/));
    // 004b6a66  740f                   -je 0x4b6a77
    if (cpu.flags.zf)
    {
        goto L_0x004b6a77;
    }
    // 004b6a68  bae3f74c00             -mov edx, 0x4cf7e3
    cpu.edx = 5044195 /*0x4cf7e3*/;
L_0x004b6a6d:
    // 004b6a6d  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b6a6f  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004b6a72  e9a1000000             -jmp 0x4b6b18
    goto L_0x004b6b18;
L_0x004b6a77:
    // 004b6a77  ba34f84c00             -mov edx, 0x4cf834
    cpu.edx = 5044276 /*0x4cf834*/;
    // 004b6a7c  ebef                   -jmp 0x4b6a6d
    goto L_0x004b6a6d;
L_0x004b6a7e:
    // 004b6a7e  ba86f84c00             -mov edx, 0x4cf886
    cpu.edx = 5044358 /*0x4cf886*/;
    // 004b6a83  ebe8                   -jmp 0x4b6a6d
    goto L_0x004b6a6d;
L_0x004b6a85:
    // 004b6a85  bad9f84c00             -mov edx, 0x4cf8d9
    cpu.edx = 5044441 /*0x4cf8d9*/;
    // 004b6a8a  ebe1                   -jmp 0x4b6a6d
    goto L_0x004b6a6d;
L_0x004b6a8c:
    // 004b6a8c  ba2cf94c00             -mov edx, 0x4cf92c
    cpu.edx = 5044524 /*0x4cf92c*/;
    // 004b6a91  ebda                   -jmp 0x4b6a6d
    goto L_0x004b6a6d;
L_0x004b6a93:
    // 004b6a93  ba7df94c00             -mov edx, 0x4cf97d
    cpu.edx = 5044605 /*0x4cf97d*/;
    // 004b6a98  ebd3                   -jmp 0x4b6a6d
    goto L_0x004b6a6d;
L_0x004b6a9a:
    // 004b6a9a  bac9f94c00             -mov edx, 0x4cf9c9
    cpu.edx = 5044681 /*0x4cf9c9*/;
    // 004b6a9f  ebcc                   -jmp 0x4b6a6d
    goto L_0x004b6a6d;
L_0x004b6aa1:
    // 004b6aa1  ba16fa4c00             -mov edx, 0x4cfa16
    cpu.edx = 5044758 /*0x4cfa16*/;
    // 004b6aa6  ebc5                   -jmp 0x4b6a6d
    goto L_0x004b6a6d;
L_0x004b6aa8:
    // 004b6aa8  ba6bfa4c00             -mov edx, 0x4cfa6b
    cpu.edx = 5044843 /*0x4cfa6b*/;
    // 004b6aad  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b6aaf  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 004b6ab2  e8a6feffff             -call 0x4b695d
    cpu.esp -= 4;
    sub_4b695d(app, cpu);
    if (cpu.terminate) return;
    // 004b6ab7  ba9cfa4c00             -mov edx, 0x4cfa9c
    cpu.edx = 5044892 /*0x4cfa9c*/;
    // 004b6abc  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b6abe  8b5918                 -mov ebx, dword ptr [ecx + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
    // 004b6ac1  e897feffff             -call 0x4b695d
    cpu.esp -= 4;
    sub_4b695d(app, cpu);
    if (cpu.terminate) return;
    // 004b6ac6  83791400               +cmp dword ptr [ecx + 0x14], 0
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
    // 004b6aca  750b                   -jne 0x4b6ad7
    if (!cpu.flags.zf)
    {
        goto L_0x004b6ad7;
    }
    // 004b6acc  bac4fa4c00             -mov edx, 0x4cfac4
    cpu.edx = 5044932 /*0x4cfac4*/;
L_0x004b6ad1:
    // 004b6ad1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b6ad3  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004b6ad5  eb41                   -jmp 0x4b6b18
    goto L_0x004b6b18;
L_0x004b6ad7:
    // 004b6ad7  bacbfa4c00             -mov edx, 0x4cfacb
    cpu.edx = 5044939 /*0x4cfacb*/;
    // 004b6adc  ebf3                   -jmp 0x4b6ad1
    goto L_0x004b6ad1;
L_0x004b6ade:
    // 004b6ade  bad5fa4c00             -mov edx, 0x4cfad5
    cpu.edx = 5044949 /*0x4cfad5*/;
    // 004b6ae3  eb88                   -jmp 0x4b6a6d
    goto L_0x004b6a6d;
L_0x004b6ae5:
    // 004b6ae5  ba13fb4c00             -mov edx, 0x4cfb13
    cpu.edx = 5045011 /*0x4cfb13*/;
    // 004b6aea  eb81                   -jmp 0x4b6a6d
    goto L_0x004b6a6d;
L_0x004b6aec:
    // 004b6aec  ba4ffb4c00             -mov edx, 0x4cfb4f
    cpu.edx = 5045071 /*0x4cfb4f*/;
    // 004b6af1  e977ffffff             -jmp 0x4b6a6d
    goto L_0x004b6a6d;
L_0x004b6af6:
    // 004b6af6  ba91fb4c00             -mov edx, 0x4cfb91
    cpu.edx = 5045137 /*0x4cfb91*/;
    // 004b6afb  e96dffffff             -jmp 0x4b6a6d
    goto L_0x004b6a6d;
L_0x004b6b00:
    // 004b6b00  bacafb4c00             -mov edx, 0x4cfbca
    cpu.edx = 5045194 /*0x4cfbca*/;
    // 004b6b05  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b6b07  8b19                   -mov ebx, dword ptr [ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004b6b09  e84ffeffff             -call 0x4b695d
    cpu.esp -= 4;
    sub_4b695d(app, cpu);
    if (cpu.terminate) return;
    // 004b6b0e  bafbfb4c00             -mov edx, 0x4cfbfb
    cpu.edx = 5045243 /*0x4cfbfb*/;
    // 004b6b13  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b6b15  8b590c                 -mov ebx, dword ptr [ecx + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
L_0x004b6b18:
    // 004b6b18  e840feffff             -call 0x4b695d
    cpu.esp -= 4;
    sub_4b695d(app, cpu);
    if (cpu.terminate) return;
    // 004b6b1d  6a00                   -push 0
    app->getMemory<x86::reg32>(cpu.esp-4) = 0 /*0x0*/;
    cpu.esp -= 4;
    // 004b6b1f  8d842404010000         -lea eax, [esp + 0x104]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(260) /* 0x104 */);
    // 004b6b26  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b6b27  8d7c2408               -lea edi, [esp + 8]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 004b6b2b  06                     -push es
    app->getMemory<x86::reg16>(cpu.esp-4) = cpu.es;
    cpu.esp -= 4;
    // 004b6b2c  8cd8                   -mov eax, ds
    cpu.eax = cpu.ds;
    // 004b6b2e  8ec0                   -mov es, eax
    cpu.es = cpu.eax;
    // 004b6b30  29c9                   -sub ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b6b32  49                     -dec ecx
    (cpu.ecx)--;
    // 004b6b33  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b6b35  f2ae                   -repne scasb al, byte ptr es:[edi]
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
    // 004b6b37  f7d1                   -not ecx
    cpu.ecx = ~cpu.ecx;
    // 004b6b39  49                     -dec ecx
    (cpu.ecx)--;
    // 004b6b3a  07                     -pop es
    cpu.es = app->getMemory<x86::reg16>(cpu.esp);
    cpu.esp += 4;
    // 004b6b3b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6b3c  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 004b6b40  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b6b41  a1d8e44d00             -mov eax, dword ptr [0x4de4d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104856) /* 0x4de4d8 */);
    // 004b6b46  8b5808                 -mov ebx, dword ptr [eax + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004b6b49  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6b4a  2eff15b8454c00         -call dword ptr cs:[0x4c45b8]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998584) /* 0x4c45b8 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6b51  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004b6b56:
    // 004b6b56  81c404010000           -add esp, 0x104
    (cpu.esp) += x86::reg32(x86::sreg32(260 /*0x104*/));
    // 004b6b5c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6b5d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6b5e  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip  */
void Application::sub_4b6b61(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6b61);
  goto start;
dynamic_jump:
  switch(cpu.ip)
  {
start:
    // 004b6b61  8bc0                   -mov eax, eax
    cpu.eax = cpu.eax;
    // 004b6b63  c9                     -leave 
    cpu.esp = cpu.ebp;
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6b64  6b4b00d3               -imul ecx, dword ptr [ebx], -0x2d
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx))) * x86::sreg64(x86::sreg32(-45 /*-0x2d*/)));
    // 004b6b68  6b4b00dd               -imul ecx, dword ptr [ebx], -0x23
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx))) * x86::sreg64(x86::sreg32(-35 /*-0x23*/)));
    // 004b6b6c  6b4b00fb               -imul ecx, dword ptr [ebx], -5
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx))) * x86::sreg64(x86::sreg32(-5 /*-0x5*/)));
    // 004b6b70  6b4b00e7               -imul ecx, dword ptr [ebx], -0x19
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx))) * x86::sreg64(x86::sreg32(-25 /*-0x19*/)));
    // 004b6b74  6b4b00af               -imul ecx, dword ptr [ebx], -0x51
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx))) * x86::sreg64(x86::sreg32(-81 /*-0x51*/)));
    // 004b6b78  6b4b00f1               -imul ecx, dword ptr [ebx], -0xf
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx))) * x86::sreg64(x86::sreg32(-15 /*-0xf*/)));
    // 004b6b7c  6b4b0053               -imul ecx, dword ptr [ebx], 0x53
    cpu.ecx = x86::reg32(x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx))) * x86::sreg64(x86::sreg32(83 /*0x53*/)));
    // 004b6b80  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6b81  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b6b82  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b6b85  8b742418               -mov esi, dword ptr [esp + 0x18]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 004b6b89  8b7c2420               -mov edi, dword ptr [esp + 0x20]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004b6b8d  f6460406               +test byte ptr [esi + 4], 6
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(4) /* 0x4 */) & 6 /*0x6*/));
    // 004b6b91  0f85a0010000           -jne 0x4b6d37
    if (!cpu.flags.zf)
    {
        goto L_0x004b6d37;
    }
    // 004b6b97  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004b6b99  0573ffff3f             -add eax, 0x3fffff73
    (cpu.eax) += x86::reg32(x86::sreg32(1073741683 /*0x3fffff73*/));
    // 004b6b9e  83f806                 +cmp eax, 6
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
    // 004b6ba1  0f8723010000           -ja 0x4b6cca
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x004b6cca;
    }
    // 004b6ba7  2eff2485636b4b00       -jmp dword ptr cs:[eax*4 + 0x4b6b63]
    cpu.ip = app->getMemory<x86::reg32>(4942691 + cpu.eax * 4); goto dynamic_jump;
  case 0x004b6baf:
    // 004b6baf  f6472102               +test byte ptr [edi + 0x21], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(33) /* 0x21 */) & 2 /*0x2*/));
    // 004b6bb3  740a                   -je 0x4b6bbf
    if (cpu.flags.zf)
    {
        goto L_0x004b6bbf;
    }
    // 004b6bb5  bb8a000000             -mov ebx, 0x8a
    cpu.ebx = 138 /*0x8a*/;
    // 004b6bba  e9ce000000             -jmp 0x4b6c8d
    goto L_0x004b6c8d;
L_0x004b6bbf:
    // 004b6bbf  bb8b000000             -mov ebx, 0x8b
    cpu.ebx = 139 /*0x8b*/;
    // 004b6bc4  e9c4000000             -jmp 0x4b6c8d
    goto L_0x004b6c8d;
  case 0x004b6bc9:
    // 004b6bc9  bb82000000             -mov ebx, 0x82
    cpu.ebx = 130 /*0x82*/;
    // 004b6bce  e9ba000000             -jmp 0x4b6c8d
    goto L_0x004b6c8d;
  case 0x004b6bd3:
L_0x004b6bd3:
    // 004b6bd3  bb83000000             -mov ebx, 0x83
    cpu.ebx = 131 /*0x83*/;
    // 004b6bd8  e9b0000000             -jmp 0x4b6c8d
    goto L_0x004b6c8d;
  case 0x004b6bdd:
    // 004b6bdd  bb86000000             -mov ebx, 0x86
    cpu.ebx = 134 /*0x86*/;
    // 004b6be2  e9a6000000             -jmp 0x4b6c8d
    goto L_0x004b6c8d;
  case 0x004b6be7:
    // 004b6be7  bb84000000             -mov ebx, 0x84
    cpu.ebx = 132 /*0x84*/;
    // 004b6bec  e99c000000             -jmp 0x4b6c8d
    goto L_0x004b6c8d;
  case 0x004b6bf1:
    // 004b6bf1  bb85000000             -mov ebx, 0x85
    cpu.ebx = 133 /*0x85*/;
    // 004b6bf6  e992000000             -jmp 0x4b6c8d
    goto L_0x004b6c8d;
  case 0x004b6bfb:
    // 004b6bfb  8b4728                 -mov eax, dword ptr [edi + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(40) /* 0x28 */);
    // 004b6bfe  668b10                 -mov dx, word ptr [eax]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax);
    // 004b6c01  bb81000000             -mov ebx, 0x81
    cpu.ebx = 129 /*0x81*/;
    // 004b6c06  6681fad9fa             +cmp dx, 0xfad9
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
    // 004b6c0b  750a                   -jne 0x4b6c17
    if (!cpu.flags.zf)
    {
        goto L_0x004b6c17;
    }
    // 004b6c0d  bb88000000             -mov ebx, 0x88
    cpu.ebx = 136 /*0x88*/;
    // 004b6c12  e976000000             -jmp 0x4b6c8d
    goto L_0x004b6c8d;
L_0x004b6c17:
    // 004b6c17  6681fad9f1             +cmp dx, 0xf1d9
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
    // 004b6c1c  750a                   -jne 0x4b6c28
    if (!cpu.flags.zf)
    {
        goto L_0x004b6c28;
    }
    // 004b6c1e  bb8e000000             -mov ebx, 0x8e
    cpu.ebx = 142 /*0x8e*/;
    // 004b6c23  e965000000             -jmp 0x4b6c8d
    goto L_0x004b6c8d;
L_0x004b6c28:
    // 004b6c28  7507                   -jne 0x4b6c31
    if (!cpu.flags.zf)
    {
        goto L_0x004b6c31;
    }
    // 004b6c2a  bb8f000000             -mov ebx, 0x8f
    cpu.ebx = 143 /*0x8f*/;
    // 004b6c2f  eb5c                   -jmp 0x4b6c8d
    goto L_0x004b6c8d;
L_0x004b6c31:
    // 004b6c31  8a30                   -mov dh, byte ptr [eax]
    cpu.dh = app->getMemory<x86::reg8>(cpu.eax);
    // 004b6c33  80fedb                 +cmp dh, 0xdb
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
    // 004b6c36  7405                   -je 0x4b6c3d
    if (cpu.flags.zf)
    {
        goto L_0x004b6c3d;
    }
    // 004b6c38  80fedf                 +cmp dh, 0xdf
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
    // 004b6c3b  7510                   -jne 0x4b6c4d
    if (!cpu.flags.zf)
    {
        goto L_0x004b6c4d;
    }
L_0x004b6c3d:
    // 004b6c3d  8a5001                 -mov dl, byte ptr [eax + 1]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b6c40  80e230                 -and dl, 0x30
    cpu.dl &= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004b6c43  80fa10                 +cmp dl, 0x10
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
    // 004b6c46  7505                   -jne 0x4b6c4d
    if (!cpu.flags.zf)
    {
        goto L_0x004b6c4d;
    }
    // 004b6c48  bb8d000000             -mov ebx, 0x8d
    cpu.ebx = 141 /*0x8d*/;
L_0x004b6c4d:
    // 004b6c4d  f60001                 +test byte ptr [eax], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax) & 1 /*0x1*/));
    // 004b6c50  7536                   -jne 0x4b6c88
    if (!cpu.flags.zf)
    {
        goto L_0x004b6c88;
    }
    // 004b6c52  8a4001                 -mov al, byte ptr [eax + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b6c55  2430                   -and al, 0x30
    cpu.al &= x86::reg8(x86::sreg8(48 /*0x30*/));
    // 004b6c57  3c30                   +cmp al, 0x30
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
    // 004b6c59  752d                   -jne 0x4b6c88
    if (!cpu.flags.zf)
    {
        goto L_0x004b6c88;
    }
    // 004b6c5b  8b4720                 -mov eax, dword ptr [edi + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 004b6c5e  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004b6c63  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004b6c66  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004b6c68  66c1e80d               -shr ax, 0xd
    cpu.ax >>= 13 /*0xd*/ % 32;
    // 004b6c6c  8b5724                 -mov edx, dword ptr [edi + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(36) /* 0x24 */);
    // 004b6c6f  6689c1                 -mov cx, ax
    cpu.cx = cpu.ax;
    // 004b6c72  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 004b6c78  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b6c7a  d3ea                   -shr edx, cl
    cpu.edx >>= cpu.cl % 32;
    // 004b6c7c  83e201                 -and edx, 1
    cpu.edx &= x86::reg32(x86::sreg32(1 /*0x1*/));
    // 004b6c7f  83fa01                 +cmp edx, 1
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
    // 004b6c82  0f844bffffff           -je 0x4b6bd3
    if (cpu.flags.zf)
    {
        goto L_0x004b6bd3;
    }
L_0x004b6c88:
    // 004b6c88  83fbff                 +cmp ebx, -1
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
    // 004b6c8b  743d                   -je 0x4b6cca
    if (cpu.flags.zf)
    {
        goto L_0x004b6cca;
    }
L_0x004b6c8d:
    // 004b6c8d  c6058c805b0001         -mov byte ptr [0x5b808c], 1
    app->getMemory<x86::reg8>(x86::reg32(5996684) /* 0x5b808c */) = 1 /*0x1*/;
    // 004b6c94  e8bc650000             -call 0x4bd255
    cpu.esp -= 4;
    sub_4bd255(app, cpu);
    if (cpu.terminate) return;
    // 004b6c99  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b6c9b  e882670000             -call 0x4bd422
    cpu.esp -= 4;
    sub_4bd422(app, cpu);
    if (cpu.terminate) return;
    // 004b6ca0  83f8ff                 +cmp eax, -1
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
    // 004b6ca3  0f846f000000           -je 0x4b6d18
    if (cpu.flags.zf)
    {
        goto L_0x004b6d18;
    }
    // 004b6ca9  803d8c805b0000         +cmp byte ptr [0x5b808c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5996684) /* 0x5b808c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b6cb0  0f8462000000           -je 0x4b6d18
    if (cpu.flags.zf)
    {
        goto L_0x004b6d18;
    }
    // 004b6cb6  668b5f20               -mov bx, word ptr [edi + 0x20]
    cpu.bx = app->getMemory<x86::reg16>(cpu.edi + x86::reg32(32) /* 0x20 */);
    // 004b6cba  30db                   -xor bl, bl
    cpu.bl ^= x86::reg8(x86::sreg8(cpu.bl));
    // 004b6cbc  80e77f                 -and bh, 0x7f
    cpu.bh &= x86::reg8(x86::sreg8(127 /*0x7f*/));
    // 004b6cbf  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b6cc1  66895f20               -mov word ptr [edi + 0x20], bx
    app->getMemory<x86::reg16>(cpu.edi + x86::reg32(32) /* 0x20 */) = cpu.bx;
    // 004b6cc5  e972000000             -jmp 0x4b6d3c
    goto L_0x004b6d3c;
L_0x004b6cca:
    // 004b6cca  833d50e54d0000         +cmp dword ptr [0x4de550], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5104976) /* 0x4de550 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b6cd1  7445                   -je 0x4b6d18
    if (cpu.flags.zf)
    {
        goto L_0x004b6d18;
    }
    // 004b6cd3  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x004b6cd8:
    // 004b6cd8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b6cda  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 004b6cdc  ff154ce54d00           -call dword ptr [0x4de54c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5104972) /* 0x4de54c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6ce2  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b6ce4  742c                   -je 0x4b6d12
    if (cpu.flags.zf)
    {
        goto L_0x004b6d12;
    }
    // 004b6ce6  83f801                 +cmp eax, 1
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
    // 004b6ce9  742d                   -je 0x4b6d18
    if (cpu.flags.zf)
    {
        goto L_0x004b6d18;
    }
    // 004b6ceb  83f802                 +cmp eax, 2
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
    // 004b6cee  7428                   -je 0x4b6d18
    if (cpu.flags.zf)
    {
        goto L_0x004b6d18;
    }
    // 004b6cf0  83f803                 +cmp eax, 3
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
    // 004b6cf3  7423                   -je 0x4b6d18
    if (cpu.flags.zf)
    {
        goto L_0x004b6d18;
    }
    // 004b6cf5  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 004b6cf7  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b6cf9  88158c805b00           -mov byte ptr [0x5b808c], dl
    app->getMemory<x86::reg8>(x86::reg32(5996684) /* 0x5b808c */) = cpu.dl;
    // 004b6cff  ff1550e54d00           -call dword ptr [0x4de550]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5104976) /* 0x4de550 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6d05  803d8c805b0000         +cmp byte ptr [0x5b808c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5996684) /* 0x5b808c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004b6d0c  7404                   -je 0x4b6d12
    if (cpu.flags.zf)
    {
        goto L_0x004b6d12;
    }
    // 004b6d0e  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b6d10  eb2a                   -jmp 0x4b6d3c
    goto L_0x004b6d3c;
L_0x004b6d12:
    // 004b6d12  43                     -inc ebx
    (cpu.ebx)++;
    // 004b6d13  83fb0c                 +cmp ebx, 0xc
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
    // 004b6d16  7ec0                   -jle 0x4b6cd8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004b6cd8;
    }
L_0x004b6d18:
    // 004b6d18  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b6d1a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b6d1b  89742404               -mov dword ptr [esp + 4], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.esi;
    // 004b6d1f  897c2408               -mov dword ptr [esp + 8], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edi;
    // 004b6d23  2eff1590454c00         -call dword ptr cs:[0x4c4590]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998544) /* 0x4c4590 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6d2a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b6d2c  7409                   -je 0x4b6d37
    if (cpu.flags.zf)
    {
        goto L_0x004b6d37;
    }
    // 004b6d2e  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 004b6d30  2eff1558444c00         -call dword ptr cs:[0x4c4458]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998232) /* 0x4c4458 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
L_0x004b6d37:
    // 004b6d37  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x004b6d3c:
    // 004b6d3c  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b6d3f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6d40  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6d41  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6d42  c3                     -ret 
    cpu.esp += 4;
    return;
  default:
    NFS2_ASSERT(false);
  }
}

/* align: skip  */
void Application::sub_4b6d43(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6d43);
    // 004b6d43  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6d44  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6d45  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b6d47  ff151ccb4d00           -call dword ptr [0x4dcb1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098268) /* 0x4dcb1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6d4d  895054                 -mov dword ptr [eax + 0x54], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = cpu.edx;
    // 004b6d50  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b6d52  648b00                 -mov eax, dword ptr fs:[eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.efs + cpu.eax);
    // 004b6d55  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b6d57  ff151ccb4d00           -call dword ptr [0x4dcb1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098268) /* 0x4dcb1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6d5d  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004b6d60  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 004b6d62  ff151ccb4d00           -call dword ptr [0x4dcb1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098268) /* 0x4dcb1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6d68  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004b6d6b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b6d6d  c740047f6b4b00         -mov dword ptr [eax + 4], 0x4b6b7f
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 4942719 /*0x4b6b7f*/;
    // 004b6d74  ff151ccb4d00           -call dword ptr [0x4dcb1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098268) /* 0x4dcb1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6d7a  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004b6d7d  648902                 -mov dword ptr fs:[edx], eax
    app->getMemory<x86::reg32>(cpu.efs + cpu.edx) = cpu.eax;
    // 004b6d80  68aa694b00             -push 0x4b69aa
    app->getMemory<x86::reg32>(cpu.esp-4) = 4942250 /*0x4b69aa*/;
    cpu.esp -= 4;
    // 004b6d85  2eff1574454c00         -call dword ptr cs:[0x4c4574]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998516) /* 0x4c4574 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6d8c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6d8d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6d8e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6d8f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6d8f);
    // 004b6d8f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6d90  ff151ccb4d00           -call dword ptr [0x4dcb1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098268) /* 0x4dcb1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6d96  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004b6d99  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b6d9b  7407                   -je 0x4b6da4
    if (cpu.flags.zf)
    {
        goto L_0x004b6da4;
    }
    // 004b6d9d  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 004b6d9f  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b6da1  648902                 -mov dword ptr fs:[edx], eax
    app->getMemory<x86::reg32>(cpu.efs + cpu.edx) = cpu.eax;
L_0x004b6da4:
    // 004b6da4  ff151ccb4d00           -call dword ptr [0x4dcb1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098268) /* 0x4dcb1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6daa  c7405400000000         -mov dword ptr [eax + 0x54], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */) = 0 /*0x0*/;
    // 004b6db1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6db2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6db3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6db3);
    // 004b6db3  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b6db8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6db9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6dba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6dbb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b6dbd  ff1530cb4d00           -call dword ptr [0x4dcb30]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098288) /* 0x4dcb30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6dc3  8b15e4435b00           -mov edx, dword ptr [0x5b43e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5981156) /* 0x5b43e4 */);
    // 004b6dc9  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004b6dcb  eb16                   -jmp 0x4b6de3
    goto L_0x004b6de3;
L_0x004b6dcd:
    // 004b6dcd  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004b6dd0  85480c                 -test dword ptr [eax + 0xc], ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) & cpu.ecx));
    // 004b6dd3  740c                   -je 0x4b6de1
    if (cpu.flags.zf)
    {
        goto L_0x004b6de1;
    }
    // 004b6dd5  43                     -inc ebx
    (cpu.ebx)++;
    // 004b6dd6  f6400d10               +test byte ptr [eax + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 004b6dda  7405                   -je 0x4b6de1
    if (cpu.flags.zf)
    {
        goto L_0x004b6de1;
    }
    // 004b6ddc  e86e00ffff             -call 0x4a6e4f
    cpu.esp -= 4;
    sub_4a6e4f(app, cpu);
    if (cpu.terminate) return;
L_0x004b6de1:
    // 004b6de1  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
L_0x004b6de3:
    // 004b6de3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b6de5  75e6                   -jne 0x4b6dcd
    if (!cpu.flags.zf)
    {
        goto L_0x004b6dcd;
    }
    // 004b6de7  ff1534cb4d00           -call dword ptr [0x4dcb34]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098292) /* 0x4dcb34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6ded  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b6def  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6df0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6df1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6df2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6db8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6db8);
    goto L_entry_0x004b6db8;
    // 004b6db3  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_entry_0x004b6db8:
    // 004b6db8  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6db9  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6dba  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6dbb  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b6dbd  ff1530cb4d00           -call dword ptr [0x4dcb30]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098288) /* 0x4dcb30 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6dc3  8b15e4435b00           -mov edx, dword ptr [0x5b43e4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5981156) /* 0x5b43e4 */);
    // 004b6dc9  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004b6dcb  eb16                   -jmp 0x4b6de3
    goto L_0x004b6de3;
L_0x004b6dcd:
    // 004b6dcd  8b4204                 -mov eax, dword ptr [edx + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 004b6dd0  85480c                 -test dword ptr [eax + 0xc], ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) & cpu.ecx));
    // 004b6dd3  740c                   -je 0x4b6de1
    if (cpu.flags.zf)
    {
        goto L_0x004b6de1;
    }
    // 004b6dd5  43                     -inc ebx
    (cpu.ebx)++;
    // 004b6dd6  f6400d10               +test byte ptr [eax + 0xd], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(13) /* 0xd */) & 16 /*0x10*/));
    // 004b6dda  7405                   -je 0x4b6de1
    if (cpu.flags.zf)
    {
        goto L_0x004b6de1;
    }
    // 004b6ddc  e86e00ffff             -call 0x4a6e4f
    cpu.esp -= 4;
    sub_4a6e4f(app, cpu);
    if (cpu.terminate) return;
L_0x004b6de1:
    // 004b6de1  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
L_0x004b6de3:
    // 004b6de3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b6de5  75e6                   -jne 0x4b6dcd
    if (!cpu.flags.zf)
    {
        goto L_0x004b6dcd;
    }
    // 004b6de7  ff1534cb4d00           -call dword ptr [0x4dcb34]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098292) /* 0x4dcb34 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6ded  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b6def  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6df0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6df1  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6df2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6df3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6df3);
    // 004b6df3  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6df4  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6df5  8b1db8b84d00           -mov ebx, dword ptr [0x4db8b8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5093560) /* 0x4db8b8 */);
    // 004b6dfb  e8d5680000             -call 0x4bd6d5
    cpu.esp -= 4;
    sub_4bd6d5(app, cpu);
    if (cpu.terminate) return;
    // 004b6e00  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b6e02  83f8ff                 +cmp eax, -1
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
    // 004b6e05  7409                   -je 0x4b6e10
    if (cpu.flags.zf)
    {
        goto L_0x004b6e10;
    }
    // 004b6e07  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b6e09  7505                   -jne 0x4b6e10
    if (!cpu.flags.zf)
    {
        goto L_0x004b6e10;
    }
    // 004b6e0b  e841690000             -call 0x4bd751
    cpu.esp -= 4;
    sub_4bd751(app, cpu);
    if (cpu.terminate) return;
L_0x004b6e10:
    // 004b6e10  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b6e12  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6e13  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6e14  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6e15(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6e15);
    // 004b6e15  8a8095805b00           -mov al, byte ptr [eax + 0x5b8095]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5996693) /* 0x5b8095 */);
    // 004b6e1b  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b6e1d  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b6e22  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6e23(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6e23);
    // 004b6e23  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b6e25  e98b690000             -jmp 0x4bd7b5
    return sub_4bd7b5(app, cpu);
}

/* align: skip  */
void Application::sub_4b6e2a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6e2a);
    // 004b6e2a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6e2b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6e2c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b6e2d  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b6e2e  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b6e30  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b6e33  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b6e35  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b6e37  7507                   -jne 0x4b6e40
    if (!cpu.flags.zf)
    {
        goto L_0x004b6e40;
    }
L_0x004b6e39:
    // 004b6e39  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b6e3b  e977000000             -jmp 0x4b6eb7
    goto L_0x004b6eb7;
L_0x004b6e40:
    // 004b6e40  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b6e42  0f866a000000           -jbe 0x4b6eb2
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b6eb2;
    }
    // 004b6e48  803a00                 +cmp byte ptr [edx], 0
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
    // 004b6e4b  750b                   -jne 0x4b6e58
    if (!cpu.flags.zf)
    {
        goto L_0x004b6e58;
    }
    // 004b6e4d  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b6e4f  74e8                   -je 0x4b6e39
    if (cpu.flags.zf)
    {
        goto L_0x004b6e39;
    }
    // 004b6e51  66c7060000             -mov word ptr [esi], 0
    app->getMemory<x86::reg16>(cpu.esi) = 0 /*0x0*/;
    // 004b6e56  ebe1                   -jmp 0x4b6e39
    goto L_0x004b6e39;
L_0x004b6e58:
    // 004b6e58  833d90805b0000         +cmp dword ptr [0x5b8090], 0
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
    // 004b6e5f  7419                   -je 0x4b6e7a
    if (cpu.flags.zf)
    {
        goto L_0x004b6e7a;
    }
    // 004b6e61  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b6e63  8a02                   -mov al, byte ptr [edx]
    cpu.al = app->getMemory<x86::reg8>(cpu.edx);
    // 004b6e65  8a8095805b00           -mov al, byte ptr [eax + 0x5b8095]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(5996693) /* 0x5b8095 */);
    // 004b6e6b  2401                   -and al, 1
    cpu.al &= x86::reg8(x86::sreg8(1 /*0x1*/));
    // 004b6e6d  25ff000000             +and eax, 0xff
    cpu.clear_co();
    cpu.set_szp((cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/))));
    // 004b6e72  7406                   -je 0x4b6e7a
    if (cpu.flags.zf)
    {
        goto L_0x004b6e7a;
    }
    // 004b6e74  807a0100               +cmp byte ptr [edx + 1], 0
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
    // 004b6e78  7438                   -je 0x4b6eb2
    if (cpu.flags.zf)
    {
        goto L_0x004b6eb2;
    }
L_0x004b6e7a:
    // 004b6e7a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b6e7c  e8806a0000             -call 0x4bd901
    cpu.esp -= 4;
    sub_4bd901(app, cpu);
    if (cpu.terminate) return;
    // 004b6e81  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004b6e83  8d4dfc                 -lea ecx, [ebp - 4]
    cpu.ecx = x86::reg32(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004b6e86  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b6e88  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6e89  39c3                   +cmp ebx, eax
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
    // 004b6e8b  7302                   -jae 0x4b6e8f
    if (!cpu.flags.cf)
    {
        goto L_0x004b6e8f;
    }
    // 004b6e8d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x004b6e8f:
    // 004b6e8f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b6e90  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6e91  6a08                   -push 8
    app->getMemory<x86::reg32>(cpu.esp-4) = 8 /*0x8*/;
    cpu.esp -= 4;
    // 004b6e93  a198e84d00             -mov eax, dword ptr [0x4de898]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5105816) /* 0x4de898 */);
    // 004b6e98  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b6e99  2eff1524454c00         -call dword ptr cs:[0x4c4524]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998436) /* 0x4c4524 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6ea0  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b6ea2  740e                   -je 0x4b6eb2
    if (cpu.flags.zf)
    {
        goto L_0x004b6eb2;
    }
    // 004b6ea4  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004b6ea6  7406                   -je 0x4b6eae
    if (cpu.flags.zf)
    {
        goto L_0x004b6eae;
    }
    // 004b6ea8  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004b6eab  668906                 -mov word ptr [esi], ax
    app->getMemory<x86::reg16>(cpu.esi) = cpu.ax;
L_0x004b6eae:
    // 004b6eae  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b6eb0  eb05                   -jmp 0x4b6eb7
    goto L_0x004b6eb7;
L_0x004b6eb2:
    // 004b6eb2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x004b6eb7:
    // 004b6eb7  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004b6eb9  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6eba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6ebb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6ebc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6ebd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6ebe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6ebe);
    // 004b6ebe  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6ebf  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 004b6ec4  b824fc4c00             -mov eax, 0x4cfc24
    cpu.eax = 5045284 /*0x4cfc24*/;
    // 004b6ec9  e893290000             -call 0x4b9861
    cpu.esp -= 4;
    sub_4b9861(app, cpu);
    if (cpu.terminate) return;
    // 004b6ece  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6ecf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6ed0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6ed0);
    // 004b6ed0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6ed1  f7c20000f07f           +test edx, 0x7ff00000
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & 2146435072 /*0x7ff00000*/));
    // 004b6ed7  743f                   -je 0x4b6f18
    if (cpu.flags.zf)
    {
        goto L_0x004b6f18;
    }
    // 004b6ed9  29db                   -sub ebx, ebx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b6edb  01c0                   +add eax, eax
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
    // 004b6edd  11d2                   +adc edx, edx
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
    // 004b6edf  d1db                   -rcr ebx, 1
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
    // 004b6ee1  0500000020             +add eax, 0x20000000
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
    // 004b6ee6  83d200                 +adc edx, 0
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
    // 004b6ee9  7424                   -je 0x4b6f0f
    if (cpu.flags.zf)
    {
        goto L_0x004b6f0f;
    }
    // 004b6eeb  81fa0000e08f           +cmp edx, 0x8fe00000
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
    // 004b6ef1  731c                   -jae 0x4b6f0f
    if (!cpu.flags.cf)
    {
        goto L_0x004b6f0f;
    }
    // 004b6ef3  81fa00002070           +cmp edx, 0x70200000
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
    // 004b6ef9  721d                   -jb 0x4b6f18
    if (cpu.flags.cf)
    {
        goto L_0x004b6f18;
    }
    // 004b6efb  81ea00000070           -sub edx, 0x70000000
    (cpu.edx) -= x86::reg32(x86::sreg32(1879048192 /*0x70000000*/));
    // 004b6f01  01c0                   +add eax, eax
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
    // 004b6f03  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004b6f05  01c0                   +add eax, eax
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
    // 004b6f07  11d2                   -adc edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004b6f09  09da                   -or edx, ebx
    cpu.edx |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b6f0b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004b6f0d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6f0e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b6f0f:
    // 004b6f0f  b80000807f             -mov eax, 0x7f800000
    cpu.eax = 2139095040 /*0x7f800000*/;
    // 004b6f14  09d8                   -or eax, ebx
    cpu.eax |= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b6f16  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6f17  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b6f18:
    // 004b6f18  29c0                   -sub eax, eax
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004b6f1a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6f1b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6f1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6f1c);
    // 004b6f1c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004b6f1e  7507                   -jne 0x4b6f27
    if (!cpu.flags.zf)
    {
        goto L_0x004b6f27;
    }
    // 004b6f20  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b6f22  7503                   -jne 0x4b6f27
    if (!cpu.flags.zf)
    {
        goto L_0x004b6f27;
    }
    // 004b6f24  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 004b6f26  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b6f27:
    // 004b6f27  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b6f28  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6f29  f7e1                   -mul ecx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ecx);
    // 004b6f2b  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004b6f2d  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6f2e  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 004b6f30  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004b6f32  58                     -pop eax
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6f33  f7e3                   -mul ebx
    cpu.edx_eax = x86::reg64(cpu.eax) * x86::reg64(cpu.ebx);
    // 004b6f35  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 004b6f37  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6f38(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6f38);
    // 004b6f38  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b6f39  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6f3a  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004b6f3c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b6f3d  2eff15b4444c00         -call dword ptr cs:[0x4c44b4]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998324) /* 0x4c44b4 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6f44  83f8ff                 +cmp eax, -1
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
    // 004b6f47  7508                   -jne 0x4b6f51
    if (!cpu.flags.zf)
    {
        goto L_0x004b6f51;
    }
    // 004b6f49  e8d4b1feff             -call 0x4a2122
    cpu.esp -= 4;
    sub_4a2122(app, cpu);
    if (cpu.terminate) return;
    // 004b6f4e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6f4f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6f50  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b6f51:
    // 004b6f51  f6c302                 +test bl, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 2 /*0x2*/));
    // 004b6f54  7411                   -je 0x4b6f67
    if (cpu.flags.zf)
    {
        goto L_0x004b6f67;
    }
    // 004b6f56  a801                   +test al, 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 1 /*0x1*/));
    // 004b6f58  740d                   -je 0x4b6f67
    if (cpu.flags.zf)
    {
        goto L_0x004b6f67;
    }
    // 004b6f5a  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 004b6f5f  e86db1feff             -call 0x4a20d1
    cpu.esp -= 4;
    sub_4a20d1(app, cpu);
    if (cpu.terminate) return;
    // 004b6f64  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6f65  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6f66  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b6f67:
    // 004b6f67  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b6f69  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6f6a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6f6b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6f6c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6f6c);
    // 004b6f6c  ff151ccb4d00           -call dword ptr [0x4dcb1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098268) /* 0x4dcb1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6f72  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b6f75  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6f76(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6f76);
    // 004b6f76  ff151ccb4d00           -call dword ptr [0x4dcb1c]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098268) /* 0x4dcb1c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6f7c  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b6f7f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6f80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6f80);
    // 004b6f80  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6f81  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b6f82  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b6f83  2eff1520454c00         -call dword ptr cs:[0x4c4520]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998432) /* 0x4c4520 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b6f8a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b6f8c  7507                   -jne 0x4b6f95
    if (!cpu.flags.zf)
    {
        goto L_0x004b6f95;
    }
    // 004b6f8e  e88fb1feff             -call 0x4a2122
    cpu.esp -= 4;
    sub_4a2122(app, cpu);
    if (cpu.terminate) return;
    // 004b6f93  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6f94  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b6f95:
    // 004b6f95  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b6f97  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b6f98  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b6f99(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b6f99);
    // 004b6f99  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b6f9a  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b6f9b  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b6f9c  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b6f9f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b6fa1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004b6fa3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b6fa5  7522                   -jne 0x4b6fc9
    if (!cpu.flags.zf)
    {
        goto L_0x004b6fc9;
    }
    // 004b6fa7  bb04010000             -mov ebx, 0x104
    cpu.ebx = 260 /*0x104*/;
    // 004b6fac  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b6fae  e880b1feff             -call 0x4a2133
    cpu.esp -= 4;
    sub_4a2133(app, cpu);
    if (cpu.terminate) return;
    // 004b6fb3  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004b6fb5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b6fb7  750e                   -jne 0x4b6fc7
    if (!cpu.flags.zf)
    {
        goto L_0x004b6fc7;
    }
    // 004b6fb9  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
L_0x004b6fbe:
    // 004b6fbe  e85db2feff             -call 0x4a2220
    cpu.esp -= 4;
    sub_4a2220(app, cpu);
    if (cpu.terminate) return;
L_0x004b6fc3:
    // 004b6fc3  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 004b6fc5  eb5c                   -jmp 0x4b7023
    goto L_0x004b7023;
L_0x004b6fc7:
    // 004b6fc7  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x004b6fc9:
    // 004b6fc9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004b6fcb  7405                   -je 0x4b6fd2
    if (cpu.flags.zf)
    {
        goto L_0x004b6fd2;
    }
    // 004b6fcd  803900                 +cmp byte ptr [ecx], 0
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
    // 004b6fd0  750b                   -jne 0x4b6fdd
    if (!cpu.flags.zf)
    {
        goto L_0x004b6fdd;
    }
L_0x004b6fd2:
    // 004b6fd2  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b6fd4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b6fd6  e8dadefcff             -call 0x484eb5
    cpu.esp -= 4;
    sub_484eb5(app, cpu);
    if (cpu.terminate) return;
    // 004b6fdb  eb46                   -jmp 0x4b7023
    goto L_0x004b7023;
L_0x004b6fdd:
    // 004b6fdd  ba48fc4c00             -mov edx, 0x4cfc48
    cpu.edx = 5045320 /*0x4cfc48*/;
    // 004b6fe2  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 004b6fe4  e8ba30feff             -call 0x49a0a3
    cpu.esp -= 4;
    sub_49a0a3(app, cpu);
    if (cpu.terminate) return;
    // 004b6fe9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b6feb  751c                   -jne 0x4b7009
    if (!cpu.flags.zf)
    {
        goto L_0x004b7009;
    }
    // 004b6fed  83fb04                 +cmp ebx, 4
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
    // 004b6ff0  730e                   -jae 0x4b7000
    if (!cpu.flags.cf)
    {
        goto L_0x004b7000;
    }
    // 004b6ff2  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004b6ff4  e8bf00ffff             -call 0x4a70b8
    cpu.esp -= 4;
    sub_4a70b8(app, cpu);
    if (cpu.terminate) return;
    // 004b6ff9  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 004b6ffe  ebbe                   -jmp 0x4b6fbe
    goto L_0x004b6fbe;
L_0x004b7000:
    // 004b7000  a148fc4c00             -mov eax, dword ptr [0x4cfc48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5045320) /* 0x4cfc48 */);
    // 004b7005  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 004b7007  eb18                   -jmp 0x4b7021
    goto L_0x004b7021;
L_0x004b7009:
    // 004b7009  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004b700b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b700c  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b700d  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b700e  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b700f  2eff15c0444c00         -call dword ptr cs:[0x4c44c0]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998336) /* 0x4c44c0 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b7016  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b7018  7507                   -jne 0x4b7021
    if (!cpu.flags.zf)
    {
        goto L_0x004b7021;
    }
    // 004b701a  e803b1feff             -call 0x4a2122
    cpu.esp -= 4;
    sub_4a2122(app, cpu);
    if (cpu.terminate) return;
    // 004b701f  eba2                   -jmp 0x4b6fc3
    goto L_0x004b6fc3;
L_0x004b7021:
    // 004b7021  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x004b7023:
    // 004b7023  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004b7026  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7027  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7028  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7029  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b702a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b702a);
    // 004b702a  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b702b  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b702c  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004b702d  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b702e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b7030  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 004b7032  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b7034  7c08                   -jl 0x4b703e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004b703e;
    }
    // 004b7036  3b05e8e44d00           +cmp eax, dword ptr [0x4de4e8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5104872) /* 0x4de4e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004b703c  7614                   -jbe 0x4b7052
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004b7052;
    }
L_0x004b703e:
    // 004b703e  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 004b7043  e8d8b1feff             -call 0x4a2220
    cpu.esp -= 4;
    sub_4a2220(app, cpu);
    if (cpu.terminate) return;
    // 004b7048  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004b704d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b704e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b704f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7050  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7051  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004b7052:
    // 004b7052  ff1520cb4d00           -call dword ptr [0x4dcb20]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098272) /* 0x4dcb20 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b7058  a1d8e44d00             -mov eax, dword ptr [0x4de4d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5104856) /* 0x4de4d8 */);
    // 004b705d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b705f  8b0490                 -mov eax, dword ptr [eax + edx*4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + cpu.edx * 4);
    // 004b7062  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004b7063  2eff156c444c00         -call dword ptr cs:[0x4c446c]
    cpu.ip = app->getMemory<x86::reg32>(cpu.ecs + x86::reg32(4998252) /* 0x4c446c */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b706a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004b706c  750a                   -jne 0x4b7078
    if (!cpu.flags.zf)
    {
        goto L_0x004b7078;
    }
    // 004b706e  e8afb0feff             -call 0x4a2122
    cpu.esp -= 4;
    sub_4a2122(app, cpu);
    if (cpu.terminate) return;
    // 004b7073  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
L_0x004b7078:
    // 004b7078  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004b707a  ff1524cb4d00           -call dword ptr [0x4dcb24]
    cpu.ip = app->getMemory<x86::reg32>(x86::reg32(5098276) /* 0x4dcb24 */);
    cpu.esp -= 4;
    app->dynamic_call(cpu.ip, cpu);
    if (cpu.terminate) return;
    // 004b7080  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b7082  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7083  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7084  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7085  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7086  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7087(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7087);
    // 004b7087  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004b7088  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004b708a  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004b708b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004b708c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004b708d  83ec40                 -sub esp, 0x40
    (cpu.esp) -= x86::reg32(x86::sreg32(64 /*0x40*/));
    // 004b7090  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004b7092  89d9                   -mov ecx, ebx
    cpu.ecx = cpu.ebx;
    // 004b7094  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b7096  8a4315                 -mov al, byte ptr [ebx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(21) /* 0x15 */);
    // 004b7099  8945c0                 -mov dword ptr [ebp - 0x40], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.eax;
    // 004b709c  8a4115                 -mov al, byte ptr [ecx + 0x15]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(21) /* 0x15 */);
    // 004b709f  8b5b08                 -mov ebx, dword ptr [ebx + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(8) /* 0x8 */);
    // 004b70a2  245f                   -and al, 0x5f
    cpu.al &= x86::reg8(x86::sreg8(95 /*0x5f*/));
    // 004b70a4  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b70a9  83f847                 +cmp eax, 0x47
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
    // 004b70ac  7523                   -jne 0x4b70d1
    if (!cpu.flags.zf)
    {
        goto L_0x004b70d1;
    }
    // 004b70ae  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 004b70b0  7505                   -jne 0x4b70b7
    if (!cpu.flags.zf)
    {
        goto L_0x004b70b7;
    }
    // 004b70b2  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
L_0x004b70b7:
    // 004b70b7  c745bc04000000         -mov dword ptr [ebp - 0x44], 4
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = 4 /*0x4*/;
    // 004b70be  8b7dc0                 -mov edi, dword ptr [ebp - 0x40]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */);
    // 004b70c1  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004b70c6  83ef02                 +sub edi, 2
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
    // 004b70c9  8945b8                 -mov dword ptr [ebp - 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
    // 004b70cc  897dc0                 -mov dword ptr [ebp - 0x40], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-64) /* -0x40 */) = cpu.edi;
    // 004b70cf  eb1f                   -jmp 0x4b70f0
    goto L_0x004b70f0;
L_0x004b70d1:
    // 004b70d1  83f845                 +cmp eax, 0x45
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
    // 004b70d4  750d                   -jne 0x4b70e3
    if (!cpu.flags.zf)
    {
        goto L_0x004b70e3;
    }
    // 004b70d6  bf01000000             -mov edi, 1
    cpu.edi = 1 /*0x1*/;
    // 004b70db  897dbc                 -mov dword ptr [ebp - 0x44], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.edi;
    // 004b70de  897db8                 -mov dword ptr [ebp - 0x48], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.edi;
    // 004b70e1  eb0d                   -jmp 0x4b70f0
    goto L_0x004b70f0;
L_0x004b70e3:
    // 004b70e3  bf02000000             -mov edi, 2
    cpu.edi = 2 /*0x2*/;
    // 004b70e8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b70ea  897dbc                 -mov dword ptr [ebp - 0x44], edi
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-68) /* -0x44 */) = cpu.edi;
    // 004b70ed  8945b8                 -mov dword ptr [ebp - 0x48], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-72) /* -0x48 */) = cpu.eax;
L_0x004b70f0:
    // 004b70f0  f6411e01               +test byte ptr [ecx + 0x1e], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */) & 1 /*0x1*/));
    // 004b70f4  7404                   -je 0x4b70fa
    if (cpu.flags.zf)
    {
        goto L_0x004b70fa;
    }
    // 004b70f6  804dbc10               -or byte ptr [ebp - 0x44], 0x10
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(-68) /* -0x44 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x004b70fa:
    // 004b70fa  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004b70fc  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004b70ff  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004b7101  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004b7103  8b40f8                 -mov eax, dword ptr [eax - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(-8) /* -0x8 */);
    // 004b7106  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 004b7109  8b42fc                 -mov eax, dword ptr [edx - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-4) /* -0x4 */);
    // 004b710c  8d55e0                 -lea edx, [ebp - 0x20]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004b710f  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 004b7112  8d45ec                 -lea eax, [ebp - 0x14]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004b7115  dd00                   -fld qword ptr [eax]
    cpu.fpu.push(x86::Float(app->getMemory<double>(cpu.eax)));
    // 004b7117  db3a                   -fstp xword ptr [edx]
    app->getMemory<x86::IEEEf80>(cpu.edx) = x86::Float(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b7119  83fbff                 +cmp ebx, -1
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
    // 004b711c  7505                   -jne 0x4b7123
    if (!cpu.flags.zf)
    {
        goto L_0x004b7123;
    }
    // 004b711e  bb06000000             -mov ebx, 6
    cpu.ebx = 6 /*0x6*/;
L_0x004b7123:
    // 004b7123  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004b7126  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b7128  895db4                 -mov dword ptr [ebp - 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-76) /* -0x4c */) = cpu.ebx;
    // 004b712b  8955c4                 -mov dword ptr [ebp - 0x3c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-60) /* -0x3c */) = cpu.edx;
    // 004b712e  8d5e01                 -lea ebx, [esi + 1]
    cpu.ebx = x86::reg32(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b7131  8d55b4                 -lea edx, [ebp - 0x4c]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-76) /* -0x4c */);
    // 004b7134  e82b690000             -call 0x4bda64
    cpu.esp -= 4;
    sub_4bda64(app, cpu);
    if (cpu.terminate) return;
    // 004b7139  8b45d0                 -mov eax, dword ptr [ebp - 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-48) /* -0x30 */);
    // 004b713c  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 004b713f  8b45d4                 -mov eax, dword ptr [ebp - 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-44) /* -0x2c */);
    // 004b7142  89412c                 -mov dword ptr [ecx + 0x2c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */) = cpu.eax;
    // 004b7145  8b45d8                 -mov eax, dword ptr [ebp - 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-40) /* -0x28 */);
    // 004b7148  894130                 -mov dword ptr [ecx + 0x30], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 004b714b  8b45dc                 -mov eax, dword ptr [ebp - 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-36) /* -0x24 */);
    // 004b714e  894134                 -mov dword ptr [ecx + 0x34], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(52) /* 0x34 */) = cpu.eax;
    // 004b7151  837dc800               +cmp dword ptr [ebp - 0x38], 0
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
    // 004b7155  7d0f                   -jge 0x4b7166
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004b7166;
    }
    // 004b7157  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004b715a  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b715d  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004b7160  c604062d               -mov byte ptr [esi + eax], 0x2d
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 45 /*0x2d*/;
    // 004b7164  eb29                   -jmp 0x4b718f
    goto L_0x004b718f;
L_0x004b7166:
    // 004b7166  8a611e                 -mov ah, byte ptr [ecx + 0x1e]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(30) /* 0x1e */);
    // 004b7169  f6c404                 +test ah, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 4 /*0x4*/));
    // 004b716c  740f                   -je 0x4b717d
    if (cpu.flags.zf)
    {
        goto L_0x004b717d;
    }
    // 004b716e  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004b7171  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b7174  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004b7177  c604062b               -mov byte ptr [esi + eax], 0x2b
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 43 /*0x2b*/;
    // 004b717b  eb12                   -jmp 0x4b718f
    goto L_0x004b718f;
L_0x004b717d:
    // 004b717d  f6c402                 +test ah, 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 2 /*0x2*/));
    // 004b7180  740d                   -je 0x4b718f
    if (cpu.flags.zf)
    {
        goto L_0x004b718f;
    }
    // 004b7182  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 004b7185  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 004b7188  895120                 -mov dword ptr [ecx + 0x20], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.edx;
    // 004b718b  c6040620               -mov byte ptr [esi + eax], 0x20
    app->getMemory<x86::reg8>(cpu.esi + cpu.eax * 1) = 32 /*0x20*/;
L_0x004b718f:
    // 004b718f  8cda                   -mov edx, ds
    cpu.edx = cpu.ds;
    // 004b7191  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004b7193  8d65f4                 -lea esp, [ebp - 0xc]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004b7196  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7197  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7198  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b7199  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b719a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b719b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b719b);
    // 004b719b  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004b719c  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 004b719e  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004b71a0  e809740000             -call 0x4be5ae
    cpu.esp -= 4;
    sub_4be5ae(app, cpu);
    if (cpu.terminate) return;
    // 004b71a5  dd1b                   -fstp qword ptr [ebx]
    app->getMemory<double>(cpu.ebx) = double(cpu.fpu.st(0));
    cpu.fpu.pop();
    // 004b71a7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004b71a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4b71ac(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b71ac);
    // 004b71ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b71ad(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b71ad);
    // 004b71ad  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b71af  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b71b2  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b71b8  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b71ba  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b71bd  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b71c0  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b71c6  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b71c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b71c9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b71c9);
    // 004b71c9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b71cb  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b71cd  81e3fcfcfcfc           -and ebx, 0xfcfcfcfc
    cpu.ebx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004b71d3  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b71d6  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b71db  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b71dd  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b71e0  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b71e3  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b71e9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b71eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b71ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b71ec);
    // 004b71ec  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b71ee  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b71f0  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b71f6  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b71f9  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b71fe  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7200  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b7203  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b7205  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7208  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b720e  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b7211  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7217  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b7219  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b721b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b721c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b721c);
    // 004b721c  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b721e  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b7223  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b7226  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b7228  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b722e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7230  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7231(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7231);
    // 004b7231  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b7233  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b7236  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b723c  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b723f  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7244  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7246  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b7249  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b724b  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b724d  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b7253  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b7256  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b725c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b725e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7260  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7261(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7261);
    // 004b7261  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b7264  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7269  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b726c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b726e  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b7270  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004b7276  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004b7279  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b727f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b7281  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7283  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7284(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7284);
    // 004b7284  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b7287  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b728c  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b728f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b7291  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b7294  81e21f1f1f1f           -and edx, 0x1f1f1f1f
    cpu.edx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b729a  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b729c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b729e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b729f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b729f);
    // 004b729f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b72a1  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b72a4  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b72aa  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b72ac  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b72af  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b72b2  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b72b8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b72ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b72bb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b72bb);
    // 004b72bb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b72bd  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b72bf  81e3fcfcfcfc           -and ebx, 0xfcfcfcfc
    cpu.ebx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004b72c5  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b72c8  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b72cd  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b72cf  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b72d2  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b72d5  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b72db  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b72dd  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b72e0  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b72e3  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b72e9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b72eb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b72ec(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b72ec);
    // 004b72ec  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b72ee  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b72f0  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b72f6  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b72f9  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b72fe  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7300  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b7303  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7306  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b730c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b730e  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b7311  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7314  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b731a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b731c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b731d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b731d);
    // 004b731d  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b731f  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b7324  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b7327  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b7329  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b732c  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b7332  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b7335  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b733b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b733d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b733f  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b7342  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7345  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b734b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b734d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b734e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b734e);
    // 004b734e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b7350  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b7353  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b7359  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b735c  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7361  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7363  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b7366  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b7368  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b736e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7370  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b7374  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7377  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b737d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b737f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7380(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7380);
    // 004b7380  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b7383  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7388  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b738b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b738d  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b738f  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b7395  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b7398  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b739e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b73a0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b73a2  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b73a6  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b73a9  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b73af  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b73b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b73b2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b73b2);
    // 004b73b2  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b73b5  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b73ba  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b73bd  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b73bf  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b73c1  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004b73c7  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004b73ca  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b73d0  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b73d2  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b73d4  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b73d8  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b73db  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b73e1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b73e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b73e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b73e4);
    // 004b73e4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b73e6  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b73e8  81e3fcfcfcfc           -and ebx, 0xfcfcfcfc
    cpu.ebx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004b73ee  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b73f1  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b73f6  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b73f8  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b73fb  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b73fe  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7404  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7406  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7407(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7407);
    // 004b7407  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b7409  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b740b  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b7411  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7414  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b7419  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b741b  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b741e  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7421  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b7427  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7429  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b742c  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b742f  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7435  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7437  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7438(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7438);
    // 004b7438  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b743a  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b743f  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b7442  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7445  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b744b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b744d  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b7450  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7453  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7459  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b745b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b745c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b745c);
    // 004b745c  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b745e  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b7463  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b7466  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7469  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b746f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7471  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b7474  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7477  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b747d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b747f  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b7483  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7486  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b748c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b748e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b748f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b748f);
    // 004b748f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b7491  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b7494  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b749a  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b749d  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b74a2  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b74a4  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b74a7  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b74a9  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b74ac  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b74b2  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b74b5  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b74bb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b74bd  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b74bf  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b74c2  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b74c5  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b74cb  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b74cd  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b74d1  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b74d4  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b74da  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b74dc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b74dd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b74dd);
    // 004b74dd  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b74e0  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b74e5  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b74e8  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b74ea  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b74f0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b74f2  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b74f5  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b74f8  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b74fe  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7500  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b7504  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7507  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b750d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b750f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7510(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7510);
    // 004b7510  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b7513  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7518  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b751b  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b751d  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b7523  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7525  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b7529  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b752c  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7532  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7534  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7535(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7535);
    // 004b7535  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b7538  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b753d  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b7540  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b7542  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b7544  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b754a  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b754d  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b7553  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b7555  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7557  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b755b  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b755e  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7564  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7566  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7567(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7567);
    // 004b7567  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b7569  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b756b  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b7571  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7574  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b7579  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b757b  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b757e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b7580  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7583  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b7589  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b758c  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7592  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b7594  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7596  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7597(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7597);
    // 004b7597  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b7599  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b759e  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b75a1  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b75a4  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b75aa  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b75ac  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b75af  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b75b1  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b75b4  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b75ba  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b75bd  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b75c3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b75c5  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b75c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b75c8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b75c8);
    // 004b75c8  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b75ca  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b75cf  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b75d2  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b75d5  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b75db  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b75dd  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b75e0  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b75e3  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b75e9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b75eb  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b75ef  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b75f2  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b75f8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b75fa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b75fb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b75fb);
    // 004b75fb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b75fd  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b7600  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b7606  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7609  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b760e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7610  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b7613  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7616  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b761c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b761e  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b7621  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7624  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b762a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b762c  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b7630  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7633  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b7639  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b763b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b763c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b763c);
    // 004b763c  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b763f  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7644  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b7647  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b764a  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7650  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7652  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b7655  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7658  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b765e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7660  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b7664  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7667  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b766d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b766f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7670(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7670);
    // 004b7670  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b7673  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7678  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b767b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b767d  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7680  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b7686  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b7689  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b768f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b7691  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7693  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b7696  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7699  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b769f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b76a1  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b76a5  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b76a8  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b76ae  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b76b0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b76b1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b76b1);
    // 004b76b1  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b76b4  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b76b9  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b76bc  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b76be  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b76c4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b76c6  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b76c9  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b76cc  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b76d2  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b76d4  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b76d8  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b76db  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b76e1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b76e3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b76e4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b76e4);
    // 004b76e4  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b76e7  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b76ec  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b76ef  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b76f1  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b76f7  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b76f9  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b76fd  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b76ff  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7702  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b7708  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b770b  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7711  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b7713  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7715  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7716(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7716);
    // 004b7716  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b7718  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b771d  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b7720  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b7722  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b7728  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b772a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b772b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b772b);
    // 004b772b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b772d  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b7730  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b7736  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7739  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b773e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7740  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b7743  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7746  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b774c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b774e  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b7751  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b7753  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7756  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b775c  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b775f  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7765  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b7767  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7769  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b776d  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7770  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b7776  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7778  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7779(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7779);
    // 004b7779  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b777c  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b7781  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b7784  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b7786  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7789  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b778f  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b7792  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7798  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b779a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b779c  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b779f  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b77a2  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b77a8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b77aa  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b77ae  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b77b0  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b77b3  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b77b9  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b77bc  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b77c2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b77c4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b77c6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b77c7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b77c7);
    // 004b77c7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b77c9  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b77cc  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b77ce  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b77d4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b77d6  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b77da  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b77dc  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b77e2  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b77e4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b77e5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b77e5);
    // 004b77e5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b77e7  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b77ea  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b77f0  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b77f3  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b77f8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b77fa  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b77fd  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b77ff  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b7801  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b7807  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b780a  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b7810  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b7812  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7814  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7815(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7815);
    // 004b7815  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b7817  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b781a  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b7820  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7823  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7828  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b782a  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b782d  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b782f  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b7835  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7837  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b783b  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b783e  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b7844  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7846  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7847(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7847);
    // 004b7847  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b784a  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b784f  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b7852  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7855  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b785b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b785d  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b7860  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b7862  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b7868  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b786a  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b786e  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7871  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b7877  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7879  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b787a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b787a);
    // 004b787a  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b787d  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7882  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b7885  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7888  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b788e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7890  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b7893  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b7895  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7898  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b789e  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b78a1  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b78a7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b78a9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b78ab  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b78af  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b78b2  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b78b8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b78ba  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b78bb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b78bb);
    // 004b78bb  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b78be  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b78c3  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b78c6  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b78c9  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b78cf  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b78d1  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b78d4  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b78d7  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b78dd  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b78df  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b78e3  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b78e5  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b78e8  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b78ee  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b78f1  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b78f7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b78f9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b78fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b78fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b78fc);
    // 004b78fc  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b78ff  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b7904  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b7907  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b790a  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7910  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7912  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b7915  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7918  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b791e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7920  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b7924  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b7926  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b792c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b792e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b792f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b792f);
    // 004b792f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b7931  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b7934  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b7936  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7939  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b793f  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b7942  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7948  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b794a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b794c  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b794f  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7952  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b7958  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b795a  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b795e  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b7960  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b7966  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7968  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7969(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7969);
    // 004b7969  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b796c  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7971  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b7974  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b7976  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b7978  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004b797e  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004b7981  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b7987  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b7989  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b798b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b798c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b798c);
    // 004b798c  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b798f  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7994  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b7997  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b7999  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b799b  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b79a1  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b79a4  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b79aa  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b79ac  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b79ae  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b79b2  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b79b5  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b79bb  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b79bd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b79be(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b79be);
    // 004b79be  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b79c1  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b79c6  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b79c9  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b79cb  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b79d1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b79d3  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b79d7  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b79da  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b79e0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b79e2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b79e3(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b79e3);
    // 004b79e3  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b79e6  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b79eb  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b79ee  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b79f1  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b79f7  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b79f9  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b79fc  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b79fe  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b7a04  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7a06  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b7a0a  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7a0d  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7a13  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7a15  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7a16(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7a16);
    // 004b7a16  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b7a19  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b7a1e  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b7a21  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7a24  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b7a2a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7a2c  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b7a2f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b7a31  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7a34  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b7a3a  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b7a3d  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7a43  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b7a45  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7a47  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b7a4b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b7a4d  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7a50  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b7a56  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b7a59  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7a5f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b7a61  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7a63  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7a64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7a64);
    // 004b7a64  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b7a67  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b7a6c  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b7a6f  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7a72  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b7a78  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7a7a  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b7a7d  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7a80  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7a86  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7a88  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b7a8c  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b7a8e  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b7a94  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7a96  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7a97(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7a97);
    // 004b7a97  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b7a99  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b7a9c  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7a9f  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7aa5  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7aa7  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b7aaa  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7aad  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7ab3  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7ab5  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b7ab9  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b7abb  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b7ac1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7ac3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7ac4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7ac4);
    // 004b7ac4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b7ac6  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b7ac9  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7acc  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7ad2  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7ad4  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b7ad7  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7ada  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b7ae0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7ae2  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b7ae6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b7ae8  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b7aea  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b7af0  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b7af3  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b7af9  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b7afb  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7afd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7afe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7afe);
    // 004b7afe  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b7b01  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b7b06  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b7b09  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b7b0b  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b7b0e  81e21f1f1f1f           -and edx, 0x1f1f1f1f
    cpu.edx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b7b14  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b7b16  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7b18  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7b19(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7b19);
    // 004b7b19  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b7b1c  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b7b21  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b7b24  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b7b26  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b7b28  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004b7b2e  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004b7b31  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b7b37  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b7b39  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7b3b  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b7b3f  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7b42  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b7b48  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7b4a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7b4b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7b4b);
    // 004b7b4b  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b7b4e  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b7b53  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b7b56  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b7b58  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b7b5a  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b7b60  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b7b63  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b7b69  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b7b6b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7b6d  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b7b71  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7b74  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7b7a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7b7c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7b7d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7b7d);
    // 004b7b7d  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b7b80  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b7b85  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b7b88  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b7b8a  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b7b90  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7b92  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b7b96  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b7b98  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7b9b  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b7ba1  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b7ba4  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7baa  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b7bac  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7bae  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7baf(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7baf);
    // 004b7baf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b7bb1  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b7bb4  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b7bb6  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b7bbc  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7bbe  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b7bc2  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b7bc4  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b7bca  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7bcc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7bcd(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7bcd);
    // 004b7bcd  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b7bcf  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b7bd2  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7bd5  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b7bdb  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7bdd  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b7be0  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b7be2  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7be5  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b7beb  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b7bee  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7bf4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b7bf6  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7bf8  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b7bfc  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b7bfe  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b7c04  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7c06  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7c07(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7c07);
    // 004b7c07  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b7c09  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b7c0c  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7c0f  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b7c15  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7c17  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b7c1a  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b7c1d  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b7c23  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7c25  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b7c29  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b7c2b  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b7c2d  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b7c33  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b7c36  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b7c3c  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b7c3e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7c40  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b7c41(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7c41);
    // 004b7c41  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b7c43  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b7c46  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7c49  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b7c4f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7c51  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b7c54  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b7c57  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b7c5d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7c5f  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b7c63  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b7c65  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b7c67  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004b7c6d  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004b7c70  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b7c76  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b7c78  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b7c7a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4b7c7c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
  WinApplication::profileEntry(0x004b7c7c);
    // 004b7c7c  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
