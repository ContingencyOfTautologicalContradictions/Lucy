export module Lucy.Core.Unsafe;

export class [[nodiscard]] Unsafe
{
public:
    constexpr ~Unsafe() noexcept = default;

    constexpr Unsafe() noexcept = default;

    constexpr Unsafe(const Unsafe& other) noexcept = delete;

    constexpr Unsafe(Unsafe&& other) noexcept = delete;

    constexpr auto operator=(const Unsafe& other) noexcept -> Unsafe& = delete;

    constexpr auto operator=(Unsafe&& other) noexcept -> Unsafe& = delete;
};