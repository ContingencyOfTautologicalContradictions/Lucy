#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_s8
#define lucy_core_s8
#include "u8.hpp"

namespace Lucy
{
    class [[nodiscard]] s8
    {
        signed char m_value;
    public:
        using Native = signed char;

        [[nodiscard]] static consteval auto Bits() noexcept -> u8
        {
            using namespace ::Lucy::Literal;
            return 8_u8;
        }

        [[nodiscard]] static consteval auto Minimum() noexcept -> s8
        {
            return s8 lucy_unsafe(-128);
        }

        [[nodiscard]] static consteval auto Maximum() noexcept -> s8
        {
            return s8 lucy_unsafe(127);
        }

        constexpr ~s8() noexcept = default;

        constexpr s8() noexcept : m_value(0){}

        constexpr s8(const s8& other) noexcept = default;

        constexpr s8(s8&& other) noexcept = default;

        constexpr auto operator=(const s8& other) noexcept -> s8& = default;

        constexpr auto operator=(s8&& other) noexcept -> s8& = default;

        constexpr s8 lucy_unreliable() noexcept{}

        constexpr s8 lucy_unreliable(const signed char value) noexcept : m_value(value){}

        [[nodiscard]] constexpr operator bool() const noexcept
        {
            return static_cast<bool>(m_value);
        }

        [[nodiscard]] explicit constexpr operator u8() const noexcept
        {
            return u8 lucy_unsafe(static_cast<unsigned char>(m_value));
        }

        [[nodiscard]] explicit constexpr operator u16() const noexcept;

        [[nodiscard]] explicit constexpr operator s16() const noexcept;

        [[nodiscard]] explicit constexpr operator f16() const noexcept;

        [[nodiscard]] explicit constexpr operator u32() const noexcept;

        [[nodiscard]] explicit constexpr operator s32() const noexcept;

        [[nodiscard]] explicit constexpr operator f32() const noexcept;

        [[nodiscard]] explicit constexpr operator u64() const noexcept;

        [[nodiscard]] explicit constexpr operator s64() const noexcept;

        [[nodiscard]] explicit constexpr operator f64() const noexcept;

        [[nodiscard]] constexpr auto operator+() const noexcept -> s8
        {
            return s8 lucy_unsafe(m_value);
        }

        [[nodiscard]] constexpr auto operator-() const noexcept -> s8
        {
            return s8 lucy_unsafe(-m_value);
        }

        constexpr auto operator++() noexcept -> s8&
        {
            ++m_value;
            return *this;
        }

        constexpr auto operator++(int) noexcept -> s8
        {
            return s8 lucy_unsafe(m_value++);
        }

        constexpr auto operator--() noexcept -> s8&
        {
            --m_value;
            return *this;
        }

        constexpr auto operator--(int) noexcept -> s8
        {
            return s8 lucy_unsafe(m_value--);
        }

        [[nodiscard]] constexpr auto operator==(const s8 other) const noexcept -> bool
        {
            return m_value == other.m_value;
        }

        [[nodiscard]] constexpr auto operator not_eq(const s8 other) const noexcept -> bool
        {
            return m_value not_eq other.m_value;
        }

        [[nodiscard]] constexpr auto operator<(const s8 other) const noexcept -> bool
        {
            return m_value < other.m_value;
        }

        [[nodiscard]] constexpr auto operator>(const s8 other) const noexcept -> bool
        {
            return m_value > other.m_value;
        }

        [[nodiscard]] constexpr auto operator<=(const s8 other) const noexcept -> bool
        {
            return m_value <= other.m_value;
        }

        [[nodiscard]] constexpr auto operator>=(const s8 other) const noexcept -> bool
        {
            return m_value >= other.m_value;
        }

        [[nodiscard]] constexpr auto operator<=>(const s8 other) const noexcept -> Comparison
        {
            using enum Comparison;
            if(m_value < other.m_value)
                return Lesser;
            else if(m_value > other.m_value)
                return Greater;
            return Equal;
        }

