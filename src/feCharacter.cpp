#include "feCharacter.h"

feCharacter::feCharacter(char id, std::string n, bool g, char l, feClass j) {
  uniqID = id;
  name = n;
  gender = g;
  loyalty = l;
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
  base.emplace("mov", 0);
  // add other stat things here
}
