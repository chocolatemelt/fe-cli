/**
 * tests/utils.cpp
 * Generic tests for the feUtils class.
 */

#include "catch.hpp"

#include "feUtils.h"

TEST_CASE("RNG correctly outputs 0-99", "[feUtils]") {
	std::vector<int> testVector;
	int a;
	for(int i = 0; i < 10000; ++i) {
		a = utils.feRNG();
		if(a >= 0 && a <= 99) testVector.push_back(a);
	}
	REQUIRE(testVector.size() == 10000);
}