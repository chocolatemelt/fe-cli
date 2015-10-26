#include <fstream>
#include <string>
#include <ncurses.h>

#include "feCharacter.h"
#include "feClass.h"
#include "feUtils.h"

std::string get_file_contents(const char *);

int main() {
  // initialize
  initscr();
	int row, col, dispr, dispc;
	std::string logopath = "dat/logo_jp.txt";

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

	// get char to keep window open, and exit
  getch();
  endwin();
  return 0;
}

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
