#include "feUtils.h"
#include <cmath>

/**
 * Return: Random number from 0 to 99.
 */
int feUtils::feRNG() {
    static std::uniform_int_distribution<int> rng(0, 99);
    return rng(rand);
}

/**
 * Parameters:
 *    character_stats: vector of ints containing
 *    values of the necessary character/weapon stats needed
 *    for calculating the actual attack of a character
 *
 * Modifies: attack - use to calculate base attack without any modifiers
 *
 * Return: Nothing
 * Notes: Make sure to check whether using a physical or magical weapon prior to
 * using this method
 */
void feUtils::setBaseAttack(const std::vector<int>& character_stats) {
    attack = 0;
    std::vector<int>::const_iterator itr = character_stats.begin();
    for( ; itr != character_stats.end(); ++itr)
        attack += *itr;
}

/**
 * Parameters:
 *    weapon_stats: vector of ints containing
 *    values of the necessary character/weapon stats needed
 *    for calculating the actual hit rate of a character
 *    rank: a character representing a character's
 *    weapon rank (capital letter)
 *    buffOrDebuff: an integer representing whether it's
 *    debuff or buff to character
 *
 * Modifies: hit_rate - use to calculate base hit rate without
 * any modifiers
 *
 * Return: Nothing
 */
void feUtils::setBaseHitRate(const std::vector<int>& weapon_stats, const char rank, const int buffOrDebuff) {
    hit_rate = 0;
    hit_rate = weapon_stats[0] +
               ((weapon_stats[1] * 3) + ceil(weapon_stats[2])/2) +
               weapon_stats[4];
    weaponTriangle(rank, buffOrDebuff);
}

/**
 * Parameters:
 *    character_stats: vector of ints containing
 *    values of the necessary character/weapon stats needed
 *    for calculating the actual critical rate of a character
 *
 * Modifies: critical - use to calculate base critical chance without
 * any modifiers
 *
 * Return: Nothing
 */
void feUtils::setBaseCritical(const std::vector<int>& character_stats) {
    critical = 0;
    critical = character_stats[0] + ceil(character_stats[1]/2);
}

/**
 * Parameters:
 *    character_stats: vector of ints containing
 *    values of the necessary character/weapon stats needed
 *    for calculating the actual avoid rate of a character
 *
 * Modifies: avoid - use to calculate base avoid of character without
 * any modifiers
 *
 * Return: Nothing
 */
void feUtils::setBaseAvoid(const std::vector<int>& character_stats) {
    avoid = 0;
    avoid = ceil(((character_stats[0] * 3) + character_stats[1])/2);
}

/**
 * Parameters:
 *    character_stats: vector of ints containing
 *    values of the necessary character/weapon stats needed
 *    for calculating the rating of a character
 *
 * Modifies: rating - use to calculate base rating of character without
 * any modifiers
 *
 * Return: Nothing
 */
void feUtils::setBaseRating(const std::vector<int>& character_stats) {
    rating = 0;
    std::vector<int>::const_iterator itr = character_stats.begin();
    for( ; itr != character_stats.end(); ++itr)
        rating += *itr;
}

/**
 * Parameters:
 *      rank: a character representing a character's weapon rank (capital letter)
 *      buffOrDebuff: an integer representing whether it's debuff or buff to character
 *
 * Modifies: Calculates the weapon triangle buff of debuff for specified character when
 * about to initiate combat
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
            attack += 1;
        }
        else if(rank == 'A')
        {
            hit_rate -= 15;
            attack -= 1;
        }
    }
}

/**
 * Parameters:
 *      rank: a character representing a character's weapon rank (capital letter)
 *      weapon_type: a string specifying character's currently equipped weapon type
 *
 * Modifies: Calculates the additional weapon rank bonus for a character when
 * equipping a specific weapon type
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
