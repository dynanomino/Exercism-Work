#include "matching_brackets.h"
#include <iostream>

namespace matching_brackets {

    bool check(std::string str_to_check){

        int par_count {}, brac_count {}, curl_count {};
        //char expected_closer{}, prev_closer{};

        std::vector<char> openers{};
        //int j{};

        // indexing to pick up the chars easily and get the counts, and what is expected to close brackets
        for(int i = 0; i < static_cast<int>( str_to_check.length() ); i++){

            // only a valid count is the number 0, elsewise it's a mismatch
            // the order is also important, so if the count is ever negative while checking, the order is wrong
            // the brackets also must close with their counterpart, not another bracket type
            switch (str_to_check[i])
            {
                case '[':
                    brac_count ++;
                    openers.push_back('[');
                    break;

                case ']':

                    // if openers is empty at a closer, wrong order
                    if (!openers.empty()){

                        if(openers.back() == '['){

                            brac_count --;
                            openers.pop_back();
                        } else {

                            return false;
                        }
                    } else {

                        return false;
                    }
                    break;

                case '(':

                    par_count ++;
                    openers.push_back('(');
                    break;

                case ')':
                    
                    if (!openers.empty()){

                        if(openers.back() == '('){

                            par_count --;
                            openers.pop_back();
                        } else {

                            return false;
                        }
                    } else {

                        return false;
                    }
                    break;

                case '{':

                    curl_count ++;
                    openers.push_back('{');
                    break;

                case '}':

                    if (!openers.empty()){

                        if (openers.back() == '{'){

                            curl_count --;
                            openers.pop_back();
                        } else {

                            return false;
                        }
                    } else {

                        return false;
                    }
                    break;         
            };

            if( brac_count < 0 || curl_count < 0 || par_count < 0){

                return false;
                break;
            };
        };

        // this checks for no leftover punctuation, after ensuring correct order
        return ( brac_count == 0 && par_count == 0 && curl_count == 0 );
    };
};