#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_s64
#define lucy_core_s64
#include "u64.hpp"

namespace Lucy
{
    class [[nodiscard]] s64
    {
        long long int m_value;
    public:
        using Native = long long int;

        [[nodiscard]] static consteval auto Bits() noexcept -> u8
        {
            using namespace ::Lucy::Literal;
            return 64_u8;
        }

        [[nodiscard]] static consteval auto Minimum() noexcept -> s64
        {
            return s64 lucy_unsafe(-9223372036854775807ll - 1ll);
        }

        [[nodiscard]] static consteval auto Maximum() noexcept -> s64
        {
            return s64 lucy_unsafe(9223372036854775807ll);
        }

        constexpr ~s64() noexcept = default;

        constexpr s64() noexcept : m_value(0l){}

        constexpr s64(const s64& other) noexcept = default;

        constexpr s64(s64&& other) noexcept = default;

        constexpr auto operator=(const s64& other) noexcept -> s64& = default;

        constexpr auto operator=(s64&& other) noexcept -> s64& = default;

        constexpr s64 lucy_unreliable() noexcept{}

        constexpr s64 lucy_unreliable(const long long int value) noexcept : m_value(value){}

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

        [[nodiscard]] explicit constexpr operator s32() const noexcept
        {
            return s32 lucy_unsafe(static_cast<int>(m_value));
        }

        [[nodiscard]] explicit constexpr operator f32() const noexcept
        {
            return f32 lucy_unsafe(static_cast<float>(m_value));
        }
        
        [[nodiscard]] explicit constexpr operator u64() const noexcept
        {
            return u64 lucy_unsafe(static_cast<unsigned long long int>(m_value));
        }

        [[nodiscard]] explicit constexpr operator f64() const noexcept;

        [[nodiscard]] constexpr auto operator+() const noexcept -> s64
        {
            return s64 lucy_unsafe(m_value);
        }

        [[nodiscard]] constexpr auto operator-() const noexcept -> s64
        {
            return s64 lucy_unsafe(-m_value);
        }

        constexpr auto operator++() noexcept -> s64&
        {
            ++m_value;
            return *this;
        }

        constexpr auto operator++(int) noexcept -> s64
        {
            return s64 lucy_unsafe(m_value++);
        }

        constexpr auto operator--() noexcept -> s64&
        {
            --m_value;
            return *this;
        }

        constexpr auto operator--(int) noexcept -> s64
        {
            return s64 lucy_unsafe(m_value--);
        }

        [[nodiscard]] constexpr auto operator==(const s64 other) const noexcept -> bool
        {
            return m_value == other.m_value;
        }

        [[nodiscard]] constexpr auto operator not_eq(const s64 other) const noexcept -> bool
        {
            return m_value not_eq other.m_value;
        }

        [[nodiscard]] constexpr auto operator<(const s64 other) const noexcept -> bool
        {
            return m_value < other.m_value;
        }

        [[nodiscard]] constexpr auto operator>(const s64 other) const noexcept -> bool
        {
            return m_value > other.m_value;
        }

        [[nodiscard]] constexpr auto operator<=(const s64 other) const noexcept -> bool
        {
            return m_value <= other.m_value;
        }

        [[nodiscard]] constexpr auto operator>=(const s64 other) const noexcept -> bool
        {
            return m_value >= other.m_value;
        }

        [[nodiscard]] constexpr auto operator<=>(const s64 other) const noexcept -> Comparison
        {
            using enum Comparison;
            if(m_value < other.m_value)
                return Lesser;
            else if(m_value > other.m_value)
                return Greater;
            return Equal;
        }

        constexpr auto operator and_eq(const s64 other) noexcept -> s64&
        {
            m_value and_eq other.m_value;
            return *this;
        }

        constexpr auto operator or_eq(const s64 other) noexcept -> s64&
        {
            m_value or_eq other.m_value;
            return *this;
        }

        constexpr auto operator xor_eq(const s64 other) noexcept -> s64&
        {
            m_value xor_eq other.m_value;
            return *this;
        }

        constexpr auto operator<<=(const u8 shifts) noexcept -> s64&
        {
            m_value <<= shifts.Value();
            return *this;
        }

        constexpr auto operator>>=(const u8 shifts) noexcept -> s64&
        {
            m_value >>= shifts.Value();
            return *this;
        }

        constexpr auto operator+=(const s64 other) noexcept -> s64&
        {
            m_value += other.m_value;
            return *this;
        }

