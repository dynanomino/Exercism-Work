#include <array>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <tuple>

using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

// Round down all provided student scores
std::tuple< std::vector<int>,  duration<double, std::milli> > round_down_scores_condense(std::vector<double> student_scores) {

    auto t1 = steady_clock::now();

    // size declaration needed to avoid segmentation fault when referencing the beginning of this vector
    std::vector<int> result( student_scores.size() );
    
    // can cast a double to an int, to automatically truncate the fraction in the double number
    // could be useful when handling encoders with motors that might give fractions in the numbers
    // the input iterators use type double, which should match the capture clause "[]", which is used to give access to variables (by value or a pointer)
    std::transform(student_scores.begin(), student_scores.end(), result.begin(), [](double &n) { return static_cast<int>(n); } );

    auto t2 = steady_clock::now();

    //if you want integer time, use...
    //... "auto ms_int = duration_cast<milliseconds>(t2 - t1)""
    duration<double, std::milli> ms_time = t2 - t1;

    return std::make_tuple( result, ms_time );
}

std::tuple< std::vector<int>, duration<double, std::milli> > round_down_scores_elab(std::vector<double> student_scores){

    auto t1 = steady_clock::now();

    std::vector<int> result ( student_scores.size() );
    int i {};

    for(double score : student_scores) {

        result[i] = static_cast<int>( score );
        i++;
    }

    auto t2 = steady_clock::now();
    duration<double, std::milli> ms_time = t2 - t1;

    return std::make_tuple( result, ms_time );
}

std::vector<int> round_down_scores(std::vector<double> student_scores) {

    std::vector<int> result( student_scores.size() );
    int i{};

    for (double score : student_scores){

        result[i] = static_cast<int>( score );
        i++;
    }

    return result;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {

    int fail_count {};

    for (double score:student_scores){

        if (score <= 40) {fail_count++;}
    }

    // TODO: Implement count_failed_students
    return fail_count;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {

    int grade_interval { (highest_score - 40) / 4 };

    std::array<int, 4> thresholds {41};

    int i{1};

    while (i < thresholds.size()) {

        thresholds[i] = thresholds[i-1] + grade_interval;
        i++;
    }

    return thresholds;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {

    int j{};

    while ( j < student_scores.size() ){

        for (int i{}; i < student_scores.size() - 1; i++) {

            if (student_scores[i+1] > student_scores[i]){

                int temp_int = student_scores[i+1];
                std::string temp_string = student_names[i+1];

                student_scores[i+1] = student_scores[i];
                student_names[i+1] = student_names[i];

                student_scores[i] = temp_int;
                student_names[i] = temp_string;
            }
        }

        j++;
    }

    std::vector<std::string> result (student_names.size());

    j = 1;

    for (int i {0}; i < result.size(); i++) {

        result[i] = std::to_string(j) + ". " + student_names[j-1] + ": " + std::to_string(student_scores[j-1]);
        j++;
    }

    // TODO: Implement student_ranking
    return result;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    
    int i{ 1 };

    // location of the max score
    int j{};
    int max { student_scores[j] };

    while ( i < student_scores.size() ) {

        // updating where the max score is located
        // will ignore the case of finding 100 again later in the vector
        // that ensures only the FIRST student is collected
        if ( student_scores[i] > max ){

            max = student_scores[i];
            j = i;
        }

        i++;
    }
    
    if (max == 100) {

        return student_names[j];
    }
    else {

        return "";
    }
}
