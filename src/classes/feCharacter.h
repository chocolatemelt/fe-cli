#ifndef CHARACTER_H
#define CHARACTER_H

#include <sstream>
#include <string>
#include <vector>

#include "feClass.h"
#include "feItem.h"
#include "feSkill.h"
#include "feStats.h"
#include "feSupport.h"
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
     * Base stats can be anything.
     * Base caps modify the class caps. Reasonable numbers should be single digits.
     * Growths modify the class growths. I'm not sure if this is how it actually works.
     * A character's current stats are calculated from these stats and the class stats.
     */
    int current_lvl;    // Level of character
    int internal_lvl;   // Total number of levels overall
    feStats base;       // base stats of the unit
    feStats current;    // current stats
    feStats cap;        // capped maximum stat modifiers
    feStats bonus;      // bonus stats given to the unit
    feStats growth;     // stat growths of the unit
    int current_experience;     // Current amount of experience till leveling up

    /**
     * SKILLS
     * Skills are simply composed of two vectors - one for active skills
     * and another for inactive skills.
     * Learning them is handled by the feClass.
     */
    std::vector< feSkill > activeSkills;
    std::vector< feSkill > inactiveSkills;

    /**
     * ITEMS
     * Items - including weapons - are also stored in a vector. The vector
     * size should always be within 0 and 5.
     * The equipped weapon is just a pointer to an item in the vector.
     * Note that convoy items are stored in the feRoster object, and
     * not on any characters.
     */
    std::vector< feItem * > bag;
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
    void initStats(feClass c);
    std::string printInfo();

    feStats getBaseStats() const { return base; }
    feStats getCapStats() const { return cap; }
    feStats getBonusStats() const { return bonus; }
    feStats getGrowthStats() const { return growth; }

    void addBonuses(feStats b);
};

#endif
