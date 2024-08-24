#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_meta_convertible
#define lucy_meta_convertible

namespace Lucy::Meta
{
    template<class From, class To> concept Convertible = __is_convertible(From, To);

    template<class From, class To> concept NotConvertible = not __is_convertible(From, To);
}

#endif
#endif