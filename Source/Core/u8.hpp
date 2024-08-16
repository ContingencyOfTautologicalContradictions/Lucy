#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_u8
#define lucy_core_u8
#include "Unsafe.hpp"
#include "Comparison.hpp"

namespace Lucy
{
    class [[nodiscard]] s8;

    class [[nodiscard]] u16;

    class [[nodiscard]] s16;

    class [[nodiscard]] f16;

    class [[nodiscard]] u32;

    class [[nodiscard]] s32;
    
    class [[nodiscard]] f32;

    class [[nodiscard]] u64;

    class [[nodiscard]] s64;

    class [[nodiscard]] f64;

    class [[nodiscard]] u8
    {
        unsigned char m_value;
    public:
        using Native = unsigned char;

        [[nodiscard]] inline consteval auto Bits() noexcept -> u8
        {
            return u8 lucy_unsafe(8u);
        }

        [[nodiscard]] inline consteval auto Minimum() noexcept -> u8
        {
            return u8 lucy_unsafe(0u);
        }

        [[nodiscard]] inline consteval auto Maximum() noexcept -> u8
        {
            return u8 lucy_unsafe(255u);
        }

        inline constexpr ~u8() noexcept = default;

        inline constexpr u8() noexcept : m_value(0u){}

        inline constexpr u8(const u8& other) noexcept = default;

        inline constexpr u8(u8&& other) noexcept = default;

        inline constexpr auto operator=(const u8& other) noexcept -> u8& = default;

        inline constexpr auto operator=(u8&& other) noexcept -> u8& = default;

        inline constexpr u8 lucy_unreliable() noexcept{}

        inline constexpr u8 lucy_unreliable(const unsigned char value) noexcept : m_value(value){}

        [[nodiscard]] inline constexpr operator bool() const noexcept
        {
            return static_cast<bool>(m_value);
        }

        [[nodiscard]] explicit inline constexpr operator s8() const noexcept;

        [[nodiscard]] explicit inline constexpr operator u16() const noexcept;

        [[nodiscard]] explicit inline constexpr operator s16() const noexcept;

        [[nodiscard]] explicit inline constexpr operator f16() const noexcept;

        [[nodiscard]] explicit inline constexpr operator u32() const noexcept;

        [[nodiscard]] explicit inline constexpr operator s32() const noexcept;

        [[nodiscard]] explicit inline constexpr operator f32() const noexcept;

        [[nodiscard]] explicit inline constexpr operator u64() const noexcept;

        [[nodiscard]] explicit inline constexpr operator s64() const noexcept;

        [[nodiscard]] explicit inline constexpr operator f64() const noexcept;

        [[nodiscard]] inline constexpr auto operator+() const noexcept -> u8
        {
            return u8 lucy_unsafe(m_value);
        }

        inline constexpr auto operator++() noexcept -> u8&
        {
            ++m_value;
            return *this;
        }

        inline constexpr auto operator++(int) noexcept -> u8
        {
            return u8 lucy_unsafe(m_value++);
        }

        inline constexpr auto operator--() noexcept -> u8&
        {
            --m_value;
            return *this;
        }

        inline constexpr auto operator--(int) noexcept -> u8
        {
            return u8 lucy_unsafe(m_value--);
        }

        [[nodiscard]] inline constexpr auto operator==(const u8 other) const noexcept -> bool
        {
            return m_value == other.m_value;
        }

        [[nodiscard]] inline constexpr auto operator not_eq(const u8 other) const noexcept -> bool
        {
            return m_value not_eq other.m_value;
        }

        [[nodiscard]] inline constexpr auto operator<(const u8 other) const noexcept -> bool
        {
            return m_value < other.m_value;
        }

        [[nodiscard]] inline constexpr auto operator>(const u8 other) const noexcept -> bool
        {
            return m_value > other.m_value;
        }

        [[nodiscard]] inline constexpr auto operator<=(const u8 other) const noexcept -> bool
        {
            return m_value <= other.m_value;
        }

        [[nodiscard]] inline constexpr auto operator>=(const u8 other) const noexcept -> bool
        {
            return m_value >= other.m_value;
        }

