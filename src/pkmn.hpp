#pragma once

// Goal: Have 2 Pokemons on Cache
// Considering a L2 Cache of 256kb
// Pokemon Class: 8 bytes
class Pokemon {
public:
    unsigned short int mHp;
    unsigned char mAttack;
    unsigned char mDefense;
    unsigned char mSpecialAttack;
    unsigned char mSpecialDeffense;
    unsigned char mSpeed;
};

// public attributes uses less cpu cycles to read/write
// also, what is the real need for get and set methods?