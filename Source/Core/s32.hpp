#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_s32
#define lucy_core_s32
#include "u32.hpp"

namespace Lucy
{
    class [[nodiscard]] s32
    {
        int m_value;
    public:
        using Native = int;

        [[nodiscard]] static consteval auto Bits() noexcept -> u8
        {
            using namespace ::Lucy::Literal;
            return 32_u8;
        }

        [[nodiscard]] static consteval auto Minimum() noexcept -> s32
        {
            return s32 lucy_unsafe(-2147483648l);
        }

        [[nodiscard]] static consteval auto Maximum() noexcept -> s32
        {
            return s32 lucy_unsafe(2147483647l);
        }

        constexpr ~s32() noexcept = default;

        constexpr s32() noexcept : m_value(0l){}

        constexpr s32(const s32& other) noexcept = default;

        constexpr s32(s32&& other) noexcept = default;

        constexpr auto operator=(const s32& other) noexcept -> s32& = default;

        constexpr auto operator=(s32&& other) noexcept -> s32& = default;

        constexpr s32 lucy_unreliable() noexcept{}

        constexpr s32 lucy_unreliable(const int value) noexcept : m_value(value){}

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

        [[nodiscard]] explicit constexpr operator s16() const noexcept
        {
            return s16 lucy_unsafe(static_cast<short>(m_value));
        }

        [[nodiscard]] explicit constexpr operator f16() const noexcept
        {
            return f16 lucy_unsafe(static_cast<_Float16>(m_value));
        }

        [[nodiscard]] explicit constexpr operator u32() const noexcept
        {
            return u32 lucy_unsafe(static_cast<unsigned int>(m_value));
        }

        [[nodiscard]] explicit constexpr operator f32() const noexcept;

        [[nodiscard]] explicit constexpr operator u64() const noexcept;
        
        [[nodiscard]] explicit constexpr operator s64() const noexcept;

        [[nodiscard]] explicit constexpr operator f64() const noexcept;

        [[nodiscard]] constexpr auto operator+() const noexcept -> s32
        {
            return s32 lucy_unsafe(m_value);
        }

        [[nodiscard]] constexpr auto operator-() const noexcept -> s32
        {
            return s32 lucy_unsafe(-m_value);
        }

        constexpr auto operator++() noexcept -> s32&
        {
            ++m_value;
            return *this;
        }

        constexpr auto operator++(int) noexcept -> s32
        {
            return s32 lucy_unsafe(m_value++);
        }

        constexpr auto operator--() noexcept -> s32&
        {
            --m_value;
            return *this;
        }

        constexpr auto operator--(int) noexcept -> s32
        {
            return s32 lucy_unsafe(m_value--);
        }

        [[nodiscard]] constexpr auto operator==(const s32 other) const noexcept -> bool
        {
            return m_value == other.m_value;
        }

        [[nodiscard]] constexpr auto operator not_eq(const s32 other) const noexcept -> bool
        {
            return m_value not_eq other.m_value;
        }

        [[nodiscard]] constexpr auto operator<(const s32 other) const noexcept -> bool
        {
            return m_value < other.m_value;
        }

        [[nodiscard]] constexpr auto operator>(const s32 other) const noexcept -> bool
        {
            return m_value > other.m_value;
        }

        [[nodiscard]] constexpr auto operator<=(const s32 other) const noexcept -> bool
        {
            return m_value <= other.m_value;
        }

        [[nodiscard]] constexpr auto operator>=(const s32 other) const noexcept -> bool
        {
            return m_value >= other.m_value;
        }

        [[nodiscard]] constexpr auto operator<=>(const s32 other) const noexcept -> Comparison
        {
            using enum Comparison;
            if(m_value < other.m_value)
                return Lesser;
            else if(m_value > other.m_value)
                return Greater;
            return Equal;
        }

        constexpr auto operator and_eq(const s32 other) noexcept -> s32&
        {
            m_value and_eq other.m_value;
            return *this;
        }

        constexpr auto operator or_eq(const s32 other) noexcept -> s32&
        {
            m_value or_eq other.m_value;
            return *this;
        }

        constexpr auto operator xor_eq(const s32 other) noexcept -> s32&
        {
            m_value xor_eq other.m_value;
            return *this;
        }

