#pragma once
#include <bits/stdc++.h>
#include <string>
#include <algorithm>

namespace kindergarten_garden {

    // // to cover the case of a pot being empty, since it's not a guarantee that all pots are filled
    // // empty pots are denoted by " "
    enum class Plants{

        clover,
        grass,
        violets,
        radishes,
        empty
    };

    std::array<kindergarten_garden::Plants, 4> plants( std::string pots, std::string studentName );
}
