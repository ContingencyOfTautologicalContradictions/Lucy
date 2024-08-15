#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_comparison
#define lucy_core_comparison

namespace Lucy
{
    enum class [[nodiscard]] Comparison : unsigned char
    {
        Lesser,
        Greater,
        Equal
    };
}

#endif
#endif