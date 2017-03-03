#include "feSkill.h"

feSkill get(std::string skill) {
	switch(skill) {
		case "HP+5":
			return feSkillHP5::self();
		default:
			return feSkillHP5::self(); // this is undefined behavior... should throw an error
	}
}
