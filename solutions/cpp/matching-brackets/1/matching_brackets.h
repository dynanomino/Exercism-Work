#pragma once

#include <string>
#include <vector>

namespace matching_brackets {

    /*
        a string filter method for capturing the string,
        scans for the (, { and [ chars with a count for each,
        and if the count for either of them doesn't reach zero,
        the brackets don't match
    */ 
    bool check(std::string str_to_check);
}
