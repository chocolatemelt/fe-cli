/*
 * feJsonUtils.cpp
 *
 * Generic static methods to turn feClass, feChar, and feItem into JSON.
 */

#include "feJsonUtils.h"

std::vector<int> stattovector(feStats stats) {
	std::vector<int> ret;
	ret.push_back(stats.hp);
	ret.push_back(stats.str);
	ret.push_back(stats.mag);
	ret.push_back(stats.skl);
	ret.push_back(stats.spd);
	ret.push_back(stats.lck);
	ret.push_back(stats.def);
	ret.push_back(stats.res);
	ret.push_back(stats.con);
	ret.push_back(stats.mov);

	return ret;
}

json feJsonUtils::exportClass(feClass cls) {
	json jsonClass;

	jsonClass["name"] = cls.getClassName();

	std::vector<int> basestat = stattovector(cls.getBaseStats());
	jsonClass["base"] = basestat;

	std::vector<int> capstat = stattovector(cls.getCapStats());
	jsonClass["cap"] = capstat;

	std::vector<int> growthstat = stattovector(cls.getGrowthStats());
	jsonClass["growth"];

	jsonClass["weaponType"] = cls.getWeaponTypes();
	jsonClass["promotion"] = cls.getPromotions();

	std::unordered_map<int, feSkill>::iterator skilliterator;
	for (skilliterator = cls.getSkills().begin(); skilliterator != cls.getSkills().end(); ++skilliterator) {
		jsonClass[skilliterator->second.getName()] = {skilliterator->first};
	}

	return jsonClass;
}
