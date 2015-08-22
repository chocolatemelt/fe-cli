#include <ncurses.h>

#include "feCharacter.h"
#include "feClass.h"
#include "feUtils.h"

int main() {
  // initialize
  feClass c;
  feCharacter test('m', "My Unit", false, 'p', c);
  feUtils utils;
  initscr();

  // test character and class initialization
  printw("initialization of character MU successful\n");

  // test RNG functionality
  printw("testing RNG machine\n");
  int a;
  for(int i = 0; i < 100; ++i) {
    a = utils.feRNG();
    printw("%d ", a);
  }
  printw("\nRNG execution successful\n");

  // test terminal capabilities
  printw("testing terminal capabilities:\n");
  if(has_colors()) printw("terminal supports colors\n");
  else printw("terminal does not support colors\n");
  if(can_change_color()) printw("terminal can change colors\n");
  else printw("terminal cannot change colors\n");

  // get char to keep window open, and exit
  getch();
  endwin();
  return 0;
}
