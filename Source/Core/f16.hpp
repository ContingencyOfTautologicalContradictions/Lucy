#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_f16
#define lucy_core_f16
#include "s16.hpp"
#include "BitCast.hpp"

namespace Lucy
{
    class [[nodiscard]] f16
    {
        _Float16 m_value;
    public:
        using Native = _Float16;

        [[nodiscard]] static consteval auto Bits() noexcept -> u8
        {
            using namespace ::Lucy::Literal;
            return 16_u8;
        }

        [[nodiscard]] static consteval auto Minimum() noexcept -> f16
        {
            return f16 lucy_unsafe(-65504.f16);
        }

        [[nodiscard]] static consteval auto Maximum() noexcept -> f16
        {
            return f16 lucy_unsafe(65504.f16);
        }

        constexpr ~f16() noexcept = default;

        constexpr f16() noexcept : m_value(0.f16){}

        constexpr f16(const f16& other) noexcept = default;

        constexpr f16(f16&& other) noexcept = default;

        constexpr auto operator=(const f16& other) noexcept -> f16& = default;

        constexpr auto operator=(f16&& other) noexcept -> f16& = default;

        constexpr f16 lucy_unreliable() noexcept{}

        constexpr f16 lucy_unreliable(const _Float16 value) noexcept : m_value(value){}

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

        [[nodiscard]] explicit constexpr operator u32() const noexcept;

        [[nodiscard]] explicit constexpr operator s32() const noexcept;

        [[nodiscard]] explicit constexpr operator f32() const noexcept;

        [[nodiscard]] explicit constexpr operator u64() const noexcept;

        [[nodiscard]] explicit constexpr operator s64() const noexcept;

        [[nodiscard]] explicit constexpr operator f64() const noexcept;

        [[nodiscard]] constexpr auto operator+() const noexcept -> f16
        {
            return f16 lucy_unsafe(m_value);
        }

        [[nodiscard]] constexpr auto operator-() const noexcept -> f16
        {
            return f16 lucy_unsafe(-m_value);
        }

        constexpr auto operator++() noexcept -> f16&
        {
            ++m_value;
            return *this;
        }

        constexpr auto operator++(int) noexcept -> f16
        {
            return f16 lucy_unsafe(m_value++);
        }

        constexpr auto operator--() noexcept -> f16&
        {
            --m_value;
            return *this;
        }

        constexpr auto operator--(int) noexcept -> f16
        {
            return f16 lucy_unsafe(m_value--);
        }

        [[nodiscard]] constexpr auto operator==(const f16 other) const noexcept -> bool
        {
            return m_value == other.m_value;
        }

        [[nodiscard]] constexpr auto operator not_eq(const f16 other) const noexcept -> bool
        {
            return m_value not_eq other.m_value;
        }

        [[nodiscard]] constexpr auto operator<(const f16 other) const noexcept -> bool
        {
            return m_value < other.m_value;
        }

        [[nodiscard]] constexpr auto operator>(const f16 other) const noexcept -> bool
        {
            return m_value > other.m_value;
        }

        [[nodiscard]] constexpr auto operator<=(const f16 other) const noexcept -> bool
        {
            return m_value <= other.m_value;
        }

        [[nodiscard]] constexpr auto operator>=(const f16 other) const noexcept -> bool
        {
            return m_value >= other.m_value;
        }

        [[nodiscard]] constexpr auto operator<=>(const f16 other) const noexcept -> Comparison
        {
            using enum Comparison;
            if(m_value < other.m_value)
                return Lesser;
            else if(m_value > other.m_value)
                return Greater;
            return Equal;
        }

        constexpr auto operator and_eq(const f16 other) noexcept -> f16&
        {
            const unsigned short value(BitCast<unsigned short>(m_value) bitand BitCast<unsigned short>(other.m_value));
            m_value = BitCast<_Float16>(value);
            return *this;
        }

        constexpr auto operator or_eq(const f16 other) noexcept -> f16&
        {
            const unsigned short value(BitCast<unsigned short>(m_value) bitor BitCast<unsigned short>(other.m_value));
            m_value = BitCast<_Float16>(value);
            return *this;
        }

        constexpr auto operator xor_eq(const f16 other) noexcept -> f16&
        {
            const unsigned short value(BitCast<unsigned short>(m_value) xor BitCast<unsigned short>(other.m_value));
            m_value = BitCast<_Float16>(value);
            return *this;
        }

        constexpr auto operator<<=(const u8 shifts) noexcept -> f16&
        {
            const unsigned short value(BitCast<unsigned short>(m_value) << shifts.Value());
            m_value = BitCast<_Float16>(value);
            return *this;
        }

