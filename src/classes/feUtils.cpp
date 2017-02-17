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
 *    character_stats: vector of ints containing
 *    values of the necessary character/weapon stats needed
 *    for calculating the actual attack of a character
 *
 * @modifies attack - use to calculate base attack without any modifiers
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
 *    weapon_stats: vector of ints containing
 *    values of the necessary character/weapon stats needed
 *    for calculating the actual hit rate of a character
 *    rank: a character representing a character's
 *    weapon rank (capital letter)
 *    buffOrDebuff: an integer representing whether it's
 *    debuff or buff to character
 *
 * @modifies hit_rate - use to calculate base hit rate without
 * any modifiers
 */
void feUtils::setBaseHitRate(const feStats& character_stats, int hr) {
    hit_rate = 0;
    hit_rate += ((character_stats.skl * 3) + character_stats.lck) / 2;
    hit_rate += hr;
}

/**
 * void setBaseCritical()
 * @param
 *    character_stats: vector of ints containing
 *    values of the necessary character/weapon stats needed
 *    for calculating the actual critical rate of a character
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
 *    character_stats: vector of ints containing
 *    values of the necessary character/weapon stats needed
 *    for calculating the actual avoid rate of a character
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
 *    character_stats: vector of ints containing
 *    values of the necessary character/weapon stats needed
 *    for calculating the rating of a character
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
 *      buffOrDebuff: an integer representing whether it's debuff or buff to character
 */
void feUtils::weaponTriangle(const char rank, const int buffOrDebuff) {
    // Buff
    if(buffOrDebuff == 1)
    {
        if(rank == 'E' || rank == 'D')
            hit_rate += 5;
        else if(rank == 'C')
            hit_rate += 10;
        else if(rank == 'B')
        {
            hit_rate += 10;
            attack += 1;
        }
        else if(rank == 'A')
        {
            hit_rate += 15;
            attack += 1;
        }
    }
    // Debuff
    else
    {
        if(rank == 'E' || rank == 'D')
            hit_rate -= 5;
        else if(rank == 'C')
            hit_rate -= 10;
        else if(rank == 'B')
        {
            hit_rate -= 10;
            attack -= 1;
        }
        else if(rank == 'A')
        {
            hit_rate -= 15;
            attack -= 1;
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
        if(rank == 'A')
            attack += 3;
        else if(rank == 'B')
            attack += 2;
        else if(rank == 'C')
            attack += 1;
    }
    else if(weapon_type == "Lance" || weapon_type == "Bow" || weapon_type == "Tome")
    {
        if(rank == 'A')
        {
            attack += 2;
            hit_rate += 5;
        }
        else if(rank == 'B')
        {
            attack += 1;
            hit_rate += 5;
        }
        else if(rank == 'C')
            attack += 1;
    }
    else if(weapon_type == "Axe")
    {
        if(rank == 'A')
        {
            attack += 1;
            hit_rate += 10;
        }
        else if(rank == 'B')
            hit_rate += 10;
        else if(rank == 'C')
            hit_rate += 5;
    }
    else if(weapon_type == "Staff")
    {
        if(rank == 'A')
            recovery_amount += 3;
        else if (rank == 'B')
            recovery_amount += 2;
        else if(rank == 'C')
            recovery_amount += 1;
    }
}
