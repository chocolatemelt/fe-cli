#include <ncurses.h>

#include "feCharacter.h"

int main() {
  initscr();
  printw("ncurses");
  refresh();
  getch();
  endwin();
  return 0;
}
