#pragma once
#ifndef PEMATH_HPP
#define PEMATH_HPP

#include "Manager.hpp"
#include <string_view>

namespace Math {
    class PEMath {
    public:
        PEMath() = default;
        ~PEMath() = default;

        static unsigned long long fibonacci(unsigned int n);
        static unsigned long long evenFibonacciSum(unsigned int limit);
        static unsigned long long factorial(unsigned int n);
        static unsigned long long gcd(unsigned long long a, unsigned long long b);
        static unsigned long long lcm(unsigned long long a, unsigned long long b);
        static unsigned long long power(unsigned int base, unsigned int exponent);
        static unsigned long long fibonacciSum(unsigned int n);
        static size_t sumMultiple(int multiple, int limit);
        static size_t sumMultiples(int multiples[2], int limit);
    };
}

#endif
