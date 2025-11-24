#include "luhn.h"
#include <iostream>

namespace luhn {

    bool valid(std::string input){

        //first, remove the spaces if any
        while (input.find(" ") != std::string::npos){

            // if the space is at the start, then the substring uses the next index upto length-1
            // if the space is not at the start:
            // 1.   get a substring of index 0 upto space_index-1
            // 2.   get a substring of index space_index+1 upto length
            // 3.   combine the substrings

            if (input.find(" ") == 0){

                input = input.substr(1, input.length() - 1);
            } else {

                input = input.substr(0, input.find(" ")) + input.substr(input.find(" ") + 1, input.length() - 1);
            }
        }

        //then, check for any character that's not an integer
        for (long unsigned int i{}; i<input.length(); i++){

            // invalid characters will have an ascii value below 48 and above 57 (outside of the inclusive range 0-9)
            if (static_cast<int>(input[i]) < 48 || static_cast<int>(input[i]) > 57){

                return false;
                break;
            } 
        }

        // if the string input is just "0", it's rendered invalid by default
        if (input == "0"){

            return false;
        }
        
        // numbers with an odd length will have the digit 0 appended to it at the start
        // they won't affect Luhn's algorithm, and it allows for a proper pointer termination for the loop
        if ( (input.length() % 2) != 0 ){

            input.insert(0, "0");
        }

        // even lengths will have the pointer terminate at begin() - 2
        // since we have to check every 2 characters, this loop can't be condensed to contain the sum calculation without losing readability
        for( auto cur_num { input.end() - 2 }; cur_num != input.begin() - 2; cur_num -= 2 ){

            int double_check { (static_cast<int>(*cur_num) - 48) * 2 };
            if (double_check > 9){

                double_check -= 9;
            }

            // the ascii conversion needs to be reversed for the doubled result before replacing the string char
            *cur_num = '0' + double_check;
        }

        int luhn_sum {};

        for ( auto cur_num {input.begin()}; cur_num != input.end(); cur_num++){
            
            // perform ascii conversion
            luhn_sum += static_cast<int>(*cur_num) - 48;
        }

        return ( luhn_sum%10 == 0 );
    }
} 
