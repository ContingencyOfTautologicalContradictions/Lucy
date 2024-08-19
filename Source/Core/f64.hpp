#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_f64
#define lucy_core_f64
#include "s64.hpp"

namespace Lucy
{
    class [[nodiscard]] f64
    {
        double m_value;
    public:
        using Native = double;

        [[nodiscard]] static consteval auto Bits() noexcept -> u8
        {
            using namespace ::Lucy::Literal;
            return 64_u8;
        }

        [[nodiscard]] static consteval auto Minimum() noexcept -> f64
        {
            return f64 lucy_unsafe(-1.7976931348623157e+308);
        }

        [[nodiscard]] static consteval auto Maximum() noexcept -> f64
        {
            return f64 lucy_unsafe(1.7976931348623157e+308);
        }

        constexpr ~f64() noexcept = default;

        constexpr f64() noexcept : m_value(0.){}

        constexpr f64(const f64& other) noexcept = default;

        constexpr f64(f64&& other) noexcept = default;

        constexpr auto operator=(const f64& other) noexcept -> f64& = default;

        constexpr auto operator=(f64&& other) noexcept -> f64& = default;

        constexpr f64 lucy_unreliable() noexcept{}

        constexpr f64 lucy_unreliable(const double value) noexcept : m_value(value){}

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

        [[nodiscard]] explicit constexpr operator s64() const noexcept
        {
            return s64 lucy_unsafe(static_cast<long long int>(m_value));
        }

        [[nodiscard]] constexpr auto operator+() const noexcept -> f64
        {
            return f64 lucy_unsafe(m_value);
        }

        [[nodiscard]] constexpr auto operator-() const noexcept -> f64
        {
            return f64 lucy_unsafe(-m_value);
        }

        constexpr auto operator++() noexcept -> f64&
        {
            ++m_value;
            return *this;
        }

        constexpr auto operator++(int) noexcept -> f64
        {
            return f64 lucy_unsafe(m_value++);
        }

        constexpr auto operator--() noexcept -> f64&
        {
            --m_value;
            return *this;
        }

        constexpr auto operator--(int) noexcept -> f64
        {
            return f64 lucy_unsafe(m_value--);
        }

        [[nodiscard]] constexpr auto operator==(const f64 other) const noexcept -> bool
        {
            return m_value == other.m_value;
        }

        [[nodiscard]] constexpr auto operator not_eq(const f64 other) const noexcept -> bool
        {
            return m_value not_eq other.m_value;
        }

        [[nodiscard]] constexpr auto operator<(const f64 other) const noexcept -> bool
        {
            return m_value < other.m_value;
        }

        [[nodiscard]] constexpr auto operator>(const f64 other) const noexcept -> bool
        {
            return m_value > other.m_value;
        }

        [[nodiscard]] constexpr auto operator<=(const f64 other) const noexcept -> bool
        {
            return m_value <= other.m_value;
        }

        [[nodiscard]] constexpr auto operator>=(const f64 other) const noexcept -> bool
        {
            return m_value >= other.m_value;
        }

        [[nodiscard]] constexpr auto operator<=>(const f64 other) const noexcept -> Comparison
        {
            using enum Comparison;
            if(m_value < other.m_value)
                return Lesser;
            else if(m_value > other.m_value)
                return Greater;
            return Equal;
        }

        constexpr auto operator and_eq(const f64 other) noexcept -> f64&
        {
            const unsigned long long int value(BitCast<unsigned long long int>(m_value) bitand BitCast<unsigned long long int>(other.m_value));
            m_value = BitCast<double>(value);
            return *this;
        }

        constexpr auto operator or_eq(const f64 other) noexcept -> f64&
        {
            const unsigned long long int value(BitCast<unsigned long long int>(m_value) bitor BitCast<unsigned long long int>(other.m_value));
            m_value = BitCast<double>(value);
            return *this;
        }

        constexpr auto operator xor_eq(const f64 other) noexcept -> f64&
        {
            const unsigned long long int value(BitCast<unsigned long long int>(m_value) xor BitCast<unsigned long long int>(other.m_value));
            m_value = BitCast<double>(value);
            return *this;
        }

        constexpr auto operator<<=(const u8 shifts) noexcept -> f64&
        {
            const unsigned long long int value(BitCast<unsigned long long int>(m_value) << shifts.Value());
            m_value = BitCast<double>(value);
            return *this;
        }

        constexpr auto operator>>=(const u8 shifts) noexcept -> f64&
        {
            const unsigned long long int value(BitCast<unsigned long long int>(m_value) >> shifts.Value());
            m_value = BitCast<double>(value);
            return *this;
        }

        constexpr auto operator+=(const f64 other) noexcept -> f64&
        {
            m_value += other.m_value;
            return *this;
        }

        constexpr auto operator-=(const f64 other) noexcept -> f64&
        {
            m_value -= other.m_value;
            return *this;
        }

        constexpr auto operator*=(const f64 other) noexcept -> f64&
        {
            m_value *= other.m_value;
            return *this;
        }

