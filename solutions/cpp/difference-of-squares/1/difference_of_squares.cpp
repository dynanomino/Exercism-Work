#include "difference_of_squares.h"
#include "math.h"

namespace difference_of_squares {

    int sum_of_squares (int n_count){

        if ( n_count == 1 ){

            return n_count;
        } else {

            return pow(n_count, 2) + sum_of_squares(n_count - 1);
        }
    }

    // the square can't be computed during recursion, only at the end result in a single call
    int helper_square_of_sum (int n_count){

        if (n_count == 1 ){

            return n_count;
        } else {

            return n_count + helper_square_of_sum(n_count - 1);
        }
    }

    int square_of_sum (int n_count){

        return pow( helper_square_of_sum(n_count), 2 );
    }

    int difference (int n_count){

        return square_of_sum(n_count) - sum_of_squares(n_count);
    }

}  // namespace difference_of_squares
