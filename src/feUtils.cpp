#include "feUtils.h"

#include <cmath>

/**
 * int feRNG()
 * @return Random number from 0 to 99.
 */
int feUtils::feRNG() {
	static std::uniform_int_distribution<int> rng(0, 99);
	return rng(rand);
}

/**
 * void setBaseAttack()
 * NOTE: Make sure to check whether using a physical or magical weapon prior to
 * using this method
 * @param
 *    character_stats: feStats object which has character str/mag
 *    isPhys: determines str or mag use
 *    mt: weapon bonus
 *
 * @modifies attack - use to calculate base attack
 */
void feUtils::setBaseAttack(const feStats& character_stats, bool isPhys, int mt) {
	attack = 0;
	if (isPhys){
		attack += character_stats.str;
	}
	else{
		attack += character_stats.mag;
	}
	attack += mt;
}

/**
 * void setBaseHitRate()
 * @param
 *    weapon_stats: feStats object with skl and lck stats
 *    hr: weapon hit rate
 *
 * @modifies hit_rate - use to calculate base hit rate
 */
void feUtils::setBaseHitRate(const feStats& character_stats, int hr) {
	hit_rate = 0;
	hit_rate += ((character_stats.skl * 3) + character_stats.lck) / 2;
	hit_rate += hr;
}

/**
 * void setBaseCritical()
 * @param
 *    character_stats: feStats object with skl
 *    crit: weapon critical rate
 *
 * @modifies critical - use to calculate base critical chance without
 * any modifiers
 */
void feUtils::setBaseCritical(const feStats& character_stats, int crit) {
	critical = 0;
	critical += character_stats.skl / 2;
	critical += crit;
}

/**
 * void setBaseAvoid()
 * @param
 *    character_stats: feStats object with spd and lck
 *
 * @modifies avoid - use to calculate base avoid of character without
 * any modifiers
 */
void feUtils::setBaseAvoid(const feStats& character_stats) {
	avoid = 0;
	avoid += (character_stats.spd * 3 + character_stats.lck) / 2;
}

/**
 * void setBaseRating()
 * @param
 *    character_stats: feStats object
 *    isPhys: determines str or mag use
 *
 * @modifies rating - use to calculate base rating of character without
 * any modifiers
 *
 * @return nothing
 */
void feUtils::setBaseRating(const feStats& character_stats, bool isPhys) {
	rating = 0;
	if (isPhys){
		rating += character_stats.str + character_stats.skl + character_stats.spd + character_stats.lck +
			character_stats.def + character_stats.res;
	}
	else{
		rating += character_stats.mag + character_stats.skl + character_stats.spd + character_stats.lck +
			character_stats.def + character_stats.res;
	}
}

/**
 * void weaponTriangle()
 * Calculates the weapon triangle buff of debuff for specified character when
 * about to initiate combat
 * @param
 *      rank: a character representing a character's weapon rank (capital letter)
 *      buff: an integer representing whether it's debuff or buff to character
 */
void feUtils::weaponTriangle(const char rank, const int buff)
{
	// Buff
	if(buff == 1)
	{
		switch (rank)
		{
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
	else
	{
		switch (rank)
		{
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
}

/**
 * void weaponRankBonus()
 * Calculates the additional weapon rank bonus for a character when
 * equipping a specific weapon type
 * @param
 *      rank: a character representing a character's weapon rank (capital letter)
 *      weapon_type: a string specifying character's currently equipped weapon type
 */
void feUtils::weaponRankBonus(const char rank, const std::string &weapon_type)
{
	if(weapon_type == "Sword")
	{
		switch (rank)
		{
			default:
				break;
			case 'A':
				attack += 3;
			case 'B':
				attack += 2;
			case 'C':
				attack += 1;
		}
	}
	else if(weapon_type == "Lance" || weapon_type == "Bow" || weapon_type == "Tome")
	{
		switch (rank)
		{
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
	}
	else if(weapon_type == "Axe")
	{
		switch (rank)
		{
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
	}
	else if(weapon_type == "Staff")
	{
		switch (rank)
		{
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
}
