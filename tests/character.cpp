/**
 * tests/character.cpp
 * Generic tests for the feCharacter class.
 */

#include "catch.hpp"

#include "feCharacter.h"

TEST_CASE("feCharacter tests", "[feCharacter]") {
	feCharacter marth("Ma", "Marth", true, 'p', 'l', feClass::NONE);
	feCharacter lucina("Lu", "Lucina", false, 'e', 'l', feClass::NONE);

	SECTION("Construction") {
		CHECK(marth.printInfo() == "MaMarthmalep");
		CHECK(lucina.printInfo() == "LuLucinafemalee");
	}
}