        constexpr auto operator and_eq(const s8 other) noexcept -> s8&
        {
            m_value and_eq other.m_value;
            return *this;
        }

        constexpr auto operator or_eq(const s8 other) noexcept -> s8&
        {
            m_value or_eq other.m_value;
            return *this;
        }

        constexpr auto operator xor_eq(const s8 other) noexcept -> s8&
        {
            m_value xor_eq other.m_value;
            return *this;
        }

        constexpr auto operator<<=(const u8 shifts) noexcept -> s8&
        {
            m_value <<= shifts.Value();
            return *this;
        }

        constexpr auto operator>>=(const u8 shifts) noexcept -> s8&
        {
            m_value >>= shifts.Value();
            return *this;
        }

        constexpr auto operator+=(const s8 other) noexcept -> s8&
        {
            m_value += other.m_value;
            return *this;
        }

        constexpr auto operator-=(const s8 other) noexcept -> s8&
        {
            m_value -= other.m_value;
            return *this;
        }

        constexpr auto operator*=(const s8 other) noexcept -> s8&
        {
            m_value *= other.m_value;
            return *this;
        }

        constexpr auto operator/=(const s8 other) noexcept -> s8&
        {
            m_value /= other.m_value;
            return *this;
        }

        constexpr auto operator%=(const s8 other) noexcept -> s8&
        {
            m_value %= other.m_value;
            return *this;
        }

        [[nodiscard]] constexpr auto operator compl() const noexcept -> s8
        {
            return s8 lucy_unsafe(compl m_value);
        }

        [[nodiscard]] constexpr auto operator bitand(const s8 other) const noexcept -> s8
        {
            return s8 lucy_unsafe(m_value bitand other.m_value);
        }

        [[nodiscard]] constexpr auto operator bitor(const s8 other) const noexcept -> s8
        {
            return s8 lucy_unsafe(m_value bitor other.m_value);
        }

        [[nodiscard]] constexpr auto operator xor(const s8 other) const noexcept -> s8
        {
            return s8 lucy_unsafe(m_value xor other.m_value);
        }

        [[nodiscard]] constexpr auto operator<<(const u8 shifts) const noexcept -> s8
        {
            return s8 lucy_unsafe(m_value << shifts.Value());
        }

        [[nodiscard]] constexpr auto operator>>(const u8 shifts) const noexcept -> s8
        {
            return s8 lucy_unsafe(m_value >> shifts.Value());
        }

        [[nodiscard]] constexpr auto operator+(const s8 other) const noexcept -> s8
        {
            return s8 lucy_unsafe(m_value + other.m_value);
        }

        [[nodiscard]] constexpr auto operator-(const s8 other) const noexcept -> s8
        {
            return s8 lucy_unsafe(m_value - other.m_value);
        }

        [[nodiscard]] constexpr auto operator*(const s8 other) const noexcept -> s8
        {
            return s8 lucy_unsafe(m_value * other.m_value);
        }

        [[nodiscard]] constexpr auto operator/(const s8 other) const noexcept -> s8
        {
            return s8 lucy_unsafe(m_value / other.m_value);
        }

        [[nodiscard]] constexpr auto operator%(const s8 other) const noexcept -> s8
        {
            return s8 lucy_unsafe(m_value % other.m_value);
        }

        [[nodiscard]] constexpr auto Value() const noexcept -> signed char
        {
            return m_value;
        }
    };

    namespace Literal
    {
        void LiteralIsBiggerThan128() noexcept;

        [[nodiscard]] consteval auto operator ""_s8(const unsigned long long int value) noexcept -> s8
        {
            if(value > 128)
                LiteralIsBiggerThan128();
            return s8 lucy_unsafe(static_cast<signed char>(value));
        }
    }

    [[nodiscard]] constexpr u8::operator s8() const noexcept
    {
        return s8 lucy_unsafe(static_cast<signed char>(m_value));
    }
}

#endif
#endif