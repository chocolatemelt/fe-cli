#ifndef SKILLHP5_H
#define SKILLHP5_H

#include "feSkillStat.h"

class feSkillHP5 : public feSkillStat {
	private:
		static feSkillHP5 *instance;
		feSkillHP5() {}
	public:
		static feSkillHP5 *self() {
			if(!instance) instance = new feSkillHP5;
			return instance;
		}
		feStats apply() {
			return feStats(5, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		}
};

#endif
