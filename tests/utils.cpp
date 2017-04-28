/**
 * tests/utils.cpp
 * Generic tests for the feUtils class.
 */

#include <iostream>
#include "catch.hpp"

#include "feUtils.h"

TEST_CASE("RNG correctly outputs 0-99", "[feUtils]") {
	feUtils utils;
	std::vector<int> testVector;

	std::cout << "[feUtils]: Check distribution:" << std::endl;
	int a;
	for(int i = 0; i < 10000; ++i) {
		a = utils.feRNG();
		std::cout << a << " ";
		if(a >= 0 && a <= 99) testVector.push_back(a);
	}
	std::cout << std::endl;

	REQUIRE(testVector.size() == 10000);
}