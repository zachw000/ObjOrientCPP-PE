#include "../inc/PEMath.hpp"
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>
#include <string_view>

size_t Math::PEMath::sumMultiple(int multiple, int limit) {
    size_t sum = 0;
    // Implement Series Sum
    sum = (floor((double)(limit - 1)/(double)multiple) / 2) *
        (multiple + (limit - 1) - ((limit - 1) % multiple));
    return sum;
}

/// @brief Gets the sum of multiples of two numbers up to a limit.
/// @details Uses the inclusion-exclusion principle to avoid double counting.
/// @param multiples 
/// @param limit 
/// @return 
size_t Math::PEMath::sumMultiples(int multiples[2], int limit) {
    return sumMultiple(multiples[0], limit) +
        sumMultiple(multiples[1], limit) -
        sumMultiple(multiples[0] * multiples[1], limit);
}

// Returns the nth Fibonacci number using Binet's formula
unsigned long long Math::PEMath::fibonacci(unsigned int n) {
    static const double sqrt5 = std::sqrt(5.0);
    static const double phi = (1.0 + sqrt5) / 2.0;
    static const double psi = (1.0 - sqrt5) / 2.0;
    return static_cast<unsigned long long>(
        std::round((std::pow(phi, n) - std::pow(psi, n)) / sqrt5)
    );
}

unsigned long long Math::PEMath::fibonacciSum(unsigned int limit) {
    unsigned long long sum = 0;
    unsigned int n = 0;
    unsigned long long fib = fibonacci(n);
    
    while (fib <= limit) {
        if (fib % 2 == 0) {
            sum += fib;
        }
        n++;
        fib = fibonacci(n);
    }
    
    return sum;
}

unsigned long long Math::PEMath::evenFibonacciSum(unsigned int limit) {
    unsigned long long sum = 0;
    unsigned int n = 0;
    unsigned long long fib = fibonacci(n);

    while (fib <= limit) {
        if (fib % 2 == 0) {
            sum += fib;
        }
        n++;
        fib = fibonacci(n);
    }

    return sum;
}

unsigned long long Math::PEMath::power(unsigned int base, unsigned int exponent) {
    unsigned long long result = 1;
    for (unsigned int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

unsigned long long Math::PEMath::factorial(unsigned int n) {
    
}

unsigned long long Math::PEMath::gcd(unsigned long long a, unsigned long long b) {

}