#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_u16
#define lucy_core_u16
#include "s8.hpp"

namespace Lucy
{
    class [[nodiscard]] u16
    {
        unsigned short m_value;
    public:
        using Native = unsigned short;

        [[nodiscard]] static inline consteval auto Bits() noexcept -> u8
        {
            using namespace ::Lucy::Literal;
            return 16_u8;
        }

        [[nodiscard]] static inline consteval auto Minimum() noexcept -> u16
        {
            return u16 lucy_unsafe(0u);
        }

        [[nodiscard]] static inline consteval auto Maximum() noexcept -> u16
        {
            return u16 lucy_unsafe(65535u);
        }

        inline constexpr ~u16() noexcept = default;

        inline constexpr u16() noexcept : m_value(0u){}

        inline constexpr u16(const u16& other) noexcept = default;

        inline constexpr u16(u16&& other) noexcept = default;

        inline constexpr auto operator=(const u16& other) noexcept -> u16& = default;

        inline constexpr auto operator=(u16&& other) noexcept -> u16& = default;

        inline constexpr u16 lucy_unreliable() noexcept{}

        inline constexpr u16 lucy_unreliable(const unsigned short value) noexcept : m_value(value){}

        [[nodiscard]] inline constexpr operator bool() const noexcept
        {
            return static_cast<bool>(m_value);
        }

        [[nodiscard]] explicit inline constexpr operator u8() const noexcept
        {
            return u8 lucy_unsafe(static_cast<unsigned char>(m_value));
        }

        [[nodiscard]] explicit inline constexpr operator s8() const noexcept
        {
            return s8 lucy_unsafe(static_cast<signed char>(m_value));
        }

        [[nodiscard]] explicit inline constexpr operator s16() const noexcept;

        [[nodiscard]] explicit inline constexpr operator f16() const noexcept;

        [[nodiscard]] explicit inline constexpr operator u32() const noexcept;

        [[nodiscard]] explicit inline constexpr operator s32() const noexcept;

        [[nodiscard]] explicit inline constexpr operator f32() const noexcept;

        [[nodiscard]] explicit inline constexpr operator u64() const noexcept;

        [[nodiscard]] explicit inline constexpr operator s64() const noexcept;

        [[nodiscard]] explicit inline constexpr operator f64() const noexcept;

        [[nodiscard]] inline constexpr auto operator+() const noexcept -> u16
        {
            return u16 lucy_unsafe(m_value);
        }

        inline constexpr auto operator++() noexcept -> u16&
        {
            ++m_value;
            return *this;
        }

        inline constexpr auto operator++(int) noexcept -> u16
        {
            return u16 lucy_unsafe(m_value++);
        }

        inline constexpr auto operator--() noexcept -> u16&
        {
            --m_value;
            return *this;
        }

        inline constexpr auto operator--(int) noexcept -> u16
        {
            return u16 lucy_unsafe(m_value--);
        }

        [[nodiscard]] inline constexpr auto operator==(const u16 other) const noexcept -> bool
        {
            return m_value == other.m_value;
        }

        [[nodiscard]] inline constexpr auto operator not_eq(const u16 other) const noexcept -> bool
        {
            return m_value not_eq other.m_value;
        }

        [[nodiscard]] inline constexpr auto operator<(const u16 other) const noexcept -> bool
        {
            return m_value < other.m_value;
        }

        [[nodiscard]] inline constexpr auto operator>(const u16 other) const noexcept -> bool
        {
            return m_value > other.m_value;
        }

        [[nodiscard]] inline constexpr auto operator<=(const u16 other) const noexcept -> bool
        {
            return m_value <= other.m_value;
        }

        [[nodiscard]] inline constexpr auto operator>=(const u16 other) const noexcept -> bool
        {
            return m_value >= other.m_value;
        }

        [[nodiscard]] inline constexpr auto operator<=>(const u16 other) const noexcept -> Comparison
        {
            using enum Comparison;
            if(m_value < other.m_value)
                return Lesser;
            else if(m_value > other.m_value)
                return Greater;
            return Equal;
        }

        inline constexpr auto operator and_eq(const u16 other) noexcept -> u16&
        {
            m_value and_eq other.m_value;
            return *this;
        }
        
