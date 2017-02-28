#ifndef SKILLMAP_H
#define SKILLMAP_H

#include "feSkill.h"
#include "feStats.h"

class feSkillMap : public feSkill
{
private:
public:
    char getType() { return 'm'; }
};

#endif