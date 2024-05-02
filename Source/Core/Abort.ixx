module;
#ifdef _MSC_VER
#include <intrin.h>
#endif
export module Lucy.Core.Abort;

export [[noreturn]] auto Abort() noexcept -> void
{
    #ifdef _MSC_VER
    __fastfail(false);
    #else
    __builtin_trap();
    #endif
}