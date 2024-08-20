#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_encoding
#define lucy_core_encoding
#include "u8.hpp"

namespace Lucy
{
    enum class [[nodiscard]] Encoding : u8::Native
    {
        UTF8,
        UTF16,
        UTF32
    };
}

#endif
#endif