#ifndef CHARACTER_H
#define CHARACTER_H

#include <algorithm>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "feBuff.h"
#include "feClass.h"
#include "feItem.h"
#include "feSkill.h"
#include "feStats.h"
#include "feSupport.h"
#include "feWeapon.h"
#include "feWeaponRank.h"

class feCharacter {
	private:
		std::string uniqID; // unique identifier for the character on the map
		std::string name;   // display name
		bool gender;        // 0: female, 1: male
		char loyalty;       // 'p': player, 'a': ally, 'e': enemy, else neutral
		char affinity;      // 'a'nima, 'd'ark, 'f'ire, 'i'ce, 'l'ight, 't'hunder, 'w'ind, 'h'eaven
		feClass job;        // character class

		feSupport supports; // support bonds from C - S/A+, see feSupport.h
		feWeaponRank weaponRank;  // weapon proficiency from E-S, see feRank.h

		/**
		 * STATS
		 * Base stats are completely unmodified, i.e. excluding class skills.
		 * Bonus stats include the rest, such as HP tonics, the HP+5 skill, etc.
		 * Bonus stats are not the same as buffs / debuffs.
		 * Buffs and debuffs implementation TBD.
		 * Base caps modify the class caps. Reasonable numbers should be single digits.
		 * Growths modify the class growths.
		 * A character's starting stats are calculated from base stats and bonus stats.
		 * A character's current stats are modified by damage, weapons, and bonuses
		 */
		int current_lvl;    // level of character
		int internal_lvl;   // total number of levels overall
		feStats base;       // base stats of the unit
		feStats current;    // current stats
		feStats cap;        // capped maximum stat modifiers
		feStats bonus;      // bonus stats given to the unit
		feStats growth;     // stat growths of the unit
		std::vector<std::shared_ptr<feBuff>> buffs; // bonuses applied to this character
		int current_experience; // current amount of experience till leveling up

		/**
		 * COMBAT STATS
		 * These are secondary stats modified by current stats and weapons.
		 * These are the bases used in many of the combat calculations used.
		 */
		int attack;
		int avoid;
		int critical;
		int hitrate;

		/**
		 * SKILLS
		 * Skills are simply composed of two vectors - one for active skills
		 * and another for inactive skills.
		 * Learning them is handled by the feClass.
		 */
		std::vector<feSkill> activeSkills;
		std::vector<feSkill> inactiveSkills;

		/**
		 * ITEMS
		 * Items - including weapons - are also stored in a vector. The vector
		 * size should always be within 0 and 5.
		 * The equipped weapon is just a pointer to an item in the vector.
		 * Note that convoy items are stored in the feRoster object, and
		 * not on any characters.
		 */
		std::vector<feItem *> bag;
		feItem *equipped;

		/**
		 * PAIRING
		 * Probably not the best solution? Open to suggestions.
		 * When paired, both units will have a pair pointer to the other.
		 * One will be flagged as the main and the other will be implied
		 * as the secondary. If the units switch, we just have to toggle
		 * the flags and switch the bonuses.
		 * I have no idea how we will display a pair.
		 */
		feCharacter *pair;
		bool mainPair;

	public:
		feCharacter(std::string id, std::string n, bool g, char l, char a, feClass j);

		void buff(feBuff);
		void equip(feWeapon *);
		void initStats(feClass c);
		std::string printInfo();
		void recalculateStats();
		void resetStats();
		void tick();

		feStats getBaseStats() const { return base; }
		feStats getCapStats() const { return cap; }
		feStats getBonusStats() const { return bonus; }
		feStats getGrowthStats() const { return growth; }
};

#endif
