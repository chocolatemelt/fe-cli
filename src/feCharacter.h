#ifndef CHARACTER_H
#define CHARACTER_H

#include <unordered_map>
#include <string>
#include <vector>

#include "feClass.h"
#include "feSkill.h"
#include "feItem.h"

typedef std::unordered_map< string, char > dict;
typedef std::unordered_map< string, int > stats;

class feCharacter {
  private:
    char uniqID;       // unique identifier for the character on the map
    std::string name;  // display name
    bool gender;       // 0: female, 1: male
    char loyalty;      // 'p': player, 'a': ally, 'e': enemy, else neutral
    feClass job;       // character class

    dict supports;     // support bonds from C-S, where string identifies character
    dict weaponRank;   // weapon proficiency from E-S, where string identifies type

    /**
     * STATS
     * Stats and stat growths are each unordered maps. Keys should not
     * be added or removed. This removes the need for publicly
     * exposed variables and/or vast amounts of mutator/accessor
     * methods for each stat while also providing amortized
     * O(1) lookups.
     */
    stats base;        // base stats of the unit
    stats cap;         // capped maximum stats of the unit
    stats current;     // current stats of the unit
    stats bonus;       // bonus stats given to the unit
    std::unordered_map< string, double > growth;    // stat growths of the unit

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
    std::vector< feItem > bag;
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
    feCharacter()
};

#endif
