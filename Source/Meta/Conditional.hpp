#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_meta_conditional
#define lucy_meta_conditional

namespace Lucy::Meta
{
    namespace Detail
    {
        template<class, class T, bool> class Condition
        {
        public:
            using Type = T;
        };

        template<class T, class U> class Condition<T, U, true>
        {
        public:
            using Type = T;
        };
    }

    template<class T, class U, bool Condition> using Conditional = Detail::Condition<T, U, Condition>::Type;
}

#endif
#endif