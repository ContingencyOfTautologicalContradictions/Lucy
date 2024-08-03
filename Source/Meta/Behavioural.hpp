#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_meta_behavioural
#define lucy_meta_behavioural
#include "Void.hpp"
#include "../Engine/Behaviour.hpp"

namespace Lucy::Meta
{
    template<class T> concept Behavioural = __is_base_of(Engine::Behaviour, T) and requires(T behaviour)
    {
        {behaviour.Start()} -> Void;
        {behaviour.Update()} -> Void;
        {behaviour.Finish()} -> Void;
    };

    template<class T> concept NotBehavioural = not Behavioural<T>;
}

#endif
#endif