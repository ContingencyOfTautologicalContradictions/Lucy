#ifndef lucy_core_signal
#define lucy_core_signal

namespace Lucy
{
    class [[nodiscard]] Default final
    {
    public:
        inline constexpr ~Default() noexcept = default;

        inline constexpr Default() noexcept = default;

        constexpr Default(const Default&) noexcept = delete;

        constexpr Default(Default&&) noexcept = delete;

        constexpr auto operator=(const Default&) noexcept -> Default& = delete;

        constexpr auto operator=(Default&&) noexcept -> Default& = delete;
    };

    class [[nodiscard]] Ignore final
    {
    public:
        inline constexpr ~Ignore() noexcept = default;

        inline constexpr Ignore() noexcept = default;

        constexpr Ignore(const Ignore&) noexcept = delete;

        constexpr Ignore(Ignore&&) noexcept = delete;

        constexpr auto operator=(const Ignore&) noexcept -> Ignore& = delete;

        constexpr auto operator=(Ignore&&) noexcept -> Ignore& = delete;
    };

    enum class [[nodiscard]] Action : unsigned char
    {
        Abort,
        UnknownInstruction,
        Interruptor,
        Segfault,
        Termination
    };

    auto Signal(Action action, Default) noexcept -> void;

    auto Signal(Action action, Ignore) noexcept -> void;

    auto Signal(Action action, void (*handler)(int)) noexcept -> void;
}

#endif