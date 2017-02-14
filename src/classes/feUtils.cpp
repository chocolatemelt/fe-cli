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
void feUtils::setBaseAttack(const std::vector<int>& character_stats) {
    attack = 0;
    std::vector<int>::const_iterator itr = character_stats.begin();
    for( ; itr != character_stats.end(); ++itr)
        attack += *itr;
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
void feUtils::setBaseHitRate(const std::vector<int>& weapon_stats, const char rank, const int buffOrDebuff) {
    hit_rate = 0;
    hit_rate = weapon_stats[0] +
               ((weapon_stats[1] * 3) + ceil(weapon_stats[2])/2) +
               weapon_stats[4];
    weaponTriangle(rank, buffOrDebuff);
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
void feUtils::setBaseCritical(const std::vector<int>& character_stats) {
    critical = 0;
    critical = character_stats[0] + ceil(character_stats[1]/2);
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
void feUtils::setBaseAvoid(const std::vector<int>& character_stats) {
    avoid = 0;
    avoid = ceil(((character_stats[0] * 3) + character_stats[1])/2);
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
void feUtils::setBaseRating(const std::vector<int>& character_stats) {
    rating = 0;
    std::vector<int>::const_iterator itr = character_stats.begin();
    for( ; itr != character_stats.end(); ++itr)
        rating += *itr;
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
