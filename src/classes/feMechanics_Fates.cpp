#include "feMechanics.h"
#include "feUtils.h"

void feMechanics::combat(feCharacter attacker, feCharacter defender)
{
    //used to get bonuses
    feUtils calc;

    //weapon triangle bonus
    int bonustrihr=0;
    int bonustriatk=0;

    //weapon rank bonus
    int bonusrankatk=0;
    int bonusrankhr=0;
    int bonusrankrc=0;

    //weakness bonus
    int effdmg;
    if (defender.getWeak() == attacker.getWep()->getName())
    { effdmg = 3; }
    else { effdmg = 1; }

    //attack based on weapon type + weapon might and attacker strenght/magic
    int attack;
    if (attacker.getWep()->getPhys() == true)
    { attack = attacker.getStr() + (attacker.getWep()->getMt() * effdmg); }
    else
    { attack = attacker.getMag() + (attacker.getWep()->getMt() * effdmg); }

    //hitrate based on weapon hitrate and attacker skill/luck
    int hitrate = attacker.getWep()->getHr() + ((attacker.getSkl() * 3 + attacker.getLck()) / 2);

    //crit chance from weapon + skill
    int crit = attacker.getWep()->getCrit() + (attacker.getSkl()/2);

    //defender avoid chance from speed + luck
    int avd = (defender.getSpd() * 3 + defender.getLck()) / 2;

    //rating is stat sum
    int rating = attacker.getStr() + attacker.getMag() + attacker.getSpd() + attacker.getSkl() + attacker.getLck() + attacker.getRes() + attacker.getDef();

    //apply triangle + rank bonuses
    //rank bonus can canceled by triangle
    attack += bonusrankatk + bonustriatk;
    hitrate += bonusrankhr + bonustrihr;

    bool doubleattack=false;
    if (attacker.getSpd() - defender.getSpd() >= 5)
    { doubleattack = true; }
    //if (attacker.getWep() type? == bravesword) { doubleattack = true; }

    //----------------------------------------------------------------------------------------------

    int damage = attack - (defender.getDef() + defender.getRes()); //+terrain?
    int totalhr = (hitrate - avd); //+support?
    int totalcr = crit - (defender.getLck()); //+support?

    int checkhit = calc.feRNG();
    if (checkhit > totalhr)
    {
        int checkcr = calc.feRNG();
        if (checkcr > totalcr)
        {
            defender.changeHp(-3*damage);
        }
        else
        {
            defender.changeHp(-1 * damage);
        }
        if (defender.ded()) { exp(attacker, defender, damage); }
    }

    return;
}

void feMechanics::exp(feCharacter winner, feCharacter loser, int dmg)
{
    return;
}
