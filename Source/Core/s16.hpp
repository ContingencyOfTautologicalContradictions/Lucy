#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_s16
#define lucy_core_s16
#include "u16.hpp"

namespace Lucy
{
    class [[nodiscard]] s16
    {
        short m_value;
    public:
        using Native = short;

        [[nodiscard]] static consteval auto Bits() noexcept -> u8
        {
            using namespace ::Lucy::Literal;
            return 16_u8;
        }

        [[nodiscard]] static consteval auto Minimum() noexcept -> s16
        {
            return s16 lucy_unsafe(-32768);
        }

        [[nodiscard]] static consteval auto Maximum() noexcept -> s16
        {
            return s16 lucy_unsafe(32767);
        }

        constexpr ~s16() noexcept = default;

        constexpr s16() noexcept : m_value(0){}

        constexpr s16(const s16& other) noexcept = default;

        constexpr s16(s16&& other) noexcept = default;

        constexpr auto operator=(const s16& other) noexcept -> s16& = default;

        constexpr auto operator=(s16&& other) noexcept -> s16& = default;

        constexpr s16 lucy_unreliable() noexcept{}

        constexpr s16 lucy_unreliable(const short value) noexcept : m_value(value){}

        [[nodiscard]] constexpr operator bool() const noexcept
        {
            return static_cast<bool>(m_value);
        }

        [[nodiscard]] explicit constexpr operator u8() const noexcept
        {
            return u8 lucy_unsafe(static_cast<unsigned char>(m_value));
        }

        [[nodiscard]] explicit constexpr operator s8() const noexcept
        {
            return s8 lucy_unsafe(static_cast<signed char>(m_value));
        }

        [[nodiscard]] explicit constexpr operator u16() const noexcept
        {
            return u16 lucy_unsafe(static_cast<unsigned short>(m_value));
        }

        [[nodiscard]] explicit constexpr operator f16() const noexcept;

        [[nodiscard]] explicit constexpr operator u32() const noexcept;

        [[nodiscard]] explicit constexpr operator s32() const noexcept;

        [[nodiscard]] explicit constexpr operator f32() const noexcept;

        [[nodiscard]] explicit constexpr operator u64() const noexcept;
        
        [[nodiscard]] explicit constexpr operator s64() const noexcept;

        [[nodiscard]] explicit constexpr operator f64() const noexcept;

        [[nodiscard]] constexpr auto operator+() const noexcept -> s16
        {
            return s16 lucy_unsafe(m_value);
        }

        [[nodiscard]] constexpr auto operator-() const noexcept -> s16
        {
            return s16 lucy_unsafe(-m_value);
        }

        constexpr auto operator++() noexcept -> s16&
        {
            ++m_value;
            return *this;
        }

        constexpr auto operator++(int) noexcept -> s16
        {
            return s16 lucy_unsafe(m_value++);
        }

        constexpr auto operator--() noexcept -> s16&
        {
            --m_value;
            return *this;
        }

        constexpr auto operator--(int) noexcept -> s16
        {
            return s16 lucy_unsafe(m_value--);
        }

        [[nodiscard]] constexpr auto operator==(const s16 other) const noexcept -> bool
        {
            return m_value == other.m_value;
        }

        [[nodiscard]] constexpr auto operator not_eq(const s16 other) const noexcept -> bool
        {
            return m_value not_eq other.m_value;
        }

        [[nodiscard]] constexpr auto operator<(const s16 other) const noexcept -> bool
        {
            return m_value < other.m_value;
        }

        [[nodiscard]] constexpr auto operator>(const s16 other) const noexcept -> bool
        {
            return m_value > other.m_value;
        }

        [[nodiscard]] constexpr auto operator<=(const s16 other) const noexcept -> bool
        {
            return m_value <= other.m_value;
        }

        [[nodiscard]] constexpr auto operator>=(const s16 other) const noexcept -> bool
        {
            return m_value >= other.m_value;
        }

        [[nodiscard]] constexpr auto operator<=>(const s16 other) const noexcept -> Comparison
        {
            using enum Comparison;
            if(m_value < other.m_value)
                return Lesser;
            else if(m_value > other.m_value)
                return Greater;
            return Equal;
        }

