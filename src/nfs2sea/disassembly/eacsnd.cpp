#include "eacsnd.h"
#include <x86.h>
#include <winapi/wrapper.h>

namespace eacsnd
{

win32::Library s_library = win32::Library("eacsnd.dll");
win32::Library* s_registry = &(s_library
        .registerSymbol("iSNDdirectcaps_", &sub_5bba3c)
        .registerSymbol("iSNDdirectserve_", &sub_5bc8d4)
        .registerSymbol("iSNDdirectsetfunctions_", &sub_5bba14)
        .registerSymbol("iSNDdirectstart_", &sub_5bc5dc)
        .registerSymbol("iSNDdirectstop_", &sub_5bc624)
        .registerSymbol("iSNDdllversion_", &sub_5bba00)

    );
}
