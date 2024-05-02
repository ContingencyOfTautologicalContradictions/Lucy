export module Lucy.Core.Forward;
import Lucy.Meta.RemoveReferences;

export template<class T> [[nodiscard]] constexpr auto Forward(RemoveReferences<T>& value) noexcept -> T&&
{
    return static_cast<T&&>(value);
}

export template<class T> [[nodiscard]] constexpr auto Forward(RemoveReferences<T>&& value) noexcept -> T&&
{
    return static_cast<T&&>(value);
}