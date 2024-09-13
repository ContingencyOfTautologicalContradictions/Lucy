#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_character
#define lucy_core_character
#include "u8.hpp"
#include "Option.hpp"
#include "Reference.hpp"

namespace Lucy
{
    class [[nodiscard]] Character
    {
        char8_t m_value;
    public:
        using Native = char8_t;

        [[nodiscard]] static consteval auto Bits() noexcept -> u8
        {
            using namespace Literal;
            return 8_u8;
        }

        constexpr ~Character() noexcept = default;

        constexpr Character() noexcept : m_value(u8'\0'){}

        constexpr Character(const Character& other) noexcept = default;

        constexpr Character(Character&& other) noexcept = default;

        constexpr auto operator=(const Character& other) noexcept -> Character& = default;

        constexpr auto operator=(Character&& other) noexcept -> Character& = default;

        constexpr Character lucy_unreliable() noexcept{}

        constexpr Character(const char8_t value) noexcept : m_value(value){}

        [[nodiscard]] explicit constexpr operator u8() const noexcept
        {
            return u8 lucy_unsafe(static_cast<unsigned char>(m_value - u8'0'));
        }

        [[nodiscard]] constexpr auto operator==(const Character other) const noexcept -> bool
        {
            return m_value == other.m_value;
        }

        [[nodiscard]] constexpr auto operator not_eq(const Character other) const noexcept -> bool
        {
            return m_value not_eq other.m_value;
        }

        [[nodiscard]] constexpr auto Control() const noexcept -> bool
        {
            return m_value < u8'!' or m_value == 0x7f;
        }

        [[nodiscard]] constexpr auto Punctuation() const noexcept -> bool
        {
            return (m_value >= u8'!' and m_value <= u8'#') or (m_value >= u8'%' and m_value <= u8'*') or (m_value >= u8',' and m_value <= u8'/') or m_value == u8':' or m_value == u8';' or m_value == u8'?' or m_value == u8'@' or (m_value >= u8'[' and m_value <= u8']') or m_value == u8'_' or m_value == u8'{' or m_value == u8'}';
        }

        [[nodiscard]] constexpr auto Symbol() const noexcept -> bool
        {
            return m_value == u8'$' or m_value == u8'^' or m_value == u8'`' or m_value == u8'|' or m_value == u8'~';
        }

        [[nodiscard]] constexpr auto MathematicalOperator() const noexcept -> bool
        {
            return m_value == u8'+' or (m_value >= u8'<' and m_value <= u8'>');
        }

        [[nodiscard]] constexpr auto Digits() const noexcept -> bool
        {
            return m_value >= u8'0' and m_value <= u8'9';
        }

        [[nodiscard]] constexpr auto Uppercase() const noexcept -> bool
        {
            return m_value >= u8'A' and m_value <= u8'Z';
        }

        [[nodiscard]] constexpr auto Lowercase() const noexcept -> bool
        {
            return m_value >= u8'a' and m_value <= u8'z';
        }

        [[nodiscard]] constexpr auto ASCII() const noexcept -> bool
        {
            return m_value <= 0x7f;
        }

        [[nodiscard]] constexpr auto ToUppercase lucy_unreliable() const noexcept -> Character
        {
            return Character(m_value - u8' ');
        }

        [[nodiscard]] constexpr auto ToLowercase lucy_unreliable() const noexcept -> Character
        {
            return Character(m_value + u8' ');
        }

        [[nodiscard]] constexpr auto ToUppercase() const noexcept -> Option<Character>
        {
            if(m_value < u8'a' or m_value > u8'z')
                return None();
            return Character(m_value - u8' ');
        }

        [[nodiscard]] constexpr auto ToLowercase() const noexcept -> Option<Character>
        {
            if(m_value < u8'A' or m_value > u8'Z')
                return None();
            return Character(m_value + u8' ');
        }

        constexpr auto MakeLowercase lucy_unreliable() noexcept -> Character&
        {
            m_value += u8' ';
            return *this;
        }

        constexpr auto MakeUppercase lucy_unreliable() noexcept -> Character&
        {
            m_value -= u8' ';
            return *this;
        }

        constexpr auto MakeLowercase() noexcept -> Option<Reference<Character>>
        {
            if(m_value < u8'A' or m_value > u8'Z')
                return None();
            m_value += u8' ';
            return *this;
        }

        constexpr auto MakeUppercase() noexcept -> Option<Reference<Character>>
        {
            if(m_value < u8'a' or m_value > u8'z')
                return None();
            m_value -= u8' ';
            return *this;
        }

        [[nodiscard]] constexpr auto Value() const noexcept -> const char8_t&
        {
            return m_value;
        }
    };
}

#endif
#endif