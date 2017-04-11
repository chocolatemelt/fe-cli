#ifndef MAP_H
#define MAP_H

#include <ostream>
#include <string>

#include "feTile.h"

class feMap {
	private:
		std::string name;
		int width;
		int height;
		feTile **mapTiles;
	public:
		void update();
		void print();
}

#endif
