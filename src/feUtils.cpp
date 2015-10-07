#include "feUtils.h"
#include <vector>
#include <cmath>

/**
 * Parameters:
 *    character_stats: vector of ints containing
 *    values of the necessary character/weapon stats needed
 *    for calculating the actual attack of a character
 *
 * Return: Nothing
 */
void feUtils::setAttack(const std::vector<int>& character_stats) {
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
 * Return: Nothing
 */
void feUtils::setHitRate(const std::vector<int>& weapon_stats, const char rank, const int buffOrDebuff) {
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
 * Return: Nothing
 */
void feUtils::setCritical(const std::vector<int>& character_stats) {
    critical = 0;
    critical = character_stats[0] + ceil(character_stats[1]/2);
}

/**
 * Parameters:
 *    character_stats: vector of ints containing
 *    values of the necessary character/weapon stats needed
 *    for calculating the actual avoid rate of a character
 *
 * Return: Nothing
 */
void feUtils::setAvoid(const std::vector<int>& character_stats) {
    avoid = 0;
    avoid = ceil(((character_stats[0] * 3) + character_stats[1])/2);
}

/**
 * Parameters:
 *    character_stats: vector of ints containing
 *    values of the necessary character/weapon stats needed
 *    for calculating the rating of a character
 *
 * Return: Nothing
 */
void feUtils::setRating(const std::vector<int>& character_stats) {
    rating = 0;
    std::vector<int>::const_iterator itr = character_stats.begin();
    for( ; itr != character_stats.end(); ++itr)
        rating += *itr;
}

/**
 * Parameters: None
 *
 * Modifies: Sets all the combat stats back to zero.  Use when a
 * character level ups or changes weapons, so that the proper values
 * can be recalculated
 *
 * Notes: Might not be needed if at the start of every "set" method,
 * resets the specified stat to 0 to calculate, since most likely
 * calling that method because it needs to be reset anyways.  That
 * way can avoid having to reset everything at once.
 *//*
void feUtils::resetCombatStats() {
    attack = 0;
    hit_rate = 0;
    critical = 0;
    avoid = 0;
    rating = 0;
}*/

/**
 * Parameters: 
 *      rank: a character representing a character's weapon rank (capital letter)
 *      buffOrDebuff: an integer representing whether it's debuff or buff to character
 *
 * Modifies: Sets all the combat stats back to zero.  Use when a
 * character level ups or changes weapons, so that the proper values
 * can be recalculated
 *
 * Notes: Might not be needed if at the start of every "set" method,
 * resets the specified stat to 0 to calculate, since most likely
 * calling that method because it needs to be reset anyways.  That
 * way can avoid having to reset everything at once.
 */
int weaponTriangle(const char rank, const int buffOrDebuff) {
    // Buff
    if(buffOrDebuff == 1) {
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
    else {
        if(rank == 'E' || rank == 'D') 
            hit_rate -= 5;
        else if(rank == 'C')
            hit_rate -= 10;
        else if(rank == 'B')
        {
            hit_rate -= 10;
            attack +-= 1;
        }
        else if(rank == 'A')
        {
            hit_rate -= 15;
            attack -= 1;
        }
    }
}
