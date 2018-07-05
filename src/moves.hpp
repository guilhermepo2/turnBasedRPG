#pragma once

class Move {
    public:
    unsigned int mId; // 1 - 728
    unsigned char mPp; // 0 - 40
    unsigned char mPower; // 0 - 255
    unsigned char mAccuracy; // 0 - 100
    
    // Other Information Currently not Implemented
    // TYPE (string)
    // CATEGORY (string)
    // CONTEST (string)
    // these can be mapped to enum or ints actually
};