#include "feClass.h"

feClass::feClass() {
}

feClass::feClass(std::string baseClassData) {
	initializeNameStats(baseClassData);
}

void feClass::initializeNameStats(std::string baseClassData) {
}

std::vector<std::string> feClass::getWeaponTypes() const
{
	return (weaponTypes);
}

std::vector<std::string> feClass::getPromotions() const {
	return (promotions);
}

std::unordered_map<int, feSkill> feClass::getSkills() const {
	return (classSkills);
}