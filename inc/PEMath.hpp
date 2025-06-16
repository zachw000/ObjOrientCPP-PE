#pragma once
#ifndef PEMATH_HPP
#define PEMATH_HPP

#include "Manager.hpp"
#include <string_view>
#include <complex>

namespace Math {
    class PEMath {
    private:
        static constexpr double m_PHI = (1 + sqrt(5)) / 2;
        static constexpr double m_PHI_CONJUGATE = -1 * (1 / m_PHI);
    public:
        PEMath() = default;
        ~PEMath() = default;

        static unsigned long long fibonacci(unsigned int n);
        static unsigned long long evenFibonacciSum(unsigned int limit);
        static unsigned long long factorial(unsigned int n);
        static unsigned long long gcd(unsigned long long a, unsigned long long b);
        static unsigned long long lcm(unsigned long long a, unsigned long long b);
        static unsigned long long power(unsigned int base, unsigned int exponent);
        static unsigned long long fibonacciSum(unsigned int limit);
        static size_t sumMultiple(int multiple, int limit);
        static size_t sumMultiples(int multiples[2], int limit);
    };

    class Quaternion : std::complex<double> {
    private:
        double r, i, j, k;
        /*Quaternion QuadMult(Quaternion a, std::static_cast<typename _T> t) {

        }*/
    public:
        
    };
}

#endif
