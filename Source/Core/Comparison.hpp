#ifndef lucy_core_comparison
#define lucy_core_comparison

namespace Lucy
{
    enum class [[nodiscard]] Comparison : unsigned char
    {
        Lesser,
        Equal,
        Greater
    };
}

#endif