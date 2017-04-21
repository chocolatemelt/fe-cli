#include "feUtils.h"

/**
 * int feRNG()
 * @return Random number from 0 to 99.
 */
int feUtils::feRNG() {
	static std::uniform_int_distribution<int> rng(0, 99);
	return rng(rand);
}