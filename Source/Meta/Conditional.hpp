#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_meta_conditional
#define lucy_meta_conditional

namespace Lucy::Meta
{
    namespace Detail
    {
        template<bool, class, class T> class Condition
        {
        public:
            using Type = T;
        };

        template<class T, class U> class Condition<true, T, U>
        {
        public:
            using Type = T;
        };
    }

    template<bool Condition, class T, class U> using Conditional = Detail::Condition<Condition, T, U>::Type;
}

#endif
#endif