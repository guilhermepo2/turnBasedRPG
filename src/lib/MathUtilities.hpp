#pragma once
#include "lib/BaseType.hpp"

namespace MathUtilities {
    int uint8_max(uint8 first, uint8 second) {
        int bigger = first > second ? first : second;
        return bigger;
    }

    int uint8_min(int first, int second) {
        int smaller = first > second ? second : first;
        return smaller;
    }
}