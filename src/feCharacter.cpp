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
  initStats(j);
}

/**
 * zeroStats()
 * Initializes stats (does nothing for stats otherwise).
 */
void feCharacter::initStats(feClass c) {
    feStats classbase = c.getBaseStats();
    base = classbase;
    current = base;
    bonus = base;

    feStats classgrowth = c.getGrowthStats();
    growth = classgrowth;
    feStats classcap = c.getCapStats();
    cap = classcap;
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