        constexpr auto operator/=(const f64 other) noexcept -> f64&
        {
            m_value /= other.m_value;
            return *this;
        }

        inline auto operator%=(const f64 other) noexcept -> f64&
        {
            m_value -= __builtin_fmod(m_value, other.m_value);
            return *this;
        }

        [[nodiscard]] constexpr auto operator compl() const noexcept -> f64
        {
            const unsigned long long int value(compl BitCast<unsigned long long int>(m_value));
            return f64 lucy_unsafe(BitCast<double>(value));
        }

        [[nodiscard]] constexpr auto operator bitand(const f64 other) const noexcept -> f64
        {
            const unsigned long long int value(BitCast<unsigned long long int>(m_value) bitand BitCast<unsigned long long int>(other.m_value));
            return f64 lucy_unsafe(BitCast<double>(value));
        }

        [[nodiscard]] constexpr auto operator bitor(const f64 other) const noexcept -> f64
        {
            const unsigned long long int value(BitCast<unsigned long long int>(m_value) bitor BitCast<unsigned long long int>(other.m_value));
            return f64 lucy_unsafe(BitCast<double>(value));
        }

        [[nodiscard]] constexpr auto operator xor(const f64 other) const noexcept -> f64
        {
            const unsigned long long int value(BitCast<unsigned long long int>(m_value) xor BitCast<unsigned long long int>(other.m_value));
            return f64 lucy_unsafe(BitCast<double>(value));
        }

        [[nodiscard]] constexpr auto operator<<(const u8 shifts) const noexcept -> f64
        {
            const unsigned long long int value(BitCast<unsigned long long int>(m_value) << shifts.Value());
            return f64 lucy_unsafe(BitCast<double>(value));
        }

        [[nodiscard]] constexpr auto operator>>(const u8 shifts) const noexcept -> f64
        {
            const unsigned long long int value(BitCast<unsigned long long int>(m_value) >> shifts.Value());
            return f64 lucy_unsafe(BitCast<double>(value));
        }

        [[nodiscard]] constexpr auto operator+(const f64 other) const noexcept -> f64
        {
            return f64 lucy_unsafe(m_value + other.m_value);
        }

        [[nodiscard]] constexpr auto operator-(const f64 other) const noexcept -> f64
        {
            return f64 lucy_unsafe(m_value - other.m_value);
        }

        [[nodiscard]] constexpr auto operator*(const f64 other) const noexcept -> f64
        {
            return f64 lucy_unsafe(m_value * other.m_value);
        }

        [[nodiscard]] constexpr auto operator/(const f64 other) const noexcept -> f64
        {
            return f64 lucy_unsafe(m_value / other.m_value);
        }

        [[nodiscard]] inline auto operator%(const f64 other) const noexcept -> f64
        {
            return f64 lucy_unsafe(__builtin_fmod(m_value, other.m_value));
        }

        [[nodiscard]] constexpr auto Value() const noexcept -> double
        {
            return m_value;
        }
    };

    namespace Literal
    {
        void LiteralIsBiggerThan1dot7976931348623157e308() noexcept;

        [[nodiscard]] consteval auto operator ""_f64(const long double value) noexcept -> f64
        {
            if(value > 1.7976931348623157e+308)
                LiteralIsBiggerThan1dot7976931348623157e308();
            return f64 lucy_unsafe(static_cast<double>(value));
        }
    }

    [[nodiscard]] constexpr u8::operator f64() const noexcept
    {
        return f64 lucy_unsafe(static_cast<double>(m_value));
    }

    [[nodiscard]] constexpr s8::operator f64() const noexcept
    {
        return f64 lucy_unsafe(static_cast<double>(m_value));
    }

    [[nodiscard]] constexpr u16::operator f64() const noexcept
    {
        return f64 lucy_unsafe(static_cast<double>(m_value));
    }

    [[nodiscard]] constexpr s16::operator f64() const noexcept
    {
        return f64 lucy_unsafe(static_cast<double>(m_value));
    }

    [[nodiscard]] constexpr f16::operator f64() const noexcept
    {
        return f64 lucy_unsafe(static_cast<double>(m_value));
    }

    [[nodiscard]] constexpr u32::operator f64() const noexcept
    {
        return f64 lucy_unsafe(static_cast<double>(m_value));
    }

    [[nodiscard]] constexpr s32::operator f64() const noexcept
    {
        return f64 lucy_unsafe(static_cast<double>(m_value));
    }

    [[nodiscard]] constexpr f32::operator f64() const noexcept
    {
        return f64 lucy_unsafe(static_cast<double>(m_value));
    }

    [[nodiscard]] constexpr u64::operator f64() const noexcept
    {
        return f64 lucy_unsafe(static_cast<double>(m_value));
    }

    [[nodiscard]] constexpr s64::operator f64() const noexcept
    {
        return f64 lucy_unsafe(static_cast<double>(m_value));
    }
}

#endif
#endif