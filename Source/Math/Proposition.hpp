#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_math_proposition
#define lucy_math_proposition
#include "../Core/Size.hpp"
#include "../Core/BitCast.hpp"

namespace Lucy::Math
{
    template<Size arity = 1> requires(arity > 0) class [[nodiscard]] Proposition
    {
        bool m_value;
    public:
        [[nodiscard]] static consteval auto Arity() noexcept -> Size
        {
            return arity;
        }

        [[nodiscard]] static consteval auto Atomic() noexcept -> bool
        {
            return arity == 1;
        }

        [[nodiscard]] static consteval auto Compound() noexcept -> bool
        {
            return arity > 1;
        }

        inline constexpr ~Proposition() noexcept = default;

        inline constexpr Proposition() noexcept = delete;

        inline constexpr Proposition(const Proposition& other) noexcept = default;

        inline constexpr Proposition(Proposition&& other) noexcept = default;

        inline constexpr auto operator=(const Proposition& other) noexcept -> Proposition& = delete;

        inline constexpr auto operator=(Proposition&& other) noexcept -> Proposition& = delete;

        [[nodiscard]] inline constexpr auto operator not() const noexcept -> Proposition<arity + 1>
        {
            const bool value(not m_value);
            return BitCast<Proposition<arity + 1>>(value);
        }

        template<Size conjunct_arity> [[nodiscard]] inline constexpr auto operator and(const Proposition<conjunct_arity> conjunct) const noexcept -> Proposition<arity + conjunct_arity + 1>
        {
            const bool value(m_value and conjunct.Value());
            return BitCast<Proposition<arity + conjunct_arity + 1>>(value);
        }

        template<Size disjunct_arity> [[nodiscard]] inline constexpr auto operator or(const Proposition<disjunct_arity> disjunct) const noexcept -> Proposition<arity + disjunct_arity + 1>
        {
            const bool value(m_value or disjunct.Value());
            return BitCast<Proposition<arity + disjunct_arity + 1>>(value);
        }

        template<Size other_arity> [[nodiscard]] inline constexpr auto operator==(const Proposition<other_arity> other) const noexcept -> Proposition<arity + other_arity + 1>
        {
            const bool value(m_value == other.Value());
            return BitCast<Proposition<arity + other_arity + 1>>(value);
        }

        template<Size disjunct_arity> [[nodiscard]] inline constexpr auto MaterialImplication(const Proposition<disjunct_arity> disjunct) const noexcept -> Proposition<arity + disjunct_arity + 1>
        {
            const bool value(not m_value or disjunct.Value());
            return BitCast<Proposition<arity + disjunct_arity + 1>>(value);
        }

        [[nodiscard]] inline constexpr auto Value() const noexcept -> bool
        {
            return m_value;
        }
    };

    [[nodiscard]] consteval auto Tautology() noexcept -> Proposition<>
    {
        const bool value(true);
        return BitCast<Proposition<>>(value);
    }

    [[nodiscard]] consteval auto Contradiction() noexcept -> Proposition<>
    {
        const bool value(false);
        return BitCast<Proposition<>>(value);
    }
}

#endif
#endif