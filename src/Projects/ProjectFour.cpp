#include "../../inc/Projects/ProjectFour.hpp"
#include "../../inc/PEMath.hpp"
#include <iostream>

/**
 * @description Runs the solver for Project Euler Project Archive 4
 * @author Zachary Waldron
 * @return int <status code>
 */
int Projects::ProjectFour::run() {
    int largest = 0;
    // Project Four is about finding the largest palindrome number
    // that results from multiplying two 3-digit numbers.
    // As n grows larger the proportion of prime numbers to palindromes
    // significantly decreases, at a rate of app
    // range of all 3-digit numbers multiplied is 10000 (1x10^4) to 998001 (9.98001x10^5)
    // if log(n)/log(10) >= 5 adjust from 4 shifts to 5
    // any number that ends with "0" will not be a palindrome, except 0 itself smallest
    // number to check is 101^2 due to any integer multiplied by 100 will end with "00"
    for (int i = 101; i <= 999; ++i) {
        for (int j = 101; j <= 999; ++j) {
            using namespace Math;
            int result = i * j;
            bool isPalindrome = PEMath::checkPalindrome(result);
            largest = isPalindrome && result > largest ? result : largest;
        }
    }

    const unsigned short ID = this->getID();
    std::cout << "Project ID: " << ID << std::endl;

    std::cout << "Largest Palindrome: " << largest << std::endl;

    return 0;
}

unsigned short Projects::ProjectFour::getID() {
    return this->PID;
}

Projects::ProjectFour::~ProjectFour() {
    return;
}
