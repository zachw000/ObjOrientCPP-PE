#include "../../inc/Projects/ProjectFive.hpp"
#include <iostream>
#include <numeric>
// Project Five: The Smallest Multiple
/*
Overview of the problem:
When solving for the smallest multiple of a range of numbers, we can use the concept of least common multiple (LCM). 
The LCM of two numbers can be calculated using their greatest common divisor (GCD) with the formula: 
LCM(a, b) = (a * b) / GCD(a, b). To find the smallest multiple that is evenly divisible by all numbers from 1 to n, 
we can iteratively calculate the LCM of the current result with each number in the range.

So for the range of numbers from 1 to 20, we can start with an initial value of 1 and iteratively calculate the LCM 
with each number from 2 to 20.
*/
/**
 * @brief Constructor for ProjectFive class
 */
int Projects::ProjectFive::run() {
    std::cout << this->p_name << std::endl;

    const unsigned short ID = this->getID();
    std::cout << "Project ID: " << ID << std::endl;
    std::cout << "Calculating the smallest multiple that is evenly divisible by all numbers from 1 to 20..." << std::endl;
    int result = 1;
    for (int i = 2; i <= 20; ++i) {
        result = std::lcm(result, i);
    }

    std::cout << "Result: " << result << std::endl;
    return 0;
}

unsigned short Projects::ProjectFive::getID() {
    return this->PID;
}

Projects::ProjectFive::~ProjectFive() {
    return;
}
