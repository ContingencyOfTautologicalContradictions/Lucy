#ifndef lucy_core_nullpointer
#define lucy_core_nullpointer
#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1

namespace Lucy
{
    using NullPointer = decltype(nullptr);
}

#endif
#endif