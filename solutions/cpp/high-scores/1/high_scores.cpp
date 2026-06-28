#include "high_scores.h"

#include <algorithm>
#include <iostream>

namespace arcade {

    
    std::vector<int> HighScores::list_scores() {
        
        return arcade::HighScores::scores;
    }

    int HighScores::latest_score() {
        
        return HighScores::scores.back();
    }

    int HighScores::personal_best() {
        
        std::vector<int> scores_copy { scores };
        std::sort(scores_copy.begin(), scores_copy.end());
        return scores_copy[scores_copy.size() - 1];
    }

    std::vector<int> HighScores::top_three() {
        
        std::vector<int> scores_copy { scores };
        std::sort(scores_copy.begin(), scores_copy.end());
        std::reverse(scores_copy.begin(), scores_copy.end());
        
        if (scores_copy.size() < 3){

            scores_copy.resize(scores_copy.size());
        } else {

            scores_copy.resize(3);
        }
        
        return scores_copy;
    }

}

// int main(){

//     std::vector<int> test_scores { 9, 8, 15, 6 };

//     arcade::HighScores hs { test_scores };
    
//     std::cout << "The scores are: [ ";

//     for(int i{}; i < static_cast<int>( hs.list_scores().size() ); i++){

//         std::cout << hs.list_scores()[i] << " ";
//     }

//     std::cout << "]" << "\n";

//     std::cout << "Method match: " << ( hs.list_scores() == test_scores ) << "\n";

//     std::cout << "Best score: " << hs.personal_best() << "\n";

//     std::cout << "Top 3: [ ";
//     for(int i{}; i < static_cast<int>( hs.top_three().size() ); i++){

//         std::cout << hs.top_three()[i] << " ";
//     };
//     std::cout << "]" << "\n";

//     return 0;

// }
