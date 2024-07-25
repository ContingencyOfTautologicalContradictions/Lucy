#include "Exception.hpp"

namespace Lucy::Detail
{
    constexpr Exception::~Exception() noexcept
    {
        if(m_state == Thrown or m_state == Rethrown)
            Abort();
    }

    constexpr auto Exception::operator=(const TryBlock auto&& block) noexcept -> void
    {
        if(m_state == Thrown or m_state == Rethrown)
            Abort();
        m_state = Trying;
        block();
    }

    [[nodiscard]] constexpr auto Exception::Unwind() const noexcept -> bool
    {
        return m_state == Thrown or m_state == Rethrown;
    }

    [[nodiscard]] constexpr auto Exception::CheckCatch() const noexcept -> bool
    {
        if(m_state == Idle)
            Abort();
        return m_state == Thrown;
    }

    [[nodiscard]] constexpr auto Exception::Any() noexcept -> bool
    {
        switch(m_state)
        {
            case Thrown:
                return true;
            default:
                return false;
            case Idle:
                Abort();
        }
    }

    constexpr auto Exception::Finally() noexcept -> void
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
}