#include <iostream>
#include "core/Pokemon.hpp"
#include "lib/Profiling.hpp"

// https://bulbapedia.bulbagarden.net/wiki/List_of_Pokémon_by_base_stats_(Generation_II-V)

int main() {
    Pokemon pkmn[2];
    uint64_t begin, end;
    begin = Profiling::rdtsc();
    pkmn[0].mHp = 55;
    pkmn[0].mAttack = 70;
    pkmn[0].mDefense = 45;
    pkmn[0].mSpecialAttack = 70;
    pkmn[0].mSpecialDefense = 50;
    pkmn[0].mSpeed = 60;
    pkmn[0].mLevel = 5;

    pkmn[1].mHp = 35;
    pkmn[1].mAttack = 55;
    pkmn[1].mDefense = 30;
    pkmn[1].mSpecialAttack = 50;
    pkmn[1].mSpecialDefense = 40;
    pkmn[1].mSpeed = 90;
    pkmn[1].mLevel = 5;
    end = Profiling::rdtsc();
    std::cout << "Size of pkmn[2]: " << sizeof(pkmn) << std::endl;
    std::cout << "Written Pokemon Data in " << (end - begin) << " cycles." << std::endl;

    int iDamage;
    float fDamage;
    int iModifier = 1;
    float fModifier = 1.0f;

    // dmg pkm0 -> pkm1 => MOVE: TACKLE
    begin = Profiling::rdtsc();
    iDamage = (
        ((((((2 * pkmn[0].mLevel) / 5) + 2) *
        40 *
        (pkmn[0].mAttack / pkmn[1].mDefense)) /
        50) + 2) * iModifier
    );
    end = Profiling::rdtsc();
    std::cout << "Int Damage: " << iDamage << " calculated on " << (end-begin) << " cycles." << std::endl;

    begin = Profiling::rdtsc();
    fDamage = (
        ((((((2 * pkmn[0].mLevel) / 5) + 2) *
        40 *
        (pkmn[0].mAttack / pkmn[1].mDefense)) /
        50) + 2) * fModifier
    );
    end = Profiling::rdtsc();
    std::cout << "Float Damage: " << fDamage << " calculated on " << (end-begin) << " cycles." << std::endl;

    return 0;
}