#include "../../inc/Projects/ProjectOne.hpp"
#include <iostream>
#include <cmath>
size_t sumMultiple(int multiple, int limit) {
    size_t sum = 0;
    // Implement Series Sum
    sum = (floor((double)(limit - 1)/(double)multiple) / 2) *
        (multiple + (limit - 1) - ((limit - 1) % multiple));
    return sum;
}

size_t sumMultiples(int multiples[2], int limit) {
    return sumMultiple(multiples[0], limit) +
        sumMultiple(multiples[1], limit) -
        sumMultiple(multiples[0] * multiples[1], limit);
}

int Projects::ProjectOne::run() {
    std::cout << "Multiples of 3 and 5" << std::endl;

    unsigned short ID = this->getID();
    std::cout << "Project ID: " << ID << std::endl;

    std::cout << "Multiples: " << this->multiples[0] << ", " << this->multiples[1] << std::endl;
    std::cout << "Limit: " << this->limit << std::endl;

    size_t result = sumMultiples(this->multiples, this->limit);

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
}
