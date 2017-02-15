#ifndef WEAPON_H
#define WEAPON_H

#include "feItem.h"

class feWeapon : public feItem  {
	private:
		int mt;

	public:
		//check class if usable
		std::string check();

		void print();

		//equips?
		void use();
};

#endif
