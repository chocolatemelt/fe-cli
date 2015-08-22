#include "feUtils.h"

/**
 * feUtils RNG uses the Mersenne Twister which should be
 * initialized only once before the game starts. Seeds based
 * on time which makes it somewhat predictable but it's
 * not a huge deal and a lot less hassle.
 */
 
feUtils::feUtils() {
	rand.seed(time(NULL));
}

feUtils::feUtils(std::string s) {
	std::seed_seq seed(s.begin(), s.end());
    rand.seed(seed);
}

/**
 * feRNG()
 * Gets random number from 0-99.
 */
int feUtils::feRNG() {
	static std::uniform_int_distribution<int> rng(0, 99);
	return rng(rand);
}