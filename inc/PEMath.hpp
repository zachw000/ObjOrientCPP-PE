#pragma once
#ifndef PEMATH_HPP
#define PEMATH_HPP

#include "Manager.hpp"
#include <string_view>
#include <complex>
#include <vector>
#include <cmath>

namespace Math {
    class PEMath {
    private:
        double m_PHI = (1 + sqrt(5)) / 2;
        double m_PHI_CONJUGATE = -1 * (1 / m_PHI);
    public:
        PEMath() = default;
        ~PEMath() = default;

        static unsigned long long fibonacci(unsigned int n);
        static unsigned long long evenFibonacciSum(unsigned int limit);
        static unsigned long long factorial(unsigned int n);
        static unsigned long long gcd(unsigned long long a, unsigned long long b);
        static unsigned long long lcm(unsigned long long a, unsigned long long b);
        static unsigned long long power(unsigned int base, unsigned int exponent);
        static std::vector<int> primeFactors(unsigned long long n);
        static unsigned long long fibonacciSum(unsigned int limit);
        static size_t sumMultiple(int multiple, int limit);
        static size_t sumMultiples(int multiples[2], int limit);
    };

    class Quaternion {
    private:
        double a, b, c, d;
    public:
        Quaternion(double a, double b, double c, double d);

        Quaternion operator+(const Quaternion& other) const;
        Quaternion operator-(const Quaternion& other) const;
        Quaternion operator*(const Quaternion& other) const;
        Quaternion operator*(double scalar) const;
        friend Quaternion operator*(double scalar, const Quaternion& q);

        double norm() const;
        Quaternion normalized() const;

        double i_component() const;
        double j_component() const;
        double k_component() const;
        double scalar_component() const;

        friend std::ostream& operator<<(std::ostream& os, const Quaternion& q);
    };
}

#endif
