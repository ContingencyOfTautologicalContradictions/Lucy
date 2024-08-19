#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_f32
#define lucy_core_f32
#include "s32.hpp"

namespace Lucy
{
    class [[nodiscard]] f32
    {
        float m_value;
    public:
        using Native = float;

        [[nodiscard]] static consteval auto Bits() noexcept -> u8
        {
            using namespace ::Lucy::Literal;
            return 32_u8;
        }

        [[nodiscard]] static consteval auto Minimum() noexcept -> f32
        {
            return f32 lucy_unsafe(-3.40282347e38f);
        }

        [[nodiscard]] static consteval auto Maximum() noexcept -> f32
        {
            return f32 lucy_unsafe(3.40282347e38f);
        }

        constexpr ~f32() noexcept = default;

        constexpr f32() noexcept : m_value(0.f){}

        constexpr f32(const f32& other) noexcept = default;

        constexpr f32(f32&& other) noexcept = default;

        constexpr auto operator=(const f32& other) noexcept -> f32& = default;

        constexpr auto operator=(f32&& other) noexcept -> f32& = default;

        constexpr f32 lucy_unreliable() noexcept{}

        constexpr f32 lucy_unreliable(const float value) noexcept : m_value(value){}

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

        [[nodiscard]] explicit constexpr operator u64() const noexcept;

        [[nodiscard]] explicit constexpr operator s64() const noexcept;

        [[nodiscard]] explicit constexpr operator f64() const noexcept;

        [[nodiscard]] constexpr auto operator+() const noexcept -> f32
        {
            return f32 lucy_unsafe(m_value);
        }

        [[nodiscard]] constexpr auto operator-() const noexcept -> f32
        {
            return f32 lucy_unsafe(-m_value);
        }

        constexpr auto operator++() noexcept -> f32&
        {
            ++m_value;
            return *this;
        }

        constexpr auto operator++(int) noexcept -> f32
        {
            return f32 lucy_unsafe(m_value++);
        }

        constexpr auto operator--() noexcept -> f32&
        {
            --m_value;
            return *this;
        }

        constexpr auto operator--(int) noexcept -> f32
        {
            return f32 lucy_unsafe(m_value--);
        }

        [[nodiscard]] constexpr auto operator==(const f32 other) const noexcept -> bool
        {
            return m_value == other.m_value;
        }

        [[nodiscard]] constexpr auto operator not_eq(const f32 other) const noexcept -> bool
        {
            return m_value not_eq other.m_value;
        }

        [[nodiscard]] constexpr auto operator<(const f32 other) const noexcept -> bool
        {
            return m_value < other.m_value;
        }

        [[nodiscard]] constexpr auto operator>(const f32 other) const noexcept -> bool
        {
            return m_value > other.m_value;
        }

        [[nodiscard]] constexpr auto operator<=(const f32 other) const noexcept -> bool
        {
            return m_value <= other.m_value;
        }

        [[nodiscard]] constexpr auto operator>=(const f32 other) const noexcept -> bool
        {
            return m_value >= other.m_value;
        }

        [[nodiscard]] constexpr auto operator<=>(const f32 other) const noexcept -> Comparison
        {
            using enum Comparison;
            if(m_value < other.m_value)
                return Lesser;
            else if(m_value > other.m_value)
                return Greater;
            return Equal;
        }

        constexpr auto operator and_eq(const f32 other) noexcept -> f32&
        {
            const unsigned int value(BitCast<unsigned int>(m_value) bitand BitCast<unsigned int>(other.m_value));
            m_value = BitCast<float>(value);
            return *this;
        }

        constexpr auto operator or_eq(const f32 other) noexcept -> f32&
        {
            const unsigned int value(BitCast<unsigned int>(m_value) bitor BitCast<unsigned int>(other.m_value));
            m_value = BitCast<float>(value);
            return *this;
        }

        constexpr auto operator xor_eq(const f32 other) noexcept -> f32&
        {
            const unsigned int value(BitCast<unsigned int>(m_value) xor BitCast<unsigned int>(other.m_value));
            m_value = BitCast<float>(value);
            return *this;
        }

        constexpr auto operator<<=(const u8 shifts) noexcept -> f32&
        {
            const unsigned int value(BitCast<unsigned int>(m_value) << shifts.Value());
            m_value = BitCast<float>(value);
            return *this;
        }

        constexpr auto operator>>=(const u8 shifts) noexcept -> f32&
        {
            const unsigned int value(BitCast<unsigned int>(m_value) >> shifts.Value());
            m_value = BitCast<float>(value);
            return *this;
        }

        constexpr auto operator+=(const f32 other) noexcept -> f32&
        {
            m_value += other.m_value;
            return *this;
        }

