#include "kindergarten_garden.h"
#include <iostream>

namespace kindergarten_garden {

    // it's not a guarantee that the first pot not being planted means no pots were planted
    // this map allows for flexibility of any case for the pots being planted
    std::unordered_map < std::string, std::array<int, 4> > plant_positions = {

        { "Alice", {0, 1, 24, 25} },
        { "Bob", {2, 3, 26, 27} },
        { "Charlie", {4, 5, 28, 29} },
        { "David", {6, 7, 30, 31} },
        { "Eve", {8, 9, 32, 33} },
        { "Fred", {10, 11, 34, 35} },
        { "Ginny", {12, 13, 36, 37} },
        { "Harriet", {14, 15, 38, 39} },
        { "Ileana", {16, 17, 40, 41} },
        { "Joseph", {18, 19, 42, 43} },
        { "Kincaid", {20, 21, 44, 45} },
        { "Larry", {22, 23, 46, 47} }
    };

    // pass a string containing "\n" to indicate the rows of plants, and return the plant names of a given student
    // this can handle any number of pots being filled or unfilled for a given student
    std::array<kindergarten_garden::Plants, 4> plants( std::string pots, std::string studentName ){
        
        try
        {
            plant_positions.at(studentName);
        }
        catch(const std::out_of_range& e)
        {
            throw std::runtime_error("Student is not part of the classroom");
        }

        std::cout << "Length of string before processing: " << pots.length() << "\n";

        // first, find where the "\" in "\n" is located, so that in a case like "RV\nRC" -> "RVRC", the top-row-end is at index 1
        long unsigned int end_of_top_row { pots.find("\n") - static_cast<long unsigned int>(1) };

        std::cout << "Found backslash after index: " << end_of_top_row << "\n";
        std::cout << "pots before: " << pots << "\n";

        std::array<kindergarten_garden::Plants, 4> results{};

        // since the map is designed to look at the full string length, the pots string gets filled with ' ' for empty pots before \n and after the last char
        // it allows the map to be easily used to know whether or not a certain plant was put in the pot for a given student
        // without this step, the code would have convoluted if-logic for dealing with pots string of varying and/or non-even length

        // we first check the top row being full, then the bottom row
        if (end_of_top_row != 23){

            pots.insert( pots.begin() + pots.find("\n"), 24 - (end_of_top_row + 1), ' ' );
        }
        
        if (pots.length() != 49){

            pots.insert( pots.end(), 49 - pots.length(), ' ' );
        }

        //end_of_top_row needs to be recalculated for new pots string length
        // in this case it's guaranteed to now be the index 23
        end_of_top_row = 23;

        // "\n" in a string only counts as one character
        // also guarantee the algo to work with capitals
        pots.replace(end_of_top_row + 1, 1, "");
        std::transform( pots.begin(), pots.end(), pots.begin(), [](char& c){ return std::toupper(c); } );

        std::transform( plant_positions[studentName].begin(), 
                        plant_positions[studentName].end(),
                        results.begin(), [&pots]( const int& indexstr ){
                            
                            switch ( pots[indexstr] )
                            {
                            case 'C':
                                return kindergarten_garden::Plants::clover;
                                break;
                            case 'G':
                                return  kindergarten_garden::Plants::grass;
                                break;
                            case 'V':
                                return kindergarten_garden::Plants::violets;
                                break;
                            case 'R':
                                return kindergarten_garden::Plants::radishes;
                                break;
                            default:
                                return kindergarten_garden::Plants::empty;
                            }
                        }
                    );
        return results;
    }
}
