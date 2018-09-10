#pragma once
#include "lib/BaseType.hpp"

class Move {
    public:
    uint16 mId; // 1 - 728
    uint8 mPp; // 0 - 40
    uint8 mPower; // 0 - 255
    uint8 mAccuracy; // 0 - 100
    
    // Other Information Currently not Implemented
    // TYPE (string)
    // CATEGORY (string)
    // CONTEST (string)
    // these can be mapped to enum or ints actually
};