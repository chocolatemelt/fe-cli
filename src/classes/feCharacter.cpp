#include "feCharacter.h"

feCharacter::feCharacter(std::string id, std::string n, bool g, char l, char a, feClass j) {
  uniqID = id;
  name = n;
  gender = g;
  loyalty = l;
	affinity = a;
  job = j;

  /* initialize stats */
  initStats();
}

/**
 * zeroStats()
 * Initializes stats (does nothing for stats otherwise).
 */
void feCharacter::initStats() {
  base.emplace("str", 0);
  base.emplace("mag", 0);
  base.emplace("skl", 0);
  base.emplace("spd", 0);
  base.emplace("lck", 0);
  base.emplace("def", 0);
  base.emplace("res", 0);
	base.emplace("con", 0);
  base.emplace("mov", 0);

  growth.emplace("str", 0);
  growth.emplace("mag", 0);
  growth.emplace("skl", 0);
  growth.emplace("spd", 0);
  growth.emplace("lck", 0);
  growth.emplace("def", 0);
  growth.emplace("res", 0);
  growth.emplace("con", 0);
  growth.emplace("mov", 0);

  // copy
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

void feCharacter::changeHp(int val)
{
  current.hp += val;
}
bool feCharacter::ded()
{
  if (current.hp <= 0)
  { return true; }
  return false;
}

feItem* feCharacter::getWep()
{
  return (feWeapon*)this->equipped;
}
int feCharacter::getStr() { return current.str; }
int feCharacter::getMag() { return current.mag; }
int feCharacter::getSkl() { return current.skl; }
int feCharacter::getLck() { return current.lck; }
int feCharacter::getSpd() { return current.spd; }
int feCharacter::getRes() { return current.res; }
int feCharacter::getDef() { return current.def; }
std::string feCharacter::getWeak() { return job.getWeak(); }