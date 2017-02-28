#ifndef SKILLSTAT_H
#define SKILLSTAT_H

#include "feSkill.h"

class feSkillStat : public feSkill {
	public:
		virtual feStats apply();
}

#endif
