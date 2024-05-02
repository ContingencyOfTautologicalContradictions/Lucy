export module Lucy.Meta.RemoveRvalueReference;

namespace Detail
{
    template<class T> class RemoveRvalueReference
    {
    public:
        using Type = T;
    };

    template<class T> class RemoveRvalueReference<T&&>
    {
    public:
        using Type = T;
    };
}

export template<class Type> using RemoveRvalueReference = Detail::RemoveRvalueReference<Type>::Type;