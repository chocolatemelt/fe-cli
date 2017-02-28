#include "feWeaponRank.h"

/**
 * feWeaponRank(feClass j)
 * The only constructor available for feWeaponRank, which inserts
 * a new item for each weapon supplied by feClass.
 */
feWeaponRank::feWeaponRank(feClass j) {
	for(auto w : j.getWeaponTypes()) {
		std::pair< std::string, int > weapon(w, 0);
		weaponRank.insert(weapon);
	}
}
