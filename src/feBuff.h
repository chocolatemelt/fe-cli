#ifndef BONUS_H
#define BONUS_H

#include "feStats.h"

struct feBuff {
	feStats bonus;
	feStats reduction;

	feBuff(const feBuff &);
	~feBuff() {}

	bool tick();
	bool invariant();
};

#endif