        constexpr auto operator and_eq(const s16 other) noexcept -> s16&
        {
            m_value and_eq other.m_value;
            return *this;
        }

        constexpr auto operator or_eq(const s16 other) noexcept -> s16&
        {
            m_value or_eq other.m_value;
            return *this;
        }

        constexpr auto operator xor_eq(const s16 other) noexcept -> s16&
        {
            m_value xor_eq other.m_value;
            return *this;
        }

        constexpr auto operator<<=(const u8 shifts) noexcept -> s16&
        {
            m_value <<= shifts.Value();
            return *this;
        }

        constexpr auto operator>>=(const u8 shifts) noexcept -> s16&
        {
            m_value >>= shifts.Value();
            return *this;
        }

        constexpr auto operator+=(const s16 other) noexcept -> s16&
        {
            m_value += other.m_value;
            return *this;
        }

        constexpr auto operator-=(const s16 other) noexcept -> s16&
        {
            m_value -= other.m_value;
            return *this;
        }

        constexpr auto operator*=(const s16 other) noexcept -> s16&
        {
            m_value *= other.m_value;
            return *this;
        }

        constexpr auto operator/=(const s16 other) noexcept -> s16&
        {
            m_value /= other.m_value;
            return *this;
        }

        constexpr auto operator%=(const s16 other) noexcept -> s16&
        {
            m_value %= other.m_value;
            return *this;
        }

        [[nodiscard]] constexpr auto operator compl() const noexcept -> s16
        {
            return s16 lucy_unsafe(compl m_value);
        }

        [[nodiscard]] constexpr auto operator bitand(const s16 other) const noexcept -> s16
        {
            return s16 lucy_unsafe(m_value bitand other.m_value);
        }

        [[nodiscard]] constexpr auto operator bitor(const s16 other) const noexcept -> s16
        {
            return s16 lucy_unsafe(m_value bitor other.m_value);
        }

        [[nodiscard]] constexpr auto operator xor(const s16 other) const noexcept -> s16
        {
            return s16 lucy_unsafe(m_value xor other.m_value);
        }

        [[nodiscard]] constexpr auto operator<<(const u8 shifts) const noexcept -> s16
        {
            return s16 lucy_unsafe(m_value << shifts.Value());
        }

        [[nodiscard]] constexpr auto operator>>(const u8 shifts) const noexcept -> s16
        {
            return s16 lucy_unsafe(m_value >> shifts.Value());
        }

        [[nodiscard]] constexpr auto operator+(const s16 other) const noexcept -> s16
        {
            return s16 lucy_unsafe(m_value + other.m_value);
        }

        [[nodiscard]] constexpr auto operator-(const s16 other) const noexcept -> s16
        {
            return s16 lucy_unsafe(m_value - other.m_value);
        }

        [[nodiscard]] constexpr auto operator*(const s16 other) const noexcept -> s16
        {
            return s16 lucy_unsafe(m_value * other.m_value);
        }

        [[nodiscard]] constexpr auto operator/(const s16 other) const noexcept -> s16
        {
            return s16 lucy_unsafe(m_value / other.m_value);
        }

        [[nodiscard]] constexpr auto operator%(const s16 other) const noexcept -> s16
        {
            return s16 lucy_unsafe(m_value % other.m_value);
        }

        [[nodiscard]] constexpr auto Value() const noexcept -> short
        {
            return m_value;
        }
    };

    namespace Literal
    {
        void LiteralIsBiggerThan32768() noexcept;

        [[nodiscard]] consteval auto operator ""_s16(const unsigned long long int value) noexcept -> s16
        {
            if(value > 32768ull)
                LiteralIsBiggerThan32768();
            return s16 lucy_unsafe(static_cast<short>(value));
        }
    }

    [[nodiscard]] constexpr u8::operator s16() const noexcept
    {
        return s16 lucy_unsafe(static_cast<short>(m_value));
    }

    [[nodiscard]] constexpr s8::operator s16() const noexcept
    {
        return s16 lucy_unsafe(static_cast<short>(m_value));
    }

    [[nodiscard]] constexpr u16::operator s16() const noexcept
    {
        return s16 lucy_unsafe(static_cast<short>(m_value));
    }
}

#endif
#endif