#ifndef UTILS_H
#define UTILS_H

#include "feStats.h"

#include <random>
#include <string>
#include <time.h>
#include <vector>

class feUtils {
	public:
		std::mt19937 rand;

		feUtils() {
			rand.seed(time(NULL));
			attack = 0;
			hit_rate = 0;
			critical = 0;
			avoid = 0;
			rating = 0;
			recovery_amount = 0;
		}

		feUtils(std::string s) {
			std::seed_seq seed(s.begin(), s.end());
			rand.seed(seed);
			attack = 0;
			hit_rate = 0;
			critical = 0;
			avoid = 0;
			rating = 0;
			recovery_amount = 0;
		}

		int feRNG();

		// For now keeping combat algorithms here - might need to move
		// Observers
		// Returns the final value with all bonuses or debuffs included
		int getAttack() { return attack; }
		int getHitRate() { return hit_rate; }
		int getCritical() { return critical; }
		int getAvoid() { return avoid; }
		int getRating() { return rating; }

		// Mutators
		void setBaseAttack(const feStats& character_stats, bool isPhys, int mt);
		void setBaseHitRate(const feStats& character_stats, int hr);
		void setBaseCritical(const feStats& character_stats, int crit);
		void setBaseAvoid(const feStats& character_stats);
		void setBaseRating(const feStats& character_stats, bool isPhys);

		void weaponTriangle(const char rank, const int buff);
		void weaponRankBonus(const char rank, const std::string &weapon_type);

	private:
		// Combat Stats
		int attack;
		int hit_rate;
		int critical;
		int avoid;
		int rating;

		//Healing related variables
		int recovery_amount;
};

#endif
