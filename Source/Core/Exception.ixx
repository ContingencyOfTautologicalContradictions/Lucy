export module Lucy.Core.Exception;
import Lucy.Core.Move;
import Lucy.Meta.Same;
import Lucy.Core.Abort;
import Lucy.Core.Forward;
import Lucy.Meta.Underlying;
import std;

template<class T> concept IsAnomaly = Same<Underlying<T>, unsigned short>;

template<class T> concept TryCallable = requires(T fn)
{
    fn();
};

enum class [[nodiscard]] ExceptionState : unsigned char
{
    None = 0,
    Trying = 1,
    Thrown = 2,
    Catched = 3,
    Rethrown = 4
};

export template<IsAnomaly auto code> class [[nodiscard]] reason final
{
public:
    std::string mreason;

    constexpr reason(std::string&& vreason) noexcept : mreason(Forward<std::string>(vreason)){}

    [[nodiscard]] constexpr auto mcode() const noexcept -> auto
    {
        return code;
    }
};

class [[nodiscard]] Exception final
{
    std::string mreason;

    unsigned short code = 0, last_code = 0;

    ExceptionState state = ExceptionState::None;
public:
    constexpr ~Exception() noexcept
    {
        if(state not_eq ExceptionState::None)
            Abort();
    }

    constexpr Exception() noexcept = default;

    constexpr Exception(const Exception& other) noexcept = delete;

    constexpr Exception(Exception&& other) noexcept = delete;

    constexpr auto operator=(const Exception& other) noexcept -> Exception& = delete;

    constexpr auto operator=(Exception&& other) noexcept -> Exception& = delete;

    constexpr auto operator=(const TryCallable auto&& try_block) noexcept -> void
    {
        if(state not_eq ExceptionState::None and state not_eq ExceptionState::Trying)
            Abort();
        state = ExceptionState::Trying;
        try_block();
    }

    constexpr auto operator=(const IsAnomaly auto&& anomaly_value) noexcept -> void
    {
        if(code or not static_cast<unsigned short>(anomaly_value))
            Abort();
        code = static_cast<unsigned short>(anomaly_value);
        state = state == ExceptionState::Catched ? ExceptionState::Rethrown : ExceptionState::Thrown;
    }

    template<IsAnomaly auto value> constexpr auto operator=(reason<value>&& vreason) noexcept -> void
    {
        if(code or not static_cast<unsigned short>(vreason.mcode()))
            Abort();
        mreason = Move(vreason.mreason);
        code = static_cast<unsigned short>(vreason.mcode());
        state = state == ExceptionState::Catched ? ExceptionState::Rethrown : ExceptionState::Thrown;
    }

    [[nodiscard]] constexpr auto Thrown() const noexcept -> bool
    {
        if(state == ExceptionState::None)
            Abort();
        return state == ExceptionState::Thrown;
    }

    [[nodiscard]] constexpr auto Catch(const IsAnomaly auto&& anomaly_value) noexcept -> bool
    {
        if(code == static_cast<unsigned short>(anomaly_value))
        {
            state = ExceptionState::Catched;
            last_code = code;
            code = 0;
            return true;
        }
        return false;
    }

    template<IsAnomaly... Types> [[nodiscard]] constexpr auto Catch(const IsAnomaly auto&& anomaly_value, Types&&... anomalies) noexcept -> bool
    {
        if(code == static_cast<unsigned short>(anomaly_value))
        {
            state = ExceptionState::Catched;
            last_code = code;
            code = 0;
            return true;
        }
        return Catch(Forward<Types>(anomalies)...);
    }

    [[nodiscard]] constexpr auto Any() noexcept -> bool
    {
        switch(state)
        {
            using enum ExceptionState;
            default:
                return false;
            case None:
                Abort();
            case Thrown:
                state = ExceptionState::Catched;
                last_code = code;
                code = 0;
                return true;
        }
    }

    [[nodiscard]] constexpr auto Finally() noexcept -> bool
    {
        switch(state)
        {
            using enum ExceptionState;
            default:
                Abort();
            case Trying:
            case Catched:
                state = None;
                last_code = 0;
            break;
            case Rethrown:
                state = Thrown;
        }
        return true;
    }

    template<IsAnomaly Anomaly> [[nodiscard]] explicit constexpr operator Anomaly() const noexcept
    {
        return static_cast<Anomaly>(last_code);
    }

    [[nodiscard]] constexpr auto Message() const noexcept -> const std::string&
    {
        if(state == ExceptionState::Catched)
            return mreason;
        Abort();
    }
};

export template<class T> class [[nodiscard]] PackedException
{
public:
    Exception& e;

    T instance;

    using type = T;

    template<class U> constexpr PackedException(Exception& ex, U&& forwarded) noexcept : e(ex), instance(Forward<U>(forwarded)){}

    constexpr auto operator=(const IsAnomaly auto&& anomaly) noexcept -> void
    {
        e = Forward<decltype(anomaly)>(anomaly);
    }
};

export constexpr inline bool exception_object_private_and_secret_stub = true;