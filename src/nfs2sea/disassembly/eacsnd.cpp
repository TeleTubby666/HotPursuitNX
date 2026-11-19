#include "eacsnd.h"
#include <x86.h>
#include <winapi/wrapper.h>

namespace eacsnd
{

win32::Library s_library = win32::Library("eacsnd.dll");
win32::Library* s_registry = &(s_library
        .registerSymbol("iSNDdirectcaps_", &sub_5b963c)
        .registerSymbol("iSNDdirectserve_", &sub_5ba4d4)
        .registerSymbol("iSNDdirectsetfunctions_", &sub_5b9614)
        .registerSymbol("iSNDdirectstart_", &sub_5ba1dc)
        .registerSymbol("iSNDdirectstop_", &sub_5ba224)
        .registerSymbol("iSNDdllversion_", &sub_5b9600)

    );
}
