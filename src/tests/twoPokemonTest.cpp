#include <iostream>
#include "core/Pokemon.hpp"
#include "lib/Profiling.hpp"

// https://bulbapedia.bulbagarden.net/wiki/List_of_Pokémon_by_base_stats_(Generation_II-V)

int main() {
    Pokemon pkmn[2];
    uint64_t begin, end;
    begin = Profiling::rdtsc();
    pkmn[0].stats.hp = 55;
    pkmn[0].stats.attack = 70;
    pkmn[0].stats.defense = 45;
    pkmn[0].stats.specialAttack = 70;
    pkmn[0].stats.specialDefense = 50;
    pkmn[0].stats.speed = 60;
    pkmn[0].stats.level = 5;

    pkmn[1].stats.hp = 35;
    pkmn[1].stats.attack = 55;
    pkmn[1].stats.defense = 30;
    pkmn[1].stats.specialAttack = 50;
    pkmn[1].stats.specialDefense = 40;
    pkmn[1].stats.speed = 90;
    pkmn[1].stats.level = 5;
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
        ((((((2 * pkmn[0].stats.level) / 5) + 2) *
        40 *
        (pkmn[0].stats.attack / pkmn[1].stats.defense)) /
        50) + 2) * iModifier
    );
    end = Profiling::rdtsc();
    std::cout << "Int Damage: " << iDamage << " calculated on " << (end-begin) << " cycles." << std::endl;

    begin = Profiling::rdtsc();
    fDamage = (
        ((((((2 * pkmn[0].stats.level) / 5) + 2) *
        40 *
        (pkmn[0].stats.attack / pkmn[1].stats.defense)) /
        50) + 2) * fModifier
    );
    end = Profiling::rdtsc();
    std::cout << "Float Damage: " << fDamage << " calculated on " << (end-begin) << " cycles." << std::endl;

    return 0;
}