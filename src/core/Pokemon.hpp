#pragma once
#include "core/Move.hpp"

// Goal: Have 2 Pokemons on Cache
// Considering a L2 Cache of 256kb
// Pokemon Class: 8 bytes
class Pokemon {
public:
    uint16 m_hp;
    uint8 m_attack;
    uint8 m_defense;
    uint8 m_specialAttack;
    uint8 m_specialDefense;
    uint8 m_speed;
    uint8 m_level;
    Move m_moves[4];

    // Create All Constructors
};

// public attributes uses less cpu cycles to read/write
// also, what is the real need for get and set methods?