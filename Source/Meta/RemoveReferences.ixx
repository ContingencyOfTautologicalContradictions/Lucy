export module Lucy.Meta.RemoveReferences;

namespace Detail
{
    template<class T> class RemoveReferences
    {
    public:
        using Type = T;
    };

    template<class T> class RemoveReferences<T&>
    {
    public:
        using Type = T;
    };

    template<class T> class RemoveReferences<T&&>
    {
    public:
        using Type = T;
    };
}

export template<class T> using RemoveReferences = Detail::RemoveReferences<T>::Type;