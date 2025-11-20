#include "atbash_cipher.h"

#include <string>
#include <iostream>
#include <chrono>
#include <algorithm>

using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

namespace atbash_cipher {

    // std::string source_after_encode  { "zyxwvutsrqponmlkjihgfedcba" };

// TODO: add your solution here

    int is_a_punctuation(char c){

        if (c == ',' || c == '.' || c == ';' || c == '.' || c == ':' || c == ' '){

            return 1;
        }

        return 0;
    }

    std::string cipher(std::string input, bool is_decode){

        auto t1 = steady_clock::now();

        std::string source { "abcdefghijklmnopqrstuvwxyz" };

        std::string result {};

        std::transform( input.begin(), input.end(), input.begin(), [](char &n){ return std::tolower(n); } );

        int j{0};
        // need to extract each character in the input
        for (int i {}; i < static_cast<int>( input.length() ); i++){

            // anything not part of the source is either a digit or a punctuation mark
            // theoretically, all punctuation marks should be added, have only a subset of them
            if ( source.find(input[i]) == std::string::npos && is_a_punctuation(input[i]) ){
                
                // we found a punctuation mark, which needs to be ignored
                continue;
            }
                // we found either a legit source character, or a digit
                // in the case of a digit, it can't be found in the source
                // we already know a digit isn't a punctuation mark
            else if ( source.find(input[i]) == std::string::npos ){

                if ( j==5 && !is_decode ){

                    result += " ";
                    j=0;
                }

                result += input[i];
            }
                // just a normal letter character here
            else {

                if ( j==5 && !is_decode ){

                    result += " ";
                    j=0;
                }

                // finding the complement
                result += source[ 25 - source.find(input[i]) ];
            }

            j++;
        }

        auto t2 = steady_clock::now();

        duration<double, std::milli> ms_time = t2 - t1;

        // result += "\nTime: " + std::to_string(ms_time.count()) + "\n \n";

        return result;
    }

    // std::string cipher_pointers(std::string input){

    //     auto t1 = steady_clock::now();

    //     std::string result{};

    //     const char* tail { source.c_str() + 25 };

    //     for (int i{}; i < static_cast<int>( input.length() ); i++){

    //         result += *( tail - source.find(input[i]) );

    //     }

    //     auto t2 = steady_clock::now();

    //     duration<double, std::milli> ms_time = t2 - t1;

    //     result += "\nTime: " + std::to_string(ms_time.count()) + "\n \n";

    //     return result;

    // }

    std::string encode(std::string input){

        return cipher(input, false);
    }
    std::string decode(std::string input){

        return cipher(input, true);
    }

}  // namespace atbash_cipher

