#include <ncurses.h>

#include "feCharacter.h"
#include "feClass.h"

int main() {
  feClass r;
  feCharacter test('i', "fuc", true, 'p', r);
  initscr();
  printw("ncurses");
  refresh();
  getch();
  endwin();
  return 0;
}
