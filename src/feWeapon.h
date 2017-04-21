#ifndef WEAPON_H
#define WEAPON_H

#include <string>

#include "feItem.h"

class feWeapon : public feItem  {
	private:
		int might;
		int hitrate;
		int critical;
		bool physical;
		std::string type;

	public:
		feWeapon();
		int getCritical() const { return critical; }
		int getHitrate() const { return hitrate; }
		int getMight() const { return might; }
		int isPhysical() const { return physical; }
		std::string getType() const { return type; }
};

#endif
