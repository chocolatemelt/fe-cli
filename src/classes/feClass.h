#ifndef CLASS_H
#define CLASS_H

#include <string>
#include <unordered_map>
#include <vector>

#include "feSkill.h"
#include "feStats.h"

/**
 * Barebones class: will read in data about each class into a map and store in
 * memory at the start as a map of classes.  Since each character's official
 * stats must be taken from a conglomeration of class stats and base stats,
 * have characters define the getters/setters of their stats.
 */
class feClass
{
private:
    std::string name;
    feStats base;
    feStats cap;
    feStats growth;

    std::vector<std::string> weaponTypes;

    std::vector<std::string> promotions; // possible classes to reclass to from here

    std::unordered_map<feSkill, int> classSkills; // map of skills to level required

	void initializeNameStats(std::string baseClassData);

public:
	feClass();
    feClass(std::string baseClassData);
    std::string getClassName();
	std::vector<std::string> getWeaponTypes() const;
	feStats getBaseStats() { return base; }
	feStats getCapStats() { return cap; }
	feStats getGrowthStats() { return growth; }
};

#endif