        constexpr auto operator<<=(const u8 shifts) noexcept -> s32&
        {
            m_value <<= shifts.Value();
            return *this;
        }

        constexpr auto operator>>=(const u8 shifts) noexcept -> s32&
        {
            m_value >>= shifts.Value();
            return *this;
        }

        constexpr auto operator+=(const s32 other) noexcept -> s32&
        {
            m_value += other.m_value;
            return *this;
        }

        constexpr auto operator-=(const s32 other) noexcept -> s32&
        {
            m_value -= other.m_value;
            return *this;
        }

        constexpr auto operator*=(const s32 other) noexcept -> s32&
        {
            m_value *= other.m_value;
            return *this;
        }

        constexpr auto operator/=(const s32 other) noexcept -> s32&
        {
            m_value /= other.m_value;
            return *this;
        }

        constexpr auto operator%=(const s32 other) noexcept -> s32&
        {
            m_value %= other.m_value;
            return *this;
        }

        [[nodiscard]] constexpr auto operator compl() const noexcept -> s32
        {
            return s32 lucy_unsafe(compl m_value);
        }

        [[nodiscard]] constexpr auto operator bitand(const s32 other) const noexcept -> s32
        {
            return s32 lucy_unsafe(m_value bitand other.m_value);
        }

        [[nodiscard]] constexpr auto operator bitor(const s32 other) const noexcept -> s32
        {
            return s32 lucy_unsafe(m_value bitor other.m_value);
        }

        [[nodiscard]] constexpr auto operator xor(const s32 other) const noexcept -> s32
        {
            return s32 lucy_unsafe(m_value xor other.m_value);
        }

        [[nodiscard]] constexpr auto operator<<(const u8 shifts) const noexcept -> s32
        {
            return s32 lucy_unsafe(m_value << shifts.Value());
        }

        [[nodiscard]] constexpr auto operator>>(const u8 shifts) const noexcept -> s32
        {
            return s32 lucy_unsafe(m_value >> shifts.Value());
        }

        [[nodiscard]] constexpr auto operator+(const s32 other) const noexcept -> s32
        {
            return s32 lucy_unsafe(m_value + other.m_value);
        }

        [[nodiscard]] constexpr auto operator-(const s32 other) const noexcept -> s32
        {
            return s32 lucy_unsafe(m_value - other.m_value);
        }

        [[nodiscard]] constexpr auto operator*(const s32 other) const noexcept -> s32
        {
            return s32 lucy_unsafe(m_value * other.m_value);
        }

        [[nodiscard]] constexpr auto operator/(const s32 other) const noexcept -> s32
        {
            return s32 lucy_unsafe(m_value / other.m_value);
        }

        [[nodiscard]] constexpr auto operator%(const s32 other) const noexcept -> s32
        {
            return s32 lucy_unsafe(m_value % other.m_value);
        }

        [[nodiscard]] constexpr auto Value() const noexcept -> int
        {
            return m_value;
        }
    };

    namespace Literal
    {
        void LiteralIsBiggerThan2147483648() noexcept;

        [[nodiscard]] consteval auto operator ""_s32(const unsigned long long int value) noexcept -> s32
        {
            if(value > 2147483648ull)
                LiteralIsBiggerThan2147483648();
            return s32 lucy_unsafe(static_cast<int>(value));
        }
    }

    [[nodiscard]] constexpr u8::operator s32() const noexcept
    {
        return s32 lucy_unsafe(static_cast<int>(m_value));
    }

    [[nodiscard]] constexpr s8::operator s32() const noexcept
    {
        return s32 lucy_unsafe(static_cast<int>(m_value));
    }

    [[nodiscard]] constexpr u16::operator s32() const noexcept
    {
        return s32 lucy_unsafe(static_cast<int>(m_value));
    }

    [[nodiscard]] constexpr s16::operator s32() const noexcept
    {
        return s32 lucy_unsafe(static_cast<int>(m_value));
    }

    [[nodiscard]] constexpr f16::operator s32() const noexcept
    {
        return s32 lucy_unsafe(static_cast<int>(m_value));
    }

    [[nodiscard]] constexpr u32::operator s32() const noexcept
    {
        return s32 lucy_unsafe(static_cast<int>(m_value));
    }
}

#endif
#endif