#ifndef lucy_
#define lucy_
#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1

namespace Lucy
{
    enum class [[nodiscard]] Comparison : unsigned char
    {
        Less = 0u,
        Equal = 1u,
        Great = 2u
    };
}

#endif
#endif