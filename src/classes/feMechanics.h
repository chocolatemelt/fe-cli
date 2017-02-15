#ifndef MECHANICS_H
#define MECHANICS_H

#include "feCharacter.h"
#include "feClass.h"
#include "feItem.h"

class feMechanics
{
public:
    virtual void combat(feCharacter attacker, feCharacter defender);
    virtual void exp(feCharacter winner, feCharacter loser, int dmg);
private:
};

#endif