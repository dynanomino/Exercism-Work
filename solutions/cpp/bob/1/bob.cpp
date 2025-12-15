#include "bob.h"
#include <algorithm>
#include <iostream>

namespace bob {

    std::string hey (std::string message){

        std::string result {};

        bool is_only_whitespace { false };
        bool is_qs_with_spaces_afterwards { false };

        // to check if every character in the message is a whitespace, an extra loop is required
        // this loop will inform the next filter below it that there's more than just whitespace in the message
        for (long unsigned int i{ }; i < message.length(); i++){

            if( std::isspace(message[i]) != 0 ){
                
                // if only whitespace was encountered with the last index being reached, the flag becomes true
                if (i == ( message.length() - 1 )){

                    is_only_whitespace = true;
                }
                continue;

            } else {

                // the loop needs a short circuit for anything other than a whitespace being encountered
                break;
            }
        }

        // to check if the LAST question mark in the message is followed by only whitespace afterwards, making it a valid question
        for (long unsigned int i { message.find_last_of('?') }; i < message.length(); i++){

            if( (i + 1) <= (message.length() - 1) ){

                if( std::isspace(message[i + 1]) != 0 ){

                    //space found, keep moving
                    continue;
                
                } else {

                    // found that the qs mark is followed by a non-space character
                    // the qs is not followed only by spaces
                    is_qs_with_spaces_afterwards = false;
                    break;
                }
            } else {

                // reached the end of the string, final check for a space character
                if ( std::isspace(message[i]) != 0 ) {
                    
                    is_qs_with_spaces_afterwards = true;
                } else {

                    is_qs_with_spaces_afterwards = false;
                }
            }
        }

        //checking for both types of questions being asked
        // should also check for the case where you have a question mark followed by only whitespace afterwards
        if( (message[message.length() - 1] == '?') || (is_qs_with_spaces_afterwards) ){
            
            bool cap_letter_is_present {false};

            //checking all characters are in all caps
            // if not, then respond like an ordinary question
            for( long unsigned int i { }; i <= message.length() - 2; i++){
                
                // ignoring a punctuation mark or digit or space
                if ( (std::ispunct(message[i]) != 0) || (std::isdigit(message[i]) != 0) || (std::isspace(message[i]) != 0) ){

                    continue;
                } else if( (std::isalpha(message[i]) != 0) && (std::islower(message[i]) != 0) ){

                    result = "Sure.";
                    break;
                } else if( (i > 0) && (std::isalpha(message[i]) != 0) && (std::islower(message[i]) == 0) ){

                    cap_letter_is_present = true;
                }
            }

            // if the value of result is still blank, either the question is being yelled OR there were no letters used
            // we need another loop to confirm AT LEAST 1 uppercase letter to guarantee he's being yelled at
            // otherwise respond as "Sure", since a nonsense question is still a question
            if (result == "" && cap_letter_is_present){

                result = "Calm down, I know what I'm doing!";
            } else {

                result = "Sure.";
            }
        }

        // checking for the case where all letters have been uppercase, must ignore both whitespaces and any question given
        if( ( (message[message.length() - 1] != '?') && !is_qs_with_spaces_afterwards ) && (message.length() > 0) && (!is_only_whitespace) ){

            bool cap_letter_is_present {false};
            
            // set a flag for a lowercase letter being found
            for( long unsigned int i{ }; i < message.length(); i++){

                // ignoring what isn't part of the alphabet
                if ( std::isalpha(message[i]) == 0 ){

                    continue;
                } else if ( (std::isalpha(message[i]) != 0) && (std::islower(message[i]) != 0) ){

                    result =  "Whatever.";
                    break;
                } else if ( (i > 0) && (std::isalpha(message[i]) != 0) && (std::islower(message[i]) == 0) ){

                    cap_letter_is_present = true;
                }
            }
            
            // if result is blank, either all letters are capitals OR no letters were used
            // just check if there is at least one capital letter from the flag.
            // Guarantees a yell in that case, even if it's a nonsense yell
            if (result == "" && cap_letter_is_present){

                result = "Whoa, chill out!";
            } else {

                result = "Whatever.";
            }
        }

        // for a whitespace-only case or an empty message, the result is the same
        if (is_only_whitespace || message == ""){

            result = "Fine. Be that way!";
        }

        return result;
    }
}
