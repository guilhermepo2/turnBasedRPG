#define CATCH_CONFIG_MAIN
#include "core/Stats.hpp"
#include "lib/catch.hpp"

TEST_CASE("Sanity Check", "[sanity]") {
    REQUIRE( 1 == 1);
}

TEST_CASE("Empty Constructor", "[constructor]") {
    Stats stats = Stats();
    REQUIRE(stats.hp == 0);
    REQUIRE(stats.attack == 0);
    REQUIRE(stats.defense == 0);
    REQUIRE(stats.specialAttack == 0);
    REQUIRE(stats.specialDefense == 0);
    REQUIRE(stats.speed == 0);
    REQUIRE(stats.level == 0);
}

TEST_CASE("Parameter Constructor", "[constructor]") {
    Stats stats = Stats(45, 49, 49, 65, 65, 45, 5);
    REQUIRE(stats.hp == 45);
    REQUIRE(stats.attack == 49);
    REQUIRE(stats.defense == 49);
    REQUIRE(stats.specialAttack == 65);
    REQUIRE(stats.specialDefense == 65);
    REQUIRE(stats.speed == 45);
    REQUIRE(stats.level == 5);
}

TEST_CASE("Multiply by constant", "[multiply]") {
    Stats stats = Stats(45, 49, 49, 65, 65, 45, 5);
    stats = stats * 2;
    REQUIRE(stats.hp == 90);
    REQUIRE(stats.attack == 98);
    REQUIRE(stats.defense == 98);
    REQUIRE(stats.specialAttack == 130);
    REQUIRE(stats.specialDefense == 130);
    REQUIRE(stats.speed == 90);
    REQUIRE(stats.level == 10);
}

TEST_CASE("Multiply by constant with *=", "[multiply]") {
    Stats stats = Stats(45, 49, 49, 65, 65, 45, 5);
    stats *= 2;
    REQUIRE(stats.hp == 90);
    REQUIRE(stats.attack == 98);
    REQUIRE(stats.defense == 98);
    REQUIRE(stats.specialAttack == 130);
    REQUIRE(stats.specialDefense == 130);
    REQUIRE(stats.speed == 90);
    REQUIRE(stats.level == 10);
}