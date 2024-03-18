#ifndef lucy_core_abort
#define lucy_core_abort
#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1

namespace Lucy
{
    /**
    Terminates the running program abnormally.
    
    The destructors of any created instance that remains within its lifetime are not invoked.
    */
    [[noreturn]] auto Abort() noexcept -> void;
}

#endif
#endif