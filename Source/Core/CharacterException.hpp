#ifndef lucy_core_character_exception
#define lucy_core_character_exception
#include "Exception.hpp"

namespace Lucy
{
    lucy_exception CharacterException
    {
        lucy_anomaly<1ul> NotLowercase;

        lucy_anomaly<2ul> NotUppercase;
    };
}

#endif