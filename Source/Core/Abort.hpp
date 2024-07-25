#ifndef lucy_core_abort
#define lucy_core_abort

namespace Lucy
{
    [[noreturn]] auto Abort() noexcept -> void;
}

#endif