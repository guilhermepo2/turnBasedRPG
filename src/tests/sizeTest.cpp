#include <iostream>
#include <vector>
#include "core/Moves.hpp"

// This class has 12 bytes
class uPokemon {
public:
    unsigned short int mHp;
    unsigned short int mAttack;
    unsigned short int mDefense;
    unsigned short int mSpecialAttack;
    unsigned short int mSpecialDeffense;
    unsigned short int mSpeed;
};

// 8 bytes
class cPokemon {
public:
    unsigned short int mHp;
    unsigned char mAttack;
    unsigned char mDefense;
    unsigned char mSpecialAttack;
    unsigned char mSpecialDefense;
    unsigned char mSpeed;
};

// This class has 24 bytes
class nPokemon {
public:
    unsigned int mHp;
    unsigned int mAttack;
    unsigned int mDefense;
    unsigned int mSpecialAttack;
    unsigned int mSpecialDeffense;
    unsigned int mSpeed;
};

// this also has 12 bytes
class oopPokemon {
public: 
    void setHp(int tHp) { this->mHp = tHp; }
    void setAttack(int tAttack) { this->mAttack = tAttack; }
    void setDefense(int tDefense) { this->mDefense = tDefense; }
    void setSpecialAttack(int tSpecialAttack) { this->mSpecialAttack = tSpecialAttack; }
    void setSpecialDefense(int tSpecialDefense) { this->mSpecialDefense = tSpecialDefense; }
    void setSpeed(int tSpeed) { this->mSpeed = tSpeed; }
    unsigned short int getHp() { return this->mHp; }
    unsigned short int getAttack() { return this->mAttack; }
    unsigned short int getDefense() { return this->mDefense; }
    unsigned short int getSpecialAttack() { return this->mSpecialAttack; }
    unsigned short int getSpecialDefense() { return this->mSpecialDefense; }
    unsigned short int getSpeed() { return this->mSpeed; }
private:
    unsigned short int mHp;
    unsigned short int mAttack;
    unsigned short int mDefense;
    unsigned short int mSpecialAttack;
    unsigned short int mSpecialDefense;
    unsigned short int mSpeed;
};

uint64_t rdtsc(){
    unsigned int lo,hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}

int main() {
    uPokemon uPkmn = uPokemon();
    nPokemon nPkmn = nPokemon();
    oopPokemon oopPkmn = oopPokemon();
    uint64_t begin, end;

    std::cout << "CLOCKS_PER_SEC: " << CLOCKS_PER_SEC << std::endl;
    std::cout << "uPokemon Class Size: " << sizeof(uPokemon) << std::endl;
    std::cout << "uPokemon Object Size: " << sizeof(uPkmn) << std::endl;
    std::cout << "nPokemon Class Size: " << sizeof(nPokemon) << std::endl;
    std::cout << "nPokemon Object Size: " << sizeof(nPkmn) << std::endl;
    std::cout << "oopPokemon Class Size: " << sizeof(oopPokemon) << std::endl;
    std::cout << "oopPokemon Object Size: " << sizeof(oopPkmn) << std::endl;
    std::cout << "cPokemon Class Size: " << sizeof(cPokemon) << std::endl;
    std::cout << std::endl;

    // this takes an average of 27 cpu cycles
    std::cout << "Setting variables on uPokemon (all public) - 100.000 times" << std::endl;
    uint64_t totalCycles = 0;
    for(int i = 0; i < 100000; i++) {
        begin = rdtsc();
        uPkmn.mHp = 55;
        uPkmn.mAttack = 15;
        uPkmn.mDefense = 12;
        uPkmn.mSpecialAttack = 55;
        uPkmn.mSpecialDeffense = 14;
        uPkmn.mSpeed = 25;
        end = rdtsc();
        totalCycles += (end - begin);
    }
    std::cout << "total cycles: " << totalCycles << std::endl;
    std::cout << "average: " << (double)(totalCycles / 100000) << std::endl;

    // this takes in average from 37 to 44 cpu cycles
    std::cout << "Setting variables on oopPokemon (standard oop) - 100.000 times" << std::endl;
    totalCycles = 0;
    for(int i = 0; i < 100000; i++) {
        begin = rdtsc();
        oopPkmn.setHp(55);
        oopPkmn.setAttack(15);
        oopPkmn.setDefense(12);
        oopPkmn.setSpecialAttack(55);
        oopPkmn.setSpecialDefense(14);
        oopPkmn.setSpeed(25);
        end = rdtsc();
        totalCycles += (end - begin);
    }
    std::cout << "total cycles: " << totalCycles << std::endl;
    std::cout << "average: " << (double)(totalCycles / 100000) << std::endl;
    std::cout << std::endl;

    std::cout << "Reading Attributes" << std::endl;
    // average of 25 cycles
    std::cout << "Reading variables on uPokemon (all public) - 100.000 times" << std::endl;
    totalCycles = 0;
    for(int i = 0; i < 100000; i++) {
        begin = rdtsc();
        uPkmn.mHp;
        uPkmn.mAttack;
        uPkmn.mDefense;
        uPkmn.mSpecialAttack;
        uPkmn.mSpecialDeffense;
        uPkmn.mSpeed;
        end = rdtsc();
        totalCycles += (end - begin);
    }
    std::cout << "total cycles: " << totalCycles << std::endl;
    std::cout << "average: " << (double)(totalCycles / 100000) << std::endl;

    // average of 40 cycles
    std::cout << "Reading variables on oopPokemon (standard oop) - 100.000 times" << std::endl;
    totalCycles = 0;
    for(int i = 0; i < 100000; i++) {
        begin = rdtsc();
        oopPkmn.getHp();
        oopPkmn.getAttack();
        oopPkmn.getDefense();
        oopPkmn.getSpecialAttack();
        oopPkmn.getSpecialDefense();
        oopPkmn.getSpeed();
        end = rdtsc();
        totalCycles += (end - begin);
    }
    std::cout << "total cycles: " << totalCycles << std::endl;
    std::cout << "average: " << (double)(totalCycles / 100000) << std::endl;
    std::cout << "The Winner is the class uPokemon" << std::endl;
    
    return 0;
}