#ifndef lucy_core_unsafe_unsafe
#define lucy_core_unsafe_unsafe
#define lucy_unreliable(...) (::Unsafe __VA_OPT__(,) __VA_ARGS__)
#define lucy_unsafe(...) (::Unsafe{} __VA_OPT__(,) __VA_ARGS__)
#endif