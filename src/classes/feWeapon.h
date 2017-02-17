#ifndef WEAPON_H
#define WEAPON_H

#include "feItem.h"

class feWeapon : public feItem  {
	private:
		int mt;		//might
		int hr;		//hit rate
		int crit;	//crit chance
		bool phys;	//physical
	public:
		//check class if usable
		std::string check();

		void print();

		//equips?
		void use();

		//returns true if weapon type is physical
		bool isPhys() { return phys; }
		//returns weapon stats
		int getMt() { return mt; }
		int getHr() { return hr; }
		int getCrit() { return crit; }
		std::string getName() { return name; }
};

#endif
