#pragma once
#include "core/Moves.hpp"
// Goal: Have 2 Pokemons on Cache
// Considering a L2 Cache of 256kb
// Pokemon Class: 8 bytes
class Pokemon {
public:
    uint16 mHp;
    uint8 mAttack;
    uint8 mDefense;
    uint8 mSpecialAttack;
    uint8 mSpecialDefense;
    uint8 mSpeed;
    uint8 mLevel;
};

// public attributes uses less cpu cycles to read/write
// also, what is the real need for get and set methods?