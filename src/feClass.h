#ifndef CLASS_H
#define CLASS_H

#include <string>
#include <unordered_map>
#include <vector>

#include "feSkill.h"
#include "feStats.h"

class feClass {
	private:
		std::string name;
		feStats base;
		feStats cap;
		feStats growth;

		std::vector<std::string> weaponTypes;

		std::vector<std::string> promotions; // possible classes to reclass to from here

		std::unordered_map<int, feSkill> classSkills; // map of level to learnable skill

		void initializeNameStats(std::string baseClassData);

	public:
		feClass();
		feClass(std::string baseClassData);
		std::string getClassName() { return name; }
		std::vector<std::string> getWeaponTypes() const;
		std::vector<std::string> getPromotions() const;
		feStats getBaseStats() { return base; }
		feStats getCapStats() { return cap; }
		feStats getGrowthStats() { return growth; }
};

#endif
