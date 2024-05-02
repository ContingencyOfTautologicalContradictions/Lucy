/**export module Lucy.Result.Result;
import Lucy.Meta.Same;
import Lucy.Core.Forward;
import Lucy.Meta.TriviallyDestructible;

namespace Detail
{
    template<unsigned long long int, class, class...> class ResultIndex{};

    template<unsigned long long int index, class Type, class ActualType, class... Types> class ResultIndex<index, Type, ActualType, Types...>
    {
    public:
        static consteval unsigned long long int Value()
        {
            return Same<Type, ActualType> ? index : ResultIndex<index + 1, Type, Types...>::Value();
        }
    };

    template<class Type, class... Types> inline constexpr unsigned long long int ResultIndex = ResultIndex<0, Type, Types...>::Value();

    template<class...> class Result{};

    template<class ActualType, class... Rest> class Result<ActualType, Rest...>
    {
    public:
        union
        {
            ActualType actual;

            Result<Rest...> rest;
        };

        template<class Type, unsigned long long int index> constexpr Result(Type&& instance) noexcept : rest<index - 1>(Forward<Type>(instance)){}

        template<class Type> constexpr Result<Type, 0>(Type&& instance) noexcept : actual(Forward<Type>(instance)){}

        constexpr ~Result() noexcept requires TriviallyDestructible<ActualType> = default;

        constexpr ~Result() noexcept
        {
            actual.~ActualType();
        }
    };
}

export template<class Ok, class Err> class [[nodiscard]] Result
{
    bool error = false;

    Detail::Result<Ok, Err> result;
public:
    constexpr Result(const Ok&) requires CopyConstructible<Ok>
};*/