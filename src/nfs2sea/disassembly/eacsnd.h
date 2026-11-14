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
void sub_5b9600(win32::WinApplication* app, x86::CPU& cpu);
void sub_5b9614(win32::WinApplication* app, x86::CPU& cpu);
void sub_5b963c(win32::WinApplication* app, x86::CPU& cpu);
void sub_5b9b6c(win32::WinApplication* app, x86::CPU& cpu);
void sub_5ba1dc(win32::WinApplication* app, x86::CPU& cpu);
void sub_5ba224(win32::WinApplication* app, x86::CPU& cpu);
void sub_5ba2d0(win32::WinApplication* app, x86::CPU& cpu);
void sub_5ba394(win32::WinApplication* app, x86::CPU& cpu);
void sub_5ba4d4(win32::WinApplication* app, x86::CPU& cpu);
void sub_5ba777(win32::WinApplication* app, x86::CPU& cpu);
void sub_5ba790(win32::WinApplication* app, x86::CPU& cpu);
void sub_5ba7c2(win32::WinApplication* app, x86::CPU& cpu);
void sub_5ba7c7(win32::WinApplication* app, x86::CPU& cpu);
void sub_5ba834(win32::WinApplication* app, x86::CPU& cpu);
void sub_5ba840(win32::WinApplication* app, x86::CPU& cpu);

extern win32::Library* s_registry;

}

#endif /* !EACSND_H_ */
