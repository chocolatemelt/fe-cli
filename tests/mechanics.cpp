/**
 * tests/mechanics.cpp
 * Generic mechanics tests.
 */

#include "catch.hpp"

#include "feMechanics.h"

TEST_CASE("Weapon triangle", "[feMechanics]") {
	feWeapon sword(0, 90, 12, true, "sword", "Silver Sword");
	feWeapon axe(0, 70, 16, true, "axe", "Silver Axe");
	feWeapon lance(0, 80, 14, true, "lance", "Silver Lance");

	SECTION("Weapon gets assigned correct color") {
		CHECK(feMechanics::getWeaponColor(sword) == 'r');
		CHECK(feMechanics::getWeaponColor(axe) == 'g');
		CHECK(feMechanics::getWeaponColor(lance) == 'b');
	}

	SECTION("Weapon triangle correctly trumps") {
		CHECK(feMechanics::weaponTriangle(sword, axe) == 1);
		CHECK(feMechanics::weaponTriangle(axe, lance) == 1);
		CHECK(feMechanics::weaponTriangle(lance, sword) == 1);
	}

	SECTION("Weapon triangle correctly fails") {
		CHECK(feMechanics::weaponTriangle(sword, lance) == -1);
		CHECK(feMechanics::weaponTriangle(axe, sword) == -1);
		CHECK(feMechanics::weaponTriangle(lance, axe) == -1);
	}

	SECTION("Weapon triangle correctly returns 0") {
		CHECK(feMechanics::weaponTriangle(sword, sword) == 0);
		CHECK(feMechanics::weaponTriangle(axe, axe) == 0);
		CHECK(feMechanics::weaponTriangle(lance, lance) == 0);
	}
}