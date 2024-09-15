#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_meta_trivially_destructible
#define lucy_meta_trivially_destructible

namespace Lucy::Meta
{
    template<class T> concept TriviallyDestructible = __is_trivially_destructible(T);

    template<class T> concept NotTriviallyDestructible = not __is_trivially_destructible(T);
}

#endif
#endif