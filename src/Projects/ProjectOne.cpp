#include "../../inc/Projects/ProjectOne.hpp"
#include "../../inc/PEMath.hpp"
#include <iostream>

int Projects::ProjectOne::run() {
    using namespace Math;

    std::cout << "Multiples of 3 and 5" << std::endl;

    const unsigned short ID = this->getID();
    std::cout << "Project ID: " << ID << std::endl;

    std::cout << "Multiples: " << this->multiples[0] << ", " << this->multiples[1] << std::endl;
    std::cout << "Limit: " << this->limit << std::endl;

    size_t result = PEMath::sumMultiples(this->multiples, this->limit);

    std::cout << "Sum of Multiples: " << result << std::endl;

    return 0;
}

unsigned short Projects::ProjectOne::getID() {
    return this->PID;
}

void Projects::ProjectOne::setMultiples(int newMultiples[2]) {
    this->multiples[0] = newMultiples[0];
    this->multiples[1] = newMultiples[1];
}

void Projects::ProjectOne::setLimit(int newLimit) {
    this->limit = newLimit;
}

Projects::ProjectOne::~ProjectOne() {
    this->setLimit(0);

    return;
}
