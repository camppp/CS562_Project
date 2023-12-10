#include "catch2/catch.hpp"

// Include the function to be tested
int add(int a, int b) {
    return a + b;
}

TEST_CASE("Addition tests") {
    SECTION("Add two positive numbers") {
        REQUIRE(add(2, 3) == 5);
    }

    SECTION("Add a positive and a negative number") {
        REQUIRE(add(5, -3) == 2);
    }

    SECTION("Add two negative numbers") {
        REQUIRE(add(-7, -3) == -10);
    }

    SECTION("Add zero and a positive number") {
        REQUIRE(add(0, 8) == 8);
    }

    SECTION("Add zero and a negative number") {
        REQUIRE(add(0, -5) == -5);
    }

    SECTION("Add zero and zero") {
        REQUIRE(add(0, 0) == 0);
}
