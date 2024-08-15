#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_value_exception
#define lucy_core_value_exception
#include "Exception.hpp"

namespace Lucy
{
    lucy_exception ValueException
    {
        lucy_anomaly<1ul> Undervalued;

        lucy_anomaly<2ul> Overvalued;
    };
}

#endif
#endif