        constexpr auto operator>>=(const u8 shifts) noexcept -> f16&
        {
            const unsigned short value(BitCast<unsigned short>(m_value) >> shifts.Value());
            m_value = BitCast<_Float16>(value);
            return *this;
        }

        constexpr auto operator+=(const f16 other) noexcept -> f16&
        {
            m_value += other.m_value;
            return *this;
        }

        constexpr auto operator-=(const f16 other) noexcept -> f16&
        {
            m_value -= other.m_value;
            return *this;
        }

        constexpr auto operator*=(const f16 other) noexcept -> f16&
        {
            m_value *= other.m_value;
            return *this;
        }

        constexpr auto operator/=(const f16 other) noexcept -> f16&
        {
            m_value /= other.m_value;
            return *this;
        }

        constexpr auto operator%=(const f16 other) noexcept -> f16&
        {
            m_value -= static_cast<_Float16>(static_cast<int>(m_value / other.m_value)) * other.m_value;
            return *this;
        }

        [[nodiscard]] constexpr auto operator compl() const noexcept -> f16
        {
            const unsigned short value(compl BitCast<unsigned short>(m_value));
            return f16 lucy_unsafe(BitCast<_Float16>(value));
        }

        [[nodiscard]] constexpr auto operator bitand(const f16 other) const noexcept -> f16
        {
            const unsigned short value(BitCast<unsigned short>(m_value) bitand BitCast<unsigned short>(other.m_value));
            return f16 lucy_unsafe(BitCast<_Float16>(value));
        }

        [[nodiscard]] constexpr auto operator bitor(const f16 other) const noexcept -> f16
        {
            const unsigned short value(BitCast<unsigned short>(m_value) bitor BitCast<unsigned short>(other.m_value));
            return f16 lucy_unsafe(BitCast<_Float16>(value));
        }

        [[nodiscard]] constexpr auto operator xor(const f16 other) const noexcept -> f16
        {
            const unsigned short value(BitCast<unsigned short>(m_value) xor BitCast<unsigned short>(other.m_value));
            return f16 lucy_unsafe(BitCast<_Float16>(value));
        }

        [[nodiscard]] constexpr auto operator<<(const u8 shifts) const noexcept -> f16
        {
            const unsigned short value(BitCast<unsigned short>(m_value) << shifts.Value());
            return f16 lucy_unsafe(BitCast<_Float16>(value));
        }

        [[nodiscard]] constexpr auto operator>>(const u8 shifts) const noexcept -> f16
        {
            const unsigned short value(BitCast<unsigned short>(m_value) >> shifts.Value());
            return f16 lucy_unsafe(BitCast<_Float16>(value));
        }

        [[nodiscard]] constexpr auto operator+(const f16 other) const noexcept -> f16
        {
            return f16 lucy_unsafe(m_value + other.m_value);
        }

        [[nodiscard]] constexpr auto operator-(const f16 other) const noexcept -> f16
        {
            return f16 lucy_unsafe(m_value - other.m_value);
        }

        [[nodiscard]] constexpr auto operator*(const f16 other) const noexcept -> f16
        {
            return f16 lucy_unsafe(m_value * other.m_value);
        }

        [[nodiscard]] constexpr auto operator/(const f16 other) const noexcept -> f16
        {
            return f16 lucy_unsafe(m_value / other.m_value);
        }

        [[nodiscard]] constexpr auto operator%(const f16 other) const noexcept -> f16
        {
            return f16 lucy_unsafe(m_value - static_cast<_Float16>(static_cast<int>(m_value / other.m_value)) * other.m_value);
        }

        [[nodiscard]] constexpr auto Value() const noexcept -> _Float16
        {
            return m_value;
        }
    };

    namespace Literal
    {
        void LiteralIsBiggerThan65504() noexcept;

        [[nodiscard]] consteval auto operator ""_f16(const long double value) noexcept -> f16
        {
            if(value > 65504.)
                LiteralIsBiggerThan65504();
            return f16 lucy_unsafe(static_cast<_Float16>(value));
        }
    }

    [[nodiscard]] constexpr u8::operator f16() const noexcept
    {
        return f16 lucy_unsafe(static_cast<_Float16>(m_value));
    }

    [[nodiscard]] constexpr s8::operator f16() const noexcept
    {
        return f16 lucy_unsafe(static_cast<_Float16>(m_value));
    }

    [[nodiscard]] constexpr u16::operator f16() const noexcept
    {
        return f16 lucy_unsafe(static_cast<_Float16>(m_value));
    }

    [[nodiscard]] constexpr s16::operator f16() const noexcept
    {
        return f16 lucy_unsafe(static_cast<_Float16>(m_value));
    }
}

#endif
#endif