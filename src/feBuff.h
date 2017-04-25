#ifndef BONUS_H
#define BONUS_H

#include "feStats.h"

struct feBuff {
	feStats bonus;
	feStats reduction;

	bool tick();
	bool invariant();
};

#endif