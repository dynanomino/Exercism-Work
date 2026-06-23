#pragma once
#include <algorithm>
#include <string>
#include <math.h>

namespace armstrong_numbers {

    int recursive_add( std::string all_digits, int og_length);
    
    bool is_armstrong_number(int num);

}  // namespace armstrong_numbers
