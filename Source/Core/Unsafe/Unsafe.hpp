#ifndef lucy_core_unsafe_unsafe
#define lucy_core_unsafe_unsafe
#define unreliable(...) (::Unsafe __VA_OPT__(,) __VA_ARGS__)
#define unsafe(...) (::Unsafe{} __VA_OPT__(,) __VA_ARGS__)
#endif