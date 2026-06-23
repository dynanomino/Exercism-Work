#pragma once
#include <string>
#include <map>
#include <math.h>
#include <unordered_set>

namespace allergies {

    class allergy_test{

        
        public:

            int allergy_score {};

            allergy_test( int my_allergy_score );

            bool is_allergic_to ( std::string food_name );

            std::unordered_set<std::string> get_allergies();


        private:

            std::unordered_set<std::string> my_allergies {};

            std::map<int, std::string> all_allergies {};
    };

}  // namespace allergies
