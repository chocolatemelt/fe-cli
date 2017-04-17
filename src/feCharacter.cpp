#include "feCharacter.h"

feCharacter::feCharacter(std::string id, std::string n, bool g, char l, char a, feClass j)
	: weaponRank(j) {
		uniqID = id;
		name = n;
		gender = g;
		loyalty = l;
		affinity = a;
		job = j;

		/* initialize stats */
		initStats(j);
	}

/**
 * initStats(feClass c)
 * Initializes stats (does nothing for stats otherwise).
 */
void feCharacter::initStats(feClass c) {
	feStats classbase = c.getBaseStats();
	base = classbase;
	current = base;
	bonus = base;

	feStats classgrowth = c.getGrowthStats();
	growth = classgrowth;
	feStats classcap = c.getCapStats();
	cap = classcap;
}

/**
 * printStats()
 * Simple printout of character information.
 */
std::string feCharacter::printInfo() {

	std::stringstream ss;
	std::string id;
	ss << uniqID;
	ss >> id;

	std::stringstream ll;
	std::string loy;
	ll << loyalty;
	ll >> loy;

	std::string g;
	if (gender == 0) g = "female";
	if (gender == 1) g = "male";

	return id + name + g + loy;
}
