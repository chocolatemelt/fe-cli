#include <ncurses.h>

#include "feCharacter.h"
#include "feClass.h"

int main() {
  feClass c;
  feCharacter test('m', "My Unit", false, 'p', c);
  initscr();
  printw("initialization of character MU successful\n");
  printw("testing terminal capabilities:\n");
  if(has_colors()) printw("terminal supports colors\n");
  else printw("terminal does not support colors\n");
  if(can_change_color()) printw("terminal can change colors\n");
  else printw("terminal cannot change colors\n");
  getch();
  endwin();
  return 0;
}
