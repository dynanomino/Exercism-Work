#include "armstrong_numbers.h"
#include <iostream>

namespace armstrong_numbers {

    int recursive_add (std::string all_digits, int og_length){

        if (all_digits.length() != 1){ 

            return pow( static_cast<int>(all_digits[0]) - 48, og_length ) + recursive_add(all_digits.substr(1, all_digits.length() - 1), og_length);
        
        } else {

            return pow( static_cast<int>(all_digits[0]) - 48, og_length );
        }
    }

    bool is_armstrong_number(int num){

        // easier to handle this if you convert to a string first
        std::string num_str { std::to_string(num) };

        int sum { recursive_add(num_str, num_str.length()) };

        return sum == num;
    }
}
