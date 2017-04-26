/**
 * tests/character.cpp
 * Generic tests for the feCharacter class.
 */

#include "catch.hpp"

#include "feCharacter.h"

TEST_CASE("Character is constructed properly", "[feCharacter]") {
	feClass c;
	feCharacter test("Ma", "Marth", true, 'p', 'l', c);
	REQUIRE(test.printInfo() == "MaMarthmalep");
}

TEST_CASE("Character can assign buffs and reflect stat changes", "[feCharacter]") {
}