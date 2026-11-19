#include "eacsnd.h"
#include <x86.h>
#include <winapi/wrapper.h>

namespace eacsnd
{

win32::Library s_library = win32::Library("eacsnd.dll");
win32::Library* s_registry = &(s_library
        .registerSymbol("iSNDdirectcaps_", &sub_54aa3c)
        .registerSymbol("iSNDdirectserve_", &sub_54b8d4)
        .registerSymbol("iSNDdirectsetfunctions_", &sub_54aa14)
        .registerSymbol("iSNDdirectstart_", &sub_54b5dc)
        .registerSymbol("iSNDdirectstop_", &sub_54b624)
        .registerSymbol("iSNDdllversion_", &sub_54aa00)

    );
}
