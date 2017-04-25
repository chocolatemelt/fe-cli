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
 * void buff(feBuff buff)
 * Creates a new buff as a smart pointer and adds it to the buff vector.
 * Note that buffs refer to both buffs AND debuffs.
 * @param
 *     buff - the applied buff
 */
void feCharacter::buff(feBuff b) {
	std::shared_ptr<feBuff> buff = std::make_shared<feBuff>(b);
	buffs.push_back(buff);
}

/**
 * void equip(feWeapon *weapon)
 * Equips a new weapon, with the precondition that the weapon is already in the bag of the character.
 * Naturally, you should not be able to equip from a bag, trade, other character, or directly from drops.
 * @param
 *     weapon - equippable item in bag
 */
void feCharacter::equip(feWeapon *weapon) {
	// TODO: impl
}

/**
 * void initStats(feClass c)
 * Initializes stats (does nothing for stats otherwise).
 * @param
 *     c - class to initialize stats with
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
 * string printStats()
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


/**
 * void recalculateStats()
 * Recalculates all stats, including secondary combat stats.
 */
void feCharacter::recalculateStats() {
	// TODO: update the current stats of the character
}

/**
 * void resetStats()
 * Resets stats to default state; useful to run as a post-map hook.
 */
void feCharacter::resetStats() {
	bonus = feStats::ZERO;
	buffs.clear();
	// TODO: update current stats of the character
}

/**
 * void tick()
 * Ticks by one for all time-related buffs.
 * @modifies
 *     buffs - decrements them by one tick (if applicable) and deletes them at 0
 */
void feCharacter::tick() {
	// remove_if moves elements to be deleted to the back, pointing towards the first one
	// erase removes the subsection from remove_if to the end, which should be all finished ticks
	buffs.erase(std::remove_if(buffs.begin(), buffs.end(), [](std::shared_ptr<feBuff> b) { return b->tick(); }), buffs.end());
}
