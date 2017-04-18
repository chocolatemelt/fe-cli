#ifndef BONUS_H
#define BONUS_H

#include "feStats.h"

struct feBonus {
	feStats bonus;
	feStats reduction;

	bool tick();
	bool invariant();
}