        constexpr auto operator-=(const s64 other) noexcept -> s64&
        {
            m_value -= other.m_value;
            return *this;
        }

        constexpr auto operator*=(const s64 other) noexcept -> s64&
        {
            m_value *= other.m_value;
            return *this;
        }

        constexpr auto operator/=(const s64 other) noexcept -> s64&
        {
            m_value /= other.m_value;
            return *this;
        }

        constexpr auto operator%=(const s64 other) noexcept -> s64&
        {
            m_value %= other.m_value;
            return *this;
        }

        [[nodiscard]] constexpr auto operator compl() const noexcept -> s64
        {
            return s64 lucy_unsafe(compl m_value);
        }

        [[nodiscard]] constexpr auto operator bitand(const s64 other) const noexcept -> s64
        {
            return s64 lucy_unsafe(m_value bitand other.m_value);
        }

        [[nodiscard]] constexpr auto operator bitor(const s64 other) const noexcept -> s64
        {
            return s64 lucy_unsafe(m_value bitor other.m_value);
        }

        [[nodiscard]] constexpr auto operator xor(const s64 other) const noexcept -> s64
        {
            return s64 lucy_unsafe(m_value xor other.m_value);
        }

        [[nodiscard]] constexpr auto operator<<(const u8 shifts) const noexcept -> s64
        {
            return s64 lucy_unsafe(m_value << shifts.Value());
        }

        [[nodiscard]] constexpr auto operator>>(const u8 shifts) const noexcept -> s64
        {
            return s64 lucy_unsafe(m_value >> shifts.Value());
        }

        [[nodiscard]] constexpr auto operator+(const s64 other) const noexcept -> s64
        {
            return s64 lucy_unsafe(m_value + other.m_value);
        }

        [[nodiscard]] constexpr auto operator-(const s64 other) const noexcept -> s64
        {
            return s64 lucy_unsafe(m_value - other.m_value);
        }

        [[nodiscard]] constexpr auto operator*(const s64 other) const noexcept -> s64
        {
            return s64 lucy_unsafe(m_value * other.m_value);
        }

        [[nodiscard]] constexpr auto operator/(const s64 other) const noexcept -> s64
        {
            return s64 lucy_unsafe(m_value / other.m_value);
        }

        [[nodiscard]] constexpr auto operator%(const s64 other) const noexcept -> s64
        {
            return s64 lucy_unsafe(m_value % other.m_value);
        }

        [[nodiscard]] constexpr auto Value() const noexcept -> long long int
        {
            return m_value;
        }
    };

    namespace Literal
    {
        void LiteralIsBiggerThan9223372036854775808() noexcept;

        [[nodiscard]] consteval auto operator ""_s64(const unsigned long long int value) noexcept -> s64
        {
            if(value > 9223372036854775808ull)
                LiteralIsBiggerThan9223372036854775808();
            return s64 lucy_unsafe(static_cast<long long int>(value));
        }
    }

    [[nodiscard]] constexpr u8::operator s64() const noexcept
    {
        return s64 lucy_unsafe(static_cast<long long int>(m_value));
    }

    [[nodiscard]] constexpr s8::operator s64() const noexcept
    {
        return s64 lucy_unsafe(static_cast<long long int>(m_value));
    }

    [[nodiscard]] constexpr u16::operator s64() const noexcept
    {
        return s64 lucy_unsafe(static_cast<long long int>(m_value));
    }

    [[nodiscard]] constexpr s16::operator s64() const noexcept
    {
        return s64 lucy_unsafe(static_cast<long long int>(m_value));
    }

    [[nodiscard]] constexpr f16::operator s64() const noexcept
    {
        return s64 lucy_unsafe(static_cast<long long int>(m_value));
    }

    [[nodiscard]] constexpr u32::operator s64() const noexcept
    {
        return s64 lucy_unsafe(static_cast<long long int>(m_value));
    }

    [[nodiscard]] constexpr s32::operator s64() const noexcept
    {
        return s64 lucy_unsafe(static_cast<long long int>(m_value));
    }

    [[nodiscard]] constexpr f32::operator s64() const noexcept
    {
        return s64 lucy_unsafe(static_cast<long long int>(m_value));
    }

    [[nodiscard]] constexpr u64::operator s64() const noexcept
    {
        return s64 lucy_unsafe(static_cast<long long int>(m_value));
    }
}

#endif
#endif