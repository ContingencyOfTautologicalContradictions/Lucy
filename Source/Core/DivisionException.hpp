#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_division_exception
#define lucy_core_division_exception
#include "Exception.hpp"

namespace Lucy
{
    lucy_exception DivisionException
    {
        lucy_anomaly<3ul> DivisorIsZero;
    };
}

#endif
#endif