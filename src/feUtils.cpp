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
    std::vector<int>::iterator itr = character_stats.begin();
    for( ; itr != character_stats.end(); ++itr)
        attack += *itr;
}

/**
 * Parameters:
 *    weapon_stats: vector of ints containing
 *    values of the necessary character/weapon stats needed
 *    for calculating the actual hit rate of a character
 *
 * Return: Nothing
 */
void feUtils::setHitRate(const std::vector<int>& weapon_stats) {
    hit_rate = weapon_stats[0] +
               ((weapon_stats[1] * 3) + ceil(weapon_stats[2])/2) +
               weapon_stats[4];
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
    std::vector<int>::iterator itr = character_stats.begin();
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
 */
void feUtils::resetCombatStats() {
    attack = 0;
    hit_rate = 0;
    critical = 0;
    avoid = 0;
    rating = 0;
}
