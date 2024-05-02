export module Lucy.Meta.Same;

namespace Detail
{
    template<class, class> class Same
    {
    public:
        static consteval bool Value()
        {
            return false;
        }
    };

    template<class Type> class Same<Type, Type>
    {
    public:
        static consteval bool Value()
        {
            return true;
        }
    };
}

export template<class Type1, class Type2> concept Same = Detail::Same<Type1, Type2>::Value();

export template<class Type1, class Type2> concept NotSame = not Detail::Same<Type1, Type2>::Value();