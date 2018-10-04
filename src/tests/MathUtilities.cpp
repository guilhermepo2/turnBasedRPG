#define CATCH_CONFIG_MAIN
#include "lib/BaseType.hpp"
#include "lib/MathUtilities.hpp"
#include "lib/catch.hpp"

TEST_CASE("Sanity Check", "[sanity]") {
    REQUIRE( 1 == 1);
}

TEST_CASE("A Bunch of MAX test", "[max]") {
    REQUIRE ( MathUtilities::uint8_max(3,8) == 8);
    REQUIRE ( MathUtilities::uint8_max((45*45),255) == 255);
}