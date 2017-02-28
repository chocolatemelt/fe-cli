#ifndef SKILLCOMBAT_H
#define SKILLCOMBAT_H

#include "feCharacter.h"
#include "feSkill.h"
#include "feStats.h"

class feSkillCombat : public feSkill {
	public:
		virtual int apply(feCharacter attacker, feCharacter defender) = 0;
};
