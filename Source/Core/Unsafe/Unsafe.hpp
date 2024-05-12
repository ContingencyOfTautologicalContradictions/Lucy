#ifndef lucy_core_unsafe_unsafe
#define lucy_core_unsafe_unsafe
#define lucy_unreliable(...) (::Unsafe __VA_OPT__(,) __VA_ARGS__)
#define lucy_unsafe(...) (::Unsafe{} __VA_OPT__(,) __VA_ARGS__)
#define lucy_operator_unreliable(type) (::PackedUnsafe<type>&& unsafe_object_private_and_secret)
#define lucy_operator_unsafe(type, instance) ::PackedUnsafe<type>(instance)
#define lucy_unsafe_parameter unsafe_object_private_and_secret
#endif