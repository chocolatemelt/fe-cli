#ifndef WEAPON_H
#define WEAPON_H

#include "feItem.h"

class feWeapon : public feItem  {
	private:
		int might;
		int hitrate;
		int critical;

	public:
		int getMt() { return might; }
		int getHr() { return hitrate; }
		int getCrit() { return critical; }
};

#endif
