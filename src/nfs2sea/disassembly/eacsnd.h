#ifndef EACSND_H_
#define EACSND_H_
#include <x86.h>
#include <lib/winapp.h>
#include <lib/library.h>

namespace eacsnd
{

extern const x86::reg8 s_AUTOSegment[];
extern const x86::reg8 s__idataSegment[];
extern const x86::reg8 s_DGROUPSegment[];
extern const x86::reg8 s__edataSegment[];
void sub_5bba00(win32::WinApplication* app, x86::CPU& cpu);
void sub_5bba14(win32::WinApplication* app, x86::CPU& cpu);
void sub_5bba3c(win32::WinApplication* app, x86::CPU& cpu);
void sub_5bbf6c(win32::WinApplication* app, x86::CPU& cpu);
void sub_5bc5dc(win32::WinApplication* app, x86::CPU& cpu);
void sub_5bc624(win32::WinApplication* app, x86::CPU& cpu);
void sub_5bc6d0(win32::WinApplication* app, x86::CPU& cpu);
void sub_5bc794(win32::WinApplication* app, x86::CPU& cpu);
void sub_5bc8d4(win32::WinApplication* app, x86::CPU& cpu);
void sub_5bcb77(win32::WinApplication* app, x86::CPU& cpu);
void sub_5bcb90(win32::WinApplication* app, x86::CPU& cpu);
void sub_5bcbc2(win32::WinApplication* app, x86::CPU& cpu);
void sub_5bcbc7(win32::WinApplication* app, x86::CPU& cpu);
void sub_5bcc34(win32::WinApplication* app, x86::CPU& cpu);
void sub_5bcc40(win32::WinApplication* app, x86::CPU& cpu);

extern win32::Library* s_registry;

}

#endif /* !EACSND_H_ */
