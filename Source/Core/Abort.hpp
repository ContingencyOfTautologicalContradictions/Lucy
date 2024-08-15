#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_abort
#define lucy_core_abort
#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace Lucy
{
    [[noreturn]] inline auto Abort() noexcept -> void
    {
        #ifdef _MSC_VER
        __fastfail(0);
        #else
        __builtin_trap();
        #endif
    }
}

#endif
#endif