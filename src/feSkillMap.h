#ifndef SKILLMAP_H
#define SKILLMAP_H

#include "feMap.h"

class feSkillMap : public feSkill {
	public:
		virtual void apply(feMap gameState) = 0;
};
