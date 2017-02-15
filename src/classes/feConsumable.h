#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "feItem.h"
#include "feStats.h"

class feConsumable : public feItem {
	private:
		//consumables change stats right?
		feStats affected;
	public:
		std::string check();

		void print();

		void use();
};

#endif
