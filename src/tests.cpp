#include <ncurses.h>
#include <iostream>

#include "feCharacter.h"
#include "feClass.h"
#include "feUtils.h"

int main() {

  feClass c;
  feCharacter test('m', "Marth", true, 'p', c);
  feUtils utils;

  //printw("initialization of character MU successful\n");
  if (test.printInfo() == "mMarthmalep") {
    std::cout << ("1");
  }
  else std::cout << (test.printInfo());
  //printw("testing terminal capabilities:\n");

  // test RNG functionality
  std::vector<int> test_vector;
  int a;
  for(int i = 0; i < 100; ++i) {
    a = utils.feRNG();
    test_vector.push_back(a);
  }
  if (test_vector.size() == 100) std::cout << ("1");
  else std::cout << ("0");

  std::cout << std::endl;

  return 0;
}
