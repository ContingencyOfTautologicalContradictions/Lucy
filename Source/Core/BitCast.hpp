#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_bit_cast
#define lucy_core_bit_cast
#include "../Meta/TriviallyCopyable.hpp"

namespace Lucy
{
    template<Meta::TriviallyCopyable T> [[nodiscard]] inline constexpr auto BitCast(const Meta::TriviallyCopyable auto& from) noexcept -> T requires(sizeof(decltype(from)) == sizeof(T))
    {
        return __builtin_bit_cast(T, from);
    }
}

#endif
#endif