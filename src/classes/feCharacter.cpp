#include "feCharacter.h"

feCharacter::feCharacter(std::string id, std::string n, bool g, char l, char a, feClass j) {
  uniqID = id;
  name = n;
  gender = g;
  loyalty = l;
  affinity = a;
  job = j;
  weaponRank = feWeaponRank(j);

  /* initialize stats */
  initStats();
}

/**
 * zeroStats()
 * Initializes stats (does nothing for stats otherwise).
 */
void feCharacter::initStats() {
  base.str = 0;
  base.mag = 0;
  base.skl = 0;
  base.spd = 0;
  base.lck = 0;
  base.def = 0;
  base.res = 0;
  base.con = 0;
  base.mov = 0;

  // copy
  growth = base;
  cap = base;
  current = base;
  bonus = base;
}

std::string feCharacter::printInfo() {

  std::stringstream ss;
  std::string id;
  ss << uniqID;
  ss >> id;

  std::stringstream ll;
  std::string loy;
  ll << loyalty;
  ll >> loy;

  std::string g;
  if (gender == 0) g = "female";
  if (gender == 1) g = "male";



  return id + name + g + loy;
}

void feCharacter::addBonues(feStats morebonus)
{
  bonus.hp += morebonus.hp;
  bonus.str += morebonus.str;
  bonus.mag += morebonus.mag;
  bonus.skl += morebonus.skl;
  bonus.spd += morebonus.spd;
  bonus.lck += morebonus.lck;
  bonus.def += morebonus.def;
  bonus.res += morebonus.res;
  bonus.con += morebonus.con;
  bonus.mov += morebonus.mov;
}