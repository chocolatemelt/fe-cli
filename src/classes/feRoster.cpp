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
feRoster::add(feCharacter c) {
	r.push(c);
}

/**
 * Lists the characters in the roster.
 */
feRoster::list() {
	/* implementation */
}