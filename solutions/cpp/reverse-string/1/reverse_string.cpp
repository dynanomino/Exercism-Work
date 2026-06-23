#include "reverse_string.h"
#include <iostream>

namespace reverse_string {

    std::string reverse_string( std::string input ){

        //two pointers at the start and end, with each replacing the contents of the other
        auto start { input.begin() };
        auto end { --input.end() };

        while (start < end){

            std::string temp {*start};
            *start = *end;
            *end = *(temp.begin());

            start++;
            end--;
        }

        return input;
    }
}
