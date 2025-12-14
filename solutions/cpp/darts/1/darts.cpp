#include "darts.h"

namespace darts {

    int score(float x, float y){

        float distance { pow( (pow(x, static_cast<float>(2)) + pow(y, static_cast<float>(2))), static_cast<float>(0.5) ) };

        if (distance <= 1){

            return 10;
        }else if (distance <= 5)
        {
            
            return 5;
        } else if (distance <= 10){

            return 1;
        } else {

            return 0;
        }
    }
}  
