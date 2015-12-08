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
	curs_set(false);
	keypad(stdscr, true);

	int row, col, dispr, dispc; // positional variables
	int width, height; // menu window dimensions
	std::string logopath = "dat/logo_jp.txt";

	const char *menu[] = {
		"  Start  ",
		"  Rosters  ",
		"  Options  ",
		"  Exit  "
	};
	ITEM **items;
	ITEM *cur_item;
	MENU *game_menu;
	WINDOW *game_menu_win;
	WINDOW *game_menu_sub;

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

	// build menu
	int c, n_choices;
	n_choices = ARRAY_SIZE(menu);
	items = (ITEM **) calloc(n_choices + 1, sizeof(ITEM *));
	for(int i = 0; i < n_choices; ++i) items[i] = new_item(menu[i], "");
	items[n_choices] = (ITEM *) NULL;
	game_menu = new_menu((ITEM **) items);
	set_menu_mark(game_menu, ">");

	// create menu windows for positioning
	height = n_choices + 2;
	width = 14; // max width + 4 (TODO programmatically get max width of an item)
	getmaxyx(stdscr, c, col); // using c as a dummy variable here; probably better way to do this
	col = (col - width) / 2;
	game_menu_win = newwin(height, width, row, col);
	game_menu_sub = derwin(game_menu_win, height-2, width-2, 1, 1);

	// set menu windows and display!
	set_menu_win(game_menu, game_menu_win);
	set_menu_sub(game_menu, game_menu_sub);
	post_menu(game_menu);
	wrefresh(game_menu_win);
	wrefresh(game_menu_sub);

	// keypress handler
	while((c = getch())) {
		// exit if q or esc key is pressed (esc strangely lags...)
		if(c == 'q' || c == 27) break;

		switch(c) {
			case KEY_DOWN:
				menu_driver(game_menu, REQ_DOWN_ITEM);
				wrefresh(game_menu_win);
				wrefresh(game_menu_sub);
				break;
			case KEY_UP:
				menu_driver(game_menu, REQ_UP_ITEM);
				wrefresh(game_menu_win);
				wrefresh(game_menu_sub);
				break;
			case 10: case 'z': case 'x': // selecting an item
				ITEM *cur;
				cur = current_item(game_menu);
				printw("item sel is %s", (char *)item_name(cur));
				break;
		}
	}

	// cleanup routine
	unpost_menu(game_menu);
	delwin(game_menu_win);
	delwin(game_menu_sub);
	free_menu(game_menu);
	for(int i = 0; i < n_choices; ++i) free_item(items[i]);
	free(items);
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
