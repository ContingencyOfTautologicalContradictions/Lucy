#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_result
#define lucy_core_result
#include "Size.hpp"
#include "Abort.hpp"
#include "Forward.hpp"
#include "../Meta/Constructible.hpp"
#include "../Meta/TriviallyCopyable.hpp"

namespace Lucy
{
    namespace Detail
    {
        template<class...> class [[nodiscard]] ResultH{};

        template<Size> class [[nodiscard]] ResultCopy final{};

        template<class T, class... U>  class [[nodiscard]] ResultH<T, U...>
        {
        public:
            union
            {
                T m_actual;

                ResultH<U...> m_tail;
            };

            constexpr ~ResultH() noexcept{}

            constexpr ~ResultH() noexcept requires(Meta::TriviallyCopyable<T>)
            {
                m_actual.~T();
            }

            template<Size index, class... Args> constexpr ResultH(ResultCopy<index>, Args&&... args) noexcept : m_tail(ResultH<U...>(ResultCopy<index - 1uz>{}, lucy_forward(args)...)){}

            template<class... Args> constexpr ResultH(ResultCopy<0uz>, Args&&... args) noexcept : m_actual(lucy_forward(args)...){}
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

        template<Size index, class T, class U> constexpr auto Value(ResultH<T, U>& result) noexcept -> ResultConditional<index == 0uz, T, U>::Type&
        {
            if constexpr(index == 0u)
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

        constexpr Result() noexcept : m_error(false), m_variant(Detail::ResultCopy<0uz>{}){}

        template<class... Arguments> requires(Meta::Constructible<T, Arguments...>) constexpr Result(Arguments&&... arguments) noexcept : m_error(false), m_variant(Detail::ResultCopy<0uz>{}, lucy_forward(arguments)...){}

        template<class... Arguments> requires(Meta::Constructible<ErrorT, Arguments...>) constexpr Result(Arguments&&... arguments) noexcept : m_error(true), m_variant(Detail::ResultCopy<1uz>{}, lucy_forward(arguments)...){}

        template<class... Arguments> requires(Meta::Constructible<T, Arguments...>) constexpr Result(ConstructT, Arguments&&... arguments) noexcept : m_error(false), m_variant(Detail::ResultCopy<0uz>{}, lucy_forward(arguments)...){}

        template<class... Arguments> requires(Meta::Constructible<ErrorT, Arguments...>) constexpr Result(ConstructError, Arguments&&... arguments) noexcept : m_error(true), m_variant(Detail::ResultCopy<1uz>{}, lucy_forward(arguments)...){}

        template<class Argument> requires(Meta::Constructible<T, Argument>) constexpr auto operator=(Argument&& argument) noexcept -> Result<T, ErrorT>&
        {
            if(m_error)
            {
                m_error = false;
                m_variant.m_tail.m_actual.~ErrorT();
                new (&m_variant.m_actual) ErrorT(lucy_forward(argument));
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
            return Detail::Value<0uz>(m_variant);
        }

        constexpr auto Error() noexcept -> ErrorT&
        {
            if(not m_error)
                Abort();
            return Detail::Value<1uz>(m_variant);
        }
    };
}

#endif
#endif