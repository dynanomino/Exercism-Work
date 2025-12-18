#include "allergies.h"
#include <iostream>

allergies::allergy_test::allergy_test( int my_allergy_score ){

    allergy_score = my_allergy_score % 256;

    all_allergies = { 

        {1, "eggs"},
        {2, "peanuts"},
        {4, "shellfish"},
        {8, "strawberries"},
        {16, "tomatoes"},
        {32, "chocolate"},
        {64, "pollen"},
        {128, "cats"}
    };

    // avoids making copies or modifications
    for ( const auto& [score, item] : all_allergies ){

        // each item is a single bit that is set
        // we just need to see that the same bits are set in allergy score
        if ( score & allergy_score ){

            my_allergies.emplace(item);
        }
    }
}

// so long as the find iterator isn't the end, we found the item
bool allergies::allergy_test::is_allergic_to( std::string item ){
    
    return ( my_allergies.find( item ) != my_allergies.end() );
}

std::unordered_set<std::string> allergies::allergy_test::get_allergies(){

    return my_allergies;
}