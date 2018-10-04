#pragma once
#include "lib/BaseType.hpp"

class Stats {
public:
    uint16 hp;
    uint8 attack;
    uint8 defense;
    uint8 specialAttack;
    uint8 specialDefense;
    uint8 speed;
    uint8 level;

    Stats() : hp(0), attack(0), defense(0), specialAttack(0), specialDefense(0), speed(0), level(0) {}
    
    Stats(uint16 hp, uint8 attack, uint8 defense, uint8 specialAttack, uint8 specialDefense, uint8 speed, uint8 level) : hp(hp), attack(attack), defense(defense), specialAttack(specialAttack), specialDefense(specialDefense), speed(speed), level(level) {}

    Stats operator* (const int& t) const {
        return Stats(hp*t, attack*t, defense*t, specialAttack*t, specialDefense*t, speed*t, level*t);
    }

    Stats operator *= (const int& t) {
        hp *= t;
        attack *= t;
        defense *= t;
        specialAttack *= t;
        specialDefense *= t;
        speed *= t;
        level *= t;

        return *this;
    }
};