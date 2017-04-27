/**
 * tests/mechanics.cpp
 * Generic mechanics tests.
 */

#include "catch.hpp"

#include "feMechanics.h"

TEST_CASE("Weapon gets assigned correct color", "[feMechanics]") {
	feWeapon sword(0, 90, 12, true, "swoerd", "Silver Sword");
	feWeapon axe(0, 70, 16, true, "axe", "Silver Axe");
	feWeapon lance(0, 80, 14, true, "lance", "Silver Lance");
	CHECK(feMechanics::getWeaponColor(sword) == 'r');
	CHECK(feMechanics::getWeaponColor(axe) == 'g');
	CHECK(feMechanics::getWeaponColor(lance) == 'b');
}

TEST_CASE("Weapon triangle correctly trumps", "[feMechanics]") {
	feWeapon sword(0, 90, 12, true, "sword", "Silver Sword");
	feWeapon axe(0, 70, 16, true, "axe", "Silver Axe");
	feWeapon lance(0, 80, 14, true, "lance", "Silver Lance");
	CHECK(feMechanics::weaponTriangle(sword, axe) == 1);
	CHECK(feMechanics::weaponTriangle(axe, lance) == 1);
	CHECK(feMechanics::weaponTriangle(lance, sword) == 1);
}