#include "../../inc/Projects/ProjectThree.hpp"
#include "../../inc/PEMath.hpp"
#include "../../inc/PEMath.hpp"
#include <iostream>
/*
* The prime factors of 13195 are 5,7,13 and 29.
* What is the largest prime factor of the number 600851475143?
 */
int Projects::ProjectThree::run() {
    std::cout <<"Largest Prime Factor (Problem 3)" << std::endl;
    const unsigned short ID = this->getID();
    std::cout << "Project ID: " << ID << std::endl;
    {
        using namespace Math;
        constexpr unsigned long factor = 600851475143;

        std::vector<int> factors = PEMath::primeFactors(factor);
        int max = 0;
        for (const int prime : factors) {
            if (max < prime) {
                max = prime;
            }
        }
        factors.clear();
        std::cout << "The largest prime factor of " << factor << " is: \n\t" << max << std::endl;
    }
    return 0;
}

unsigned short Projects::ProjectThree::getID() {
    return this->PID;
}

Projects::ProjectThree::~ProjectThree() = default;
