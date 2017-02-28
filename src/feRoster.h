#ifndef ROSTER_H
#define ROSTER_H

#include <vector>
#include <string>
#include "feCharacter.h"

class feRoster {
	private:
		std::string name;
		std::vector<feCharacter> roster;
	public: 
		feRoster(std::string n);
		feRoster(std::string n, std::vector<feCharacter> r);
		void add(feCharacter c);
		std::string list();
};

#endif