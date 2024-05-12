export module Lucy.Meta.RemoveConstant;

namespace Detail
{
    template<class T> class RemoveConstant
    {
    public:
        using Type = T;
    };

    template<class T> class RemoveConstant<const T>
    {
    public:
        using Type = T;
    };
}

export template<class Type> using RemoveConstant = Detail::RemoveConstant<Type>::Type;