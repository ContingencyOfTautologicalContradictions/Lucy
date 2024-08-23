#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_meta_same
#define lucy_meta_same

namespace Lucy::Meta
{
    template<class T, class U> concept Same = __is_same(T, U);

    template<class T, class U> concept NotSame = not __is_same(T, U);
}

#endif
#endif