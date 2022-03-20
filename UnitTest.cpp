#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "1.6/RightAngled.cpp"
#include "1.6/RightAngled.hpp"

TEST_CASE( "Arguments initialized") {
    int a1 = 10;
    int b1 = 8;
    int c1 = 6;
    int a2 = 5;
    int b2 = 4;
    int c2 = 3;
    RightAngled testing1;
    REQUIRE( testing1.Init(a1, b1, c1) == true);
    REQUIRE( testing1.Init(a2, b2, c2) == true);
}

