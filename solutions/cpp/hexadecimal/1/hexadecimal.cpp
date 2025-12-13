#include "hexadecimal.h"
#include "iostream"
#include <bits/stdc++.h>

// the goal is to not use any library for performing this conversion
namespace hexadecimal {

    // this function assumes positive powers only
    int power(int num1, int num2){

        if (num2 < 0){

            throw std::runtime_error(" Invalid power provided ");
        }

        // multiply num1 with itself, num2 times
        while (num2 > 0){

            return num1 * power(num1, --num2);
        }

        return 1;
    }

    int convert( std::string hex ){

        // need ascii to reject the string upon encountering a character outside of the hex range 0-f (lowercase)
        // when split into two, the valid ascii values are 48 to 57 for 0 to 9, and 97 to 102 for a to f 
        auto cur_char { --hex.end() };

        // the power count is needed for each digit to be converted
        int power {};

        int value {};

        while ( cur_char != --hex.begin() ){

            auto cur_int { static_cast<int>( *cur_char ) };
            
            // the 0-9 digits and a-f digits need their own custom offset when determining the value
            // eventually, the discovery of an invalid number is rejected
            if( ( cur_int >= 48 ) && ( cur_int <= 57 ) )
            {

                value += (cur_int - 48) * hexadecimal::power(16, power);
            } else if ( ( cur_int >= 97 ) && ( cur_int <= 102 ) ){

                value += (cur_int - 97 + 10) * hexadecimal::power(16, power);
            } else {

                return 0;
                break;
            }

            power++;
            cur_char--;
        }
        return value; 
    }

}