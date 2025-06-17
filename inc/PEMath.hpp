#pragma once
#ifndef PEMATH_HPP
#define PEMATH_HPP

#include "Manager.hpp"
#include <string_view>
#include <complex>
#include <vector>

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
        static std::vector<int> primeFactors(unsigned long long n);
        static unsigned long long fibonacciSum(unsigned int limit);
        static size_t sumMultiple(int multiple, int limit);
        static size_t sumMultiples(int multiples[2], int limit);
    };

    class Quaternion {
    public:
        double a, b, c, d;

        Quaternion(double a, double b, double c, double d)
            : a(a), b(b), c(c), d(d) {}

        // Addition
        Quaternion operator+(const Quaternion& other) const {
            return Quaternion(a + other.a, b + other.b, c + other.c, d + other.d);
        }

        // Subtraction
        Quaternion operator-(const Quaternion& other) const {
            return Quaternion(a - other.a, b - other.b, c - other.c, d - other.d);
        }

        // Multiplication (by scalar or quaternion)
        Quaternion operator*(const Quaternion& other) const {
            double na = a * other.a - b * other.b - c * other.c - d * other.d;
            double nb = a * other.b + b * other.a + c * other.d - d * other.c;
            double nc = a * other.c - b * other.d + c * other.a + d * other.b;
            double nd = a * other.d + b * other.c - c * other.b + d * other.a;
            return Quaternion(na, nb, nc, nd);
        }
        Quaternion operator*(double scalar) const {
            return Quaternion(a * scalar, b * scalar, c * scalar, d * scalar);
        }
        // Allow scalar * Quaternion
        friend Quaternion operator*(double scalar, const Quaternion& q) {
            return q * scalar;
        }

        // Norm (magnitude)
        double norm() const {
            return std::sqrt(a * a + b * b + c * c + d * d);
        }

        // Normalized quaternion
        Quaternion normalized() const {
            double n = norm();
            return Quaternion(a / n, b / n, c / n, d / n);
        }

        // Component accessors
        double i_component() const { return b; }
        double j_component() const { return c; }
        double k_component() const { return d; }
        double scalar_component() const { return a; }

        // String representation
        friend std::ostream& operator<<(std::ostream& os, const Quaternion& q) {
            os << q.a << "+" << q.b << "i+" << q.c << "j+" << q.d << "k";
            return os;
        }
    };
}

#endif
