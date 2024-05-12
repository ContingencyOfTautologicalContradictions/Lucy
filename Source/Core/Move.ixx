export module Lucy.Core.Move;
import Lucy.Meta.RemoveReferences;

export template<class Type> [[nodiscard]] constexpr auto Move(Type&& value) noexcept -> RemoveReferences<Type>&&
{
    return static_cast<RemoveReferences<Type>&&>(value);
}