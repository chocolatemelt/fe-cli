#include "feClass.h"

feClass::feClass() {
}

feClass::feClass(std::string baseClassData) {
	initializeNameStats(baseClassData);
}

void feClass::initializeNameStats(std::string baseClassData) {
}

std::string feClass::getClassName() {
	return name;
}

std::vector<std::string> feClass::getWeaponTypes() const
{
	return (weaponTypes);
}