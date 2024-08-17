#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_unsafe
#define lucy_core_unsafe
#define lucy_unreliable(...) ([[maybe_unused]] ::Lucy::Detail::Unsafe __VA_OPT__(,) __VA_ARGS__)
#define lucy_unsafe(...) (::Lucy::Detail::Unsafe{} __VA_OPT__(,) __VA_ARGS__)

namespace Lucy::Detail
{
    class [[nodiscard]] Unsafe final
    {
    public:
        constexpr ~Unsafe() noexcept = default;

        constexpr Unsafe() noexcept = default;

        constexpr Unsafe(const Unsafe&) noexcept = delete;

        constexpr Unsafe(Unsafe&&) noexcept = delete;

        constexpr auto operator=(const Unsafe&) noexcept -> Unsafe& = delete;

        constexpr auto operator=(Unsafe&&) noexcept -> Unsafe& = delete;
    };
}

#endif
#endif