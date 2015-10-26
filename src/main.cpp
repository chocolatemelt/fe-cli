#include <cstdlib>
#include <fstream>
#include <string>
#include <ncurses.h>
#include <menu.h>

#include "feCharacter.h"
#include "feClass.h"
#include "feUtils.h"

// lazy af
#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

std::string get_file_contents(const char *);

int main() {
  // initialize
  initscr();
	cbreak();
	noecho();
	keypad(stdscr, true);

	int row, col, dispr, dispc;
	std::string logopath = "dat/logo_jp.txt";

	const char *menu[] = {
		"Start",
		"Rosters",
		"Options",
		"Exit"
	};
	ITEM **items;
	ITEM *cur_item;
	MENU *game_menu;

	// get row, column, and displacements
	getmaxyx(stdscr,row,col);
	dispr = 20;
	dispc = 100;
	row = (row - dispr) / 2;
	col = (col - dispc) / 2;
	row -= 8; // move it up 8 rows to make room for menu

  // get splash & print to center of screen
	std::ifstream inf(logopath, std::ios::in | std::ios::binary);
	for(std::string line; getline(inf, line); ) {
		mvprintw(row++, col, "%s", line.c_str());
	}
	refresh();

	// build menu (looks more c than c++ to me...)
	int c, n_choices;
	n_choices = ARRAY_SIZE(menu);
	items = (ITEM **) calloc(n_choices + 1, sizeof(ITEM *));
	for(int i = 0; i < n_choices; ++i) items[i] = new_item(menu[i], menu[i]);
	items[n_choices] = (ITEM *) NULL;
	game_menu = new_menu((ITEM **) items);
	post_menu(game_menu);

	// exit handler
	while((c = getch()) != 10){
		switch(c) {
			case KEY_DOWN:
		    menu_driver(game_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(game_menu, REQ_UP_ITEM);
				break;
		}
	}

	// free stuff up and exit
	free_item(items[0]);
	free_item(items[1]);
	free_menu(game_menu);
  endwin();
  return 0;
}

/**
 * store file contents into a string
 */
std::string get_file_contents(const char *filename) {
  std::ifstream in(filename, std::ios::in | std::ios::binary);
  if (in)
  {
    std::string contents;
    in.seekg(0, std::ios::end);
    contents.resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&contents[0], contents.size());
    in.close();
    return(contents);
  }
  throw(errno);
	/* std::ifstream ifs(filename); */
	/* std::string content( (std::istreambuf_iterator<char>(ifs) ), */
                       /* (std::istreambuf_iterator<char>()    ) ); */
	/* return content; */
}
