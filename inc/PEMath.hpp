#pragma once
#ifndef PEMATH_HPP
#define PEMATH_HPP

#include "Manager.hpp"
#include <string_view>

namespace Math {
    class FastMath {
    public:
        FastMath() = default;
        ~FastMath() = default;

        FastMath(const FastMath&) = delete;
        FastMath& operator=(const FastMath&) = delete;

        FastMath(FastMath&&) = delete;
        FastMath& operator=(FastMath&&) = delete;

        static double sqrt(double x);
        static double pow(double x, double y);
        static double exp(double x);
        static double log(double x);
        static double sin(double x);
        static double cos(double x);
        static double tan(double x);
        static double asin(double x);
        static double acos(double x);
        static double atan(double x);
        static double atan2(double y, double x);
        static double sinh(double x);
        static double cosh(double x);
        static double tanh(double x);
        static double asinh(double x);
        static double acosh(double x);
        static double atanh(double x);
    };
}

#endif
