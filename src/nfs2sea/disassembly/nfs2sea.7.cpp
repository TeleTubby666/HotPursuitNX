#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43cb40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043cb40  e81b380000             -call 0x440360
    cpu.esp -= 4;
    sub_440360(app, cpu);
    if (cpu.terminate) return;
    // 0043cb45  e8c6380000             -call 0x440410
    cpu.esp -= 4;
    sub_440410(app, cpu);
    if (cpu.terminate) return;
    // 0043cb4a  e911790200             -jmp 0x464460
    return sub_464460(app, cpu);
}

/* align: skip 0x00 */
void Application::sub_43cb50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043cb50  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43cb60(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043cb60  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043cb61  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043cb62  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043cb63  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043cb64  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043cb65  81ece8000000           -sub esp, 0xe8
    (cpu.esp) -= x86::reg32(x86::sreg32(232 /*0xe8*/));
    // 0043cb6b  898424e4000000         -mov dword ptr [esp + 0xe4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(228) /* 0xe4 */) = cpu.eax;
    // 0043cb72  899424e0000000         -mov dword ptr [esp + 0xe0], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */) = cpu.edx;
    // 0043cb79  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043cb7b  8b9424e4000000         -mov edx, dword ptr [esp + 0xe4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(228) /* 0xe4 */);
    // 0043cb82  bb1c000000             -mov ebx, 0x1c
    cpu.ebx = 28 /*0x1c*/;
    // 0043cb87  e874930300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043cb8c  8982b4030000           -mov dword ptr [edx + 0x3b4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(948) /* 0x3b4 */) = cpu.eax;
    // 0043cb92  81c2d0030000           -add edx, 0x3d0
    (cpu.edx) += x86::reg32(x86::sreg32(976 /*0x3d0*/));
    // 0043cb98  8b8424e0000000         -mov eax, dword ptr [esp + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 0043cb9f  8bac24e4000000         -mov ebp, dword ptr [esp + 0xe4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(228) /* 0xe4 */);
    // 0043cba6  e855930300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043cbab  8942ec                 -mov dword ptr [edx - 0x14], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 0043cbae  8b8424e0000000         -mov eax, dword ptr [esp + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 0043cbb5  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 0043cbb7  e8b4920300             -call 0x475e70
    cpu.esp -= 4;
    sub_475e70(app, cpu);
    if (cpu.terminate) return;
L_0x0043cbbc:
    // 0043cbbc  8b9424e4000000         -mov edx, dword ptr [esp + 0xe4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(228) /* 0xe4 */);
    // 0043cbc3  8d34bd00000000         -lea esi, [edi*4]
    cpu.esi = x86::reg32(cpu.edi * 4);
    // 0043cbca  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043cbcc  b800000100             -mov eax, 0x10000
    cpu.eax = 65536 /*0x10000*/;
    // 0043cbd1  8b9ed0030000           -mov ebx, dword ptr [esi + 0x3d0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(976) /* 0x3d0 */);
L_0x0043cbd7:
    // 0043cbd7  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0043cbd8  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043cbda  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043cbdc  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043cbde  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0043cbe2  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043cbe5  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043cbe7  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0043cbea  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0043cbec  8986ec030000           -mov dword ptr [esi + 0x3ec], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1004) /* 0x3ec */) = cpu.eax;
L_0x0043cbf2:
    // 0043cbf2  47                     -inc edi
    (cpu.edi)++;
    // 0043cbf3  83c604                 -add esi, 4
    (cpu.esi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0043cbf6  83ff07                 +cmp edi, 7
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(7 /*0x7*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043cbf9  7d25                   -jge 0x43cc20
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043cc20;
    }
    // 0043cbfb  39ee                   +cmp esi, ebp
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
    // 0043cbfd  74bd                   -je 0x43cbbc
    if (cpu.flags.zf)
    {
        goto L_0x0043cbbc;
    }
    // 0043cbff  8b9ed0030000           -mov ebx, dword ptr [esi + 0x3d0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(976) /* 0x3d0 */);
    // 0043cc05  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043cc07  7508                   -jne 0x43cc11
    if (!cpu.flags.zf)
    {
        goto L_0x0043cc11;
    }
    // 0043cc09  899eec030000           -mov dword ptr [esi + 0x3ec], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1004) /* 0x3ec */) = cpu.ebx;
    // 0043cc0f  ebe1                   -jmp 0x43cbf2
    goto L_0x0043cbf2;
L_0x0043cc11:
    // 0043cc11  8b96cc030000           -mov edx, dword ptr [esi + 0x3cc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(972) /* 0x3cc */);
    // 0043cc17  b800000100             -mov eax, 0x10000
    cpu.eax = 65536 /*0x10000*/;
    // 0043cc1c  29d3                   +sub ebx, edx
    {
        x86::reg32& tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043cc1e  ebb7                   -jmp 0x43cbd7
    goto L_0x0043cbd7;
L_0x0043cc20:
    // 0043cc20  8bb424e4000000         -mov esi, dword ptr [esp + 0xe4]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(228) /* 0xe4 */);
    // 0043cc27  8b0d04225100           -mov ecx, dword ptr [0x512204]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5317124) /* 0x512204 */);
    // 0043cc2d  81c608040000           -add esi, 0x408
    (cpu.esi) += x86::reg32(x86::sreg32(1032 /*0x408*/));
    // 0043cc33  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0043cc35  0f8525010000           -jne 0x43cd60
    if (!cpu.flags.zf)
    {
        goto L_0x0043cd60;
    }
    // 0043cc3b  bbe0000000             -mov ebx, 0xe0
    cpu.ebx = 224 /*0xe0*/;
    // 0043cc40  8b8424e0000000         -mov eax, dword ptr [esp + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 0043cc47  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0043cc49  e822920300             -call 0x475e70
    cpu.esp -= 4;
    sub_475e70(app, cpu);
    if (cpu.terminate) return;
    // 0043cc4e  8b8424e0000000         -mov eax, dword ptr [esp + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 0043cc55  8b9424e4000000         -mov edx, dword ptr [esp + 0xe4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(228) /* 0xe4 */);
    // 0043cc5c  e89f920300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043cc61  898250050000           -mov dword ptr [edx + 0x550], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1360) /* 0x550 */) = cpu.eax;
    // 0043cc67  8b8424e0000000         -mov eax, dword ptr [esp + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 0043cc6e  bbe0000000             -mov ebx, 0xe0
    cpu.ebx = 224 /*0xe0*/;
    // 0043cc73  e888920300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043cc78  898254050000           -mov dword ptr [edx + 0x554], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1364) /* 0x554 */) = cpu.eax;
    // 0043cc7e  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0043cc80  8b8424e0000000         -mov eax, dword ptr [esp + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 0043cc87  e8e4910300             -call 0x475e70
    cpu.esp -= 4;
    sub_475e70(app, cpu);
    if (cpu.terminate) return;
    // 0043cc8c  8b8424e0000000         -mov eax, dword ptr [esp + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 0043cc93  e868920300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043cc98  8b8424e0000000         -mov eax, dword ptr [esp + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 0043cc9f  e85c920300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
L_0x0043cca4:
    // 0043cca4  8b8424e0000000         -mov eax, dword ptr [esp + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 0043ccab  8b9424e4000000         -mov edx, dword ptr [esp + 0xe4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(228) /* 0xe4 */);
    // 0043ccb2  e849920300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043ccb7  8982e8040000           -mov dword ptr [edx + 0x4e8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1256) /* 0x4e8 */) = cpu.eax;
    // 0043ccbd  8b8424e0000000         -mov eax, dword ptr [esp + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 0043ccc4  e837920300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043ccc9  8982f0040000           -mov dword ptr [edx + 0x4f0], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1264) /* 0x4f0 */) = cpu.eax;
    // 0043cccf  8b8424e0000000         -mov eax, dword ptr [esp + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 0043ccd6  e825920300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043ccdb  8982f4040000           -mov dword ptr [edx + 0x4f4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1268) /* 0x4f4 */) = cpu.eax;
    // 0043cce1  8b8424e0000000         -mov eax, dword ptr [esp + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 0043cce8  e813920300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043cced  8b9af0040000           -mov ebx, dword ptr [edx + 0x4f0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1264) /* 0x4f0 */);
    // 0043ccf3  2b9af4040000           -sub ebx, dword ptr [edx + 0x4f4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1268) /* 0x4f4 */)));
    // 0043ccf9  c1e310                 -shl ebx, 0x10
    cpu.ebx <<= 16 /*0x10*/ % 32;
    // 0043ccfc  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0043ccfd  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043ccff  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043cd01  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043cd03  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0043cd07  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043cd0a  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043cd0c  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0043cd0f  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0043cd11  8b9424e4000000         -mov edx, dword ptr [esp + 0xe4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(228) /* 0xe4 */);
    // 0043cd18  8982f8040000           -mov dword ptr [edx + 0x4f8], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1272) /* 0x4f8 */) = cpu.eax;
    // 0043cd1e  8b8424e0000000         -mov eax, dword ptr [esp + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 0043cd25  e8d6910300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043cd2a  898260050000           -mov dword ptr [edx + 0x560], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1376) /* 0x560 */) = cpu.eax;
    // 0043cd30  8b8424e0000000         -mov eax, dword ptr [esp + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 0043cd37  81c208040000           -add edx, 0x408
    (cpu.edx) += x86::reg32(x86::sreg32(1032 /*0x408*/));
    // 0043cd3d  e8be910300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043cd42  89825c010000           -mov dword ptr [edx + 0x15c], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(348) /* 0x15c */) = cpu.eax;
    // 0043cd48  8b8424e4000000         -mov eax, dword ptr [esp + 0xe4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(228) /* 0xe4 */);
    // 0043cd4f  e81c360000             -call 0x440370
    cpu.esp -= 4;
    sub_440370(app, cpu);
    if (cpu.terminate) return;
    // 0043cd54  81c4e8000000           +add esp, 0xe8
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(232 /*0xe8*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043cd5a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cd5b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cd5c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cd5d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cd5e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cd5f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043cd60:
    // 0043cd60  bbe0000000             -mov ebx, 0xe0
    cpu.ebx = 224 /*0xe0*/;
    // 0043cd65  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0043cd67  8b8424e0000000         -mov eax, dword ptr [esp + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 0043cd6e  e8fd900300             -call 0x475e70
    cpu.esp -= 4;
    sub_475e70(app, cpu);
    if (cpu.terminate) return;
    // 0043cd73  8b8424e0000000         -mov eax, dword ptr [esp + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 0043cd7a  bbe0000000             -mov ebx, 0xe0
    cpu.ebx = 224 /*0xe0*/;
    // 0043cd7f  e87c910300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043cd84  8b8424e0000000         -mov eax, dword ptr [esp + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 0043cd8b  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0043cd8d  e86e910300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043cd92  8b8424e0000000         -mov eax, dword ptr [esp + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 0043cd99  e8d2900300             -call 0x475e70
    cpu.esp -= 4;
    sub_475e70(app, cpu);
    if (cpu.terminate) return;
    // 0043cd9e  8b8424e0000000         -mov eax, dword ptr [esp + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 0043cda5  8b9424e4000000         -mov edx, dword ptr [esp + 0xe4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(228) /* 0xe4 */);
    // 0043cdac  e84f910300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043cdb1  898250050000           -mov dword ptr [edx + 0x550], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1360) /* 0x550 */) = cpu.eax;
    // 0043cdb7  8b8424e0000000         -mov eax, dword ptr [esp + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(224) /* 0xe0 */);
    // 0043cdbe  e83d910300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043cdc3  898254050000           -mov dword ptr [edx + 0x554], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1364) /* 0x554 */) = cpu.eax;
    // 0043cdc9  e9d6feffff             -jmp 0x43cca4
    goto L_0x0043cca4;
}

/* align: skip 0x00 0x00 */
void Application::sub_43cdd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043cdd0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043cdd1  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0043cdd4  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0043cdd6  c7802805000000000000   -mov dword ptr [eax + 0x528], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1320) /* 0x528 */) = 0 /*0x0*/;
    // 0043cde0  c7802005000000000000   -mov dword ptr [eax + 0x520], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1312) /* 0x520 */) = 0 /*0x0*/;
    // 0043cdea  c780fc04000000000000   -mov dword ptr [eax + 0x4fc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1276) /* 0x4fc */) = 0 /*0x0*/;
    // 0043cdf4  c7809403000000000000   -mov dword ptr [eax + 0x394], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(916) /* 0x394 */) = 0 /*0x0*/;
    // 0043cdfe  c7809803000000000000   -mov dword ptr [eax + 0x398], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(920) /* 0x398 */) = 0 /*0x0*/;
    // 0043ce08  c7809c03000000000000   -mov dword ptr [eax + 0x39c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(924) /* 0x39c */) = 0 /*0x0*/;
    // 0043ce12  c780a003000000000000   -mov dword ptr [eax + 0x3a0], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(928) /* 0x3a0 */) = 0 /*0x0*/;
    // 0043ce1c  c780a403000000000000   -mov dword ptr [eax + 0x3a4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(932) /* 0x3a4 */) = 0 /*0x0*/;
    // 0043ce26  c780ac03000000000000   -mov dword ptr [eax + 0x3ac], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(940) /* 0x3ac */) = 0 /*0x0*/;
    // 0043ce30  c780a803000000000000   -mov dword ptr [eax + 0x3a8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(936) /* 0x3a8 */) = 0 /*0x0*/;
    // 0043ce3a  c7801402000000000000   -mov dword ptr [eax + 0x214], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(532) /* 0x214 */) = 0 /*0x0*/;
    // 0043ce44  c780b803000000000000   -mov dword ptr [eax + 0x3b8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(952) /* 0x3b8 */) = 0 /*0x0*/;
    // 0043ce4e  c780c003000000000000   -mov dword ptr [eax + 0x3c0], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(960) /* 0x3c0 */) = 0 /*0x0*/;
    // 0043ce58  c780c403000000000000   -mov dword ptr [eax + 0x3c4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(964) /* 0x3c4 */) = 0 /*0x0*/;
    // 0043ce62  c780c803000000000000   -mov dword ptr [eax + 0x3c8], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(968) /* 0x3c8 */) = 0 /*0x0*/;
    // 0043ce6c  c780cc03000000000000   -mov dword ptr [eax + 0x3cc], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(972) /* 0x3cc */) = 0 /*0x0*/;
    // 0043ce76  c780ec04000000000000   -mov dword ptr [eax + 0x4ec], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1260) /* 0x4ec */) = 0 /*0x0*/;
    // 0043ce80  c7804c05000000000000   -mov dword ptr [eax + 0x54c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1356) /* 0x54c */) = 0 /*0x0*/;
    // 0043ce8a  c7804805000000000000   -mov dword ptr [eax + 0x548], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1352) /* 0x548 */) = 0 /*0x0*/;
    // 0043ce94  c7803c05000000000000   -mov dword ptr [eax + 0x53c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1340) /* 0x53c */) = 0 /*0x0*/;
    // 0043ce9e  c7804005000000000000   -mov dword ptr [eax + 0x540], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1344) /* 0x540 */) = 0 /*0x0*/;
    // 0043cea8  c7804405000000000000   -mov dword ptr [eax + 0x544], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1348) /* 0x544 */) = 0 /*0x0*/;
    // 0043ceb2  c7802405000001000000   -mov dword ptr [eax + 0x524], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1316) /* 0x524 */) = 1 /*0x1*/;
    // 0043cebc  8980b0030000           -mov dword ptr [eax + 0x3b0], eax
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(944) /* 0x3b0 */) = cpu.eax;
    // 0043cec2  f680f401000010         +test byte ptr [eax + 0x1f4], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(500) /* 0x1f4 */) & 16 /*0x10*/));
    // 0043cec9  750e                   -jne 0x43ced9
    if (!cpu.flags.zf)
    {
        goto L_0x0043ced9;
    }
    // 0043cecb  f685f401000020         +test byte ptr [ebp + 0x1f4], 0x20
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(500) /* 0x1f4 */) & 32 /*0x20*/));
    // 0043ced2  7505                   -jne 0x43ced9
    if (!cpu.flags.zf)
    {
        goto L_0x0043ced9;
    }
    // 0043ced4  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0043ced7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ced8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043ced9:
    // 0043ced9  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043ceda  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043cedb  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043cedc  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043cedd  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043cede  8d7c2414               -lea edi, [esp + 0x14]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0043cee2  8d5c2414               -lea ebx, [esp + 0x14]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0043cee6  be90834300             -mov esi, 0x438390
    cpu.esi = 4424592 /*0x438390*/;
    // 0043ceeb  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0043ceed  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043ceef  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043cef0  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043cef1  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043cef2  e8d9f5ffff             -call 0x43c4d0
    cpu.esp -= 4;
    sub_43c4d0(app, cpu);
    if (cpu.terminate) return;
    // 0043cef7  8b0d28225100           -mov ecx, dword ptr [0x512228]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */);
    // 0043cefd  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0043ceff  e8ac550200             -call 0x4624b0
    cpu.esp -= 4;
    sub_4624b0(app, cpu);
    if (cpu.terminate) return;
    // 0043cf04  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cf05  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cf06  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cf07  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cf08  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cf09  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0043cf0c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cf0d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_43cf10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043cf10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043cf11  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043cf12  81ecfc000000           -sub esp, 0xfc
    (cpu.esp) -= x86::reg32(x86::sreg32(252 /*0xfc*/));
    // 0043cf18  68ccb84c00             -push 0x4cb8cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5028044 /*0x4cb8cc*/;
    cpu.esp -= 4;
    // 0043cf1d  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0043cf21  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043cf22  8d542408               -lea edx, [esp + 8]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0043cf26  e8d6950400             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 0043cf2b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0043cf2e  a1f05e4d00             -mov eax, dword ptr [0x4d5ef0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5070576) /* 0x4d5ef0 */);
    // 0043cf33  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0043cf38  e83f070600             -call 0x49d67c
    cpu.esp -= 4;
    sub_49d67c(app, cpu);
    if (cpu.terminate) return;
    // 0043cf3d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043cf3f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043cf41  e83a900300             -call 0x475f80
    cpu.esp -= 4;
    sub_475f80(app, cpu);
    if (cpu.terminate) return;
    // 0043cf46  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043cf48  e823000000             -call 0x43cf70
    cpu.esp -= 4;
    sub_43cf70(app, cpu);
    if (cpu.terminate) return;
    // 0043cf4d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043cf4f  e8bc010000             -call 0x43d110
    cpu.esp -= 4;
    sub_43d110(app, cpu);
    if (cpu.terminate) return;
    // 0043cf54  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043cf56  e895000000             -call 0x43cff0
    cpu.esp -= 4;
    sub_43cff0(app, cpu);
    if (cpu.terminate) return;
    // 0043cf5b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043cf5d  e8ee8f0300             -call 0x475f50
    cpu.esp -= 4;
    sub_475f50(app, cpu);
    if (cpu.terminate) return;
    // 0043cf62  81c4fc000000           -add esp, 0xfc
    (cpu.esp) += x86::reg32(x86::sreg32(252 /*0xfc*/));
    // 0043cf68  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cf69  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cf6a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43cf70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043cf70  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043cf71  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043cf72  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043cf74  e8878f0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043cf79  a358ab5000             -mov dword ptr [0x50ab58], eax
    app->getMemory<x86::reg32>(x86::reg32(5286744) /* 0x50ab58 */) = cpu.eax;
    // 0043cf7e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043cf80  e87b8f0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043cf85  a35cab5000             -mov dword ptr [0x50ab5c], eax
    app->getMemory<x86::reg32>(x86::reg32(5286748) /* 0x50ab5c */) = cpu.eax;
    // 0043cf8a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043cf8c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043cf8e  e86d8f0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043cf93  a360ab5000             -mov dword ptr [0x50ab60], eax
    app->getMemory<x86::reg32>(x86::reg32(5286752) /* 0x50ab60 */) = cpu.eax;
L_0x0043cf98:
    // 0043cf98  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043cf9a  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0043cf9d  e85e8f0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043cfa2  898260ab5000           -mov dword ptr [edx + 0x50ab60], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5286752) /* 0x50ab60 */) = cpu.eax;
    // 0043cfa8  83fa10                 +cmp edx, 0x10
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
    // 0043cfab  75eb                   -jne 0x43cf98
    if (!cpu.flags.zf)
    {
        goto L_0x0043cf98;
    }
    // 0043cfad  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043cfaf  ba1c470000             -mov edx, 0x471c
    cpu.edx = 18204 /*0x471c*/;
    // 0043cfb4  e8478f0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043cfb9  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043cfbb  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043cfbe  c1e810                 +shr eax, 0x10
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
    // 0043cfc1  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043cfc3  a374ab5000             -mov dword ptr [0x50ab74], eax
    app->getMemory<x86::reg32>(x86::reg32(5286772) /* 0x50ab74 */) = cpu.eax;
    // 0043cfc8  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043cfca:
    // 0043cfca  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043cfcc  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0043cfcf  e82c8f0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043cfd4  898274ab5000           -mov dword ptr [edx + 0x50ab74], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5286772) /* 0x50ab74 */) = cpu.eax;
    // 0043cfda  83fa10                 +cmp edx, 0x10
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
    // 0043cfdd  75eb                   -jne 0x43cfca
    if (!cpu.flags.zf)
    {
        goto L_0x0043cfca;
    }
    // 0043cfdf  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cfe0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043cfe1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43cff0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043cff0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043cff1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043cff2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043cff3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043cff4  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043cff6  e8058f0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043cffb  a398ac5000             -mov dword ptr [0x50ac98], eax
    app->getMemory<x86::reg32>(x86::reg32(5287064) /* 0x50ac98 */) = cpu.eax;
    // 0043d000  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043d002  e8f98e0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043d007  8b0d04225100           -mov ecx, dword ptr [0x512204]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5317124) /* 0x512204 */);
    // 0043d00d  a39cac5000             -mov dword ptr [0x50ac9c], eax
    app->getMemory<x86::reg32>(x86::reg32(5287068) /* 0x50ac9c */) = cpu.eax;
    // 0043d012  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0043d014  0f84b9000000           -je 0x43d0d3
    if (cpu.flags.zf)
    {
        goto L_0x0043d0d3;
    }
    // 0043d01a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043d01c  e8df8e0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043d021  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043d023  e8d88e0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043d028  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043d02a  e8d18e0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043d02f  a3a0ac5000             -mov dword ptr [0x50aca0], eax
    app->getMemory<x86::reg32>(x86::reg32(5287072) /* 0x50aca0 */) = cpu.eax;
    // 0043d034  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043d036  e8c58e0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043d03b  a3a4ac5000             -mov dword ptr [0x50aca4], eax
    app->getMemory<x86::reg32>(x86::reg32(5287076) /* 0x50aca4 */) = cpu.eax;
L_0x0043d040:
    // 0043d040  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043d042  e8b98e0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043d047  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043d049  a3a8ac5000             -mov dword ptr [0x50aca8], eax
    app->getMemory<x86::reg32>(x86::reg32(5287080) /* 0x50aca8 */) = cpu.eax;
    // 0043d04e  bdd8ac5000             -mov ebp, 0x50acd8
    cpu.ebp = 5287128 /*0x50acd8*/;
L_0x0043d053:
    // 0043d053  b9acac5000             -mov ecx, 0x50acac
    cpu.ecx = 5287084 /*0x50acac*/;
L_0x0043d058:
    // 0043d058  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043d05a  e8a18e0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043d05f  8901                   -mov dword ptr [ecx], eax
    app->getMemory<x86::reg32>(cpu.ecx) = cpu.eax;
    // 0043d061  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043d063  e8988e0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043d068  894104                 -mov dword ptr [ecx + 4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0043d06b  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043d06d  e88e8e0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043d072  894108                 -mov dword ptr [ecx + 8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0043d075  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043d077  e8848e0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043d07c  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0043d07f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043d081  e87a8e0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043d086  894110                 -mov dword ptr [ecx + 0x10], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0043d089  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043d08b  e8708e0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043d090  894114                 -mov dword ptr [ecx + 0x14], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0043d093  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043d095  e8668e0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043d09a  894118                 -mov dword ptr [ecx + 0x18], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0043d09d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043d09f  e85c8e0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043d0a4  89411c                 -mov dword ptr [ecx + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0043d0a7  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043d0a9  e8528e0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043d0ae  894120                 -mov dword ptr [ecx + 0x20], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0043d0b1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043d0b3  e8488e0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043d0b8  894124                 -mov dword ptr [ecx + 0x24], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0043d0bb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043d0bd  43                     -inc ebx
    (cpu.ebx)++;
    // 0043d0be  e83d8e0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043d0c3  894128                 -mov dword ptr [ecx + 0x28], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0043d0c6  83fb02                 +cmp ebx, 2
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
    // 0043d0c9  7d33                   -jge 0x43d0fe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043d0fe;
    }
    // 0043d0cb  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043d0cd  7484                   -je 0x43d053
    if (cpu.flags.zf)
    {
        goto L_0x0043d053;
    }
    // 0043d0cf  89e9                   -mov ecx, ebp
    cpu.ecx = cpu.ebp;
    // 0043d0d1  eb85                   -jmp 0x43d058
    goto L_0x0043d058;
L_0x0043d0d3:
    // 0043d0d3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043d0d5  e8268e0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043d0da  a3a0ac5000             -mov dword ptr [0x50aca0], eax
    app->getMemory<x86::reg32>(x86::reg32(5287072) /* 0x50aca0 */) = cpu.eax;
    // 0043d0df  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043d0e1  e81a8e0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043d0e6  a3a4ac5000             -mov dword ptr [0x50aca4], eax
    app->getMemory<x86::reg32>(x86::reg32(5287076) /* 0x50aca4 */) = cpu.eax;
    // 0043d0eb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043d0ed  e80e8e0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043d0f2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043d0f4  e8078e0300             -call 0x475f00
    cpu.esp -= 4;
    sub_475f00(app, cpu);
    if (cpu.terminate) return;
    // 0043d0f9  e942ffffff             -jmp 0x43d040
    goto L_0x0043d040;
L_0x0043d0fe:
    // 0043d0fe  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d0ff  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d100  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d101  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d102  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43d110(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d110  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043d111  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043d112  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043d113  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043d114  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043d115  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043d116  81ec2c010000           -sub esp, 0x12c
    (cpu.esp) -= x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 0043d11c  bb20010000             -mov ebx, 0x120
    cpu.ebx = 288 /*0x120*/;
    // 0043d121  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0043d123  e8488d0300             -call 0x475e70
    cpu.esp -= 4;
    sub_475e70(app, cpu);
    if (cpu.terminate) return;
    // 0043d128  8b15fc215100           -mov edx, dword ptr [0x5121fc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317116) /* 0x5121fc */);
    // 0043d12e  83fa02                 +cmp edx, 2
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
    // 0043d131  0f856a010000           -jne 0x43d2a1
    if (!cpu.flags.zf)
    {
        goto L_0x0043d2a1;
    }
    // 0043d137  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0043d139:
    // 0043d139  8b15f8215100           -mov edx, dword ptr [0x5121f8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317112) /* 0x5121f8 */);
    // 0043d13f  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0043d146  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043d148  89e6                   -mov esi, esp
    cpu.esi = cpu.esp;
    // 0043d14a  c1e005                 -shl eax, 5
    cpu.eax <<= 5 /*0x5*/ % 32;
    // 0043d14d  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 0043d150  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043d152  8d3c1e                 -lea edi, [esi + ebx]
    cpu.edi = x86::reg32(cpu.esi + cpu.ebx * 1);
    // 0043d155  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043d157  89b42428010000         -mov dword ptr [esp + 0x128], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */) = cpu.esi;
L_0x0043d15e:
    // 0043d15e  833d301e510001         +cmp dword ptr [0x511e30], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5316144) /* 0x511e30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d165  0f8e4f010000           -jle 0x43d2ba
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043d2ba;
    }
    // 0043d16b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0043d170:
    // 0043d170  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0043d173  8d1406                 -lea edx, [esi + eax]
    cpu.edx = x86::reg32(cpu.esi + cpu.eax * 1);
    // 0043d176  8b2d481e5100           -mov ebp, dword ptr [0x511e48]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5316168) /* 0x511e48 */);
    // 0043d17c  8b548a50               -mov edx, dword ptr [edx + ecx*4 + 0x50]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(80) /* 0x50 */ + cpu.ecx * 4);
    // 0043d180  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0043d182  0f8439010000           -je 0x43d2c1
    if (cpu.flags.zf)
    {
        goto L_0x0043d2c1;
    }
    // 0043d188  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0043d18d:
    // 0043d18d  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0043d190  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 0043d197  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0043d199  8b440340               -mov eax, dword ptr [ebx + eax + 0x40]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(64) /* 0x40 */ + cpu.eax * 1);
    // 0043d19d  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043d19f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043d1a2  c1e810                 +shr eax, 0x10
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
    // 0043d1a5  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043d1a7  8b1500225100           -mov edx, dword ptr [0x512200]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317120) /* 0x512200 */);
    // 0043d1ad  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0043d1b0  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0043d1b2  8b6c1a30               -mov ebp, dword ptr [edx + ebx + 0x30]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */ + cpu.ebx * 1);
    // 0043d1b6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043d1b8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0043d1ba  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043d1bc  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043d1bf  c1e810                 +shr eax, 0x10
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
    // 0043d1c2  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043d1c4  8b1504225100           -mov edx, dword ptr [0x512204]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317124) /* 0x512204 */);
    // 0043d1ca  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0043d1cd  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0043d1cf  8d2c1a                 -lea ebp, [edx + ebx]
    cpu.ebp = x86::reg32(cpu.edx + cpu.ebx * 1);
    // 0043d1d2  8b6d20                 -mov ebp, dword ptr [ebp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(32) /* 0x20 */);
    // 0043d1d5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043d1d7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0043d1d9  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043d1db  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043d1de  c1e810                 +shr eax, 0x10
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
    // 0043d1e1  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043d1e3  8b6f08                 -mov ebp, dword ptr [edi + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 0043d1e6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043d1e8  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0043d1ea  8bac2428010000         -mov ebp, dword ptr [esp + 0x128]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 0043d1f1  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043d1f3  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043d1f6  c1e810                 +shr eax, 0x10
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
    // 0043d1f9  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043d1fb  8b6d00                 -mov ebp, dword ptr [ebp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp);
    // 0043d1fe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043d200  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0043d202  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043d204  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043d207  c1e810                 +shr eax, 0x10
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
    // 0043d20a  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043d20c  89841c20010000         -mov dword ptr [esp + ebx + 0x120], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */ + cpu.ebx * 1) = cpu.eax;
    // 0043d213  8b842428010000         -mov eax, dword ptr [esp + 0x128]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */);
    // 0043d21a  83c704                 -add edi, 4
    (cpu.edi) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0043d21d  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0043d220  41                     -inc ecx
    (cpu.ecx)++;
    // 0043d221  89842428010000         -mov dword ptr [esp + 0x128], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(296) /* 0x128 */) = cpu.eax;
    // 0043d228  83f902                 +cmp ecx, 2
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
    // 0043d22b  0f8c2dffffff           -jl 0x43d15e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043d15e;
    }
    // 0043d231  8b842420010000         -mov eax, dword ptr [esp + 0x120]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 0043d238  a380ac5000             -mov dword ptr [0x50ac80], eax
    app->getMemory<x86::reg32>(x86::reg32(5287040) /* 0x50ac80 */) = cpu.eax;
    // 0043d23d  8b842424010000         -mov eax, dword ptr [esp + 0x124]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(292) /* 0x124 */);
    // 0043d244  8b9c2420010000         -mov ebx, dword ptr [esp + 0x120]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(288) /* 0x120 */);
    // 0043d24b  a388ac5000             -mov dword ptr [0x50ac88], eax
    app->getMemory<x86::reg32>(x86::reg32(5287048) /* 0x50ac88 */) = cpu.eax;
    // 0043d250  b800000100             -mov eax, 0x10000
    cpu.eax = 65536 /*0x10000*/;
    // 0043d255  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0043d256  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043d258  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043d25a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043d25c  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0043d260  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043d263  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043d265  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0043d268  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0043d26a  8b1d88ac5000           -mov ebx, dword ptr [0x50ac88]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5287048) /* 0x50ac88 */);
    // 0043d270  a374ac5000             -mov dword ptr [0x50ac74], eax
    app->getMemory<x86::reg32>(x86::reg32(5287028) /* 0x50ac74 */) = cpu.eax;
    // 0043d275  b800000100             -mov eax, 0x10000
    cpu.eax = 65536 /*0x10000*/;
    // 0043d27a  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 0043d27b  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043d27d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043d27f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043d281  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0043d285  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 0043d288  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0043d28a  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 0043d28d  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0043d28f  a37cac5000             -mov dword ptr [0x50ac7c], eax
    app->getMemory<x86::reg32>(x86::reg32(5287036) /* 0x50ac7c */) = cpu.eax;
    // 0043d294  81c42c010000           -add esp, 0x12c
    (cpu.esp) += x86::reg32(x86::sreg32(300 /*0x12c*/));
    // 0043d29a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d29b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d29c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d29d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d29e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d29f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d2a0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043d2a1:
    // 0043d2a1  83fa04                 +cmp edx, 4
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
    // 0043d2a4  750a                   -jne 0x43d2b0
    if (!cpu.flags.zf)
    {
        goto L_0x0043d2b0;
    }
    // 0043d2a6  bb01000000             -mov ebx, 1
    cpu.ebx = 1 /*0x1*/;
    // 0043d2ab  e989feffff             -jmp 0x43d139
    goto L_0x0043d139;
L_0x0043d2b0:
    // 0043d2b0  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 0043d2b5  e97ffeffff             -jmp 0x43d139
    goto L_0x0043d139;
L_0x0043d2ba:
    // 0043d2ba  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043d2bc  e9affeffff             -jmp 0x43d170
    goto L_0x0043d170;
L_0x0043d2c1:
    // 0043d2c1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043d2c3  e9c5feffff             -jmp 0x43d18d
    goto L_0x0043d18d;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43d2d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d2d0  a1f8215100             -mov eax, dword ptr [0x5121f8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5317112) /* 0x5121f8 */);
    // 0043d2d5  83f801                 +cmp eax, 1
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
    // 0043d2d8  7313                   -jae 0x43d2ed
    if (!cpu.flags.cf)
    {
        goto L_0x0043d2ed;
    }
    // 0043d2da  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043d2dc  7514                   -jne 0x43d2f2
    if (!cpu.flags.zf)
    {
        goto L_0x0043d2f2;
    }
    // 0043d2de  833d301e510001         +cmp dword ptr [0x511e30], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5316144) /* 0x511e30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d2e5  7f11                   -jg 0x43d2f8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0043d2f8;
    }
    // 0043d2e7  b002                   -mov al, 2
    cpu.al = 2 /*0x2*/;
    // 0043d2e9  0fbec0                 -movsx eax, al
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 0043d2ec  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043d2ed:
    // 0043d2ed  760f                   -jbe 0x43d2fe
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0043d2fe;
    }
    // 0043d2ef  83f802                 -cmp eax, 2
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
L_0x0043d2f2:
    // 0043d2f2  30c0                   -xor al, al
    cpu.al ^= x86::reg8(x86::sreg8(cpu.al));
    // 0043d2f4  0fbec0                 -movsx eax, al
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 0043d2f7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043d2f8:
    // 0043d2f8  b003                   -mov al, 3
    cpu.al = 3 /*0x3*/;
    // 0043d2fa  0fbec0                 -movsx eax, al
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 0043d2fd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043d2fe:
    // 0043d2fe  b001                   -mov al, 1
    cpu.al = 1 /*0x1*/;
    // 0043d300  0fbec0                 -movsx eax, al
    cpu.eax = x86::reg32(static_cast<x86::sreg8>(cpu.al));
    // 0043d303  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43d310(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d310  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043d311  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043d312  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0043d314  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043d316  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0043d319  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043d31b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0043d31e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043d320  7c5d                   -jl 0x43d37f
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043d37f;
    }
    // 0043d322  8b15a4185100           -mov edx, dword ptr [0x5118a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5314724) /* 0x5118a4 */);
    // 0043d328  b907000000             -mov ecx, 7
    cpu.ecx = 7 /*0x7*/;
    // 0043d32d  8a540221               -mov dl, byte ptr [edx + eax + 0x21]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(33) /* 0x21 */ + cpu.eax * 1);
    // 0043d331  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
L_0x0043d337:
    // 0043d337  c1e20f                 -shl edx, 0xf
    cpu.edx <<= 15 /*0xf*/ % 32;
    // 0043d33a  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0043d33d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043d33f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043d342  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0043d345  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043d347  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043d34a  8b148518aa5000         -mov edx, dword ptr [eax*4 + 0x50aa18]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5286424) /* 0x50aa18 */ + cpu.eax * 4);
    // 0043d351  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043d353  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043d355  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043d358  c1e810                 +shr eax, 0x10
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
    // 0043d35b  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043d35d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043d35f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043d362  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0043d365  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043d367  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043d36a  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043d36c  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0043d36e  7c23                   -jl 0x43d393
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043d393;
    }
    // 0043d370  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043d372  83f80d                 +cmp eax, 0xd
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
    // 0043d375  7e05                   -jle 0x43d37c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043d37c;
    }
    // 0043d377  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
L_0x0043d37c:
    // 0043d37c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d37d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d37e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043d37f:
    // 0043d37f  8b15a4185100           -mov edx, dword ptr [0x5118a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5314724) /* 0x5118a4 */);
    // 0043d385  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043d387  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0043d389  8a5020                 -mov dl, byte ptr [eax + 0x20]
    cpu.dl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(32) /* 0x20 */);
    // 0043d38c  b906000000             -mov ecx, 6
    cpu.ecx = 6 /*0x6*/;
    // 0043d391  eba4                   -jmp 0x43d337
    goto L_0x0043d337;
L_0x0043d393:
    // 0043d393  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043d395  83f80d                 +cmp eax, 0xd
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
    // 0043d398  7ee2                   -jle 0x43d37c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043d37c;
    }
    // 0043d39a  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 0043d39f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d3a0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d3a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43d3b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d3b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043d3b1  b907000000             -mov ecx, 7
    cpu.ecx = 7 /*0x7*/;
    // 0043d3b6  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043d3b8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043d3ba  b908000000             -mov ecx, 8
    cpu.ecx = 8 /*0x8*/;
    // 0043d3bf  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043d3c1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043d3c3  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0043d3c5  7c1a                   -jl 0x43d3e1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043d3e1;
    }
    // 0043d3c7  83f910                 +cmp ecx, 0x10
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
    // 0043d3ca  7c05                   -jl 0x43d3d1
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043d3d1;
    }
    // 0043d3cc  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
L_0x0043d3d1:
    // 0043d3d1  b90f000000             -mov ecx, 0xf
    cpu.ecx = 15 /*0xf*/;
    // 0043d3d6  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043d3d8  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043d3dd  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0043d3df  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d3e0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043d3e1:
    // 0043d3e1  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043d3e3  b90f000000             -mov ecx, 0xf
    cpu.ecx = 15 /*0xf*/;
    // 0043d3e8  29c1                   -sub ecx, eax
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043d3ea  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043d3ef  d3e0                   -shl eax, cl
    cpu.eax <<= cpu.cl % 32;
    // 0043d3f1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d3f2  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43d400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d400  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043d401  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043d402  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043d403  8b0da0185100           -mov ecx, dword ptr [0x5118a0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5314720) /* 0x5118a0 */);
    // 0043d409  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043d40b  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0043d40d  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0043d40f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043d411  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043d414  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043d416  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0043d418  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043d41a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043d41c  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043d41e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043d420  7e04                   -jle 0x43d426
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043d426;
    }
    // 0043d422  39d0                   +cmp eax, edx
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
    // 0043d424  7f0e                   -jg 0x43d434
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0043d434;
    }
L_0x0043d426:
    // 0043d426  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043d428  7c0e                   -jl 0x43d438
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043d438;
    }
L_0x0043d42a:
    // 0043d42a  890da0185100           -mov dword ptr [0x5118a0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5314720) /* 0x5118a0 */) = cpu.ecx;
    // 0043d430  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d431  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d432  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d433  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043d434:
    // 0043d434  29c8                   +sub eax, ecx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.ecx));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043d436  ebf2                   -jmp 0x43d42a
    goto L_0x0043d42a;
L_0x0043d438:
    // 0043d438  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0043d43a  39d0                   +cmp eax, edx
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
    // 0043d43c  7dec                   -jge 0x43d42a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043d42a;
    }
    // 0043d43e  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0043d440  890da0185100           -mov dword ptr [0x5118a0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5314720) /* 0x5118a0 */) = cpu.ecx;
    // 0043d446  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d447  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d448  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d449  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43d450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d450  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043d451  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043d452  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043d453  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043d454  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0043d457  8b8a9c000000           -mov ecx, dword ptr [edx + 0x9c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(156) /* 0x9c */);
    // 0043d45d  8b989c000000           -mov ebx, dword ptr [eax + 0x9c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(156) /* 0x9c */);
    // 0043d463  8bb0a0000000           -mov esi, dword ptr [eax + 0xa0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */);
    // 0043d469  29d9                   -sub ecx, ebx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043d46b  8bb8a4000000           -mov edi, dword ptr [eax + 0xa4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
    // 0043d471  890c24                 -mov dword ptr [esp], ecx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ecx;
    // 0043d474  8b8aa0000000           -mov ecx, dword ptr [edx + 0xa0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(160) /* 0xa0 */);
    // 0043d47a  8b92a4000000           -mov edx, dword ptr [edx + 0xa4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(164) /* 0xa4 */);
    // 0043d480  29f1                   -sub ecx, esi
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0043d482  8db030010000           -lea esi, [eax + 0x130]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(304) /* 0x130 */);
    // 0043d488  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0043d48a  8d7c240c               -lea edi, [esp + 0xc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0043d48e  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0043d491  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043d492  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043d493  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043d494  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 0043d498  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0043d49c  894c2404               -mov dword ptr [esp + 4], ecx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ecx;
    // 0043d4a0  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043d4a2  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043d4a5  c1e810                 +shr eax, 0x10
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
    // 0043d4a8  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043d4aa  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0043d4ae  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043d4b0  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0043d4b4  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043d4b6  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043d4b9  c1e810                 +shr eax, 0x10
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
    // 0043d4bc  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043d4be  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0043d4c0  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0043d4c3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d4c4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d4c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d4c6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d4c7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43d4d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d4d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043d4d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043d4d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043d4d3  8b0d806a4d00           -mov ecx, dword ptr [0x4d6a80]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5073536) /* 0x4d6a80 */);
    // 0043d4d9  8b1d786a4d00           -mov ebx, dword ptr [0x4d6a78]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5073528) /* 0x4d6a78 */);
    // 0043d4df  0fafd9                 -imul ebx, ecx
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0043d4e2  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0043d4e4  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0043d4ea  8915786a4d00           -mov dword ptr [0x4d6a78], edx
    app->getMemory<x86::reg32>(x86::reg32(5073528) /* 0x4d6a78 */) = cpu.edx;
    // 0043d4f0  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0043d4f2  81e200ffff00           -and edx, 0xffff00
    cpu.edx &= x86::reg32(x86::sreg32(16776960 /*0xffff00*/));
    // 0043d4f8  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 0043d4fb  83e203                 -and edx, 3
    cpu.edx &= x86::reg32(x86::sreg32(3 /*0x3*/));
    // 0043d4fe  8a88f4010000           -mov cl, byte ptr [eax + 0x1f4]
    cpu.cl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(500) /* 0x1f4 */);
    // 0043d504  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0043d507  f6c108                 +test cl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.cl & 8 /*0x8*/));
    // 0043d50a  7424                   -je 0x43d530
    if (cpu.flags.zf)
    {
        goto L_0x0043d530;
    }
    // 0043d50c  8b88e8010000           -mov ecx, dword ptr [eax + 0x1e8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(488) /* 0x1e8 */);
    // 0043d512  8b0c8dd8a95000         -mov ecx, dword ptr [ecx*4 + 0x50a9d8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5286360) /* 0x50a9d8 */ + cpu.ecx * 4);
    // 0043d519  8b9411c8000000         -mov edx, dword ptr [ecx + edx + 0xc8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(200) /* 0xc8 */ + cpu.edx * 1);
    // 0043d520  8990a4030000           -mov dword ptr [eax + 0x3a4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(932) /* 0x3a4 */) = cpu.edx;
    // 0043d526  891d7c6a4d00           -mov dword ptr [0x4d6a7c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5073532) /* 0x4d6a7c */) = cpu.ebx;
    // 0043d52c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d52d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d52e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d52f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043d530:
    // 0043d530  8b9278ab5000           -mov edx, dword ptr [edx + 0x50ab78]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5286776) /* 0x50ab78 */);
    // 0043d536  8990a4030000           -mov dword ptr [eax + 0x3a4], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(932) /* 0x3a4 */) = cpu.edx;
    // 0043d53c  891d7c6a4d00           -mov dword ptr [0x4d6a7c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5073532) /* 0x4d6a7c */) = cpu.ebx;
    // 0043d542  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d543  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d544  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d545  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43d550(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d550  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043d551  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043d552  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043d553  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043d554  833d2822510000         +cmp dword ptr [0x512228], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d55b  0f84d4000000           -je 0x43d635
    if (cpu.flags.zf)
    {
        goto L_0x0043d635;
    }
    // 0043d561  8b90e8010000           -mov edx, dword ptr [eax + 0x1e8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(488) /* 0x1e8 */);
    // 0043d567  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043d569  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0043d56b  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 0043d56d  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0043d56f  0f8ca6000000           -jl 0x43d61b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043d61b;
    }
    // 0043d575  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0043d578  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043d57a  8b1da0185100           -mov ebx, dword ptr [0x5118a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5314720) /* 0x5118a0 */);
    // 0043d580  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0043d582  39d9                   +cmp ecx, ebx
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
    // 0043d584  7c02                   -jl 0x43d588
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043d588;
    }
    // 0043d586  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0043d588:
    // 0043d588  8a98f4010000           -mov bl, byte ptr [eax + 0x1f4]
    cpu.bl = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(500) /* 0x1f4 */);
    // 0043d58e  f6c304                 +test bl, 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 4 /*0x4*/));
    // 0043d591  0f857f000000           -jne 0x43d616
    if (!cpu.flags.zf)
    {
        goto L_0x0043d616;
    }
    // 0043d597  f6c308                 +test bl, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.bl & 8 /*0x8*/));
    // 0043d59a  740c                   -je 0x43d5a8
    if (cpu.flags.zf)
    {
        goto L_0x0043d5a8;
    }
    // 0043d59c  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0043d59e  c1f904                 -sar ecx, 4
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (4 /*0x4*/ % 32));
    // 0043d5a1  c1e104                 -shl ecx, 4
    cpu.ecx <<= 4 /*0x4*/ % 32;
    // 0043d5a4  39d1                   +cmp ecx, edx
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
    // 0043d5a6  756e                   -jne 0x43d616
    if (!cpu.flags.zf)
    {
        goto L_0x0043d616;
    }
L_0x0043d5a8:
    // 0043d5a8  f680f401000010         +test byte ptr [eax + 0x1f4], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(500) /* 0x1f4 */) & 16 /*0x10*/));
    // 0043d5af  740a                   -je 0x43d5bb
    if (cpu.flags.zf)
    {
        goto L_0x0043d5bb;
    }
    // 0043d5b1  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 0043d5b3  d1f9                   -sar ecx, 1
    cpu.ecx = x86::reg32(x86::sreg32(cpu.ecx) >> (1 /*0x1*/ % 32));
    // 0043d5b5  01c9                   -add ecx, ecx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0043d5b7  39d1                   +cmp ecx, edx
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
    // 0043d5b9  755b                   -jne 0x43d616
    if (!cpu.flags.zf)
    {
        goto L_0x0043d616;
    }
L_0x0043d5bb:
    // 0043d5bb  f680f401000008         +test byte ptr [eax + 0x1f4], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(500) /* 0x1f4 */) & 8 /*0x8*/));
    // 0043d5c2  0f84a7000000           -je 0x43d66f
    if (cpu.flags.zf)
    {
        goto L_0x0043d66f;
    }
    // 0043d5c8  8b90e8010000           -mov edx, dword ptr [eax + 0x1e8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(488) /* 0x1e8 */);
    // 0043d5ce  8b0c95d8a95000         -mov ecx, dword ptr [edx*4 + 0x50a9d8]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5286360) /* 0x50a9d8 */ + cpu.edx * 4);
    // 0043d5d5  8b89d8000000           -mov ecx, dword ptr [ecx + 0xd8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
L_0x0043d5db:
    // 0043d5db  8b3d806a4d00           -mov edi, dword ptr [0x4d6a80]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5073536) /* 0x4d6a80 */);
    // 0043d5e1  8b15786a4d00           -mov edx, dword ptr [0x4d6a78]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5073528) /* 0x4d6a78 */);
    // 0043d5e7  0fafd7                 -imul edx, edi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.edi)));
    // 0043d5ea  89157c6a4d00           -mov dword ptr [0x4d6a7c], edx
    app->getMemory<x86::reg32>(x86::reg32(5073532) /* 0x4d6a7c */) = cpu.edx;
    // 0043d5f0  81e2ffff0000           -and edx, 0xffff
    cpu.edx &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0043d5f6  8915786a4d00           -mov dword ptr [0x4d6a78], edx
    app->getMemory<x86::reg32>(x86::reg32(5073528) /* 0x4d6a78 */) = cpu.edx;
    // 0043d5fc  8b157c6a4d00           -mov edx, dword ptr [0x4d6a7c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5073532) /* 0x4d6a7c */);
    // 0043d602  81e200ffff00           -and edx, 0xffff00
    cpu.edx &= x86::reg32(x86::sreg32(16776960 /*0xffff00*/));
    // 0043d608  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 0043d60b  0fafd1                 -imul edx, ecx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ecx)));
    // 0043d60e  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0043d611  83fa01                 +cmp edx, 1
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
    // 0043d614  7464                   -je 0x43d67a
    if (cpu.flags.zf)
    {
        goto L_0x0043d67a;
    }
L_0x0043d616:
    // 0043d616  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d617  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d618  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d619  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d61a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043d61b:
    // 0043d61b  8b4814                 -mov ecx, dword ptr [eax + 0x14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0043d61e  29d1                   -sub ecx, edx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043d620  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0043d622  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0043d624  0f8d5effffff           -jge 0x43d588
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043d588;
    }
    // 0043d62a  0315a0185100           +add edx, dword ptr [0x5118a0]
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5314720) /* 0x5118a0 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043d630  e953ffffff             -jmp 0x43d588
    goto L_0x0043d588;
L_0x0043d635:
    // 0043d635  8b90e8010000           -mov edx, dword ptr [eax + 0x1e8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(488) /* 0x1e8 */);
    // 0043d63b  01d2                   -add edx, edx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043d63d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043d63f  7c18                   -jl 0x43d659
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043d659;
    }
    // 0043d641  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043d642  8b7014                 -mov esi, dword ptr [eax + 0x14]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0043d645  8b3da0185100           -mov edi, dword ptr [0x5118a0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5314720) /* 0x5118a0 */);
    // 0043d64b  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0043d64d  39fa                   +cmp edx, edi
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
    // 0043d64f  7c02                   -jl 0x43d653
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043d653;
    }
    // 0043d651  29fa                   +sub edx, edi
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
L_0x0043d653:
    // 0043d653  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d654  e92fffffff             -jmp 0x43d588
    goto L_0x0043d588;
L_0x0043d659:
    // 0043d659  035014                 -add edx, dword ptr [eax + 0x14]
    (cpu.edx) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */)));
    // 0043d65c  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043d65e  0f8d24ffffff           -jge 0x43d588
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043d588;
    }
    // 0043d664  0315a0185100           +add edx, dword ptr [0x5118a0]
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5314720) /* 0x5118a0 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043d66a  e919ffffff             -jmp 0x43d588
    goto L_0x0043d588;
L_0x0043d66f:
    // 0043d66f  8b8864050000           -mov ecx, dword ptr [eax + 0x564]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1380) /* 0x564 */);
    // 0043d675  e961ffffff             -jmp 0x43d5db
    goto L_0x0043d5db;
L_0x0043d67a:
    // 0043d67a  e851feffff             -call 0x43d4d0
    cpu.esp -= 4;
    sub_43d4d0(app, cpu);
    if (cpu.terminate) return;
    // 0043d67f  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d680  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d681  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d682  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d683  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43d690(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d690  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043d691  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043d692  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043d693  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043d694  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043d696  83b86001000000         +cmp dword ptr [eax + 0x160], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(352) /* 0x160 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d69d  7426                   -je 0x43d6c5
    if (cpu.flags.zf)
    {
        goto L_0x0043d6c5;
    }
    // 0043d69f  8b9864010000           -mov ebx, dword ptr [eax + 0x164]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(356) /* 0x164 */);
    // 0043d6a5  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043d6a7  741c                   -je 0x43d6c5
    if (cpu.flags.zf)
    {
        goto L_0x0043d6c5;
    }
    // 0043d6a9  8bb09c030000           -mov esi, dword ptr [eax + 0x39c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(924) /* 0x39c */);
    // 0043d6af  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0043d6b1  7e17                   -jle 0x43d6ca
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043d6ca;
    }
    // 0043d6b3  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0043d6b5:
    // 0043d6b5  3d00000a00             +cmp eax, 0xa0000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(655360 /*0xa0000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d6ba  7c14                   -jl 0x43d6d0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043d6d0;
    }
    // 0043d6bc  83b93c05000000         +cmp dword ptr [ecx + 0x53c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1340) /* 0x53c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d6c3  7e25                   -jle 0x43d6ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043d6ea;
    }
L_0x0043d6c5:
    // 0043d6c5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d6c6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d6c7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d6c8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d6c9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043d6ca:
    // 0043d6ca  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043d6cc  f7d8                   +neg eax
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
    // 0043d6ce  ebe5                   -jmp 0x43d6b5
    goto L_0x0043d6b5;
L_0x0043d6d0:
    // 0043d6d0  ba60000000             -mov edx, 0x60
    cpu.edx = 96 /*0x60*/;
    // 0043d6d5  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043d6d7  e8d4070000             -call 0x43deb0
    cpu.esp -= 4;
    sub_43deb0(app, cpu);
    if (cpu.terminate) return;
    // 0043d6dc  83b93c05000000         +cmp dword ptr [ecx + 0x53c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1340) /* 0x53c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d6e3  7e05                   -jle 0x43d6ea
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043d6ea;
    }
    // 0043d6e5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d6e6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d6e7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d6e8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d6e9  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043d6ea:
    // 0043d6ea  f683f401000004         +test byte ptr [ebx + 0x1f4], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(500) /* 0x1f4 */) & 4 /*0x4*/));
    // 0043d6f1  74d2                   -je 0x43d6c5
    if (cpu.flags.zf)
    {
        goto L_0x0043d6c5;
    }
    // 0043d6f3  f681f401000008         +test byte ptr [ecx + 0x1f4], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(500) /* 0x1f4 */) & 8 /*0x8*/));
    // 0043d6fa  74c9                   -je 0x43d6c5
    if (cpu.flags.zf)
    {
        goto L_0x0043d6c5;
    }
    // 0043d6fc  833d0022510000         +cmp dword ptr [0x512200], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317120) /* 0x512200 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d703  74c0                   -je 0x43d6c5
    if (cpu.flags.zf)
    {
        goto L_0x0043d6c5;
    }
    // 0043d705  8b8144050000           -mov eax, dword ptr [ecx + 0x544]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1348) /* 0x544 */);
    // 0043d70b  c7813c05000000000000   -mov dword ptr [ecx + 0x53c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1340) /* 0x53c */) = 0 /*0x0*/;
    // 0043d715  39c3                   +cmp ebx, eax
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
    // 0043d717  7533                   -jne 0x43d74c
    if (!cpu.flags.zf)
    {
        goto L_0x0043d74c;
    }
L_0x0043d719:
    // 0043d719  8b9140050000           -mov edx, dword ptr [ecx + 0x540]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1344) /* 0x540 */);
    // 0043d71f  42                     -inc edx
    (cpu.edx)++;
    // 0043d720  8b99e8010000           -mov ebx, dword ptr [ecx + 0x1e8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(488) /* 0x1e8 */);
    // 0043d726  899140050000           -mov dword ptr [ecx + 0x540], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1344) /* 0x540 */) = cpu.edx;
    // 0043d72c  8b1c9dd8a95000         -mov ebx, dword ptr [ebx*4 + 0x50a9d8]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5286360) /* 0x50a9d8 */ + cpu.ebx * 4);
    // 0043d733  3b93dc000000           +cmp edx, dword ptr [ebx + 0xdc]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(220) /* 0xdc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d739  7e8a                   -jle 0x43d6c5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043d6c5;
    }
    // 0043d73b  8b83e0000000           -mov eax, dword ptr [ebx + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(224) /* 0xe0 */);
    // 0043d741  89813c050000           -mov dword ptr [ecx + 0x53c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1340) /* 0x53c */) = cpu.eax;
    // 0043d747  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d748  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d749  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d74a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d74b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043d74c:
    // 0043d74c  c7814005000000000000   -mov dword ptr [ecx + 0x540], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1344) /* 0x540 */) = 0 /*0x0*/;
    // 0043d756  899944050000           -mov dword ptr [ecx + 0x544], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1348) /* 0x544 */) = cpu.ebx;
    // 0043d75c  ebbb                   -jmp 0x43d719
    goto L_0x0043d719;
}

/* align: skip 0x00 0x00 */
void Application::sub_43d760(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d760  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043d761  f680f401000004         +test byte ptr [eax + 0x1f4], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(500) /* 0x1f4 */) & 4 /*0x4*/));
    // 0043d768  7512                   -jne 0x43d77c
    if (!cpu.flags.zf)
    {
        goto L_0x0043d77c;
    }
    // 0043d76a  8b909c030000           -mov edx, dword ptr [eax + 0x39c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(924) /* 0x39c */);
    // 0043d770  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043d772  7e0a                   -jle 0x43d77e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043d77e;
    }
    // 0043d774  81fa00000a00           +cmp edx, 0xa0000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(655360 /*0xa0000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d77a  7c0e                   -jl 0x43d78a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043d78a;
    }
L_0x0043d77c:
    // 0043d77c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d77d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043d77e:
    // 0043d77e  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0043d780  81fa00000a00           +cmp edx, 0xa0000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(655360 /*0xa0000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d786  7c02                   -jl 0x43d78a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043d78a;
    }
    // 0043d788  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d789  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043d78a:
    // 0043d78a  ba60000000             -mov edx, 0x60
    cpu.edx = 96 /*0x60*/;
    // 0043d78f  e81c070000             -call 0x43deb0
    cpu.esp -= 4;
    sub_43deb0(app, cpu);
    if (cpu.terminate) return;
    // 0043d794  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d795  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43d7a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d7a0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043d7a1  8b151c225100           -mov edx, dword ptr [0x51221c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317148) /* 0x51221c */);
    // 0043d7a7  83fa09                 +cmp edx, 9
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d7aa  7d16                   -jge 0x43d7c2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043d7c2;
    }
    // 0043d7ac  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0043d7b3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043d7b5  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0043d7b8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043d7ba  8b8030ad5000           -mov eax, dword ptr [eax + 0x50ad30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5287216) /* 0x50ad30 */);
    // 0043d7c0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d7c1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043d7c2:
    // 0043d7c2  b890010000             -mov eax, 0x190
    cpu.eax = 400 /*0x190*/;
    // 0043d7c7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d7c8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43d7d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d7d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043d7d1  8b151c225100           -mov edx, dword ptr [0x51221c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317148) /* 0x51221c */);
    // 0043d7d7  83fa09                 +cmp edx, 9
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d7da  7d16                   -jge 0x43d7f2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043d7f2;
    }
    // 0043d7dc  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0043d7e3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043d7e5  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0043d7e8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043d7ea  8b802cad5000           -mov eax, dword ptr [eax + 0x50ad2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5287212) /* 0x50ad2c */);
    // 0043d7f0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d7f1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043d7f2:
    // 0043d7f2  b800000100             -mov eax, 0x10000
    cpu.eax = 65536 /*0x10000*/;
    // 0043d7f7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d7f8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43d800(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d800  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043d801  8b151c225100           -mov edx, dword ptr [0x51221c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317148) /* 0x51221c */);
    // 0043d807  83fa09                 +cmp edx, 9
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d80a  7d16                   -jge 0x43d822
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043d822;
    }
    // 0043d80c  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0043d813  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043d815  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0043d818  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043d81a  8b8028ad5000           -mov eax, dword ptr [eax + 0x50ad28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5287208) /* 0x50ad28 */);
    // 0043d820  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d821  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043d822:
    // 0043d822  b800000100             -mov eax, 0x10000
    cpu.eax = 65536 /*0x10000*/;
    // 0043d827  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d828  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43d830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d830  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043d831  8b151c225100           -mov edx, dword ptr [0x51221c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317148) /* 0x51221c */);
    // 0043d837  83fa09                 +cmp edx, 9
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d83a  7d16                   -jge 0x43d852
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043d852;
    }
    // 0043d83c  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0043d843  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043d845  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0043d848  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043d84a  8b8024ad5000           -mov eax, dword ptr [eax + 0x50ad24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5287204) /* 0x50ad24 */);
    // 0043d850  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d851  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043d852:
    // 0043d852  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043d857  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d858  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43d860(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d860  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043d861  8b151c225100           -mov edx, dword ptr [0x51221c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317148) /* 0x51221c */);
    // 0043d867  83fa09                 +cmp edx, 9
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d86a  7c1b                   -jl 0x43d887
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043d887;
    }
    // 0043d86c  a1a4185100             -mov eax, dword ptr [0x5118a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5314724) /* 0x5118a4 */);
    // 0043d871  8a4043                 -mov al, byte ptr [eax + 0x43]
    cpu.al = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(67) /* 0x43 */);
    // 0043d874  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0043d879  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0043d87c  a80f                   +test al, 0xf
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.al & 15 /*0xf*/));
    // 0043d87e  751d                   -jne 0x43d89d
    if (!cpu.flags.zf)
    {
        goto L_0x0043d89d;
    }
    // 0043d880  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043d885  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d886  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043d887:
    // 0043d887  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0043d88e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043d890  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0043d893  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043d895  8b8020ad5000           -mov eax, dword ptr [eax + 0x50ad20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5287200) /* 0x50ad20 */);
    // 0043d89b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d89c  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043d89d:
    // 0043d89d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043d89f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d8a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43d8b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d8b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043d8b1  8b151c225100           -mov edx, dword ptr [0x51221c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317148) /* 0x51221c */);
    // 0043d8b7  83fa09                 +cmp edx, 9
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d8ba  7d16                   -jge 0x43d8d2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043d8d2;
    }
    // 0043d8bc  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0043d8c3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043d8c5  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0043d8c8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043d8ca  8b801cad5000           -mov eax, dword ptr [eax + 0x50ad1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5287196) /* 0x50ad1c */);
    // 0043d8d0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d8d1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043d8d2:
    // 0043d8d2  b8f4010000             -mov eax, 0x1f4
    cpu.eax = 500 /*0x1f4*/;
    // 0043d8d7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d8d8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43d8e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d8e0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043d8e1  8b151c225100           -mov edx, dword ptr [0x51221c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317148) /* 0x51221c */);
    // 0043d8e7  83fa09                 +cmp edx, 9
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(9 /*0x9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043d8ea  7d16                   -jge 0x43d902
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043d902;
    }
    // 0043d8ec  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0043d8f3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043d8f5  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0043d8f8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043d8fa  8b8018ad5000           -mov eax, dword ptr [eax + 0x50ad18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5287192) /* 0x50ad18 */);
    // 0043d900  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d901  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043d902:
    // 0043d902  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 0043d907  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043d908  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43d910(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043d910  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0043d912  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0043d914  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0043d916  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0043d918  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0043d91a  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0043d91c  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0043d91e  0000                   -add byte ptr [eax], al
    (app->getMemory<x86::reg8>(cpu.eax)) += x86::reg8(x86::sreg8(cpu.al));
    // 0043d920  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043d921  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043d922  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043d923  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043d924  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043d925  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043d926  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043d928  8b9094030000           -mov edx, dword ptr [eax + 0x394]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(916) /* 0x394 */);
    // 0043d92e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043d92f  8b8898030000           -mov ecx, dword ptr [eax + 0x398]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(920) /* 0x398 */);
    // 0043d935  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043d936  8b98f0000000           -mov ebx, dword ptr [eax + 0xf0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(240) /* 0xf0 */);
    // 0043d93c  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043d93d  8bb8ec000000           -mov edi, dword ptr [eax + 0xec]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(236) /* 0xec */);
    // 0043d943  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043d944  8ba8e8000000           -mov ebp, dword ptr [eax + 0xe8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(232) /* 0xe8 */);
    // 0043d94a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043d94b  8b80b0000000           -mov eax, dword ptr [eax + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(176) /* 0xb0 */);
    // 0043d951  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043d952  8b96ac000000           -mov edx, dword ptr [esi + 0xac]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */);
    // 0043d958  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043d959  8b8ea8000000           -mov ecx, dword ptr [esi + 0xa8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(168) /* 0xa8 */);
    // 0043d95f  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043d960  8b9ea4000000           -mov ebx, dword ptr [esi + 0xa4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(164) /* 0xa4 */);
    // 0043d966  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043d967  8bbea0000000           -mov edi, dword ptr [esi + 0xa0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(160) /* 0xa0 */);
    // 0043d96d  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043d96e  8bae9c000000           -mov ebp, dword ptr [esi + 0x9c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(156) /* 0x9c */);
    // 0043d974  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043d976  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043d977  668b864c010000         -mov ax, word ptr [esi + 0x14c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(332) /* 0x14c */);
    // 0043d97e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043d97f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043d981  8a868c000000           -mov al, byte ptr [esi + 0x8c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 0043d987  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043d988  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 0043d98a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043d98b  68e4b94c00             -push 0x4cb9e4
    app->getMemory<x86::reg32>(cpu.esp-4) = 5028324 /*0x4cb9e4*/;
    cpu.esp -= 4;
    // 0043d990  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0043d992  e8d95d0100             -call 0x453770
    cpu.esp -= 4;
    sub_453770(app, cpu);
    if (cpu.terminate) return;
    // 0043d997  83c440                 -add esp, 0x40
    (cpu.esp) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 0043d99a  6810ad5000             -push 0x50ad10
    app->getMemory<x86::reg32>(cpu.esp-4) = 5287184 /*0x50ad10*/;
    cpu.esp -= 4;
    // 0043d99f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
    // 0043d9a4  680cad5000             -push 0x50ad0c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5287180 /*0x50ad0c*/;
    cpu.esp -= 4;
    // 0043d9a9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043d9ab  6808ad5000             -push 0x50ad08
    app->getMemory<x86::reg32>(cpu.esp-4) = 5287176 /*0x50ad08*/;
    cpu.esp -= 4;
    // 0043d9b0  8b0e                   -mov ecx, dword ptr [esi]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi);
    // 0043d9b2  8b9e88000000           -mov ebx, dword ptr [esi + 0x88]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(136) /* 0x88 */);
    // 0043d9b8  e8633c0300             -call 0x471620
    cpu.esp -= 4;
    sub_471620(app, cpu);
    if (cpu.terminate) return;
    // 0043d9bd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043d9bf  0f8485000000           -je 0x43da4a
    if (cpu.flags.zf)
    {
        goto L_0x0043da4a;
    }
    // 0043d9c5  f686f401000002         +test byte ptr [esi + 0x1f4], 2
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(500) /* 0x1f4 */) & 2 /*0x2*/));
    // 0043d9cc  7433                   -je 0x43da01
    if (cpu.flags.zf)
    {
        goto L_0x0043da01;
    }
    // 0043d9ce  8b86a8000000           -mov eax, dword ptr [esi + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(168) /* 0xa8 */);
    // 0043d9d4  8b96b0000000           -mov edx, dword ptr [esi + 0xb0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(176) /* 0xb0 */);
    // 0043d9da  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043d9dc  0f8e6f000000           -jle 0x43da51
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043da51;
    }
L_0x0043d9e2:
    // 0043d9e2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043d9e4  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043d9e6  0f8e69000000           -jle 0x43da55
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043da55;
    }
    // 0043d9ec  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0043d9ee:
    // 0043d9ee  39c1                   +cmp ecx, eax
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
    // 0043d9f0  0f8e65000000           -jle 0x43da5b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043da5b;
    }
    // 0043d9f6  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
L_0x0043d9f9:
    // 0043d9f9  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 0043d9fb  8986a0030000           -mov dword ptr [esi + 0x3a0], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(928) /* 0x3a0 */) = cpu.eax;
L_0x0043da01:
    // 0043da01  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043da03  e848010000             -call 0x43db50
    cpu.esp -= 4;
    sub_43db50(app, cpu);
    if (cpu.terminate) return;
    // 0043da08  f686a803000010         +test byte ptr [esi + 0x3a8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(936) /* 0x3a8 */) & 16 /*0x10*/));
    // 0043da0f  7510                   -jne 0x43da21
    if (!cpu.flags.zf)
    {
        goto L_0x0043da21;
    }
    // 0043da11  f686f401000008         +test byte ptr [esi + 0x1f4], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(500) /* 0x1f4 */) & 8 /*0x8*/));
    // 0043da18  7507                   -jne 0x43da21
    if (!cpu.flags.zf)
    {
        goto L_0x0043da21;
    }
    // 0043da1a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043da1c  e81fe4ffff             -call 0x43be40
    cpu.esp -= 4;
    sub_43be40(app, cpu);
    if (cpu.terminate) return;
L_0x0043da21:
    // 0043da21  f686a803000010         +test byte ptr [esi + 0x3a8], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(936) /* 0x3a8 */) & 16 /*0x10*/));
    // 0043da28  7536                   -jne 0x43da60
    if (!cpu.flags.zf)
    {
        goto L_0x0043da60;
    }
    // 0043da2a  833d440f540001         +cmp dword ptr [0x540f44], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5508932) /* 0x540f44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043da31  0f8475000000           -je 0x43daac
    if (cpu.flags.zf)
    {
        goto L_0x0043daac;
    }
    // 0043da37  f686f401000008         +test byte ptr [esi + 0x1f4], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esi + x86::reg32(500) /* 0x1f4 */) & 8 /*0x8*/));
    // 0043da3e  740a                   -je 0x43da4a
    if (cpu.flags.zf)
    {
        goto L_0x0043da4a;
    }
    // 0043da40  6683be4c01000000       +cmp word ptr [esi + 0x14c], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(332) /* 0x14c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043da48  741f                   -je 0x43da69
    if (cpu.flags.zf)
    {
        goto L_0x0043da69;
    }
L_0x0043da4a:
    // 0043da4a  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043da4b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043da4c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043da4d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043da4e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043da4f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043da50  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043da51:
    // 0043da51  f7d8                   +neg eax
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
    // 0043da53  eb8d                   -jmp 0x43d9e2
    goto L_0x0043d9e2;
L_0x0043da55:
    // 0043da55  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043da57  f7d8                   +neg eax
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
    // 0043da59  eb93                   -jmp 0x43d9ee
    goto L_0x0043d9ee;
L_0x0043da5b:
    // 0043da5b  c1f902                 +sar ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0043da5e  eb99                   -jmp 0x43d9f9
    goto L_0x0043d9f9;
L_0x0043da60:
    // 0043da60  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043da62  e8691b0000             -call 0x43f5d0
    cpu.esp -= 4;
    sub_43f5d0(app, cpu);
    if (cpu.terminate) return;
    // 0043da67  ebe1                   -jmp 0x43da4a
    goto L_0x0043da4a;
L_0x0043da69:
    // 0043da69  c786ac00000000000000   -mov dword ptr [esi + 0xac], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */) = 0 /*0x0*/;
    // 0043da73  c786b000000000000000   -mov dword ptr [esi + 0xb0], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(176) /* 0xb0 */) = 0 /*0x0*/;
    // 0043da7d  c786e800000000000000   -mov dword ptr [esi + 0xe8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(232) /* 0xe8 */) = 0 /*0x0*/;
    // 0043da87  c786ec00000000000000   -mov dword ptr [esi + 0xec], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(236) /* 0xec */) = 0 /*0x0*/;
    // 0043da91  c786f000000000000000   -mov dword ptr [esi + 0xf0], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(240) /* 0xf0 */) = 0 /*0x0*/;
    // 0043da9b  c786a800000000000000   -mov dword ptr [esi + 0xa8], 0
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(168) /* 0xa8 */) = 0 /*0x0*/;
    // 0043daa5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043daa6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043daa7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043daa8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043daa9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043daaa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043daab  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043daac:
    // 0043daac  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043daae  e8dd220000             -call 0x43fd90
    cpu.esp -= 4;
    sub_43fd90(app, cpu);
    if (cpu.terminate) return;
    // 0043dab3  80be8c00000000         +cmp byte ptr [esi + 0x8c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(140) /* 0x8c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043daba  0f8480000000           -je 0x43db40
    if (cpu.flags.zf)
    {
        goto L_0x0043db40;
    }
    // 0043dac0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043dac2  e8691d0000             -call 0x43f830
    cpu.esp -= 4;
    sub_43f830(app, cpu);
    if (cpu.terminate) return;
L_0x0043dac7:
    // 0043dac7  8b8e94030000           -mov ecx, dword ptr [esi + 0x394]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(916) /* 0x394 */);
    // 0043dacd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043dace  8b9e98030000           -mov ebx, dword ptr [esi + 0x398]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(920) /* 0x398 */);
    // 0043dad4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043dad5  8bbef0000000           -mov edi, dword ptr [esi + 0xf0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(240) /* 0xf0 */);
    // 0043dadb  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043dadc  8baeec000000           -mov ebp, dword ptr [esi + 0xec]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(236) /* 0xec */);
    // 0043dae2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043dae3  8b86e8000000           -mov eax, dword ptr [esi + 0xe8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(232) /* 0xe8 */);
    // 0043dae9  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043daea  8b96b0000000           -mov edx, dword ptr [esi + 0xb0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(176) /* 0xb0 */);
    // 0043daf0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043daf1  8b8eac000000           -mov ecx, dword ptr [esi + 0xac]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(172) /* 0xac */);
    // 0043daf7  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043daf8  8b9ea8000000           -mov ebx, dword ptr [esi + 0xa8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(168) /* 0xa8 */);
    // 0043dafe  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043daff  8bbea4000000           -mov edi, dword ptr [esi + 0xa4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(164) /* 0xa4 */);
    // 0043db05  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043db06  8baea0000000           -mov ebp, dword ptr [esi + 0xa0]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(160) /* 0xa0 */);
    // 0043db0c  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043db0d  8b869c000000           -mov eax, dword ptr [esi + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(156) /* 0x9c */);
    // 0043db13  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043db14  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043db16  668b864c010000         -mov ax, word ptr [esi + 0x14c]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(332) /* 0x14c */);
    // 0043db1d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043db1e  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043db20  8a868c000000           -mov al, byte ptr [esi + 0x8c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(140) /* 0x8c */);
    // 0043db26  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043db27  8b16                   -mov edx, dword ptr [esi]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi);
    // 0043db29  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043db2a  6824ba4c00             -push 0x4cba24
    app->getMemory<x86::reg32>(cpu.esp-4) = 5028388 /*0x4cba24*/;
    cpu.esp -= 4;
    // 0043db2f  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0043db31  e83a5c0100             -call 0x453770
    cpu.esp -= 4;
    sub_453770(app, cpu);
    if (cpu.terminate) return;
    // 0043db36  83c440                 +add esp, 0x40
    {
        x86::reg32& tmp1 = cpu.esp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043db39  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043db3a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043db3b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043db3c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043db3d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043db3e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043db3f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043db40:
    // 0043db40  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043db42  e8a9000000             -call 0x43dbf0
    cpu.esp -= 4;
    sub_43dbf0(app, cpu);
    if (cpu.terminate) return;
    // 0043db47  e97bffffff             -jmp 0x43dac7
    goto L_0x0043dac7;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_43db50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043db50  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043db51  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043db52  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043db53  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043db54  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043db55  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043db56  8b88ac030000           -mov ecx, dword ptr [eax + 0x3ac]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(940) /* 0x3ac */);
    // 0043db5c  3b8894030000           +cmp ecx, dword ptr [eax + 0x394]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(916) /* 0x394 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043db62  7e3b                   -jle 0x43db9f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043db9f;
    }
    // 0043db64  3b8848050000           +cmp ecx, dword ptr [eax + 0x548]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1352) /* 0x548 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043db6a  7d33                   -jge 0x43db9f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043db9f;
    }
    // 0043db6c  898848050000           -mov dword ptr [eax + 0x548], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1352) /* 0x548 */) = cpu.ecx;
L_0x0043db72:
    // 0043db72  8ba894030000           -mov ebp, dword ptr [eax + 0x394]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(916) /* 0x394 */);
    // 0043db78  8b9048050000           -mov edx, dword ptr [eax + 0x548]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1352) /* 0x548 */);
    // 0043db7e  39ea                   +cmp edx, ebp
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
    // 0043db80  7d43                   -jge 0x43dbc5
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043dbc5;
    }
    // 0043db82  8dba33330000           -lea edi, [edx + 0x3333]
    cpu.edi = x86::reg32(cpu.edx + x86::reg32(13107) /* 0x3333 */);
    // 0043db88  8ba894030000           -mov ebp, dword ptr [eax + 0x394]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(916) /* 0x394 */);
    // 0043db8e  89b848050000           -mov dword ptr [eax + 0x548], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1352) /* 0x548 */) = cpu.edi;
    // 0043db94  39ef                   +cmp edi, ebp
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
    // 0043db96  7f25                   -jg 0x43dbbd
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0043dbbd;
    }
L_0x0043db98:
    // 0043db98  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043db99  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043db9a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043db9b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043db9c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043db9d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043db9e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043db9f:
    // 0043db9f  8bb0ac030000           -mov esi, dword ptr [eax + 0x3ac]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(940) /* 0x3ac */);
    // 0043dba5  3bb048050000           +cmp esi, dword ptr [eax + 0x548]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1352) /* 0x548 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043dbab  7ec5                   -jle 0x43db72
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043db72;
    }
    // 0043dbad  3bb094030000           +cmp esi, dword ptr [eax + 0x394]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(916) /* 0x394 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043dbb3  7dbd                   -jge 0x43db72
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043db72;
    }
    // 0043dbb5  89b048050000           -mov dword ptr [eax + 0x548], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1352) /* 0x548 */) = cpu.esi;
    // 0043dbbb  ebb5                   -jmp 0x43db72
    goto L_0x0043db72;
L_0x0043dbbd:
    // 0043dbbd  89a848050000           -mov dword ptr [eax + 0x548], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1352) /* 0x548 */) = cpu.ebp;
    // 0043dbc3  ebd3                   -jmp 0x43db98
    goto L_0x0043db98;
L_0x0043dbc5:
    // 0043dbc5  7ed1                   -jle 0x43db98
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043db98;
    }
    // 0043dbc7  8d9acdccffff           -lea ebx, [edx - 0x3333]
    cpu.ebx = x86::reg32(cpu.edx + x86::reg32(-13107) /* -0x3333 */);
    // 0043dbcd  8bb094030000           -mov esi, dword ptr [eax + 0x394]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(916) /* 0x394 */);
    // 0043dbd3  899848050000           -mov dword ptr [eax + 0x548], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1352) /* 0x548 */) = cpu.ebx;
    // 0043dbd9  39f3                   +cmp ebx, esi
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
    // 0043dbdb  7dbb                   -jge 0x43db98
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043db98;
    }
    // 0043dbdd  89b048050000           -mov dword ptr [eax + 0x548], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1352) /* 0x548 */) = cpu.esi;
    // 0043dbe3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dbe4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dbe5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dbe6  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dbe7  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dbe8  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dbe9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43dbf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043dbf0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043dbf1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043dbf2  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043dbf4  6683b84c01000000       +cmp word ptr [eax + 0x14c], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(332) /* 0x14c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043dbfc  7510                   -jne 0x43dc0e
    if (!cpu.flags.zf)
    {
        goto L_0x0043dc0e;
    }
    // 0043dbfe  81b8d4000000cc4c0000   +cmp dword ptr [eax + 0xd4], 0x4ccc
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(212) /* 0xd4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(19660 /*0x4ccc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043dc08  0f8c72000000           -jl 0x43dc80
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043dc80;
    }
L_0x0043dc0e:
    // 0043dc0e  f681f401000001         +test byte ptr [ecx + 0x1f4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(500) /* 0x1f4 */) & 1 /*0x1*/));
    // 0043dc15  741c                   -je 0x43dc33
    if (cpu.flags.zf)
    {
        goto L_0x0043dc33;
    }
    // 0043dc17  83b98002000002         +cmp dword ptr [ecx + 0x280], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(640) /* 0x280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043dc1e  7513                   -jne 0x43dc33
    if (!cpu.flags.zf)
    {
        goto L_0x0043dc33;
    }
    // 0043dc20  8bb19c030000           -mov esi, dword ptr [ecx + 0x39c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */);
    // 0043dc26  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0043dc28  7e5e                   -jle 0x43dc88
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043dc88;
    }
    // 0043dc2a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0043dc2c:
    // 0043dc2c  3d00000200             +cmp eax, 0x20000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(131072 /*0x20000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043dc31  7c5b                   -jl 0x43dc8e
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043dc8e;
    }
L_0x0043dc33:
    // 0043dc33  6683b94c01000000       +cmp word ptr [ecx + 0x14c], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(332) /* 0x14c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043dc3b  7540                   -jne 0x43dc7d
    if (!cpu.flags.zf)
    {
        goto L_0x0043dc7d;
    }
    // 0043dc3d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043dc3f  e88c010000             -call 0x43ddd0
    cpu.esp -= 4;
    sub_43ddd0(app, cpu);
    if (cpu.terminate) return;
    // 0043dc44  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043dc46  e8a5d20200             -call 0x46aef0
    cpu.esp -= 4;
    sub_46aef0(app, cpu);
    if (cpu.terminate) return;
    // 0043dc4b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043dc4d  7465                   -je 0x43dcb4
    if (cpu.flags.zf)
    {
        goto L_0x0043dcb4;
    }
L_0x0043dc4f:
    // 0043dc4f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043dc50  ba40000000             -mov edx, 0x40
    cpu.edx = 64 /*0x40*/;
    // 0043dc55  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043dc57  e854020000             -call 0x43deb0
    cpu.esp -= 4;
    sub_43deb0(app, cpu);
    if (cpu.terminate) return;
    // 0043dc5c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0043dc5d:
    // 0043dc5d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043dc5f  e8ac110000             -call 0x43ee10
    cpu.esp -= 4;
    sub_43ee10(app, cpu);
    if (cpu.terminate) return;
    // 0043dc64  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043dc66  e8f50c0000             -call 0x43e960
    cpu.esp -= 4;
    sub_43e960(app, cpu);
    if (cpu.terminate) return;
    // 0043dc6b  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043dc6d  7452                   -je 0x43dcc1
    if (cpu.flags.zf)
    {
        goto L_0x0043dcc1;
    }
    // 0043dc6f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043dc71  e8fa020000             -call 0x43df70
    cpu.esp -= 4;
    sub_43df70(app, cpu);
    if (cpu.terminate) return;
    // 0043dc76  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043dc78  e8330d0000             -call 0x43e9b0
    cpu.esp -= 4;
    sub_43e9b0(app, cpu);
    if (cpu.terminate) return;
L_0x0043dc7d:
    // 0043dc7d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dc7e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dc7f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043dc80:
    // 0043dc80  e8fbc40200             -call 0x46a180
    cpu.esp -= 4;
    sub_46a180(app, cpu);
    if (cpu.terminate) return;
    // 0043dc85  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dc86  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dc87  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043dc88:
    // 0043dc88  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043dc8a  f7d8                   +neg eax
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
    // 0043dc8c  eb9e                   -jmp 0x43dc2c
    goto L_0x0043dc2c;
L_0x0043dc8e:
    // 0043dc8e  c781f000000000000000   -mov dword ptr [ecx + 0xf0], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */) = 0 /*0x0*/;
    // 0043dc98  8b81f0000000           -mov eax, dword ptr [ecx + 0xf0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */);
    // 0043dc9e  8981ec000000           -mov dword ptr [ecx + 0xec], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */) = cpu.eax;
    // 0043dca4  8981e8000000           -mov dword ptr [ecx + 0xe8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */) = cpu.eax;
    // 0043dcaa  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043dcac  e8cfc40200             -call 0x46a180
    cpu.esp -= 4;
    sub_46a180(app, cpu);
    if (cpu.terminate) return;
    // 0043dcb1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dcb2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dcb3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043dcb4:
    // 0043dcb4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043dcb6  e825000000             -call 0x43dce0
    cpu.esp -= 4;
    sub_43dce0(app, cpu);
    if (cpu.terminate) return;
    // 0043dcbb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043dcbd  7590                   -jne 0x43dc4f
    if (!cpu.flags.zf)
    {
        goto L_0x0043dc4f;
    }
    // 0043dcbf  eb9c                   -jmp 0x43dc5d
    goto L_0x0043dc5d;
L_0x0043dcc1:
    // 0043dcc1  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043dcc3  e828080000             -call 0x43e4f0
    cpu.esp -= 4;
    sub_43e4f0(app, cpu);
    if (cpu.terminate) return;
    // 0043dcc8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043dcca  e8e10c0000             -call 0x43e9b0
    cpu.esp -= 4;
    sub_43e9b0(app, cpu);
    if (cpu.terminate) return;
    // 0043dccf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dcd0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dcd1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43dce0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043dce0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043dce1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043dce2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043dce3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043dce4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043dce5  8b5814                 -mov ebx, dword ptr [eax + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0043dce8  8d14dd00000000         -lea edx, [ebx*8]
    cpu.edx = x86::reg32(cpu.ebx * 8);
    // 0043dcef  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043dcf1  8b1da4185100           -mov ebx, dword ptr [0x5118a4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5314724) /* 0x5118a4 */);
    // 0043dcf7  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0043dcfa  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043dcfc  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043dcfe  8a5a1f                 -mov bl, byte ptr [edx + 0x1f]
    cpu.bl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(31) /* 0x1f */);
    // 0043dd01  c1fb04                 -sar ebx, 4
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (4 /*0x4*/ % 32));
    // 0043dd04  be07000000             -mov esi, 7
    cpu.esi = 7 /*0x7*/;
    // 0043dd09  83e30f                 -and ebx, 0xf
    cpu.ebx &= x86::reg32(x86::sreg32(15 /*0xf*/));
    // 0043dd0c  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043dd0e  89f3                   -mov ebx, esi
    cpu.ebx = cpu.esi;
    // 0043dd10  8bb000050000           -mov esi, dword ptr [eax + 0x500]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1280) /* 0x500 */);
    // 0043dd16  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043dd18  39f3                   +cmp ebx, esi
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
    // 0043dd1a  0f8f63000000           -jg 0x43dd83
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0043dd83;
    }
    // 0043dd20  8a521f                 -mov dl, byte ptr [edx + 0x1f]
    cpu.dl = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(31) /* 0x1f */);
    // 0043dd23  80e20f                 -and dl, 0xf
    cpu.dl &= x86::reg8(x86::sreg8(15 /*0xf*/));
    // 0043dd26  81e2ff000000           -and edx, 0xff
    cpu.edx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0043dd2c  83c206                 -add edx, 6
    (cpu.edx) += x86::reg32(x86::sreg32(6 /*0x6*/));
    // 0043dd2f  39f2                   +cmp edx, esi
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
    // 0043dd31  7c50                   -jl 0x43dd83
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043dd83;
    }
    // 0043dd33  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0043dd38:
    // 0043dd38  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0043dd3a  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043dd3c  7549                   -jne 0x43dd87
    if (!cpu.flags.zf)
    {
        goto L_0x0043dd87;
    }
    // 0043dd3e  8b150cad5000           -mov edx, dword ptr [0x50ad0c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287180) /* 0x50ad0c */);
    // 0043dd44  8ba84c050000           -mov ebp, dword ptr [eax + 0x54c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1356) /* 0x54c */);
    // 0043dd4a  01d5                   -add ebp, edx
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043dd4c  89a84c050000           -mov dword ptr [eax + 0x54c], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1356) /* 0x54c */) = cpu.ebp;
    // 0043dd52  83fd04                 +cmp ebp, 4
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043dd55  7f24                   -jg 0x43dd7b
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0043dd7b;
    }
L_0x0043dd57:
    // 0043dd57  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043dd59  7520                   -jne 0x43dd7b
    if (!cpu.flags.zf)
    {
        goto L_0x0043dd7b;
    }
    // 0043dd5b  80b98c00000000         +cmp byte ptr [ecx + 0x8c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(140) /* 0x8c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0043dd62  752f                   -jne 0x43dd93
    if (!cpu.flags.zf)
    {
        goto L_0x0043dd93;
    }
    // 0043dd64  83791800               +cmp dword ptr [ecx + 0x18], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(24) /* 0x18 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043dd68  7429                   -je 0x43dd93
    if (cpu.flags.zf)
    {
        goto L_0x0043dd93;
    }
    // 0043dd6a  8b4120                 -mov eax, dword ptr [ecx + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(32) /* 0x20 */);
    // 0043dd6d  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0043dd6f  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043dd72  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043dd74  3d99d90000             +cmp eax, 0xd999
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(55705 /*0xd999*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043dd79  7e45                   -jle 0x43ddc0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043ddc0;
    }
L_0x0043dd7b:
    // 0043dd7b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043dd7d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dd7e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dd7f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dd80  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dd81  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043dd82  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043dd83:
    // 0043dd83  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0043dd85  ebb1                   -jmp 0x43dd38
    goto L_0x0043dd38;
L_0x0043dd87:
    // 0043dd87  c7804c05000000000000   -mov dword ptr [eax + 0x54c], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1356) /* 0x54c */) = 0 /*0x0*/;
    // 0043dd91  ebc4                   -jmp 0x43dd57
    goto L_0x0043dd57;
L_0x0043dd93:
    // 0043dd93  8b5114                 -mov edx, dword ptr [ecx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0043dd96  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0043dd9d  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043dd9f  a1a4185100             -mov eax, dword ptr [0x5118a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5314724) /* 0x5118a4 */);
    // 0043dda4  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0043dda7  8b44020a               -mov eax, dword ptr [edx + eax + 0xa]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(10) /* 0xa */ + cpu.eax * 1);
    // 0043ddab  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0043ddae  c1e009                 -shl eax, 9
    cpu.eax <<= 9 /*0x9*/ % 32;
    // 0043ddb1  3d99d90000             +cmp eax, 0xd999
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(55705 /*0xd999*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ddb6  7e08                   -jle 0x43ddc0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043ddc0;
    }
    // 0043ddb8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043ddba  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ddbb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ddbc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ddbd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ddbe  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ddbf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043ddc0:
    // 0043ddc0  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043ddc5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ddc6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ddc7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ddc8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ddc9  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ddca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43ddd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043ddd0  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043ddd1  83b824050000ff         +cmp dword ptr [eax + 0x524], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1316) /* 0x524 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ddd8  0f85a4000000           -jne 0x43de82
    if (!cpu.flags.zf)
    {
        goto L_0x0043de82;
    }
    // 0043ddde  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043dddf  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043dde0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043dde1  8b9048050000           -mov edx, dword ptr [eax + 0x548]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1352) /* 0x548 */);
    // 0043dde7  8b88ac030000           -mov ecx, dword ptr [eax + 0x3ac]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(940) /* 0x3ac */);
    // 0043dded  81ea00000a00           -sub edx, 0xa0000
    (cpu.edx) -= x86::reg32(x86::sreg32(655360 /*0xa0000*/));
    // 0043ddf3  39ca                   +cmp edx, ecx
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
    // 0043ddf5  0f8e89000000           -jle 0x43de84
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043de84;
    }
    // 0043ddfb  83b83805000000         +cmp dword ptr [eax + 0x538], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1336) /* 0x538 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043de02  0f8e7c000000           -jle 0x43de84
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043de84;
    }
L_0x0043de08:
    // 0043de08  8b15480f5400           -mov edx, dword ptr [0x540f48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 0043de0e  83ea18                 -sub edx, 0x18
    (cpu.edx) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0043de11  899028050000           -mov dword ptr [eax + 0x528], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1320) /* 0x528 */) = cpu.edx;
L_0x0043de17:
    // 0043de17  8b15480f5400           -mov edx, dword ptr [0x540f48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 0043de1d  8ba828050000           -mov ebp, dword ptr [eax + 0x528]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1320) /* 0x528 */);
    // 0043de23  8b8820050000           -mov ecx, dword ptr [eax + 0x520]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1312) /* 0x520 */);
    // 0043de29  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0043de2b  39ca                   +cmp edx, ecx
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
    // 0043de2d  7e16                   -jle 0x43de45
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043de45;
    }
    // 0043de2f  8b15480f5400           -mov edx, dword ptr [0x540f48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 0043de35  c7802405000001000000   -mov dword ptr [eax + 0x524], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1316) /* 0x524 */) = 1 /*0x1*/;
    // 0043de3f  899028050000           -mov dword ptr [eax + 0x528], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1320) /* 0x528 */) = cpu.edx;
L_0x0043de45:
    // 0043de45  81b89803000000001400   +cmp dword ptr [eax + 0x398], 0x140000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(920) /* 0x398 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1310720 /*0x140000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043de4f  7e0a                   -jle 0x43de5b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043de5b;
    }
    // 0043de51  c7809803000000001400   -mov dword ptr [eax + 0x398], 0x140000
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(920) /* 0x398 */) = 1310720 /*0x140000*/;
L_0x0043de5b:
    // 0043de5b  8b9098030000           -mov edx, dword ptr [eax + 0x398]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(920) /* 0x398 */);
    // 0043de61  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0043de63  81fa00001400           +cmp edx, 0x140000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1310720 /*0x140000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043de69  7e0a                   -jle 0x43de75
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043de75;
    }
    // 0043de6b  c780980300000000ecff   -mov dword ptr [eax + 0x398], 0xffec0000
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(920) /* 0x398 */) = 4293656576 /*0xffec0000*/;
L_0x0043de75:
    // 0043de75  c7804805000000000000   -mov dword ptr [eax + 0x548], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1352) /* 0x548 */) = 0 /*0x0*/;
    // 0043de7f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043de80  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043de81  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0043de82:
    // 0043de82  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043de83  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043de84:
    // 0043de84  8b9048050000           -mov edx, dword ptr [eax + 0x548]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1352) /* 0x548 */);
    // 0043de8a  8bb0ac030000           -mov esi, dword ptr [eax + 0x3ac]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(940) /* 0x3ac */);
    // 0043de90  81c200000a00           -add edx, 0xa0000
    (cpu.edx) += x86::reg32(x86::sreg32(655360 /*0xa0000*/));
    // 0043de96  39f2                   +cmp edx, esi
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
    // 0043de98  0f8d79ffffff           -jge 0x43de17
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043de17;
    }
    // 0043de9e  83b83805000000         +cmp dword ptr [eax + 0x538], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1336) /* 0x538 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043dea5  0f8c5dffffff           -jl 0x43de08
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043de08;
    }
    // 0043deab  e967ffffff             -jmp 0x43de17
    goto L_0x0043de17;
}

/* align: skip  */
void Application::sub_43deb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043deb0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043deb1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043deb2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043deb3  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043deb5  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0043deb7  83b824050000ff         +cmp dword ptr [eax + 0x524], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1316) /* 0x524 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043debe  7522                   -jne 0x43dee2
    if (!cpu.flags.zf)
    {
        goto L_0x0043dee2;
    }
    // 0043dec0  a1480f5400             -mov eax, dword ptr [0x540f48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 0043dec5  8bb128050000           -mov esi, dword ptr [ecx + 0x528]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1320) /* 0x528 */);
    // 0043decb  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0043decd  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043decf  8b8120050000           -mov eax, dword ptr [ecx + 0x520]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1312) /* 0x520 */);
    // 0043ded5  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043ded7  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043deda  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043dedc  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0043dede  39c6                   +cmp esi, eax
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
    // 0043dee0  7f3d                   -jg 0x43df1f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0043df1f;
    }
L_0x0043dee2:
    // 0043dee2  83b92405000001         +cmp dword ptr [ecx + 0x524], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1316) /* 0x524 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043dee9  7530                   -jne 0x43df1b
    if (!cpu.flags.zf)
    {
        goto L_0x0043df1b;
    }
    // 0043deeb  8b8120050000           -mov eax, dword ptr [ecx + 0x520]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1312) /* 0x520 */);
    // 0043def1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043def3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043def6  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043def8  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0043defa  8b35480f5400           -mov esi, dword ptr [0x540f48]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 0043df00  2bb128050000           -sub esi, dword ptr [ecx + 0x528]
    (cpu.esi) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1320) /* 0x528 */)));
    // 0043df06  39c6                   +cmp esi, eax
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
    // 0043df08  7e11                   -jle 0x43df1b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043df1b;
    }
    // 0043df0a  8b819c030000           -mov eax, dword ptr [ecx + 0x39c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */);
    // 0043df10  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043df12  7e2a                   -jle 0x43df3e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043df3e;
    }
    // 0043df14  3d00001400             +cmp eax, 0x140000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1310720 /*0x140000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043df19  7c30                   -jl 0x43df4b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043df4b;
    }
L_0x0043df1b:
    // 0043df1b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043df1c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043df1d  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043df1e  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043df1f:
    // 0043df1f  c7812405000001000000   -mov dword ptr [ecx + 0x524], 1
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1316) /* 0x524 */) = 1 /*0x1*/;
    // 0043df29  a1480f5400             -mov eax, dword ptr [0x540f48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 0043df2e  899920050000           -mov dword ptr [ecx + 0x520], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1312) /* 0x520 */) = cpu.ebx;
    // 0043df34  898128050000           -mov dword ptr [ecx + 0x528], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1320) /* 0x528 */) = cpu.eax;
    // 0043df3a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043df3b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043df3c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043df3d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043df3e:
    // 0043df3e  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0043df40  3d00001400             +cmp eax, 0x140000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1310720 /*0x140000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043df45  7c04                   -jl 0x43df4b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043df4b;
    }
    // 0043df47  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043df48  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043df49  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043df4a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043df4b:
    // 0043df4b  c78124050000ffffffff   -mov dword ptr [ecx + 0x524], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1316) /* 0x524 */) = 4294967295 /*0xffffffff*/;
    // 0043df55  a1480f5400             -mov eax, dword ptr [0x540f48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 0043df5a  899920050000           -mov dword ptr [ecx + 0x520], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1312) /* 0x520 */) = cpu.ebx;
    // 0043df60  898128050000           -mov dword ptr [ecx + 0x528], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1320) /* 0x528 */) = cpu.eax;
    // 0043df66  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043df67  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043df68  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043df69  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43df70(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043df70  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043df71  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043df72  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043df73  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043df74  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043df75  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043df76  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0043df79  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0043df7b  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0043df7d  be10d94300             -mov esi, 0x43d910
    cpu.esi = 4446480 /*0x43d910*/;
    // 0043df82  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043df83  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043df84  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043df85  f680a903000010         +test byte ptr [eax + 0x3a9], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(937) /* 0x3a9 */) & 16 /*0x10*/));
    // 0043df8c  0f8482030000           -je 0x43e314
    if (cpu.flags.zf)
    {
        goto L_0x0043e314;
    }
    // 0043df92  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0043df97:
    // 0043df97  330528225100           +xor eax, dword ptr [0x512228]
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */)))));
    // 0043df9d  0f8478030000           -je 0x43e31b
    if (cpu.flags.zf)
    {
        goto L_0x0043e31b;
    }
    // 0043dfa3  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x0043dfa8:
    // 0043dfa8  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0043dfac  8b8d9c030000           -mov ecx, dword ptr [ebp + 0x39c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(924) /* 0x39c */);
    // 0043dfb2  c7855c05000000000000   -mov dword ptr [ebp + 0x55c], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1372) /* 0x55c */) = 0 /*0x0*/;
    // 0043dfbc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0043dfbe  0f8e61030000           -jle 0x43e325
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e325;
    }
    // 0043dfc4  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0043dfc6:
    // 0043dfc6  8b9d24050000           -mov ebx, dword ptr [ebp + 0x524]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1316) /* 0x524 */);
    // 0043dfcc  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043dfce  83fbff                 +cmp ebx, -1
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
    // 0043dfd1  0f8557030000           -jne 0x43e32e
    if (!cpu.flags.zf)
    {
        goto L_0x0043e32e;
    }
    // 0043dfd7  8b8598030000           -mov eax, dword ptr [ebp + 0x398]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(920) /* 0x398 */);
    // 0043dfdd  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0043dfdf  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0043dfe3  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
    // 0043dfe5  897c2410               -mov dword ptr [esp + 0x10], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edi;
L_0x0043dfe9:
    // 0043dfe9  8b5c240c               -mov ebx, dword ptr [esp + 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0043dfed  0faf1d98ac5000         -imul ebx, dword ptr [0x50ac98]
    cpu.ebx = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5287064) /* 0x50ac98 */))));
    // 0043dff4  8b5514                 -mov edx, dword ptr [ebp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(20) /* 0x14 */);
    // 0043dff7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0043dff9  e8e2140000             -call 0x43f4e0
    cpu.esp -= 4;
    sub_43f4e0(app, cpu);
    if (cpu.terminate) return;
    // 0043dffe  8b959c030000           -mov edx, dword ptr [ebp + 0x39c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(924) /* 0x39c */);
    // 0043e004  81fa0000feff           +cmp edx, 0xfffe0000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294836224 /*0xfffe0000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043e00a  0f8e2d030000           -jle 0x43e33d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e33d;
    }
    // 0043e010  81fa00000200           +cmp edx, 0x20000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(131072 /*0x20000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043e016  0f8d21030000           -jge 0x43e33d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e33d;
    }
    // 0043e01c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x0043e01e:
    // 0043e01e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043e020  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
L_0x0043e022:
    // 0043e022  8d8200010000           -lea eax, [edx + 0x100]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(256) /* 0x100 */);
    // 0043e028  8d8800010000           -lea ecx, [eax + 0x100]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(256) /* 0x100 */);
    // 0043e02e  c0e507                 +shl ch, 7
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
    // 0043e031  19d2                   -sbb edx, edx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043e033  00ed                   +add ch, ch
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
    // 0043e035  19c9                   -sbb ecx, ecx
    (cpu.ecx) -= x86::reg32(x86::sreg32(cpu.ecx) + cpu.flags.cf);
    // 0043e037  31c8                   -xor eax, ecx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043e039  25ff000000             -and eax, 0xff
    cpu.eax &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 0043e03e  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043e040  8b0485b4b64d00         -mov eax, dword ptr [eax*4 + 0x4db6b4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5093044) /* 0x4db6b4 */ + cpu.eax * 4);
    // 0043e047  31d0                   -xor eax, edx
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043e049  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043e04b  8d8800000100           -lea ecx, [eax + 0x10000]
    cpu.ecx = x86::reg32(cpu.eax + x86::reg32(65536) /* 0x10000 */);
    // 0043e051  81fe00001200           +cmp esi, 0x120000
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1179648 /*0x120000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043e057  7e23                   -jle 0x43e07c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e07c;
    }
    // 0043e059  ba00000100             -mov edx, 0x10000
    cpu.edx = 65536 /*0x10000*/;
    // 0043e05e  b8cc0c0000             -mov eax, 0xccc
    cpu.eax = 3276 /*0xccc*/;
    // 0043e063  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043e065  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043e067  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043e06a  c1e810                 +shr eax, 0x10
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
    // 0043e06d  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043e06f  ba00000100             -mov edx, 0x10000
    cpu.edx = 65536 /*0x10000*/;
    // 0043e074  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043e076  89955c050000           -mov dword ptr [ebp + 0x55c], edx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1372) /* 0x55c */) = cpu.edx;
L_0x0043e07c:
    // 0043e07c  b880000000             -mov eax, 0x80
    cpu.eax = 128 /*0x80*/;
    // 0043e081  8b9d10050000           -mov ebx, dword ptr [ebp + 0x510]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1296) /* 0x510 */);
    // 0043e087  8b15e8ac5000           -mov edx, dword ptr [0x50ace8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287144) /* 0x50ace8 */);
    // 0043e08d  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 0043e08f  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043e091  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043e094  c1e810                 +shr eax, 0x10
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
    // 0043e097  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043e099  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0043e09c  8b1decac5000           -mov ebx, dword ptr [0x50acec]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5287148) /* 0x50acec */);
    // 0043e0a2  39d8                   +cmp eax, ebx
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
    // 0043e0a4  0f8de6020000           -jge 0x43e390
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e390;
    }
L_0x0043e0aa:
    // 0043e0aa  8b15ecac5000           -mov edx, dword ptr [0x50acec]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287148) /* 0x50acec */);
    // 0043e0b0  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0043e0b2  39d0                   +cmp eax, edx
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
    // 0043e0b4  0f8edd020000           -jle 0x43e397
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e397;
    }
L_0x0043e0ba:
    // 0043e0ba  ba00000a00             -mov edx, 0xa0000
    cpu.edx = 655360 /*0xa0000*/;
    // 0043e0bf  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043e0c1  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043e0c3  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043e0c6  c1e810                 +shr eax, 0x10
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
    // 0043e0c9  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043e0cb  8b3ddcac5000           -mov edi, dword ptr [0x50acdc]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5287132) /* 0x50acdc */);
    // 0043e0d1  39f8                   +cmp eax, edi
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
    // 0043e0d3  0f8dc5020000           -jge 0x43e39e
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e39e;
    }
L_0x0043e0d9:
    // 0043e0d9  8b15dcac5000           -mov edx, dword ptr [0x50acdc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287132) /* 0x50acdc */);
    // 0043e0df  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0043e0e1  39d0                   +cmp eax, edx
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
    // 0043e0e3  0f8ebc020000           -jle 0x43e3a5
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e3a5;
    }
L_0x0043e0e9:
    // 0043e0e9  8b95a0030000           -mov edx, dword ptr [ebp + 0x3a0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(928) /* 0x3a0 */);
    // 0043e0ef  39d0                   +cmp eax, edx
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
    // 0043e0f1  0f8db5020000           -jge 0x43e3ac
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e3ac;
    }
L_0x0043e0f7:
    // 0043e0f7  8b95a0030000           -mov edx, dword ptr [ebp + 0x3a0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(928) /* 0x3a0 */);
    // 0043e0fd  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0043e0ff  39d0                   +cmp eax, edx
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
    // 0043e101  0f8eac020000           -jle 0x43e3b3
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e3b3;
    }
L_0x0043e107:
    // 0043e107  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043e109  a1f8ac5000             -mov eax, dword ptr [0x50acf8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5287160) /* 0x50acf8 */);
    // 0043e10e  8bbd9c030000           -mov edi, dword ptr [ebp + 0x39c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(924) /* 0x39c */);
    // 0043e114  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0043e116  39f8                   +cmp eax, edi
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
    // 0043e118  7d6c                   -jge 0x43e186
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e186;
    }
    // 0043e11a  3b3df8ac5000           +cmp edi, dword ptr [0x50acf8]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5287160) /* 0x50acf8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043e120  7d64                   -jge 0x43e186
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e186;
    }
    // 0043e122  8b15fcac5000           -mov edx, dword ptr [0x50acfc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287164) /* 0x50acfc */);
    // 0043e128  8b85a0030000           -mov eax, dword ptr [ebp + 0x3a0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(928) /* 0x3a0 */);
    // 0043e12e  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043e130  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043e133  c1e810                 +shr eax, 0x10
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
    // 0043e136  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043e138  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043e13a  0f8e7a020000           -jle 0x43e3ba
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e3ba;
    }
L_0x0043e140:
    // 0043e140  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043e142  39c3                   +cmp ebx, eax
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
    // 0043e144  7d02                   -jge 0x43e148
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e148;
    }
    // 0043e146  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0043e148:
    // 0043e148  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0043e14a  39d0                   +cmp eax, edx
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
    // 0043e14c  0f8e6f020000           -jle 0x43e3c1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e3c1;
    }
L_0x0043e152:
    // 0043e152  8b1500ad5000           -mov edx, dword ptr [0x50ad00]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287168) /* 0x50ad00 */);
    // 0043e158  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043e15a  8b85a0030000           -mov eax, dword ptr [ebp + 0x3a0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(928) /* 0x3a0 */);
    // 0043e160  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043e162  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043e165  c1e810                 +shr eax, 0x10
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
    // 0043e168  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043e16a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043e16c  0f8e56020000           -jle 0x43e3c8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e3c8;
    }
L_0x0043e172:
    // 0043e172  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043e174  39c6                   +cmp esi, eax
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
    // 0043e176  7d02                   -jge 0x43e17a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e17a;
    }
    // 0043e178  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0043e17a:
    // 0043e17a  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0043e17c  39d0                   +cmp eax, edx
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
    // 0043e17e  0f8e4b020000           -jle 0x43e3cf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e3cf;
    }
L_0x0043e184:
    // 0043e184  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0043e186:
    // 0043e186  8b85c0020000           -mov eax, dword ptr [ebp + 0x2c0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(704) /* 0x2c0 */);
    // 0043e18c  8b15f0ac5000           -mov edx, dword ptr [0x50acf0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287152) /* 0x50acf0 */);
    // 0043e192  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0043e194  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043e196  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043e199  c1e810                 +shr eax, 0x10
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
    // 0043e19c  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043e19e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043e1a0  8bb59c030000           -mov esi, dword ptr [ebp + 0x39c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(924) /* 0x39c */);
    // 0043e1a6  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0043e1a8  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0043e1aa  0f8e26020000           -jle 0x43e3d6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e3d6;
    }
    // 0043e1b0  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0043e1b2:
    // 0043e1b2  3d00001200             +cmp eax, 0x120000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1179648 /*0x120000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043e1b7  7e0b                   -jle 0x43e1c4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e1c4;
    }
    // 0043e1b9  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043e1bb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043e1be  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043e1c0  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 0043e1c2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0043e1c4:
    // 0043e1c4  8bbd54050000           -mov edi, dword ptr [ebp + 0x554]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1364) /* 0x554 */);
    // 0043e1ca  39fa                   +cmp edx, edi
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
    // 0043e1cc  0f8d0d020000           -jge 0x43e3df
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e3df;
    }
L_0x0043e1d2:
    // 0043e1d2  8b8554050000           -mov eax, dword ptr [ebp + 0x554]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1364) /* 0x554 */);
    // 0043e1d8  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0043e1da  39c2                   +cmp edx, eax
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
    // 0043e1dc  0f8e04020000           -jle 0x43e3e6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e3e6;
    }
L_0x0043e1e2:
    // 0043e1e2  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0043e1e4  8b85b0020000           -mov eax, dword ptr [ebp + 0x2b0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(688) /* 0x2b0 */);
    // 0043e1ea  8b15e0ac5000           -mov edx, dword ptr [0x50ace0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287136) /* 0x50ace0 */);
    // 0043e1f0  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043e1f2  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043e1f4  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043e1f7  c1e810                 +shr eax, 0x10
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
    // 0043e1fa  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043e1fc  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0043e1fe  8b9550050000           -mov edx, dword ptr [ebp + 0x550]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1360) /* 0x550 */);
    // 0043e204  39d0                   +cmp eax, edx
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
    // 0043e206  0f8de1010000           -jge 0x43e3ed
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e3ed;
    }
L_0x0043e20c:
    // 0043e20c  8b9550050000           -mov edx, dword ptr [ebp + 0x550]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1360) /* 0x550 */);
    // 0043e212  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0043e214  39d0                   +cmp eax, edx
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
    // 0043e216  0f8ed8010000           -jle 0x43e3f4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e3f4;
    }
L_0x0043e21c:
    // 0043e21c  8b9d98030000           -mov ebx, dword ptr [ebp + 0x398]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(920) /* 0x398 */);
    // 0043e222  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0043e224  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043e226  0f85cf010000           -jne 0x43e3fb
    if (!cpu.flags.zf)
    {
        goto L_0x0043e3fb;
    }
L_0x0043e22c:
    // 0043e22c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0043e22e  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043e230  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043e232  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043e235  c1e810                 +shr eax, 0x10
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
    // 0043e238  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043e23a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043e23c  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0043e23e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0043e240  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043e242  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043e245  c1e810                 +shr eax, 0x10
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
    // 0043e248  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043e24a  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0043e24c  81f900800000           +cmp ecx, 0x8000
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32768 /*0x8000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043e252  0f8d63020000           -jge 0x43e4bb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e4bb;
    }
    // 0043e258  ba00800000             -mov edx, 0x8000
    cpu.edx = 32768 /*0x8000*/;
L_0x0043e25d:
    // 0043e25d  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043e25f  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043e261  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043e264  c1e810                 +shr eax, 0x10
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
    // 0043e267  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043e269  8b959c030000           -mov edx, dword ptr [ebp + 0x39c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(924) /* 0x39c */);
    // 0043e26f  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043e271  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043e273  0f8e49020000           -jle 0x43e4c2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e4c2;
    }
    // 0043e279  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
L_0x0043e27b:
    // 0043e27b  3d00000f00             +cmp eax, 0xf0000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(983040 /*0xf0000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043e280  0f8e45020000           -jle 0x43e4cb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e4cb;
    }
    // 0043e286  898528030000           -mov dword ptr [ebp + 0x328], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(808) /* 0x328 */) = cpu.eax;
L_0x0043e28c:
    // 0043e28c  898524030000           -mov dword ptr [ebp + 0x324], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(804) /* 0x324 */) = cpu.eax;
    // 0043e292  c785a802000000000000   -mov dword ptr [ebp + 0x2a8], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(680) /* 0x2a8 */) = 0 /*0x0*/;
    // 0043e29c  c785c802000000000000   -mov dword ptr [ebp + 0x2c8], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(712) /* 0x2c8 */) = 0 /*0x0*/;
    // 0043e2a6  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0043e2a9  c785cc02000000000000   -mov dword ptr [ebp + 0x2cc], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(716) /* 0x2cc */) = 0 /*0x0*/;
    // 0043e2b3  01f8                   -add eax, edi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edi));
    // 0043e2b5  8985a4020000           -mov dword ptr [ebp + 0x2a4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(676) /* 0x2a4 */) = cpu.eax;
    // 0043e2bb  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0043e2bf  c785d002000000000000   -mov dword ptr [ebp + 0x2d0], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(720) /* 0x2d0 */) = 0 /*0x0*/;
    // 0043e2c9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043e2cb  8b8d9c030000           -mov ecx, dword ptr [ebp + 0x39c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(924) /* 0x39c */);
    // 0043e2d1  8985ac020000           -mov dword ptr [ebp + 0x2ac], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(684) /* 0x2ac */) = cpu.eax;
    // 0043e2d7  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 0043e2d9  0f8e01020000           -jle 0x43e4e0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e4e0;
    }
    // 0043e2df  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
L_0x0043e2e1:
    // 0043e2e1  3d00000200             +cmp eax, 0x20000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(131072 /*0x20000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043e2e6  7d02                   -jge 0x43e2ea
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e2ea;
    }
    // 0043e2e8  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0043e2ea:
    // 0043e2ea  c785a002000000000000   -mov dword ptr [ebp + 0x2a0], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(672) /* 0x2a0 */) = 0 /*0x0*/;
    // 0043e2f4  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0043e2f8  c7859802000000000000   -mov dword ptr [ebp + 0x298], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(664) /* 0x298 */) = 0 /*0x0*/;
    // 0043e302  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0043e304  89859c020000           -mov dword ptr [ebp + 0x29c], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(668) /* 0x29c */) = cpu.eax;
    // 0043e30a  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0043e30d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e30e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e30f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e310  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e311  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e312  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e313  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043e314:
    // 0043e314  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043e316  e97cfcffff             -jmp 0x43df97
    goto L_0x0043df97;
L_0x0043e31b:
    // 0043e31b  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043e320  e983fcffff             -jmp 0x43dfa8
    goto L_0x0043dfa8;
L_0x0043e325:
    // 0043e325  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043e327  f7d8                   +neg eax
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
    // 0043e329  e998fcffff             -jmp 0x43dfc6
    goto L_0x0043dfc6;
L_0x0043e32e:
    // 0043e32e  8b8598030000           -mov eax, dword ptr [ebp + 0x398]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(920) /* 0x398 */);
    // 0043e334  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0043e338  e9acfcffff             -jmp 0x43dfe9
    goto L_0x0043dfe9;
L_0x0043e33d:
    // 0043e33d  8b95b0000000           -mov edx, dword ptr [ebp + 0xb0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(176) /* 0xb0 */);
    // 0043e343  8b85a8000000           -mov eax, dword ptr [ebp + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(168) /* 0xa8 */);
    // 0043e349  e892f40500             -call 0x49d7e0
    cpu.esp -= 4;
    sub_49d7e0(app, cpu);
    if (cpu.terminate) return;
    // 0043e34e  8b952c050000           -mov edx, dword ptr [ebp + 0x52c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1324) /* 0x52c */);
    // 0043e354  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043e356  81fa00feffff           +cmp edx, 0xfffffe00
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294966784 /*0xfffffe00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043e35c  7d15                   -jge 0x43e373
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e373;
    }
    // 0043e35e  81c200040000           -add edx, 0x400
    (cpu.edx) += x86::reg32(x86::sreg32(1024 /*0x400*/));
L_0x0043e364:
    // 0043e364  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043e366  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043e368  0f8eb0fcffff           -jle 0x43e01e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e01e;
    }
    // 0043e36e  e9affcffff             -jmp 0x43e022
    goto L_0x0043e022;
L_0x0043e373:
    // 0043e373  81fa00020000           +cmp edx, 0x200
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043e379  7ee9                   -jle 0x43e364
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e364;
    }
    // 0043e37b  81ea00040000           -sub edx, 0x400
    (cpu.edx) -= x86::reg32(x86::sreg32(1024 /*0x400*/));
    // 0043e381  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043e383  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043e385  0f8e93fcffff           -jle 0x43e01e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e01e;
    }
    // 0043e38b  e992fcffff             -jmp 0x43e022
    goto L_0x0043e022;
L_0x0043e390:
    // 0043e390  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043e392  e913fdffff             -jmp 0x43e0aa
    goto L_0x0043e0aa;
L_0x0043e397:
    // 0043e397  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043e399  e91cfdffff             -jmp 0x43e0ba
    goto L_0x0043e0ba;
L_0x0043e39e:
    // 0043e39e  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0043e3a0  e934fdffff             -jmp 0x43e0d9
    goto L_0x0043e0d9;
L_0x0043e3a5:
    // 0043e3a5  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043e3a7  e93dfdffff             -jmp 0x43e0e9
    goto L_0x0043e0e9;
L_0x0043e3ac:
    // 0043e3ac  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043e3ae  e944fdffff             -jmp 0x43e0f7
    goto L_0x0043e0f7;
L_0x0043e3b3:
    // 0043e3b3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043e3b5  e94dfdffff             -jmp 0x43e107
    goto L_0x0043e107;
L_0x0043e3ba:
    // 0043e3ba  f7d8                   +neg eax
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
    // 0043e3bc  e97ffdffff             -jmp 0x43e140
    goto L_0x0043e140;
L_0x0043e3c1:
    // 0043e3c1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043e3c3  e98afdffff             -jmp 0x43e152
    goto L_0x0043e152;
L_0x0043e3c8:
    // 0043e3c8  f7d8                   +neg eax
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
    // 0043e3ca  e9a3fdffff             -jmp 0x43e172
    goto L_0x0043e172;
L_0x0043e3cf:
    // 0043e3cf  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043e3d1  e9aefdffff             -jmp 0x43e184
    goto L_0x0043e184;
L_0x0043e3d6:
    // 0043e3d6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043e3d8  f7d8                   +neg eax
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
    // 0043e3da  e9d3fdffff             -jmp 0x43e1b2
    goto L_0x0043e1b2;
L_0x0043e3df:
    // 0043e3df  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0043e3e1  e9ecfdffff             -jmp 0x43e1d2
    goto L_0x0043e1d2;
L_0x0043e3e6:
    // 0043e3e6  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043e3e8  e9f5fdffff             -jmp 0x43e1e2
    goto L_0x0043e1e2;
L_0x0043e3ed:
    // 0043e3ed  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043e3ef  e918feffff             -jmp 0x43e20c
    goto L_0x0043e20c;
L_0x0043e3f4:
    // 0043e3f4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043e3f6  e921feffff             -jmp 0x43e21c
    goto L_0x0043e21c;
L_0x0043e3fb:
    // 0043e3fb  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0043e3ff  8b85b8020000           -mov eax, dword ptr [ebp + 0x2b8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(696) /* 0x2b8 */);
    // 0043e405  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043e408  8b15f8ac5000           -mov edx, dword ptr [0x50acf8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287160) /* 0x50acf8 */);
    // 0043e40e  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0043e410  39c2                   +cmp edx, eax
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
    // 0043e412  7d04                   -jge 0x43e418
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e418;
    }
    // 0043e414  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043e416  7e36                   -jle 0x43e44e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e44e;
    }
L_0x0043e418:
    // 0043e418  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0043e41c  8b85b8020000           -mov eax, dword ptr [ebp + 0x2b8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(696) /* 0x2b8 */);
    // 0043e422  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043e425  3b05f8ac5000           +cmp eax, dword ptr [0x50acf8]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5287160) /* 0x50acf8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043e42b  7d0a                   -jge 0x43e437
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e437;
    }
    // 0043e42d  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043e42f  7c06                   -jl 0x43e437
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043e437;
    }
    // 0043e431  3b442410               +cmp eax, dword ptr [esp + 0x10]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043e435  7c1d                   -jl 0x43e454
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043e454;
    }
L_0x0043e437:
    // 0043e437  8b9d9c030000           -mov ebx, dword ptr [ebp + 0x39c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(924) /* 0x39c */);
    // 0043e43d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043e43f  7e2f                   -jle 0x43e470
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e470;
    }
    // 0043e441  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043e443  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043e445  7f38                   -jg 0x43e47f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0043e47f;
    }
    // 0043e447  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0043e449  e9defdffff             -jmp 0x43e22c
    goto L_0x0043e22c;
L_0x0043e44e:
    // 0043e44e  3b442410               +cmp eax, dword ptr [esp + 0x10]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043e452  7ec4                   -jle 0x43e418
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e418;
    }
L_0x0043e454:
    // 0043e454  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0043e456  e825170000             -call 0x43fb80
    cpu.esp -= 4;
    sub_43fb80(app, cpu);
    if (cpu.terminate) return;
    // 0043e45b  8b9d24050000           -mov ebx, dword ptr [ebp + 0x524]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1316) /* 0x524 */);
    // 0043e461  c685d802000000         -mov byte ptr [ebp + 0x2d8], 0
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(728) /* 0x2d8 */) = 0 /*0x0*/;
    // 0043e468  0fafd8                 +imul ebx, eax
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.ebx)) * x86::sreg64(x86::sreg32(cpu.eax));
        cpu.ebx = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.ebx)));
    }
    // 0043e46b  e9bcfdffff             -jmp 0x43e22c
    goto L_0x0043e22c;
L_0x0043e470:
    // 0043e470  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043e472  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0043e474  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043e476  7f07                   -jg 0x43e47f
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0043e47f;
    }
    // 0043e478  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0043e47a  e9adfdffff             -jmp 0x43e22c
    goto L_0x0043e22c;
L_0x0043e47f:
    // 0043e47f  8b9d98030000           -mov ebx, dword ptr [ebp + 0x398]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(920) /* 0x398 */);
    // 0043e485  2b9d9c030000           -sub ebx, dword ptr [ebp + 0x39c]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(924) /* 0x39c */)));
    // 0043e48b  8b95f4010000           -mov edx, dword ptr [ebp + 0x1f4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(500) /* 0x1f4 */);
    // 0043e491  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0043e493  83e208                 -and edx, 8
    cpu.edx &= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0043e496  e8b5180000             -call 0x43fd50
    cpu.esp -= 4;
    sub_43fd50(app, cpu);
    if (cpu.terminate) return;
    // 0043e49b  c685d8020000ff         -mov byte ptr [ebp + 0x2d8], 0xff
    app->getMemory<x86::reg8>(cpu.ebp + x86::reg32(728) /* 0x2d8 */) = 255 /*0xff*/;
    // 0043e4a2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043e4a4  8b85b8020000           -mov eax, dword ptr [ebp + 0x2b8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(696) /* 0x2b8 */);
    // 0043e4aa  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 0043e4ac  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043e4ae  0f8d78fdffff           -jge 0x43e22c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e22c;
    }
    // 0043e4b4  f7db                   +neg ebx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ebx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0043e4b6  e971fdffff             -jmp 0x43e22c
    goto L_0x0043e22c;
L_0x0043e4bb:
    // 0043e4bb  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0043e4bd  e99bfdffff             -jmp 0x43e25d
    goto L_0x0043e25d;
L_0x0043e4c2:
    // 0043e4c2  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043e4c4  f7d8                   +neg eax
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
    // 0043e4c6  e9b0fdffff             -jmp 0x43e27b
    goto L_0x0043e27b;
L_0x0043e4cb:
    // 0043e4cb  c7852803000000000000   -mov dword ptr [ebp + 0x328], 0
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(808) /* 0x328 */) = 0 /*0x0*/;
    // 0043e4d5  8b8528030000           -mov eax, dword ptr [ebp + 0x328]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(808) /* 0x328 */);
    // 0043e4db  e9acfdffff             -jmp 0x43e28c
    goto L_0x0043e28c;
L_0x0043e4e0:
    // 0043e4e0  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043e4e2  f7d8                   +neg eax
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
    // 0043e4e4  e9f8fdffff             -jmp 0x43e2e1
    goto L_0x0043e2e1;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43e4f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043e4f0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043e4f1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043e4f2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043e4f3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043e4f4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043e4f5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043e4f6  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0043e4f9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043e4fb  f680a903000010         +test byte ptr [eax + 0x3a9], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(937) /* 0x3a9 */) & 16 /*0x10*/));
    // 0043e502  0f8424030000           -je 0x43e82c
    if (cpu.flags.zf)
    {
        goto L_0x0043e82c;
    }
    // 0043e508  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0043e50d:
    // 0043e50d  330528225100           +xor eax, dword ptr [0x512228]
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */)))));
    // 0043e513  0f841a030000           -je 0x43e833
    if (cpu.flags.zf)
    {
        goto L_0x0043e833;
    }
    // 0043e519  beffffffff             -mov esi, 0xffffffff
    cpu.esi = 4294967295 /*0xffffffff*/;
L_0x0043e51e:
    // 0043e51e  8b91ac030000           -mov edx, dword ptr [ecx + 0x3ac]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(940) /* 0x3ac */);
    // 0043e524  8b8148050000           -mov eax, dword ptr [ecx + 0x548]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1352) /* 0x548 */);
    // 0043e52a  bf00000100             -mov edi, 0x10000
    cpu.edi = 65536 /*0x10000*/;
    // 0043e52f  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043e531  c7815c05000000000000   -mov dword ptr [ecx + 0x55c], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1372) /* 0x55c */) = 0 /*0x0*/;
    // 0043e53b  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0043e53e  8b81b8020000           -mov eax, dword ptr [ecx + 0x2b8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(696) /* 0x2b8 */);
    // 0043e544  ba62000000             -mov edx, 0x62
    cpu.edx = 98 /*0x62*/;
    // 0043e549  8ba938050000           -mov ebp, dword ptr [ecx + 0x538]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1336) /* 0x538 */);
    // 0043e54f  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043e551  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043e554  c1e810                 +shr eax, 0x10
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
    // 0043e557  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043e559  8d1c38                 -lea ebx, [eax + edi]
    cpu.ebx = x86::reg32(cpu.eax + cpu.edi * 1);
    // 0043e55c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0043e55e  8b8150050000           -mov eax, dword ptr [ecx + 0x550]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1360) /* 0x550 */);
    // 0043e564  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043e566  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043e569  c1e810                 +shr eax, 0x10
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
    // 0043e56c  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043e56e  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0043e572  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0043e576  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0043e578  a1b4ac5000             -mov eax, dword ptr [0x50acb4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5287092) /* 0x50acb4 */);
    // 0043e57d  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043e57f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043e582  c1e810                 +shr eax, 0x10
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
    // 0043e585  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043e587  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043e589  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0043e58d  8b8158050000           -mov eax, dword ptr [ecx + 0x558]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1368) /* 0x558 */);
    // 0043e593  39f8                   +cmp eax, edi
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
    // 0043e595  7e28                   -jle 0x43e5bf
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e5bf;
    }
    // 0043e597  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0043e59b  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043e59d  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043e5a0  c1e810                 +shr eax, 0x10
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
    // 0043e5a3  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043e5a5  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0043e5a9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0043e5ab  8b8158050000           -mov eax, dword ptr [ecx + 0x558]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1368) /* 0x558 */);
    // 0043e5b1  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043e5b3  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043e5b6  c1e810                 +shr eax, 0x10
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
    // 0043e5b9  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043e5bb  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x0043e5bf:
    // 0043e5bf  8b15bcac5000           -mov edx, dword ptr [0x50acbc]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287100) /* 0x50acbc */);
    // 0043e5c5  8b8198030000           -mov eax, dword ptr [ecx + 0x398]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(920) /* 0x398 */);
    // 0043e5cb  8b9910050000           -mov ebx, dword ptr [ecx + 0x510]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1296) /* 0x510 */);
    // 0043e5d1  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0043e5d5  b880000000             -mov eax, 0x80
    cpu.eax = 128 /*0x80*/;
    // 0043e5da  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 0043e5dc  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043e5de  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043e5e1  c1e810                 +shr eax, 0x10
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
    // 0043e5e4  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043e5e6  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 0043e5e9  8b15c0ac5000           -mov edx, dword ptr [0x50acc0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287104) /* 0x50acc0 */);
    // 0043e5ef  39d0                   +cmp eax, edx
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
    // 0043e5f1  0f8d46020000           -jge 0x43e83d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e83d;
    }
L_0x0043e5f7:
    // 0043e5f7  8b15c0ac5000           -mov edx, dword ptr [0x50acc0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287104) /* 0x50acc0 */);
    // 0043e5fd  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0043e5ff  39d0                   +cmp eax, edx
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
    // 0043e601  0f8e3d020000           -jle 0x43e844
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e844;
    }
L_0x0043e607:
    // 0043e607  8b15acac5000           -mov edx, dword ptr [0x50acac]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287084) /* 0x50acac */);
    // 0043e60d  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0043e611  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0043e614  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043e616  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043e619  c1e810                 +shr eax, 0x10
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
    // 0043e61c  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043e61e  8b1db0ac5000           -mov ebx, dword ptr [0x50acb0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5287088) /* 0x50acb0 */);
    // 0043e624  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0043e626  39d8                   +cmp eax, ebx
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
    // 0043e628  0f8d1d020000           -jge 0x43e84b
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e84b;
    }
L_0x0043e62e:
    // 0043e62e  8b1db0ac5000           -mov ebx, dword ptr [0x50acb0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5287088) /* 0x50acb0 */);
    // 0043e634  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 0043e636  39d8                   +cmp eax, ebx
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
    // 0043e638  0f8e14020000           -jle 0x43e852
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e852;
    }
L_0x0043e63e:
    // 0043e63e  8b91a0030000           -mov edx, dword ptr [ecx + 0x3a0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(928) /* 0x3a0 */);
    // 0043e644  39d0                   +cmp eax, edx
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
    // 0043e646  0f8d0d020000           -jge 0x43e859
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e859;
    }
L_0x0043e64c:
    // 0043e64c  8b99a0030000           -mov ebx, dword ptr [ecx + 0x3a0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(928) /* 0x3a0 */);
    // 0043e652  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 0043e654  39d8                   +cmp eax, ebx
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
    // 0043e656  0f8e04020000           -jle 0x43e860
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e860;
    }
L_0x0043e65c:
    // 0043e65c  8944241c               -mov dword ptr [esp + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0043e660  a1ccac5000             -mov eax, dword ptr [0x50accc]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5287116) /* 0x50accc */);
    // 0043e665  8b999c030000           -mov ebx, dword ptr [ecx + 0x39c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */);
    // 0043e66b  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0043e66d  39d8                   +cmp eax, ebx
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
    // 0043e66f  0f8d7a000000           -jge 0x43e6ef
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e6ef;
    }
    // 0043e675  3b1dccac5000           +cmp ebx, dword ptr [0x50accc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5287116) /* 0x50accc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043e67b  7d72                   -jge 0x43e6ef
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e6ef;
    }
    // 0043e67d  8b15d0ac5000           -mov edx, dword ptr [0x50acd0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287120) /* 0x50acd0 */);
    // 0043e683  8b81a0030000           -mov eax, dword ptr [ecx + 0x3a0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(928) /* 0x3a0 */);
    // 0043e689  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043e68b  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043e68e  c1e810                 +shr eax, 0x10
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
    // 0043e691  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043e693  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043e695  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043e697  0f8eca010000           -jle 0x43e867
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e867;
    }
L_0x0043e69d:
    // 0043e69d  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0043e6a1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043e6a3  39d3                   +cmp ebx, edx
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
    // 0043e6a5  7e02                   -jle 0x43e6a9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e6a9;
    }
    // 0043e6a7  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x0043e6a9:
    // 0043e6a9  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0043e6ab  39c3                   +cmp ebx, eax
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
    // 0043e6ad  0f8ebb010000           -jle 0x43e86e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e86e;
    }
L_0x0043e6b3:
    // 0043e6b3  8b15d4ac5000           -mov edx, dword ptr [0x50acd4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287124) /* 0x50acd4 */);
    // 0043e6b9  8b81a0030000           -mov eax, dword ptr [ecx + 0x3a0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(928) /* 0x3a0 */);
    // 0043e6bf  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043e6c1  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043e6c4  c1e810                 +shr eax, 0x10
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
    // 0043e6c7  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043e6c9  895c241c               -mov dword ptr [esp + 0x1c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.ebx;
    // 0043e6cd  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043e6cf  0f8ea0010000           -jle 0x43e875
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e875;
    }
L_0x0043e6d5:
    // 0043e6d5  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0043e6d9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043e6db  39d8                   +cmp eax, ebx
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
    // 0043e6dd  7e02                   -jle 0x43e6e1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e6e1;
    }
    // 0043e6df  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0043e6e1:
    // 0043e6e1  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0043e6e3  39d0                   +cmp eax, edx
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
    // 0043e6e5  0f8e91010000           -jle 0x43e87c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e87c;
    }
L_0x0043e6eb:
    // 0043e6eb  89442420               -mov dword ptr [esp + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.eax;
L_0x0043e6ef:
    // 0043e6ef  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0043e6f3  8b81c0020000           -mov eax, dword ptr [ecx + 0x2c0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(704) /* 0x2c0 */);
    // 0043e6f9  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043e6fb  8b15c4ac5000           -mov edx, dword ptr [0x50acc4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287108) /* 0x50acc4 */);
    // 0043e701  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043e703  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043e706  c1e810                 +shr eax, 0x10
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
    // 0043e709  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043e70b  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 0043e70d  8b9954050000           -mov ebx, dword ptr [ecx + 0x554]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1364) /* 0x554 */);
    // 0043e713  39d8                   +cmp eax, ebx
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
    // 0043e715  0f8d68010000           -jge 0x43e883
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e883;
    }
L_0x0043e71b:
    // 0043e71b  8b9954050000           -mov ebx, dword ptr [ecx + 0x554]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1364) /* 0x554 */);
    // 0043e721  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 0043e723  39d8                   +cmp eax, ebx
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
    // 0043e725  0f8e5f010000           -jle 0x43e88a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e88a;
    }
L_0x0043e72b:
    // 0043e72b  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0043e72f  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0043e733  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0043e735  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043e737  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0043e73b  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043e73d  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043e740  c1e810                 +shr eax, 0x10
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
    // 0043e743  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043e745  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0043e747  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0043e749  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043e74c  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0043e750  39d8                   +cmp eax, ebx
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
    // 0043e752  0f8d39010000           -jge 0x43e891
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e891;
    }
L_0x0043e758:
    // 0043e758  8b5c2418               -mov ebx, dword ptr [esp + 0x18]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0043e75c  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 0043e75e  39d8                   +cmp eax, ebx
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
    // 0043e760  0f8e32010000           -jle 0x43e898
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e898;
    }
L_0x0043e766:
    // 0043e766  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0043e76a  837c241400             +cmp dword ptr [esp + 0x14], 0
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
    // 0043e76f  0f852a010000           -jne 0x43e89f
    if (!cpu.flags.zf)
    {
        goto L_0x0043e89f;
    }
    // 0043e775  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0043e777:
    // 0043e777  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0043e779  0f8e83010000           -jle 0x43e902
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e902;
    }
L_0x0043e77f:
    // 0043e77f  8b15a8ac5000           -mov edx, dword ptr [0x50aca8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287080) /* 0x50aca8 */);
    // 0043e785  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0043e787  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043e789  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043e78b  0f8e78010000           -jle 0x43e909
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e909;
    }
    // 0043e791  898128030000           -mov dword ptr [ecx + 0x328], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(808) /* 0x328 */) = cpu.eax;
L_0x0043e797:
    // 0043e797  898124030000           -mov dword ptr [ecx + 0x324], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(804) /* 0x324 */) = cpu.eax;
    // 0043e79d  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0043e7a1  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0043e7a3  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043e7a5  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043e7a8  c1e810                 +shr eax, 0x10
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
    // 0043e7ab  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043e7ad  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0043e7af  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0043e7b1  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043e7b3  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043e7b5  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043e7b8  c1e810                 +shr eax, 0x10
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
    // 0043e7bb  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043e7bd  f681a903000010         +test byte ptr [ecx + 0x3a9], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(937) /* 0x3a9 */) & 16 /*0x10*/));
    // 0043e7c4  0f8554010000           -jne 0x43e91e
    if (!cpu.flags.zf)
    {
        goto L_0x0043e91e;
    }
    // 0043e7ca  0fafee                 -imul ebp, esi
    cpu.ebp = x86::reg32(x86::sreg64(x86::sreg32(cpu.ebp)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0043e7cd  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0043e7d0  c781a802000000000000   -mov dword ptr [ecx + 0x2a8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(680) /* 0x2a8 */) = 0 /*0x0*/;
    // 0043e7da  c781ac02000000000000   -mov dword ptr [ecx + 0x2ac], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(684) /* 0x2ac */) = 0 /*0x0*/;
    // 0043e7e4  c781cc02000000000000   -mov dword ptr [ecx + 0x2cc], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(716) /* 0x2cc */) = 0 /*0x0*/;
    // 0043e7ee  c781a402000000000000   -mov dword ptr [ecx + 0x2a4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(676) /* 0x2a4 */) = 0 /*0x0*/;
    // 0043e7f8  89a9c8020000           -mov dword ptr [ecx + 0x2c8], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(712) /* 0x2c8 */) = cpu.ebp;
    // 0043e7fe  8981d0020000           -mov dword ptr [ecx + 0x2d0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(720) /* 0x2d0 */) = cpu.eax;
L_0x0043e804:
    // 0043e804  c781a002000000000000   -mov dword ptr [ecx + 0x2a0], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(672) /* 0x2a0 */) = 0 /*0x0*/;
    // 0043e80e  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0043e812  c7819802000000000000   -mov dword ptr [ecx + 0x298], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(664) /* 0x298 */) = 0 /*0x0*/;
    // 0043e81c  89819c020000           -mov dword ptr [ecx + 0x29c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(668) /* 0x29c */) = cpu.eax;
    // 0043e822  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0043e825  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e826  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e827  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e828  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e829  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e82a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e82b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043e82c:
    // 0043e82c  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043e82e  e9dafcffff             -jmp 0x43e50d
    goto L_0x0043e50d;
L_0x0043e833:
    // 0043e833  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 0043e838  e9e1fcffff             -jmp 0x43e51e
    goto L_0x0043e51e;
L_0x0043e83d:
    // 0043e83d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043e83f  e9b3fdffff             -jmp 0x43e5f7
    goto L_0x0043e5f7;
L_0x0043e844:
    // 0043e844  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043e846  e9bcfdffff             -jmp 0x43e607
    goto L_0x0043e607;
L_0x0043e84b:
    // 0043e84b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043e84d  e9dcfdffff             -jmp 0x43e62e
    goto L_0x0043e62e;
L_0x0043e852:
    // 0043e852  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043e854  e9e5fdffff             -jmp 0x43e63e
    goto L_0x0043e63e;
L_0x0043e859:
    // 0043e859  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043e85b  e9ecfdffff             -jmp 0x43e64c
    goto L_0x0043e64c;
L_0x0043e860:
    // 0043e860  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043e862  e9f5fdffff             -jmp 0x43e65c
    goto L_0x0043e65c;
L_0x0043e867:
    // 0043e867  f7db                   +neg ebx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ebx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0043e869  e92ffeffff             -jmp 0x43e69d
    goto L_0x0043e69d;
L_0x0043e86e:
    // 0043e86e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043e870  e93efeffff             -jmp 0x43e6b3
    goto L_0x0043e6b3;
L_0x0043e875:
    // 0043e875  f7d8                   +neg eax
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
    // 0043e877  e959feffff             -jmp 0x43e6d5
    goto L_0x0043e6d5;
L_0x0043e87c:
    // 0043e87c  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043e87e  e968feffff             -jmp 0x43e6eb
    goto L_0x0043e6eb;
L_0x0043e883:
    // 0043e883  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043e885  e991feffff             -jmp 0x43e71b
    goto L_0x0043e71b;
L_0x0043e88a:
    // 0043e88a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043e88c  e99afeffff             -jmp 0x43e72b
    goto L_0x0043e72b;
L_0x0043e891:
    // 0043e891  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043e893  e9c0feffff             -jmp 0x43e758
    goto L_0x0043e758;
L_0x0043e898:
    // 0043e898  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043e89a  e9c7feffff             -jmp 0x43e766
    goto L_0x0043e766;
L_0x0043e89f:
    // 0043e89f  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0043e8a3  0fafd6                 -imul edx, esi
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0043e8a6  8b819c030000           -mov eax, dword ptr [ecx + 0x39c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */);
    // 0043e8ac  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0043e8af  39c2                   +cmp edx, eax
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
    // 0043e8b1  7e15                   -jle 0x43e8c8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e8c8;
    }
    // 0043e8b3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043e8b5  e8c6120000             -call 0x43fb80
    cpu.esp -= 4;
    sub_43fb80(app, cpu);
    if (cpu.terminate) return;
    // 0043e8ba  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043e8bc  c681d802000000         -mov byte ptr [ecx + 0x2d8], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(728) /* 0x2d8 */) = 0 /*0x0*/;
    // 0043e8c3  e9affeffff             -jmp 0x43e777
    goto L_0x0043e777;
L_0x0043e8c8:
    // 0043e8c8  8b5c2414               -mov ebx, dword ptr [esp + 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0043e8cc  2b999c030000           -sub ebx, dword ptr [ecx + 0x39c]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */)));
    // 0043e8d2  8b91f4010000           -mov edx, dword ptr [ecx + 0x1f4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(500) /* 0x1f4 */);
    // 0043e8d8  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043e8da  83e208                 -and edx, 8
    cpu.edx &= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0043e8dd  e86e140000             -call 0x43fd50
    cpu.esp -= 4;
    sub_43fd50(app, cpu);
    if (cpu.terminate) return;
    // 0043e8e2  c681d8020000ff         -mov byte ptr [ecx + 0x2d8], 0xff
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(728) /* 0x2d8 */) = 255 /*0xff*/;
    // 0043e8e9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043e8eb  8b81b8020000           -mov eax, dword ptr [ecx + 0x2b8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(696) /* 0x2b8 */);
    // 0043e8f1  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 0043e8f3  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043e8f5  0f8d7cfeffff           -jge 0x43e777
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e777;
    }
    // 0043e8fb  f7db                   +neg ebx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ebx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0043e8fd  e975feffff             -jmp 0x43e777
    goto L_0x0043e777;
L_0x0043e902:
    // 0043e902  f7dd                   +neg ebp
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ebp;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0043e904  e976feffff             -jmp 0x43e77f
    goto L_0x0043e77f;
L_0x0043e909:
    // 0043e909  c7812803000000000000   -mov dword ptr [ecx + 0x328], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(808) /* 0x328 */) = 0 /*0x0*/;
    // 0043e913  8b8128030000           -mov eax, dword ptr [ecx + 0x328]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(808) /* 0x328 */);
    // 0043e919  e979feffff             -jmp 0x43e797
    goto L_0x0043e797;
L_0x0043e91e:
    // 0043e91e  c781a802000000000000   -mov dword ptr [ecx + 0x2a8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(680) /* 0x2a8 */) = 0 /*0x0*/;
    // 0043e928  c781c802000000000000   -mov dword ptr [ecx + 0x2c8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(712) /* 0x2c8 */) = 0 /*0x0*/;
    // 0043e932  c781cc02000000000000   -mov dword ptr [ecx + 0x2cc], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(716) /* 0x2cc */) = 0 /*0x0*/;
    // 0043e93c  c781d002000000000000   -mov dword ptr [ecx + 0x2d0], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(720) /* 0x2d0 */) = 0 /*0x0*/;
    // 0043e946  8981ac020000           -mov dword ptr [ecx + 0x2ac], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(684) /* 0x2ac */) = cpu.eax;
    // 0043e94c  89a9a4020000           -mov dword ptr [ecx + 0x2a4], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(676) /* 0x2a4 */) = cpu.ebp;
    // 0043e952  e9adfeffff             -jmp 0x43e804
    goto L_0x0043e804;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43e960(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043e960  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043e961  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043e962  8b9010050000           -mov edx, dword ptr [eax + 0x510]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1296) /* 0x510 */);
    // 0043e968  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043e96a  7e32                   -jle 0x43e99e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e99e;
    }
L_0x0043e96c:
    // 0043e96c  83fa73                 +cmp edx, 0x73
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(115 /*0x73*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043e96f  7f25                   -jg 0x43e996
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0043e996;
    }
    // 0043e971  83b824050000ff         +cmp dword ptr [eax + 0x524], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1316) /* 0x524 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043e978  741c                   -je 0x43e996
    if (cpu.flags.zf)
    {
        goto L_0x0043e996;
    }
    // 0043e97a  8b989c030000           -mov ebx, dword ptr [eax + 0x39c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(924) /* 0x39c */);
    // 0043e980  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043e982  7e1e                   -jle 0x43e9a2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043e9a2;
    }
    // 0043e984  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0043e986:
    // 0043e986  8b15f8ac5000           -mov edx, dword ptr [0x50acf8]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287160) /* 0x50acf8 */);
    // 0043e98c  81ea00000300           -sub edx, 0x30000
    (cpu.edx) -= x86::reg32(x86::sreg32(196608 /*0x30000*/));
    // 0043e992  39d0                   +cmp eax, edx
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
    // 0043e994  7d12                   -jge 0x43e9a8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043e9a8;
    }
L_0x0043e996:
    // 0043e996  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043e99b  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e99c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e99d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043e99e:
    // 0043e99e  f7da                   +neg edx
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
    // 0043e9a0  ebca                   -jmp 0x43e96c
    goto L_0x0043e96c;
L_0x0043e9a2:
    // 0043e9a2  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043e9a4  f7d8                   +neg eax
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
    // 0043e9a6  ebde                   -jmp 0x43e986
    goto L_0x0043e986;
L_0x0043e9a8:
    // 0043e9a8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043e9aa  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e9ab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043e9ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_43e9b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043e9b0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043e9b1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043e9b2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043e9b3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043e9b4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043e9b5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043e9b6  83ec54                 -sub esp, 0x54
    (cpu.esp) -= x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0043e9b9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043e9bb  8b80d0020000           -mov eax, dword ptr [eax + 0x2d0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(720) /* 0x2d0 */);
    // 0043e9c1  8b91ac020000           -mov edx, dword ptr [ecx + 0x2ac]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(684) /* 0x2ac */);
    // 0043e9c7  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043e9c9  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043e9cb  8991ac020000           -mov dword ptr [ecx + 0x2ac], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(684) /* 0x2ac */) = cpu.edx;
    // 0043e9d1  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043e9d3  e8984c0100             -call 0x453670
    cpu.esp -= 4;
    sub_453670(app, cpu);
    if (cpu.terminate) return;
    // 0043e9d8  8b81d0020000           -mov eax, dword ptr [ecx + 0x2d0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(720) /* 0x2d0 */);
    // 0043e9de  8b99ac020000           -mov ebx, dword ptr [ecx + 0x2ac]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(684) /* 0x2ac */);
    // 0043e9e4  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 0043e9e6  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043e9e8  8d81c4000000           -lea eax, [ecx + 0xc4]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(196) /* 0xc4 */);
    // 0043e9ee  8999ac020000           -mov dword ptr [ecx + 0x2ac], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(684) /* 0x2ac */) = cpu.ebx;
    // 0043e9f4  e897ee0500             -call 0x49d890
    cpu.esp -= 4;
    sub_49d890(app, cpu);
    if (cpu.terminate) return;
    // 0043e9f9  8d542424               -lea edx, [esp + 0x24]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0043e9fd  8d8118010000           -lea eax, [ecx + 0x118]
    cpu.eax = x86::reg32(cpu.ecx + x86::reg32(280) /* 0x118 */);
    // 0043ea03  e888ee0500             -call 0x49d890
    cpu.esp -= 4;
    sub_49d890(app, cpu);
    if (cpu.terminate) return;
    // 0043ea08  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0043ea0b  8b81a4020000           -mov eax, dword ptr [ecx + 0x2a4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(676) /* 0x2a4 */);
    // 0043ea11  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ea13  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ea16  c1e810                 +shr eax, 0x10
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
    // 0043ea19  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ea1b  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0043ea1f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043ea21  8b81a8020000           -mov eax, dword ptr [ecx + 0x2a8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(680) /* 0x2a8 */);
    // 0043ea27  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ea29  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ea2c  c1e810                 +shr eax, 0x10
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
    // 0043ea2f  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ea31  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0043ea35  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043ea37  8b81ac020000           -mov eax, dword ptr [ecx + 0x2ac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(684) /* 0x2ac */);
    // 0043ea3d  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ea3f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ea42  c1e810                 +shr eax, 0x10
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
    // 0043ea45  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ea47  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043ea49  89998c020000           -mov dword ptr [ecx + 0x28c], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(652) /* 0x28c */) = cpu.ebx;
    // 0043ea4f  8b81a4020000           -mov eax, dword ptr [ecx + 0x2a4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(676) /* 0x2a4 */);
    // 0043ea55  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0043ea59  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ea5b  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ea5e  c1e810                 +shr eax, 0x10
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
    // 0043ea61  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ea63  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0043ea67  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043ea69  8b81a8020000           -mov eax, dword ptr [ecx + 0x2a8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(680) /* 0x2a8 */);
    // 0043ea6f  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ea71  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ea74  c1e810                 +shr eax, 0x10
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
    // 0043ea77  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ea79  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0043ea7d  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043ea7f  8b81ac020000           -mov eax, dword ptr [ecx + 0x2ac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(684) /* 0x2ac */);
    // 0043ea85  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ea87  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ea8a  c1e810                 +shr eax, 0x10
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
    // 0043ea8d  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ea8f  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043ea91  899990020000           -mov dword ptr [ecx + 0x290], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(656) /* 0x290 */) = cpu.ebx;
    // 0043ea97  8b81a4020000           -mov eax, dword ptr [ecx + 0x2a4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(676) /* 0x2a4 */);
    // 0043ea9d  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0043eaa1  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043eaa3  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043eaa6  c1e810                 +shr eax, 0x10
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
    // 0043eaa9  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043eaab  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0043eaaf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043eab1  8b81a8020000           -mov eax, dword ptr [ecx + 0x2a8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(680) /* 0x2a8 */);
    // 0043eab7  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043eab9  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043eabc  c1e810                 +shr eax, 0x10
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
    // 0043eabf  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043eac1  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0043eac5  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043eac7  8b81ac020000           -mov eax, dword ptr [ecx + 0x2ac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(684) /* 0x2ac */);
    // 0043eacd  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043eacf  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ead2  c1e810                 +shr eax, 0x10
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
    // 0043ead5  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ead7  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043ead9  899994020000           -mov dword ptr [ecx + 0x294], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(660) /* 0x294 */) = cpu.ebx;
    // 0043eadf  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0043eae3  8b81c8020000           -mov eax, dword ptr [ecx + 0x2c8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(712) /* 0x2c8 */);
    // 0043eae9  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043eaeb  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043eaee  c1e810                 +shr eax, 0x10
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
    // 0043eaf1  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043eaf3  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0043eaf7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043eaf9  8b81cc020000           -mov eax, dword ptr [ecx + 0x2cc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(716) /* 0x2cc */);
    // 0043eaff  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043eb01  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043eb04  c1e810                 +shr eax, 0x10
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
    // 0043eb07  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043eb09  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0043eb0d  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043eb0f  8b81d0020000           -mov eax, dword ptr [ecx + 0x2d0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(720) /* 0x2d0 */);
    // 0043eb15  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043eb17  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043eb1a  c1e810                 +shr eax, 0x10
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
    // 0043eb1d  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043eb1f  8bb18c020000           -mov esi, dword ptr [ecx + 0x28c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(652) /* 0x28c */);
    // 0043eb25  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043eb27  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043eb29  89b18c020000           -mov dword ptr [ecx + 0x28c], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(652) /* 0x28c */) = cpu.esi;
    // 0043eb2f  8b81c8020000           -mov eax, dword ptr [ecx + 0x2c8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(712) /* 0x2c8 */);
    // 0043eb35  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0043eb39  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043eb3b  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043eb3e  c1e810                 +shr eax, 0x10
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
    // 0043eb41  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043eb43  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 0043eb47  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043eb49  8b81cc020000           -mov eax, dword ptr [ecx + 0x2cc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(716) /* 0x2cc */);
    // 0043eb4f  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043eb51  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043eb54  c1e810                 +shr eax, 0x10
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
    // 0043eb57  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043eb59  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 0043eb5d  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043eb5f  8b81d0020000           -mov eax, dword ptr [ecx + 0x2d0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(720) /* 0x2d0 */);
    // 0043eb65  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043eb67  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043eb6a  c1e810                 +shr eax, 0x10
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
    // 0043eb6d  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043eb6f  8bb990020000           -mov edi, dword ptr [ecx + 0x290]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(656) /* 0x290 */);
    // 0043eb75  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043eb77  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043eb79  89b990020000           -mov dword ptr [ecx + 0x290], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(656) /* 0x290 */) = cpu.edi;
    // 0043eb7f  8b81c8020000           -mov eax, dword ptr [ecx + 0x2c8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(712) /* 0x2c8 */);
    // 0043eb85  8b54243c               -mov edx, dword ptr [esp + 0x3c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(60) /* 0x3c */);
    // 0043eb89  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043eb8b  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043eb8e  c1e810                 +shr eax, 0x10
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
    // 0043eb91  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043eb93  8b542440               -mov edx, dword ptr [esp + 0x40]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(64) /* 0x40 */);
    // 0043eb97  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043eb99  8b81cc020000           -mov eax, dword ptr [ecx + 0x2cc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(716) /* 0x2cc */);
    // 0043eb9f  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043eba1  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043eba4  c1e810                 +shr eax, 0x10
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
    // 0043eba7  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043eba9  8b542444               -mov edx, dword ptr [esp + 0x44]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(68) /* 0x44 */);
    // 0043ebad  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043ebaf  8b81d0020000           -mov eax, dword ptr [ecx + 0x2d0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(720) /* 0x2d0 */);
    // 0043ebb5  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ebb7  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ebba  c1e810                 +shr eax, 0x10
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
    // 0043ebbd  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ebbf  8ba994020000           -mov ebp, dword ptr [ecx + 0x294]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(660) /* 0x294 */);
    // 0043ebc5  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043ebc7  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043ebc9  89a994020000           -mov dword ptr [ecx + 0x294], ebp
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(660) /* 0x294 */) = cpu.ebp;
    // 0043ebcf  8b8198020000           -mov eax, dword ptr [ecx + 0x298]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(664) /* 0x298 */);
    // 0043ebd5  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0043ebd8  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ebda  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ebdd  c1e810                 +shr eax, 0x10
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
    // 0043ebe0  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ebe2  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0043ebe6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043ebe8  8b819c020000           -mov eax, dword ptr [ecx + 0x29c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(668) /* 0x29c */);
    // 0043ebee  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ebf0  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ebf3  c1e810                 +shr eax, 0x10
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
    // 0043ebf6  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ebf8  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0043ebfc  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043ebfe  8b81a0020000           -mov eax, dword ptr [ecx + 0x2a0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(672) /* 0x2a0 */);
    // 0043ec04  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ec06  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ec09  c1e810                 +shr eax, 0x10
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
    // 0043ec0c  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ec0e  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043ec10  895c2448               -mov dword ptr [esp + 0x48], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(72) /* 0x48 */) = cpu.ebx;
    // 0043ec14  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0043ec18  8b8198020000           -mov eax, dword ptr [ecx + 0x298]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(664) /* 0x298 */);
    // 0043ec1e  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ec20  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ec23  c1e810                 +shr eax, 0x10
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
    // 0043ec26  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ec28  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0043ec2c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043ec2e  8b819c020000           -mov eax, dword ptr [ecx + 0x29c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(668) /* 0x29c */);
    // 0043ec34  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ec36  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ec39  c1e810                 +shr eax, 0x10
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
    // 0043ec3c  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ec3e  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0043ec42  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043ec44  8b81a0020000           -mov eax, dword ptr [ecx + 0x2a0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(672) /* 0x2a0 */);
    // 0043ec4a  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ec4c  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ec4f  c1e810                 +shr eax, 0x10
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
    // 0043ec52  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ec54  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0043ec58  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043ec5a  8b8198020000           -mov eax, dword ptr [ecx + 0x298]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(664) /* 0x298 */);
    // 0043ec60  895c244c               -mov dword ptr [esp + 0x4c], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */) = cpu.ebx;
    // 0043ec64  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ec66  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ec69  c1e810                 +shr eax, 0x10
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
    // 0043ec6c  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ec6e  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0043ec72  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043ec74  8b819c020000           -mov eax, dword ptr [ecx + 0x29c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(668) /* 0x29c */);
    // 0043ec7a  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ec7c  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ec7f  c1e810                 +shr eax, 0x10
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
    // 0043ec82  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ec84  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0043ec88  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043ec8a  8b81a0020000           -mov eax, dword ptr [ecx + 0x2a0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(672) /* 0x2a0 */);
    // 0043ec90  8d742448               -lea esi, [esp + 0x48]
    cpu.esi = x86::reg32(cpu.esp + x86::reg32(72) /* 0x48 */);
    // 0043ec94  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ec96  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ec99  c1e810                 +shr eax, 0x10
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
    // 0043ec9c  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ec9e  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043eca0  8db998020000           -lea edi, [ecx + 0x298]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(664) /* 0x298 */);
    // 0043eca6  895c2450               -mov dword ptr [esp + 0x50], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(80) /* 0x50 */) = cpu.ebx;
    // 0043ecaa  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043ecab  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043ecac  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043ecad  8b1510ad5000           -mov edx, dword ptr [0x50ad10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287184) /* 0x50ad10 */);
    // 0043ecb3  8b818c020000           -mov eax, dword ptr [ecx + 0x28c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(652) /* 0x28c */);
    // 0043ecb9  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ecbb  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ecbe  c1e810                 +shr eax, 0x10
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
    // 0043ecc1  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ecc3  8b91a8000000           -mov edx, dword ptr [ecx + 0xa8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 0043ecc9  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043eccb  8b8190020000           -mov eax, dword ptr [ecx + 0x290]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(656) /* 0x290 */);
    // 0043ecd1  8991a8000000           -mov dword ptr [ecx + 0xa8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */) = cpu.edx;
    // 0043ecd7  8b1510ad5000           -mov edx, dword ptr [0x50ad10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287184) /* 0x50ad10 */);
    // 0043ecdd  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ecdf  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ece2  c1e810                 +shr eax, 0x10
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
    // 0043ece5  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ece7  8b99ac000000           -mov ebx, dword ptr [ecx + 0xac]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0043eced  8b1510ad5000           -mov edx, dword ptr [0x50ad10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287184) /* 0x50ad10 */);
    // 0043ecf3  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043ecf5  8b8194020000           -mov eax, dword ptr [ecx + 0x294]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(660) /* 0x294 */);
    // 0043ecfb  8999ac000000           -mov dword ptr [ecx + 0xac], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */) = cpu.ebx;
    // 0043ed01  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ed03  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ed06  c1e810                 +shr eax, 0x10
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
    // 0043ed09  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ed0b  8bb1b0000000           -mov esi, dword ptr [ecx + 0xb0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */);
    // 0043ed11  8bb95c050000           -mov edi, dword ptr [ecx + 0x55c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1372) /* 0x55c */);
    // 0043ed17  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043ed19  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043ed1b  89b1b0000000           -mov dword ptr [ecx + 0xb0], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */) = cpu.esi;
    // 0043ed21  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0043ed23  7467                   -je 0x43ed8c
    if (cpu.flags.zf)
    {
        goto L_0x0043ed8c;
    }
L_0x0043ed25:
    // 0043ed25  3b1d0cad5000           +cmp ebx, dword ptr [0x50ad0c]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5287180) /* 0x50ad0c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ed2b  7d5f                   -jge 0x43ed8c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043ed8c;
    }
    // 0043ed2d  8b915c050000           -mov edx, dword ptr [ecx + 0x55c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1372) /* 0x55c */);
    // 0043ed33  8b81a8000000           -mov eax, dword ptr [ecx + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 0043ed39  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ed3b  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ed3e  c1e810                 +shr eax, 0x10
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
    // 0043ed41  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ed43  8981a8000000           -mov dword ptr [ecx + 0xa8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 0043ed49  8b915c050000           -mov edx, dword ptr [ecx + 0x55c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1372) /* 0x55c */);
    // 0043ed4f  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0043ed55  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ed57  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ed5a  c1e810                 +shr eax, 0x10
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
    // 0043ed5d  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ed5f  8981ac000000           -mov dword ptr [ecx + 0xac], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */) = cpu.eax;
    // 0043ed65  8b915c050000           -mov edx, dword ptr [ecx + 0x55c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1372) /* 0x55c */);
    // 0043ed6b  8b81b0000000           -mov eax, dword ptr [ecx + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */);
    // 0043ed71  43                     -inc ebx
    (cpu.ebx)++;
    // 0043ed72  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ed74  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ed77  c1e810                 +shr eax, 0x10
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
    // 0043ed7a  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ed7c  8ba95c050000           -mov ebp, dword ptr [ecx + 0x55c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1372) /* 0x55c */);
    // 0043ed82  8981b0000000           -mov dword ptr [ecx + 0xb0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */) = cpu.eax;
    // 0043ed88  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0043ed8a  7599                   -jne 0x43ed25
    if (!cpu.flags.zf)
    {
        goto L_0x0043ed25;
    }
L_0x0043ed8c:
    // 0043ed8c  8b1510ad5000           -mov edx, dword ptr [0x50ad10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287184) /* 0x50ad10 */);
    // 0043ed92  8b8198020000           -mov eax, dword ptr [ecx + 0x298]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(664) /* 0x298 */);
    // 0043ed98  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ed9a  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ed9d  c1e810                 +shr eax, 0x10
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
    // 0043eda0  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043eda2  8b91e8000000           -mov edx, dword ptr [ecx + 0xe8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */);
    // 0043eda8  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043edaa  8b819c020000           -mov eax, dword ptr [ecx + 0x29c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(668) /* 0x29c */);
    // 0043edb0  8991e8000000           -mov dword ptr [ecx + 0xe8], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */) = cpu.edx;
    // 0043edb6  8b1510ad5000           -mov edx, dword ptr [0x50ad10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287184) /* 0x50ad10 */);
    // 0043edbc  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043edbe  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043edc1  c1e810                 +shr eax, 0x10
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
    // 0043edc4  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043edc6  8b99ec000000           -mov ebx, dword ptr [ecx + 0xec]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */);
    // 0043edcc  8b1510ad5000           -mov edx, dword ptr [0x50ad10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287184) /* 0x50ad10 */);
    // 0043edd2  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043edd4  8b81a0020000           -mov eax, dword ptr [ecx + 0x2a0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(672) /* 0x2a0 */);
    // 0043edda  8999ec000000           -mov dword ptr [ecx + 0xec], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */) = cpu.ebx;
    // 0043ede0  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ede2  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ede5  c1e810                 +shr eax, 0x10
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
    // 0043ede8  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043edea  8bb1f0000000           -mov esi, dword ptr [ecx + 0xf0]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */);
    // 0043edf0  c781ac02000000000000   -mov dword ptr [ecx + 0x2ac], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(684) /* 0x2ac */) = 0 /*0x0*/;
    // 0043edfa  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043edfc  89b1f0000000           -mov dword ptr [ecx + 0xf0], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */) = cpu.esi;
    // 0043ee02  83c454                 -add esp, 0x54
    (cpu.esp) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0043ee05  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ee06  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ee07  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ee08  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ee09  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ee0a  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043ee0b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_43ee10(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043ee10  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043ee11  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043ee12  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043ee13  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043ee14  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043ee15  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043ee16  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0043ee19  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043ee1b  f680a903000010         +test byte ptr [eax + 0x3a9], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(937) /* 0x3a9 */) & 16 /*0x10*/));
    // 0043ee22  0f849a020000           -je 0x43f0c2
    if (cpu.flags.zf)
    {
        goto L_0x0043f0c2;
    }
    // 0043ee28  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0043ee2d:
    // 0043ee2d  330528225100           +xor eax, dword ptr [0x512228]
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */)))));
    // 0043ee33  0f8490020000           -je 0x43f0c9
    if (cpu.flags.zf)
    {
        goto L_0x0043f0c9;
    }
    // 0043ee39  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x0043ee3e:
    // 0043ee3e  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0043ee40  8b91c4000000           -mov edx, dword ptr [ecx + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(196) /* 0xc4 */);
    // 0043ee46  8b81a8000000           -mov eax, dword ptr [ecx + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 0043ee4c  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ee4e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ee51  c1e810                 +shr eax, 0x10
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
    // 0043ee54  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ee56  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043ee58  8b91c8000000           -mov edx, dword ptr [ecx + 0xc8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(200) /* 0xc8 */);
    // 0043ee5e  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0043ee64  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ee66  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ee69  c1e810                 +shr eax, 0x10
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
    // 0043ee6c  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ee6e  8b91cc000000           -mov edx, dword ptr [ecx + 0xcc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(204) /* 0xcc */);
    // 0043ee74  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043ee76  8b81b0000000           -mov eax, dword ptr [ecx + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */);
    // 0043ee7c  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ee7e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ee81  c1e810                 +shr eax, 0x10
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
    // 0043ee84  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ee86  8b91d0000000           -mov edx, dword ptr [ecx + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 0043ee8c  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043ee8e  8b81a8000000           -mov eax, dword ptr [ecx + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 0043ee94  8999b0020000           -mov dword ptr [ecx + 0x2b0], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(688) /* 0x2b0 */) = cpu.ebx;
    // 0043ee9a  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ee9c  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ee9f  c1e810                 +shr eax, 0x10
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
    // 0043eea2  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043eea4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043eea6  8b91d4000000           -mov edx, dword ptr [ecx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 0043eeac  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0043eeb2  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043eeb4  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043eeb7  c1e810                 +shr eax, 0x10
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
    // 0043eeba  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043eebc  8b91d8000000           -mov edx, dword ptr [ecx + 0xd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 0043eec2  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043eec4  8b81b0000000           -mov eax, dword ptr [ecx + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */);
    // 0043eeca  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043eecc  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043eecf  c1e810                 +shr eax, 0x10
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
    // 0043eed2  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043eed4  8b91dc000000           -mov edx, dword ptr [ecx + 0xdc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(220) /* 0xdc */);
    // 0043eeda  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043eedc  8b81a8000000           -mov eax, dword ptr [ecx + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 0043eee2  8999b4020000           -mov dword ptr [ecx + 0x2b4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(692) /* 0x2b4 */) = cpu.ebx;
    // 0043eee8  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043eeea  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043eeed  c1e810                 +shr eax, 0x10
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
    // 0043eef0  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043eef2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043eef4  8b91e0000000           -mov edx, dword ptr [ecx + 0xe0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(224) /* 0xe0 */);
    // 0043eefa  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0043ef00  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ef02  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ef05  c1e810                 +shr eax, 0x10
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
    // 0043ef08  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ef0a  8b91e4000000           -mov edx, dword ptr [ecx + 0xe4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(228) /* 0xe4 */);
    // 0043ef10  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043ef12  8b81b0000000           -mov eax, dword ptr [ecx + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */);
    // 0043ef18  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ef1a  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ef1d  c1e810                 +shr eax, 0x10
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
    // 0043ef20  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ef22  8b91c4000000           -mov edx, dword ptr [ecx + 0xc4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(196) /* 0xc4 */);
    // 0043ef28  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043ef2a  8b81e8000000           -mov eax, dword ptr [ecx + 0xe8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */);
    // 0043ef30  8999b8020000           -mov dword ptr [ecx + 0x2b8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(696) /* 0x2b8 */) = cpu.ebx;
    // 0043ef36  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ef38  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ef3b  c1e810                 +shr eax, 0x10
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
    // 0043ef3e  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ef40  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043ef42  8b91c8000000           -mov edx, dword ptr [ecx + 0xc8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(200) /* 0xc8 */);
    // 0043ef48  8b81ec000000           -mov eax, dword ptr [ecx + 0xec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */);
    // 0043ef4e  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ef50  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ef53  c1e810                 +shr eax, 0x10
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
    // 0043ef56  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ef58  8b91cc000000           -mov edx, dword ptr [ecx + 0xcc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(204) /* 0xcc */);
    // 0043ef5e  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043ef60  8b81f0000000           -mov eax, dword ptr [ecx + 0xf0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */);
    // 0043ef66  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ef68  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ef6b  c1e810                 +shr eax, 0x10
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
    // 0043ef6e  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ef70  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043ef72  8999bc020000           -mov dword ptr [ecx + 0x2bc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(700) /* 0x2bc */) = cpu.ebx;
    // 0043ef78  8b91d0000000           -mov edx, dword ptr [ecx + 0xd0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 0043ef7e  8b81e8000000           -mov eax, dword ptr [ecx + 0xe8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */);
    // 0043ef84  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ef86  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ef89  c1e810                 +shr eax, 0x10
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
    // 0043ef8c  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ef8e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043ef90  8b91d4000000           -mov edx, dword ptr [ecx + 0xd4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 0043ef96  8b81ec000000           -mov eax, dword ptr [ecx + 0xec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */);
    // 0043ef9c  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ef9e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043efa1  c1e810                 +shr eax, 0x10
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
    // 0043efa4  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043efa6  8b91d8000000           -mov edx, dword ptr [ecx + 0xd8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 0043efac  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043efae  8b81f0000000           -mov eax, dword ptr [ecx + 0xf0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */);
    // 0043efb4  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043efb6  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043efb9  c1e810                 +shr eax, 0x10
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
    // 0043efbc  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043efbe  8b91dc000000           -mov edx, dword ptr [ecx + 0xdc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(220) /* 0xdc */);
    // 0043efc4  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043efc6  8b81e8000000           -mov eax, dword ptr [ecx + 0xe8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */);
    // 0043efcc  8999c0020000           -mov dword ptr [ecx + 0x2c0], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(704) /* 0x2c0 */) = cpu.ebx;
    // 0043efd2  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043efd4  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043efd7  c1e810                 +shr eax, 0x10
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
    // 0043efda  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043efdc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043efde  8b91e0000000           -mov edx, dword ptr [ecx + 0xe0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(224) /* 0xe0 */);
    // 0043efe4  8b81ec000000           -mov eax, dword ptr [ecx + 0xec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */);
    // 0043efea  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043efec  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043efef  c1e810                 +shr eax, 0x10
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
    // 0043eff2  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043eff4  8b91e4000000           -mov edx, dword ptr [ecx + 0xe4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(228) /* 0xe4 */);
    // 0043effa  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043effc  8b81f0000000           -mov eax, dword ptr [ecx + 0xf0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */);
    // 0043f002  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0043f004  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043f006  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043f009  c1e810                 +shr eax, 0x10
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
    // 0043f00c  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043f00e  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043f010  8db1dc000000           -lea esi, [ecx + 0xdc]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(220) /* 0xdc */);
    // 0043f016  8999c4020000           -mov dword ptr [ecx + 0x2c4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(708) /* 0x2c4 */) = cpu.ebx;
    // 0043f01c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043f01d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043f01e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043f01f  83b92405000001         +cmp dword ptr [ecx + 0x524], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1316) /* 0x524 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043f026  0f85a7000000           -jne 0x43f0d3
    if (!cpu.flags.zf)
    {
        goto L_0x0043f0d3;
    }
    // 0043f02c  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0043f030  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
L_0x0043f033:
    // 0043f033  e8a8e70500             -call 0x49d7e0
    cpu.esp -= 4;
    sub_49d7e0(app, cpu);
    if (cpu.terminate) return;
    // 0043f038  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043f03a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043f03c  89992c050000           -mov dword ptr [ecx + 0x52c], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1324) /* 0x52c */) = cpu.ebx;
    // 0043f042  e8f9010000             -call 0x43f240
    cpu.esp -= 4;
    sub_43f240(app, cpu);
    if (cpu.terminate) return;
    // 0043f047  8b910c050000           -mov edx, dword ptr [ecx + 0x50c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1292) /* 0x50c */);
    // 0043f04d  8b8104050000           -mov eax, dword ptr [ecx + 0x504]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1284) /* 0x504 */);
    // 0043f053  e888e70500             -call 0x49d7e0
    cpu.esp -= 4;
    sub_49d7e0(app, cpu);
    if (cpu.terminate) return;
    // 0043f058  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0043f05a  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043f05c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043f05e  81fa00feffff           +cmp edx, 0xfffffe00
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294966784 /*0xfffffe00*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043f064  0f8d79000000           -jge 0x43f0e3
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043f0e3;
    }
    // 0043f06a  81c200040000           -add edx, 0x400
    (cpu.edx) += x86::reg32(x86::sreg32(1024 /*0x400*/));
L_0x0043f070:
    // 0043f070  899110050000           -mov dword ptr [ecx + 0x510], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1296) /* 0x510 */) = cpu.edx;
    // 0043f076  8b1598ac5000           -mov edx, dword ptr [0x50ac98]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287064) /* 0x50ac98 */);
    // 0043f07c  0fafd5                 -imul edx, ebp
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebp)));
    // 0043f07f  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043f081  89b130050000           -mov dword ptr [ecx + 0x530], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1328) /* 0x530 */) = cpu.esi;
    // 0043f087  e894000000             -call 0x43f120
    cpu.esp -= 4;
    sub_43f120(app, cpu);
    if (cpu.terminate) return;
    // 0043f08c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043f08e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043f090  7e0e                   -jle 0x43f0a0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043f0a0;
    }
    // 0043f092  8bb1ac030000           -mov esi, dword ptr [ecx + 0x3ac]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(940) /* 0x3ac */);
    // 0043f098  3bb148050000           +cmp esi, dword ptr [ecx + 0x548]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1352) /* 0x548 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043f09e  7f64                   -jg 0x43f104
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0043f104;
    }
L_0x0043f0a0:
    // 0043f0a0  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043f0a2  7c52                   -jl 0x43f0f6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043f0f6;
    }
L_0x0043f0a4:
    // 0043f0a4  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0043f0a7  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0043f0a9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043f0ab  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043f0ad  e82e040000             -call 0x43f4e0
    cpu.esp -= 4;
    sub_43f4e0(app, cpu);
    if (cpu.terminate) return;
    // 0043f0b2  898138050000           -mov dword ptr [ecx + 0x538], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1336) /* 0x538 */) = cpu.eax;
    // 0043f0b8  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0043f0bb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f0bc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f0bd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f0be  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f0bf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f0c0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f0c1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043f0c2:
    // 0043f0c2  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043f0c4  e964fdffff             -jmp 0x43ee2d
    goto L_0x0043ee2d;
L_0x0043f0c9:
    // 0043f0c9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043f0ce  e96bfdffff             -jmp 0x43ee3e
    goto L_0x0043ee3e;
L_0x0043f0d3:
    // 0043f0d3  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0043f0d7  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0043f0da  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 0043f0dc  f7d8                   +neg eax
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
    // 0043f0de  e950ffffff             -jmp 0x43f033
    goto L_0x0043f033;
L_0x0043f0e3:
    // 0043f0e3  81fa00020000           +cmp edx, 0x200
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(512 /*0x200*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043f0e9  7e85                   -jle 0x43f070
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043f070;
    }
    // 0043f0eb  81ea00040000           +sub edx, 0x400
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1024 /*0x400*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043f0f1  e97affffff             -jmp 0x43f070
    goto L_0x0043f070;
L_0x0043f0f6:
    // 0043f0f6  8bb9ac030000           -mov edi, dword ptr [ecx + 0x3ac]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(940) /* 0x3ac */);
    // 0043f0fc  3bb948050000           +cmp edi, dword ptr [ecx + 0x548]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1352) /* 0x548 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043f102  7da0                   -jge 0x43f0a4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043f0a4;
    }
L_0x0043f104:
    // 0043f104  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043f106  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043f109  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043f10b  d1f8                   +sar eax, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0043f10d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043f10f  eb93                   -jmp 0x43f0a4
    goto L_0x0043f0a4;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43f120(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043f120  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043f121  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043f122  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043f123  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043f124  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043f125  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043f127  8b1528225100           -mov edx, dword ptr [0x512228]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */);
    // 0043f12d  8b4014                 -mov eax, dword ptr [eax + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */);
    // 0043f130  85d2                   -test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043f132  833d2822510000         +cmp dword ptr [0x512228], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043f139  0f84b6000000           -je 0x43f1f5
    if (cpu.flags.zf)
    {
        goto L_0x0043f1f5;
    }
    // 0043f13f  bafdffffff             -mov edx, 0xfffffffd
    cpu.edx = 4294967293 /*0xfffffffd*/;
L_0x0043f144:
    // 0043f144  8b35a0185100           -mov esi, dword ptr [0x5118a0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5314720) /* 0x5118a0 */);
    // 0043f14a  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043f14c  39f2                   +cmp edx, esi
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
    // 0043f14e  0f8cb5000000           -jl 0x43f209
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043f209;
    }
    // 0043f154  833d2822510000         +cmp dword ptr [0x512228], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043f15b  0f849e000000           -je 0x43f1ff
    if (cpu.flags.zf)
    {
        goto L_0x0043f1ff;
    }
    // 0043f161  bafdffffff             -mov edx, 0xfffffffd
    cpu.edx = 4294967293 /*0xfffffffd*/;
L_0x0043f166:
    // 0043f166  8b1da0185100           -mov ebx, dword ptr [0x5118a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5314720) /* 0x5118a0 */);
    // 0043f16c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043f16e  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0043f170:
    // 0043f170  8d3cc500000000         -lea edi, [eax*8]
    cpu.edi = x86::reg32(cpu.eax * 8);
    // 0043f177  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043f179  8b1da4185100           -mov ebx, dword ptr [0x5118a4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5314724) /* 0x5118a4 */);
    // 0043f17f  c1e702                 -shl edi, 2
    cpu.edi <<= 2 /*0x2*/ % 32;
    // 0043f182  8d043b                 -lea eax, [ebx + edi]
    cpu.eax = x86::reg32(cpu.ebx + cpu.edi * 1);
    // 0043f185  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0043f187  8b500f                 -mov edx, dword ptr [eax + 0xf]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 0043f18a  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043f18c  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0043f18f  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043f191  c1e602                 -shl esi, 2
    cpu.esi <<= 2 /*0x2*/ % 32;
    // 0043f194  8b441e0c               -mov eax, dword ptr [esi + ebx + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */ + cpu.ebx * 1);
    // 0043f198  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0043f19b  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0043f19e  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 0043f1a1  c1e009                 -shl eax, 9
    cpu.eax <<= 9 /*0x9*/ % 32;
    // 0043f1a4  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043f1a6  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043f1a9  c1e810                 +shr eax, 0x10
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
    // 0043f1ac  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043f1ae  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043f1b0  a1a4185100             -mov eax, dword ptr [0x5118a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5314724) /* 0x5118a4 */);
    // 0043f1b5  8b540711               -mov edx, dword ptr [edi + eax + 0x11]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(17) /* 0x11 */ + cpu.eax * 1);
    // 0043f1b9  8b44060e               -mov eax, dword ptr [esi + eax + 0xe]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(14) /* 0xe */ + cpu.eax * 1);
    // 0043f1bd  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0043f1c0  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0043f1c3  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 0043f1c6  c1e009                 -shl eax, 9
    cpu.eax <<= 9 /*0x9*/ % 32;
    // 0043f1c9  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043f1cb  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043f1ce  c1e810                 +shr eax, 0x10
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
    // 0043f1d1  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043f1d3  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043f1d5  f681a903000010         +test byte ptr [ecx + 0x3a9], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(937) /* 0x3a9 */) & 16 /*0x10*/));
    // 0043f1dc  7447                   -je 0x43f225
    if (cpu.flags.zf)
    {
        goto L_0x0043f225;
    }
    // 0043f1de  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0043f1e3:
    // 0043f1e3  330528225100           +xor eax, dword ptr [0x512228]
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */)))));
    // 0043f1e9  743e                   -je 0x43f229
    if (cpu.flags.zf)
    {
        goto L_0x0043f229;
    }
    // 0043f1eb  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043f1ed  f7d8                   +neg eax
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
    // 0043f1ef  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f1f0  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f1f1  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f1f2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f1f3  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f1f4  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043f1f5:
    // 0043f1f5  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0043f1fa  e945ffffff             -jmp 0x43f144
    goto L_0x0043f144;
L_0x0043f1ff:
    // 0043f1ff  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0043f204  e95dffffff             -jmp 0x43f166
    goto L_0x0043f166;
L_0x0043f209:
    // 0043f209  833d2822510000         +cmp dword ptr [0x512228], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043f210  740c                   -je 0x43f21e
    if (cpu.flags.zf)
    {
        goto L_0x0043f21e;
    }
    // 0043f212  bafdffffff             -mov edx, 0xfffffffd
    cpu.edx = 4294967293 /*0xfffffffd*/;
L_0x0043f217:
    // 0043f217  01c2                   +add edx, eax
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
    // 0043f219  e952ffffff             -jmp 0x43f170
    goto L_0x0043f170;
L_0x0043f21e:
    // 0043f21e  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 0043f223  ebf2                   -jmp 0x43f217
    goto L_0x0043f217;
L_0x0043f225:
    // 0043f225  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043f227  ebba                   -jmp 0x43f1e3
    goto L_0x0043f1e3;
L_0x0043f229:
    // 0043f229  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043f22b  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f22c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f22d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f22e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f22f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f230  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43f240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043f240  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043f241  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043f242  83ec24                 -sub esp, 0x24
    (cpu.esp) -= x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0043f245  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043f247  e8b4010000             -call 0x43f400
    cpu.esp -= 4;
    sub_43f400(app, cpu);
    if (cpu.terminate) return;
    // 0043f24c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043f24e  0f8574010000           -jne 0x43f3c8
    if (!cpu.flags.zf)
    {
        goto L_0x0043f3c8;
    }
    // 0043f254  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043f255  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043f256  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043f257  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043f258  8b919c030000           -mov edx, dword ptr [ecx + 0x39c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */);
    // 0043f25e  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043f260  0f8e68010000           -jle 0x43f3ce
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043f3ce;
    }
    // 0043f266  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
L_0x0043f268:
    // 0043f268  b800400000             -mov eax, 0x4000
    cpu.eax = 16384 /*0x4000*/;
    // 0043f26d  8b15a4ac5000           -mov edx, dword ptr [0x50aca4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287076) /* 0x50aca4 */);
    // 0043f273  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043f275  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043f278  c1e810                 +shr eax, 0x10
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
    // 0043f27b  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043f27d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0043f27f  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043f281  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043f284  c1e810                 +shr eax, 0x10
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
    // 0043f287  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043f289  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043f28b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043f28e  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0043f291  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043f293  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0043f296  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043f298  7c10                   -jl 0x43f2aa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043f2aa;
    }
    // 0043f29a  8b359cac5000           -mov esi, dword ptr [0x50ac9c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5287068) /* 0x50ac9c */);
    // 0043f2a0  39f0                   +cmp eax, esi
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
    // 0043f2a2  7d06                   -jge 0x43f2aa
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043f2aa;
    }
    // 0043f2a4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043f2a6  7c02                   -jl 0x43f2aa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043f2aa;
    }
    // 0043f2a8  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0043f2aa:
    // 0043f2aa  8b3da0ac5000           -mov edi, dword ptr [0x50aca0]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5287072) /* 0x50aca0 */);
    // 0043f2b0  39f8                   +cmp eax, edi
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
    // 0043f2b2  0f8e1f010000           -jle 0x43f3d7
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043f3d7;
    }
    // 0043f2b8  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
L_0x0043f2ba:
    // 0043f2ba  8ba924050000           -mov ebp, dword ptr [ecx + 0x524]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1316) /* 0x524 */);
    // 0043f2c0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043f2c2  83fdff                 +cmp ebp, -1
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
    // 0043f2c5  7502                   -jne 0x43f2c9
    if (!cpu.flags.zf)
    {
        goto L_0x0043f2c9;
    }
    // 0043f2c7  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x0043f2c9:
    // 0043f2c9  f681a903000010         +test byte ptr [ecx + 0x3a9], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(937) /* 0x3a9 */) & 16 /*0x10*/));
    // 0043f2d0  0f8408010000           -je 0x43f3de
    if (cpu.flags.zf)
    {
        goto L_0x0043f3de;
    }
    // 0043f2d6  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0043f2db:
    // 0043f2db  331528225100           +xor edx, dword ptr [0x512228]
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */)))));
    // 0043f2e1  7402                   -je 0x43f2e5
    if (cpu.flags.zf)
    {
        goto L_0x0043f2e5;
    }
    // 0043f2e3  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
L_0x0043f2e5:
    // 0043f2e5  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043f2e7  0f8cf8000000           -jl 0x43f3e5
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043f3e5;
    }
    // 0043f2ed  8b6914                 -mov ebp, dword ptr [ecx + 0x14]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0043f2f0  8b15a0185100           -mov edx, dword ptr [0x5118a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5314720) /* 0x5118a0 */);
    // 0043f2f6  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0043f2f8  39d0                   +cmp eax, edx
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
    // 0043f2fa  7c02                   -jl 0x43f2fe
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043f2fe;
    }
    // 0043f2fc  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
L_0x0043f2fe:
    // 0043f2fe  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043f300  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0043f303  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043f305  8b35a4185100           -mov esi, dword ptr [0x5118a4]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5314724) /* 0x5118a4 */);
    // 0043f30b  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0043f30e  8d7c241c               -lea edi, [esp + 0x1c]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0043f312  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043f314  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043f315  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043f316  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043f317  8d7c2428               -lea edi, [esp + 0x28]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0043f31b  8db118010000           -lea esi, [ecx + 0x118]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(280) /* 0x118 */);
    // 0043f321  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043f322  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043f323  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043f324  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0043f328  8b8148050000           -mov eax, dword ptr [ecx + 0x548]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1352) /* 0x548 */);
    // 0043f32e  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043f330  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043f333  c1e810                 +shr eax, 0x10
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
    // 0043f336  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043f338  8b54242c               -mov edx, dword ptr [esp + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0043f33c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043f33e  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0043f342  8b8148050000           -mov eax, dword ptr [ecx + 0x548]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1352) /* 0x548 */);
    // 0043f348  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043f34a  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043f34d  c1e810                 +shr eax, 0x10
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
    // 0043f350  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043f352  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 0043f356  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043f358  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0043f35c  8b8148050000           -mov eax, dword ptr [ecx + 0x548]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1352) /* 0x548 */);
    // 0043f362  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043f364  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043f367  c1e810                 +shr eax, 0x10
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
    // 0043f36a  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043f36c  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 0043f370  01f2                   -add edx, esi
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.esi));
    // 0043f372  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 0043f376  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0043f37a  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043f37c  89542414               -mov dword ptr [esp + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0043f380  8b542424               -mov edx, dword ptr [esp + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0043f384  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 0043f388  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043f38a  89542418               -mov dword ptr [esp + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 0043f38e  8b819c000000           -mov eax, dword ptr [ecx + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(156) /* 0x9c */);
    // 0043f394  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0043f398  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043f39a  8b81a0000000           -mov eax, dword ptr [ecx + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */);
    // 0043f3a0  899104050000           -mov dword ptr [ecx + 0x504], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1284) /* 0x504 */) = cpu.edx;
    // 0043f3a6  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0043f3aa  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043f3ac  8b81a4000000           -mov eax, dword ptr [ecx + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(164) /* 0xa4 */);
    // 0043f3b2  899108050000           -mov dword ptr [ecx + 0x508], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1288) /* 0x508 */) = cpu.edx;
    // 0043f3b8  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 0043f3bc  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043f3be  89910c050000           -mov dword ptr [ecx + 0x50c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1292) /* 0x50c */) = cpu.edx;
    // 0043f3c4  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f3c5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f3c6  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f3c7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x0043f3c8:
    // 0043f3c8  83c424                 -add esp, 0x24
    (cpu.esp) += x86::reg32(x86::sreg32(36 /*0x24*/));
    // 0043f3cb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f3cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f3cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043f3ce:
    // 0043f3ce  89d3                   -mov ebx, edx
    cpu.ebx = cpu.edx;
    // 0043f3d0  f7db                   +neg ebx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ebx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0043f3d2  e991feffff             -jmp 0x43f268
    goto L_0x0043f268;
L_0x0043f3d7:
    // 0043f3d7  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043f3d9  e9dcfeffff             -jmp 0x43f2ba
    goto L_0x0043f2ba;
L_0x0043f3de:
    // 0043f3de  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0043f3e0  e9f6feffff             -jmp 0x43f2db
    goto L_0x0043f2db;
L_0x0043f3e5:
    // 0043f3e5  034114                 -add eax, dword ptr [ecx + 0x14]
    (cpu.eax) += x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */)));
    // 0043f3e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043f3ea  0f8d0effffff           -jge 0x43f2fe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043f2fe;
    }
    // 0043f3f0  0305a0185100           +add eax, dword ptr [0x5118a0]
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5314720) /* 0x5118a0 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043f3f6  e903ffffff             -jmp 0x43f2fe
    goto L_0x0043f2fe;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43f400(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043f400  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043f401  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043f402  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043f403  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043f404  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043f405  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043f407  83b83c05000000         +cmp dword ptr [eax + 0x53c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1340) /* 0x53c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043f40e  0f8eb4000000           -jle 0x43f4c8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043f4c8;
    }
    // 0043f414  8b9824050000           -mov ebx, dword ptr [eax + 0x524]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1316) /* 0x524 */);
    // 0043f41a  83fb01                 +cmp ebx, 1
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
    // 0043f41d  0f85a5000000           -jne 0x43f4c8
    if (!cpu.flags.zf)
    {
        goto L_0x0043f4c8;
    }
    // 0043f423  f680a903000010         +test byte ptr [eax + 0x3a9], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(937) /* 0x3a9 */) & 16 /*0x10*/));
    // 0043f42a  0f8591000000           -jne 0x43f4c1
    if (!cpu.flags.zf)
    {
        goto L_0x0043f4c1;
    }
    // 0043f430  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0043f432:
    // 0043f432  8b9944050000           -mov ebx, dword ptr [ecx + 0x544]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1348) /* 0x544 */);
    // 0043f438  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043f43a  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043f43c  0f8486000000           -je 0x43f4c8
    if (cpu.flags.zf)
    {
        goto L_0x0043f4c8;
    }
    // 0043f442  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 0043f445  8b4114                 -mov eax, dword ptr [ecx + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 0043f448  e8b3dfffff             -call 0x43d400
    cpu.esp -= 4;
    sub_43d400(app, cpu);
    if (cpu.terminate) return;
    // 0043f44d  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043f44f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043f451  0f8e79000000           -jle 0x43f4d0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043f4d0;
    }
L_0x0043f457:
    // 0043f457  83f81e                 +cmp eax, 0x1e
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(30 /*0x1e*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043f45a  7d6c                   -jge 0x43f4c8
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043f4c8;
    }
    // 0043f45c  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0043f45e  7404                   -je 0x43f464
    if (cpu.flags.zf)
    {
        goto L_0x0043f464;
    }
    // 0043f460  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043f462  7c08                   -jl 0x43f46c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043f46c;
    }
L_0x0043f464:
    // 0043f464  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0043f466  7560                   -jne 0x43f4c8
    if (!cpu.flags.zf)
    {
        goto L_0x0043f4c8;
    }
    // 0043f468  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043f46a  7e5c                   -jle 0x43f4c8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043f4c8;
    }
L_0x0043f46c:
    // 0043f46c  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043f46d  8bb19c000000           -mov esi, dword ptr [ecx + 0x9c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(156) /* 0x9c */);
    // 0043f473  8b839c000000           -mov eax, dword ptr [ebx + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(156) /* 0x9c */);
    // 0043f479  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0043f47b  898104050000           -mov dword ptr [ecx + 0x504], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1284) /* 0x504 */) = cpu.eax;
    // 0043f481  8bb9a0000000           -mov edi, dword ptr [ecx + 0xa0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(160) /* 0xa0 */);
    // 0043f487  8b83a0000000           -mov eax, dword ptr [ebx + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(160) /* 0xa0 */);
    // 0043f48d  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0043f48f  898108050000           -mov dword ptr [ecx + 0x508], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1288) /* 0x508 */) = cpu.eax;
    // 0043f495  8ba9a4000000           -mov ebp, dword ptr [ecx + 0xa4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(164) /* 0xa4 */);
    // 0043f49b  8b83a4000000           -mov eax, dword ptr [ebx + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(164) /* 0xa4 */);
    // 0043f4a1  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0043f4a3  89810c050000           -mov dword ptr [ecx + 0x50c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1292) /* 0x50c */) = cpu.eax;
    // 0043f4a9  8b83ac030000           -mov eax, dword ptr [ebx + 0x3ac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(940) /* 0x3ac */);
    // 0043f4af  898148050000           -mov dword ptr [ecx + 0x548], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1352) /* 0x548 */) = cpu.eax;
    // 0043f4b5  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043f4ba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f4bb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f4bc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f4bd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f4be  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f4bf  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f4c0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043f4c1:
    // 0043f4c1  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043f4c3  e96affffff             -jmp 0x43f432
    goto L_0x0043f432;
L_0x0043f4c8:
    // 0043f4c8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043f4ca  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f4cb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f4cc  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f4cd  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f4ce  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f4cf  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043f4d0:
    // 0043f4d0  f7d8                   +neg eax
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
    // 0043f4d2  eb83                   -jmp 0x43f457
    goto L_0x0043f457;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43f4e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043f4e0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043f4e1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043f4e2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043f4e3  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0043f4e6  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043f4e8  f680f401000010         +test byte ptr [eax + 0x1f4], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(500) /* 0x1f4 */) & 16 /*0x10*/));
    // 0043f4ef  0f84b6000000           -je 0x43f5ab
    if (cpu.flags.zf)
    {
        goto L_0x0043f5ab;
    }
    // 0043f4f5  8bb19c030000           -mov esi, dword ptr [ecx + 0x39c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */);
    // 0043f4fb  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0043f4fd  0f8e9f000000           -jle 0x43f5a2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043f5a2;
    }
    // 0043f503  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0043f505:
    // 0043f505  3d00001400             +cmp eax, 0x140000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1310720 /*0x140000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043f50a  0f8d9b000000           -jge 0x43f5ab
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043f5ab;
    }
    // 0043f510  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
L_0x0043f512:
    // 0043f512  8b2da0185100           -mov ebp, dword ptr [0x5118a0]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5314720) /* 0x5118a0 */);
    // 0043f518  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043f51a  39ea                   +cmp edx, ebp
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
    // 0043f51c  7c02                   -jl 0x43f520
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043f520;
    }
    // 0043f51e  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0043f520:
    // 0043f520  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0043f527  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043f529  8b15a4185100           -mov edx, dword ptr [0x5118a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5314724) /* 0x5118a4 */);
    // 0043f52f  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0043f532  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043f534  8b500f                 -mov edx, dword ptr [eax + 0xf]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(15) /* 0xf */);
    // 0043f537  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0043f53a  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 0043f53d  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 0043f540  8b5010                 -mov edx, dword ptr [eax + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */);
    // 0043f543  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0043f546  8b4011                 -mov eax, dword ptr [eax + 0x11]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(17) /* 0x11 */);
    // 0043f549  c1e209                 -shl edx, 9
    cpu.edx <<= 9 /*0x9*/ % 32;
    // 0043f54c  c1f818                 -sar eax, 0x18
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (24 /*0x18*/ % 32));
    // 0043f54f  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 0043f553  c1e009                 -shl eax, 9
    cpu.eax <<= 9 /*0x9*/ % 32;
    // 0043f556  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0043f559  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0043f55d  8b81a8000000           -mov eax, dword ptr [ecx + 0xa8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */);
    // 0043f563  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043f565  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043f568  c1e810                 +shr eax, 0x10
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
    // 0043f56b  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043f56d  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0043f571  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043f573  8b81ac000000           -mov eax, dword ptr [ecx + 0xac]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */);
    // 0043f579  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043f57b  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043f57e  c1e810                 +shr eax, 0x10
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
    // 0043f581  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043f583  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0043f587  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043f589  8b81b0000000           -mov eax, dword ptr [ecx + 0xb0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */);
    // 0043f58f  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043f591  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043f594  c1e810                 +shr eax, 0x10
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
    // 0043f597  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043f599  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043f59b  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0043f59e  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f59f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f5a0  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f5a1  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043f5a2:
    // 0043f5a2  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043f5a4  f7d8                   +neg eax
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
    // 0043f5a6  e95affffff             -jmp 0x43f505
    goto L_0x0043f505;
L_0x0043f5ab:
    // 0043f5ab  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043f5ad  0f8d5fffffff           -jge 0x43f512
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043f512;
    }
    // 0043f5b3  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043f5b5  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043f5b7  0f8d63ffffff           -jge 0x43f520
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043f520;
    }
    // 0043f5bd  0315a0185100           +add edx, dword ptr [0x5118a0]
    {
        x86::reg32& tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5314720) /* 0x5118a0 */)));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043f5c3  e958ffffff             -jmp 0x43f520
    goto L_0x0043f520;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43f5d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043f5d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043f5d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043f5d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043f5d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043f5d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043f5d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043f5d6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043f5d8  8b15081c5100           -mov edx, dword ptr [0x511c08]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5315592) /* 0x511c08 */);
    // 0043f5de  8b8ae8010000           -mov ecx, dword ptr [edx + 0x1e8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(488) /* 0x1e8 */);
    // 0043f5e4  8b153c1e5100           -mov edx, dword ptr [0x511e3c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5316156) /* 0x511e3c */);
    // 0043f5ea  8bb8e8010000           -mov edi, dword ptr [eax + 0x1e8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(488) /* 0x1e8 */);
    // 0043f5f0  4a                     -dec edx
    (cpu.edx)--;
    // 0043f5f1  29cf                   -sub edi, ecx
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043f5f3  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043f5f5  7c20                   -jl 0x43f617
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043f617;
    }
    // 0043f5f7  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
L_0x0043f5fe:
    // 0043f5fe  8b88881a5100           -mov ecx, dword ptr [eax + 0x511a88]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5315208) /* 0x511a88 */);
    // 0043f604  f681f401000001         +test byte ptr [ecx + 0x1f4], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(500) /* 0x1f4 */) & 1 /*0x1*/));
    // 0043f60b  0f84a6000000           -je 0x43f6b7
    if (cpu.flags.zf)
    {
        goto L_0x0043f6b7;
    }
    // 0043f611  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 0043f613  668b7106               -mov si, word ptr [ecx + 6]
    cpu.si = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
L_0x0043f617:
    // 0043f617  81febc020000           +cmp esi, 0x2bc
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(700 /*0x2bc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043f61d  7d39                   -jge 0x43f658
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043f658;
    }
    // 0043f61f  8b2d480f5400           -mov ebp, dword ptr [0x540f48]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 0043f625  81fdc0050000           +cmp ebp, 0x5c0
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1472 /*0x5c0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043f62b  7e2b                   -jle 0x43f658
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043f658;
    }
    // 0043f62d  8d9500feffff           -lea edx, [ebp - 0x200]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-512) /* -0x200 */);
    // 0043f633  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043f635  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043f638  c1e206                 +shl edx, 6
    {
        x86::reg8 tmp = 6 /*0x6*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0043f63b  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043f63d  c1f806                 -sar eax, 6
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (6 /*0x6*/ % 32));
    // 0043f640  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043f642  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043f644  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0043f647  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043f649  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043f64b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043f64e  c1e202                 +shl edx, 2
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
    // 0043f651  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043f653  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
    // 0043f656  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
L_0x0043f658:
    // 0043f658  f6051922510004         +test byte ptr [0x512219], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5317145) /* 0x512219 */) & 4 /*0x4*/));
    // 0043f65f  7406                   -je 0x43f667
    if (cpu.flags.zf)
    {
        goto L_0x0043f667;
    }
    // 0043f661  81c6c8000000           -add esi, 0xc8
    (cpu.esi) += x86::reg32(x86::sreg32(200 /*0xc8*/));
L_0x0043f667:
    // 0043f667  81febc020000           +cmp esi, 0x2bc
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(700 /*0x2bc*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043f66d  7d2a                   -jge 0x43f699
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043f699;
    }
    // 0043f66f  8d5701                 -lea edx, [edi + 1]
    cpu.edx = x86::reg32(cpu.edi + x86::reg32(1) /* 0x1 */);
    // 0043f672  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0043f679  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043f67b  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0043f67e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043f680  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043f682  8d504b                 -lea edx, [eax + 0x4b]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(75) /* 0x4b */);
    // 0043f685  833d301e510002         +cmp dword ptr [0x511e30], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5316144) /* 0x511e30 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043f68c  7e3a                   -jle 0x43f6c8
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043f6c8;
    }
    // 0043f68e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0043f693:
    // 0043f693  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043f695  39c6                   +cmp esi, eax
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
    // 0043f697  7c17                   -jl 0x43f6b0
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043f6b0;
    }
L_0x0043f699:
    // 0043f699  a10cad5000             -mov eax, dword ptr [0x50ad0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5287180) /* 0x50ad0c */);
    // 0043f69e  8b93c4030000           -mov edx, dword ptr [ebx + 0x3c4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(964) /* 0x3c4 */);
    // 0043f6a4  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043f6a6  8993c4030000           -mov dword ptr [ebx + 0x3c4], edx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(964) /* 0x3c4 */) = cpu.edx;
    // 0043f6ac  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043f6ae  7e1c                   -jle 0x43f6cc
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043f6cc;
    }
L_0x0043f6b0:
    // 0043f6b0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f6b1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f6b2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f6b3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f6b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f6b5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f6b6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043f6b7:
    // 0043f6b7  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0043f6ba  4a                     -dec edx
    (cpu.edx)--;
    // 0043f6bb  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043f6bd  0f8d3bffffff           -jge 0x43f5fe
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043f5fe;
    }
    // 0043f6c3  e94fffffff             -jmp 0x43f617
    goto L_0x0043f617;
L_0x0043f6c8:
    // 0043f6c8  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043f6ca  ebc7                   -jmp 0x43f693
    goto L_0x0043f693;
L_0x0043f6cc:
    // 0043f6cc  8b35381e5100           -mov esi, dword ptr [0x511e38]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5316152) /* 0x511e38 */);
    // 0043f6d2  a1481e5100             -mov eax, dword ptr [0x511e48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5316168) /* 0x511e48 */);
    // 0043f6d7  8b3d8cac5000           -mov edi, dword ptr [0x50ac8c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5287052) /* 0x50ac8c */);
    // 0043f6dd  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0043f6df  8b2d64ac5000           -mov ebp, dword ptr [0x50ac64]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5287012) /* 0x50ac64 */);
    // 0043f6e5  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0043f6e7  39e8                   +cmp eax, ebp
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
    // 0043f6e9  7c11                   -jl 0x43f6fc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043f6fc;
    }
    // 0043f6eb  c783c403000001000000   -mov dword ptr [ebx + 0x3c4], 1
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(964) /* 0x3c4 */) = 1 /*0x1*/;
    // 0043f6f5  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f6f6  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f6f7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f6f8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f6f9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f6fa  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f6fb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043f6fc:
    // 0043f6fc  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043f6fe  e80d000000             -call 0x43f710
    cpu.esp -= 4;
    sub_43f710(app, cpu);
    if (cpu.terminate) return;
    // 0043f703  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f704  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f705  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f706  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f707  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f708  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f709  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43f710(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043f710  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043f711  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043f712  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043f713  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043f714  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043f716  668b90a8030000         -mov dx, word ptr [eax + 0x3a8]
    cpu.dx = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(936) /* 0x3a8 */);
    // 0043f71d  c780ec04000001000000   -mov dword ptr [eax + 0x4ec], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1260) /* 0x4ec */) = 1 /*0x1*/;
    // 0043f727  81e2eff7ffff           -and edx, 0xfffff7ef
    cpu.edx &= x86::reg32(x86::sreg32(4294965231 /*0xfffff7ef*/));
    // 0043f72d  668990a8030000         -mov word ptr [eax + 0x3a8], dx
    app->getMemory<x86::reg16>(cpu.eax + x86::reg32(936) /* 0x3a8 */) = cpu.dx;
    // 0043f734  8aa0a9030000           -mov ah, byte ptr [eax + 0x3a9]
    cpu.ah = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(937) /* 0x3a9 */);
    // 0043f73a  80cc08                 -or ah, 8
    cpu.ah |= x86::reg8(x86::sreg8(8 /*0x8*/));
    // 0043f73d  8b15806a4d00           -mov edx, dword ptr [0x4d6a80]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5073536) /* 0x4d6a80 */);
    // 0043f743  88a3a9030000           -mov byte ptr [ebx + 0x3a9], ah
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(937) /* 0x3a9 */) = cpu.ah;
    // 0043f749  a1786a4d00             -mov eax, dword ptr [0x4d6a78]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5073528) /* 0x4d6a78 */);
    // 0043f74e  0fafc2                 -imul eax, edx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043f751  a37c6a4d00             -mov dword ptr [0x4d6a7c], eax
    app->getMemory<x86::reg32>(x86::reg32(5073532) /* 0x4d6a7c */) = cpu.eax;
    // 0043f756  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0043f75b  a3786a4d00             -mov dword ptr [0x4d6a78], eax
    app->getMemory<x86::reg32>(x86::reg32(5073528) /* 0x4d6a78 */) = cpu.eax;
    // 0043f760  a17c6a4d00             -mov eax, dword ptr [0x4d6a7c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5073532) /* 0x4d6a7c */);
    // 0043f765  2500ffff00             -and eax, 0xffff00
    cpu.eax &= x86::reg32(x86::sreg32(16776960 /*0xffff00*/));
    // 0043f76a  c1e808                 -shr eax, 8
    cpu.eax >>= 8 /*0x8*/ % 32;
    // 0043f76d  8b0d8cac5000           -mov ecx, dword ptr [0x50ac8c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5287052) /* 0x50ac8c */);
    // 0043f773  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043f775  49                     -dec ecx
    (cpu.ecx)--;
    // 0043f776  c1e810                 -shr eax, 0x10
    cpu.eax >>= 16 /*0x10*/ % 32;
    // 0043f779  890d8cac5000           -mov dword ptr [0x50ac8c], ecx
    app->getMemory<x86::reg32>(x86::reg32(5287052) /* 0x50ac8c */) = cpu.ecx;
    // 0043f77f  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043f781  0f8484000000           -je 0x43f80b
    if (cpu.flags.zf)
    {
        goto L_0x0043f80b;
    }
    // 0043f787  808ba903000010         -or byte ptr [ebx + 0x3a9], 0x10
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(937) /* 0x3a9 */) |= x86::reg8(x86::sreg8(16 /*0x10*/));
L_0x0043f78e:
    // 0043f78e  a1786a4d00             -mov eax, dword ptr [0x4d6a78]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5073528) /* 0x4d6a78 */);
    // 0043f793  8b35806a4d00           -mov esi, dword ptr [0x4d6a80]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5073536) /* 0x4d6a80 */);
    // 0043f799  0fafc6                 -imul eax, esi
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.esi)));
    // 0043f79c  a37c6a4d00             -mov dword ptr [0x4d6a7c], eax
    app->getMemory<x86::reg32>(x86::reg32(5073532) /* 0x4d6a7c */) = cpu.eax;
    // 0043f7a1  8b157c6a4d00           -mov edx, dword ptr [0x4d6a7c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5073532) /* 0x4d6a7c */);
    // 0043f7a7  81e200ffff00           -and edx, 0xffff00
    cpu.edx &= x86::reg32(x86::sreg32(16776960 /*0xffff00*/));
    // 0043f7ad  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 0043f7b2  c1ea08                 -shr edx, 8
    cpu.edx >>= 8 /*0x8*/ % 32;
    // 0043f7b5  a3786a4d00             -mov dword ptr [0x4d6a78], eax
    app->getMemory<x86::reg32>(x86::reg32(5073528) /* 0x4d6a78 */) = cpu.eax;
    // 0043f7ba  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 0043f7c1  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043f7c3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043f7c5  c1ea10                 -shr edx, 0x10
    cpu.edx >>= 16 /*0x10*/ % 32;
    // 0043f7c8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043f7ca  e811db0200             -call 0x46d2e0
    cpu.esp -= 4;
    sub_46d2e0(app, cpu);
    if (cpu.terminate) return;
    // 0043f7cf  8b153c1e5100           -mov edx, dword ptr [0x511e3c]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5316156) /* 0x511e3c */);
    // 0043f7d5  4a                     -dec edx
    (cpu.edx)--;
    // 0043f7d6  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043f7d8  7c1e                   -jl 0x43f7f8
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043f7f8;
    }
    // 0043f7da  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
L_0x0043f7e1:
    // 0043f7e1  8b88c81a5100           -mov ecx, dword ptr [eax + 0x511ac8]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5315272) /* 0x511ac8 */);
    // 0043f7e7  f681f401000004         +test byte ptr [ecx + 0x1f4], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(500) /* 0x1f4 */) & 4 /*0x4*/));
    // 0043f7ee  7527                   -jne 0x43f817
    if (!cpu.flags.zf)
    {
        goto L_0x0043f817;
    }
    // 0043f7f0  83e804                 -sub eax, 4
    (cpu.eax) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0043f7f3  4a                     -dec edx
    (cpu.edx)--;
    // 0043f7f4  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043f7f6  7de9                   -jge 0x43f7e1
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043f7e1;
    }
L_0x0043f7f8:
    // 0043f7f8  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043f7fa  c6838d00000001         -mov byte ptr [ebx + 0x8d], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(141) /* 0x8d */) = 1 /*0x1*/;
    // 0043f801  e82acaffff             -call 0x43c230
    cpu.esp -= 4;
    sub_43c230(app, cpu);
    if (cpu.terminate) return;
    // 0043f806  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f807  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f808  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f809  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f80a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043f80b:
    // 0043f80b  80a3a9030000ef         +and byte ptr [ebx + 0x3a9], 0xef
    cpu.clear_co();
    cpu.set_szp((app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(937) /* 0x3a9 */) &= x86::reg8(x86::sreg8(239 /*0xef*/))));
    // 0043f812  e977ffffff             -jmp 0x43f78e
    goto L_0x0043f78e;
L_0x0043f817:
    // 0043f817  898bb0030000           -mov dword ptr [ebx + 0x3b0], ecx
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(944) /* 0x3b0 */) = cpu.ecx;
    // 0043f81d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043f81f  c6838d00000001         -mov byte ptr [ebx + 0x8d], 1
    app->getMemory<x86::reg8>(cpu.ebx + x86::reg32(141) /* 0x8d */) = 1 /*0x1*/;
    // 0043f826  e805caffff             -call 0x43c230
    cpu.esp -= 4;
    sub_43c230(app, cpu);
    if (cpu.terminate) return;
    // 0043f82b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f82c  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f82d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f82e  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f82f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_43f830(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043f830  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043f831  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043f832  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043f833  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043f834  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043f835  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043f836  83ec18                 -sub esp, 0x18
    (cpu.esp) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0043f839  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043f83b  8b98f4010000           -mov ebx, dword ptr [eax + 0x1f4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(500) /* 0x1f4 */);
    // 0043f841  83e308                 -and ebx, 8
    cpu.ebx &= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 0043f844  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0043f846  e875010000             -call 0x43f9c0
    cpu.esp -= 4;
    sub_43f9c0(app, cpu);
    if (cpu.terminate) return;
    // 0043f84b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0043f84d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043f84f  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 0043f851  e88a010000             -call 0x43f9e0
    cpu.esp -= 4;
    sub_43f9e0(app, cpu);
    if (cpu.terminate) return;
    // 0043f856  8db118010000           -lea esi, [ecx + 0x118]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(280) /* 0x118 */);
    // 0043f85c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043f85d  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043f85e  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043f85f  8d7c240c               -lea edi, [esp + 0xc]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0043f863  8db1dc000000           -lea esi, [ecx + 0xdc]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(220) /* 0xdc */);
    // 0043f869  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043f86a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043f86b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 0043f86c  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0043f86f  8b81cc030000           -mov eax, dword ptr [ecx + 0x3cc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(972) /* 0x3cc */);
    // 0043f875  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043f877  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043f87a  c1e810                 +shr eax, 0x10
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
    // 0043f87d  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043f87f  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0043f883  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 0043f886  8b81cc030000           -mov eax, dword ptr [ecx + 0x3cc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(972) /* 0x3cc */);
    // 0043f88c  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043f88e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043f891  c1e810                 +shr eax, 0x10
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
    // 0043f894  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043f896  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0043f89a  89442404               -mov dword ptr [esp + 4], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 0043f89e  8b81cc030000           -mov eax, dword ptr [ecx + 0x3cc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(972) /* 0x3cc */);
    // 0043f8a4  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043f8a6  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043f8a9  c1e810                 +shr eax, 0x10
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
    // 0043f8ac  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043f8ae  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0043f8b2  8b999c030000           -mov ebx, dword ptr [ecx + 0x39c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */);
    // 0043f8b8  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 0043f8bc  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043f8be  0f8ed4000000           -jle 0x43f998
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043f998;
    }
    // 0043f8c4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
L_0x0043f8c6:
    // 0043f8c6  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043f8c8  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043f8cb  c1e810                 +shr eax, 0x10
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
    // 0043f8ce  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043f8d0  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0043f8d4  8bb19c030000           -mov esi, dword ptr [ecx + 0x39c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */);
    // 0043f8da  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0043f8de  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0043f8e0  0f8ebb000000           -jle 0x43f9a1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043f9a1;
    }
    // 0043f8e6  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
L_0x0043f8e8:
    // 0043f8e8  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043f8ea  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043f8ed  c1e810                 +shr eax, 0x10
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
    // 0043f8f0  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043f8f2  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 0043f8f6  8bb99c030000           -mov edi, dword ptr [ecx + 0x39c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */);
    // 0043f8fc  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 0043f900  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0043f902  0f8ea2000000           -jle 0x43f9aa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043f9aa;
    }
    // 0043f908  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
L_0x0043f90a:
    // 0043f90a  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043f90c  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043f90f  c1e810                 +shr eax, 0x10
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
    // 0043f912  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043f914  8b2c24                 -mov ebp, dword ptr [esp]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    // 0043f917  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043f919  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0043f91d  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0043f921  01e8                   -add eax, ebp
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebp));
    // 0043f923  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0043f927  8981a8000000           -mov dword ptr [ecx + 0xa8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(168) /* 0xa8 */) = cpu.eax;
    // 0043f92d  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0043f931  c781e800000000000000   -mov dword ptr [ecx + 0xe8], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(232) /* 0xe8 */) = 0 /*0x0*/;
    // 0043f93b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0043f93d  8981ac000000           -mov dword ptr [ecx + 0xac], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(172) /* 0xac */) = cpu.eax;
    // 0043f943  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0043f947  c781ec00000000000000   -mov dword ptr [ecx + 0xec], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(236) /* 0xec */) = 0 /*0x0*/;
    // 0043f951  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043f953  8981b0000000           -mov dword ptr [ecx + 0xb0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(176) /* 0xb0 */) = cpu.eax;
    // 0043f959  8b81a0030000           -mov eax, dword ptr [ecx + 0x3a0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(928) /* 0x3a0 */);
    // 0043f95f  8981b8020000           -mov dword ptr [ecx + 0x2b8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(696) /* 0x2b8 */) = cpu.eax;
    // 0043f965  8aa1a9030000           -mov ah, byte ptr [ecx + 0x3a9]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(937) /* 0x3a9 */);
    // 0043f96b  c781f000000000000000   -mov dword ptr [ecx + 0xf0], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(240) /* 0xf0 */) = 0 /*0x0*/;
    // 0043f975  f6c410                 +test ah, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 16 /*0x10*/));
    // 0043f978  7439                   -je 0x43f9b3
    if (cpu.flags.zf)
    {
        goto L_0x0043f9b3;
    }
    // 0043f97a  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0043f97f:
    // 0043f97f  8b1d28225100           -mov ebx, dword ptr [0x512228]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */);
    // 0043f985  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043f987  31da                   -xor edx, ebx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043f989  e8622e0200             -call 0x4627f0
    cpu.esp -= 4;
    sub_4627f0(app, cpu);
    if (cpu.terminate) return;
    // 0043f98e  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 0043f991  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f992  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f993  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f994  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f995  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f996  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f997  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043f998:
    // 0043f998  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043f99a  f7d8                   +neg eax
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
    // 0043f99c  e925ffffff             -jmp 0x43f8c6
    goto L_0x0043f8c6;
L_0x0043f9a1:
    // 0043f9a1  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043f9a3  f7d8                   +neg eax
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
    // 0043f9a5  e93effffff             -jmp 0x43f8e8
    goto L_0x0043f8e8;
L_0x0043f9aa:
    // 0043f9aa  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 0043f9ac  f7d8                   +neg eax
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
    // 0043f9ae  e957ffffff             -jmp 0x43f90a
    goto L_0x0043f90a;
L_0x0043f9b3:
    // 0043f9b3  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0043f9b5  ebc8                   -jmp 0x43f97f
    goto L_0x0043f97f;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43f9c0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043f9c0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043f9c1  8b88ac030000           -mov ecx, dword ptr [eax + 0x3ac]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(940) /* 0x3ac */);
    // 0043f9c7  8b9048050000           -mov edx, dword ptr [eax + 0x548]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1352) /* 0x548 */);
    // 0043f9cd  29ca                   -sub edx, ecx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0043f9cf  c1e203                 -shl edx, 3
    cpu.edx <<= 3 /*0x3*/ % 32;
    // 0043f9d2  8990cc030000           -mov dword ptr [eax + 0x3cc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(972) /* 0x3cc */) = cpu.edx;
    // 0043f9d8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043f9d9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43f9e0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043f9e0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043f9e1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043f9e2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043f9e3  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043f9e4  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043f9e5  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043f9e7  e894010000             -call 0x43fb80
    cpu.esp -= 4;
    sub_43fb80(app, cpu);
    if (cpu.terminate) return;
    // 0043f9ec  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043f9ee  8b9998030000           -mov ebx, dword ptr [ecx + 0x398]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(920) /* 0x398 */);
    // 0043f9f4  8bb99c030000           -mov edi, dword ptr [ecx + 0x39c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */);
    // 0043f9fa  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043f9fc  29fb                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 0043f9fe  e84d030000             -call 0x43fd50
    cpu.esp -= 4;
    sub_43fd50(app, cpu);
    if (cpu.terminate) return;
    // 0043fa03  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043fa05  f681a903000010         +test byte ptr [ecx + 0x3a9], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(937) /* 0x3a9 */) & 16 /*0x10*/));
    // 0043fa0c  7468                   -je 0x43fa76
    if (cpu.flags.zf)
    {
        goto L_0x0043fa76;
    }
    // 0043fa0e  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0043fa13:
    // 0043fa13  330528225100           +xor eax, dword ptr [0x512228]
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */)))));
    // 0043fa19  0f84aa000000           -je 0x43fac9
    if (cpu.flags.zf)
    {
        goto L_0x0043fac9;
    }
    // 0043fa1f  8b919c030000           -mov edx, dword ptr [ecx + 0x39c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */);
    // 0043fa25  3b9198030000           +cmp edx, dword ptr [ecx + 0x398]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(920) /* 0x398 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043fa2b  7c4d                   -jl 0x43fa7a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043fa7a;
    }
    // 0043fa2d  8b1510ad5000           -mov edx, dword ptr [0x50ad10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287184) /* 0x50ad10 */);
    // 0043fa33  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043fa35  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043fa37  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043fa3a  c1e810                 +shr eax, 0x10
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
    // 0043fa3d  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043fa3f  8b999c030000           -mov ebx, dword ptr [ecx + 0x39c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */);
    // 0043fa45  89b1ac020000           -mov dword ptr [ecx + 0x2ac], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(684) /* 0x2ac */) = cpu.esi;
    // 0043fa4b  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043fa4d  89999c030000           -mov dword ptr [ecx + 0x39c], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */) = cpu.ebx;
    // 0043fa53  8bb198030000           -mov esi, dword ptr [ecx + 0x398]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(920) /* 0x398 */);
    // 0043fa59  8b819c030000           -mov eax, dword ptr [ecx + 0x39c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */);
    // 0043fa5f  c681d802000000         -mov byte ptr [ecx + 0x2d8], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(728) /* 0x2d8 */) = 0 /*0x0*/;
    // 0043fa66  39f0                   +cmp eax, esi
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
    // 0043fa68  7e51                   -jle 0x43fabb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043fabb;
    }
L_0x0043fa6a:
    // 0043fa6a  89819c030000           -mov dword ptr [ecx + 0x39c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */) = cpu.eax;
    // 0043fa70  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fa71  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fa72  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fa73  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fa74  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fa75  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043fa76:
    // 0043fa76  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0043fa78  eb99                   -jmp 0x43fa13
    goto L_0x0043fa13;
L_0x0043fa7a:
    // 0043fa7a  8b1510ad5000           -mov edx, dword ptr [0x50ad10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287184) /* 0x50ad10 */);
    // 0043fa80  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043fa82  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043fa84  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043fa87  c1e810                 +shr eax, 0x10
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
    // 0043fa8a  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043fa8c  8bb99c030000           -mov edi, dword ptr [ecx + 0x39c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */);
    // 0043fa92  c681d8020000ff         -mov byte ptr [ecx + 0x2d8], 0xff
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(728) /* 0x2d8 */) = 255 /*0xff*/;
    // 0043fa99  01c7                   -add edi, eax
    (cpu.edi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043fa9b  89b99c030000           -mov dword ptr [ecx + 0x39c], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */) = cpu.edi;
    // 0043faa1  8ba998030000           -mov ebp, dword ptr [ecx + 0x398]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(920) /* 0x398 */);
    // 0043faa7  8b819c030000           -mov eax, dword ptr [ecx + 0x39c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */);
    // 0043faad  8999ac020000           -mov dword ptr [ecx + 0x2ac], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(684) /* 0x2ac */) = cpu.ebx;
    // 0043fab3  39e8                   +cmp eax, ebp
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
    // 0043fab5  7eb3                   -jle 0x43fa6a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043fa6a;
    }
    // 0043fab7  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0043fab9  ebaf                   -jmp 0x43fa6a
    goto L_0x0043fa6a;
L_0x0043fabb:
    // 0043fabb  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043fabd  89819c030000           -mov dword ptr [ecx + 0x39c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */) = cpu.eax;
    // 0043fac3  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fac4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fac5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fac6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fac7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fac8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043fac9:
    // 0043fac9  8b919c030000           -mov edx, dword ptr [ecx + 0x39c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */);
    // 0043facf  3b9198030000           +cmp edx, dword ptr [ecx + 0x398]
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(920) /* 0x398 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043fad5  7f4f                   -jg 0x43fb26
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0043fb26;
    }
    // 0043fad7  8b1510ad5000           -mov edx, dword ptr [0x50ad10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287184) /* 0x50ad10 */);
    // 0043fadd  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043fadf  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043fae1  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043fae4  c1e810                 +shr eax, 0x10
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
    // 0043fae7  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043fae9  8b999c030000           -mov ebx, dword ptr [ecx + 0x39c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */);
    // 0043faef  89b1ac020000           -mov dword ptr [ecx + 0x2ac], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(684) /* 0x2ac */) = cpu.esi;
    // 0043faf5  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043faf7  89999c030000           -mov dword ptr [ecx + 0x39c], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */) = cpu.ebx;
    // 0043fafd  8bb198030000           -mov esi, dword ptr [ecx + 0x398]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(920) /* 0x398 */);
    // 0043fb03  8b819c030000           -mov eax, dword ptr [ecx + 0x39c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */);
    // 0043fb09  c681d802000000         -mov byte ptr [ecx + 0x2d8], 0
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(728) /* 0x2d8 */) = 0 /*0x0*/;
    // 0043fb10  39f0                   +cmp eax, esi
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
    // 0043fb12  0f8e52ffffff           -jle 0x43fa6a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043fa6a;
    }
    // 0043fb18  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043fb1a  89819c030000           -mov dword ptr [ecx + 0x39c], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */) = cpu.eax;
    // 0043fb20  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fb21  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fb22  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fb23  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fb24  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fb25  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043fb26:
    // 0043fb26  8b1510ad5000           -mov edx, dword ptr [0x50ad10]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287184) /* 0x50ad10 */);
    // 0043fb2c  c681d8020000ff         -mov byte ptr [ecx + 0x2d8], 0xff
    app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(728) /* 0x2d8 */) = 255 /*0xff*/;
    // 0043fb33  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043fb35  8999ac020000           -mov dword ptr [ecx + 0x2ac], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(684) /* 0x2ac */) = cpu.ebx;
    // 0043fb3b  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043fb3d  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043fb40  c1e810                 +shr eax, 0x10
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
    // 0043fb43  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043fb45  8bb99c030000           -mov edi, dword ptr [ecx + 0x39c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */);
    // 0043fb4b  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043fb4d  8ba998030000           -mov ebp, dword ptr [ecx + 0x398]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(920) /* 0x398 */);
    // 0043fb53  89b99c030000           -mov dword ptr [ecx + 0x39c], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */) = cpu.edi;
    // 0043fb59  39ef                   +cmp edi, ebp
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
    // 0043fb5b  7e0e                   -jle 0x43fb6b
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043fb6b;
    }
    // 0043fb5d  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0043fb5f  89919c030000           -mov dword ptr [ecx + 0x39c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */) = cpu.edx;
    // 0043fb65  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fb66  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fb67  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fb68  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fb69  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fb6a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043fb6b:
    // 0043fb6b  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0043fb6d  89919c030000           -mov dword ptr [ecx + 0x39c], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */) = cpu.edx;
    // 0043fb73  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fb74  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fb75  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fb76  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fb77  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fb78  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43fb80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043fb80  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043fb81  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043fb82  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043fb83  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043fb84  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043fb85  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043fb86  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043fb88  833d2822510000         +cmp dword ptr [0x512228], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043fb8f  741c                   -je 0x43fbad
    if (cpu.flags.zf)
    {
        goto L_0x0043fbad;
    }
    // 0043fb91  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x0043fb96:
    // 0043fb96  8b99b8030000           -mov ebx, dword ptr [ecx + 0x3b8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(952) /* 0x3b8 */);
    // 0043fb9c  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 0043fb9e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043fba0  7e12                   -jle 0x43fbb4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043fbb4;
    }
L_0x0043fba2:
    // 0043fba2  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0043fba4  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043fba6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fba7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fba8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fba9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fbaa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fbab  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fbac  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043fbad:
    // 0043fbad  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0043fbb2  ebe2                   -jmp 0x43fb96
    goto L_0x0043fb96;
L_0x0043fbb4:
    // 0043fbb4  8b811c020000           -mov eax, dword ptr [ecx + 0x21c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(540) /* 0x21c */);
    // 0043fbba  8b38                   -mov edi, dword ptr [eax]
    cpu.edi = app->getMemory<x86::reg32>(cpu.eax);
    // 0043fbbc  83ff0f                 +cmp edi, 0xf
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043fbbf  7d66                   -jge 0x43fc27
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043fc27;
    }
    // 0043fbc1  8b2d04ad5000           -mov ebp, dword ptr [0x50ad04]
    cpu.ebp = app->getMemory<x86::reg32>(x86::reg32(5287172) /* 0x50ad04 */);
    // 0043fbc7  8b1cbd745f4d00         -mov ebx, dword ptr [edi*4 + 0x4d5f74]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5070708) /* 0x4d5f74 */ + cpu.edi * 4);
    // 0043fbce  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 0043fbd0  7431                   -je 0x43fc03
    if (cpu.flags.zf)
    {
        goto L_0x0043fc03;
    }
    // 0043fbd2  8b1500225100           -mov edx, dword ptr [0x512200]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317120) /* 0x512200 */);
    // 0043fbd8  8b81e8010000           -mov eax, dword ptr [ecx + 0x1e8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(488) /* 0x1e8 */);
    // 0043fbde  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 0043fbe1  8b0485b0265100         -mov eax, dword ptr [eax*4 + 0x5126b0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5318320) /* 0x5126b0 */ + cpu.eax * 4);
    // 0043fbe8  8b94c2f8574d00         -mov edx, dword ptr [edx + eax*8 + 0x4d57f8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5068792) /* 0x4d57f8 */ + cpu.eax * 8);
    // 0043fbef  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043fbf1  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043fbf3  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043fbf6  c1e810                 +shr eax, 0x10
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
    // 0043fbf9  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043fbfb  3b819c030000           +cmp eax, dword ptr [ecx + 0x39c]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043fc01  7c9f                   -jl 0x43fba2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043fba2;
    }
L_0x0043fc03:
    // 0043fc03  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043fc05  8b9158050000           -mov edx, dword ptr [ecx + 0x558]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1368) /* 0x558 */);
    // 0043fc0b  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043fc0d  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043fc10  c1e810                 +shr eax, 0x10
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
    // 0043fc13  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043fc15  8bb99c030000           -mov edi, dword ptr [ecx + 0x39c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */);
    // 0043fc1b  39f8                   +cmp eax, edi
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
    // 0043fc1d  7c83                   -jl 0x43fba2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043fba2;
    }
    // 0043fc1f  39fb                   +cmp ebx, edi
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
    // 0043fc21  0f8c7bffffff           -jl 0x43fba2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043fba2;
    }
L_0x0043fc27:
    // 0043fc27  8b999c030000           -mov ebx, dword ptr [ecx + 0x39c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(924) /* 0x39c */);
    // 0043fc2d  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0043fc30  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043fc32  0f8e91000000           -jle 0x43fcc9
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043fcc9;
    }
L_0x0043fc38:
    // 0043fc38  83fb6f                 +cmp ebx, 0x6f
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
    // 0043fc3b  0f8d8f000000           -jge 0x43fcd0
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043fcd0;
    }
    // 0043fc41  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043fc43  0f8e91000000           -jle 0x43fcda
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043fcda;
    }
L_0x0043fc49:
    // 0043fc49  8b9c5906040000         -mov ebx, dword ptr [ecx + ebx*2 + 0x406]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1030) /* 0x406 */ + cpu.ebx * 2);
    // 0043fc50  c1fb10                 -sar ebx, 0x10
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (16 /*0x10*/ % 32));
    // 0043fc53  8aa1f4010000           -mov ah, byte ptr [ecx + 0x1f4]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(500) /* 0x1f4 */);
    // 0043fc59  c1e308                 -shl ebx, 8
    cpu.ebx <<= 8 /*0x8*/ % 32;
    // 0043fc5c  f6c408                 +test ah, 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ah & 8 /*0x8*/));
    // 0043fc5f  0f857c000000           -jne 0x43fce1
    if (!cpu.flags.zf)
    {
        goto L_0x0043fce1;
    }
L_0x0043fc65:
    // 0043fc65  833d0022510000         +cmp dword ptr [0x512200], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317120) /* 0x512200 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043fc6c  751a                   -jne 0x43fc88
    if (!cpu.flags.zf)
    {
        goto L_0x0043fc88;
    }
    // 0043fc6e  6683790664             +cmp word ptr [ecx + 6], 0x64
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(100 /*0x64*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043fc73  7613                   -jbe 0x43fc88
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x0043fc88;
    }
    // 0043fc75  ba00c00000             -mov edx, 0xc000
    cpu.edx = 49152 /*0xc000*/;
    // 0043fc7a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043fc7c  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043fc7e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043fc81  c1e810                 +shr eax, 0x10
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
    // 0043fc84  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043fc86  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0043fc88:
    // 0043fc88  83b93c05000000         +cmp dword ptr [ecx + 0x53c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1340) /* 0x53c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043fc8f  7e13                   -jle 0x43fca4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043fca4;
    }
    // 0043fc91  bacc4c0100             -mov edx, 0x14ccc
    cpu.edx = 85196 /*0x14ccc*/;
    // 0043fc96  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043fc98  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043fc9a  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043fc9d  c1e810                 +shr eax, 0x10
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
    // 0043fca0  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043fca2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0043fca4:
    // 0043fca4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043fca6  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043fca7  8a818c000000           -mov al, byte ptr [ecx + 0x8c]
    cpu.al = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(140) /* 0x8c */);
    // 0043fcad  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043fcae  8b01                   -mov eax, dword ptr [ecx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx);
    // 0043fcb0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0043fcb1  68ccb94c00             -push 0x4cb9cc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5028300 /*0x4cb9cc*/;
    cpu.esp -= 4;
    // 0043fcb6  6a03                   -push 3
    app->getMemory<x86::reg32>(cpu.esp-4) = 3 /*0x3*/;
    cpu.esp -= 4;
    // 0043fcb8  e8b33a0100             -call 0x453770
    cpu.esp -= 4;
    sub_453770(app, cpu);
    if (cpu.terminate) return;
    // 0043fcbd  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0043fcc0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043fcc2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fcc3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fcc4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fcc5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fcc6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fcc7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fcc8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043fcc9:
    // 0043fcc9  f7db                   +neg ebx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ebx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0043fccb  e968ffffff             -jmp 0x43fc38
    goto L_0x0043fc38;
L_0x0043fcd0:
    // 0043fcd0  bb6f000000             -mov ebx, 0x6f
    cpu.ebx = 111 /*0x6f*/;
    // 0043fcd5  e96fffffff             -jmp 0x43fc49
    goto L_0x0043fc49;
L_0x0043fcda:
    // 0043fcda  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 0043fcdc  e968ffffff             -jmp 0x43fc49
    goto L_0x0043fc49;
L_0x0043fce1:
    // 0043fce1  a190ac5000             -mov eax, dword ptr [0x50ac90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5287056) /* 0x50ac90 */);
    // 0043fce6  0fafb09c030000         -imul esi, dword ptr [eax + 0x39c]
    cpu.esi = x86::reg32(x86::sreg64(x86::sreg32(cpu.esi)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(924) /* 0x39c */))));
    // 0043fced  81fe00000200           +cmp esi, 0x20000
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(131072 /*0x20000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043fcf3  7d0e                   -jge 0x43fd03
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0043fd03;
    }
    // 0043fcf5  6683b84e01000000       +cmp word ptr [eax + 0x14e], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(334) /* 0x14e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043fcfd  0f8562ffffff           -jne 0x43fc65
    if (!cpu.flags.zf)
    {
        goto L_0x0043fc65;
    }
L_0x0043fd03:
    // 0043fd03  a190ac5000             -mov eax, dword ptr [0x50ac90]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5287056) /* 0x50ac90 */);
    // 0043fd08  6683b84e01000000       +cmp word ptr [eax + 0x14e], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(334) /* 0x14e */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 0043fd10  0f854fffffff           -jne 0x43fc65
    if (!cpu.flags.zf)
    {
        goto L_0x0043fc65;
    }
    // 0043fd16  833d1022510000         +cmp dword ptr [0x512210], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317136) /* 0x512210 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043fd1d  7521                   -jne 0x43fd40
    if (!cpu.flags.zf)
    {
        goto L_0x0043fd40;
    }
    // 0043fd1f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x0043fd24:
    // 0043fd24  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043fd26  e8c58cffff             -call 0x4389f0
    cpu.esp -= 4;
    sub_4389f0(app, cpu);
    if (cpu.terminate) return;
    // 0043fd2b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043fd2d  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0043fd2f  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043fd31  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043fd34  c1e810                 +shr eax, 0x10
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
    // 0043fd37  11d0                   +adc eax, edx
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(cpu.edx)) + cpu.flags.cf;
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0043fd39  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043fd3b  e925ffffff             -jmp 0x43fc65
    goto L_0x0043fc65;
L_0x0043fd40:
    // 0043fd40  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 0043fd42  ebe0                   -jmp 0x43fd24
    goto L_0x0043fd24;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43fd50(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043fd50  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043fd51  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043fd53  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043fd55  7420                   -je 0x43fd77
    if (cpu.flags.zf)
    {
        goto L_0x0043fd77;
    }
    // 0043fd57  b800000f00             -mov eax, 0xf0000
    cpu.eax = 983040 /*0xf0000*/;
L_0x0043fd5c:
    // 0043fd5c  833d0422510000         +cmp dword ptr [0x512204], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317124) /* 0x512204 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043fd63  7402                   -je 0x43fd67
    if (cpu.flags.zf)
    {
        goto L_0x0043fd67;
    }
    // 0043fd65  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
L_0x0043fd67:
    // 0043fd67  8b9958050000           -mov ebx, dword ptr [ecx + 0x558]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1368) /* 0x558 */);
    // 0043fd6d  81fb00000100           +cmp ebx, 0x10000
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043fd73  7f09                   -jg 0x43fd7e
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0043fd7e;
    }
    // 0043fd75  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fd76  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043fd77:
    // 0043fd77  b800000c00             -mov eax, 0xc0000
    cpu.eax = 786432 /*0xc0000*/;
    // 0043fd7c  ebde                   -jmp 0x43fd5c
    goto L_0x0043fd5c;
L_0x0043fd7e:
    // 0043fd7e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0043fd80  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043fd82  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043fd85  c1e810                 +shr eax, 0x10
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
    // 0043fd88  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043fd8a  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fd8b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_43fd90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043fd90  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043fd91  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043fd92  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 0043fd93  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043fd94  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043fd95  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043fd96  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043fd98  83b8b803000000         +cmp dword ptr [eax + 0x3b8], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(952) /* 0x3b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043fd9f  7e33                   -jle 0x43fdd4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043fdd4;
    }
    // 0043fda1  a10cad5000             -mov eax, dword ptr [0x50ad0c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5287180) /* 0x50ad0c */);
    // 0043fda6  8bb1b8030000           -mov esi, dword ptr [ecx + 0x3b8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(952) /* 0x3b8 */);
    // 0043fdac  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043fdae  b8b80b0000             -mov eax, 0xbb8
    cpu.eax = 3000 /*0xbb8*/;
    // 0043fdb3  89b1b8030000           -mov dword ptr [ecx + 0x3b8], esi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(952) /* 0x3b8 */) = cpu.esi;
L_0x0043fdb9:
    // 0043fdb9  8ba9f0020000           -mov ebp, dword ptr [ecx + 0x2f0]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(752) /* 0x2f0 */);
    // 0043fdbf  39e8                   +cmp eax, ebp
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
    // 0043fdc1  0f8fe1000000           -jg 0x43fea8
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0043fea8;
    }
    // 0043fdc7  0f8cfa000000           -jl 0x43fec7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043fec7;
    }
    // 0043fdcd  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fdce  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fdcf  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fdd0  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fdd1  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fdd2  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fdd3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043fdd4:
    // 0043fdd4  8b989c030000           -mov ebx, dword ptr [eax + 0x39c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(924) /* 0x39c */);
    // 0043fdda  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0043fddc  7e3c                   -jle 0x43fe1a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043fe1a;
    }
    // 0043fdde  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
L_0x0043fde0:
    // 0043fde0  8d99da020000           -lea ebx, [ecx + 0x2da]
    cpu.ebx = x86::reg32(cpu.ecx + x86::reg32(730) /* 0x2da */);
    // 0043fde6  31ed                   -xor ebp, ebp
    cpu.ebp ^= x86::reg32(x86::sreg32(cpu.ebp));
L_0x0043fde8:
    // 0043fde8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043fdea  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 0043fdec  8b8481d0030000         -mov eax, dword ptr [ecx + eax*4 + 0x3d0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(976) /* 0x3d0 */ + cpu.eax * 4);
    // 0043fdf3  39c6                   +cmp esi, eax
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
    // 0043fdf5  7e29                   -jle 0x43fe20
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0043fe20;
    }
    // 0043fdf7  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
L_0x0043fdfc:
    // 0043fdfc  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 0043fdfe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043fe00  7422                   -je 0x43fe24
    if (cpu.flags.zf)
    {
        goto L_0x0043fe24;
    }
L_0x0043fe02:
    // 0043fe02  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0043fe04  0f8573000000           -jne 0x43fe7d
    if (!cpu.flags.zf)
    {
        goto L_0x0043fe7d;
    }
    // 0043fe0a  fe0b                   +dec byte ptr [ebx]
    {
        auto tmp = app->getMemory<x86::reg8>(cpu.ebx);
        cpu.flags.of = 1 & (tmp >> 7);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 7));
        cpu.set_szp(tmp);
    }
    // 0043fe0c  8b81b4030000           -mov eax, dword ptr [ecx + 0x3b4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(948) /* 0x3b4 */);
    // 0043fe12  8981b8030000           -mov dword ptr [ecx + 0x3b8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(952) /* 0x3b8 */) = cpu.eax;
    // 0043fe18  ebce                   -jmp 0x43fde8
    goto L_0x0043fde8;
L_0x0043fe1a:
    // 0043fe1a  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0043fe1c  f7de                   +neg esi
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.esi;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0043fe1e  ebc0                   -jmp 0x43fde0
    goto L_0x0043fde0;
L_0x0043fe20:
    // 0043fe20  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 0043fe22  ebd8                   -jmp 0x43fdfc
    goto L_0x0043fdfc;
L_0x0043fe24:
    // 0043fe24  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043fe26  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043fe28  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0043fe2a  e831040000             -call 0x440260
    cpu.esp -= 4;
    sub_440260(app, cpu);
    if (cpu.terminate) return;
    // 0043fe2f  39c6                   +cmp esi, eax
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
    // 0043fe31  7ccf                   -jl 0x43fe02
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043fe02;
    }
L_0x0043fe33:
    // 0043fe33  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043fe35  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0043fe37  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0043fe39  e822040000             -call 0x440260
    cpu.esp -= 4;
    sub_440260(app, cpu);
    if (cpu.terminate) return;
    // 0043fe3e  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043fe40  8a33                   -mov dh, byte ptr [ebx]
    cpu.dh = app->getMemory<x86::reg8>(cpu.ebx);
    // 0043fe42  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0043fe44  84f6                   +test dh, dh
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.dh & cpu.dh));
    // 0043fe46  7559                   -jne 0x43fea1
    if (!cpu.flags.zf)
    {
        goto L_0x0043fea1;
    }
    // 0043fe48  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
L_0x0043fe4a:
    // 0043fe4a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0043fe4c  8a13                   -mov dl, byte ptr [ebx]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ebx);
    // 0043fe4e  8bb9bc030000           -mov edi, dword ptr [ecx + 0x3bc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(956) /* 0x3bc */);
    // 0043fe54  8b9491ec030000         -mov edx, dword ptr [ecx + edx*4 + 0x3ec]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1004) /* 0x3ec */ + cpu.edx * 4);
    // 0043fe5b  29f7                   -sub edi, esi
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0043fe5d  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043fe5f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043fe62  c1e810                 +shr eax, 0x10
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
    // 0043fe65  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043fe67  89fa                   -mov edx, edi
    cpu.edx = cpu.edi;
    // 0043fe69  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043fe6b  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043fe6e  c1e810                 +shr eax, 0x10
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
    // 0043fe71  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043fe73  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0043fe75  c1f810                 +sar eax, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0043fe78  e93cffffff             -jmp 0x43fdb9
    goto L_0x0043fdb9;
L_0x0043fe7d:
    // 0043fe7d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0043fe7f  8a03                   -mov al, byte ptr [ebx]
    cpu.al = app->getMemory<x86::reg8>(cpu.ebx);
    // 0043fe81  3bac81d4030000         +cmp ebp, dword ptr [ecx + eax*4 + 0x3d4]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(980) /* 0x3d4 */ + cpu.eax * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043fe88  74a9                   -je 0x43fe33
    if (cpu.flags.zf)
    {
        goto L_0x0043fe33;
    }
    // 0043fe8a  88c2                   -mov dl, al
    cpu.dl = cpu.al;
    // 0043fe8c  fec2                   +inc dl
    {
        x86::reg8& tmp = cpu.dl;
        cpu.flags.of = ~(1 & (tmp >> 7));
        tmp++;
        cpu.flags.of &= 1 & (tmp >> 7);
        cpu.set_szp(tmp);
    }
    // 0043fe8e  8813                   -mov byte ptr [ebx], dl
    app->getMemory<x86::reg8>(cpu.ebx) = cpu.dl;
    // 0043fe90  8b81b4030000           -mov eax, dword ptr [ecx + 0x3b4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(948) /* 0x3b4 */);
    // 0043fe96  8981b8030000           -mov dword ptr [ecx + 0x3b8], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(952) /* 0x3b8 */) = cpu.eax;
    // 0043fe9c  e947ffffff             -jmp 0x43fde8
    goto L_0x0043fde8;
L_0x0043fea1:
    // 0043fea1  be0000b80b             -mov esi, 0xbb80000
    cpu.esi = 196608000 /*0xbb80000*/;
    // 0043fea6  eba2                   -jmp 0x43fe4a
    goto L_0x0043fe4a;
L_0x0043fea8:
    // 0043fea8  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0043feaa  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043feac  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043feaf  c1e203                 +shl edx, 3
    {
        x86::reg8 tmp = 3 /*0x3*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0043feb2  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043feb4  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0043feb7  8d3c28                 -lea edi, [eax + ebp]
    cpu.edi = x86::reg32(cpu.eax + cpu.ebp * 1);
    // 0043feba  89b9f0020000           -mov dword ptr [ecx + 0x2f0], edi
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(752) /* 0x2f0 */) = cpu.edi;
    // 0043fec0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fec1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fec2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fec3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fec4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fec5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fec6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0043fec7:
    // 0043fec7  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 0043fec9  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043fecb  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043fecd  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043fed0  c1e203                 +shl edx, 3
    {
        x86::reg8 tmp = 3 /*0x3*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0043fed3  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043fed5  c1f803                 -sar eax, 3
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (3 /*0x3*/ % 32));
    // 0043fed8  89eb                   -mov ebx, ebp
    cpu.ebx = cpu.ebp;
    // 0043feda  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0043fedc  8999f0020000           -mov dword ptr [ecx + 0x2f0], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(752) /* 0x2f0 */) = cpu.ebx;
    // 0043fee2  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fee3  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fee4  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fee5  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fee6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fee7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0043fee8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_43fef0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 0043fef0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 0043fef1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0043fef2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 0043fef3  83ec0c                 -sub esp, 0xc
    (cpu.esp) -= x86::reg32(x86::sreg32(12 /*0xc*/));
    // 0043fef6  8b5c2428               -mov ebx, dword ptr [esp + 0x28]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0043fefa  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0043fefc  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043fefe  81fa00000f00           +cmp edx, 0xf0000
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(983040 /*0xf0000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ff04  7c10                   -jl 0x43ff16
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0043ff16;
    }
    // 0043ff06  81b9b802000000001400   +cmp dword ptr [ecx + 0x2b8], 0x140000
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(696) /* 0x2b8 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1310720 /*0x140000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ff10  0f8f06020000           -jg 0x44011c
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0044011c;
    }
L_0x0043ff16:
    // 0043ff16  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0043ff17  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0043ff19  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0043ff1c  81cb00000400           -or ebx, 0x40000
    cpu.ebx |= x86::reg32(x86::sreg32(262144 /*0x40000*/));
    // 0043ff22  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0043ff24  c7816401000000000000   -mov dword ptr [ecx + 0x164], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(356) /* 0x164 */) = 0 /*0x0*/;
    // 0043ff2e  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043ff30  8b91a0010000           -mov edx, dword ptr [ecx + 0x1a0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(416) /* 0x1a0 */);
    // 0043ff36  898160010000           -mov dword ptr [ecx + 0x160], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(352) /* 0x160 */) = cpu.eax;
    // 0043ff3c  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0043ff40  899968010000           -mov dword ptr [ecx + 0x168], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(360) /* 0x168 */) = cpu.ebx;
    // 0043ff46  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ff48  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ff4b  c1e810                 +shr eax, 0x10
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
    // 0043ff4e  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ff50  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0043ff52  8b91a4010000           -mov edx, dword ptr [ecx + 0x1a4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(420) /* 0x1a4 */);
    // 0043ff58  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0043ff5c  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ff5e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ff61  c1e810                 +shr eax, 0x10
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
    // 0043ff64  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ff66  8b91a8010000           -mov edx, dword ptr [ecx + 0x1a8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(424) /* 0x1a8 */);
    // 0043ff6c  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0043ff6e  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0043ff72  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043ff74  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043ff77  c1e810                 +shr eax, 0x10
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
    // 0043ff7a  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ff7c  8d1403                 -lea edx, [ebx + eax]
    cpu.edx = x86::reg32(cpu.ebx + cpu.eax * 1);
    // 0043ff7f  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043ff81  0f8ec3010000           -jle 0x44014a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044014a;
    }
    // 0043ff87  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
L_0x0043ff89:
    // 0043ff89  8b1d04225100           -mov ebx, dword ptr [0x512204]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5317124) /* 0x512204 */);
    // 0043ff8f  8d04dd00000000         -lea eax, [ebx*8]
    cpu.eax = x86::reg32(cpu.ebx * 8);
    // 0043ff96  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0043ff98  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 0043ff9b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 0043ff9d  3b3485981d5100         +cmp esi, dword ptr [eax*4 + 0x511d98]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5315992) /* 0x511d98 */ + cpu.eax * 4)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ffa4  0f8e07020000           -jle 0x4401b1
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004401b1;
    }
    // 0043ffaa  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 0043ffab  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0043ffad  0f8ca0010000           -jl 0x440153
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00440153;
    }
L_0x0043ffb3:
    // 0043ffb3  8b81b8020000           -mov eax, dword ptr [ecx + 0x2b8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(696) /* 0x2b8 */);
    // 0043ffb9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0043ffbb  0f8eb5010000           -jle 0x440176
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00440176;
    }
    // 0043ffc1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
L_0x0043ffc3:
    // 0043ffc3  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0043ffc5  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0043ffc8  c1e204                 +shl edx, 4
    {
        x86::reg8 tmp = 4 /*0x4*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0043ffcb  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043ffcd  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 0043ffd0  3d00c00000             +cmp eax, 0xc000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(49152 /*0xc000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0043ffd5  0f8ea4010000           -jle 0x44017f
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044017f;
    }
    // 0043ffdb  bb00c00000             -mov ebx, 0xc000
    cpu.ebx = 49152 /*0xc000*/;
L_0x0043ffe0:
    // 0043ffe0  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0043ffe4  8bb1dc000000           -mov esi, dword ptr [ecx + 0xdc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(220) /* 0xdc */);
    // 0043ffea  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 0043ffec  29f0                   -sub eax, esi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.esi));
    // 0043ffee  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0043fff0  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0043fff3  c1e810                 +shr eax, 0x10
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
    // 0043fff6  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0043fff8  8b91dc000000           -mov edx, dword ptr [ecx + 0xdc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(220) /* 0xdc */);
    // 0043fffe  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00440000  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00440004  8b442428               -mov eax, dword ptr [esp + 0x28]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00440008  8bb9e0000000           -mov edi, dword ptr [ecx + 0xe0]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(224) /* 0xe0 */);
    // 0044000e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00440010  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00440012  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00440014  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00440017  c1e810                 +shr eax, 0x10
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
    // 0044001a  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0044001c  8b91e0000000           -mov edx, dword ptr [ecx + 0xe0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(224) /* 0xe0 */);
    // 00440022  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00440024  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00440028  8b44242c               -mov eax, dword ptr [esp + 0x2c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0044002c  8ba9e4000000           -mov ebp, dword ptr [ecx + 0xe4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(228) /* 0xe4 */);
    // 00440032  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00440034  29e8                   -sub eax, ebp
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00440036  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00440038  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 0044003b  c1e810                 +shr eax, 0x10
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
    // 0044003e  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00440040  8b91e4000000           -mov edx, dword ptr [ecx + 0xe4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(228) /* 0xe4 */);
    // 00440046  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00440048  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 0044004c  89542410               -mov dword ptr [esp + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00440050  e8bbe70100             -call 0x45e810
    cpu.esp -= 4;
    sub_45e810(app, cpu);
    if (cpu.terminate) return;
    // 00440055  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
L_0x00440056:
    // 00440056  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0044005a  8981dc000000           -mov dword ptr [ecx + 0xdc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(220) /* 0xdc */) = cpu.eax;
    // 00440060  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00440064  8981e0000000           -mov dword ptr [ecx + 0xe0], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(224) /* 0xe0 */) = cpu.eax;
    // 0044006a  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0044006e  8981e4000000           -mov dword ptr [ecx + 0xe4], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(228) /* 0xe4 */) = cpu.eax;
    // 00440074  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00440076  8b81d4000000           -mov eax, dword ptr [ecx + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 0044007c  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 0044007e  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00440081  c1e810                 +shr eax, 0x10
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
    // 00440084  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00440086  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00440088  8b91e0000000           -mov edx, dword ptr [ecx + 0xe0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(224) /* 0xe0 */);
    // 0044008e  8b81d8000000           -mov eax, dword ptr [ecx + 0xd8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 00440094  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00440096  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00440099  c1e810                 +shr eax, 0x10
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
    // 0044009c  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0044009e  8b91dc000000           -mov edx, dword ptr [ecx + 0xdc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(220) /* 0xdc */);
    // 004400a4  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004400a6  8b81d8000000           -mov eax, dword ptr [ecx + 0xd8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(216) /* 0xd8 */);
    // 004400ac  8999c4000000           -mov dword ptr [ecx + 0xc4], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(196) /* 0xc4 */) = cpu.ebx;
    // 004400b2  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004400b4  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004400b7  c1e810                 +shr eax, 0x10
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
    // 004400ba  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004400bc  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004400be  8b91e4000000           -mov edx, dword ptr [ecx + 0xe4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(228) /* 0xe4 */);
    // 004400c4  8b81d0000000           -mov eax, dword ptr [ecx + 0xd0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 004400ca  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004400cc  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004400cf  c1e810                 +shr eax, 0x10
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
    // 004400d2  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004400d4  8b91e0000000           -mov edx, dword ptr [ecx + 0xe0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(224) /* 0xe0 */);
    // 004400da  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 004400dc  8b81d0000000           -mov eax, dword ptr [ecx + 0xd0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(208) /* 0xd0 */);
    // 004400e2  8999c8000000           -mov dword ptr [ecx + 0xc8], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(200) /* 0xc8 */) = cpu.ebx;
    // 004400e8  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004400ea  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004400ed  c1e810                 +shr eax, 0x10
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
    // 004400f0  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004400f2  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004400f4  8b91dc000000           -mov edx, dword ptr [ecx + 0xdc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(220) /* 0xdc */);
    // 004400fa  8b81d4000000           -mov eax, dword ptr [ecx + 0xd4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(212) /* 0xd4 */);
    // 00440100  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00440102  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00440105  c1e810                 +shr eax, 0x10
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
    // 00440108  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0044010a  29c3                   -sub ebx, eax
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0044010c  8999cc000000           -mov dword ptr [ecx + 0xcc], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(204) /* 0xcc */) = cpu.ebx;
    // 00440112  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440113  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00440116  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440117  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440118  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440119  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0044011c:
    // 0044011c  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044011e  81cb00000400           -or ebx, 0x40000
    cpu.ebx |= x86::reg32(x86::sreg32(262144 /*0x40000*/));
    // 00440124  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00440127  c7816401000000000000   -mov dword ptr [ecx + 0x164], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(356) /* 0x164 */) = 0 /*0x0*/;
    // 00440131  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00440133  899968010000           -mov dword ptr [ecx + 0x168], ebx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(360) /* 0x168 */) = cpu.ebx;
    // 00440139  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044013b  898160010000           -mov dword ptr [ecx + 0x160], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(352) /* 0x160 */) = cpu.eax;
    // 00440141  83c40c                 -add esp, 0xc
    (cpu.esp) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00440144  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440145  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440146  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440147  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x0044014a:
    // 0044014a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0044014c  f7de                   +neg esi
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.esi;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0044014e  e936feffff             -jmp 0x43ff89
    goto L_0x0043ff89;
L_0x00440153:
    // 00440153  8b7c2428               -mov edi, dword ptr [esp + 0x28]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00440157  8b6c242c               -mov ebp, dword ptr [esp + 0x2c]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */);
    // 0044015b  8b742424               -mov esi, dword ptr [esp + 0x24]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 0044015f  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
    // 00440161  f7dd                   -neg ebp
    cpu.ebp = ~cpu.ebp + 1;
    // 00440163  f7de                   +neg esi
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.esi;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 00440165  897c2428               -mov dword ptr [esp + 0x28], edi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.edi;
    // 00440169  896c242c               -mov dword ptr [esp + 0x2c], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(44) /* 0x2c */) = cpu.ebp;
    // 0044016d  89742424               -mov dword ptr [esp + 0x24], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.esi;
    // 00440171  e93dfeffff             -jmp 0x43ffb3
    goto L_0x0043ffb3;
L_0x00440176:
    // 00440176  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00440178  f7da                   +neg edx
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
    // 0044017a  e944feffff             -jmp 0x43ffc3
    goto L_0x0043ffc3;
L_0x0044017f:
    // 0044017f  8b91b8020000           -mov edx, dword ptr [ecx + 0x2b8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(696) /* 0x2b8 */);
    // 00440185  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00440187  7e24                   -jle 0x4401ad
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004401ad;
    }
L_0x00440189:
    // 00440189  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044018b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0044018e  c1e204                 +shl edx, 4
    {
        x86::reg8 tmp = 4 /*0x4*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00440191  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00440193  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 00440196  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00440198  3d33330000             +cmp eax, 0x3333
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(13107 /*0x3333*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044019d  0f8f3dfeffff           -jg 0x43ffe0
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x0043ffe0;
    }
    // 004401a3  bb33330000             -mov ebx, 0x3333
    cpu.ebx = 13107 /*0x3333*/;
    // 004401a8  e933feffff             -jmp 0x43ffe0
    goto L_0x0043ffe0;
L_0x004401ad:
    // 004401ad  f7da                   +neg edx
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
    // 004401af  ebd8                   -jmp 0x440189
    goto L_0x00440189;
L_0x004401b1:
    // 004401b1  8aa1d7020000           -mov ah, byte ptr [ecx + 0x2d7]
    cpu.ah = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(727) /* 0x2d7 */);
    // 004401b7  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004401b9  80fc32                 +cmp ah, 0x32
    {
        x86::reg8 tmp1 = cpu.ah;
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(50 /*0x32*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004401bc  7606                   -jbe 0x4401c4
    if (cpu.flags.cf || cpu.flags.zf)
    {
        goto L_0x004401c4;
    }
    // 004401be  8b99e4020000           -mov ebx, dword ptr [ecx + 0x2e4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(740) /* 0x2e4 */);
L_0x004401c4:
    // 004401c4  8b81c4000000           -mov eax, dword ptr [ecx + 0xc4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(196) /* 0xc4 */);
    // 004401ca  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004401cc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004401cf  c1e207                 +shl edx, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004401d2  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004401d4  c1f807                 -sar eax, 7
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (7 /*0x7*/ % 32));
    // 004401d7  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004401da  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004401dc  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004401df  c1e204                 +shl edx, 4
    {
        x86::reg8 tmp = 4 /*0x4*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004401e2  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004401e4  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 004401e7  8b91dc000000           -mov edx, dword ptr [ecx + 0xdc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(220) /* 0xdc */);
    // 004401ed  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004401ef  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 004401f3  8b81c8000000           -mov eax, dword ptr [ecx + 0xc8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(200) /* 0xc8 */);
    // 004401f9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004401fb  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004401fe  c1e207                 +shl edx, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00440201  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00440203  c1f807                 -sar eax, 7
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (7 /*0x7*/ % 32));
    // 00440206  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00440209  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044020b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0044020e  c1e204                 +shl edx, 4
    {
        x86::reg8 tmp = 4 /*0x4*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00440211  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00440213  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 00440216  8b91e0000000           -mov edx, dword ptr [ecx + 0xe0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(224) /* 0xe0 */);
    // 0044021c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044021e  89542408               -mov dword ptr [esp + 8], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00440222  8b81cc000000           -mov eax, dword ptr [ecx + 0xcc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(204) /* 0xcc */);
    // 00440228  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044022a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0044022d  c1e207                 +shl edx, 7
    {
        x86::reg8 tmp = 7 /*0x7*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00440230  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00440232  c1f807                 -sar eax, 7
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (7 /*0x7*/ % 32));
    // 00440235  0fafc3                 -imul eax, ebx
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 00440238  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044023a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0044023d  c1e204                 +shl edx, 4
    {
        x86::reg8 tmp = 4 /*0x4*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00440240  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00440242  c1f804                 -sar eax, 4
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (4 /*0x4*/ % 32));
    // 00440245  8b91e4000000           -mov edx, dword ptr [ecx + 0xe4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(228) /* 0xe4 */);
    // 0044024b  01c2                   +add edx, eax
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
    // 0044024d  8d442404               -lea eax, [esp + 4]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00440251  8954240c               -mov dword ptr [esp + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00440255  e8b6e50100             -call 0x45e810
    cpu.esp -= 4;
    sub_45e810(app, cpu);
    if (cpu.terminate) return;
    // 0044025a  e9f7fdffff             -jmp 0x440056
    goto L_0x00440056;
}

/* align: skip 0x00 */
void Application::sub_440260(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440260  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00440262  7e08                   -jle 0x44026c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044026c;
    }
    // 00440264  8b8490cc030000         -mov eax, dword ptr [eax + edx*4 + 0x3cc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(972) /* 0x3cc */ + cpu.edx * 4);
    // 0044026b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044026c:
    // 0044026c  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044026e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_440270(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440270  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440271  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00440273  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00440275  833d2822510000         +cmp dword ptr [0x512228], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044027c  7456                   -je 0x4402d4
    if (cpu.flags.zf)
    {
        goto L_0x004402d4;
    }
    // 0044027e  f680f401000008         +test byte ptr [eax + 0x1f4], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(500) /* 0x1f4 */) & 8 /*0x8*/));
    // 00440285  742f                   -je 0x4402b6
    if (cpu.flags.zf)
    {
        goto L_0x004402b6;
    }
    // 00440287  8b80e8010000           -mov eax, dword ptr [eax + 0x1e8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(488) /* 0x1e8 */);
    // 0044028d  8b0485d8a95000         -mov eax, dword ptr [eax*4 + 0x50a9d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5286360) /* 0x50a9d8 */ + cpu.eax * 4);
    // 00440294  8b98bc000000           -mov ebx, dword ptr [eax + 0xbc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */);
    // 0044029a  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 0044029c  8b80c0000000           -mov eax, dword ptr [eax + 0xc0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(192) /* 0xc0 */);
L_0x004402a2:
    // 004402a2  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004402a4  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004402a7  c1e810                 +shr eax, 0x10
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
    // 004402aa  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004402ac  39d8                   +cmp eax, ebx
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
    // 004402ae  7e16                   -jle 0x4402c6
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004402c6;
    }
    // 004402b0  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004402b2  7e0e                   -jle 0x4402c2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004402c2;
    }
    // 004402b4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004402b5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004402b6:
    // 004402b6  b800400000             -mov eax, 0x4000
    cpu.eax = 16384 /*0x4000*/;
    // 004402bb  bb33330300             -mov ebx, 0x33333
    cpu.ebx = 209715 /*0x33333*/;
    // 004402c0  ebe0                   -jmp 0x4402a2
    goto L_0x004402a2;
L_0x004402c2:
    // 004402c2  f7d8                   -neg eax
    cpu.eax = ~cpu.eax + 1;
    // 004402c4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004402c5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004402c6:
    // 004402c6  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004402c8  7e04                   -jle 0x4402ce
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004402ce;
    }
    // 004402ca  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004402cc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004402cd  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004402ce:
    // 004402ce  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 004402d0  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 004402d2  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004402d3  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004402d4:
    // 004402d4  f680f401000008         +test byte ptr [eax + 0x1f4], 8
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(500) /* 0x1f4 */) & 8 /*0x8*/));
    // 004402db  742d                   -je 0x44030a
    if (cpu.flags.zf)
    {
        goto L_0x0044030a;
    }
    // 004402dd  8b80e8010000           -mov eax, dword ptr [eax + 0x1e8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(488) /* 0x1e8 */);
    // 004402e3  8b0485d8a95000         -mov eax, dword ptr [eax*4 + 0x50a9d8]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5286360) /* 0x50a9d8 */ + cpu.eax * 4);
    // 004402ea  8b98bc000000           -mov ebx, dword ptr [eax + 0xbc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(188) /* 0xbc */);
    // 004402f0  8b80c0000000           -mov eax, dword ptr [eax + 0xc0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(192) /* 0xc0 */);
L_0x004402f6:
    // 004402f6  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004402f8  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004402fb  c1e810                 +shr eax, 0x10
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
    // 004402fe  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00440300  39d8                   +cmp eax, ebx
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
    // 00440302  7d12                   -jge 0x440316
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00440316;
    }
    // 00440304  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00440306  7eba                   -jle 0x4402c2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004402c2;
    }
    // 00440308  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440309  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044030a:
    // 0044030a  b800400000             -mov eax, 0x4000
    cpu.eax = 16384 /*0x4000*/;
    // 0044030f  bb33330300             -mov ebx, 0x33333
    cpu.ebx = 209715 /*0x33333*/;
    // 00440314  ebe0                   -jmp 0x4402f6
    goto L_0x004402f6;
L_0x00440316:
    // 00440316  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00440318  7e04                   -jle 0x44031e
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044031e;
    }
    // 0044031a  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 0044031c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044031d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044031e:
    // 0044031e  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 00440320  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00440322  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440323  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_440330(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440330  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_440340(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440340  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_440350(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440350  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_440360(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440360  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_440370(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440370  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440371  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440372  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440373  8b981c020000           -mov ebx, dword ptr [eax + 0x21c]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(540) /* 0x21c */);
    // 00440379  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0044037b  83fb0f                 +cmp ebx, 0xf
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044037e  7d39                   -jge 0x4403b9
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004403b9;
    }
    // 00440380  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00440382  c1e303                 -shl ebx, 3
    cpu.ebx <<= 3 /*0x3*/ % 32;
    // 00440385  8db2e0000000           -lea esi, [edx + 0xe0]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(224) /* 0xe0 */);
L_0x0044038b:
    // 0044038b  0fbf01                 -movsx eax, word ptr [ecx]
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(app->getMemory<x86::reg16>(cpu.ecx)));
    // 0044038e  8b1504225100           -mov edx, dword ptr [0x512204]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317124) /* 0x512204 */);
    // 00440394  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00440397  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00440399  7422                   -je 0x4403bd
    if (cpu.flags.zf)
    {
        goto L_0x004403bd;
    }
    // 0044039b  8b93dc584d00           -mov edx, dword ptr [ebx + 0x4d58dc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5069020) /* 0x4d58dc */);
L_0x004403a1:
    // 004403a1  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004403a3  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004403a6  c1e810                 +shr eax, 0x10
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
    // 004403a9  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004403ab  83c102                 -add ecx, 2
    (cpu.ecx) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 004403ae  c1f808                 -sar eax, 8
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (8 /*0x8*/ % 32));
    // 004403b1  668941fe               -mov word ptr [ecx - 2], ax
    app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(-2) /* -0x2 */) = cpu.ax;
    // 004403b5  39f1                   +cmp ecx, esi
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
    // 004403b7  75d2                   -jne 0x44038b
    if (!cpu.flags.zf)
    {
        goto L_0x0044038b;
    }
L_0x004403b9:
    // 004403b9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004403ba  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004403bb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004403bc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004403bd:
    // 004403bd  8b93d8584d00           -mov edx, dword ptr [ebx + 0x4d58d8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5069016) /* 0x4d58d8 */);
    // 004403c3  ebdc                   -jmp 0x4403a1
    goto L_0x004403a1;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4403d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004403d0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004403d1  8b1598574d00           -mov edx, dword ptr [0x4d5798]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5068696) /* 0x4d5798 */);
    // 004403d7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004403d9  7502                   -jne 0x4403dd
    if (!cpu.flags.zf)
    {
        goto L_0x004403dd;
    }
    // 004403db  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004403dc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004403dd:
    // 004403dd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004403de  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004403e0  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004403e2  e815450400             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 004403e7  890d98574d00           -mov dword ptr [0x4d5798], ecx
    app->getMemory<x86::reg32>(x86::reg32(5068696) /* 0x4d5798 */) = cpu.ecx;
    // 004403ed  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004403ee  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004403ef  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4403f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004403f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004403f1  8b1594574d00           -mov edx, dword ptr [0x4d5794]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5068692) /* 0x4d5794 */);
    // 004403f7  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 004403f9  7502                   -jne 0x4403fd
    if (!cpu.flags.zf)
    {
        goto L_0x004403fd;
    }
    // 004403fb  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004403fc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004403fd:
    // 004403fd  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004403fe  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00440400  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00440402  e8f5440400             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 00440407  890d94574d00           -mov dword ptr [0x4d5794], ecx
    app->getMemory<x86::reg32>(x86::reg32(5068692) /* 0x4d5794 */) = cpu.ecx;
    // 0044040d  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044040e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044040f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_440410(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440410  e8dbffffff             -call 0x4403f0
    cpu.esp -= 4;
    sub_4403f0(app, cpu);
    if (cpu.terminate) return;
    // 00440415  e9b6ffffff             -jmp 0x4403d0
    return sub_4403d0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_440420(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440420  833d0422510000         +cmp dword ptr [0x512204], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317124) /* 0x512204 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440427  750c                   -jne 0x440435
    if (!cpu.flags.zf)
    {
        goto L_0x00440435;
    }
    // 00440429  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 0044042b  a314ad5000             -mov dword ptr [0x50ad14], eax
    app->getMemory<x86::reg32>(x86::reg32(5287188) /* 0x50ad14 */) = cpu.eax;
    // 00440430  e99b000000             -jmp 0x4404d0
    return sub_4404d0(app, cpu);
L_0x00440435:
    // 00440435  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 0044043a  a314ad5000             -mov dword ptr [0x50ad14], eax
    app->getMemory<x86::reg32>(x86::reg32(5287188) /* 0x50ad14 */) = cpu.eax;
    // 0044043f  e98c000000             -jmp 0x4404d0
    return sub_4404d0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_440450(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440450  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440451  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440452  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440453  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440454  8b1da0185100           -mov ebx, dword ptr [0x5118a0]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5314720) /* 0x5118a0 */);
    // 0044045a  8b3594574d00           -mov esi, dword ptr [0x4d5794]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5068692) /* 0x4d5794 */);
    // 00440460  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00440462  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00440464  7e1a                   -jle 0x440480
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00440480;
    }
L_0x00440466:
    // 00440466  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00440468  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 0044046a  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0044046d  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044046f  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00440471  8d1400                 -lea edx, [eax + eax]
    cpu.edx = x86::reg32(cpu.eax + cpu.eax * 1);
    // 00440474  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00440476  41                     -inc ecx
    (cpu.ecx)++;
    // 00440477  c6040232               -mov byte ptr [edx + eax], 0x32
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 50 /*0x32*/;
    // 0044047b  39d9                   +cmp ecx, ebx
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
    // 0044047d  7ce7                   -jl 0x440466
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00440466;
    }
    // 0044047f  90                     -nop 
    ;
L_0x00440480:
    // 00440480  893594574d00           -mov dword ptr [0x4d5794], esi
    app->getMemory<x86::reg32>(x86::reg32(5068692) /* 0x4d5794 */) = cpu.esi;
    // 00440486  891da0185100           -mov dword ptr [0x5118a0], ebx
    app->getMemory<x86::reg32>(x86::reg32(5314720) /* 0x5118a0 */) = cpu.ebx;
    // 0044048c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044048d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044048e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044048f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440490  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4404a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004404a0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004404a1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004404a2  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004404a3  8b0da0185100           -mov ecx, dword ptr [0x5118a0]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5314720) /* 0x5118a0 */);
    // 004404a9  8b3598574d00           -mov esi, dword ptr [0x4d5798]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5068696) /* 0x4d5798 */);
    // 004404af  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004404b1  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004404b3  7e0b                   -jle 0x4404c0
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004404c0;
    }
    // 004404b5  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
L_0x004404b7:
    // 004404b7  c6040200               -mov byte ptr [edx + eax], 0
    app->getMemory<x86::reg8>(cpu.edx + cpu.eax * 1) = 0 /*0x0*/;
    // 004404bb  40                     -inc eax
    (cpu.eax)++;
    // 004404bc  39c8                   +cmp eax, ecx
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
    // 004404be  7cf7                   -jl 0x4404b7
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004404b7;
    }
L_0x004404c0:
    // 004404c0  893598574d00           -mov dword ptr [0x4d5798], esi
    app->getMemory<x86::reg32>(x86::reg32(5068696) /* 0x4d5798 */) = cpu.esi;
    // 004404c6  890da0185100           -mov dword ptr [0x5118a0], ecx
    app->getMemory<x86::reg32>(x86::reg32(5314720) /* 0x5118a0 */) = cpu.ecx;
    // 004404cc  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004404cd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004404ce  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004404cf  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4404d0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004404d0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004404d1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004404d2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004404d3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004404d4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004404d5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004404d6  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 004404d8  81ec88000000           -sub esp, 0x88
    (cpu.esp) -= x86::reg32(x86::sreg32(136 /*0x88*/));
    // 004404de  81ed86000000           -sub ebp, 0x86
    (cpu.ebp) -= x86::reg32(x86::sreg32(134 /*0x86*/));
    // 004404e4  8b1514ad5000           -mov edx, dword ptr [0x50ad14]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287188) /* 0x50ad14 */);
    // 004404ea  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 004404f1  be9c574d00             -mov esi, 0x4d579c
    cpu.esi = 5068700 /*0x4d579c*/;
    // 004404f6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004404f8  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 004404fb  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 004404fd  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x004404fe:
    // 004404fe  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00440500  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00440502  3c00                   +cmp al, 0
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
    // 00440504  7410                   -je 0x440516
    if (cpu.flags.zf)
    {
        goto L_0x00440516;
    }
    // 00440506  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 00440509  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044050c  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 0044050f  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00440512  3c00                   +cmp al, 0
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
    // 00440514  75e8                   -jne 0x4404fe
    if (!cpu.flags.zf)
    {
        goto L_0x004404fe;
    }
L_0x00440516:
    // 00440516  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440517  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044051a  e811330200             -call 0x463830
    cpu.esp -= 4;
    sub_463830(app, cpu);
    if (cpu.terminate) return;
    // 0044051f  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00440522  8b1528225100           -mov edx, dword ptr [0x512228]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */);
    // 00440528  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00440529  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044052b  0f8409010000           -je 0x44063a
    if (cpu.flags.zf)
    {
        goto L_0x0044063a;
    }
    // 00440531  b864ba4c00             -mov eax, 0x4cba64
    cpu.eax = 5028452 /*0x4cba64*/;
L_0x00440536:
    // 00440536  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00440537  8b0d1c225100           -mov ecx, dword ptr [0x51221c]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5317148) /* 0x51221c */);
    // 0044053d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 0044053e  8b1d8c345100           -mov ebx, dword ptr [0x51348c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5321868) /* 0x51348c */);
    // 00440544  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440545  686cba4c00             -push 0x4cba6c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5028460 /*0x4cba6c*/;
    cpu.esp -= 4;
    // 0044054a  8d45fe                 -lea eax, [ebp - 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 0044054d  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0044054e  e8ae5f0400             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 00440553  8b1514ad5000           -mov edx, dword ptr [0x50ad14]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5287188) /* 0x50ad14 */);
    // 00440559  bea6574d00             -mov esi, 0x4d57a6
    cpu.esi = 5068710 /*0x4d57a6*/;
    // 0044055e  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00440565  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00440568  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 0044056a  8d7d7e                 -lea edi, [ebp + 0x7e]
    cpu.edi = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044056d  01c6                   -add esi, eax
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044056f  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
L_0x00440570:
    // 00440570  8a06                   -mov al, byte ptr [esi]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi);
    // 00440572  8807                   -mov byte ptr [edi], al
    app->getMemory<x86::reg8>(cpu.edi) = cpu.al;
    // 00440574  3c00                   +cmp al, 0
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
    // 00440576  7410                   -je 0x440588
    if (cpu.flags.zf)
    {
        goto L_0x00440588;
    }
    // 00440578  8a4601                 -mov al, byte ptr [esi + 1]
    cpu.al = app->getMemory<x86::reg8>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 0044057b  83c602                 -add esi, 2
    (cpu.esi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 0044057e  884701                 -mov byte ptr [edi + 1], al
    app->getMemory<x86::reg8>(cpu.edi + x86::reg32(1) /* 0x1 */) = cpu.al;
    // 00440581  83c702                 -add edi, 2
    (cpu.edi) += x86::reg32(x86::sreg32(2 /*0x2*/));
    // 00440584  3c00                   +cmp al, 0
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
    // 00440586  75e8                   -jne 0x440570
    if (!cpu.flags.zf)
    {
        goto L_0x00440570;
    }
L_0x00440588:
    // 00440588  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440589  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 0044058c  e89f320200             -call 0x463830
    cpu.esp -= 4;
    sub_463830(app, cpu);
    if (cpu.terminate) return;
    // 00440591  8d457e                 -lea eax, [ebp + 0x7e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(126) /* 0x7e */);
    // 00440594  8b3528225100           -mov esi, dword ptr [0x512228]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */);
    // 0044059a  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0044059b  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0044059d  0f84a1000000           -je 0x440644
    if (cpu.flags.zf)
    {
        goto L_0x00440644;
    }
    // 004405a3  b864ba4c00             -mov eax, 0x4cba64
    cpu.eax = 5028452 /*0x4cba64*/;
L_0x004405a8:
    // 004405a8  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004405a9  8b3d1c225100           -mov edi, dword ptr [0x51221c]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5317148) /* 0x51221c */);
    // 004405af  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004405b0  a18c345100             -mov eax, dword ptr [0x51348c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5321868) /* 0x51348c */);
    // 004405b5  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004405b6  686cba4c00             -push 0x4cba6c
    app->getMemory<x86::reg32>(cpu.esp-4) = 5028460 /*0x4cba6c*/;
    cpu.esp -= 4;
    // 004405bb  8d453e                 -lea eax, [ebp + 0x3e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(62) /* 0x3e */);
    // 004405be  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004405bf  e83d5f0400             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 004405c4  83c418                 -add esp, 0x18
    (cpu.esp) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004405c7  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004405c9  8d45fe                 -lea eax, [ebp - 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 004405cc  e8b3d30500             -call 0x49d984
    cpu.esp -= 4;
    sub_49d984(app, cpu);
    if (cpu.terminate) return;
    // 004405d1  a394574d00             -mov dword ptr [0x4d5794], eax
    app->getMemory<x86::reg32>(x86::reg32(5068692) /* 0x4d5794 */) = cpu.eax;
    // 004405d6  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004405d8  7474                   -je 0x44064e
    if (cpu.flags.zf)
    {
        goto L_0x0044064e;
    }
L_0x004405da:
    // 004405da  8d453e                 -lea eax, [ebp + 0x3e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(62) /* 0x3e */);
    // 004405dd  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004405df  e8a0d30500             -call 0x49d984
    cpu.esp -= 4;
    sub_49d984(app, cpu);
    if (cpu.terminate) return;
    // 004405e4  a398574d00             -mov dword ptr [0x4d5798], eax
    app->getMemory<x86::reg32>(x86::reg32(5068696) /* 0x4d5798 */) = cpu.eax;
    // 004405e9  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004405eb  0f84a1000000           -je 0x440692
    if (cpu.flags.zf)
    {
        goto L_0x00440692;
    }
L_0x004405f1:
    // 004405f1  833d94574d0000         +cmp dword ptr [0x4d5794], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5068692) /* 0x4d5794 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004405f8  7526                   -jne 0x440620
    if (!cpu.flags.zf)
    {
        goto L_0x00440620;
    }
    // 004405fa  c705d8b14d007cba4c00   -mov dword ptr [0x4db1d8], 0x4cba7c
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = 5028476 /*0x4cba7c*/;
    // 00440604  8d45fe                 -lea eax, [ebp - 2]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-2) /* -0x2 */);
    // 00440607  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00440608  ba6d010000             -mov edx, 0x16d
    cpu.edx = 365 /*0x16d*/;
    // 0044060d  68bcba4c00             -push 0x4cbabc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5028540 /*0x4cbabc*/;
    cpu.esp -= 4;
    // 00440612  8915dcb14d00           -mov dword ptr [0x4db1dc], edx
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.edx;
    // 00440618  e8d33a0400             -call 0x4840f0
    cpu.esp -= 4;
    sub_4840f0(app, cpu);
    if (cpu.terminate) return;
    // 0044061d  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
L_0x00440620:
    // 00440620  833d98574d0000         +cmp dword ptr [0x4d5798], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5068696) /* 0x4d5798 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440627  0f849c000000           -je 0x4406c9
    if (cpu.flags.zf)
    {
        goto L_0x004406c9;
    }
    // 0044062d  8da586000000           -lea esp, [ebp + 0x86]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(134) /* 0x86 */);
    // 00440633  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440634  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440635  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440636  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440637  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440638  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440639  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044063a:
    // 0044063a  b868ba4c00             -mov eax, 0x4cba68
    cpu.eax = 5028456 /*0x4cba68*/;
    // 0044063f  e9f2feffff             -jmp 0x440536
    goto L_0x00440536;
L_0x00440644:
    // 00440644  b868ba4c00             -mov eax, 0x4cba68
    cpu.eax = 5028456 /*0x4cba68*/;
    // 00440649  e95affffff             -jmp 0x4405a8
    goto L_0x004405a8;
L_0x0044064e:
    // 0044064e  ba7cba4c00             -mov edx, 0x4cba7c
    cpu.edx = 5028476 /*0x4cba7c*/;
    // 00440653  a1a0185100             -mov eax, dword ptr [0x5118a0]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5314720) /* 0x5118a0 */);
    // 00440658  8915d8b14d00           -mov dword ptr [0x4db1d8], edx
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.edx;
    // 0044065e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00440660  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00440663  2bc2                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00440665  d1f8                   -sar eax, 1
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (1 /*0x1*/ % 32));
    // 00440667  01c0                   -add eax, eax
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.eax));
    // 00440669  b91b010000             -mov ecx, 0x11b
    cpu.ecx = 283 /*0x11b*/;
    // 0044066e  8d5002                 -lea edx, [eax + 2]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(2) /* 0x2 */);
    // 00440671  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00440673  b8a0ba4c00             -mov eax, 0x4cbaa0
    cpu.eax = 5028512 /*0x4cbaa0*/;
    // 00440678  890ddcb14d00           -mov dword ptr [0x4db1dc], ecx
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.ecx;
    // 0044067e  e8153e0400             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 00440683  a394574d00             -mov dword ptr [0x4d5794], eax
    app->getMemory<x86::reg32>(x86::reg32(5068692) /* 0x4d5794 */) = cpu.eax;
    // 00440688  e8c3fdffff             -call 0x440450
    cpu.esp -= 4;
    sub_440450(app, cpu);
    if (cpu.terminate) return;
    // 0044068d  e948ffffff             -jmp 0x4405da
    goto L_0x004405da;
L_0x00440692:
    // 00440692  bb7cba4c00             -mov ebx, 0x4cba7c
    cpu.ebx = 5028476 /*0x4cba7c*/;
    // 00440697  be33010000             -mov esi, 0x133
    cpu.esi = 307 /*0x133*/;
    // 0044069c  b8b0ba4c00             -mov eax, 0x4cbab0
    cpu.eax = 5028528 /*0x4cbab0*/;
    // 004406a1  8b15a0185100           -mov edx, dword ptr [0x5118a0]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5314720) /* 0x5118a0 */);
    // 004406a7  891dd8b14d00           -mov dword ptr [0x4db1d8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.ebx;
    // 004406ad  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 004406af  8935dcb14d00           -mov dword ptr [0x4db1dc], esi
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.esi;
    // 004406b5  e8de3d0400             -call 0x484498
    cpu.esp -= 4;
    sub_484498(app, cpu);
    if (cpu.terminate) return;
    // 004406ba  a398574d00             -mov dword ptr [0x4d5798], eax
    app->getMemory<x86::reg32>(x86::reg32(5068696) /* 0x4d5798 */) = cpu.eax;
    // 004406bf  e8dcfdffff             -call 0x4404a0
    cpu.esp -= 4;
    sub_4404a0(app, cpu);
    if (cpu.terminate) return;
    // 004406c4  e928ffffff             -jmp 0x4405f1
    goto L_0x004405f1;
L_0x004406c9:
    // 004406c9  8d453e                 -lea eax, [ebp + 0x3e]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(62) /* 0x3e */);
    // 004406cc  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004406cd  bb7cba4c00             -mov ebx, 0x4cba7c
    cpu.ebx = 5028476 /*0x4cba7c*/;
    // 004406d2  be6e010000             -mov esi, 0x16e
    cpu.esi = 366 /*0x16e*/;
    // 004406d7  68bcba4c00             -push 0x4cbabc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5028540 /*0x4cbabc*/;
    cpu.esp -= 4;
    // 004406dc  891dd8b14d00           -mov dword ptr [0x4db1d8], ebx
    app->getMemory<x86::reg32>(x86::reg32(5091800) /* 0x4db1d8 */) = cpu.ebx;
    // 004406e2  8935dcb14d00           -mov dword ptr [0x4db1dc], esi
    app->getMemory<x86::reg32>(x86::reg32(5091804) /* 0x4db1dc */) = cpu.esi;
    // 004406e8  e8033a0400             -call 0x4840f0
    cpu.esp -= 4;
    sub_4840f0(app, cpu);
    if (cpu.terminate) return;
    // 004406ed  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004406f0  8da586000000           -lea esp, [ebp + 0x86]
    cpu.esp = x86::reg32(cpu.ebp + x86::reg32(134) /* 0x86 */);
    // 004406f6  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004406f7  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004406f8  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004406f9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004406fa  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004406fb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004406fc  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_440700(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440700  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440701  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440702  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440703  6890010000             -push 0x190
    app->getMemory<x86::reg32>(cpu.esp-4) = 400 /*0x190*/;
    cpu.esp -= 4;
    // 00440708  6800000100             -push 0x10000
    app->getMemory<x86::reg32>(cpu.esp-4) = 65536 /*0x10000*/;
    cpu.esp -= 4;
    // 0044070d  6800000100             -push 0x10000
    app->getMemory<x86::reg32>(cpu.esp-4) = 65536 /*0x10000*/;
    cpu.esp -= 4;
    // 00440712  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 00440717  bbf4010000             -mov ebx, 0x1f4
    cpu.ebx = 500 /*0x1f4*/;
    // 0044071c  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0044071e  b818ad5000             -mov eax, 0x50ad18
    cpu.eax = 5287192 /*0x50ad18*/;
    // 00440723  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00440725  e826010000             -call 0x440850
    cpu.esp -= 4;
    sub_440850(app, cpu);
    if (cpu.terminate) return;
    // 0044072a  6890010000             -push 0x190
    app->getMemory<x86::reg32>(cpu.esp-4) = 400 /*0x190*/;
    cpu.esp -= 4;
    // 0044072f  6800000100             -push 0x10000
    app->getMemory<x86::reg32>(cpu.esp-4) = 65536 /*0x10000*/;
    cpu.esp -= 4;
    // 00440734  6800000100             -push 0x10000
    app->getMemory<x86::reg32>(cpu.esp-4) = 65536 /*0x10000*/;
    cpu.esp -= 4;
    // 00440739  bb14050000             -mov ebx, 0x514
    cpu.ebx = 1300 /*0x514*/;
    // 0044073e  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00440743  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00440745  b850ad5000             -mov eax, 0x50ad50
    cpu.eax = 5287248 /*0x50ad50*/;
    // 0044074a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044074c  e8ff000000             -call 0x440850
    cpu.esp -= 4;
    sub_440850(app, cpu);
    if (cpu.terminate) return;
    // 00440751  6890010000             -push 0x190
    app->getMemory<x86::reg32>(cpu.esp-4) = 400 /*0x190*/;
    cpu.esp -= 4;
    // 00440756  683d0a0100             -push 0x10a3d
    app->getMemory<x86::reg32>(cpu.esp-4) = 68157 /*0x10a3d*/;
    cpu.esp -= 4;
    // 0044075b  6800000100             -push 0x10000
    app->getMemory<x86::reg32>(cpu.esp-4) = 65536 /*0x10000*/;
    cpu.esp -= 4;
    // 00440760  bb90010000             -mov ebx, 0x190
    cpu.ebx = 400 /*0x190*/;
    // 00440765  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 0044076a  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0044076c  b86cad5000             -mov eax, 0x50ad6c
    cpu.eax = 5287276 /*0x50ad6c*/;
    // 00440771  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00440773  e8d8000000             -call 0x440850
    cpu.esp -= 4;
    sub_440850(app, cpu);
    if (cpu.terminate) return;
    // 00440778  6890010000             -push 0x190
    app->getMemory<x86::reg32>(cpu.esp-4) = 400 /*0x190*/;
    cpu.esp -= 4;
    // 0044077d  6800000100             -push 0x10000
    app->getMemory<x86::reg32>(cpu.esp-4) = 65536 /*0x10000*/;
    cpu.esp -= 4;
    // 00440782  6800000100             -push 0x10000
    app->getMemory<x86::reg32>(cpu.esp-4) = 65536 /*0x10000*/;
    cpu.esp -= 4;
    // 00440787  bb20030000             -mov ebx, 0x320
    cpu.ebx = 800 /*0x320*/;
    // 0044078c  ba08000000             -mov edx, 8
    cpu.edx = 8 /*0x8*/;
    // 00440791  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00440793  b888ad5000             -mov eax, 0x50ad88
    cpu.eax = 5287304 /*0x50ad88*/;
    // 00440798  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044079a  e8b1000000             -call 0x440850
    cpu.esp -= 4;
    sub_440850(app, cpu);
    if (cpu.terminate) return;
    // 0044079f  6890010000             -push 0x190
    app->getMemory<x86::reg32>(cpu.esp-4) = 400 /*0x190*/;
    cpu.esp -= 4;
    // 004407a4  68e1fa0000             -push 0xfae1
    app->getMemory<x86::reg32>(cpu.esp-4) = 64225 /*0xfae1*/;
    cpu.esp -= 4;
    // 004407a9  68a3f00000             -push 0xf0a3
    app->getMemory<x86::reg32>(cpu.esp-4) = 61603 /*0xf0a3*/;
    cpu.esp -= 4;
    // 004407ae  bb90010000             -mov ebx, 0x190
    cpu.ebx = 400 /*0x190*/;
    // 004407b3  ba0c000000             -mov edx, 0xc
    cpu.edx = 12 /*0xc*/;
    // 004407b8  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004407ba  b8a4ad5000             -mov eax, 0x50ada4
    cpu.eax = 5287332 /*0x50ada4*/;
    // 004407bf  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 004407c1  e88a000000             -call 0x440850
    cpu.esp -= 4;
    sub_440850(app, cpu);
    if (cpu.terminate) return;
    // 004407c6  6890010000             -push 0x190
    app->getMemory<x86::reg32>(cpu.esp-4) = 400 /*0x190*/;
    cpu.esp -= 4;
    // 004407cb  6800000100             -push 0x10000
    app->getMemory<x86::reg32>(cpu.esp-4) = 65536 /*0x10000*/;
    cpu.esp -= 4;
    // 004407d0  6800000100             -push 0x10000
    app->getMemory<x86::reg32>(cpu.esp-4) = 65536 /*0x10000*/;
    cpu.esp -= 4;
    // 004407d5  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 004407da  bb94110000             -mov ebx, 0x1194
    cpu.ebx = 4500 /*0x1194*/;
    // 004407df  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 004407e1  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 004407e6  b8c0ad5000             -mov eax, 0x50adc0
    cpu.eax = 5287360 /*0x50adc0*/;
    // 004407eb  e860000000             -call 0x440850
    cpu.esp -= 4;
    sub_440850(app, cpu);
    if (cpu.terminate) return;
    // 004407f0  6890010000             -push 0x190
    app->getMemory<x86::reg32>(cpu.esp-4) = 400 /*0x190*/;
    cpu.esp -= 4;
    // 004407f5  6851f80000             -push 0xf851
    app->getMemory<x86::reg32>(cpu.esp-4) = 63569 /*0xf851*/;
    cpu.esp -= 4;
    // 004407fa  6833f30000             -push 0xf333
    app->getMemory<x86::reg32>(cpu.esp-4) = 62259 /*0xf333*/;
    cpu.esp -= 4;
    // 004407ff  bb94110000             -mov ebx, 0x1194
    cpu.ebx = 4500 /*0x1194*/;
    // 00440804  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00440809  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 0044080b  b8dcad5000             -mov eax, 0x50addc
    cpu.eax = 5287388 /*0x50addc*/;
    // 00440810  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00440812  e839000000             -call 0x440850
    cpu.esp -= 4;
    sub_440850(app, cpu);
    if (cpu.terminate) return;
    // 00440817  6890010000             -push 0x190
    app->getMemory<x86::reg32>(cpu.esp-4) = 400 /*0x190*/;
    cpu.esp -= 4;
    // 0044081c  6800000100             -push 0x10000
    app->getMemory<x86::reg32>(cpu.esp-4) = 65536 /*0x10000*/;
    cpu.esp -= 4;
    // 00440821  6800000100             -push 0x10000
    app->getMemory<x86::reg32>(cpu.esp-4) = 65536 /*0x10000*/;
    cpu.esp -= 4;
    // 00440826  b901000000             -mov ecx, 1
    cpu.ecx = 1 /*0x1*/;
    // 0044082b  bb94110000             -mov ebx, 0x1194
    cpu.ebx = 4500 /*0x1194*/;
    // 00440830  6a01                   -push 1
    app->getMemory<x86::reg32>(cpu.esp-4) = 1 /*0x1*/;
    cpu.esp -= 4;
    // 00440832  ba03000000             -mov edx, 3
    cpu.edx = 3 /*0x3*/;
    // 00440837  b8f8ad5000             -mov eax, 0x50adf8
    cpu.eax = 5287416 /*0x50adf8*/;
    // 0044083c  e80f000000             -call 0x440850
    cpu.esp -= 4;
    sub_440850(app, cpu);
    if (cpu.terminate) return;
    // 00440841  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440842  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440843  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440844  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_440850(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440850  f6051922510004         +test byte ptr [0x512219], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(x86::reg32(5317145) /* 0x512219 */) & 4 /*0x4*/));
    // 00440857  742f                   -je 0x440888
    if (cpu.flags.zf)
    {
        goto L_0x00440888;
    }
    // 00440859  c7400400000000         -mov dword ptr [eax + 4], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00440860  c7000f000000           -mov dword ptr [eax], 0xf
    app->getMemory<x86::reg32>(cpu.eax) = 15 /*0xf*/;
L_0x00440866:
    // 00440866  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 0044086a  894808                 -mov dword ptr [eax + 8], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = cpu.ecx;
    // 0044086d  89500c                 -mov dword ptr [eax + 0xc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00440870  8b542408               -mov edx, dword ptr [esp + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00440874  895010                 -mov dword ptr [eax + 0x10], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00440877  8b54240c               -mov edx, dword ptr [esp + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 0044087b  895014                 -mov dword ptr [eax + 0x14], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0044087e  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00440882  895018                 -mov dword ptr [eax + 0x18], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 00440885  c21000                 -ret 0x10
    cpu.esp += 4+16 /*0x10*/;
    return;
L_0x00440888:
    // 00440888  895804                 -mov dword ptr [eax + 4], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 0044088b  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 0044088d  ebd7                   -jmp 0x440866
    goto L_0x00440866;
}

/* align: skip 0x00 */
void Application::sub_440890(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440890  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440891  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00440893  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00440896  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00440898  833cc514ae500000       +cmp dword ptr [eax*8 + 0x50ae14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5287444) /* 0x50ae14 */ + cpu.eax * 8);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004408a0  7504                   -jne 0x4408a6
    if (!cpu.flags.zf)
    {
        goto L_0x004408a6;
    }
    // 004408a2  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004408a4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004408a5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004408a6:
    // 004408a6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004408ab  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004408ac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4408b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004408b0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004408b1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004408b2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004408b3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004408b4  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 004408b6  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 004408b8  e8d3ffffff             -call 0x440890
    cpu.esp -= 4;
    sub_440890(app, cpu);
    if (cpu.terminate) return;
    // 004408bd  83f801                 +cmp eax, 1
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
    // 004408c0  740a                   -je 0x4408cc
    if (cpu.flags.zf)
    {
        goto L_0x004408cc;
    }
    // 004408c2  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004408c7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004408c8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004408c9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004408ca  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004408cb  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004408cc:
    // 004408cc  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004408ce  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 004408d1  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 004408d3  8d3cc500000000         -lea edi, [eax*8]
    cpu.edi = x86::reg32(cpu.eax * 8);
    // 004408da  8b1d480f5400           -mov ebx, dword ptr [0x540f48]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 004408e0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004408e1  8b8f18ae5000           -mov ecx, dword ptr [edi + 0x50ae18]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5287448) /* 0x50ae18 */);
    // 004408e7  8baf20ae5000           -mov ebp, dword ptr [edi + 0x50ae20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5287456) /* 0x50ae20 */);
    // 004408ed  8b8714ae5000           -mov eax, dword ptr [edi + 0x50ae14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5287444) /* 0x50ae14 */);
    // 004408f3  29cb                   -sub ebx, ecx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 004408f5  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 004408f7  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 004408f9  e8b2010000             -call 0x440ab0
    cpu.esp -= 4;
    sub_440ab0(app, cpu);
    if (cpu.terminate) return;
    // 004408fe  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440900  744c                   -je 0x44094e
    if (cpu.flags.zf)
    {
        goto L_0x0044094e;
    }
    // 00440902  f68724ae500001         +test byte ptr [edi + 0x50ae24], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edi + x86::reg32(5287460) /* 0x50ae24 */) & 1 /*0x1*/));
    // 00440909  7439                   -je 0x440944
    if (cpu.flags.zf)
    {
        goto L_0x00440944;
    }
    // 0044090b  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 0044090e  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 00440911  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 00440914  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00440916  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 00440919  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 0044091b  895e18                 -mov dword ptr [esi + 0x18], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.ebx;
    // 0044091e  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 00440921  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 00440924  895610                 -mov dword ptr [esi + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 00440927  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00440929  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 0044092c  f7df                   -neg edi
    cpu.edi = ~cpu.edi + 1;
    // 0044092e  897e1c                 -mov dword ptr [esi + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.edi;
    // 00440931  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 00440934  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 00440937  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 0044093a  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 0044093c  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 0044093f  f7dd                   -neg ebp
    cpu.ebp = ~cpu.ebp + 1;
    // 00440941  896e20                 -mov dword ptr [esi + 0x20], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ebp;
L_0x00440944:
    // 00440944  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00440949  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044094a  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044094b  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044094c  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044094d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044094e:
    // 0044094e  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00440953  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00440955  898718ae5000           -mov dword ptr [edi + 0x50ae18], eax
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5287448) /* 0x50ae18 */) = cpu.eax;
    // 0044095b  899714ae5000           -mov dword ptr [edi + 0x50ae14], edx
    app->getMemory<x86::reg32>(cpu.edi + x86::reg32(5287444) /* 0x50ae14 */) = cpu.edx;
    // 00440961  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00440963  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440964  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440965  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440966  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440967  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_440970(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440970  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440971  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00440974  8b74240c               -mov esi, dword ptr [esp + 0xc]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00440978  891c24                 -mov dword ptr [esp], ebx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.ebx;
    // 0044097b  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 0044097c  8b1df4375600           -mov ebx, dword ptr [0x5637f4]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5650420) /* 0x5637f4 */);
    // 00440982  8b048514b15000         -mov eax, dword ptr [eax*4 + 0x50b114]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5288212) /* 0x50b114 */ + cpu.eax * 4);
    // 00440989  e862000000             -call 0x4409f0
    cpu.esp -= 4;
    sub_4409f0(app, cpu);
    if (cpu.terminate) return;
    // 0044098e  f6042401               +test byte ptr [esp], 1
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.esp) & 1 /*0x1*/));
    // 00440992  750c                   -jne 0x4409a0
    if (!cpu.flags.zf)
    {
        goto L_0x004409a0;
    }
    // 00440994  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00440999  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 0044099c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044099d  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004409a0:
    // 004409a0  8b5618                 -mov edx, dword ptr [esi + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */);
    // 004409a3  8b460c                 -mov eax, dword ptr [esi + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
    // 004409a6  89560c                 -mov dword ptr [esi + 0xc], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edx;
    // 004409a9  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004409ab  894618                 -mov dword ptr [esi + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004409ae  f7da                   -neg edx
    cpu.edx = ~cpu.edx + 1;
    // 004409b0  895618                 -mov dword ptr [esi + 0x18], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(24) /* 0x18 */) = cpu.edx;
    // 004409b3  8b4610                 -mov eax, dword ptr [esi + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */);
    // 004409b6  8b561c                 -mov edx, dword ptr [esi + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */);
    // 004409b9  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004409bb  895610                 -mov dword ptr [esi + 0x10], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.edx;
    // 004409be  f7d9                   -neg ecx
    cpu.ecx = ~cpu.ecx + 1;
    // 004409c0  89461c                 -mov dword ptr [esi + 0x1c], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.eax;
    // 004409c3  894e1c                 -mov dword ptr [esi + 0x1c], ecx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(28) /* 0x1c */) = cpu.ecx;
    // 004409c6  8b5620                 -mov edx, dword ptr [esi + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */);
    // 004409c9  8b4614                 -mov eax, dword ptr [esi + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */);
    // 004409cc  895614                 -mov dword ptr [esi + 0x14], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(20) /* 0x14 */) = cpu.edx;
    // 004409cf  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004409d1  894620                 -mov dword ptr [esi + 0x20], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.eax;
    // 004409d4  f7db                   -neg ebx
    cpu.ebx = ~cpu.ebx + 1;
    // 004409d6  895e20                 -mov dword ptr [esi + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 004409d9  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 004409de  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 004409e1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004409e2  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4409f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004409f0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004409f1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004409f2  83ec08                 -sub esp, 8
    (cpu.esp) -= x86::reg32(x86::sreg32(8 /*0x8*/));
    // 004409f5  8d5808                 -lea ebx, [eax + 8]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(8) /* 0x8 */);
    // 004409f8  668b4004               -mov ax, word ptr [eax + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(4) /* 0x4 */);
    // 004409fc  25ffff0000             -and eax, 0xffff
    cpu.eax &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00440a01  8d50ff                 -lea edx, [eax - 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 00440a04  8d049500000000         -lea eax, [edx*4]
    cpu.eax = x86::reg32(cpu.edx * 4);
    // 00440a0b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 00440a0d  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00440a10  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00440a12  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00440a14  8d700c                 -lea esi, [eax + 0xc]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00440a17  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00440a18  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00440a19  89cf                   -mov edi, ecx
    cpu.edi = cpu.ecx;
    // 00440a1b  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00440a1d  8b542414               -mov edx, dword ptr [esp + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00440a21  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00440a23  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00440a24  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00440a25  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00440a26  e875ba0200             -call 0x46c4a0
    cpu.esp -= 4;
    sub_46c4a0(app, cpu);
    if (cpu.terminate) return;
    // 00440a2b  83c408                 -add esp, 8
    (cpu.esp) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00440a2e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440a2f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440a30  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_440a40(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440a40  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440a41  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440a42  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440a43  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00440a45  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00440a47  8d148500000000         -lea edx, [eax*4]
    cpu.edx = x86::reg32(cpu.eax * 4);
    // 00440a4e  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00440a50  8d0cd500000000         -lea ecx, [edx*8]
    cpu.ecx = x86::reg32(cpu.edx * 8);
    // 00440a57  8b15480f5400           -mov edx, dword ptr [0x540f48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 00440a5d  8bb918ae5000           -mov edi, dword ptr [ecx + 0x50ae18]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5287448) /* 0x50ae18 */);
    // 00440a63  8b8914ae5000           -mov ecx, dword ptr [ecx + 0x50ae14]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5287444) /* 0x50ae14 */);
    // 00440a69  29fa                   -sub edx, edi
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00440a6b  668b7906               -mov di, word ptr [ecx + 6]
    cpu.di = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
    // 00440a6f  6683ff01               +cmp di, 1
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00440a73  7231                   -jb 0x440aa6
    if (cpu.flags.cf)
    {
        goto L_0x00440aa6;
    }
    // 00440a75  6681ff9001             +cmp di, 0x190
    {
        x86::reg16 tmp1 = cpu.di;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(400 /*0x190*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00440a7a  772a                   -ja 0x440aa6
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00440aa6;
    }
    // 00440a7c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00440a7e  668b7906               -mov di, word ptr [ecx + 6]
    cpu.di = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(6) /* 0x6 */);
L_0x00440a82:
    // 00440a82  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00440a84  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00440a87  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00440a89  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00440a8b  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00440a8d  668b7904               -mov di, word ptr [ecx + 4]
    cpu.di = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00440a91  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00440a94  4f                     -dec edi
    (cpu.edi)--;
    // 00440a95  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00440a97  8916                   -mov dword ptr [esi], edx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.edx;
    // 00440a99  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00440a9b  668b5104               -mov dx, word ptr [ecx + 4]
    cpu.dx = app->getMemory<x86::reg16>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00440a9f  4a                     +dec edx
    {
        x86::reg32& tmp = cpu.edx;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 00440aa0  8913                   -mov dword ptr [ebx], edx
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.edx;
    // 00440aa2  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440aa3  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440aa4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440aa5  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00440aa6:
    // 00440aa6  bf06000000             -mov edi, 6
    cpu.edi = 6 /*0x6*/;
    // 00440aab  ebd5                   -jmp 0x440a82
    goto L_0x00440a82;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_440ab0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440ab0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440ab1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440ab2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440ab3  83ec3c                 -sub esp, 0x3c
    (cpu.esp) -= x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00440ab6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00440ab8  89542434               -mov dword ptr [esp + 0x34], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */) = cpu.edx;
    // 00440abc  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00440abe  83c008                 -add eax, 8
    (cpu.eax) += x86::reg32(x86::sreg32(8 /*0x8*/));
    // 00440ac1  668b5606               -mov dx, word ptr [esi + 6]
    cpu.dx = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(6) /* 0x6 */);
    // 00440ac5  89442438               -mov dword ptr [esp + 0x38], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */) = cpu.eax;
    // 00440ac9  6683fa01               +cmp dx, 1
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(1 /*0x1*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00440acd  7236                   -jb 0x440b05
    if (cpu.flags.cf)
    {
        goto L_0x00440b05;
    }
    // 00440acf  6681fa9001             +cmp dx, 0x190
    {
        x86::reg16 tmp1 = cpu.dx;
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(400 /*0x190*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00440ad4  772f                   -ja 0x440b05
    if (!cpu.flags.cf && !cpu.flags.zf)
    {
        goto L_0x00440b05;
    }
    // 00440ad6  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00440ad8  6689d7                 -mov di, dx
    cpu.di = cpu.dx;
L_0x00440adb:
    // 00440adb  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00440add  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00440adf  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00440ae2  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00440ae4  8b542434               -mov edx, dword ptr [esp + 0x34]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(52) /* 0x34 */);
    // 00440ae8  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00440aea  83fa02                 +cmp edx, 2
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
    // 00440aed  751d                   -jne 0x440b0c
    if (!cpu.flags.zf)
    {
        goto L_0x00440b0c;
    }
    // 00440aef  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00440af1  668b4604               -mov ax, word ptr [esi + 4]
    cpu.ax = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00440af5  48                     -dec eax
    (cpu.eax)--;
    // 00440af6  39c1                   +cmp ecx, eax
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
    // 00440af8  7c12                   -jl 0x440b0c
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00440b0c;
    }
    // 00440afa  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00440afc  83c43c                 +add esp, 0x3c
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
    // 00440aff  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440b00  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440b01  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440b02  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00440b05:
    // 00440b05  bf06000000             -mov edi, 6
    cpu.edi = 6 /*0x6*/;
    // 00440b0a  ebcf                   -jmp 0x440adb
    goto L_0x00440adb;
L_0x00440b0c:
    // 00440b0c  668b7604               -mov si, word ptr [esi + 4]
    cpu.si = app->getMemory<x86::reg16>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00440b10  81e6ffff0000           -and esi, 0xffff
    cpu.esi &= x86::reg32(x86::sreg32(65535 /*0xffff*/));
    // 00440b16  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440b18  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 00440b1a  4e                     -dec esi
    (cpu.esi)--;
    // 00440b1b  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00440b1e  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00440b20  89d1                   -mov ecx, edx
    cpu.ecx = cpu.edx;
    // 00440b22  8d4201                 -lea eax, [edx + 1]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(1) /* 0x1 */);
    // 00440b25  89442430               -mov dword ptr [esp + 0x30], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */) = cpu.eax;
    // 00440b29  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 00440b2b  89d8                   -mov eax, ebx
    cpu.eax = cpu.ebx;
    // 00440b2d  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00440b30  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00440b32  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00440b35  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00440b37  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00440b3a  f7ff                   -idiv edi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.edi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00440b3c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00440b3e  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440b40  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 00440b43  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00440b45  8b442438               -mov eax, dword ptr [esp + 0x38]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00440b49  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 00440b4c  8b542430               -mov edx, dword ptr [esp + 0x30]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00440b50  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00440b52  8d7c2428               -lea edi, [esp + 0x28]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00440b56  8d0c9500000000         -lea ecx, [edx*4]
    cpu.ecx = x86::reg32(cpu.edx * 4);
    // 00440b5d  8d700c                 -lea esi, [eax + 0xc]
    cpu.esi = x86::reg32(cpu.eax + x86::reg32(12) /* 0xc */);
    // 00440b60  01d1                   -add ecx, edx
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.edx));
    // 00440b62  8b542438               -mov edx, dword ptr [esp + 0x38]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(56) /* 0x38 */);
    // 00440b66  c1e102                 -shl ecx, 2
    cpu.ecx <<= 2 /*0x2*/ % 32;
    // 00440b69  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00440b6a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00440b6b  01ca                   -add edx, ecx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00440b6d  8d7c2418               -lea edi, [esp + 0x18]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00440b71  8d720c                 -lea esi, [edx + 0xc]
    cpu.esi = x86::reg32(cpu.edx + x86::reg32(12) /* 0xc */);
    // 00440b74  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00440b75  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00440b76  89e7                   -mov edi, esp
    cpu.edi = cpu.esp;
    // 00440b78  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00440b7a  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440b7b  8d4c2410               -lea ecx, [esp + 0x10]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00440b7f  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00440b80  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00440b81  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00440b82  8d442424               -lea eax, [esp + 0x24]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00440b86  8d7c2410               -lea edi, [esp + 0x10]
    cpu.edi = x86::reg32(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00440b8a  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00440b8c  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00440b8d  8d542420               -lea edx, [esp + 0x20]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00440b91  8d442430               -lea eax, [esp + 0x30]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(48) /* 0x30 */);
    // 00440b95  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440b96  8d5c240c               -lea ebx, [esp + 0xc]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00440b9a  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00440b9b  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00440b9c  a5                     -movsd dword ptr es:[edi], dword ptr [esi]
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
    // 00440b9d  e8eeb90200             -call 0x46c590
    cpu.esp -= 4;
    sub_46c590(app, cpu);
    if (cpu.terminate) return;
    // 00440ba2  8b54244c               -mov edx, dword ptr [esp + 0x4c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(76) /* 0x4c */);
    // 00440ba6  8d442420               -lea eax, [esp + 0x20]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00440baa  e8f1b80200             -call 0x46c4a0
    cpu.esp -= 4;
    sub_46c4a0(app, cpu);
    if (cpu.terminate) return;
    // 00440baf  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00440bb4  83c43c                 -add esp, 0x3c
    (cpu.esp) += x86::reg32(x86::sreg32(60 /*0x3c*/));
    // 00440bb7  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440bb8  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440bb9  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440bba  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_440bc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440bc0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440bc1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00440bc3  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00440bc6  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00440bc8  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00440bcb  83b814ae500000         +cmp dword ptr [eax + 0x50ae14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5287444) /* 0x50ae14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440bd2  7507                   -jne 0x440bdb
    if (!cpu.flags.zf)
    {
        goto L_0x00440bdb;
    }
    // 00440bd4  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00440bd9  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440bda  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00440bdb:
    // 00440bdb  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440bdc  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440bdd  bbffffffff             -mov ebx, 0xffffffff
    cpu.ebx = 4294967295 /*0xffffffff*/;
    // 00440be2  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00440be4  899818ae5000           -mov dword ptr [eax + 0x50ae18], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5287448) /* 0x50ae18 */) = cpu.ebx;
    // 00440bea  89881cae5000           -mov dword ptr [eax + 0x50ae1c], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5287452) /* 0x50ae1c */) = cpu.ecx;
    // 00440bf0  898814ae5000           -mov dword ptr [eax + 0x50ae14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5287444) /* 0x50ae14 */) = cpu.ecx;
    // 00440bf6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00440bfb  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440bfc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440bfd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440bfe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_440c00(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440c00  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440c01  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 00440c03  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00440c05  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00440c08  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00440c0a  8934c520ae5000         -mov dword ptr [eax*8 + 0x50ae20], esi
    app->getMemory<x86::reg32>(x86::reg32(5287456) /* 0x50ae20 */ + cpu.eax * 8) = cpu.esi;
    // 00440c11  891cc524ae5000         -mov dword ptr [eax*8 + 0x50ae24], ebx
    app->getMemory<x86::reg32>(x86::reg32(5287460) /* 0x50ae24 */ + cpu.eax * 8) = cpu.ebx;
    // 00440c18  890cc528ae5000         -mov dword ptr [eax*8 + 0x50ae28], ecx
    app->getMemory<x86::reg32>(x86::reg32(5287464) /* 0x50ae28 */ + cpu.eax * 8) = cpu.ecx;
    // 00440c1f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440c20  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_440c30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440c30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440c31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440c32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440c33  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00440c35  e876000000             -call 0x440cb0
    cpu.esp -= 4;
    sub_440cb0(app, cpu);
    if (cpu.terminate) return;
    // 00440c3a  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00440c3c  83f8ff                 +cmp eax, -1
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
    // 00440c3f  7429                   -je 0x440c6a
    if (cpu.flags.zf)
    {
        goto L_0x00440c6a;
    }
    // 00440c41  83f920                 +cmp ecx, 0x20
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(32 /*0x20*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440c44  7d1f                   -jge 0x440c65
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00440c65;
    }
    // 00440c46  c1e002                 -shl eax, 2
    cpu.eax <<= 2 /*0x2*/ % 32;
    // 00440c49  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00440c4b  8d1c8d00000000         -lea ebx, [ecx*4]
    cpu.ebx = x86::reg32(cpu.ecx * 4);
    // 00440c52  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00440c55  8b8b14b15000           -mov ecx, dword ptr [ebx + 0x50b114]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5288212) /* 0x50b114 */);
    // 00440c5b  898814ae5000           -mov dword ptr [eax + 0x50ae14], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5287444) /* 0x50ae14 */) = cpu.ecx;
    // 00440c61  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00440c63  7509                   -jne 0x440c6e
    if (!cpu.flags.zf)
    {
        goto L_0x00440c6e;
    }
L_0x00440c65:
    // 00440c65  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
L_0x00440c6a:
    // 00440c6a  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440c6b  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440c6c  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440c6d  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00440c6e:
    // 00440c6e  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440c6f  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440c70  8b0d480f5400           -mov ecx, dword ptr [0x540f48]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 00440c76  bb02000000             -mov ebx, 2
    cpu.ebx = 2 /*0x2*/;
    // 00440c7b  898818ae5000           -mov dword ptr [eax + 0x50ae18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5287448) /* 0x50ae18 */) = cpu.ecx;
    // 00440c81  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00440c86  899820ae5000           -mov dword ptr [eax + 0x50ae20], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5287456) /* 0x50ae20 */) = cpu.ebx;
    // 00440c8c  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00440c8e  89b024ae5000           -mov dword ptr [eax + 0x50ae24], esi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5287460) /* 0x50ae24 */) = cpu.esi;
    // 00440c94  89b828ae5000           -mov dword ptr [eax + 0x50ae28], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5287464) /* 0x50ae28 */) = cpu.edi;
    // 00440c9a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00440c9c  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440c9d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440c9e  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440c9f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440ca0  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440ca1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_440cb0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440cb0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440cb1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440cb2  8b0d14ae5000           -mov ecx, dword ptr [0x50ae14]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5287444) /* 0x50ae14 */);
    // 00440cb8  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00440cba  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00440cbc  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00440cbe  7414                   -je 0x440cd4
    if (cpu.flags.zf)
    {
        goto L_0x00440cd4;
    }
L_0x00440cc0:
    // 00440cc0  83c018                 -add eax, 0x18
    (cpu.eax) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00440cc3  42                     -inc edx
    (cpu.edx)++;
    // 00440cc4  3d00030000             +cmp eax, 0x300
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
    // 00440cc9  7d09                   -jge 0x440cd4
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00440cd4;
    }
    // 00440ccb  83b814ae500000         +cmp dword ptr [eax + 0x50ae14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5287444) /* 0x50ae14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440cd2  75ec                   -jne 0x440cc0
    if (!cpu.flags.zf)
    {
        goto L_0x00440cc0;
    }
L_0x00440cd4:
    // 00440cd4  83fa20                 +cmp edx, 0x20
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
    // 00440cd7  7508                   -jne 0x440ce1
    if (!cpu.flags.zf)
    {
        goto L_0x00440ce1;
    }
    // 00440cd9  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00440cde  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440cdf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440ce0  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00440ce1:
    // 00440ce1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00440ce3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440ce4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440ce5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_440cf0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440cf0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440cf1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440cf2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440cf3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00440cf5:
    // 00440cf5  8b8a14b15000           -mov ecx, dword ptr [edx + 0x50b114]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5288212) /* 0x50b114 */);
    // 00440cfb  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00440cfd  750c                   -jne 0x440d0b
    if (!cpu.flags.zf)
    {
        goto L_0x00440d0b;
    }
    // 00440cff  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00440d02  83fa1c                 +cmp edx, 0x1c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440d05  75ee                   -jne 0x440cf5
    if (!cpu.flags.zf)
    {
        goto L_0x00440cf5;
    }
    // 00440d07  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440d08  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440d09  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440d0a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00440d0b:
    // 00440d0b  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440d0d  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00440d0f  e8e83b0400             -call 0x4848fc
    cpu.esp -= 4;
    sub_4848fc(app, cpu);
    if (cpu.terminate) return;
    // 00440d14  899a14b15000           -mov dword ptr [edx + 0x50b114], ebx
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(5288212) /* 0x50b114 */) = cpu.ebx;
    // 00440d1a  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00440d1d  83fa1c                 +cmp edx, 0x1c
    {
        x86::reg32 tmp1 = cpu.edx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440d20  75d3                   -jne 0x440cf5
    if (!cpu.flags.zf)
    {
        goto L_0x00440cf5;
    }
    // 00440d22  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440d23  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440d24  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440d25  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_440d30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440d30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00440d31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440d32  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440d33  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440d34  81ec00010000           -sub esp, 0x100
    (cpu.esp) -= x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00440d3a  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00440d3c  e87f000000             -call 0x440dc0
    cpu.esp -= 4;
    sub_440dc0(app, cpu);
    if (cpu.terminate) return;
    // 00440d41  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
L_0x00440d43:
    // 00440d43  83c104                 -add ecx, 4
    (cpu.ecx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00440d46  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00440d48  899110b15000           -mov dword ptr [ecx + 0x50b110], edx
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(5288208) /* 0x50b110 */) = cpu.edx;
    // 00440d4e  83f91c                 +cmp ecx, 0x1c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440d51  75f0                   -jne 0x440d43
    if (!cpu.flags.zf)
    {
        goto L_0x00440d43;
    }
    // 00440d53  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440d54  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440d55  68f0ba4c00             -push 0x4cbaf0
    app->getMemory<x86::reg32>(cpu.esp-4) = 5028592 /*0x4cbaf0*/;
    cpu.esp -= 4;
    // 00440d5a  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00440d5e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00440d5f  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 00440d61  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00440d63  e899570400             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 00440d68  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
L_0x00440d6b:
    // 00440d6b  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00440d6d  e8fe770400             -call 0x488570
    cpu.esp -= 4;
    sub_488570(app, cpu);
    if (cpu.terminate) return;
    // 00440d72  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440d74  750d                   -jne 0x440d83
    if (!cpu.flags.zf)
    {
        goto L_0x00440d83;
    }
    // 00440d76  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440d78  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00440d7e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440d7f  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440d80  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440d81  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440d82  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00440d83:
    // 00440d83  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00440d85  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00440d87  41                     -inc ecx
    (cpu.ecx)++;
    // 00440d88  e8b3610400             -call 0x486f40
    cpu.esp -= 4;
    sub_486f40(app, cpu);
    if (cpu.terminate) return;
    // 00440d8d  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440d8e  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440d8f  68fcba4c00             -push 0x4cbafc
    app->getMemory<x86::reg32>(cpu.esp-4) = 5028604 /*0x4cbafc*/;
    cpu.esp -= 4;
    // 00440d94  898314b15000           -mov dword ptr [ebx + 0x50b114], eax
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(5288212) /* 0x50b114 */) = cpu.eax;
    // 00440d9a  8d44240c               -lea eax, [esp + 0xc]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00440d9e  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00440d9f  83c304                 -add ebx, 4
    (cpu.ebx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00440da2  e85a570400             -call 0x486501
    cpu.esp -= 4;
    sub_486501(app, cpu);
    if (cpu.terminate) return;
    // 00440da7  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00440daa  83f907                 +cmp ecx, 7
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
    // 00440dad  7cbc                   -jl 0x440d6b
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00440d6b;
    }
    // 00440daf  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00440db1  81c400010000           -add esp, 0x100
    (cpu.esp) += x86::reg32(x86::sreg32(256 /*0x100*/));
    // 00440db7  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440db8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440db9  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440dba  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440dbb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 */
void Application::sub_440dc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440dc0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440dc1  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00440dc2  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 00440dc7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
L_0x00440dc9:
    // 00440dc9  83c018                 -add eax, 0x18
    (cpu.eax) += x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00440dcc  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00440dce  898800ae5000           -mov dword ptr [eax + 0x50ae00], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5287424) /* 0x50ae00 */) = cpu.ecx;
    // 00440dd4  899004ae5000           -mov dword ptr [eax + 0x50ae04], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5287428) /* 0x50ae04 */) = cpu.edx;
    // 00440dda  8990fcad5000           -mov dword ptr [eax + 0x50adfc], edx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5287420) /* 0x50adfc */) = cpu.edx;
    // 00440de0  3d00030000             +cmp eax, 0x300
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
    // 00440de5  75e2                   -jne 0x440dc9
    if (!cpu.flags.zf)
    {
        goto L_0x00440dc9;
    }
    // 00440de7  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440de8  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440de9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_440df0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440df0  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440df1  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440df2  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440df3  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440df4  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00440df7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00440df9  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00440dfb  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 00440dfd  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00440dff  8b11                   -mov edx, dword ptr [ecx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx);
    // 00440e01  8b5904                 -mov ebx, dword ptr [ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */);
    // 00440e04  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00440e06  8b5704                 -mov edx, dword ptr [edi + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00440e09  29da                   -sub edx, ebx
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 00440e0b  8b5f08                 -mov ebx, dword ptr [edi + 8]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */);
    // 00440e0e  8b7908                 -mov edi, dword ptr [ecx + 8]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(8) /* 0x8 */);
    // 00440e11  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00440e14  29fb                   -sub ebx, edi
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00440e16  89542404               -mov dword ptr [esp + 4], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.edx;
    // 00440e1a  895c2408               -mov dword ptr [esp + 8], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.ebx;
    // 00440e1e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440e20  0f8eb7000000           -jle 0x440edd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00440edd;
    }
L_0x00440e26:
    // 00440e26  89c7                   -mov edi, eax
    cpu.edi = cpu.eax;
    // 00440e28  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00440e2a  0f8eb4000000           -jle 0x440ee4
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00440ee4;
    }
L_0x00440e30:
    // 00440e30  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00440e32  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00440e34  0f8eb1000000           -jle 0x440eeb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00440eeb;
    }
L_0x00440e3a:
    // 00440e3a  39df                   +cmp edi, ebx
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
    // 00440e3c  0f8eb0000000           -jle 0x440ef2
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00440ef2;
    }
    // 00440e42  c1fb02                 -sar ebx, 2
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (2 /*0x2*/ % 32));
L_0x00440e45:
    // 00440e45  01fb                   -add ebx, edi
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.edi));
    // 00440e47  39d8                   +cmp eax, ebx
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
    // 00440e49  0f8eab000000           -jle 0x440efa
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00440efa;
    }
    // 00440e4f  c1fb02                 -sar ebx, 2
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (2 /*0x2*/ % 32));
L_0x00440e52:
    // 00440e52  01c3                   -add ebx, eax
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.eax));
    // 00440e54  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00440e57  8b510c                 -mov edx, dword ptr [ecx + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */);
    // 00440e5a  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00440e5c  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00440e5f  c1e810                 +shr eax, 0x10
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
    // 00440e62  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00440e64  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00440e66  8b5110                 -mov edx, dword ptr [ecx + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(16) /* 0x10 */);
    // 00440e69  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00440e6d  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00440e6f  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00440e72  c1e810                 +shr eax, 0x10
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
    // 00440e75  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00440e77  8b5114                 -mov edx, dword ptr [ecx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(20) /* 0x14 */);
    // 00440e7a  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 00440e7c  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00440e80  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00440e82  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00440e85  c1e810                 +shr eax, 0x10
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
    // 00440e88  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00440e8a  8b5124                 -mov edx, dword ptr [ecx + 0x24]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(36) /* 0x24 */);
    // 00440e8d  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 00440e8f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00440e92  896c240c               -mov dword ptr [esp + 0xc], ebp
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.ebp;
    // 00440e96  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00440e98  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00440e9b  c1e810                 +shr eax, 0x10
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
    // 00440e9e  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00440ea0  89c5                   -mov ebp, eax
    cpu.ebp = cpu.eax;
    // 00440ea2  8b5128                 -mov edx, dword ptr [ecx + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(40) /* 0x28 */);
    // 00440ea5  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00440ea9  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00440eab  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00440eae  c1e810                 +shr eax, 0x10
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
    // 00440eb1  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00440eb3  8b512c                 -mov edx, dword ptr [ecx + 0x2c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(44) /* 0x2c */);
    // 00440eb6  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 00440eb8  8b442408               -mov eax, dword ptr [esp + 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00440ebc  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00440ebe  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 00440ec0  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00440ec3  c1e810                 +shr eax, 0x10
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
    // 00440ec6  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00440ec8  01c5                   -add ebp, eax
    (cpu.ebp) += x86::reg32(x86::sreg32(cpu.eax));
    // 00440eca  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00440ecc  7534                   -jne 0x440f02
    if (!cpu.flags.zf)
    {
        goto L_0x00440f02;
    }
    // 00440ece  895e04                 -mov dword ptr [esi + 4], ebx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 00440ed1  891e                   -mov dword ptr [esi], ebx
    app->getMemory<x86::reg32>(cpu.esi) = cpu.ebx;
    // 00440ed3  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00440ed5  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00440ed8  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440ed9  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440eda  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440edb  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440edc  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00440edd:
    // 00440edd  f7d8                   +neg eax
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
    // 00440edf  e942ffffff             -jmp 0x440e26
    goto L_0x00440e26;
L_0x00440ee4:
    // 00440ee4  f7da                   +neg edx
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
    // 00440ee6  e945ffffff             -jmp 0x440e30
    goto L_0x00440e30;
L_0x00440eeb:
    // 00440eeb  f7db                   +neg ebx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ebx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 00440eed  e948ffffff             -jmp 0x440e3a
    goto L_0x00440e3a;
L_0x00440ef2:
    // 00440ef2  c1ff02                 +sar edi, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.edi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00440ef5  e94bffffff             -jmp 0x440e45
    goto L_0x00440e45;
L_0x00440efa:
    // 00440efa  c1f802                 +sar eax, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00440efd  e950ffffff             -jmp 0x440e52
    goto L_0x00440e52;
L_0x00440f02:
    // 00440f02  8b44240c               -mov eax, dword ptr [esp + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */);
    // 00440f06  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 00440f07  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00440f09  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00440f0b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00440f0d  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 00440f11  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00440f14  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00440f16  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 00440f19  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00440f1b  3d00000100             +cmp eax, 0x10000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440f20  7e3e                   -jle 0x440f60
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00440f60;
    }
    // 00440f22  c70600000100           -mov dword ptr [esi], 0x10000
    app->getMemory<x86::reg32>(cpu.esi) = 65536 /*0x10000*/;
L_0x00440f28:
    // 00440f28  89fb                   -mov ebx, edi
    cpu.ebx = cpu.edi;
    // 00440f2a  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00440f2c  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 00440f2d  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00440f2f  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00440f31  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00440f33  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 00440f37  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00440f3a  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00440f3c  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 00440f3f  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00440f41  3d00000100             +cmp eax, 0x10000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(65536 /*0x10000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440f46  7f2b                   -jg 0x440f73
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00440f73;
    }
    // 00440f48  3d0000ffff             +cmp eax, 0xffff0000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440f4d  7d35                   -jge 0x440f84
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00440f84;
    }
    // 00440f4f  c746040000ffff         -mov dword ptr [esi + 4], 0xffff0000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 4294901760 /*0xffff0000*/;
    // 00440f56  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00440f58  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00440f5b  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440f5c  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440f5d  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440f5e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440f5f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00440f60:
    // 00440f60  3d0000ffff             +cmp eax, 0xffff0000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4294901760 /*0xffff0000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440f65  7d08                   -jge 0x440f6f
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00440f6f;
    }
    // 00440f67  c7060000ffff           -mov dword ptr [esi], 0xffff0000
    app->getMemory<x86::reg32>(cpu.esi) = 4294901760 /*0xffff0000*/;
    // 00440f6d  ebb9                   -jmp 0x440f28
    goto L_0x00440f28;
L_0x00440f6f:
    // 00440f6f  8906                   -mov dword ptr [esi], eax
    app->getMemory<x86::reg32>(cpu.esi) = cpu.eax;
    // 00440f71  ebb5                   -jmp 0x440f28
    goto L_0x00440f28;
L_0x00440f73:
    // 00440f73  c7460400000100         -mov dword ptr [esi + 4], 0x10000
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = 65536 /*0x10000*/;
    // 00440f7a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00440f7c  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00440f7f  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440f80  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440f81  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440f82  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440f83  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00440f84:
    // 00440f84  894604                 -mov dword ptr [esi + 4], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 00440f87  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00440f89  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00440f8c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440f8d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440f8e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440f8f  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00440f90  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_440fa0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00440fa0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00440fa1  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00440fa2  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00440fa5  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00440fa7  c1e604                 -shl esi, 4
    cpu.esi <<= 4 /*0x4*/ % 32;
    // 00440faa  29c6                   -sub esi, eax
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00440fac  81c630b15000           -add esi, 0x50b130
    (cpu.esi) += x86::reg32(x86::sreg32(5288240 /*0x50b130*/));
    // 00440fb2  3b5e0c                 +cmp ebx, dword ptr [esi + 0xc]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00440fb5  0f857f000000           -jne 0x44103a
    if (!cpu.flags.zf)
    {
        goto L_0x0044103a;
    }
    // 00440fbb  83c60c                 -add esi, 0xc
    (cpu.esi) += x86::reg32(x86::sreg32(12 /*0xc*/));
L_0x00440fbe:
    // 00440fbe  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00440fbf  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00440fc0  8b0a                   -mov ecx, dword ptr [edx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx);
    // 00440fc2  8b839c000000           -mov eax, dword ptr [ebx + 0x9c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(156) /* 0x9c */);
    // 00440fc8  8b7a04                 -mov edi, dword ptr [edx + 4]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */);
    // 00440fcb  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00440fcd  8b6a08                 -mov ebp, dword ptr [edx + 8]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(8) /* 0x8 */);
    // 00440fd0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00440fd2  8b83a0000000           -mov eax, dword ptr [ebx + 0xa0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(160) /* 0xa0 */);
    // 00440fd8  8b9ba4000000           -mov ebx, dword ptr [ebx + 0xa4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(164) /* 0xa4 */);
    // 00440fde  29f8                   -sub eax, edi
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00440fe0  29eb                   -sub ebx, ebp
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 00440fe2  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00440fe4  0f8e72000000           -jle 0x44105c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044105c;
    }
L_0x00440fea:
    // 00440fea  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00440fec  0f8e6e000000           -jle 0x441060
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00441060;
    }
L_0x00440ff2:
    // 00440ff2  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00440ff4  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00440ff6  0f8e68000000           -jle 0x441064
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00441064;
    }
L_0x00440ffc:
    // 00440ffc  39d9                   +cmp ecx, ebx
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
    // 00440ffe  0f8e64000000           -jle 0x441068
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00441068;
    }
    // 00441004  c1fb02                 -sar ebx, 2
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (2 /*0x2*/ % 32));
L_0x00441007:
    // 00441007  01cb                   -add ebx, ecx
    (cpu.ebx) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00441009  39da                   +cmp edx, ebx
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
    // 0044100b  7e60                   -jle 0x44106d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044106d;
    }
    // 0044100d  c1fb02                 -sar ebx, 2
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (2 /*0x2*/ % 32));
L_0x00441010:
    // 00441010  01da                   -add edx, ebx
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00441012  8b4604                 -mov eax, dword ptr [esi + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 00441015  89d5                   -mov ebp, edx
    cpu.ebp = cpu.edx;
    // 00441017  83f8ff                 +cmp eax, -1
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
    // 0044101a  7556                   -jne 0x441072
    if (!cpu.flags.zf)
    {
        goto L_0x00441072;
    }
    // 0044101c  8b5608                 -mov edx, dword ptr [esi + 8]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */);
    // 0044101f  8b7e0c                 -mov edi, dword ptr [esi + 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */);
L_0x00441022:
    // 00441022  897e0c                 -mov dword ptr [esi + 0xc], edi
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(12) /* 0xc */) = cpu.edi;
    // 00441025  895608                 -mov dword ptr [esi + 8], edx
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(8) /* 0x8 */) = cpu.edx;
    // 00441028  a1480f5400             -mov eax, dword ptr [0x540f48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 0044102d  896e04                 -mov dword ptr [esi + 4], ebp
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */) = cpu.ebp;
    // 00441030  894610                 -mov dword ptr [esi + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esi + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00441033  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00441035  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441036  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441037  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441038  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441039  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044103a:
    // 0044103a  3b5e30                 +cmp ebx, dword ptr [esi + 0x30]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(48) /* 0x30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044103d  7508                   -jne 0x441047
    if (!cpu.flags.zf)
    {
        goto L_0x00441047;
    }
    // 0044103f  83c630                 +add esi, 0x30
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(48 /*0x30*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 00441042  e977ffffff             -jmp 0x440fbe
    goto L_0x00440fbe;
L_0x00441047:
    // 00441047  3b5e54                 +cmp ebx, dword ptr [esi + 0x54]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(84) /* 0x54 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044104a  7508                   -jne 0x441054
    if (!cpu.flags.zf)
    {
        goto L_0x00441054;
    }
    // 0044104c  83c654                 +add esi, 0x54
    {
        x86::reg32& tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(84 /*0x54*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0044104f  e96affffff             -jmp 0x440fbe
    goto L_0x00440fbe;
L_0x00441054:
    // 00441054  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 00441059  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044105a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044105b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044105c:
    // 0044105c  f7d9                   +neg ecx
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
    // 0044105e  eb8a                   -jmp 0x440fea
    goto L_0x00440fea;
L_0x00441060:
    // 00441060  f7d8                   +neg eax
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
    // 00441062  eb8e                   -jmp 0x440ff2
    goto L_0x00440ff2;
L_0x00441064:
    // 00441064  f7db                   +neg ebx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ebx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 00441066  eb94                   -jmp 0x440ffc
    goto L_0x00440ffc;
L_0x00441068:
    // 00441068  c1f902                 +sar ecx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ecx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0044106b  eb9a                   -jmp 0x441007
    goto L_0x00441007;
L_0x0044106d:
    // 0044106d  c1fa02                 +sar edx, 2
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
    // 00441070  eb9e                   -jmp 0x441010
    goto L_0x00441010;
L_0x00441072:
    // 00441072  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00441074  29c7                   -sub edi, eax
    (cpu.edi) -= x86::reg32(x86::sreg32(cpu.eax));
    // 00441076  c1e705                 -shl edi, 5
    cpu.edi <<= 5 /*0x5*/ % 32;
    // 00441079  b800001601             -mov eax, 0x1160000
    cpu.eax = 18219008 /*0x1160000*/;
    // 0044107e  8d9f00001601           -lea ebx, [edi + 0x1160000]
    cpu.ebx = x86::reg32(cpu.edi + x86::reg32(18219008) /* 0x1160000 */);
    // 00441084  99                     -cdq 
    cpu.edx_eax = x86::reg64(static_cast<x86::sreg32>(cpu.eax));
    // 00441085  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00441087  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00441089  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044108b  0facd010               -shrd eax, edx, 0x10
    {
        x86::reg32& destination = cpu.eax;
        destination >>= (16 /*0x10*/ % 32);
        destination |= cpu.edx  << (32 - (16 /*0x10*/ % 32));
    }
    // 0044108f  c1fa10                 -sar edx, 0x10
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (16 /*0x10*/ % 32));
    // 00441092  f7fb                   -idiv ebx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ebx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00441094  c1e110                 -shl ecx, 0x10
    cpu.ecx <<= 16 /*0x10*/ % 32;
    // 00441097  01c8                   +add eax, ecx
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
    // 00441099  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 0044109b  eb85                   -jmp 0x441022
    goto L_0x00441022;
}

/* align: skip 0x00 0x00 0x00 */
void Application::sub_4410a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004410a0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004410a1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004410a2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004410a3  83ec10                 -sub esp, 0x10
    (cpu.esp) -= x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004410a6  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004410a8  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004410aa  895c2404               -mov dword ptr [esp + 4], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.ebx;
    // 004410ae  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004410b0  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 004410b3  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004410b5  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 004410b8  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004410ba  ba30b15000             -mov edx, 0x50b130
    cpu.edx = 5288240 /*0x50b130*/;
    // 004410bf  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004410c1  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 004410c4  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 004410c6  8b1c24                 -mov ebx, dword ptr [esp]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    // 004410c9  e892a50000             -call 0x44b660
    cpu.esp -= 4;
    sub_44b660(app, cpu);
    if (cpu.terminate) return;
    // 004410ce  8b15480f5400           -mov edx, dword ptr [0x540f48]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 004410d4  2b5304                 -sub edx, dword ptr [ebx + 4]
    (cpu.edx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(4) /* 0x4 */)));
    // 004410d7  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004410d9  83fa08                 +cmp edx, 8
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
    // 004410dc  7d08                   -jge 0x4410e6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004410e6;
    }
    // 004410de  3b03                   +cmp eax, dword ptr [ebx]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.ebx)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004410e0  0f84cf000000           -je 0x4411b5
    if (cpu.flags.zf)
    {
        goto L_0x004411b5;
    }
L_0x004410e6:
    // 004410e6  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004410e9  a1480f5400             -mov eax, dword ptr [0x540f48]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5508936) /* 0x540f48 */);
    // 004410ee  8b32                   -mov esi, dword ptr [edx]
    cpu.esi = app->getMemory<x86::reg32>(cpu.edx);
    // 004410f0  894204                 -mov dword ptr [edx + 4], eax
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(4) /* 0x4 */) = cpu.eax;
    // 004410f3  39f1                   +cmp ecx, esi
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
    // 004410f5  7417                   -je 0x44110e
    if (cpu.flags.zf)
    {
        goto L_0x0044110e;
    }
    // 004410f7  c74210ffffffff         -mov dword ptr [edx + 0x10], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(16) /* 0x10 */) = 4294967295 /*0xffffffff*/;
    // 004410fe  c74234ffffffff         -mov dword ptr [edx + 0x34], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(52) /* 0x34 */) = 4294967295 /*0xffffffff*/;
    // 00441105  c74258ffffffff         -mov dword ptr [edx + 0x58], 0xffffffff
    app->getMemory<x86::reg32>(cpu.edx + x86::reg32(88) /* 0x58 */) = 4294967295 /*0xffffffff*/;
    // 0044110c  890a                   -mov dword ptr [edx], ecx
    app->getMemory<x86::reg32>(cpu.edx) = cpu.ecx;
L_0x0044110e:
    // 0044110e  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00441112  c70000000000           -mov dword ptr [eax], 0
    app->getMemory<x86::reg32>(cpu.eax) = 0 /*0x0*/;
    // 00441118  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
    // 0044111a  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 0044111d  b8ffffff7f             -mov eax, 0x7fffffff
    cpu.eax = 2147483647 /*0x7fffffff*/;
    // 00441122  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00441126  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 0044112a  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 0044112d  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00441131  8b1d3c1e5100           -mov ebx, dword ptr [0x511e3c]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5316156) /* 0x511e3c */);
    // 00441137  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 0044113a  31c9                   -xor ecx, ecx
    cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044113c  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 0044113e  ba481b5100             -mov edx, 0x511b48
    cpu.edx = 5315400 /*0x511b48*/;
    // 00441143  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00441145  7e1d                   -jle 0x441164
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00441164;
    }
L_0x00441147:
    // 00441147  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00441149  80b88c00000000         +cmp byte ptr [eax + 0x8c], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(140) /* 0x8c */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00441150  0f8473000000           -je 0x4411c9
    if (cpu.flags.zf)
    {
        goto L_0x004411c9;
    }
L_0x00441156:
    // 00441156  8b353c1e5100           -mov esi, dword ptr [0x511e3c]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5316156) /* 0x511e3c */);
    // 0044115c  41                     -inc ecx
    (cpu.ecx)++;
    // 0044115d  83c204                 -add edx, 4
    (cpu.edx) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00441160  39f1                   +cmp ecx, esi
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
    // 00441162  7ce3                   -jl 0x441147
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00441147;
    }
L_0x00441164:
    // 00441164  8b7d00                 -mov edi, dword ptr [ebp]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp);
    // 00441167  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00441169  0f8423010000           -je 0x441292
    if (cpu.flags.zf)
    {
        goto L_0x00441292;
    }
    // 0044116f  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 00441172  3b7a54                 +cmp edi, dword ptr [edx + 0x54]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(84) /* 0x54 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441175  0f8517010000           -jne 0x441292
    if (!cpu.flags.zf)
    {
        goto L_0x00441292;
    }
    // 0044117b  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0044117f  8b5a30                 -mov ebx, dword ptr [edx + 0x30]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */);
    // 00441182  3b18                   +cmp ebx, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441184  7411                   -je 0x441197
    if (cpu.flags.zf)
    {
        goto L_0x00441197;
    }
    // 00441186  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00441189  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0044118d  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 00441190  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 00441192  e8990a0000             -call 0x441c30
    cpu.esp -= 4;
    sub_441c30(app, cpu);
    if (cpu.terminate) return;
L_0x00441197:
    // 00441197  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0044119b  8b00                   -mov eax, dword ptr [eax]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax);
L_0x0044119d:
    // 0044119d  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 004411a0  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004411a3  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004411a7  8b4054                 -mov eax, dword ptr [eax + 0x54]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */);
    // 004411aa  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
L_0x004411ac:
    // 004411ac  83c410                 +add esp, 0x10
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
    // 004411af  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004411b0  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004411b1  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004411b2  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004411b5:
    // 004411b5  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004411b8  8b542404               -mov edx, dword ptr [esp + 4]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004411bc  8b400c                 -mov eax, dword ptr [eax + 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004411bf  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004411c1  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004411c4  8b4030                 -mov eax, dword ptr [eax + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 004411c7  ebd4                   -jmp 0x44119d
    goto L_0x0044119d;
L_0x004411c9:
    // 004411c9  8b442404               -mov eax, dword ptr [esp + 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 004411cd  8b30                   -mov esi, dword ptr [eax]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax);
    // 004411cf  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004411d1  740c                   -je 0x4411df
    if (cpu.flags.zf)
    {
        goto L_0x004411df;
    }
    // 004411d3  3b8ee8010000           +cmp ecx, dword ptr [esi + 0x1e8]
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.esi + x86::reg32(488) /* 0x1e8 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004411d9  0f8477ffffff           -je 0x441156
    if (cpu.flags.zf)
    {
        goto L_0x00441156;
    }
L_0x004411df:
    // 004411df  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 004411e1  f680f401000040         +test byte ptr [eax + 0x1f4], 0x40
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(500) /* 0x1f4 */) & 64 /*0x40*/));
    // 004411e8  0f8568ffffff           -jne 0x441156
    if (!cpu.flags.zf)
    {
        goto L_0x00441156;
    }
    // 004411ee  8b1f                   -mov ebx, dword ptr [edi]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi);
    // 004411f0  8bb09c000000           -mov esi, dword ptr [eax + 0x9c]
    cpu.esi = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(156) /* 0x9c */);
    // 004411f6  29de                   -sub esi, ebx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004411f8  8b98a0000000           -mov ebx, dword ptr [eax + 0xa0]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(160) /* 0xa0 */);
    // 004411fe  8b80a4000000           -mov eax, dword ptr [eax + 0xa4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(164) /* 0xa4 */);
    // 00441204  2b5f04                 -sub ebx, dword ptr [edi + 4]
    (cpu.ebx) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */)));
    // 00441207  2b4708                 -sub eax, dword ptr [edi + 8]
    (cpu.eax) -= x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edi + x86::reg32(8) /* 0x8 */)));
    // 0044120a  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 0044120c  7e56                   -jle 0x441264
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00441264;
    }
L_0x0044120e:
    // 0044120e  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00441210  7e56                   -jle 0x441268
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00441268;
    }
L_0x00441212:
    // 00441212  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00441214  7e56                   -jle 0x44126c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044126c;
    }
L_0x00441216:
    // 00441216  39c6                   +cmp esi, eax
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
    // 00441218  7e56                   -jle 0x441270
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00441270;
    }
    // 0044121a  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
L_0x0044121d:
    // 0044121d  01f0                   -add eax, esi
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.esi));
    // 0044121f  3d00004b00             +cmp eax, 0x4b0000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4915200 /*0x4b0000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441224  0f8d2cffffff           -jge 0x441156
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00441156;
    }
    // 0044122a  39c3                   +cmp ebx, eax
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
    // 0044122c  7e47                   -jle 0x441275
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00441275;
    }
    // 0044122e  c1f802                 -sar eax, 2
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (2 /*0x2*/ % 32));
L_0x00441231:
    // 00441231  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 00441233  3d00004b00             +cmp eax, 0x4b0000
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4915200 /*0x4b0000*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441238  0f8d18ffffff           -jge 0x441156
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00441156;
    }
    // 0044123e  8b742408               -mov esi, dword ptr [esp + 8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00441242  39f0                   +cmp eax, esi
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
    // 00441244  7d34                   -jge 0x44127a
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044127a;
    }
    // 00441246  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0044124a  8b1b                   -mov ebx, dword ptr [ebx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebx);
    // 0044124c  89442408               -mov dword ptr [esp + 8], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.eax;
    // 00441250  895d00                 -mov dword ptr [ebp], ebx
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.ebx;
    // 00441253  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00441257  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 00441259  8974240c               -mov dword ptr [esp + 0xc], esi
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.esi;
    // 0044125d  8903                   -mov dword ptr [ebx], eax
    app->getMemory<x86::reg32>(cpu.ebx) = cpu.eax;
    // 0044125f  e9f2feffff             -jmp 0x441156
    goto L_0x00441156;
L_0x00441264:
    // 00441264  f7de                   +neg esi
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.esi;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 00441266  eba6                   -jmp 0x44120e
    goto L_0x0044120e;
L_0x00441268:
    // 00441268  f7db                   +neg ebx
    {
        x86::reg32 tmp1 = 0;
        x86::reg32& tmp2 = cpu.ebx;
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        tmp2 = result;
        cpu.set_szp(tmp2);
    }
    // 0044126a  eba6                   -jmp 0x441212
    goto L_0x00441212;
L_0x0044126c:
    // 0044126c  f7d8                   +neg eax
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
    // 0044126e  eba6                   -jmp 0x441216
    goto L_0x00441216;
L_0x00441270:
    // 00441270  c1fe02                 +sar esi, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.esi;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00441273  eba8                   -jmp 0x44121d
    goto L_0x0044121d;
L_0x00441275:
    // 00441275  c1fb02                 +sar ebx, 2
    {
        x86::reg8 tmp = 2 /*0x2*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 00441278  ebb7                   -jmp 0x441231
    goto L_0x00441231;
L_0x0044127a:
    // 0044127a  3b44240c               +cmp eax, dword ptr [esp + 0xc]
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
    // 0044127e  0f8dd2feffff           -jge 0x441156
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00441156;
    }
    // 00441284  8944240c               -mov dword ptr [esp + 0xc], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.eax;
    // 00441288  8b02                   -mov eax, dword ptr [edx]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edx);
    // 0044128a  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 0044128d  e9c4feffff             -jmp 0x441156
    goto L_0x00441156;
L_0x00441292:
    // 00441292  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00441296  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00441298  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0044129a  743a                   -je 0x4412d6
    if (cpu.flags.zf)
    {
        goto L_0x004412d6;
    }
    // 0044129c  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 0044129f  3b5a30                 +cmp ebx, dword ptr [edx + 0x30]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004412a2  7532                   -jne 0x4412d6
    if (!cpu.flags.zf)
    {
        goto L_0x004412d6;
    }
    // 004412a4  8b4a54                 -mov ecx, dword ptr [edx + 0x54]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(84) /* 0x54 */);
    // 004412a7  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 004412aa  39c8                   +cmp eax, ecx
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
    // 004412ac  740d                   -je 0x4412bb
    if (cpu.flags.zf)
    {
        goto L_0x004412bb;
    }
    // 004412ae  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004412b0  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004412b3  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 004412b6  e875090000             -call 0x441c30
    cpu.esp -= 4;
    sub_441c30(app, cpu);
    if (cpu.terminate) return;
L_0x004412bb:
    // 004412bb  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004412bf  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 004412c2  8902                   -mov dword ptr [edx], eax
    app->getMemory<x86::reg32>(cpu.edx) = cpu.eax;
    // 004412c4  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004412c7  8b4030                 -mov eax, dword ptr [eax + 0x30]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */);
    // 004412ca  894500                 -mov dword ptr [ebp], eax
    app->getMemory<x86::reg32>(cpu.ebp) = cpu.eax;
    // 004412cd  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 004412d0  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004412d1  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004412d2  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004412d3  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x004412d6:
    // 004412d6  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004412d9  8b4500                 -mov eax, dword ptr [ebp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp);
    // 004412dc  3b4230                 +cmp eax, dword ptr [edx + 0x30]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.edx + x86::reg32(48) /* 0x30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004412df  740d                   -je 0x4412ee
    if (cpu.flags.zf)
    {
        goto L_0x004412ee;
    }
    // 004412e1  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004412e3  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 004412e6  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
    // 004412e9  e842090000             -call 0x441c30
    cpu.esp -= 4;
    sub_441c30(app, cpu);
    if (cpu.terminate) return;
L_0x004412ee:
    // 004412ee  8b1424                 -mov edx, dword ptr [esp]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    // 004412f1  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004412f5  8b6a54                 -mov ebp, dword ptr [edx + 0x54]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(84) /* 0x54 */);
    // 004412f8  3b28                   +cmp ebp, dword ptr [eax]
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004412fa  0f84acfeffff           -je 0x4411ac
    if (cpu.flags.zf)
    {
        goto L_0x004411ac;
    }
    // 00441300  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00441303  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00441307  83c054                 -add eax, 0x54
    (cpu.eax) += x86::reg32(x86::sreg32(84 /*0x54*/));
    // 0044130a  8b12                   -mov edx, dword ptr [edx]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx);
    // 0044130c  e81f090000             -call 0x441c30
    cpu.esp -= 4;
    sub_441c30(app, cpu);
    if (cpu.terminate) return;
    // 00441311  83c410                 -add esp, 0x10
    (cpu.esp) += x86::reg32(x86::sreg32(16 /*0x10*/));
    // 00441314  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441315  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441316  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441317  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_441320(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00441320  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00441321  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00441322  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00441323  89e5                   -mov ebp, esp
    cpu.ebp = cpu.esp;
    // 00441325  83ec20                 -sub esp, 0x20
    (cpu.esp) -= x86::reg32(x86::sreg32(32 /*0x20*/));
    // 00441328  8945e8                 -mov dword ptr [ebp - 0x18], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */) = cpu.eax;
    // 0044132b  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 0044132d  89de                   -mov esi, ebx
    cpu.esi = cpu.ebx;
    // 0044132f  894df4                 -mov dword ptr [ebp - 0xc], ecx
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */) = cpu.ecx;
    // 00441332  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 00441334  7506                   -jne 0x44133c
    if (!cpu.flags.zf)
    {
        goto L_0x0044133c;
    }
L_0x00441336:
    // 00441336  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00441338  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441339  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044133a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044133b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044133c:
    // 0044133c  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 0044133e  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 00441340  e85bfcffff             -call 0x440fa0
    cpu.esp -= 4;
    sub_440fa0(app, cpu);
    if (cpu.terminate) return;
    // 00441345  8945ec                 -mov dword ptr [ebp - 0x14], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */) = cpu.eax;
    // 00441348  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044134a  0f8cc6010000           -jl 0x441516
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00441516;
    }
    // 00441350  8d5de0                 -lea ebx, [ebp - 0x20]
    cpu.ebx = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00441353  8d919c000000           -lea edx, [ecx + 0x9c]
    cpu.edx = x86::reg32(cpu.ecx + x86::reg32(156) /* 0x9c */);
    // 00441359  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044135b  e890faffff             -call 0x440df0
    cpu.esp -= 4;
    sub_440df0(app, cpu);
    if (cpu.terminate) return;
    // 00441360  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00441362  8b45e8                 -mov eax, dword ptr [ebp - 0x18]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-24) /* -0x18 */);
    // 00441365  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 00441368  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044136a  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044136d  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 0044136f  0530b15000             -add eax, 0x50b130
    (cpu.eax) += x86::reg32(x86::sreg32(5288240 /*0x50b130*/));
    // 00441374  83ff04                 +cmp edi, 4
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441377  0f85ec010000           -jne 0x441569
    if (!cpu.flags.zf)
    {
        goto L_0x00441569;
    }
    // 0044137d  83c030                 -add eax, 0x30
    (cpu.eax) += x86::reg32(x86::sreg32(48 /*0x30*/));
L_0x00441380:
    // 00441380  8945f0                 -mov dword ptr [ebp - 0x10], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */) = cpu.eax;
    // 00441383  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00441385  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00441388  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0044138b  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0044138d  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00441390  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00441393  0fafc0                 -imul eax, eax
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00441396  8945fc                 -mov dword ptr [ebp - 4], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */) = cpu.eax;
    // 00441399  3df9150000             +cmp eax, 0x15f9
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5625 /*0x15f9*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044139e  0f8dcd010000           -jge 0x441571
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00441571;
    }
    // 004413a4  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x004413a6:
    // 004413a6  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004413a9  8b80f0020000           -mov eax, dword ptr [eax + 0x2f0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(752) /* 0x2f0 */);
    // 004413af  3d70170000             +cmp eax, 0x1770
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6000 /*0x1770*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004413b4  7e05                   -jle 0x4413bb
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004413bb;
    }
    // 004413b6  b870170000             -mov eax, 0x1770
    cpu.eax = 6000 /*0x1770*/;
L_0x004413bb:
    // 004413bb  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004413be  f682f401000010         +test byte ptr [edx + 0x1f4], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.edx + x86::reg32(500) /* 0x1f4 */) & 16 /*0x10*/));
    // 004413c5  0f84b0010000           -je 0x44157b
    if (cpu.flags.zf)
    {
        goto L_0x0044157b;
    }
    // 004413cb  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004413ce  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
L_0x004413d1:
    // 004413d1  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004413d3  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004413d6  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004413d9  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004413db  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004413de  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004413e0  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004413e3  83e90a                 -sub ecx, 0xa
    (cpu.ecx) -= x86::reg32(x86::sreg32(10 /*0xa*/));
    // 004413e6  89781c                 -mov dword ptr [eax + 0x1c], edi
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = cpu.edi;
    // 004413e9  85c9                   +test ecx, ecx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ecx & cpu.ecx));
    // 004413eb  0f8cb5010000           -jl 0x4415a6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004415a6;
    }
L_0x004413f1:
    // 004413f1  837dec00               +cmp dword ptr [ebp - 0x14], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004413f5  7e46                   -jle 0x44143d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044143d;
    }
    // 004413f7  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004413fa  8b500c                 -mov edx, dword ptr [eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(12) /* 0xc */);
    // 004413fd  894818                 -mov dword ptr [eax + 0x18], ecx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = cpu.ecx;
    // 00441400  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00441403  895814                 -mov dword ptr [eax + 0x14], ebx
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = cpu.ebx;
    // 00441406  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00441408  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0044140b  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 0044140e  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00441410  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00441413  89cb                   -mov ebx, ecx
    cpu.ebx = cpu.ecx;
    // 00441415  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00441418  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00441419  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0044141c  8aaaf4010000           -mov ch, byte ptr [edx + 0x1f4]
    cpu.ch = app->getMemory<x86::reg8>(cpu.edx + x86::reg32(500) /* 0x1f4 */);
    // 00441422  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00441423  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00441426  f6c510                 +test ch, 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(cpu.ch & 16 /*0x10*/));
    // 00441429  0f847e010000           -je 0x4415ad
    if (cpu.flags.zf)
    {
        goto L_0x004415ad;
    }
    // 0044142f  ba01000000             -mov edx, 1
    cpu.edx = 1 /*0x1*/;
L_0x00441434:
    // 00441434  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00441436  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00441438  e843110000             -call 0x442580
    cpu.esp -= 4;
    sub_442580(app, cpu);
    if (cpu.terminate) return;
L_0x0044143d:
    // 0044143d  83ff04                 +cmp edi, 4
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441440  0f856e010000           -jne 0x4415b4
    if (!cpu.flags.zf)
    {
        goto L_0x004415b4;
    }
    // 00441446  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
L_0x0044144b:
    // 0044144b  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 0044144e  8bbf90050000           -mov edi, dword ptr [edi + 0x590]
    cpu.edi = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(1424) /* 0x590 */);
    // 00441454  4f                     -dec edi
    (cpu.edi)--;
    // 00441455  8945f8                 -mov dword ptr [ebp - 8], eax
    app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */) = cpu.eax;
    // 00441458  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 0044145a  7c4e                   -jl 0x4414aa
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004414aa;
    }
    // 0044145c  8d34bd00000000         -lea esi, [edi*4]
    cpu.esi = x86::reg32(cpu.edi * 4);
    // 00441463  29fe                   -sub esi, edi
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edi));
    // 00441465  8b55f4                 -mov edx, dword ptr [ebp - 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00441468  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 0044146b  01d6                   -add esi, edx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.edx));
L_0x0044146d:
    // 0044146d  83be98050000ff         +cmp dword ptr [esi + 0x598], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1432) /* 0x598 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441474  0f8e44010000           -jle 0x4415be
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x004415be;
    }
    // 0044147a  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 0044147d  8b8ea4050000           -mov ecx, dword ptr [esi + 0x5a4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1444) /* 0x5a4 */);
    // 00441483  8b9e9d050000           -mov ebx, dword ptr [esi + 0x59d]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1437) /* 0x59d */);
    // 00441489  8b9699050000           -mov edx, dword ptr [esi + 0x599]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1433) /* 0x599 */);
    // 0044148f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00441490  8b45fc                 -mov eax, dword ptr [ebp - 4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 00441493  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 00441496  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00441497  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0044149a  8b45f8                 -mov eax, dword ptr [ebp - 8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-8) /* -0x8 */);
L_0x0044149d:
    // 0044149d  e84e100000             -call 0x4424f0
    cpu.esp -= 4;
    sub_4424f0(app, cpu);
    if (cpu.terminate) return;
    // 004414a2  4f                     -dec edi
    (cpu.edi)--;
    // 004414a3  83ee18                 -sub esi, 0x18
    (cpu.esi) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004414a6  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 004414a8  7dc3                   -jge 0x44146d
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044146d;
    }
L_0x004414aa:
    // 004414aa  8b45f4                 -mov eax, dword ptr [ebp - 0xc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004414ad  f680f401000004         +test byte ptr [eax + 0x1f4], 4
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(500) /* 0x1f4 */) & 4 /*0x4*/));
    // 004414b4  0f846c010000           -je 0x441626
    if (cpu.flags.zf)
    {
        goto L_0x00441626;
    }
    // 004414ba  80b8dd02000000         +cmp byte ptr [eax + 0x2dd], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(733) /* 0x2dd */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004414c1  0f8438010000           -je 0x4415ff
    if (cpu.flags.zf)
    {
        goto L_0x004415ff;
    }
    // 004414c7  80b81803000000         +cmp byte ptr [eax + 0x318], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(792) /* 0x318 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004414ce  0f852b010000           -jne 0x4415ff
    if (!cpu.flags.zf)
    {
        goto L_0x004415ff;
    }
    // 004414d4  83b81c03000000         +cmp dword ptr [eax + 0x31c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(796) /* 0x31c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004414db  0f851e010000           -jne 0x4415ff
    if (!cpu.flags.zf)
    {
        goto L_0x004415ff;
    }
    // 004414e1  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 004414e4  a128b25000             -mov eax, dword ptr [0x50b228]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5288488) /* 0x50b228 */);
    // 004414e9  39f8                   +cmp eax, edi
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
    // 004414eb  0f84f7000000           -je 0x4415e8
    if (cpu.flags.zf)
    {
        goto L_0x004415e8;
    }
    // 004414f1  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004414f3  0f853dfeffff           -jne 0x441336
    if (!cpu.flags.zf)
    {
        goto L_0x00441336;
    }
    // 004414f9  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004414fc  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004414ff  8d55e0                 -lea edx, [ebp - 0x20]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 00441502  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 00441505  e8a6010000             -call 0x4416b0
    cpu.esp -= 4;
    sub_4416b0(app, cpu);
    if (cpu.terminate) return;
    // 0044150a  893d28b25000           -mov dword ptr [0x50b228], edi
    app->getMemory<x86::reg32>(x86::reg32(5288488) /* 0x50b228 */) = cpu.edi;
    // 00441510  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00441512  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441513  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441514  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441515  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00441516:
    // 00441516  8b9190050000           -mov edx, dword ptr [ecx + 0x590]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(1424) /* 0x590 */);
    // 0044151c  4a                     -dec edx
    (cpu.edx)--;
    // 0044151d  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044151f  0f8c11feffff           -jl 0x441336
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00441336;
    }
    // 00441525  8d349500000000         -lea esi, [edx*4]
    cpu.esi = x86::reg32(cpu.edx * 4);
    // 0044152c  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044152e  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 00441531  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x00441533:
    // 00441533  83bea405000000         +cmp dword ptr [esi + 0x5a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1444) /* 0x5a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044153a  7518                   -jne 0x441554
    if (!cpu.flags.zf)
    {
        goto L_0x00441554;
    }
    // 0044153c  83be98050000ff         +cmp dword ptr [esi + 0x598], -1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1432) /* 0x598 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(-1 /*-0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441543  7e0f                   -jle 0x441554
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00441554;
    }
    // 00441545  83ff04                 +cmp edi, 4
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441548  7518                   -jne 0x441562
    if (!cpu.flags.zf)
    {
        goto L_0x00441562;
    }
    // 0044154a  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
L_0x0044154f:
    // 0044154f  e87c320000             -call 0x4447d0
    cpu.esp -= 4;
    sub_4447d0(app, cpu);
    if (cpu.terminate) return;
L_0x00441554:
    // 00441554  4a                     -dec edx
    (cpu.edx)--;
    // 00441555  83ee18                 -sub esi, 0x18
    (cpu.esi) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00441558  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044155a  0f8cd6fdffff           -jl 0x441336
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00441336;
    }
    // 00441560  ebd1                   -jmp 0x441533
    goto L_0x00441533;
L_0x00441562:
    // 00441562  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 00441567  ebe6                   -jmp 0x44154f
    goto L_0x0044154f;
L_0x00441569:
    // 00441569  83c054                 +add eax, 0x54
    {
        x86::reg32& tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(84 /*0x54*/));
        x86::reg32 result = tmp1 + tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) == (1 & (tmp2 >> 31));
        cpu.flags.cf = result < tmp1;
        tmp1 = result;
        cpu.set_szp(tmp1);
    }
    // 0044156c  e90ffeffff             -jmp 0x441380
    goto L_0x00441380;
L_0x00441571:
    // 00441571  bbf9150000             -mov ebx, 0x15f9
    cpu.ebx = 5625 /*0x15f9*/;
    // 00441576  e92bfeffff             -jmp 0x4413a6
    goto L_0x004413a6;
L_0x0044157b:
    // 0044157b  8b92ec020000           -mov edx, dword ptr [edx + 0x2ec]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(748) /* 0x2ec */);
    // 00441581  8b8af0000000           -mov ecx, dword ptr [edx + 0xf0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(240) /* 0xf0 */);
    // 00441587  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00441589  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 0044158c  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 0044158e  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00441590  81c1d0070000           -add ecx, 0x7d0
    (cpu.ecx) += x86::reg32(x86::sreg32(2000 /*0x7d0*/));
    // 00441596  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00441599  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0044159b  8b55ec                 -mov edx, dword ptr [ebp - 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 0044159e  0fafd0                 +imul edx, eax
    {
        x86::sreg64 tmp = x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax));
        cpu.edx = static_cast<x86::reg32>(static_cast<x86::sreg32>(tmp));
        cpu.flags.of = cpu.flags.cf = (tmp != x86::sreg64(x86::sreg32(cpu.edx)));
    }
    // 004415a1  e92bfeffff             -jmp 0x4413d1
    goto L_0x004413d1;
L_0x004415a6:
    // 004415a6  31c9                   +xor ecx, ecx
    cpu.clear_co();
    cpu.set_szp((cpu.ecx ^= x86::reg32(x86::sreg32(cpu.ecx))));
    // 004415a8  e944feffff             -jmp 0x4413f1
    goto L_0x004413f1;
L_0x004415ad:
    // 004415ad  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 004415af  e980feffff             -jmp 0x441434
    goto L_0x00441434;
L_0x004415b4:
    // 004415b4  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 004415b9  e98dfeffff             -jmp 0x44144b
    goto L_0x0044144b;
L_0x004415be:
    // 004415be  8d45e0                 -lea eax, [ebp - 0x20]
    cpu.eax = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004415c1  8b5dfc                 -mov ebx, dword ptr [ebp - 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004415c4  8b8ea4050000           -mov ecx, dword ptr [esi + 0x5a4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1444) /* 0x5a4 */);
    // 004415ca  8b9699050000           -mov edx, dword ptr [esi + 0x599]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1433) /* 0x599 */);
    // 004415d0  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 004415d1  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004415d4  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004415d5  8b9e9d050000           -mov ebx, dword ptr [esi + 0x59d]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1437) /* 0x59d */);
    // 004415db  b8ffffffff             -mov eax, 0xffffffff
    cpu.eax = 4294967295 /*0xffffffff*/;
    // 004415e0  c1fb18                 +sar ebx, 0x18
    {
        x86::reg8 tmp = 24 /*0x18*/ % 32;
        x86::reg32& op = cpu.ebx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 004415e3  e9b5feffff             -jmp 0x44149d
    goto L_0x0044149d;
L_0x004415e8:
    // 004415e8  8b4dfc                 -mov ecx, dword ptr [ebp - 4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-4) /* -0x4 */);
    // 004415eb  8b5dec                 -mov ebx, dword ptr [ebp - 0x14]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-20) /* -0x14 */);
    // 004415ee  8d55e0                 -lea edx, [ebp - 0x20]
    cpu.edx = x86::reg32(cpu.ebp + x86::reg32(-32) /* -0x20 */);
    // 004415f1  8b45f0                 -mov eax, dword ptr [ebp - 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-16) /* -0x10 */);
    // 004415f4  e8b7000000             -call 0x4416b0
    cpu.esp -= 4;
    sub_4416b0(app, cpu);
    if (cpu.terminate) return;
    // 004415f9  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 004415fb  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004415fc  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004415fd  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004415fe  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004415ff:
    // 004415ff  8b5df4                 -mov ebx, dword ptr [ebp - 0xc]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00441602  3b1d28b25000           +cmp ebx, dword ptr [0x50b228]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5288488) /* 0x50b228 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441608  0f8528fdffff           -jne 0x441336
    if (!cpu.flags.zf)
    {
        goto L_0x00441336;
    }
    // 0044160e  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 00441613  31f6                   -xor esi, esi
    cpu.esi ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00441615  e8b6310000             -call 0x4447d0
    cpu.esp -= 4;
    sub_4447d0(app, cpu);
    if (cpu.terminate) return;
    // 0044161a  893528b25000           -mov dword ptr [0x50b228], esi
    app->getMemory<x86::reg32>(x86::reg32(5288488) /* 0x50b228 */) = cpu.esi;
    // 00441620  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00441622  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441623  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441624  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441625  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00441626:
    // 00441626  8b7df4                 -mov edi, dword ptr [ebp - 0xc]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(-12) /* -0xc */);
    // 00441629  3b3d28b25000           +cmp edi, dword ptr [0x50b228]
    {
        x86::reg32 tmp1 = cpu.edi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5288488) /* 0x50b228 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044162f  0f8501fdffff           -jne 0x441336
    if (!cpu.flags.zf)
    {
        goto L_0x00441336;
    }
    // 00441635  a130b25000             -mov eax, dword ptr [0x50b230]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5288496) /* 0x50b230 */);
    // 0044163a  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044163c  7e42                   -jle 0x441680
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00441680;
    }
    // 0044163e  8d58ff                 -lea ebx, [eax - 1]
    cpu.ebx = x86::reg32(cpu.eax + x86::reg32(-1) /* -0x1 */);
    // 00441641  891d30b25000           -mov dword ptr [0x50b230], ebx
    app->getMemory<x86::reg32>(x86::reg32(5288496) /* 0x50b230 */) = cpu.ebx;
    // 00441647  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00441649  759d                   -jne 0x4415e8
    if (!cpu.flags.zf)
    {
        goto L_0x004415e8;
    }
    // 0044164b  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 00441650  e87b310000             -call 0x4447d0
    cpu.esp -= 4;
    sub_4447d0(app, cpu);
    if (cpu.terminate) return;
    // 00441655  8b3d24b25000           -mov edi, dword ptr [0x50b224]
    cpu.edi = app->getMemory<x86::reg32>(x86::reg32(5288484) /* 0x50b224 */);
    // 0044165b  4f                     +dec edi
    {
        x86::reg32& tmp = cpu.edi;
        cpu.flags.of = 1 & (tmp >> 31);
        tmp--;
        cpu.flags.of &= ~(1 & (tmp >> 31));
        cpu.set_szp(tmp);
    }
    // 0044165c  893d24b25000           -mov dword ptr [0x50b224], edi
    app->getMemory<x86::reg32>(x86::reg32(5288484) /* 0x50b224 */) = cpu.edi;
    // 00441662  7410                   -je 0x441674
    if (cpu.flags.zf)
    {
        goto L_0x00441674;
    }
    // 00441664  a120b25000             -mov eax, dword ptr [0x50b220]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5288480) /* 0x50b220 */);
    // 00441669  a330b25000             -mov dword ptr [0x50b230], eax
    app->getMemory<x86::reg32>(x86::reg32(5288496) /* 0x50b230 */) = cpu.eax;
    // 0044166e  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 00441670  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441671  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441672  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441673  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00441674:
    // 00441674  891d28b25000           -mov dword ptr [0x50b228], ebx
    app->getMemory<x86::reg32>(x86::reg32(5288488) /* 0x50b228 */) = cpu.ebx;
    // 0044167a  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044167c  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044167d  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044167e  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044167f  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00441680:
    // 00441680  8d5001                 -lea edx, [eax + 1]
    cpu.edx = x86::reg32(cpu.eax + x86::reg32(1) /* 0x1 */);
    // 00441683  891530b25000           -mov dword ptr [0x50b230], edx
    app->getMemory<x86::reg32>(x86::reg32(5288496) /* 0x50b230 */) = cpu.edx;
    // 00441689  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044168b  0f85a5fcffff           -jne 0x441336
    if (!cpu.flags.zf)
    {
        goto L_0x00441336;
    }
    // 00441691  a12cb25000             -mov eax, dword ptr [0x50b22c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5288492) /* 0x50b22c */);
    // 00441696  a330b25000             -mov dword ptr [0x50b230], eax
    app->getMemory<x86::reg32>(x86::reg32(5288496) /* 0x50b230 */) = cpu.eax;
    // 0044169b  89ec                   -mov esp, ebp
    cpu.esp = cpu.ebp;
    // 0044169d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044169e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044169f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004416a0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4416b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004416b0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 004416b1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 004416b2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 004416b3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 004416b5  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 004416b7  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 004416b9  8b08                   -mov ecx, dword ptr [eax]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax);
    // 004416bb  8b891c020000           -mov ecx, dword ptr [ecx + 0x21c]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(540) /* 0x21c */);
    // 004416c1  8b09                   -mov ecx, dword ptr [ecx]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.ecx);
    // 004416c3  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004416c5  8a9180594d00           -mov dl, byte ptr [ecx + 0x4d5980]
    cpu.dl = app->getMemory<x86::reg8>(cpu.ecx + x86::reg32(5069184) /* 0x4d5980 */);
    // 004416cb  0fafd3                 -imul edx, ebx
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.ebx)));
    // 004416ce  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004416d0  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004416d3  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 004416d6  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004416d8  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 004416db  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004416dd  83f87f                 +cmp eax, 0x7f
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
    // 004416e0  0f8e76000000           -jle 0x44175c
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044175c;
    }
    // 004416e6  bb7f000000             -mov ebx, 0x7f
    cpu.ebx = 127 /*0x7f*/;
L_0x004416eb:
    // 004416eb  8b06                   -mov eax, dword ptr [esi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esi);
    // 004416ed  f680f401000010         +test byte ptr [eax + 0x1f4], 0x10
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(500) /* 0x1f4 */) & 16 /*0x10*/));
    // 004416f4  0f846a000000           -je 0x441764
    if (cpu.flags.zf)
    {
        goto L_0x00441764;
    }
    // 004416fa  83f90f                 +cmp ecx, 0xf
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(15 /*0xf*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004416fd  740f                   -je 0x44170e
    if (cpu.flags.zf)
    {
        goto L_0x0044170e;
    }
    // 004416ff  83f910                 +cmp ecx, 0x10
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
    // 00441702  740a                   -je 0x44170e
    if (cpu.flags.zf)
    {
        goto L_0x0044170e;
    }
    // 00441704  83f91a                 +cmp ecx, 0x1a
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(26 /*0x1a*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441707  7405                   -je 0x44170e
    if (cpu.flags.zf)
    {
        goto L_0x0044170e;
    }
    // 00441709  83f91c                 +cmp ecx, 0x1c
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(28 /*0x1c*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044170c  755d                   -jne 0x44176b
    if (!cpu.flags.zf)
    {
        goto L_0x0044176b;
    }
L_0x0044170e:
    // 0044170e  be0b000000             -mov esi, 0xb
    cpu.esi = 11 /*0xb*/;
L_0x00441713:
    // 00441713  baf9150000             -mov edx, 0x15f9
    cpu.edx = 5625 /*0x15f9*/;
    // 00441718  29ea                   -sub edx, ebp
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 0044171a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044171c  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 0044171f  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00441721  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00441723  b9f9150000             -mov ecx, 0x15f9
    cpu.ecx = 5625 /*0x15f9*/;
    // 00441728  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0044172b  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 0044172d  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044172f  8b07                   -mov eax, dword ptr [edi]
    cpu.eax = app->getMemory<x86::reg32>(cpu.edi);
    // 00441731  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00441733  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00441736  c1e20a                 +shl edx, 0xa
    {
        x86::reg8 tmp = 10 /*0xa*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00441739  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 0044173b  c1f80a                 -sar eax, 0xa
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (10 /*0xa*/ % 32));
    // 0044173e  8b6f04                 -mov ebp, dword ptr [edi + 4]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.edi + x86::reg32(4) /* 0x4 */);
    // 00441741  83c040                 -add eax, 0x40
    (cpu.eax) += x86::reg32(x86::sreg32(64 /*0x40*/));
    // 00441744  89ea                   -mov edx, ebp
    cpu.edx = cpu.ebp;
    // 00441746  e8050b0000             -call 0x442250
    cpu.esp -= 4;
    sub_442250(app, cpu);
    if (cpu.terminate) return;
    // 0044174b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 0044174c  89f2                   -mov edx, esi
    cpu.edx = cpu.esi;
    // 0044174e  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 00441753  e8c82d0000             -call 0x444520
    cpu.esp -= 4;
    sub_444520(app, cpu);
    if (cpu.terminate) return;
    // 00441758  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441759  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044175a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044175b  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044175c:
    // 0044175c  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 0044175e  7d8b                   -jge 0x4416eb
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004416eb;
    }
    // 00441760  31c3                   +xor ebx, eax
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00441762  eb87                   -jmp 0x4416eb
    goto L_0x004416eb;
L_0x00441764:
    // 00441764  be01000000             -mov esi, 1
    cpu.esi = 1 /*0x1*/;
    // 00441769  eba8                   -jmp 0x441713
    goto L_0x00441713;
L_0x0044176b:
    // 0044176b  be0a000000             -mov esi, 0xa
    cpu.esi = 10 /*0xa*/;
    // 00441770  eba1                   -jmp 0x441713
    goto L_0x00441713;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_441780(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00441780  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00441781  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00441782  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00441783  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00441784  83ec2c                 -sub esp, 0x2c
    (cpu.esp) -= x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00441787  89442424               -mov dword ptr [esp + 0x24], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */) = cpu.eax;
    // 0044178b  8954241c               -mov dword ptr [esp + 0x1c], edx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */) = cpu.edx;
    // 0044178f  895c2420               -mov dword ptr [esp + 0x20], ebx
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */) = cpu.ebx;
    // 00441793  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00441795  0f84df010000           -je 0x44197a
    if (cpu.flags.zf)
    {
        goto L_0x0044197a;
    }
    // 0044179b  83bb8002000002         +cmp dword ptr [ebx + 0x280], 2
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(640) /* 0x280 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(2 /*0x2*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004417a2  0f85da010000           -jne 0x441982
    if (!cpu.flags.zf)
    {
        goto L_0x00441982;
    }
    // 004417a8  c7838802000000000000   -mov dword ptr [ebx + 0x288], 0
    app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(648) /* 0x288 */) = 0 /*0x0*/;
L_0x004417b2:
    // 004417b2  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004417b6  8b54241c               -mov edx, dword ptr [esp + 0x1c]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004417ba  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 004417be  e8ddf7ffff             -call 0x440fa0
    cpu.esp -= 4;
    sub_440fa0(app, cpu);
    if (cpu.terminate) return;
    // 004417c3  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 004417c7  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004417c9  0f8cbe020000           -jl 0x441a8d
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00441a8d;
    }
    // 004417cf  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004417d3  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 004417d5  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004417d9  81c29c000000           -add edx, 0x9c
    (cpu.edx) += x86::reg32(x86::sreg32(156 /*0x9c*/));
    // 004417df  e80cf6ffff             -call 0x440df0
    cpu.esp -= 4;
    sub_440df0(app, cpu);
    if (cpu.terminate) return;
    // 004417e4  8b1d08225100           -mov ebx, dword ptr [0x512208]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5317128) /* 0x512208 */);
    // 004417ea  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 004417ec  83fb01                 +cmp ebx, 1
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
    // 004417ef  7512                   -jne 0x441803
    if (!cpu.flags.zf)
    {
        goto L_0x00441803;
    }
    // 004417f1  837c242400             +cmp dword ptr [esp + 0x24], 0
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
    // 004417f6  0f85df020000           -jne 0x441adb
    if (!cpu.flags.zf)
    {
        goto L_0x00441adb;
    }
    // 004417fc  c7042400000100         -mov dword ptr [esp], 0x10000
    app->getMemory<x86::reg32>(cpu.esp) = 65536 /*0x10000*/;
L_0x00441803:
    // 00441803  8b442424               -mov eax, dword ptr [esp + 0x24]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(36) /* 0x24 */);
    // 00441807  c1e003                 -shl eax, 3
    cpu.eax <<= 3 /*0x3*/ % 32;
    // 0044180a  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 0044180c  c1e004                 -shl eax, 4
    cpu.eax <<= 4 /*0x4*/ % 32;
    // 0044180f  29c8                   -sub eax, ecx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ecx));
    // 00441811  0530b15000             -add eax, 0x50b130
    (cpu.eax) += x86::reg32(x86::sreg32(5288240 /*0x50b130*/));
    // 00441816  83c00c                 -add eax, 0xc
    (cpu.eax) += x86::reg32(x86::sreg32(12 /*0xc*/));
    // 00441819  89442414               -mov dword ptr [esp + 0x14], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */) = cpu.eax;
    // 0044181d  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044181f  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00441822  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00441825  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00441827  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044182a  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 0044182e  0fafc0                 -imul eax, eax
    cpu.eax = x86::reg32(x86::sreg64(x86::sreg32(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 00441831  89442428               -mov dword ptr [esp + 0x28], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */) = cpu.eax;
    // 00441835  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00441839  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0044183d  8b80ec020000           -mov eax, dword ptr [eax + 0x2ec]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(748) /* 0x2ec */);
    // 00441843  8b92f0020000           -mov edx, dword ptr [edx + 0x2f0]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(752) /* 0x2f0 */);
    // 00441849  8b88f0000000           -mov ecx, dword ptr [eax + 0xf0]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(240) /* 0xf0 */);
    // 0044184f  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00441851  c1e007                 -shl eax, 7
    cpu.eax <<= 7 /*0x7*/ % 32;
    // 00441854  29d0                   -sub eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00441856  89c2                   -mov edx, eax
    cpu.edx = cpu.eax;
    // 00441858  81c1d0070000           -add ecx, 0x7d0
    (cpu.ecx) += x86::reg32(x86::sreg32(2000 /*0x7d0*/));
    // 0044185e  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00441861  f7f9                   -idiv ecx
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.ecx);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00441863  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00441867  0fafd0                 -imul edx, eax
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(cpu.eax)));
    // 0044186a  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 0044186c  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 0044186f  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00441872  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00441874  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 00441877  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 00441879  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 0044187d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 0044187f  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00441883  8b6c2420               -mov ebp, dword ptr [esp + 0x20]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00441887  e8840e0000             -call 0x442710
    cpu.esp -= 4;
    sub_442710(app, cpu);
    if (cpu.terminate) return;
    // 0044188c  8bad90050000           -mov ebp, dword ptr [ebp + 0x590]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.ebp + x86::reg32(1424) /* 0x590 */);
    // 00441892  4d                     -dec ebp
    (cpu.ebp)--;
    // 00441893  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 00441895  7c65                   -jl 0x4418fc
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004418fc;
    }
    // 00441897  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0044189b  8d34ad00000000         -lea esi, [ebp*4]
    cpu.esi = x86::reg32(cpu.ebp * 4);
    // 004418a2  8b4c2420               -mov ecx, dword ptr [esp + 0x20]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 004418a6  29ee                   -sub esi, ebp
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.ebp));
    // 004418a8  0570010000             -add eax, 0x170
    (cpu.eax) += x86::reg32(x86::sreg32(368 /*0x170*/));
    // 004418ad  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 004418b0  89442418               -mov dword ptr [esp + 0x18], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */) = cpu.eax;
    // 004418b4  01ce                   -add esi, ecx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ecx));
L_0x004418b6:
    // 004418b6  8b9e98050000           -mov ebx, dword ptr [esi + 0x598]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1432) /* 0x598 */);
    // 004418bc  83fb06                 +cmp ebx, 6
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(6 /*0x6*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004418bf  0f8529020000           -jne 0x441aee
    if (!cpu.flags.zf)
    {
        goto L_0x00441aee;
    }
    // 004418c5  837c242400             +cmp dword ptr [esp + 0x24], 0
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
    // 004418ca  0f8417020000           -je 0x441ae7
    if (cpu.flags.zf)
    {
        goto L_0x00441ae7;
    }
    // 004418d0  bf07000000             -mov edi, 7
    cpu.edi = 7 /*0x7*/;
L_0x004418d5:
    // 004418d5  8b8e94050000           -mov ecx, dword ptr [esi + 0x594]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1428) /* 0x594 */);
    // 004418db  83f905                 +cmp ecx, 5
    {
        x86::reg32 tmp1 = cpu.ecx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(5 /*0x5*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004418de  0f8520020000           -jne 0x441b04
    if (!cpu.flags.zf)
    {
        goto L_0x00441b04;
    }
L_0x004418e4:
    // 004418e4  83ffff                 +cmp edi, -1
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
    // 004418e7  0f8e20020000           -jle 0x441b0d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00441b0d;
    }
    // 004418ed  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 004418ef  e8dc2e0000             -call 0x4447d0
    cpu.esp -= 4;
    sub_4447d0(app, cpu);
    if (cpu.terminate) return;
L_0x004418f4:
    // 004418f4  4d                     -dec ebp
    (cpu.ebp)--;
    // 004418f5  83ee18                 -sub esi, 0x18
    (cpu.esi) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 004418f8  85ed                   +test ebp, ebp
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebp & cpu.ebp));
    // 004418fa  7dba                   -jge 0x4418b6
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004418b6;
    }
L_0x004418fc:
    // 004418fc  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00441900  80b8dd02000000         +cmp byte ptr [eax + 0x2dd], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(733) /* 0x2dd */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00441907  0f8484020000           -je 0x441b91
    if (cpu.flags.zf)
    {
        goto L_0x00441b91;
    }
    // 0044190d  80b81803000000         +cmp byte ptr [eax + 0x318], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(cpu.eax + x86::reg32(792) /* 0x318 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00441914  0f8577020000           -jne 0x441b91
    if (!cpu.flags.zf)
    {
        goto L_0x00441b91;
    }
    // 0044191a  83b81c03000000         +cmp dword ptr [eax + 0x31c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(796) /* 0x31c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441921  0f856a020000           -jne 0x441b91
    if (!cpu.flags.zf)
    {
        goto L_0x00441b91;
    }
    // 00441927  8b542410               -mov edx, dword ptr [esp + 0x10]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 0044192b  c1e206                 -shl edx, 6
    cpu.edx <<= 6 /*0x6*/ % 32;
    // 0044192e  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00441930  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00441933  c1e210                 +shl edx, 0x10
    {
        x86::reg8 tmp = 16 /*0x10*/ % 32;
        x86::reg32& op = cpu.edx;
        if (tmp)
        {
            cpu.flags.cf = 1 & (op >> (32 - tmp));
            cpu.set_szp((op <<= tmp));
            if (tmp == 1) cpu.flags.of = (cpu.flags.cf != (1 & (op >> (32 - 1))));
        }
    }
    // 00441936  1bc2                   -sbb eax, edx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00441938  c1f810                 -sar eax, 0x10
    cpu.eax = x86::reg32(x86::sreg32(cpu.eax) >> (16 /*0x10*/ % 32));
    // 0044193b  833d0822510001         +cmp dword ptr [0x512208], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317128) /* 0x512208 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441942  7512                   -jne 0x441956
    if (!cpu.flags.zf)
    {
        goto L_0x00441956;
    }
    // 00441944  837c242400             +cmp dword ptr [esp + 0x24], 0
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
    // 00441949  0f8536020000           -jne 0x441b85
    if (!cpu.flags.zf)
    {
        goto L_0x00441b85;
    }
    // 0044194f  c7042400000100         -mov dword ptr [esp], 0x10000
    app->getMemory<x86::reg32>(cpu.esp) = 65536 /*0x10000*/;
L_0x00441956:
    // 00441956  8b742420               -mov esi, dword ptr [esp + 0x20]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 0044195a  89e1                   -mov ecx, esp
    cpu.ecx = cpu.esp;
    // 0044195c  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00441960  8bb6e8010000           -mov esi, dword ptr [esi + 0x1e8]
    cpu.esi = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(488) /* 0x1e8 */);
    // 00441966  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 00441968  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 0044196a  e8f10a0000             -call 0x442460
    cpu.esp -= 4;
    sub_442460(app, cpu);
    if (cpu.terminate) return;
    // 0044196f  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00441973  c7402001000000         -mov dword ptr [eax + 0x20], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
L_0x0044197a:
    // 0044197a  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 0044197d  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044197e  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044197f  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441980  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441981  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00441982:
    // 00441982  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 00441985  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 0044198c  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 0044198e  a1a4185100             -mov eax, dword ptr [0x5118a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5314724) /* 0x5118a4 */);
    // 00441993  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 00441996  8b54020c               -mov edx, dword ptr [edx + eax + 0xc]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(12) /* 0xc */ + cpu.eax * 1);
    // 0044199a  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 0044199d  8b83dc000000           -mov eax, dword ptr [ebx + 0xdc]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(220) /* 0xdc */);
    // 004419a3  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004419a5  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004419a8  c1e810                 +shr eax, 0x10
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
    // 004419ab  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004419ad  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004419b0  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 004419b2  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 004419b9  01c2                   -add edx, eax
    (cpu.edx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004419bb  a1a4185100             -mov eax, dword ptr [0x5118a4]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5314724) /* 0x5118a4 */);
    // 004419c0  c1e202                 -shl edx, 2
    cpu.edx <<= 2 /*0x2*/ % 32;
    // 004419c3  8b54020d               -mov edx, dword ptr [edx + eax + 0xd]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(13) /* 0xd */ + cpu.eax * 1);
    // 004419c7  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004419ca  8b83e0000000           -mov eax, dword ptr [ebx + 0xe0]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(224) /* 0xe0 */);
    // 004419d0  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004419d2  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 004419d5  c1e810                 +shr eax, 0x10
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
    // 004419d8  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 004419da  8b5314                 -mov edx, dword ptr [ebx + 0x14]
    cpu.edx = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(20) /* 0x14 */);
    // 004419dd  01c1                   -add ecx, eax
    (cpu.ecx) += x86::reg32(x86::sreg32(cpu.eax));
    // 004419df  8d04d500000000         -lea eax, [edx*8]
    cpu.eax = x86::reg32(cpu.edx * 8);
    // 004419e6  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004419e8  8b15a4185100           -mov edx, dword ptr [0x5118a4]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5314724) /* 0x5118a4 */);
    // 004419ee  8b54820e               -mov edx, dword ptr [edx + eax*4 + 0xe]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(14) /* 0xe */ + cpu.eax * 4);
    // 004419f2  c1fa18                 -sar edx, 0x18
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (24 /*0x18*/ % 32));
    // 004419f5  8b83e4000000           -mov eax, dword ptr [ebx + 0xe4]
    cpu.eax = app->getMemory<x86::reg32>(cpu.ebx + x86::reg32(228) /* 0xe4 */);
    // 004419fb  f7ea                   -imul edx
    cpu.edx_eax = x86::reg64(x86::sreg64(static_cast<x86::sreg32>(cpu.eax)) * x86::sreg64(x86::sreg32(cpu.edx)));
    // 004419fd  c1e210                 -shl edx, 0x10
    cpu.edx <<= 16 /*0x10*/ % 32;
    // 00441a00  c1e810                 +shr eax, 0x10
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
    // 00441a03  11d0                   -adc eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx) + cpu.flags.cf);
    // 00441a05  8b1d28225100           -mov ebx, dword ptr [0x512228]
    cpu.ebx = app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */);
    // 00441a0b  01c8                   -add eax, ecx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ecx));
    // 00441a0d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00441a0f  7504                   -jne 0x441a15
    if (!cpu.flags.zf)
    {
        goto L_0x00441a15;
    }
    // 00441a11  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00441a13  7c0d                   -jl 0x441a22
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00441a22;
    }
L_0x00441a15:
    // 00441a15  833d2822510000         +cmp dword ptr [0x512228], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317160) /* 0x512228 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441a1c  745c                   -je 0x441a7a
    if (cpu.flags.zf)
    {
        goto L_0x00441a7a;
    }
    // 00441a1e  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 00441a20  7e58                   -jle 0x441a7a
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00441a7a;
    }
L_0x00441a22:
    // 00441a22  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00441a26  6683b84c01000000       +cmp word ptr [eax + 0x14c], 0
    {
        x86::reg16 tmp1 = app->getMemory<x86::reg16>(cpu.eax + x86::reg32(332) /* 0x14c */);
        x86::reg16 tmp2 = x86::reg16(x86::sreg16(0 /*0x0*/));
        x86::reg16 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 15);
        cpu.flags.of ^= 1 & (result >> 15);
        cpu.flags.of &= (1 & (tmp1 >> 15)) != (1 & (tmp2 >> 15));
        cpu.set_szp(result);
    }
    // 00441a2e  0f857efdffff           -jne 0x4417b2
    if (!cpu.flags.zf)
    {
        goto L_0x004417b2;
    }
    // 00441a34  83b88c05000000         +cmp dword ptr [eax + 0x58c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(1420) /* 0x58c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441a3b  0f8571fdffff           -jne 0x4417b2
    if (!cpu.flags.zf)
    {
        goto L_0x004417b2;
    }
    // 00441a41  8ba888020000           -mov ebp, dword ptr [eax + 0x288]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(648) /* 0x288 */);
    // 00441a47  45                     -inc ebp
    (cpu.ebp)++;
    // 00441a48  89a888020000           -mov dword ptr [eax + 0x288], ebp
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(648) /* 0x288 */) = cpu.ebp;
    // 00441a4e  83fd40                 +cmp ebp, 0x40
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(64 /*0x40*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441a51  0f8c5bfdffff           -jl 0x4417b2
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004417b2;
    }
    // 00441a57  81fd94000000           +cmp ebp, 0x94
    {
        x86::reg32 tmp1 = cpu.ebp;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(148 /*0x94*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441a5d  0f8d4ffdffff           -jge 0x4417b2
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x004417b2;
    }
    // 00441a63  f680880200001f         +test byte ptr [eax + 0x288], 0x1f
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg8>(app->getMemory<x86::reg8>(cpu.eax + x86::reg32(648) /* 0x288 */) & 31 /*0x1f*/));
    // 00441a6a  0f8542fdffff           -jne 0x4417b2
    if (!cpu.flags.zf)
    {
        goto L_0x004417b2;
    }
    // 00441a70  e82b090000             -call 0x4423a0
    cpu.esp -= 4;
    sub_4423a0(app, cpu);
    if (cpu.terminate) return;
    // 00441a75  e938fdffff             -jmp 0x4417b2
    goto L_0x004417b2;
L_0x00441a7a:
    // 00441a7a  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00441a7e  c7808802000000000000   -mov dword ptr [eax + 0x288], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(648) /* 0x288 */) = 0 /*0x0*/;
    // 00441a88  e925fdffff             -jmp 0x4417b2
    goto L_0x004417b2;
L_0x00441a8d:
    // 00441a8d  8b542420               -mov edx, dword ptr [esp + 0x20]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00441a91  8b9290050000           -mov edx, dword ptr [edx + 0x590]
    cpu.edx = app->getMemory<x86::reg32>(cpu.edx + x86::reg32(1424) /* 0x590 */);
    // 00441a97  4a                     -dec edx
    (cpu.edx)--;
    // 00441a98  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00441a9a  0f8cdafeffff           -jl 0x44197a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0044197a;
    }
    // 00441aa0  8d349500000000         -lea esi, [edx*4]
    cpu.esi = x86::reg32(cpu.edx * 4);
    // 00441aa7  29d6                   -sub esi, edx
    (cpu.esi) -= x86::reg32(x86::sreg32(cpu.edx));
    // 00441aa9  8b5c2420               -mov ebx, dword ptr [esp + 0x20]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00441aad  c1e603                 -shl esi, 3
    cpu.esi <<= 3 /*0x3*/ % 32;
    // 00441ab0  01de                   -add esi, ebx
    (cpu.esi) += x86::reg32(x86::sreg32(cpu.ebx));
L_0x00441ab2:
    // 00441ab2  83bea405000000         +cmp dword ptr [esi + 0x5a4], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1444) /* 0x5a4 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441ab9  7512                   -jne 0x441acd
    if (!cpu.flags.zf)
    {
        goto L_0x00441acd;
    }
    // 00441abb  8bae98050000           -mov ebp, dword ptr [esi + 0x598]
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1432) /* 0x598 */);
    // 00441ac1  83fdff                 +cmp ebp, -1
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
    // 00441ac4  7e07                   -jle 0x441acd
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00441acd;
    }
    // 00441ac6  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00441ac8  e8032d0000             -call 0x4447d0
    cpu.esp -= 4;
    sub_4447d0(app, cpu);
    if (cpu.terminate) return;
L_0x00441acd:
    // 00441acd  4a                     -dec edx
    (cpu.edx)--;
    // 00441ace  83ee18                 -sub esi, 0x18
    (cpu.esi) -= x86::reg32(x86::sreg32(24 /*0x18*/));
    // 00441ad1  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00441ad3  0f8ca1feffff           -jl 0x44197a
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x0044197a;
    }
    // 00441ad9  ebd7                   -jmp 0x441ab2
    goto L_0x00441ab2;
L_0x00441adb:
    // 00441adb  c704240000ffff         -mov dword ptr [esp], 0xffff0000
    app->getMemory<x86::reg32>(cpu.esp) = 4294901760 /*0xffff0000*/;
    // 00441ae2  e91cfdffff             -jmp 0x441803
    goto L_0x00441803;
L_0x00441ae7:
    // 00441ae7  89df                   -mov edi, ebx
    cpu.edi = cpu.ebx;
    // 00441ae9  e9e7fdffff             -jmp 0x4418d5
    goto L_0x004418d5;
L_0x00441aee:
    // 00441aee  83fb08                 +cmp ebx, 8
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
    // 00441af1  75f4                   -jne 0x441ae7
    if (!cpu.flags.zf)
    {
        goto L_0x00441ae7;
    }
    // 00441af3  837c242400             +cmp dword ptr [esp + 0x24], 0
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
    // 00441af8  74ed                   -je 0x441ae7
    if (cpu.flags.zf)
    {
        goto L_0x00441ae7;
    }
    // 00441afa  bf09000000             -mov edi, 9
    cpu.edi = 9 /*0x9*/;
    // 00441aff  e9d1fdffff             -jmp 0x4418d5
    goto L_0x004418d5;
L_0x00441b04:
    // 00441b04  83f903                 +cmp ecx, 3
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
    // 00441b07  0f84d7fdffff           -je 0x4418e4
    if (cpu.flags.zf)
    {
        goto L_0x004418e4;
    }
L_0x00441b0d:
    // 00441b0d  85ff                   +test edi, edi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edi & cpu.edi));
    // 00441b0f  7d48                   -jge 0x441b59
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00441b59;
    }
    // 00441b11  833d0822510001         +cmp dword ptr [0x512208], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317128) /* 0x512208 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441b18  743f                   -je 0x441b59
    if (cpu.flags.zf)
    {
        goto L_0x00441b59;
    }
    // 00441b1a  8d5c2408               -lea ebx, [esp + 8]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00441b1e  8b542418               -mov edx, dword ptr [esp + 0x18]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(24) /* 0x18 */);
    // 00441b22  8b44241c               -mov eax, dword ptr [esp + 0x1c]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 00441b26  8b4c2428               -mov ecx, dword ptr [esp + 0x28]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00441b2a  e8c1f2ffff             -call 0x440df0
    cpu.esp -= 4;
    sub_440df0(app, cpu);
    if (cpu.terminate) return;
    // 00441b2f  8d442408               -lea eax, [esp + 8]
    cpu.eax = x86::reg32(cpu.esp + x86::reg32(8) /* 0x8 */);
    // 00441b33  8b9e9d050000           -mov ebx, dword ptr [esi + 0x59d]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1437) /* 0x59d */);
    // 00441b39  8b9699050000           -mov edx, dword ptr [esi + 0x599]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1433) /* 0x599 */);
    // 00441b3f  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00441b40  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 00441b43  c1fa18                 +sar edx, 0x18
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
    // 00441b46  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00441b47  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00441b49  8b8ea4050000           -mov ecx, dword ptr [esi + 0x5a4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1444) /* 0x5a4 */);
    // 00441b4f  e8dc2c0000             -call 0x444830
    cpu.esp -= 4;
    sub_444830(app, cpu);
    if (cpu.terminate) return;
    // 00441b54  e99bfdffff             -jmp 0x4418f4
    goto L_0x004418f4;
L_0x00441b59:
    // 00441b59  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 00441b5b  8b542428               -mov edx, dword ptr [esp + 0x28]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(40) /* 0x28 */);
    // 00441b5f  8b8ea4050000           -mov ecx, dword ptr [esi + 0x5a4]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1444) /* 0x5a4 */);
    // 00441b65  8b9e9d050000           -mov ebx, dword ptr [esi + 0x59d]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1437) /* 0x59d */);
    // 00441b6b  50                     -push eax
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.eax;
    cpu.esp -= 4;
    // 00441b6c  c1fb18                 -sar ebx, 0x18
    cpu.ebx = x86::reg32(x86::sreg32(cpu.ebx) >> (24 /*0x18*/ % 32));
    // 00441b6f  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00441b70  8b9699050000           -mov edx, dword ptr [esi + 0x599]
    cpu.edx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1433) /* 0x599 */);
    // 00441b76  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00441b78  c1fa18                 +sar edx, 0x18
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
    // 00441b7b  e8b02c0000             -call 0x444830
    cpu.esp -= 4;
    sub_444830(app, cpu);
    if (cpu.terminate) return;
    // 00441b80  e96ffdffff             -jmp 0x4418f4
    goto L_0x004418f4;
L_0x00441b85:
    // 00441b85  c704240000ffff         -mov dword ptr [esp], 0xffff0000
    app->getMemory<x86::reg32>(cpu.esp) = 4294901760 /*0xffff0000*/;
    // 00441b8c  e9c5fdffff             -jmp 0x441956
    goto L_0x00441956;
L_0x00441b91:
    // 00441b91  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00441b95  83782000               +cmp dword ptr [eax + 0x20], 0
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
    // 00441b99  0f84dbfdffff           -je 0x44197a
    if (cpu.flags.zf)
    {
        goto L_0x0044197a;
    }
    // 00441b9f  8b442420               -mov eax, dword ptr [esp + 0x20]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(32) /* 0x20 */);
    // 00441ba3  8b80e8010000           -mov eax, dword ptr [eax + 0x1e8]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(488) /* 0x1e8 */);
    // 00441ba9  e882080000             -call 0x442430
    cpu.esp -= 4;
    sub_442430(app, cpu);
    if (cpu.terminate) return;
    // 00441bae  8b442414               -mov eax, dword ptr [esp + 0x14]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(20) /* 0x14 */);
    // 00441bb2  c7402001000000         -mov dword ptr [eax + 0x20], 1
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 1 /*0x1*/;
    // 00441bb9  83c42c                 -add esp, 0x2c
    (cpu.esp) += x86::reg32(x86::sreg32(44 /*0x2c*/));
    // 00441bbc  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441bbd  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441bbe  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441bbf  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441bc0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_441bd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00441bd0  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00441bd1  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00441bd2  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00441bd3  89c6                   -mov esi, eax
    cpu.esi = cpu.eax;
    // 00441bd5  89d7                   -mov edi, edx
    cpu.edi = cpu.edx;
    // 00441bd7  8b1528b25000           -mov edx, dword ptr [0x50b228]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5288488) /* 0x50b228 */);
    // 00441bdd  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 00441bdf  7540                   -jne 0x441c21
    if (!cpu.flags.zf)
    {
        goto L_0x00441c21;
    }
    // 00441be1  b830b15000             -mov eax, 0x50b130
    cpu.eax = 5288240 /*0x50b130*/;
L_0x00441be6:
    // 00441be6  3b7030                 +cmp esi, dword ptr [eax + 0x30]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(48) /* 0x30 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441be9  7405                   -je 0x441bf0
    if (cpu.flags.zf)
    {
        goto L_0x00441bf0;
    }
    // 00441beb  3b7054                 +cmp esi, dword ptr [eax + 0x54]
    {
        x86::reg32 tmp1 = cpu.esi;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(cpu.eax + x86::reg32(84) /* 0x54 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441bee  7528                   -jne 0x441c18
    if (!cpu.flags.zf)
    {
        goto L_0x00441c18;
    }
L_0x00441bf0:
    // 00441bf0  891d30b25000           -mov dword ptr [0x50b230], ebx
    app->getMemory<x86::reg32>(x86::reg32(5288496) /* 0x50b230 */) = cpu.ebx;
    // 00441bf6  891d2cb25000           -mov dword ptr [0x50b22c], ebx
    app->getMemory<x86::reg32>(x86::reg32(5288492) /* 0x50b22c */) = cpu.ebx;
    // 00441bfc  890d20b25000           -mov dword ptr [0x50b220], ecx
    app->getMemory<x86::reg32>(x86::reg32(5288480) /* 0x50b220 */) = cpu.ecx;
    // 00441c02  89cd                   -mov ebp, ecx
    cpu.ebp = cpu.ecx;
    // 00441c04  893d24b25000           -mov dword ptr [0x50b224], edi
    app->getMemory<x86::reg32>(x86::reg32(5288484) /* 0x50b224 */) = cpu.edi;
    // 00441c0a  f7dd                   -neg ebp
    cpu.ebp = ~cpu.ebp + 1;
    // 00441c0c  893528b25000           -mov dword ptr [0x50b228], esi
    app->getMemory<x86::reg32>(x86::reg32(5288488) /* 0x50b228 */) = cpu.esi;
    // 00441c12  892d20b25000           -mov dword ptr [0x50b220], ebp
    app->getMemory<x86::reg32>(x86::reg32(5288480) /* 0x50b220 */) = cpu.ebp;
L_0x00441c18:
    // 00441c18  42                     -inc edx
    (cpu.edx)++;
    // 00441c19  83c078                 -add eax, 0x78
    (cpu.eax) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00441c1c  83fa02                 +cmp edx, 2
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
    // 00441c1f  7cc5                   -jl 0x441be6
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00441be6;
    }
L_0x00441c21:
    // 00441c21  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441c22  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441c23  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441c24  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_441c30(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00441c30  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00441c31  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00441c32  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00441c33  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00441c34  89c1                   -mov ecx, eax
    cpu.ecx = cpu.eax;
    // 00441c36  8b18                   -mov ebx, dword ptr [eax]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.eax);
    // 00441c38  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00441c3a  7436                   -je 0x441c72
    if (cpu.flags.zf)
    {
        goto L_0x00441c72;
    }
    // 00441c3c  8b3528b25000           -mov esi, dword ptr [0x50b228]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5288488) /* 0x50b228 */);
    // 00441c42  39f3                   +cmp ebx, esi
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
    // 00441c44  752c                   -jne 0x441c72
    if (!cpu.flags.zf)
    {
        goto L_0x00441c72;
    }
    // 00441c46  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 00441c4b  31ff                   -xor edi, edi
    cpu.edi ^= x86::reg32(x86::sreg32(cpu.edi));
    // 00441c4d  31f3                   -xor ebx, esi
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.esi));
    // 00441c4f  893d30b25000           -mov dword ptr [0x50b230], edi
    app->getMemory<x86::reg32>(x86::reg32(5288496) /* 0x50b230 */) = cpu.edi;
    // 00441c55  893d2cb25000           -mov dword ptr [0x50b22c], edi
    app->getMemory<x86::reg32>(x86::reg32(5288492) /* 0x50b22c */) = cpu.edi;
    // 00441c5b  893d20b25000           -mov dword ptr [0x50b220], edi
    app->getMemory<x86::reg32>(x86::reg32(5288480) /* 0x50b220 */) = cpu.edi;
    // 00441c61  891d24b25000           -mov dword ptr [0x50b224], ebx
    app->getMemory<x86::reg32>(x86::reg32(5288484) /* 0x50b224 */) = cpu.ebx;
    // 00441c67  893d28b25000           -mov dword ptr [0x50b228], edi
    app->getMemory<x86::reg32>(x86::reg32(5288488) /* 0x50b228 */) = cpu.edi;
    // 00441c6d  e85e2b0000             -call 0x4447d0
    cpu.esp -= 4;
    sub_4447d0(app, cpu);
    if (cpu.terminate) return;
L_0x00441c72:
    // 00441c72  8b791c                 -mov edi, dword ptr [ecx + 0x1c]
    cpu.edi = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
    // 00441c75  83ffff                 +cmp edi, -1
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
    // 00441c78  7f0c                   -jg 0x441c86
    if (!cpu.flags.zf && (cpu.flags.sf == cpu.flags.of))
    {
        goto L_0x00441c86;
    }
    // 00441c7a  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00441c7c  e80f010000             -call 0x441d90
    cpu.esp -= 4;
    sub_441d90(app, cpu);
    if (cpu.terminate) return;
    // 00441c81  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441c82  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441c83  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441c84  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441c85  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00441c86:
    // 00441c86  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00441c88  e8432b0000             -call 0x4447d0
    cpu.esp -= 4;
    sub_4447d0(app, cpu);
    if (cpu.terminate) return;
    // 00441c8d  83791c04               +cmp dword ptr [ecx + 0x1c], 4
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(28) /* 0x1c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(4 /*0x4*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441c91  7516                   -jne 0x441ca9
    if (!cpu.flags.zf)
    {
        goto L_0x00441ca9;
    }
    // 00441c93  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 00441c98  e8332b0000             -call 0x4447d0
    cpu.esp -= 4;
    sub_4447d0(app, cpu);
    if (cpu.terminate) return;
    // 00441c9d  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00441c9f  e8ec000000             -call 0x441d90
    cpu.esp -= 4;
    sub_441d90(app, cpu);
    if (cpu.terminate) return;
    // 00441ca4  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441ca5  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441ca6  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441ca7  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441ca8  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00441ca9:
    // 00441ca9  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 00441cae  e81d2b0000             -call 0x4447d0
    cpu.esp -= 4;
    sub_4447d0(app, cpu);
    if (cpu.terminate) return;
    // 00441cb3  89c8                   -mov eax, ecx
    cpu.eax = cpu.ecx;
    // 00441cb5  e8d6000000             -call 0x441d90
    cpu.esp -= 4;
    sub_441d90(app, cpu);
    if (cpu.terminate) return;
    // 00441cba  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441cbb  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441cbc  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441cbd  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441cbe  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_441cc0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00441cc0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00441cc1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00441cc2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00441cc3  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00441cc4  57                     -push edi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edi;
    cpu.esp -= 4;
    // 00441cc5  55                     -push ebp
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebp;
    cpu.esp -= 4;
    // 00441cc6  83ec04                 -sub esp, 4
    (cpu.esp) -= x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00441cc9  b930b15000             -mov ecx, 0x50b130
    cpu.ecx = 5288240 /*0x50b130*/;
    // 00441cce  b404                   -mov ah, 4
    cpu.ah = 4 /*0x4*/;
    // 00441cd0  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00441cd2  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00441cd4  891530b25000           -mov dword ptr [0x50b230], edx
    app->getMemory<x86::reg32>(x86::reg32(5288496) /* 0x50b230 */) = cpu.edx;
    // 00441cda  89152cb25000           -mov dword ptr [0x50b22c], edx
    app->getMemory<x86::reg32>(x86::reg32(5288492) /* 0x50b22c */) = cpu.edx;
    // 00441ce0  891520b25000           -mov dword ptr [0x50b220], edx
    app->getMemory<x86::reg32>(x86::reg32(5288480) /* 0x50b220 */) = cpu.edx;
    // 00441ce6  891524b25000           -mov dword ptr [0x50b224], edx
    app->getMemory<x86::reg32>(x86::reg32(5288484) /* 0x50b224 */) = cpu.edx;
    // 00441cec  891528b25000           -mov dword ptr [0x50b228], edx
    app->getMemory<x86::reg32>(x86::reg32(5288488) /* 0x50b228 */) = cpu.edx;
    // 00441cf2  8d6954                 -lea ebp, [ecx + 0x54]
    cpu.ebp = x86::reg32(cpu.ecx + x86::reg32(84) /* 0x54 */);
    // 00441cf5  891424                 -mov dword ptr [esp], edx
    app->getMemory<x86::reg32>(cpu.esp) = cpu.edx;
    // 00441cf8  8d7930                 -lea edi, [ecx + 0x30]
    cpu.edi = x86::reg32(cpu.ecx + x86::reg32(48) /* 0x30 */);
    // 00441cfb  88250c5a4d00           -mov byte ptr [0x4d5a0c], ah
    app->getMemory<x86::reg8>(x86::reg32(5069324) /* 0x4d5a0c */) = cpu.ah;
    // 00441d01  8d710c                 -lea esi, [ecx + 0xc]
    cpu.esi = x86::reg32(cpu.ecx + x86::reg32(12) /* 0xc */);
L_0x00441d04:
    // 00441d04  89f0                   -mov eax, esi
    cpu.eax = cpu.esi;
    // 00441d06  c701ffffffff           -mov dword ptr [ecx], 0xffffffff
    app->getMemory<x86::reg32>(cpu.ecx) = 4294967295 /*0xffffffff*/;
    // 00441d0c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00441d0e  c7410400000000         -mov dword ptr [ecx + 4], 0
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(4) /* 0x4 */) = 0 /*0x0*/;
    // 00441d15  e876000000             -call 0x441d90
    cpu.esp -= 4;
    sub_441d90(app, cpu);
    if (cpu.terminate) return;
    // 00441d1a  89f8                   -mov eax, edi
    cpu.eax = cpu.edi;
    // 00441d1c  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00441d1e  e86d000000             -call 0x441d90
    cpu.esp -= 4;
    sub_441d90(app, cpu);
    if (cpu.terminate) return;
    // 00441d23  89e8                   -mov eax, ebp
    cpu.eax = cpu.ebp;
    // 00441d25  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00441d27  e864000000             -call 0x441d90
    cpu.esp -= 4;
    sub_441d90(app, cpu);
    if (cpu.terminate) return;
    // 00441d2c  833d0822510001         +cmp dword ptr [0x512208], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317128) /* 0x512208 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441d33  7e42                   -jle 0x441d77
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00441d77;
    }
    // 00441d35  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 00441d37  7519                   -jne 0x441d52
    if (!cpu.flags.zf)
    {
        goto L_0x00441d52;
    }
    // 00441d39  8b15401e5100           -mov edx, dword ptr [0x511e40]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5316160) /* 0x511e40 */);
    // 00441d3f  a10c225100             -mov eax, dword ptr [0x51220c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5317132) /* 0x51220c */);
    // 00441d44  39d0                   +cmp eax, edx
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
    // 00441d46  7d0a                   -jge 0x441d52
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00441d52;
    }
    // 00441d48  8b0485081d5100         -mov eax, dword ptr [eax*4 + 0x511d08]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5315848) /* 0x511d08 */ + cpu.eax * 4);
L_0x00441d4f:
    // 00441d4f  89410c                 -mov dword ptr [ecx + 0xc], eax
    app->getMemory<x86::reg32>(cpu.ecx + x86::reg32(12) /* 0xc */) = cpu.eax;
L_0x00441d52:
    // 00441d52  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00441d55  43                     -inc ebx
    (cpu.ebx)++;
    // 00441d56  83c578                 -add ebp, 0x78
    (cpu.ebp) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00441d59  83c778                 -add edi, 0x78
    (cpu.edi) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00441d5c  83c678                 -add esi, 0x78
    (cpu.esi) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00441d5f  83c004                 -add eax, 4
    (cpu.eax) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00441d62  83c178                 -add ecx, 0x78
    (cpu.ecx) += x86::reg32(x86::sreg32(120 /*0x78*/));
    // 00441d65  890424                 -mov dword ptr [esp], eax
    app->getMemory<x86::reg32>(cpu.esp) = cpu.eax;
    // 00441d68  83fb02                 +cmp ebx, 2
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
    // 00441d6b  7c97                   -jl 0x441d04
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00441d04;
    }
    // 00441d6d  83c404                 -add esp, 4
    (cpu.esp) += x86::reg32(x86::sreg32(4 /*0x4*/));
    // 00441d70  5d                     -pop ebp
    cpu.ebp = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441d71  5f                     -pop edi
    cpu.edi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441d72  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441d73  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441d74  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441d75  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441d76  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00441d77:
    // 00441d77  3b1d401e5100           +cmp ebx, dword ptr [0x511e40]
    {
        x86::reg32 tmp1 = cpu.ebx;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5316160) /* 0x511e40 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441d7d  7dd3                   -jge 0x441d52
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x00441d52;
    }
    // 00441d7f  8b0424                 -mov eax, dword ptr [esp]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp);
    // 00441d82  8b80081d5100           -mov eax, dword ptr [eax + 0x511d08]
    cpu.eax = app->getMemory<x86::reg32>(cpu.eax + x86::reg32(5315848) /* 0x511d08 */);
    // 00441d88  ebc5                   -jmp 0x441d4f
    goto L_0x00441d4f;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_441d90(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00441d90  c74004ffffffff         -mov dword ptr [eax + 4], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(4) /* 0x4 */) = 4294967295 /*0xffffffff*/;
    // 00441d97  c74008ffffffff         -mov dword ptr [eax + 8], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(8) /* 0x8 */) = 4294967295 /*0xffffffff*/;
    // 00441d9e  c7401000000000         -mov dword ptr [eax + 0x10], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(16) /* 0x10 */) = 0 /*0x0*/;
    // 00441da5  c7402000000000         -mov dword ptr [eax + 0x20], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(32) /* 0x20 */) = 0 /*0x0*/;
    // 00441dac  c74014f9150000         -mov dword ptr [eax + 0x14], 0x15f9
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(20) /* 0x14 */) = 5625 /*0x15f9*/;
    // 00441db3  c7401800000000         -mov dword ptr [eax + 0x18], 0
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(24) /* 0x18 */) = 0 /*0x0*/;
    // 00441dba  c7401cffffffff         -mov dword ptr [eax + 0x1c], 0xffffffff
    app->getMemory<x86::reg32>(cpu.eax + x86::reg32(28) /* 0x1c */) = 4294967295 /*0xffffffff*/;
    // 00441dc1  8910                   -mov dword ptr [eax], edx
    app->getMemory<x86::reg32>(cpu.eax) = cpu.edx;
    // 00441dc3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_441dd0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00441dd0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00441dd1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00441dd2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00441dd3  83ec6c                 -sub esp, 0x6c
    (cpu.esp) -= x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00441dd6  833d0822510001         +cmp dword ptr [0x512208], 1
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317128) /* 0x512208 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(1 /*0x1*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441ddd  7468                   -je 0x441e47
    if (cpu.flags.zf)
    {
        goto L_0x00441e47;
    }
    // 00441ddf  833d50954d0000         +cmp dword ptr [0x4d9550], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5084496) /* 0x4d9550 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00441de6  0f85cb000000           -jne 0x441eb7
    if (!cpu.flags.zf)
    {
        goto L_0x00441eb7;
    }
    // 00441dec  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00441dee  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00441df0  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441df2  8d4c2460               -lea ecx, [esp + 0x60]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00441df6  e815990000             -call 0x44b710
    cpu.esp -= 4;
    sub_44b710(app, cpu);
    if (cpu.terminate) return;
    // 00441dfb  8d542464               -lea edx, [esp + 0x64]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00441dff  8d5c2468               -lea ebx, [esp + 0x68]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00441e03  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00441e04  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441e06  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00441e0a  e891f2ffff             -call 0x4410a0
    cpu.esp -= 4;
    sub_4410a0(app, cpu);
    if (cpu.terminate) return;
    // 00441e0f  8b5c2468               -mov ebx, dword ptr [esp + 0x68]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00441e13  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00441e15  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441e17  e864f9ffff             -call 0x441780
    cpu.esp -= 4;
    sub_441780(app, cpu);
    if (cpu.terminate) return;
    // 00441e1c  8b4c2460               -mov ecx, dword ptr [esp + 0x60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00441e20  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00441e22  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00441e27  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441e29  e8f2f4ffff             -call 0x441320
    cpu.esp -= 4;
    sub_441320(app, cpu);
    if (cpu.terminate) return;
    // 00441e2e  8b4c2464               -mov ecx, dword ptr [esp + 0x64]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00441e32  89e3                   -mov ebx, esp
    cpu.ebx = cpu.esp;
    // 00441e34  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 00441e39  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441e3b  e8e0f4ffff             -call 0x441320
    cpu.esp -= 4;
    sub_441320(app, cpu);
    if (cpu.terminate) return;
    // 00441e40  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00441e43  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441e44  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441e45  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441e46  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00441e47:
    // 00441e47  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00441e49  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00441e4b  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441e4d  8d4c2460               -lea ecx, [esp + 0x60]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00441e51  e8ba980000             -call 0x44b710
    cpu.esp -= 4;
    sub_44b710(app, cpu);
    if (cpu.terminate) return;
    // 00441e56  8d542464               -lea edx, [esp + 0x64]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00441e5a  8d5c2468               -lea ebx, [esp + 0x68]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00441e5e  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00441e5f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441e61  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00441e65  e836f2ffff             -call 0x4410a0
    cpu.esp -= 4;
    sub_4410a0(app, cpu);
    if (cpu.terminate) return;
    // 00441e6a  8b5c2468               -mov ebx, dword ptr [esp + 0x68]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00441e6e  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00441e70  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441e72  e809f9ffff             -call 0x441780
    cpu.esp -= 4;
    sub_441780(app, cpu);
    if (cpu.terminate) return;
    // 00441e77  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00441e79  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00441e7e  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 00441e80  8d4c2460               -lea ecx, [esp + 0x60]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00441e84  e887980000             -call 0x44b710
    cpu.esp -= 4;
    sub_44b710(app, cpu);
    if (cpu.terminate) return;
    // 00441e89  8d542464               -lea edx, [esp + 0x64]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00441e8d  8d5c2468               -lea ebx, [esp + 0x68]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00441e91  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00441e92  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00441e97  8d542404               -lea edx, [esp + 4]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(4) /* 0x4 */);
    // 00441e9b  e800f2ffff             -call 0x4410a0
    cpu.esp -= 4;
    sub_4410a0(app, cpu);
    if (cpu.terminate) return;
    // 00441ea0  8b5c2468               -mov ebx, dword ptr [esp + 0x68]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00441ea4  89e2                   -mov edx, esp
    cpu.edx = cpu.esp;
    // 00441ea6  b801000000             -mov eax, 1
    cpu.eax = 1 /*0x1*/;
    // 00441eab  e8d0f8ffff             -call 0x441780
    cpu.esp -= 4;
    sub_441780(app, cpu);
    if (cpu.terminate) return;
    // 00441eb0  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00441eb3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441eb4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441eb5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441eb6  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00441eb7:
    // 00441eb7  8d542464               -lea edx, [esp + 0x64]
    cpu.edx = x86::reg32(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00441ebb  8d4c2460               -lea ecx, [esp + 0x60]
    cpu.ecx = x86::reg32(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00441ebf  8d5c2468               -lea ebx, [esp + 0x68]
    cpu.ebx = x86::reg32(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00441ec3  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00441ec4  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441ec6  bae4225200             -mov edx, 0x5222e4
    cpu.edx = 5382884 /*0x5222e4*/;
    // 00441ecb  e8d0f1ffff             -call 0x4410a0
    cpu.esp -= 4;
    sub_4410a0(app, cpu);
    if (cpu.terminate) return;
    // 00441ed0  8b5c2468               -mov ebx, dword ptr [esp + 0x68]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(104) /* 0x68 */);
    // 00441ed4  bae4225200             -mov edx, 0x5222e4
    cpu.edx = 5382884 /*0x5222e4*/;
    // 00441ed9  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441edb  e8a0f8ffff             -call 0x441780
    cpu.esp -= 4;
    sub_441780(app, cpu);
    if (cpu.terminate) return;
    // 00441ee0  8b4c2460               -mov ecx, dword ptr [esp + 0x60]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(96) /* 0x60 */);
    // 00441ee4  bbe4225200             -mov ebx, 0x5222e4
    cpu.ebx = 5382884 /*0x5222e4*/;
    // 00441ee9  ba04000000             -mov edx, 4
    cpu.edx = 4 /*0x4*/;
    // 00441eee  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441ef0  e82bf4ffff             -call 0x441320
    cpu.esp -= 4;
    sub_441320(app, cpu);
    if (cpu.terminate) return;
    // 00441ef5  8b4c2464               -mov ecx, dword ptr [esp + 0x64]
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(100) /* 0x64 */);
    // 00441ef9  bbe4225200             -mov ebx, 0x5222e4
    cpu.ebx = 5382884 /*0x5222e4*/;
    // 00441efe  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 00441f03  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00441f05  e816f4ffff             -call 0x441320
    cpu.esp -= 4;
    sub_441320(app, cpu);
    if (cpu.terminate) return;
    // 00441f0a  83c46c                 -add esp, 0x6c
    (cpu.esp) += x86::reg32(x86::sreg32(108 /*0x6c*/));
    // 00441f0d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441f0e  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441f0f  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00441f10  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
/* data blob: 28bb4c0030bb4c0038bb4c0040bb4c0048bb4c0050bb4c0058bb4c0060bb4c0068bb4c0070bb4c0078bb4c0080bb4c0088bb4c0090bb4c0098bb4c00a0bb4c00a8bb4c00b0bb4c00b8bb4c00c0bb4c00c8bb4c00d0bb4c00d8bb4c00e0bb4c00e8bb4c00f0bb4c00f8bb4c0000bc4c0008bc4c0010bc4c0018bc4c0020bc4c0028bc4c0030bc4c0038bc4c0040bc4c0048bc4c0050bc4c0058bc4c0060bc4c0068bc4c0070bc4c0078bc4c0080bc4c0088bc4c0090bc4c0098bc4c00a0bc4c00a8bc4c00b0bc4c00b8bc4c00c0bc4c00c8bc4c00d0bc4c00d8bc4c00e0bc4c00e8bc4c00f0bc4c00f0bc4c00f0bc4c00 */
void Application::sub_442010(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442010  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00442011  803d195a4d0000         +cmp byte ptr [0x4d5a19], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5069337) /* 0x4d5a19 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00442018  741c                   -je 0x442036
    if (cpu.flags.zf)
    {
        goto L_0x00442036;
    }
    // 0044201a  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044201c  a1305a4d00             -mov eax, dword ptr [0x4d5a30]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5069360) /* 0x4d5a30 */);
    // 00442021  8915305a4d00           -mov dword ptr [0x4d5a30], edx
    app->getMemory<x86::reg32>(x86::reg32(5069360) /* 0x4d5a30 */) = cpu.edx;
    // 00442027  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 00442029  a3345a4d00             -mov dword ptr [0x4d5a34], eax
    app->getMemory<x86::reg32>(x86::reg32(5069364) /* 0x4d5a34 */) = cpu.eax;
    // 0044202e  8835195a4d00           -mov byte ptr [0x4d5a19], dh
    app->getMemory<x86::reg8>(x86::reg32(5069337) /* 0x4d5a19 */) = cpu.dh;
    // 00442034  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442035  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00442036:
    // 00442036  a1345a4d00             -mov eax, dword ptr [0x4d5a34]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5069364) /* 0x4d5a34 */);
    // 0044203b  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 0044203d  a3305a4d00             -mov dword ptr [0x4d5a30], eax
    app->getMemory<x86::reg32>(x86::reg32(5069360) /* 0x4d5a30 */) = cpu.eax;
    // 00442042  8815195a4d00           -mov byte ptr [0x4d5a19], dl
    app->getMemory<x86::reg8>(x86::reg32(5069337) /* 0x4d5a19 */) = cpu.dl;
    // 00442048  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442049  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_442050(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442050  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00442051  803d185a4d0000         +cmp byte ptr [0x4d5a18], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5069336) /* 0x4d5a18 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00442058  7411                   -je 0x44206b
    if (cpu.flags.zf)
    {
        goto L_0x0044206b;
    }
    // 0044205a  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044205c  30f6                   -xor dh, dh
    cpu.dh ^= x86::reg8(x86::sreg8(cpu.dh));
    // 0044205e  e89d770400             -call 0x489800
    cpu.esp -= 4;
    sub_489800(app, cpu);
    if (cpu.terminate) return;
    // 00442063  8835185a4d00           -mov byte ptr [0x4d5a18], dh
    app->getMemory<x86::reg8>(x86::reg32(5069336) /* 0x4d5a18 */) = cpu.dh;
    // 00442069  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044206a  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x0044206b:
    // 0044206b  a12c5a4d00             -mov eax, dword ptr [0x4d5a2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5069356) /* 0x4d5a2c */);
    // 00442070  b201                   -mov dl, 1
    cpu.dl = 1 /*0x1*/;
    // 00442072  e889770400             -call 0x489800
    cpu.esp -= 4;
    sub_489800(app, cpu);
    if (cpu.terminate) return;
    // 00442077  8815185a4d00           -mov byte ptr [0x4d5a18], dl
    app->getMemory<x86::reg8>(x86::reg32(5069336) /* 0x4d5a18 */) = cpu.dl;
    // 0044207d  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044207e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_442080(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442080  b804000000             -mov eax, 4
    cpu.eax = 4 /*0x4*/;
    // 00442085  e846270000             -call 0x4447d0
    cpu.esp -= 4;
    sub_4447d0(app, cpu);
    if (cpu.terminate) return;
    // 0044208a  b805000000             -mov eax, 5
    cpu.eax = 5 /*0x5*/;
    // 0044208f  e83c270000             -call 0x4447d0
    cpu.esp -= 4;
    sub_4447d0(app, cpu);
    if (cpu.terminate) return;
    // 00442094  b806000000             -mov eax, 6
    cpu.eax = 6 /*0x6*/;
    // 00442099  e832270000             -call 0x4447d0
    cpu.esp -= 4;
    sub_4447d0(app, cpu);
    if (cpu.terminate) return;
    // 0044209e  b807000000             -mov eax, 7
    cpu.eax = 7 /*0x7*/;
    // 004420a3  e828270000             -call 0x4447d0
    cpu.esp -= 4;
    sub_4447d0(app, cpu);
    if (cpu.terminate) return;
    // 004420a8  b808000000             -mov eax, 8
    cpu.eax = 8 /*0x8*/;
    // 004420ad  e81e270000             -call 0x4447d0
    cpu.esp -= 4;
    sub_4447d0(app, cpu);
    if (cpu.terminate) return;
    // 004420b2  b809000000             -mov eax, 9
    cpu.eax = 9 /*0x9*/;
    // 004420b7  e814270000             -call 0x4447d0
    cpu.esp -= 4;
    sub_4447d0(app, cpu);
    if (cpu.terminate) return;
    // 004420bc  b80c000000             -mov eax, 0xc
    cpu.eax = 12 /*0xc*/;
    // 004420c1  e80a270000             -call 0x4447d0
    cpu.esp -= 4;
    sub_4447d0(app, cpu);
    if (cpu.terminate) return;
    // 004420c6  b80d000000             -mov eax, 0xd
    cpu.eax = 13 /*0xd*/;
    // 004420cb  e800270000             -call 0x4447d0
    cpu.esp -= 4;
    sub_4447d0(app, cpu);
    if (cpu.terminate) return;
    // 004420d0  b80e000000             -mov eax, 0xe
    cpu.eax = 14 /*0xe*/;
    // 004420d5  e8f6260000             -call 0x4447d0
    cpu.esp -= 4;
    sub_4447d0(app, cpu);
    if (cpu.terminate) return;
    // 004420da  b80f000000             -mov eax, 0xf
    cpu.eax = 15 /*0xf*/;
    // 004420df  e8ec260000             -call 0x4447d0
    cpu.esp -= 4;
    sub_4447d0(app, cpu);
    if (cpu.terminate) return;
    // 004420e4  b810000000             -mov eax, 0x10
    cpu.eax = 16 /*0x10*/;
    // 004420e9  e8e2260000             -call 0x4447d0
    cpu.esp -= 4;
    sub_4447d0(app, cpu);
    if (cpu.terminate) return;
    // 004420ee  b811000000             -mov eax, 0x11
    cpu.eax = 17 /*0x11*/;
    // 004420f3  e8d8260000             -call 0x4447d0
    cpu.esp -= 4;
    sub_4447d0(app, cpu);
    if (cpu.terminate) return;
    // 004420f8  b812000000             -mov eax, 0x12
    cpu.eax = 18 /*0x12*/;
    // 004420fd  e8ce260000             -call 0x4447d0
    cpu.esp -= 4;
    sub_4447d0(app, cpu);
    if (cpu.terminate) return;
    // 00442102  b813000000             -mov eax, 0x13
    cpu.eax = 19 /*0x13*/;
    // 00442107  e8c4260000             -call 0x4447d0
    cpu.esp -= 4;
    sub_4447d0(app, cpu);
    if (cpu.terminate) return;
    // 0044210c  b815000000             -mov eax, 0x15
    cpu.eax = 21 /*0x15*/;
    // 00442111  e8ba260000             -call 0x4447d0
    cpu.esp -= 4;
    sub_4447d0(app, cpu);
    if (cpu.terminate) return;
    // 00442116  b816000000             -mov eax, 0x16
    cpu.eax = 22 /*0x16*/;
    // 0044211b  e8b0260000             -call 0x4447d0
    cpu.esp -= 4;
    sub_4447d0(app, cpu);
    if (cpu.terminate) return;
    // 00442120  b817000000             -mov eax, 0x17
    cpu.eax = 23 /*0x17*/;
    // 00442125  e9a6260000             -jmp 0x4447d0
    return sub_4447d0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_442130(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442130  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 00442131  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 00442132  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00442133  6aff                   -push -1
    app->getMemory<x86::reg32>(cpu.esp-4) = -1 /*-0x1*/;
    cpu.esp -= 4;
    // 00442135  b9ffffffff             -mov ecx, 0xffffffff
    cpu.ecx = 4294967295 /*0xffffffff*/;
    // 0044213a  bb14000000             -mov ebx, 0x14
    cpu.ebx = 20 /*0x14*/;
    // 0044213f  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 00442144  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00442146  e8f5b90500             -call 0x49db40
    cpu.esp -= 4;
    sub_49db40(app, cpu);
    if (cpu.terminate) return;
    // 0044214b  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 0044214d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 0044214f  e854ba0500             -call 0x49dba8
    cpu.esp -= 4;
    sub_49dba8(app, cpu);
    if (cpu.terminate) return;
    // 00442154  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442155  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442156  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442157  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_442160(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442160  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 00442161  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00442163  e848b90500             -call 0x49dab0
    cpu.esp -= 4;
    sub_49dab0(app, cpu);
    if (cpu.terminate) return;
    // 00442168  e873410300             -call 0x4762e0
    cpu.esp -= 4;
    sub_4762e0(app, cpu);
    if (cpu.terminate) return;
    // 0044216d  e8aeb90500             -call 0x49db20
    cpu.esp -= 4;
    sub_49db20(app, cpu);
    if (cpu.terminate) return;
    // 00442172  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x00442174:
    // 00442174  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00442176  42                     -inc edx
    (cpu.edx)++;
    // 00442177  e834b90500             -call 0x49dab0
    cpu.esp -= 4;
    sub_49dab0(app, cpu);
    if (cpu.terminate) return;
    // 0044217c  81fa80000000           +cmp edx, 0x80
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
    // 00442182  7cf0                   -jl 0x442174
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x00442174;
    }
    // 00442184  803d485a4d0000         +cmp byte ptr [0x4d5a48], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5069384) /* 0x4d5a48 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 0044218b  7507                   -jne 0x442194
    if (!cpu.flags.zf)
    {
        goto L_0x00442194;
    }
    // 0044218d  e8fe410000             -call 0x446390
    cpu.esp -= 4;
    sub_446390(app, cpu);
    if (cpu.terminate) return;
    // 00442192  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442193  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00442194:
    // 00442194  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 00442196  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 00442198  e80bba0500             -call 0x49dba8
    cpu.esp -= 4;
    sub_49dba8(app, cpu);
    if (cpu.terminate) return;
    // 0044219d  e8ee410000             -call 0x446390
    cpu.esp -= 4;
    sub_446390(app, cpu);
    if (cpu.terminate) return;
    // 004421a2  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004421a3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4421b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004421b0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004421b1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004421b3  e8f8b80500             -call 0x49dab0
    cpu.esp -= 4;
    sub_49dab0(app, cpu);
    if (cpu.terminate) return;
    // 004421b8  e823410300             -call 0x4762e0
    cpu.esp -= 4;
    sub_4762e0(app, cpu);
    if (cpu.terminate) return;
    // 004421bd  e85eb90500             -call 0x49db20
    cpu.esp -= 4;
    sub_49db20(app, cpu);
    if (cpu.terminate) return;
    // 004421c2  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
L_0x004421c4:
    // 004421c4  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004421c6  42                     -inc edx
    (cpu.edx)++;
    // 004421c7  e8e4b80500             -call 0x49dab0
    cpu.esp -= 4;
    sub_49dab0(app, cpu);
    if (cpu.terminate) return;
    // 004421cc  81fa80000000           +cmp edx, 0x80
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
    // 004421d2  7cf0                   -jl 0x4421c4
    if (cpu.flags.sf != cpu.flags.of)
    {
        goto L_0x004421c4;
    }
    // 004421d4  803d485a4d0000         +cmp byte ptr [0x4d5a48], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5069384) /* 0x4d5a48 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 004421db  7502                   -jne 0x4421df
    if (!cpu.flags.zf)
    {
        goto L_0x004421df;
    }
    // 004421dd  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004421de  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004421df:
    // 004421df  31d2                   -xor edx, edx
    cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx));
    // 004421e1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004421e3  e8c0b90500             -call 0x49dba8
    cpu.esp -= 4;
    sub_49dba8(app, cpu);
    if (cpu.terminate) return;
    // 004421e8  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004421e9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_4421f0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004421f0  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004421f1  b87f000000             -mov eax, 0x7f
    cpu.eax = 127 /*0x7f*/;
    // 004421f6  e8b5b80500             -call 0x49dab0
    cpu.esp -= 4;
    sub_49dab0(app, cpu);
    if (cpu.terminate) return;
    // 004421fb  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004421fd  e8fe750400             -call 0x489800
    cpu.esp -= 4;
    sub_489800(app, cpu);
    if (cpu.terminate) return;
    // 00442202  b864000000             -mov eax, 0x64
    cpu.eax = 100 /*0x64*/;
    // 00442207  8b15285a4d00           -mov edx, dword ptr [0x4d5a28]
    cpu.edx = app->getMemory<x86::reg32>(x86::reg32(5069352) /* 0x4d5a28 */);
    // 0044220d  e88e420400             -call 0x4864a0
    cpu.esp -= 4;
    sub_4864a0(app, cpu);
    if (cpu.terminate) return;
    // 00442212  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442213  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_442220(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442220  b87f000000             -mov eax, 0x7f
    cpu.eax = 127 /*0x7f*/;
    // 00442225  e886b80500             -call 0x49dab0
    cpu.esp -= 4;
    sub_49dab0(app, cpu);
    if (cpu.terminate) return;
    // 0044222a  803d185a4d0000         +cmp byte ptr [0x4d5a18], 0
    {
        x86::reg8 tmp1 = app->getMemory<x86::reg8>(x86::reg32(5069336) /* 0x4d5a18 */);
        x86::reg8 tmp2 = x86::reg8(x86::sreg8(0 /*0x0*/));
        x86::reg8 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 7);
        cpu.flags.of ^= 1 & (result >> 7);
        cpu.flags.of &= (1 & (tmp1 >> 7)) != (1 & (tmp2 >> 7));
        cpu.set_szp(result);
    }
    // 00442231  7501                   -jne 0x442234
    if (!cpu.flags.zf)
    {
        goto L_0x00442234;
    }
    // 00442233  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00442234:
    // 00442234  a12c5a4d00             -mov eax, dword ptr [0x4d5a2c]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5069356) /* 0x4d5a2c */);
    // 00442239  e9c2750400             -jmp 0x489800
    return sub_489800(app, cpu);
}

/* align: skip 0x00 0x00 */
void Application::sub_442240(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442240  31c0                   +xor eax, eax
    cpu.clear_co();
    cpu.set_szp((cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax))));
    // 00442242  e969b80500             -jmp 0x49dab0
    return sub_49dab0(app, cpu);
}

/* align: skip 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 */
void Application::sub_442250(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442250  833db0964d0000         +cmp dword ptr [0x4d96b0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5084848) /* 0x4d96b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00442257  740d                   -je 0x442266
    if (cpu.flags.zf)
    {
        goto L_0x00442266;
    }
    // 00442259  85d2                   +test edx, edx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.edx & cpu.edx));
    // 0044225b  7e0b                   -jle 0x442268
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x00442268;
    }
    // 0044225d  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00442260  81e8fe3f0000           -sub eax, 0x3ffe
    (cpu.eax) -= x86::reg32(x86::sreg32(16382 /*0x3ffe*/));
L_0x00442266:
    // 00442266  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 00442267  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x00442268:
    // 00442268  ba7f000000             -mov edx, 0x7f
    cpu.edx = 127 /*0x7f*/;
    // 0044226d  29c2                   -sub edx, eax
    (cpu.edx) -= x86::reg32(x86::sreg32(cpu.eax));
    // 0044226f  8d8280000000           -lea eax, [edx + 0x80]
    cpu.eax = x86::reg32(cpu.edx + x86::reg32(128) /* 0x80 */);
    // 00442275  c1e008                 -shl eax, 8
    cpu.eax <<= 8 /*0x8*/ % 32;
    // 00442278  81e8fe3f0000           -sub eax, 0x3ffe
    (cpu.eax) -= x86::reg32(x86::sreg32(16382 /*0x3ffe*/));
    // 0044227e  98                     -cwde 
    cpu.eax = x86::reg32(static_cast<x86::sreg16>(cpu.ax));
    // 0044227f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_442280(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 00442280  56                     -push esi
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.esi;
    cpu.esp -= 4;
    // 00442281  83ec14                 -sub esp, 0x14
    (cpu.esp) -= x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00442284  89442410               -mov dword ptr [esp + 0x10], eax
    app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */) = cpu.eax;
    // 00442288  89d6                   -mov esi, edx
    cpu.esi = cpu.edx;
    // 0044228a  89ca                   -mov edx, ecx
    cpu.edx = cpu.ecx;
    // 0044228c  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0044228e  e8ed300400             -call 0x485380
    cpu.esp -= 4;
    sub_485380(app, cpu);
    if (cpu.terminate) return;
    // 00442293  8a442410               -mov al, byte ptr [esp + 0x10]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 00442297  8b0d40b45000           -mov ecx, dword ptr [0x50b440]
    cpu.ecx = app->getMemory<x86::reg32>(x86::reg32(5289024) /* 0x50b440 */);
    // 0044229d  88442404               -mov byte ptr [esp + 4], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(4) /* 0x4 */) = cpu.al;
    // 004422a1  8b442410               -mov eax, dword ptr [esp + 0x10]
    cpu.eax = app->getMemory<x86::reg32>(cpu.esp + x86::reg32(16) /* 0x10 */);
    // 004422a5  893424                 -mov dword ptr [esp], esi
    app->getMemory<x86::reg32>(cpu.esp) = cpu.esi;
    // 004422a8  39c8                   +cmp eax, ecx
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
    // 004422aa  7408                   -je 0x4422b4
    if (cpu.flags.zf)
    {
        goto L_0x004422b4;
    }
    // 004422ac  3b0534b45000           +cmp eax, dword ptr [0x50b434]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5289012) /* 0x50b434 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004422b2  7551                   -jne 0x442305
    if (!cpu.flags.zf)
    {
        goto L_0x00442305;
    }
L_0x004422b4:
    // 004422b4  0faf15305a4d00         -imul edx, dword ptr [0x4d5a30]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5069360) /* 0x4d5a30 */))));
    // 004422bb  be7f000000             -mov esi, 0x7f
    cpu.esi = 127 /*0x7f*/;
    // 004422c0  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 004422c2  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 004422c5  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
L_0x004422c7:
    // 004422c7  88442408               -mov byte ptr [esp + 8], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(8) /* 0x8 */) = cpu.al;
    // 004422cb  8a44241c               -mov al, byte ptr [esp + 0x1c]
    cpu.al = app->getMemory<x86::reg8>(cpu.esp + x86::reg32(28) /* 0x1c */);
    // 004422cf  8b35b0964d00           -mov esi, dword ptr [0x4d96b0]
    cpu.esi = app->getMemory<x86::reg32>(x86::reg32(5084848) /* 0x4d96b0 */);
    // 004422d5  88442409               -mov byte ptr [esp + 9], al
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(9) /* 0x9 */) = cpu.al;
    // 004422d9  85f6                   +test esi, esi
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.esi & cpu.esi));
    // 004422db  745d                   -je 0x44233a
    if (cpu.flags.zf)
    {
        goto L_0x0044233a;
    }
    // 004422dd  b601                   -mov dh, 1
    cpu.dh = 1 /*0x1*/;
    // 004422df  a1445a4d00             -mov eax, dword ptr [0x4d5a44]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5069380) /* 0x4d5a44 */);
    // 004422e4  8874240b               -mov byte ptr [esp + 0xb], dh
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(11) /* 0xb */) = cpu.dh;
    // 004422e8  85c0                   +test eax, eax
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.eax & cpu.eax));
    // 004422ea  7445                   -je 0x442331
    if (cpu.flags.zf)
    {
        goto L_0x00442331;
    }
    // 004422ec  66895c240c             -mov word ptr [esp + 0xc], bx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.bx;
L_0x004422f1:
    // 004422f1  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 004422f3  e8c8300400             -call 0x4853c0
    cpu.esp -= 4;
    sub_4853c0(app, cpu);
    if (cpu.terminate) return;
    // 004422f8  ff05405a4d00           -inc dword ptr [0x4d5a40]
    (app->getMemory<x86::reg32>(x86::reg32(5069376) /* 0x4d5a40 */))++;
    // 004422fe  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00442301  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 00442302  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x00442305:
    // 00442305  3b0558b45000           +cmp eax, dword ptr [0x50b458]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5289048) /* 0x50b458 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 0044230b  74a7                   -je 0x4422b4
    if (cpu.flags.zf)
    {
        goto L_0x004422b4;
    }
    // 0044230d  3b0564b45000           +cmp eax, dword ptr [0x50b464]
    {
        x86::reg32 tmp1 = cpu.eax;
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5289060) /* 0x50b464 */)));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00442313  749f                   -je 0x4422b4
    if (cpu.flags.zf)
    {
        goto L_0x004422b4;
    }
    // 00442315  0faf15305a4d00         -imul edx, dword ptr [0x4d5a30]
    cpu.edx = x86::reg32(x86::sreg64(x86::sreg32(cpu.edx)) * x86::sreg64(x86::sreg32(app->getMemory<x86::reg32>(x86::reg32(5069360) /* 0x4d5a30 */))));
    // 0044231c  be7f000000             -mov esi, 0x7f
    cpu.esi = 127 /*0x7f*/;
    // 00442321  89d0                   -mov eax, edx
    cpu.eax = cpu.edx;
    // 00442323  c1fa1f                 -sar edx, 0x1f
    cpu.edx = x86::reg32(x86::sreg32(cpu.edx) >> (31 /*0x1f*/ % 32));
    // 00442326  f7fe                   -idiv esi
    {
        x86::sreg64 tmp = x86::sreg64(cpu.edx_eax);
        x86::sreg32 d = x86::sreg32(cpu.esi);
        cpu.edx_eax = x86::reg64(tmp / d);
        cpu.edx = x86::reg32(tmp % d);
    }
    // 00442328  a37cb45000             -mov dword ptr [0x50b47c], eax
    app->getMemory<x86::reg32>(x86::reg32(5289084) /* 0x50b47c */) = cpu.eax;
    // 0044232d  d1f8                   +sar eax, 1
    {
        x86::reg32 tmp = 1 /*0x1*/ % 32;
        x86::reg32& op = cpu.eax;
        if (tmp)
        {
            cpu.flags.cf = 1 & (x86::sreg32(op) >> (tmp - 1));
            if (tmp == 1) cpu.flags.of = 0;
            cpu.set_szp((op = x86::reg32(x86::sreg32(op) >> tmp)));
        }
    }
    // 0044232f  eb96                   -jmp 0x4422c7
    goto L_0x004422c7;
L_0x00442331:
    // 00442331  31d2                   +xor edx, edx
    cpu.clear_co();
    cpu.set_szp((cpu.edx ^= x86::reg32(x86::sreg32(cpu.edx))));
    // 00442333  668954240c             -mov word ptr [esp + 0xc], dx
    app->getMemory<x86::reg16>(cpu.esp + x86::reg32(12) /* 0xc */) = cpu.dx;
    // 00442338  ebb7                   -jmp 0x4422f1
    goto L_0x004422f1;
L_0x0044233a:
    // 0044233a  833d2c22510000         +cmp dword ptr [0x51222c], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5317164) /* 0x51222c */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00442341  7409                   -je 0x44234c
    if (cpu.flags.zf)
    {
        goto L_0x0044234c;
    }
    // 00442343  b87f000000             -mov eax, 0x7f
    cpu.eax = 127 /*0x7f*/;
    // 00442348  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 0044234a  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
L_0x0044234c:
    // 0044234c  30e4                   -xor ah, ah
    cpu.ah ^= x86::reg8(x86::sreg8(cpu.ah));
    // 0044234e  8864240b               -mov byte ptr [esp + 0xb], ah
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(11) /* 0xb */) = cpu.ah;
    // 00442352  83fb7f                 +cmp ebx, 0x7f
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
    // 00442355  7e26                   -jle 0x44237d
    if (cpu.flags.zf || (cpu.flags.sf != cpu.flags.of))
    {
        goto L_0x0044237d;
    }
    // 00442357  bb7f000000             -mov ebx, 0x7f
    cpu.ebx = 127 /*0x7f*/;
L_0x0044235c:
    // 0044235c  833d445a4d0000         +cmp dword ptr [0x4d5a44], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5069380) /* 0x4d5a44 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 00442363  7420                   -je 0x442385
    if (cpu.flags.zf)
    {
        goto L_0x00442385;
    }
    // 00442365  885c2407               -mov byte ptr [esp + 7], bl
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */) = cpu.bl;
    // 00442369  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0044236b  e850300400             -call 0x4853c0
    cpu.esp -= 4;
    sub_4853c0(app, cpu);
    if (cpu.terminate) return;
    // 00442370  ff05405a4d00           -inc dword ptr [0x4d5a40]
    (app->getMemory<x86::reg32>(x86::reg32(5069376) /* 0x4d5a40 */))++;
    // 00442376  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 00442379  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044237a  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
L_0x0044237d:
    // 0044237d  85db                   +test ebx, ebx
    cpu.clear_co();
    cpu.set_szp(static_cast<x86::reg32>(cpu.ebx & cpu.ebx));
    // 0044237f  7ddb                   -jge 0x44235c
    if (cpu.flags.sf == cpu.flags.of)
    {
        goto L_0x0044235c;
    }
    // 00442381  31db                   +xor ebx, ebx
    cpu.clear_co();
    cpu.set_szp((cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx))));
    // 00442383  ebd7                   -jmp 0x44235c
    goto L_0x0044235c;
L_0x00442385:
    // 00442385  c644240740             -mov byte ptr [esp + 7], 0x40
    app->getMemory<x86::reg8>(cpu.esp + x86::reg32(7) /* 0x7 */) = 64 /*0x40*/;
    // 0044238a  89e0                   -mov eax, esp
    cpu.eax = cpu.esp;
    // 0044238c  e82f300400             -call 0x4853c0
    cpu.esp -= 4;
    sub_4853c0(app, cpu);
    if (cpu.terminate) return;
    // 00442391  ff05405a4d00           -inc dword ptr [0x4d5a40]
    (app->getMemory<x86::reg32>(x86::reg32(5069376) /* 0x4d5a40 */))++;
    // 00442397  83c414                 -add esp, 0x14
    (cpu.esp) += x86::reg32(x86::sreg32(20 /*0x14*/));
    // 0044239a  5e                     -pop esi
    cpu.esi = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 0044239b  c20400                 -ret 4
    cpu.esp += 4+4 /*0x4*/;
    return;
}

/* align: skip 0x00 0x00 */
void Application::sub_4423a0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004423a0  53                     -push ebx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ebx;
    cpu.esp -= 4;
    // 004423a1  51                     -push ecx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.ecx;
    cpu.esp -= 4;
    // 004423a2  52                     -push edx
    app->getMemory<x86::reg32>(cpu.esp-4) = cpu.edx;
    cpu.esp -= 4;
    // 004423a3  833db0964d0000         +cmp dword ptr [0x4d96b0], 0
    {
        x86::reg32 tmp1 = app->getMemory<x86::reg32>(x86::reg32(5084848) /* 0x4d96b0 */);
        x86::reg32 tmp2 = x86::reg32(x86::sreg32(0 /*0x0*/));
        x86::reg32 result = tmp1 - tmp2;
        cpu.flags.cf = tmp1 < tmp2;
        cpu.flags.of = 1 & (tmp1 >> 31);
        cpu.flags.of ^= 1 & (result >> 31);
        cpu.flags.of &= (1 & (tmp1 >> 31)) != (1 & (tmp2 >> 31));
        cpu.set_szp(result);
    }
    // 004423aa  741c                   -je 0x4423c8
    if (cpu.flags.zf)
    {
        goto L_0x004423c8;
    }
    // 004423ac  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 004423ae  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 004423b3  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 004423b8  a128b45000             -mov eax, dword ptr [0x50b428]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5289000) /* 0x50b428 */);
    // 004423bd  31db                   -xor ebx, ebx
    cpu.ebx ^= x86::reg32(x86::sreg32(cpu.ebx));
    // 004423bf  e8bcfeffff             -call 0x442280
    cpu.esp -= 4;
    sub_442280(app, cpu);
    if (cpu.terminate) return;
    // 004423c4  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004423c5  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004423c6  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004423c7  c3                     -ret 
    cpu.esp += 4;
    return;
L_0x004423c8:
    // 004423c8  6a40                   -push 0x40
    app->getMemory<x86::reg32>(cpu.esp-4) = 64 /*0x40*/;
    cpu.esp -= 4;
    // 004423ca  b97f000000             -mov ecx, 0x7f
    cpu.ecx = 127 /*0x7f*/;
    // 004423cf  bb40000000             -mov ebx, 0x40
    cpu.ebx = 64 /*0x40*/;
    // 004423d4  ba05000000             -mov edx, 5
    cpu.edx = 5 /*0x5*/;
    // 004423d9  a128b45000             -mov eax, dword ptr [0x50b428]
    cpu.eax = app->getMemory<x86::reg32>(x86::reg32(5289000) /* 0x50b428 */);
    // 004423de  e89dfeffff             -call 0x442280
    cpu.esp -= 4;
    sub_442280(app, cpu);
    if (cpu.terminate) return;
    // 004423e3  5a                     -pop edx
    cpu.edx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004423e4  59                     -pop ecx
    cpu.ecx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004423e5  5b                     -pop ebx
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esp);
    cpu.esp += 4;
    // 004423e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
