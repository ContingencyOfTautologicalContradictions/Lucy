#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#include "Abort.hpp"
#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace Lucy
{
    [[noreturn]] auto Abort() noexcept -> void
    {
        #ifdef _MSC_VER
        __fastfail(0);
        #else
        __builtin_trap();
        #endif
    }
}

#endif