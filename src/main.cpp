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
	int row, col;

  // get splash
	std::string logo = get_file_contents("dat/logo_en.txt");

	// print to center of screen
	getmaxyx(stdscr,row,col);
	mvprintw(row/2, 0, "%s", logo.c_str());
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
