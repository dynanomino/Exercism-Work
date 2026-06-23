#include "eliuds_eggs.h"
#include <iostream>

namespace chicken_coop {

    int positions_to_quantity (int decimal){

        std::string bin_string {};
        int egg_count {};

        // grab binary representation, count the 1's in the string, return the count
        // do a short circuit for a decimal of 0
        if (!decimal){

            return 0;
        }

        while (decimal != 1){

            bin_string.insert(0, std::to_string(decimal % 2) );
                
            decimal = decimal / 2;

            // can't do a quick boolean using a string value, so a comparison is required
            if( bin_string[0] == '1' ){

                egg_count += 1;
            }
        }

        // just left with the number 1 to be divided, so egg count increments
        return egg_count + 1;
    }
}
