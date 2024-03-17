#ifndef lucy_meta_nullpointer
#define lucy_meta_nullpointer
#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1

namespace Lucy
{
    /**
    @brief The type of the null pointer literal
    */
    using NullPointer = decltype(nullptr);
}

#endif
#endif