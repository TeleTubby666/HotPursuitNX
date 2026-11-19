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
void sub_54aa00(win32::WinApplication* app, x86::CPU& cpu);
void sub_54aa14(win32::WinApplication* app, x86::CPU& cpu);
void sub_54aa3c(win32::WinApplication* app, x86::CPU& cpu);
void sub_54af6c(win32::WinApplication* app, x86::CPU& cpu);
void sub_54b5dc(win32::WinApplication* app, x86::CPU& cpu);
void sub_54b624(win32::WinApplication* app, x86::CPU& cpu);
void sub_54b6d0(win32::WinApplication* app, x86::CPU& cpu);
void sub_54b794(win32::WinApplication* app, x86::CPU& cpu);
void sub_54b8d4(win32::WinApplication* app, x86::CPU& cpu);
void sub_54bb77(win32::WinApplication* app, x86::CPU& cpu);
void sub_54bb90(win32::WinApplication* app, x86::CPU& cpu);
void sub_54bbc2(win32::WinApplication* app, x86::CPU& cpu);
void sub_54bbc7(win32::WinApplication* app, x86::CPU& cpu);
void sub_54bc34(win32::WinApplication* app, x86::CPU& cpu);
void sub_54bc40(win32::WinApplication* app, x86::CPU& cpu);

extern win32::Library* s_registry;

}

#endif /* !EACSND_H_ */
