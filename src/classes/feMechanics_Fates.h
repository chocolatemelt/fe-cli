#ifndef MECHANIC_FATES_H
#define MECHANIC_FATES_H

#include "feMechanics.h"
#include "feUtils.h"

class feMechanics_Fates : public feMechanics
{
public:
    void combat(feCharacter attacker, feCharacter defender);
    void exp(feCharacter winner, feCharacter loser, int dmg);
private:
};

#endif