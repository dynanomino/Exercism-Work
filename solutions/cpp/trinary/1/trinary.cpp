#include "trinary.h"
#include <math.h>
#include <string>
#include <iostream>

namespace trinary {

    int to_decimal (std::string trinary_num){

        int power {};
        int decimal {};

        // starting with the pointer at the last char, to follow the proper calculation
        // be mindful that the end iterator points beyond the last character, so we need pre-decrements for the iterators
        for( auto cur_char{ --trinary_num.end() }; cur_char != --trinary_num.begin(); cur_char-- ){
            
            // invalid input would be any character in the string having an ascii value less than 48 or above 50
            // trinary numbers can only be having the digits 0, 1 & 2
            if ( static_cast<int>(*cur_char) < 48 || static_cast<int>(*cur_char) > 50 ){

                std::cout << "Invalid trinary character detected, cannot be converted to an integer";
                decimal = 0;
                break;
            }

            // ascii conversion done by static_cast needs subtraction
            decimal += pow(3, power) * ( static_cast<int>(*cur_char) - 48 );
            power++;
        }

        return decimal;
    }
}