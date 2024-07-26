#ifndef lucy_core_address
#define lucy_core_address

namespace Lucy
{
    template<class T> [[nodiscard]] inline constexpr auto Address(const T& object) noexcept -> T*
    {
        return __builtin_addressof(object);
    }
}

#endif