        constexpr auto operator-=(const f32 other) noexcept -> f32&
        {
            m_value -= other.m_value;
            return *this;
        }

        constexpr auto operator*=(const f32 other) noexcept -> f32&
        {
            m_value *= other.m_value;
            return *this;
        }

        constexpr auto operator/=(const f32 other) noexcept -> f32&
        {
            m_value /= other.m_value;
            return *this;
        }

        inline auto operator%=(const f32 other) noexcept -> f32&
        {
            m_value -= __builtin_fmodf(m_value, other.m_value);
            return *this;
        }

        [[nodiscard]] constexpr auto operator compl() const noexcept -> f32
        {
            const unsigned int value(compl BitCast<unsigned int>(m_value));
            return f32 lucy_unsafe(BitCast<float>(value));
        }

        [[nodiscard]] constexpr auto operator bitand(const f32 other) const noexcept -> f32
        {
            const unsigned int value(BitCast<unsigned int>(m_value) bitand BitCast<unsigned int>(other.m_value));
            return f32 lucy_unsafe(BitCast<float>(value));
        }

        [[nodiscard]] constexpr auto operator bitor(const f32 other) const noexcept -> f32
        {
            const unsigned int value(BitCast<unsigned int>(m_value) bitor BitCast<unsigned int>(other.m_value));
            return f32 lucy_unsafe(BitCast<float>(value));
        }

        [[nodiscard]] constexpr auto operator xor(const f32 other) const noexcept -> f32
        {
            const unsigned int value(BitCast<unsigned int>(m_value) xor BitCast<unsigned int>(other.m_value));
            return f32 lucy_unsafe(BitCast<float>(value));
        }

        [[nodiscard]] constexpr auto operator<<(const u8 shifts) const noexcept -> f32
        {
            const unsigned int value(BitCast<unsigned int>(m_value) << shifts.Value());
            return f32 lucy_unsafe(BitCast<float>(value));
        }

        [[nodiscard]] constexpr auto operator>>(const u8 shifts) const noexcept -> f32
        {
            const unsigned int value(BitCast<unsigned int>(m_value) >> shifts.Value());
            return f32 lucy_unsafe(BitCast<float>(value));
        }

        [[nodiscard]] constexpr auto operator+(const f32 other) const noexcept -> f32
        {
            return f32 lucy_unsafe(m_value + other.m_value);
        }

        [[nodiscard]] constexpr auto operator-(const f32 other) const noexcept -> f32
        {
            return f32 lucy_unsafe(m_value - other.m_value);
        }

        [[nodiscard]] constexpr auto operator*(const f32 other) const noexcept -> f32
        {
            return f32 lucy_unsafe(m_value * other.m_value);
        }

        [[nodiscard]] constexpr auto operator/(const f32 other) const noexcept -> f32
        {
            return f32 lucy_unsafe(m_value / other.m_value);
        }

        [[nodiscard]] inline auto operator%(const f32 other) const noexcept -> f32
        {
            return f32 lucy_unsafe(__builtin_fmodf(m_value, other.m_value));
        }

        [[nodiscard]] constexpr auto Value() const noexcept -> float
        {
            return m_value;
        }
    };

    namespace Literal
    {
        void LiteralIsBiggerThan3dot40282347e38() noexcept;

        [[nodiscard]] consteval auto operator ""_f32(const long double value) noexcept -> f32
        {
            if(value > 3.40282347e38)
                LiteralIsBiggerThan3dot40282347e38();
            return f32 lucy_unsafe(static_cast<float>(value));
        }
    }

    [[nodiscard]] constexpr u8::operator f32() const noexcept
    {
        return f32 lucy_unsafe(static_cast<float>(m_value));
    }

    [[nodiscard]] constexpr s8::operator f32() const noexcept
    {
        return f32 lucy_unsafe(static_cast<float>(m_value));
    }

    [[nodiscard]] constexpr u16::operator f32() const noexcept
    {
        return f32 lucy_unsafe(static_cast<float>(m_value));
    }

    [[nodiscard]] constexpr s16::operator f32() const noexcept
    {
        return f32 lucy_unsafe(static_cast<float>(m_value));
    }

    [[nodiscard]] constexpr f16::operator f32() const noexcept
    {
        return f32 lucy_unsafe(static_cast<float>(m_value));
    }

    [[nodiscard]] constexpr u32::operator f32() const noexcept
    {
        return f32 lucy_unsafe(static_cast<float>(m_value));
    }

    [[nodiscard]] constexpr s32::operator f32() const noexcept
    {
        return f32 lucy_unsafe(static_cast<float>(m_value));
    }
}

#endif
#endif