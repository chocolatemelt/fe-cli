#ifndef UTILS_H
#define UTILS_H

#include <random>
#include <string>
#include <time.h>
#include <vector>

#include "feStats.h"

class feUtils {
	public:
		std::mt19937 rand;

		feUtils() {
			rand.seed(time(NULL));
		}

		feUtils(std::string s) {
			std::seed_seq seed(s.begin(), s.end());
			rand.seed(seed);
		}

		int feRNG();
};

#endif
