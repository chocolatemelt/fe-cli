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

void feCharacter::addBonuses(feStats b)
{
  bonus.hp += b.hp;
  bonus.str += b.str;
  bonus.mag += b.mag;
  bonus.skl += b.skl;
  bonus.spd += b.spd;
  bonus.lck += b.lck;
  bonus.def += b.def;
  bonus.res += b.res;
  bonus.con += b.con;
  bonus.mov += b.mov;
}
