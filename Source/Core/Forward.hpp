#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_forward
#define lucy_core_forward
#define lucy_forward(value) static_cast<decltype(value)&&>(value)
#endif
#endif