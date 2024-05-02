export module Lucy.Core.Move;
import Lucy.Meta.RemoveRvalueReference;

export template<class Type> [[nodiscard]] constexpr auto Move(Type&& value) noexcept -> RemoveRvalueReference<Type>&&
{
    return static_cast<RemoveRvalueReference<Type>&&>(value);
}