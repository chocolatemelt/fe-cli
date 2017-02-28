#ifndef SKILLCOMBAT_H
#define SKILLCOMBAT_H

#include "feSkill.h"
#include "feStats.h"

class feSkillCombat : public feSkill
{
private:
    //combat skills modify character stats during battle only, applied to bonus stats
    feStats tempbonus;
public:
    char getType() { return 'c'; }
    feStats useSkill();
};

#endif