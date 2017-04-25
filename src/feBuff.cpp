#include "feBuff.h"

feBuff::feBuff(const feBuff &rhs) {
	bonus = rhs.bonus;
	reduction = rhs.reduction;
}

/**
 * void tick()
 * One 'tick', or 'turn', for this bonus, which should ideally
 * reduce to 0 at some point.
 * @returns true when tick has hit 0, false otherwise
 */
bool feBuff::tick() {
	bonus /= reduction;
	return bonus == feStats::ZERO;
}

/**
 * void invariant()
 * Checks if the bonus is constructed correctly; note that bonuses
 * must have an evenly divisible buff and reduction, otherwise we
 * can't correctly end and free the buff.
 * @returns true if invariant is fulfilled, false otherwise
 */
bool feBuff::invariant() {
	return (bonus % reduction) == feStats::ZERO;
}
