#ifndef CHARACTER_H
#define CHARACTER_H

#include <sstream>
#include <string>
#include <vector>

#include "feClass.h"
#include "feItem.h"
#include "feRank.h"
#include "feSkill.h"
#include "feStats.h"
#include "feSupport.h"

class feCharacter {
  private:
		std::string uniqID; // unique identifier for the character on the map
    std::string name;   // display name
    bool gender;        // 0: female, 1: male
    char loyalty;       // 'p': player, 'a': ally, 'e': enemy, else neutral
		char affinity;      // 'a'nima, 'd'ark, 'f'ire, 'i'ce, 'l'ight, 't'hunder, 'w'ind, 'h'eaven
    feClass job;        // character class

    feSupport supports; // support bonds from C - S/A+, see feSupport.h
                        // support other class or characters?
    feRank weaponRank;  // weapon proficiency from E-S, see feRank.h

    /**
     * STATS
     * Stats and stat growths are each unordered maps. Keys should not
     * be added or removed. This removes the need for publicly
     * exposed variables and/or vast amounts of mutator/accessor
     * methods for each stat while also providing amortized
     * O(1) lookups.
     * Base stats can be anything.
     * Base caps modify the class caps. Reasonable numbers should
     * be single digits (positive or negative).
     * Growths modify the class growths. I'm not sure if this is how it actually works.
     * Current does NOT include bonuses for easier outputting.
     */
    int current_lvl;    // Level of character
    int internal_lvl;   // Total number of levels overall
    //use this stat member
    //refer to class stat member for max?
    feStats base;       // base stats of the unit
    feStats cap;        // capped maximum stat modifiers
    feStats current;    // current stats of the unit (without bonuses)
    feStats bonus;      // bonus stats given to the unit
    feStats growth;     // stat growths of the unit
    int current_experience;     // Current amount of experience till leveling up
    //add another wepstat class? or weapons share same stats class as players
    //stats weapon_experience;    // Current amount of experience for each weapon type till leveling up

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
    /**
     * Instead of making an feClass that just returns a character
     * Just have feCharacter extend from feClass and then implement any necessary
     * details.
     */
    feCharacter(std::string id, std::string n, bool g, char l, char a, feClass j);
    //init uses feStats methods but its a struct
    void initStats();
    std::string printInfo();
};

#endif
