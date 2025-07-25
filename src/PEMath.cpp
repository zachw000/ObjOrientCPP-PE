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
        sum += fib;
        n++;
        fib = fibonacci(n);
    }
    
    return sum;
}

unsigned long long Math::PEMath::evenFibonacciSum(unsigned int limit) {
    unsigned long long sum = 0;
    unsigned int n = 3;
    unsigned long long fib = fibonacci(n);

    while (fib <= limit) {
        if (fib % 2 == 0) {
            sum += fib;
        }
        n += 3;
        fib = fibonacci(n);
    }

    // OBSERVATION: The Fibonacci sequence contains an even number every third term.
    // This means we can optimize the calculation by only considering every third Fibonacci number.
    // This is because the Fibonacci sequence is periodic with respect to even numbers.

    return sum;
}

unsigned long long Math::PEMath::power(unsigned int base, unsigned int exponent) {
    unsigned long long result = 1;
    for (unsigned int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

std::vector<int> primeFactors(unsigned long long n) {
    std::vector<int> factors;

    // Check for number of 2s that divide n
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    // n must be odd at this point, so we can skip even numbers
    for (unsigned long long i = 3; i <= std::sqrt(n); i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    // This condition is to check if n is a prime number greater than 2
    if (n > 2) {
        factors.push_back(n);
    }

    // Convert vector to array and return
    return factors;
}

unsigned long long Math::PEMath::factorial(unsigned int n) {
    return 0; // Placeholder for factorial implementation
}

unsigned long long Math::PEMath::gcd(unsigned long long a, unsigned long long b) {
    return 0; // Placeholder for GCD implementation
}

unsigned long long Math::PEMath::lcm(unsigned long long a, unsigned long long b)
{
    return 0;   // Placeholder for LCM implementation
}

// Quaternion implementation
Math::Quaternion::Quaternion(double a, double b, double c, double d)
    : a(a), b(b), c(c), d(d) {}

Math::Quaternion Math::Quaternion::operator+(const Quaternion& other) const {
    return {a + other.a, b + other.b, c + other.c, d + other.d};
}

Math::Quaternion Math::Quaternion::operator-(const Quaternion& other) const {
    return {a - other.a, b - other.b, c - other.c, d - other.d};
}

Math::Quaternion Math::Quaternion::operator*(const Quaternion& other) const {
    double na = a * other.a - b * other.b - c * other.c - d * other.d;
    double nb = a * other.b + b * other.a + c * other.d - d * other.c;
    double nc = a * other.c - b * other.d + c * other.a + d * other.b;
    double nd = a * other.d + b * other.c - c * other.b + d * other.a;
    return {na, nb, nc, nd};
}

Math::Quaternion Math::Quaternion::operator*(double scalar) const {
    return {a * scalar, b * scalar, c * scalar, d * scalar};
}

Math::Quaternion operator*(const double scalar, const Math::Quaternion& q) {
    return q * scalar;
}

double Math::Quaternion::norm() const {
    return std::sqrt(a * a + b * b + c * c + d * d);
}

Math::Quaternion Math::Quaternion::normalized() const {
    double n = norm();
    if (n == 0) {
        return {0, 0, 0, 0}; // Avoid division by zero
    }
    return {a / n, b / n, c / n, d / n};
}

double Math::Quaternion::i_component() const { return b; }
double Math::Quaternion::j_component() const { return c; }
double Math::Quaternion::k_component() const { return d; }
double Math::Quaternion::scalar_component() const { return a; }

std::ostream& Math::operator<<(std::ostream& os, const Math::Quaternion& q) {
    os << q.scalar_component() << "+" << q.i_component() << "i+"
       << q.j_component() << "j+" << q.k_component() << "k";
    return os;
}