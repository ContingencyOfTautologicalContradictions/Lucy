#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_move
#define lucy_core_move
#include "../Meta/RemoveReferences.hpp"
#define lucy_move(value) static_cast<::Lucy::Meta::RemoveReferences<decltype(value)>&&>(value)
#endif
#endif