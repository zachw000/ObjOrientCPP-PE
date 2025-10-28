#include "../../inc/Projects/ProjectThree.hpp"
#include "../../inc/PEMath.hpp"
#include <iostream>

int Projects::ProjectThree::run() {
    std::cout <<"Largest Prime Factor (Problem 3)" << std::endl;

    const unsigned short ID = this->getID();
    std::cout << "Project ID: " << ID << std::endl;
    constexpr unsigned long factor = 600851475143;
    {
        using namespace Math;
        std::vector<int> factors = PEMath::primeFactors(factor);
        int max = 0;
        for (const int prime : factors) max = prime > max ? prime : max;
        std::cout << "The largest prime factor of " << factor << " is:\n\t" << max << std::endl;
    }

    return 0;
}

unsigned short Projects::ProjectThree::getID() {
    return this->PID;
}

Projects::ProjectThree::~ProjectThree() {
    // TODO: Delete this->factors<int> when implemented
    return;
}
