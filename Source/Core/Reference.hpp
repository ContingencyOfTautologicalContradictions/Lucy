#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_reference
#define lucy_core_reference

namespace Lucy
{
    template<class T> class [[nodiscard]] Reference
    {
        T& m_reference;
    public:
        constexpr ~Reference() noexcept = default;

        constexpr Reference() noexcept = delete;

        constexpr Reference(const Reference<T>& other) noexcept = delete;

        constexpr Reference(Reference<T>&& other) noexcept = delete;

        constexpr auto operator=(const Reference<T>& other) noexcept -> Reference<T>& = delete;

        constexpr auto operator=(Reference<T>&& other) noexcept -> Reference<T>& = delete;

        constexpr Reference(T& object) noexcept : m_reference(object){}

        constexpr auto operator=(T& object) noexcept -> Reference<T>&
        {
            m_reference = object;
            return *this;
        }

        [[nodiscard]] constexpr auto Object() const noexcept -> const T&
        {
            return m_reference;
        }

        [[nodiscard]] constexpr auto Object() noexcept -> T&
        {
            return m_reference;
        }
    };
}

#endif
#endif