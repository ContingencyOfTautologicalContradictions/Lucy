#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_option
#define lucy_core_option
#include "Abort.hpp"
#include "Forward.hpp"
#include "../Meta/Constructible.hpp"
#include "../Meta/TriviallyCopyable.hpp"

namespace Lucy
{
    namespace Detail
    {
        template<class...> class [[nodiscard]] OptionH{};

        template<bool> class [[nodiscard]] OptionCopy final{};

        template<class T, class... U>  class [[nodiscard]] OptionH<T, U...>
        {
        public:
            union
            {
                T m_actual;

                OptionH<U...> m_tail;
            };

            constexpr ~OptionH() noexcept
            {
                m_actual.~T();
            }

            constexpr ~OptionH() noexcept requires(Meta::TriviallyCopyable<T>){}

            template<class... Args> constexpr OptionH(OptionCopy<true>, Args&&... args) noexcept : m_tail(OptionH<U...>(OptionCopy<false>{}, lucy_forward(args)...)){}

            template<class... Args> constexpr OptionH(OptionCopy<false>, Args&&... args) noexcept : m_actual(lucy_forward(args)...){}
        };

        template<bool, class, class T> class OptionConditional
        {
        public:
            using Type = T;
        };

        template<class T, class U> class OptionConditional<true, T, U>
        {
        public:
            using Type = T;
        };

        template<bool index, class T, class U> constexpr auto Value(OptionH<T, U>& result) noexcept -> OptionConditional<not index, T, U>::Type&
        {
            if constexpr(not index)
                return result.m_actual;
            else
                return result.m_tail.m_actual;
        }
    }

    class [[nodiscard]] ConstructT final{};

    class [[nodiscard]] None{};

    template<class T> class [[nodiscard]] Option
    {
        bool m_none;

        Detail::OptionH<T, None> m_variant;
    public:
        constexpr ~Option() noexcept = default;

        constexpr Option() noexcept : m_none(false), m_variant(Detail::OptionCopy<false>{}){}

        template<class... Arguments> requires(Meta::Constructible<T, Arguments...>) constexpr Option(Arguments&&... arguments) noexcept : m_none(false), m_variant(Detail::OptionCopy<false>{}, lucy_forward(arguments)...){}

        template<class... Arguments> requires(Meta::Constructible<T, Arguments...>) constexpr Option(ConstructT, Arguments&&... arguments) noexcept : m_none(false), m_variant(Detail::OptionCopy<false>{}, lucy_forward(arguments)...){}

        constexpr Option(const None) noexcept : m_none(true), m_variant(Detail::OptionCopy<true>{}){}

        template<class Argument> requires(Meta::Constructible<T, Argument>) constexpr auto operator=(Argument&& argument) noexcept -> Option<T>&
        {
            if(m_none)
            {
                m_none = false;
                m_variant.m_tail.m_actual.~None();
                new (&m_variant.m_actual) T(lucy_forward(argument));
            }
            else
            {
                m_variant.m_actual.~T();
                new (&m_variant.m_actual) T(lucy_forward(argument));
            }
            return *this;
        }

        constexpr auto operator=(const None) noexcept -> Option<T>&
        {
            if(not m_none)
            {
                m_none = true;
                m_variant.m_actual.~T();
                new (&m_variant.m_tail.m_actual) None();
            }
            return *this;
        }

        [[nodiscard]] constexpr auto Empty() const noexcept -> bool
        {
            return m_none;
        }

        constexpr auto Some() noexcept -> T&
        {
            if(m_none)
                Abort();
            return Detail::Value<false>(m_variant);
        }
    };
}

#endif
#endif