#include "nfs2sea.h"
#include <lib/thread.h>

namespace nfs2sea
{

/* align: skip  */
void Application::sub_4b9384(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9384  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b9386  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b9388  81e3fcfcfcfc           -and ebx, 0xfcfcfcfc
    cpu.ebx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004b938e  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9391  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9396  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9398  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b939b  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b939e  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b93a4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b93a6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b93a7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b93a7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b93a9  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b93ab  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b93b1  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b93b4  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b93b9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b93bb  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b93be  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b93c1  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b93c7  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b93c9  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b93cc  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b93cf  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b93d5  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b93d7  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b93d8(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b93d8  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b93da  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b93df  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b93e2  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b93e5  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b93eb  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b93ed  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b93f0  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b93f3  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b93f9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b93fb  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b93fc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b93fc  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b93fe  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9403  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b9406  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9409  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b940f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9411  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9414  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9417  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b941d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b941f  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b9423  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9426  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b942c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b942e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b942f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b942f  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b9431  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b9434  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b943a  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b943d  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9442  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9444  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b9447  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b9449  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b944c  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b9452  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b9455  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b945b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b945d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b945f  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9462  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9465  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b946b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b946d  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b9471  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9474  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b947a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b947c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b947d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b947d  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b9480  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9485  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b9488  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b948a  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9490  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9492  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9495  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9498  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b949e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b94a0  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b94a4  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b94a7  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b94ad  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b94af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b94b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b94b0  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b94b3  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b94b8  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b94bb  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b94bd  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b94c3  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b94c5  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b94c9  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b94cc  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b94d2  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b94d4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b94d5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b94d5  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b94d8  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b94dd  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b94e0  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b94e2  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b94e4  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b94ea  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b94ed  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b94f3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b94f5  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b94f7  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b94fb  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b94fe  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9504  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9506  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9507(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9507  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b9509  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b950b  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b9511  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9514  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9519  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b951b  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b951e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b9520  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9523  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b9529  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b952c  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9532  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b9534  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9536  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9537(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9537  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b9539  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b953e  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b9541  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9544  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b954a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b954c  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b954f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b9551  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9554  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b955a  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b955d  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9563  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b9565  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9567  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9568(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9568  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b956a  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b956f  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b9572  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9575  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b957b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b957d  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9580  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9583  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9589  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b958b  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b958f  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9592  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9598  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b959a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b959b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b959b  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b959d  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b95a0  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b95a6  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b95a9  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b95ae  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b95b0  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b95b3  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b95b6  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b95bc  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b95be  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b95c1  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b95c4  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b95ca  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b95cc  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b95d0  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b95d3  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b95d9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b95db  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b95dc(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b95dc  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b95df  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b95e4  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b95e7  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b95ea  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b95f0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b95f2  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b95f5  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b95f8  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b95fe  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9600  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b9604  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9607  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b960d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b960f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9610(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9610  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b9613  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9618  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b961b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b961d  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9620  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b9626  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b9629  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b962f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b9631  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9633  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9636  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9639  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b963f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9641  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b9645  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9648  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b964e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9650  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9651(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9651  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b9654  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9659  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b965c  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b965e  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9664  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9666  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9669  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b966c  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9672  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9674  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b9678  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b967b  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9681  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9683  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9684(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9684  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b9687  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b968c  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b968f  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b9691  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9697  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9699  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b969d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b969f  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b96a2  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b96a8  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b96ab  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b96b1  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b96b3  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b96b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b96b6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b96b6  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b96b8  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b96bd  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b96c0  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b96c2  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b96c8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b96ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b96cb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b96cb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b96cd  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b96d0  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b96d6  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b96d9  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b96de  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b96e0  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b96e3  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b96e6  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b96ec  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b96ee  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b96f1  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b96f3  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b96f6  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b96fc  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b96ff  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9705  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b9707  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9709  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b970d  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9710  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9716  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9718  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9719(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9719  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b971c  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9721  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b9724  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b9726  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9729  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b972f  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b9732  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9738  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b973a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b973c  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b973f  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9742  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9748  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b974a  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b974e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b9750  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9753  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b9759  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b975c  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9762  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b9764  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9766  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9767(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9767  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b9769  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b976c  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b976e  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9774  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9776  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b977a  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b977c  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9782  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9784  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9785(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9785  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b9787  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b978a  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b9790  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9793  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9798  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b979a  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b979d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b979f  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b97a1  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b97a7  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b97aa  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b97b0  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b97b2  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b97b4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b97b5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b97b5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b97b7  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b97ba  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b97c0  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b97c3  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b97c8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b97ca  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b97cd  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b97cf  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b97d5  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b97d7  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b97db  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b97de  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b97e4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b97e6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b97e7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b97e7  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b97ea  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b97ef  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b97f2  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b97f5  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b97fb  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b97fd  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9800  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b9802  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9808  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b980a  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b980e  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9811  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9817  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9819  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b981a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b981a  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b981d  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9822  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b9825  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9828  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b982e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9830  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9833  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b9835  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9838  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b983e  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b9841  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9847  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b9849  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b984b  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b984f  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9852  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9858  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b985a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b985b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b985b  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b985e  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9863  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b9866  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9869  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b986f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9871  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9874  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9877  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b987d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b987f  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b9883  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b9885  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9888  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b988e  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b9891  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9897  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b9899  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b989b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b989c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b989c  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b989f  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b98a4  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b98a7  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b98aa  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b98b0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b98b2  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b98b5  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b98b8  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b98be  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b98c0  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b98c4  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b98c6  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b98cc  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b98ce  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b98cf(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b98cf  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b98d1  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b98d4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b98d6  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b98d9  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b98df  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b98e2  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b98e8  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b98ea  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b98ec  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b98ef  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b98f2  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b98f8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b98fa  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b98fe  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b9900  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9906  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9908  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9909(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9909  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b990c  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9911  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9914  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b9916  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b9918  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004b991e  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004b9921  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9927  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b9929  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b992b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b992c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b992c  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b992f  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9934  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9937  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b9939  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b993b  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b9941  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b9944  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b994a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b994c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b994e  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b9952  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9955  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b995b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b995d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b995e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b995e  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b9961  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9966  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9969  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b996b  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9971  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9973  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b9977  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b997a  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9980  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9982  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9983(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9983  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b9986  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b998b  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b998e  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9991  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9997  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9999  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b999c  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b999e  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b99a4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b99a6  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b99aa  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b99ad  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b99b3  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b99b5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b99b6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b99b6  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b99b9  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b99be  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b99c1  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b99c4  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b99ca  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b99cc  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b99cf  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b99d1  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b99d4  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b99da  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b99dd  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b99e3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b99e5  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b99e7  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b99eb  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b99ed  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b99f0  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b99f6  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b99f9  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b99ff  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b9a01  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9a03  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9a04(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9a04  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b9a07  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9a0c  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b9a0f  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9a12  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9a18  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9a1a  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9a1d  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9a20  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9a26  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9a28  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b9a2c  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b9a2e  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9a34  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9a36  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9a37(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9a37  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b9a39  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b9a3c  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9a3f  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9a45  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9a47  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9a4a  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9a4d  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9a53  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9a55  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b9a59  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b9a5b  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9a61  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9a63  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9a64(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9a64  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b9a66  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b9a69  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9a6c  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9a72  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9a74  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9a77  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9a7a  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9a80  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9a82  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b9a86  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b9a88  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b9a8a  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b9a90  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b9a93  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9a99  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b9a9b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9a9d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9a9e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9a9e  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b9aa1  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9aa6  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9aa9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b9aab  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b9aae  81e21f1f1f1f           -and edx, 0x1f1f1f1f
    cpu.edx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9ab4  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b9ab6  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9ab8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9ab9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9ab9  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b9abc  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9ac1  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9ac4  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b9ac6  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b9ac8  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004b9ace  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004b9ad1  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9ad7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b9ad9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9adb  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b9adf  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9ae2  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9ae8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9aea  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9aeb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9aeb  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b9aee  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9af3  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9af6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b9af8  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b9afa  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b9b00  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b9b03  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9b09  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b9b0b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9b0d  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b9b11  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9b14  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9b1a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9b1c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9b1d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9b1d  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b9b20  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9b25  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9b28  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b9b2a  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9b30  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9b32  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b9b36  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b9b38  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9b3b  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b9b41  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b9b44  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9b4a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b9b4c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9b4e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9b4f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9b4f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b9b51  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9b54  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b9b56  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9b5c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9b5e  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b9b62  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b9b64  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9b6a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9b6c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9b6d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9b6d  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b9b6f  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b9b72  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9b75  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9b7b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9b7d  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9b80  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b9b82  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9b85  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b9b8b  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b9b8e  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9b94  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b9b96  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9b98  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b9b9c  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b9b9e  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9ba4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9ba6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9ba7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9ba7  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b9ba9  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b9bac  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9baf  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9bb5  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9bb7  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9bba  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9bbd  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9bc3  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9bc5  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b9bc9  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b9bcb  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b9bcd  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b9bd3  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b9bd6  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9bdc  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b9bde  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9be0  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9be1(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9be1  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004b9be3  8b5e04                 -mov ebx, dword ptr [esi + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */);
    // 004b9be6  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9be9  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9bef  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9bf1  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9bf4  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9bf7  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9bfd  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9bff  8b5c0e04               -mov ebx, dword ptr [esi + ecx + 4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(4) /* 0x4 */ + cpu.ecx * 1);
    // 004b9c03  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b9c05  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b9c07  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004b9c0d  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004b9c10  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9c16  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b9c18  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9c1a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip 0x00 */
void Application::sub_4b9c1c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9c1c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9c1d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9c1d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b9c1f  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9c22  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9c28  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9c2a  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b9c2d  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9c33  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9c36  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9c39  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9c3f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9c41  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9c42(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9c42  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b9c44  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b9c46  81e3fcfcfcfc           -and ebx, 0xfcfcfcfc
    cpu.ebx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004b9c4c  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9c4f  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9c54  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9c56  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b9c59  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9c5f  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9c62  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9c65  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9c6b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9c6d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9c6e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9c6e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b9c70  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b9c72  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b9c78  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9c7b  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9c80  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9c82  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b9c85  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9c8b  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9c8e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b9c90  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9c93  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b9c99  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b9c9c  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9ca2  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b9ca4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9ca6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9ca7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9ca7  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b9ca9  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9cae  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b9cb1  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9cb7  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9cba  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b9cbc  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9cc2  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9cc4  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9cc5(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9cc5  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b9cc7  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b9cca  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b9cd0  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9cd3  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9cd8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9cda  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b9cdd  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9ce3  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9ce6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b9ce8  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b9cea  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b9cf0  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b9cf3  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9cf9  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b9cfb  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9cfd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9cfe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9cfe  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b9d01  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9d06  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b9d09  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9d0f  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9d12  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b9d14  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b9d16  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004b9d1c  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004b9d1f  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9d25  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b9d27  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9d29  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9d2a(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9d2a  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b9d2d  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9d32  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b9d35  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9d3b  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9d3e  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b9d40  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b9d43  81e21f1f1f1f           -and edx, 0x1f1f1f1f
    cpu.edx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9d49  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004b9d4b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9d4d  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9d4e(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9d4e  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b9d50  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9d53  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9d59  29d8                   -sub eax, ebx
    (cpu.eax) -= x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9d5b  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9d5e  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9d64  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9d67  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9d6a  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9d70  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9d72  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9d73(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9d73  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b9d75  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b9d77  81e3fcfcfcfc           -and ebx, 0xfcfcfcfc
    cpu.ebx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004b9d7d  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9d80  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9d85  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9d87  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b9d8a  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9d90  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9d93  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9d96  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9d9c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9d9e  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9da1  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9da7  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9daa  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9dad  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9db3  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9db5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9db6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9db6  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b9db8  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b9dba  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b9dc0  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9dc3  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9dc8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9dca  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b9dcd  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9dd3  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9dd6  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9dd9  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9ddf  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9de1  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9de4  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9dea  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9ded  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9df0  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9df6  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9df8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9df9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9df9  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b9dfb  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9e00  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b9e03  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9e09  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9e0c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b9e0e  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9e11  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b9e17  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b9e1a  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9e20  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b9e22  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9e24  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9e27  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9e2d  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9e30  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9e33  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9e39  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9e3b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9e3c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9e3c  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b9e3e  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b9e41  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b9e47  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9e4a  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9e4f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9e51  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b9e54  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9e5a  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9e5d  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b9e5f  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9e65  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9e67  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004b9e6b  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9e71  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9e74  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9e77  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9e7d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9e7f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9e80(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9e80  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004b9e83  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9e88  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b9e8b  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9e91  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9e94  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b9e96  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b9e98  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b9e9e  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004b9ea1  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9ea7  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b9ea9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9eab  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004b9eaf  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9eb5  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9eb8  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9ebb  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9ec1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9ec3  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9ec4(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9ec4  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004b9ec7  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9ecc  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b9ecf  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9ed5  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9ed8  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004b9eda  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004b9edc  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004b9ee2  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004b9ee5  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9eeb  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004b9eed  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9eef  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004b9ef3  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9ef9  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9efc  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9eff  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9f05  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9f07  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9f08(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9f08  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b9f0a  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b9f0c  81e3fcfcfcfc           -and ebx, 0xfcfcfcfc
    cpu.ebx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004b9f12  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9f15  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9f1a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9f1c  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9f1f  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9f25  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9f28  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9f2b  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9f31  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9f33  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9f34(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9f34  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b9f36  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b9f38  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004b9f3e  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9f41  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9f46  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9f48  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b9f4b  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9f51  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9f54  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9f57  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9f5d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9f5f  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9f62  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9f68  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9f6b  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9f6e  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9f74  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9f76  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9f77(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9f77  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b9f79  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9f7e  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b9f81  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9f87  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9f8a  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9f8d  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9f93  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9f95  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9f98  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9f9e  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9fa1  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9fa4  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9faa  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9fac  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9fad(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9fad  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004b9faf  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004b9fb4  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004b9fb7  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9fbd  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9fc0  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004b9fc3  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004b9fc9  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9fcb  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004b9fce  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9fd4  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9fd7  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9fda  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9fe0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9fe2  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004b9fe6  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004b9fec  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004b9fef  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004b9ff2  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004b9ff8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004b9ffa  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4b9ffb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004b9ffb  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004b9ffd  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ba000  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ba006  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba009  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba00e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba010  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ba013  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba019  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba01c  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ba01e  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba021  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ba027  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ba02a  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba030  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ba032  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba034  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba037  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba03d  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba040  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba043  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba049  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba04b  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba04f  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba055  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba058  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba05b  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba061  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba063  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba064(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba064  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ba067  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba06c  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ba06f  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba075  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba078  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ba07a  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba080  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba082  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba085  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba08b  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba08e  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba091  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba097  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba099  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba09d  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba0a3  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba0a6  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba0a9  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba0af  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba0b1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba0b2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba0b2  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ba0b5  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba0ba  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ba0bd  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba0c3  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba0c6  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ba0c8  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba0ce  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba0d0  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba0d4  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba0da  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba0dd  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba0e0  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba0e6  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba0e8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba0e9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba0e9  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ba0ec  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba0f1  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ba0f4  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba0fa  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba0fd  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ba0ff  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ba101  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ba107  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ba10a  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba110  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ba112  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba114  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba118  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba11e  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba121  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba124  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba12a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba12c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba12d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba12d  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ba12f  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004ba131  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ba137  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba13a  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba13f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba141  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba144  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba14a  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba14d  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ba14f  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba152  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ba158  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ba15b  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba161  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ba163  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba165  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba166(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba166  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004ba168  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba16d  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ba170  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba176  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba179  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba17c  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba182  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba184  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba187  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba18d  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba190  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ba192  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba195  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ba19b  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ba19e  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba1a4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ba1a6  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba1a8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba1a9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba1a9  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004ba1ab  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba1b0  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ba1b3  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba1b9  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba1bc  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba1bf  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba1c5  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba1c7  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba1ca  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba1d0  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba1d3  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba1d6  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba1dc  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba1de  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba1e2  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba1e8  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba1eb  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba1ee  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba1f4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba1f6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba1f7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba1f7  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ba1f9  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ba1fc  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ba202  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba205  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba20a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba20c  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ba20f  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba215  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba218  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba21b  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba221  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba223  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba226  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba22c  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba22f  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba232  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba238  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba23a  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba23e  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba244  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba247  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba24a  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba250  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba252  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba253(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba253  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ba256  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba25b  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ba25e  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba264  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba267  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba26a  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba270  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba272  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba275  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba27b  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba27e  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba281  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba287  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba289  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba28d  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba293  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba296  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba299  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba29f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba2a1  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba2a2(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba2a2  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ba2a5  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba2aa  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ba2ad  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba2b3  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba2b6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ba2b8  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba2bb  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ba2c1  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ba2c4  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba2ca  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ba2cc  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba2ce  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba2d1  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba2d7  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba2da  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba2dd  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba2e3  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba2e5  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba2e9  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba2ef  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba2f2  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba2f5  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba2fb  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba2fd  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba2fe(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba2fe  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ba301  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba306  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ba309  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba30f  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba312  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ba314  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba31a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba31c  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba31f  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba325  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba328  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba32b  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba331  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba333  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba337  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba33d  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba340  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba343  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba349  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba34b  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba34c(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba34c  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ba34f  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba354  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ba357  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba35d  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba360  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ba362  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba368  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba36a  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba36e  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba374  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba377  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ba379  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba37c  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ba382  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ba385  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba38b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ba38d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba38f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba390(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba390  d1e8                   -shr eax, 1
    cpu.eax >>= 1 /*0x1*/ % 32;
    // 004ba392  257f7f7f7f             -and eax, 0x7f7f7f7f
    cpu.eax &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba397  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba39a  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba3a0  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba3a3  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ba3a5  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba3ab  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba3ad  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba3ae(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba3ae  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ba3b0  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ba3b3  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ba3b9  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba3bc  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba3c1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba3c3  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ba3c6  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba3cc  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba3cf  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba3d2  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba3d8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba3da  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba3dd  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba3e3  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba3e6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ba3e8  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba3eb  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ba3f1  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ba3f4  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba3fa  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ba3fc  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba3fe  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba402  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba408  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba40b  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba40e  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba414  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba416  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba417(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba417  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ba41a  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba41f  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ba422  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba428  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba42b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ba42d  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba430  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ba436  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ba439  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba43f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ba441  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba443  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba446  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba44c  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba44f  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba452  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba458  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba45a  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba45e  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba464  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba467  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ba469  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba46c  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ba472  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ba475  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba47b  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ba47d  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba47f  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba480(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba480  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ba482  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ba485  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba48b  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba48e  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ba490  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba496  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba498  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba49c  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba4a2  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba4a5  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ba4a7  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba4ad  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba4af  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba4b0(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba4b0  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ba4b2  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ba4b5  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ba4bb  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba4be  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba4c3  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba4c5  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba4c8  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba4ce  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba4d1  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ba4d3  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ba4d5  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ba4db  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ba4de  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba4e4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ba4e6  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba4e8  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba4e9(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba4e9  89c3                   -mov ebx, eax
    cpu.ebx = cpu.eax;
    // 004ba4eb  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ba4ee  81e3f8f8f8f8           -and ebx, 0xf8f8f8f8
    cpu.ebx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ba4f4  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba4f7  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba4fc  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba4fe  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba501  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba507  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba50a  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ba50c  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba512  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba514  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba518  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba51e  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba521  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba524  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba52a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba52c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba52d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba52d  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ba530  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba535  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ba538  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba53e  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba541  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba544  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba54a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba54c  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba54f  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba555  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba558  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ba55a  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba560  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba562  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba566  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba56c  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba56f  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba572  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba578  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba57a  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba57b(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba57b  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ba57e  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba583  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ba586  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba58c  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba58f  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba592  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba598  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba59a  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba59d  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba5a3  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba5a6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ba5a8  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba5ab  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ba5b1  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ba5b4  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba5ba  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ba5bc  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba5be  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba5c2  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba5c8  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba5cb  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba5ce  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba5d4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba5d6  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba5d7(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba5d7  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ba5da  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba5df  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ba5e2  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba5e8  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba5eb  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba5ee  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba5f4  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba5f6  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba5f9  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba5ff  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba602  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba605  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba60b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba60d  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba611  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba617  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba61a  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ba61c  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba61f  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ba625  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ba628  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba62e  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ba630  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba632  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba633(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba633  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ba636  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba63b  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ba63e  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba644  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba647  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba64a  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba650  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba652  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba655  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba65b  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba65e  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba661  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba667  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba669  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba66d  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba673  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba676  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ba678  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba67e  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba680  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba681(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba681  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ba683  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ba686  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba68c  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba68f  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ba691  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba694  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ba69a  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ba69d  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba6a3  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ba6a5  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba6a7  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba6aa  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba6b0  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba6b3  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba6b6  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba6bc  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba6be  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba6c2  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba6c8  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba6cb  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ba6cd  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba6d3  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba6d5  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba6d6(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba6d6  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ba6d9  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba6de  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba6e1  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba6e7  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba6ea  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ba6ec  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ba6ee  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004ba6f4  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004ba6f7  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba6fd  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ba6ff  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba701  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba702(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba702  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ba705  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba70a  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba70d  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba713  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba716  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ba718  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ba71a  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ba720  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ba723  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba729  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ba72b  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba72d  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba731  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba737  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba73a  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba73d  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba743  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba745  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba746(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba746  c1e802                 -shr eax, 2
    cpu.eax >>= 2 /*0x2*/ % 32;
    // 004ba749  253f3f3f3f             -and eax, 0x3f3f3f3f
    cpu.eax &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba74e  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba751  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba757  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba75a  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ba75c  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba762  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba764  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba768  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba76e  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba771  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba774  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba77a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba77c  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba77d(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba77d  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ba780  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba785  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ba788  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba78e  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba791  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba794  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba79a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba79c  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba79f  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba7a5  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba7a8  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ba7aa  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba7b0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba7b2  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba7b6  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba7bc  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba7bf  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba7c2  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba7c8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba7ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba7cb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba7cb  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ba7ce  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba7d3  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ba7d6  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba7dc  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba7df  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba7e2  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba7e8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba7ea  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba7ed  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba7f3  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba7f6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ba7f8  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba7fb  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ba801  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ba804  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba80a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ba80c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba80e  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba812  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba818  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba81b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ba81d  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba820  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ba826  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ba829  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba82f  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ba831  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba833  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba834(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba834  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ba837  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba83c  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ba83f  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba845  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba848  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba84b  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba851  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba853  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba856  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba85c  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba85f  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba862  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba868  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba86a  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba86e  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba874  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba877  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ba879  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba87f  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba881  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba882(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba882  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ba884  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ba887  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba88d  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba890  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba893  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba899  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba89b  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba89e  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba8a4  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba8a7  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba8aa  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba8b0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba8b2  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba8b6  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba8bc  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba8bf  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ba8c1  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba8c7  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba8c9  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba8ca(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba8ca  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004ba8cc  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004ba8cf  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba8d5  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba8d8  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba8db  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba8e1  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba8e3  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba8e6  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba8ec  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba8ef  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba8f2  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba8f8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba8fa  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba8fe  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba904  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba907  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ba909  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ba90b  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ba911  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ba914  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba91a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ba91c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba91e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba91f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba91f  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ba922  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba927  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba92a  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba930  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba933  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ba935  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ba938  81e21f1f1f1f           -and edx, 0x1f1f1f1f
    cpu.edx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba93e  29d3                   -sub ebx, edx
    (cpu.ebx) -= x86::reg32(x86::sreg32(cpu.edx));
    // 004ba940  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba942  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba943(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba943  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ba946  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba94b  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba94e  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba954  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba957  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ba959  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ba95b  81e2fcfcfcfc           -and edx, 0xfcfcfcfc
    cpu.edx &= x86::reg32(x86::sreg32(4244438268 /*0xfcfcfcfc*/));
    // 004ba961  c1ea02                 -shr edx, 2
    cpu.edx >>= 2 /*0x2*/ % 32;
    // 004ba964  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba96a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ba96c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba96e  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba972  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba978  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba97b  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004ba97e  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba984  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba986  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba987(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba987  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ba98a  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba98f  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba992  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba998  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba99b  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ba99d  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ba99f  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004ba9a5  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004ba9a8  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba9ae  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004ba9b0  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba9b2  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba9b6  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba9bc  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba9bf  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba9c2  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004ba9c8  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba9ca  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4ba9cb(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004ba9cb  c1e803                 -shr eax, 3
    cpu.eax >>= 3 /*0x3*/ % 32;
    // 004ba9ce  251f1f1f1f             -and eax, 0x1f1f1f1f
    cpu.eax &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004ba9d3  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004ba9d6  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba9dc  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba9df  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004ba9e1  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004ba9e7  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004ba9e9  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004ba9ed  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004ba9f3  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004ba9f6  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004ba9f8  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004ba9fb  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004baa01  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004baa04  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004baa0a  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004baa0c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004baa0e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4baa0f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004baa0f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004baa11  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004baa14  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004baa1a  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004baa1d  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004baa1f  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004baa25  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004baa27  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004baa2b  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004baa31  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004baa34  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004baa36  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004baa3c  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004baa3e  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4baa3f(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004baa3f  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004baa41  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004baa44  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004baa4a  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004baa4d  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004baa50  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004baa56  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004baa58  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004baa5b  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004baa61  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004baa64  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004baa66  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004baa69  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004baa6f  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004baa72  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004baa78  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004baa7a  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004baa7c  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004baa80  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004baa86  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004baa89  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004baa8b  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004baa91  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004baa93  c3                     -ret 
    cpu.esp += 4;
    return;
}

/* align: skip  */
void Application::sub_4baa94(WinApplication* app, x86::CPU& cpu)
{
  NFS2_USE(cpu);
  NFS2_USE(app);
    // 004baa94  31c0                   -xor eax, eax
    cpu.eax ^= x86::reg32(x86::sreg32(cpu.eax));
    // 004baa96  8b5e01                 -mov ebx, dword ptr [esi + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */);
    // 004baa99  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004baa9f  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004baaa2  c1eb03                 -shr ebx, 3
    cpu.ebx >>= 3 /*0x3*/ % 32;
    // 004baaa5  81e31f1f1f1f           -and ebx, 0x1f1f1f1f
    cpu.ebx &= x86::reg32(x86::sreg32(522133279 /*0x1f1f1f1f*/));
    // 004baaab  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004baaad  8b1c0e                 -mov ebx, dword ptr [esi + ecx]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + cpu.ecx * 1);
    // 004baab0  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004baab6  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004baab9  c1eb02                 -shr ebx, 2
    cpu.ebx >>= 2 /*0x2*/ % 32;
    // 004baabc  81e33f3f3f3f           -and ebx, 0x3f3f3f3f
    cpu.ebx &= x86::reg32(x86::sreg32(1061109567 /*0x3f3f3f3f*/));
    // 004baac2  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004baac4  8b5c0e01               -mov ebx, dword ptr [esi + ecx + 1]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.esi + x86::reg32(1) /* 0x1 */ + cpu.ecx * 1);
    // 004baac8  81e3ff000000           -and ebx, 0xff
    cpu.ebx &= x86::reg32(x86::sreg32(255 /*0xff*/));
    // 004baace  8b1c9f                 -mov ebx, dword ptr [edi + ebx*4]
    cpu.ebx = app->getMemory<x86::reg32>(cpu.edi + cpu.ebx * 4);
    // 004baad1  89da                   -mov edx, ebx
    cpu.edx = cpu.ebx;
    // 004baad3  d1eb                   -shr ebx, 1
    cpu.ebx >>= 1 /*0x1*/ % 32;
    // 004baad5  81e2f8f8f8f8           -and edx, 0xf8f8f8f8
    cpu.edx &= x86::reg32(x86::sreg32(4177066232 /*0xf8f8f8f8*/));
    // 004baadb  c1ea03                 -shr edx, 3
    cpu.edx >>= 3 /*0x3*/ % 32;
    // 004baade  81e37f7f7f7f           -and ebx, 0x7f7f7f7f
    cpu.ebx &= x86::reg32(x86::sreg32(2139062143 /*0x7f7f7f7f*/));
    // 004baae4  01d0                   -add eax, edx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.edx));
    // 004baae6  01d8                   -add eax, ebx
    (cpu.eax) += x86::reg32(x86::sreg32(cpu.ebx));
    // 004baae8  c3                     -ret 
    cpu.esp += 4;
    return;
}

}
