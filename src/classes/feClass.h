#ifndef CLASS_H
#define CLASS_H

#include <vector>
#include <string>
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
    void initializeNameStats(std::string baseClassData);

protected:
    std::string class_name; // Name of class

	//doesnt character have several stat members?
    feStats base_stats; // HP, Str, Mag, Skl, Spd, Def, Res, Mov
    feStats max_stats; // Lvl, HP, Str, Mag, Skl, Spd, Def, Res, use 0 on mov?
    feStats growth_rates; // HP, Str, Mag, Skl, Spd, Def, Res

    std::vector<std::string> weapon_types; // Usable weapon types

    std::vector<std::string> promotion_classes; // Vector of possible classes to promote to

    bool special; // True = special class -> item, False = standard class
    std::string special_item; // Needed special item to change into class

	//maybe add tuple for skill and level learned?
    std::vector<feSkill> class_skills; // Vector of class skills

    bool class_weakness; // True = weak to something, False = no weakness
    std::string weakness; // Not really what it's weak to, but what makes it weak to things

public:
		feClass();
    feClass(std::string baseClassData);
    std::string getClassName();
};

#endif