        inline constexpr auto operator or_eq(const u16 other) noexcept -> u16&
        {
            m_value or_eq other.m_value;
            return *this;
        }

        inline constexpr auto operator xor_eq(const u16 other) noexcept -> u16&
        {
            m_value xor_eq other.m_value;
            return *this;
        }

        inline constexpr auto operator<<=(const u8 shifts) noexcept -> u16&
        {
            m_value <<= shifts.Value();
            return *this;
        }

        inline constexpr auto operator>>=(const u8 shifts) noexcept -> u16&
        {
            m_value >>= shifts.Value();
            return *this;
        }

        inline constexpr auto operator+=(const u16 other) noexcept -> u16&
        {
            m_value += other.m_value;
            return *this;
        }

        inline constexpr auto operator-=(const u16 other) noexcept -> u16&
        {
            m_value -= other.m_value;
            return *this;
        }

        inline constexpr auto operator*=(const u16 other) noexcept -> u16&
        {
            m_value *= other.m_value;
            return *this;
        }

        inline constexpr auto operator/=(const u16 other) noexcept -> u16&
        {
            m_value /= other.m_value;
            return *this;
        }

        inline constexpr auto operator%=(const u16 other) noexcept -> u16&
        {
            m_value %= other.m_value;
            return *this;
        }

        [[nodiscard]] inline constexpr auto operator compl() const noexcept -> u16
        {
            return u16 lucy_unsafe(compl m_value);
        }

        [[nodiscard]] inline constexpr auto operator bitand(const u16 other) const noexcept -> u16
        {
            return u16 lucy_unsafe(m_value bitand other.m_value);
        }

        [[nodiscard]] inline constexpr auto operator bitor(const u16 other) const noexcept -> u16
        {
            return u16 lucy_unsafe(m_value bitor other.m_value);
        }

        [[nodiscard]] inline constexpr auto operator xor(const u16 other) const noexcept -> u16
        {
            return u16 lucy_unsafe(m_value xor other.m_value);
        }

        [[nodiscard]] inline constexpr auto operator<<(const u8 shifts) const noexcept -> u16
        {
            return u16 lucy_unsafe(m_value << shifts.Value());
        }

        [[nodiscard]] inline constexpr auto operator>>(const u8 shifts) const noexcept -> u16
        {
            return u16 lucy_unsafe(m_value >> shifts.Value());
        }

        [[nodiscard]] inline constexpr auto operator+(const u16 other) const noexcept -> u16
        {
            return u16 lucy_unsafe(m_value + other.m_value);
        }

        [[nodiscard]] inline constexpr auto operator-(const u16 other) const noexcept -> u16
        {
            return u16 lucy_unsafe(m_value - other.m_value);
        }

        [[nodiscard]] inline constexpr auto operator*(const u16 other) const noexcept -> u16
        {
            return u16 lucy_unsafe(m_value * other.m_value);
        }

        [[nodiscard]] inline constexpr auto operator/(const u16 other) const noexcept -> u16
        {
            return u16 lucy_unsafe(m_value / other.m_value);
        }

        [[nodiscard]] inline constexpr auto operator%(const u16 other) const noexcept -> u16
        {
            return u16 lucy_unsafe(m_value % other.m_value);
        }

        [[nodiscard]] inline constexpr auto Value() const noexcept -> unsigned short
        {
            return m_value;
        }
    };

    namespace Literal
    {
        void LiteralIsBiggerThan65535() noexcept;

        [[nodiscard]] inline consteval auto operator ""_u16(const unsigned long long int value) noexcept -> u16
        {
            if(value > 65535ull)
                LiteralIsBiggerThan65535();
            return u16 lucy_unsafe(static_cast<unsigned short>(value));
        }
    }

    [[nodiscard]] inline constexpr u8::operator u16() const noexcept
    {
        return u16 lucy_unsafe(static_cast<unsigned short>(m_value));
    }

    [[nodiscard]] inline constexpr s8::operator u16() const noexcept
    {
        return u16 lucy_unsafe(static_cast<unsigned short>(m_value));
    }
}

#endif
#endif