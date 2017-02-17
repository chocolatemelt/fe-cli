#ifndef SKILL_H
#define SKILL_H

#include "feClass.h"
#include <string>
#include <vector>

class feSkill {
  private:
    //skill name?
    std::string name;
  public:
    //abstract skill
    //changes based on subclass skill class
    virtual void useSkill();
};

#endif
