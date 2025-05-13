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

size_t Math::PEMath::sumMultiples(int multiples[2], int limit) {
    return sumMultiple(multiples[0], limit) +
        sumMultiple(multiples[1], limit) -
        sumMultiple(multiples[0] * multiples[1], limit);
}