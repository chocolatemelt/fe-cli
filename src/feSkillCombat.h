#ifndef SKILLCOMBAT_H
#define SKILLCOMBAT_H

#include "feSkill.h"

class feSkillCombat : public feSkill
{
private:
public:
    char getType() { return 'c'; }
};

#endif