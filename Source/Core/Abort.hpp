#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_abort
#define lucy_core_abort

namespace Lucy
{
    [[noreturn]] auto Abort() noexcept -> void;
}

#endif
#endif