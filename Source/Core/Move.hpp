#ifndef lucy_core_move
#define lucy_core_move
#include "../Meta/RemoveReferences.hpp"

namespace Lucy
{
    template<class T> [[nodiscard]] inline constexpr auto Move(T&& moved_from) noexcept -> Meta::RemoveReferences<T>&&
    {
        return static_cast<Meta::RemoveReferences<T>&&>(moved_from);
    }
}

#endif