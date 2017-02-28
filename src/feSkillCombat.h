#ifndef SKILLCOMBAT_H
#define SKILLCOMBAT_H

#include "feSkill.h"
#include "feCharacter.h"

class feSkillCombat : public feSkill {
	public:
		virtual int apply(feCharacter attacker, feCharacter defender) = 0;
};
