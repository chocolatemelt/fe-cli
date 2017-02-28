#include "feRoster.h"

feRoster::feRoster(std::string n) {
	name = n;
}

feRoster::feRoster(std::string n, std::vector<feCharacter> r) {
	name = n;
	roster = r;
}

/**
 * Adds a character to the roster.
 */
void feRoster::add(feCharacter c) {
	roster.push_back(c);
}

/**
 * Lists the characters in the roster.
 */
std::string feRoster::list() {
	std::string allchar = "";
	for(unsigned int i = 0; i < roster.size(); ++i)
	{
		allchar += roster[i].printInfo();
		allchar += "\n";
	}

	return allchar;
}