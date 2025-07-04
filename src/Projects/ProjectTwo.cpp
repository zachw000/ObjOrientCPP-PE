#include "../../inc/Projects/ProjectTwo.hpp"
#include "../../inc/PEMath.hpp"
#include <iostream>

/**
 * @author Zachary Waldron
 * @date 2025-05-12
 * @brief Project Two Even Fibonacci Numbers
 * @details This project calculates the sum of even Fibonacci numbers up to a given limit.
 * @warning This project is for educational purposes only and should not be used in production.
 * @license Apache-2.0 All rights reserved.
 * @see
 * 
 * Each new term in the Fibonacci sequence is generated by adding the previous two terms. 
 * By starting with and , the first terms will be: 
 * 1,2,3,5,8,13,21,34,55,89,...
 * By considering the terms in the Fibonacci sequence whose values do not exceed four million, 
 * find the sum of the even-valued terms.
 * 
 */

int Projects::ProjectTwo::run() {
    std::cout << "Even Fibonacci Numbers (linker test 2)" << std::endl;

    std::cout << "Calculating the sum of even Fibonacci numbers up to " 
              << this->limit << "..." << std::endl;
    unsigned long long sum = Math::PEMath::evenFibonacciSum(this->limit);
    std::cout << "Sum of even Fibonacci numbers: " << sum << std::endl;
    std::cout << "Project Name: " << this->getName() << std::endl;
    std::cout << "Project ID: " << this->getID() << std::endl;

    return 0;
}

unsigned short Projects::ProjectTwo::getID() {
    return this->PID;
}

Projects::ProjectTwo::~ProjectTwo() {
    return;
}
