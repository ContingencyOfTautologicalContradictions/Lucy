export module Lucy.Core.Unsafe;
import Lucy.Core.Forward;

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

export template<class T> class [[nodiscard]] PackedUnsafe
{
public:
    T instance;

    template<class U> constexpr PackedUnsafe(U&& forwarded) noexcept : instance(Forward<U>(forwarded)){}
};