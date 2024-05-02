export module Lucy.Meta.Void;

namespace Detail
{
    template<class> class Void
    {
    public:
        static consteval bool Value()
        {
            return false;
        }
    };

    template<> class Void<void>
    {
    public:
        static consteval bool Value()
        {
            return true;
        }
    };

    template<> class Void<const void>
    {
    public:
        static consteval bool Value()
        {
            return true;
        }
    };

    template<> class Void<volatile void>
    {
    public:
        static consteval bool Value()
        {
            return true;
        }
    };

    template<> class Void<const volatile void>
    {
    public:
        static consteval bool Value()
        {
            return true;
        }
    };
}

export template<class Type> concept Void = Detail::Void<Type>::Value();

export template<class Type> concept NotVoid = not Detail::Void<Type>::Value();