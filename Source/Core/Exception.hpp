#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_exception
#define lucy_core_exception
#include "Abort.hpp"
#include "Forward.hpp"
#include "../Meta/Void.hpp"
#define lucy_exception struct
#define lucy_anomaly static constexpr ::Lucy::Detail::Anomaly<__COUNTER__>
#define lucy_record if([[maybe_unused]] ::Lucy::Detail::Exception exception_object_private_secret; true)
#define lucy_throwable(...) ([[maybe_unused]] ::Lucy::Detail::Exception& exception_object_private_secret __VA_OPT__(,) __VA_ARGS__)
#define lucy_subscript_detect(...) [exception_object_private_secret.Detect() __VA_OPT__(,) __VA_ARGS__]
#define lucy_braced_detect(...) {exception_object_private_secret.Detect() __VA_OPT__(,) __VA_ARGS__}
#define lucy_detect(...) (exception_object_private_secret.Detect() __VA_OPT__(,) __VA_ARGS__)
#define lucy_unwind do if(exception_object_private_secret.Unwind()) return; while(false)
#define lucy_try exception_object_private_secret = [&]
#define lucy_throw(anomaly, ...) do {exception_object_private_secret = anomaly; return __VA_ARGS__;} while(false)
#define lucy_rethrow exception_object_private_secret =
#define lucy_catch(...) if(exception_object_private_secret.CheckCatch() and exception_object_private_secret.Catch(__VA_ARGS__))
#define lucy_any if(exception_object_private_secret.Any())
#define lucy_finally if(exception_object_private_secret.Finally(); true)

namespace Lucy::Detail
{
    static constexpr auto MaybeZero = __COUNTER__;

    template<class Block> concept TryBlock = requires(Block&& block)
    {
        {block()} -> Meta::Void;
    };

    template<unsigned int value> requires(value > 0ul) class [[nodiscard]] Anomaly final
    {
    public:
        constexpr ~Anomaly() noexcept = default;

        constexpr Anomaly() noexcept = default;

        constexpr Anomaly(const Anomaly&) noexcept = default;

        constexpr Anomaly(Anomaly&&) noexcept = delete;

        constexpr auto operator=(const Anomaly&) noexcept -> Anomaly& = delete;

        constexpr auto operator=(Anomaly&&) noexcept -> Anomaly& = delete;
    };

    enum class State : unsigned char
    {
        Idle,
        Trying,
        Catched,
        Thrown,
        Rethrown
    };

    class [[nodiscard]] Exception final
    {
        using enum State;

        unsigned int m_code = 0ul;

        State m_state = Idle;
        #define lmao pepe_##__COUNTER__:;
    public:
        constexpr ~Exception() noexcept
        {
            if(m_state == Thrown or m_state == Rethrown)
                Abort();
        }

        constexpr Exception() noexcept = default;

        constexpr Exception(const Exception&) noexcept = delete;

        constexpr Exception(Exception&&) noexcept = delete;

        constexpr auto operator=(const Exception&) noexcept -> Exception& = delete;

        constexpr auto operator=(Exception&&) noexcept -> Exception& = delete;

        constexpr auto operator=(const TryBlock auto&& block) noexcept -> void
        {
            if(m_state == Thrown or m_state == Rethrown)
                Abort();
            m_state = Trying;
            block();
        }

        [[nodiscard]] constexpr auto Detect() noexcept -> Exception&
        {
            if(m_state not_eq Trying)
                Abort();
            return *this;
        }

        [[nodiscard]] constexpr auto Unwind() const noexcept -> bool
        {
            return m_state == Thrown or m_state == Rethrown;
        }

        [[nodiscard]] constexpr auto CheckCatch() const noexcept -> bool
        {
            if(m_state == Idle)
                Abort();
            return m_state == Thrown;
        }

        template<unsigned int value> constexpr auto operator=(Anomaly<value>) noexcept -> void
        {
            if(m_state == Idle or m_state == Thrown or m_state == Rethrown)
                Abort();
            m_state = m_state == Catched ? Rethrown : Thrown;
            m_code = value;
        }

        template<unsigned int value> [[nodiscard]] constexpr auto Catch(Anomaly<value>) noexcept -> bool
        {
            if(m_code == value)
            {
                m_state = Catched;
                return true;
            }
            return false;
        }

        template<unsigned int value, unsigned int... values> [[nodiscard]] constexpr auto Catch(Anomaly<value>, Anomaly<values>&&... anomalies) noexcept -> bool
        {
            if(m_code == value)
            {
                m_state = Catched;
                return true;
            }
            return Catch(lucy_forward(anomalies)...);
        }

        [[nodiscard]] constexpr auto Any() noexcept -> bool
        {
            switch(m_state)
            {
                case Thrown:
                    m_state = Catched;
                    return true;
                default:
                    return false;
                case Idle:
                    Abort();
            }
        }

        constexpr auto Finally() noexcept -> void
        {
            switch(m_state)
            {
                case Idle:
                case Thrown:
                    Abort();
                case Rethrown:
                    m_state = Thrown;
                break;
                default:
                    m_state = Idle;
            }
        }
    };
}

#endif
#endif