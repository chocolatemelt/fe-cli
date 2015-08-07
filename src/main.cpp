#include <ncurses.h>

#include "feCharacter.h"
#include "feClass.h"

int main() {
  feClass c;
  feCharacter test('m', "My Unit", false, 'p', c);
  initscr();
  printw("hi");
  refresh();
  getch();
  printw("hihi");
  refresh();
  getch();
  endwin();
  return 0;
}
