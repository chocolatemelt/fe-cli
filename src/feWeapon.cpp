#include "feWeapon.h"

feWeapon::feWeapon() {
	critical = 0;
	hitrate = 0;
	might = 0;
	physical = true;
	type = "none";
	name = "";
}

feWeapon::feWeapon(int c, int h, int m, bool p, std::string t, std::string n) {
	critical = c;
	hitrate = h;
	might = m;
	physical = p;
	type = t;
	name = n;
}