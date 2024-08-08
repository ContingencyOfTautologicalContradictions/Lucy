#ifndef lucy_core_encoding
#define lucy_core_encoding

namespace Lucy
{
    enum class [[nodiscard]] Encoding : unsigned char
    {
        UTF8,
        UTF16,
        UTF32
    };
}

#endif