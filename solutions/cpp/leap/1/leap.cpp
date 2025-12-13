#include "leap.h"

namespace leap {

    bool is_leap_year(int cur_year){

        // this follows the gregorian calendar definition of a leap year
        // leap year happens on mod 4 == 0, or mod 400 AND mod 100

        return (!(cur_year % 4) && ((cur_year % 100) != 0)) || ( (!(cur_year % 400)) && (!(cur_year % 100)) );
    }
}