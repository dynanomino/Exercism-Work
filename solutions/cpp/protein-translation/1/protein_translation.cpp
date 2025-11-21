#include "protein_translation.h"

#include <string>
#include <vector>
#include <iostream>
#include <map>

namespace protein_translation {

    // dictionary for protein mapping
    std::map<std::string, std::string> map_protein{

        { "AUG", "Methionine"},
        { "UUU", "Phenylalanine"},
        { "UUC", "Phenylalanine"},
        { "UUA", "Leucine"},
        { "UUG", "Leucine"},
        { "UCU", "Serine"},
        { "UCC", "Serine"},
        { "UCA", "Serine"},
        { "UCG", "Serine"},
        { "UAU", "Tyrosine"},
        { "UAC", "Tyrosine"},
        { "UGU", "Cysteine"},
        { "UGC", "Cysteine"},
        { "UGG" , "Tryptophan"},
        { "UAA" , "STOP"},
        { "UAG" , "STOP"},
        { "UGA" , "STOP"}
    };

    std::vector<std::string> proteins(std::string input_rna){

        // we don't know how big the protein chain will be, so the vector size is unkown
        std::vector<std::string> list_protein { };

        // going through every 3 characters in "input_rna"
        for (long unsigned int i{}; i < input_rna.length(); i+=3){

            std::string cur_sequence { input_rna.substr(i, 3) };

            // check if the sequence is a terminator or invalid, otherwise add the proper name to protein list
            try
            {   
                // at() returns the value associated to the key, not a pointer to the map
                std::string map_value { map_protein.at(cur_sequence) };

                // as soon as STOP is encountered, all protein entries henceforth are terminated
                if ( map_value == "STOP" ){

                    //to conserve memory, shrink the vector when terminating
                    list_protein.shrink_to_fit();
                    break;

                } else {

                    // using push_back() since the empty protein vector is filled by pushing to the rear end
                    list_protein.push_back(map_value);
                    std::cout << "Entered " + map_value + "\n";
                }
            }
            catch(const std::out_of_range &e)
            {   

                // invalid sequence
                list_protein.push_back("");
            }
        }

        return list_protein;
    }

}  // namespace protein_translation
