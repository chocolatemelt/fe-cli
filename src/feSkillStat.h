#ifndef SKILLSTAT_H
#define SKILLSTAT_H

#include "feSkill.h"

class feSkillStat : public feSkill {
	private:
	public:
		void getType() { return 's'; }
		virtual feStats apply();
}

#endif
