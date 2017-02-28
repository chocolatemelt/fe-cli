#ifndef SKILLSTAT_H
#define SKILLSTAT_H

#include "feSkill.h"
#include "feStats.h"

class feSkillStat : public feSkill {
	private:
	public:
		char getType() { return 's'; }
		virtual feStats apply();
};

#endif
