#ifndef SKILLHP5_H
#define SKILLHP5_H

#include "feSkillStat.h"

class feSkillHP5 : public feSkillStat {
	public:
		feStats apply() {
			return feStats(5, 0, 0, 0, 0, 0, 0, 0, 0, 0,);
		}
};

#endif
