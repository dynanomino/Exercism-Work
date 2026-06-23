#include "rotational_cipher.h"

#include <regex>
#include <iostream>

namespace rotational_cipher {

    std::string rotate (std::string input, int key){

        if (key < 0 || key > 26){

            return "Error. Key invalid (value must be 0 to 26)";
        }

        std::string source {"abcdefghijklmnopqrstuvwxyz"};

        std::string result {};

        // indicates how far the characters shift to the right
        int shift { (key + 26) % 26 };

        // no shift happens on the character, unusable cipher was given
        if (!shift){

            return input;
        }
        else {

            for (int i{}; i < static_cast<int>( input.size() ); i++){
                
                // if it's not a source character, including capitalised, then keep the input character
                if (source.find(input[i]) == std::string::npos && source.find(std::tolower(input[i])) == std::string::npos) {

                    result += input[i];
                }
                else {

                    //preserving the capitalised case
                    if ( source.find(std::tolower(input[i])) != std::string::npos && source.find(input[i]) == std::string::npos) {

                        result += std::toupper( source.at( (source.find( std::tolower(input[i]) ) + shift) % 26) );
                    }
                    else {
                        
                        result += source.at( (source.find(input[i]) + shift) % 26 );
                    }
                }
            }
        }

        return result;
    }
}

