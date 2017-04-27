#ifndef WEAPON_H
#define WEAPON_H

#include <string>

#include "feItem.h"

class feWeapon : public feItem  {
	private:
		int critical;
		int hitrate;
		int might;
		bool physical;
		std::string name;
		std::string type;

	public:
		feWeapon();
		feWeapon(int, int, int, bool, std::string, std::string);
		int getCritical() const { return critical; }
		int getHitrate() const { return hitrate; }
		int getMight() const { return might; }
		int isPhysical() const { return physical; }
		std::string getType() const { return type; }
};

#endif
