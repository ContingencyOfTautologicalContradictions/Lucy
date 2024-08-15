#if lucy_major >= 0 and lucy_middle >= 0 and lucy_minor >= 1
#ifndef lucy_core_bitshift_exception
#define lucy_core_bitshift_exception
#include "Exception.hpp"

namespace Lucy
{
    lucy_exception BitshiftException
    {
        lucy_anomaly<4ul> NoShifts;

        lucy_anomaly<5ul> MoreThan7Shifts;

        lucy_anomaly<6ul> MoreThan15Shifts;

        lucy_anomaly<7ul> MoreThan31Shifts;
        
        lucy_anomaly<8ul> MoreThan63Shifts;
    };
}

#endif
#endif