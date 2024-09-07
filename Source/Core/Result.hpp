#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_result
#define lucy_core_result
#include "Abort.hpp"
#include "Forward.hpp"
#include "../Meta/Constructible.hpp"
#include "../Meta/TriviallyCopyable.hpp"

namespace Lucy
{
    namespace Detail
    {
        template<class...> class [[nodiscard]] ResultH{};

        template<bool> class [[nodiscard]] ResultCopy final{};

        template<class T, class... U>  class [[nodiscard]] ResultH<T, U...>
        {
        public:
            union
            {
                T m_actual;

                ResultH<U...> m_tail;
            };

            constexpr ~ResultH() noexcept
            {
                m_actual.~T();
            }

            constexpr ~ResultH() noexcept requires(Meta::TriviallyCopyable<T>){}

            template<class... Args> constexpr ResultH(ResultCopy<true>, Args&&... args) noexcept : m_tail(ResultH<U...>(ResultCopy<false>{}, lucy_forward(args)...)){}

            template<class... Args> constexpr ResultH(ResultCopy<false>, Args&&... args) noexcept : m_actual(lucy_forward(args)...){}
        };

        template<bool, class, class T> class ResultConditional
        {
        public:
            using Type = T;
        };

        template<class T, class U> class ResultConditional<true, T, U>
        {
        public:
            using Type = T;
        };

        template<bool index, class T, class U> constexpr auto Value(ResultH<T, U>& result) noexcept -> ResultConditional<not index, T, U>::Type&
        {
            if constexpr(not index)
                return result.m_actual;
            else
                return result.m_tail.m_actual;
        }
    }

    class [[nodiscard]] ConstructT final{};

    class [[nodiscard]] ConstructError final{};

    template<class T, class ErrorT> class [[nodiscard]] Result
    {
        bool m_error;

        Detail::ResultH<T, ErrorT> m_variant;
    public:
        constexpr ~Result() noexcept = default;

        constexpr Result() noexcept : m_error(false), m_variant(Detail::ResultCopy<false>{}){}

        template<class... Arguments> requires(Meta::Constructible<T, Arguments...>) constexpr Result(Arguments&&... arguments) noexcept : m_error(false), m_variant(Detail::ResultCopy<false>{}, lucy_forward(arguments)...){}

        template<class... Arguments> requires(Meta::Constructible<ErrorT, Arguments...>) constexpr Result(Arguments&&... arguments) noexcept : m_error(true), m_variant(Detail::ResultCopy<true>{}, lucy_forward(arguments)...){}

        template<class... Arguments> requires(Meta::Constructible<T, Arguments...>) constexpr Result(ConstructT, Arguments&&... arguments) noexcept : m_error(false), m_variant(Detail::ResultCopy<false>{}, lucy_forward(arguments)...){}

        template<class... Arguments> requires(Meta::Constructible<ErrorT, Arguments...>) constexpr Result(ConstructError, Arguments&&... arguments) noexcept : m_error(true), m_variant(Detail::ResultCopy<true>{}, lucy_forward(arguments)...){}

        template<class Argument> requires(Meta::Constructible<T, Argument>) constexpr auto operator=(Argument&& argument) noexcept -> Result<T, ErrorT>&
        {
            if(m_error)
            {
                m_error = false;
                m_variant.m_tail.m_actual.~ErrorT();
                new (&m_variant.m_actual) T(lucy_forward(argument));
            }
            else
            {
                m_variant.m_actual.~T();
                new (&m_variant.m_actual) T(lucy_forward(argument));
            }
            return *this;
        }

        template<class Argument> requires(Meta::Constructible<ErrorT, Argument>) constexpr auto operator=(Argument&& argument) noexcept -> Result<T, ErrorT>&
        {
            if(m_error)
            {
                m_variant.m_tail.m_actual.~ErrorT();
                new (&m_variant.m_tail.m_actual) ErrorT(lucy_forward(argument));
            }
            else
            {
                m_error = true;
                m_variant.m_actual.~T();
                new (&m_variant.m_tail.m_actual) ErrorT(lucy_forward(argument));
            }
            return *this;
        }

        [[nodiscard]] constexpr auto IsError() const noexcept -> bool
        {
            return m_error;
        }

        constexpr auto Ok() noexcept -> T&
        {
            if(m_error)
                Abort();
            return Detail::Value<false>(m_variant);
        }

        constexpr auto Error() noexcept -> ErrorT&
        {
            if(not m_error)
                Abort();
            return Detail::Value<true>(m_variant);
        }
    };
}

#endif
#endif