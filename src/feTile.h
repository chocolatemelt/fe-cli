#ifndef TILE_H
#define TILE_H

#include <string>

class Tile {
	private:
		std::string type;
	public:
		feTile(char t);
		feTile(const char &t);
		feStats getBonuses();
}

#endif
