#pragma once
#include "core/Move.hpp"
#include "core/Stats.hpp"

// Goal: Have 2 Pokemons on Cache
// Considering a L2 Cache of 256kb
// Pokemon Class: 8 bytes
class Pokemon {
public:
    Stats stats;    
    Move moves[4];

    // Create All Constructors
};

// public attributes uses less cpu cycles to read/write
// also, what is the real need for get and set methods?