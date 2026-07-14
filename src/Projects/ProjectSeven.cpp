#include "../../inc/Projects/ProjectSeven.hpp"
#include "../../inc/PEMath.hpp"
#include <iostream>

int Projects::ProjectSeven::run() {
    using namespace Math;

    std::cout << "10001st prime" << std::endl;

    const unsigned short ID = this->getID();
    std::cout << "Project ID: " << ID << std::endl;
    std::cout << "Limit: " << this->limit << std::endl;
    // Get the 10001st prime number
    const int result = PEMath::getNthPrime(this->limit);
    std::cout << "10001st prime: " << result << std::endl;

    return 0;
}

unsigned short Projects::ProjectSeven::getID() {
    return this->PID;
}

Projects::ProjectSeven::~ProjectSeven() {
    return;
}
