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