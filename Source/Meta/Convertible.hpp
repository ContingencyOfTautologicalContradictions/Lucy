#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_meta_convertible
#define lucy_meta_convertible

namespace Lucy::Meta
{
    template<class From, class To> concept Convertible = requires(From from)
    {
        static_cast<To>(from);
    };

    template<class From, class To> concept NotConvertible = not requires(From from)
    {
        static_cast<To>(from);
    };
}

#endif
#endif