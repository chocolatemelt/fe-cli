#ifndef WEAPONRANK_H
#define WEAPONRANK_H

#include <unordered_map>

#include "feClass.h"
#include "feUtils.h"

class feWeaponRank {
	private:
		std::unordered_map< std::string, int > weaponRank;
	public:
		feWeaponRank(feClass j);
		std::string getWeaponRanks(feClass f);
		char getWeaponRank(std::string w);
		void incWEx(int xp);
};

#endif