        [[nodiscard]] inline constexpr auto operator<=>(const u8 other) const noexcept -> Comparison
        {
            using enum Comparison;
            if(m_value < other.m_value)
                return Lesser;
            else if(m_value > other.m_value)
                return Greater;
            return Equal;
        }

        inline constexpr auto operator and_eq(const u8 other) noexcept -> u8&
        {
            m_value and_eq other.m_value;
            return *this;
        }

        inline constexpr auto operator or_eq(const u8 other) noexcept -> u8&
        {
            m_value or_eq other.m_value;
            return *this;
        }

        inline constexpr auto operator xor_eq(const u8 other) noexcept -> u8&
        {
            m_value xor_eq other.m_value;
            return *this;
        }

        inline constexpr auto operator<<=(const u8 shifts) noexcept -> u8&
        {
            m_value <<= shifts.m_value;
            return *this;
        }

        inline constexpr auto operator>>=(const u8 shifts) noexcept -> u8&
        {
            m_value >>= shifts.m_value;
            return *this;
        }

        inline constexpr auto operator+=(const u8 other) noexcept -> u8&
        {
            m_value += other.m_value;
            return *this;
        }

        inline constexpr auto operator-=(const u8 other) noexcept -> u8&
        {
            m_value -= other.m_value;
            return *this;
        }

        inline constexpr auto operator*=(const u8 other) noexcept -> u8&
        {
            m_value *= other.m_value;
            return *this;
        }

        inline constexpr auto operator/=(const u8 other) noexcept -> u8&
        {
            m_value /= other.m_value;
            return *this;
        }

        inline constexpr auto operator%=(const u8 other) noexcept -> u8&
        {
            m_value %= other.m_value;
            return *this;
        }

        [[nodiscard]] inline constexpr auto operator compl() const noexcept -> u8
        {
            return u8 lucy_unsafe(compl m_value);
        }

        [[nodiscard]] inline constexpr auto operator bitand(const u8 other) const noexcept -> u8
        {
            return u8 lucy_unsafe(m_value bitand other.m_value);
        }

        [[nodiscard]] inline constexpr auto operator bitor(const u8 other) const noexcept -> u8
        {
            return u8 lucy_unsafe(m_value bitor other.m_value);
        }

        [[nodiscard]] inline constexpr auto operator xor(const u8 other) const noexcept -> u8
        {
            return u8 lucy_unsafe(m_value xor other.m_value);
        }

        [[nodiscard]] inline constexpr auto operator<<(const u8 other) const noexcept -> u8
        {
            return u8 lucy_unsafe(m_value << other.m_value);
        }

        [[nodiscard]] inline constexpr auto operator>>(const u8 other) const noexcept -> u8
        {
            return u8 lucy_unsafe(m_value >> other.m_value);
        }

        [[nodiscard]] inline constexpr auto operator+(const u8 other) const noexcept -> u8
        {
            return u8 lucy_unsafe(m_value + other.m_value);
        }

        [[nodiscard]] inline constexpr auto operator-(const u8 other) const noexcept -> u8
        {
            return u8 lucy_unsafe(m_value - other.m_value);
        }

        [[nodiscard]] inline constexpr auto operator*(const u8 other) const noexcept -> u8
        {
            return u8 lucy_unsafe(m_value * other.m_value);
        }

        [[nodiscard]] inline constexpr auto operator/(const u8 other) const noexcept -> u8
        {
            return u8 lucy_unsafe(m_value / other.m_value);
        }

        [[nodiscard]] inline constexpr auto operator%(const u8 other) const noexcept -> u8
        {
            return u8 lucy_unsafe(m_value % other.m_value);
        }

        [[nodiscard]] inline constexpr auto Value() const noexcept -> unsigned char
        {
            return m_value;
        }
    };

    namespace Literal
    {
        void LiteralIsBiggerThan255() noexcept;

        [[nodiscard]] inline consteval auto operator ""_u8(const unsigned long long int value) noexcept -> u8
        {
            if(value > 255ull)
                LiteralIsBiggerThan255();
            return u8 lucy_unsafe(static_cast<unsigned char>(value));
        }
    }
}

#endif
#endif