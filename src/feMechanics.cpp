#include "feMechanics.h"

std::map<std::string, feMechanics::WeaponType> feMechanics::mapStringToWeaponType = {
	{ "sword", WeaponType::Sword },
	{ "tome", WeaponType::Tome },
	{ "axe", WeaponType::Axe },
	{ "bow", WeaponType::Bow },
	{ "lance", WeaponType::Lance },
	{ "dagger", WeaponType::Dagger },
	{ "none", WeaponType::None }
};

std::map<feMechanics::WeaponType, std::string> feMechanics::mapWeaponTypeToString = {
	{ WeaponType::Sword, "sword" },
	{ WeaponType::Tome, "tome" },
	{ WeaponType::Axe, "axe" },
	{ WeaponType::Bow, "bow" },
	{ WeaponType::Lance, "lance" },
	{ WeaponType::Dagger, "dagger" },
	{ WeaponType::None, "none" }
};

/**
 * int getBaseAttack()
 * @param
 *    stats: feStats of the character
 *    weapon: feWeapon to be used for calculation
 *
 * @return base attack damage
 */
int feMechanics::getBaseAttack(const feStats& stats, const feWeapon &weapon) {
	int attack = 0;
	if(weapon.isPhysical()) {
		attack += stats.str;
	}
	else {
		attack += stats.mag;
	}
	attack += weapon.getMight();
	return attack;
}

/**
 * int getBaseHitRate()
 * @param
 *    stats: feStats of the character
 *    weapon: feWeapon to be used for calculation
 *
 * @return base hitrate
 */
int feMechanics::getBaseHitRate(const feStats &stats, const feWeapon &weapon) {
	int hitrate = ((stats.skl * 3) + stats.lck) / 2;
	hitrate += weapon.getHitrate();
	return hitrate;
}

/**
 * int getBaseCritical()
 * @param
 *    stats: feStats of the character
 *    weapon: feWeapon to be used for calculation
 *
 * @return base critical chance
 */
int feMechanics::getBaseCritical(const feStats &stats, const feWeapon &weapon) {
	int critical = stats.skl / 2;
	critical += weapon.getCritical();
	return critical;
}

/**
 * int getBaseAvoid()
 * @param
 *    stats: feStats of the character
 *
 * @return base avoid
 */
int feMechanics::getBaseAvoid(const feStats &stats) {
	int avoid = (stats.spd * 3 + stats.lck) / 2;
	return avoid;
}

/**
 * int getBaseRating()
 * @param
 *    stats: feStats object
 *    isPhys: determines str or mag use
 *
 * @return base rating, calculated from the character stats and selected weapon
 */
int feMechanics::getBaseRating(const feStats &stats, const feWeapon &weapon) {
	int rating = 0;
	if(weapon.isPhysical()) {
		rating += stats.str + stats.skl + stats.spd + stats.lck +
		          stats.def + stats.res;
	}
	else {
		rating += stats.mag + stats.skl + stats.spd + stats.lck +
		          stats.def + stats.res;
	}
	return rating;
}

/**
 * get
 * @param weapon 
 * @return 
 */
char feMechanics::getWeaponColor(const feWeapon &weapon) {
	// in order to gracefully handle most weapon types, we convert them to colors: 'r', 'g', 'b', 'n' (neutral)
	// see the enum and mappings defined in the header file for details
	WeaponType type = mapStringToWeaponType[weapon.getType()];
	switch(type) {
		case WeaponType::Sword: case WeaponType::Tome:
			return 'r';
		case WeaponType::Axe: case WeaponType::Bow:
			return 'g';
		case WeaponType::Lance: case WeaponType::Dagger:
			return 'b';
		case WeaponType::None:
			return 'n';
	}
}

/**
 * void calculateWeaponTriangle()
 * Calculates the weapon triangle buffs and debuffs for each involved character.
 * @param
 *      rank: a character representing a character's weapon rank (capital letter)
 *      buff: an integer representing whether it's debuff or buff to character

void feMechanics::calculateWeaponTriangle(const feWeapon &, const feWeapon &, int &, int &) {
	// Buff
	if(buff == 1) {
		switch(rank) {
			default:        //no rank provided
				break;
			case 'E':       //otherwise provide bonus according to rank
				hit_rate += 5;
				break;
			case 'D':
				hit_rate += 5;
				break;
			case 'C':
				hit_rate += 10;
				break;
			case 'B':
				hit_rate += 10;
				attack += 1;
				break;
			case 'A':
				hit_rate += 15;
				attack += 1;
				break;
		}
	}
		// Debuff
	else {
		switch(rank) {
			default:        //no rank provided
				break;
			case 'E':       //otherwise provide bonus according to rank
				hit_rate -= 5;
				break;
			case 'D':
				hit_rate -= 5;
				break;
			case 'C':
				hit_rate -= 10;
				break;
			case 'B':
				hit_rate -= 10;
				attack -= 1;
				break;
			case 'A':
				hit_rate -= 15;
				attack -= 1;
				break;
		}
	}
} */

/**
 * int weaponTriangle()
 * Checks the weapon triangle precedence.
 * @param
 *      attacker: attacker's weapon
 *      defender: defender's weapon
 *
 * @return 1 if attacker advantage, 0 if no advantage, and -1 if attacker disadvantage
 */
int feMechanics::weaponTriangle(const feWeapon &attacker, const feWeapon &defender) {
	char attackerColor = getWeaponColor(attacker);
	char defenderColor = getWeaponColor(defender);
	// same weapon type (color)
	if(attackerColor == defenderColor) return 0;
	// empty weapon type / neutral
	else if(attackerColor == 'n' || defenderColor == 'n') return 0;
	// attacker superior
	else if(attackerColor == 'r' && defenderColor == 'g'
		|| attackerColor == 'g' && defenderColor == 'b'
		|| attackerColor == 'b' && defenderColor == 'r') return 1;
	// default case / defender superior
	else return -1;
}

/**
 * void weaponRankBonus()
 * Calculates the additional weapon rank bonus for a character when
 * equipping a specific weapon type
 * @param
 *      rank: a character representing a character's weapon rank (capital letter)
 *      weapon_type: a string specifying character's currently equipped weapon type

void feMechanics::weaponRankBonus(const char rank, const std::string &weapon_type) {
	if (weapon_type == "Sword") {
		switch (rank) {
			default:
				break;
			case 'A':
				attack += 3;
			case 'B':
				attack += 2;
			case 'C':
				attack += 1;
		}
	} else if (weapon_type == "Lance" || weapon_type == "Bow" || weapon_type == "Tome") {
		switch (rank) {
			default:
				break;
			case 'A':
				attack += 2;
				hit_rate += 5;
				break;
			case 'B':
				attack += 1;
				hit_rate += 5;
				break;
			case 'C':
				attack += 1;
				break;
		}
	} else if (weapon_type == "Axe") {
		switch (rank) {
			default:
				break;
			case 'A':
				attack += 1;
				hit_rate += 10;
				break;
			case 'B':
				hit_rate += 10;
				break;
			case 'C':
				hit_rate += 5;
				break;
		}
	} else if (weapon_type == "Staff") {
		switch (rank) {
			default:
				break;
			case 'A':
				recovery_amount += 3;
				break;
			case 'B':
				recovery_amount += 2;
				break;
			case 'C':
				recovery_amount += 1;
				break;
		}
	}
} */