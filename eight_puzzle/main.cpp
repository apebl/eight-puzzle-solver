#include "solver.hpp"
#include <iostream>

void solve (int initial_array[], int goal_array[]) {
    eight_puzzle::Matrix initial {initial_array};
    eight_puzzle::Matrix goal {goal_array};
    eight_puzzle::Solver solver { initial, goal };
    solver.solve();
}

void question_1 () {
    std::cout << "========== Question-1 ==========" << std::endl << std::endl;
    int initial_array[] {
        2, 8, 3,
        1, 6, 4,
        7, BLANK, 5
    };
    int goal_array[] {
        1, 2 ,3,
        8, BLANK, 4,
        7, 6, 5
    };
    solve(initial_array, goal_array);
}

void question_2 () {
    std::cout << "========== Question-2 ==========" << std::endl << std::endl;
    int initial_array[] {
        3, 8, 1,
        6, 2, 5,
        BLANK, 4, 7
    };
    int goal_array[] {
        1, 2 ,3,
        8, BLANK, 4,
        7, 6, 5
    };
    solve(initial_array, goal_array);
}

void question_3 () {
    std::cout << "========== Question-3 ==========" << std::endl << std::endl;
    int initial_array[] {
        1, 4, 3,
        7, BLANK, 6,
        5, 8, 2
    };
    int goal_array[] {
        1, 3, 6,
        7, 4, 2,
        5, 8, BLANK
    };
    solve(initial_array, goal_array);
}

int main () {
    question_1();
    question_2();
    question_3();
    return 0;
}
