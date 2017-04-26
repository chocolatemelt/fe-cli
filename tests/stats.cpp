/* test feStats class */

#include "catch.hpp"
#include "feStats.h"

TEST_CASE("feStats operation checks", "[feStats]") {
	feStats feStats1 = feStats::ZERO;
	feStats feStats2 = feStats::ZERO;

	feStats1.hp  = 9;
	feStats1.str = 8;
	feStats1.mag = 7;
	feStats1.skl = 6;
	feStats1.spd = 5;
	feStats1.lck = 4;
	feStats1.def = 3;
	feStats1.res = 2;
	feStats1.con = 1;
	feStats1.mov = 0;

	SECTION("defaults") {
		CHECK(feStats2.hp  == 0);
		CHECK(feStats2.str == 0);
		CHECK(feStats2.mag == 0);
		CHECK(feStats2.skl == 0);
		CHECK(feStats2.spd == 0);
		CHECK(feStats2.lck == 0);
		CHECK(feStats2.def == 0);
		CHECK(feStats2.res == 0);
		CHECK(feStats2.con == 0);
		CHECK(feStats2.mov == 0);
	}

	SECTION("equality comparison") {
		CHECK(feStats::ZERO == feStats2);
		CHECK(feStats2 == feStats::ZERO);
		CHECK(feStats1 == feStats1);
		CHECK(feStats2 == feStats2);
	}

	SECTION("flat assign") {
		feStats1.flatassign(0);
		CHECK(feStats1 == feStats::ZERO);
	}

	SECTION("assignment check") {
		feStats1 = feStats2;
		CHECK(feStats1 == feStats2);
	}

	SECTION("addition check") {
		feStats feStats3 = feStats1 + feStats2;
		CHECK(feStats3 == feStats1);

		feStats1 += feStats3;
		CHECK(feStats1.hp  == 18);
		CHECK(feStats1.str == 16);
		CHECK(feStats1.mag == 14);
		CHECK(feStats1.skl == 12);
		CHECK(feStats1.spd == 10);
		CHECK(feStats1.lck == 8);
		CHECK(feStats1.def == 6);
		CHECK(feStats1.res == 4);
		CHECK(feStats1.con == 2);
		CHECK(feStats1.mov == 0);
	}

	SECTION("multiplication check") {
		feStats feStats3 = feStats1 * feStats2;
		CHECK(feStats3 == feStats::ZERO);

		feStats1 *= feStats3;
		CHECK(feStats1 == feStats::ZERO);
	}

	SECTION("subtraction check") {
		feStats feStats3 = feStats1 - feStats2;
		feStats feStats4 = feStats2 - feStats1;

		CHECK(feStats3 == feStats1);
		CHECK(feStats4.hp  == -9);
		CHECK(feStats4.str == -8);
		CHECK(feStats4.mag == -7);
		CHECK(feStats4.skl == -6);
		CHECK(feStats4.spd == -5);
		CHECK(feStats4.lck == -4);
		CHECK(feStats4.def == -3);
		CHECK(feStats4.res == -2);
		CHECK(feStats4.con == -1);
		CHECK(feStats4.mov ==  0);

		feStats1 -= feStats2;
		CHECK(feStats1 == feStats3);

		feStats1 -= feStats1;
		CHECK(feStats1 == feStats::ZERO);
	}

	SECTION("division") {
		feStats2.flatassign(2);
		feStats feStats3 = feStats1 * feStats2;

		feStats feStats4 = feStats3 / feStats2;
		CHECK(feStats4 == feStats1);

		feStats3 /= feStats2;
		CHECK(feStats3 == feStats1);

		feStats1 = feStats1 / feStats::ZERO;
		CHECK(feStats1 == feStats::ZERO);
	}

	SECTION("modulus") {
		feStats2.flatassign(2);
		feStats feStats3 = feStats1 * feStats2;
		feStats1.flatassign(1);
		feStats3 += feStats1;

		feStats feStats4 = feStats3 % feStats2;
		CHECK(feStats4 == feStats1);
	}
};