#pragma once

#include <algorithm>
#include <vector>

namespace arcade {

    class HighScores {
        private:
            std::vector<int> scores;

        public:

            // this is a way of having constructors directly initialise member vars
            HighScores(std::vector<int> scores) : scores(scores){};

            std::vector<int> list_scores();

            int latest_score();

            int personal_best();

            std::vector<int> top_three();
    };

}  // namespace arcade
