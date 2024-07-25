#ifndef lucy_core_forward
#define lucy_core_forward
#include "../Meta/RemoveReferences.hpp"

namespace Lucy
{
    template<class T> [[nodiscard]] inline constexpr auto Forward(Meta::RemoveReferences<T>& value) noexcept -> T&&
    {
        return static_cast<T&&>(value);
    }

    template<class T> [[nodiscard]] inline constexpr auto Forward(Meta::RemoveReferences<T>&& value) noexcept -> T&&
    {
        return static_cast<T&&>(value);
    }
}

#endif