#ifndef SKILL_H
#define SKILL_H

#include <string>

class feSkill {
	private:
		std::string name;
	public:
		std::string getName();
		static feSkill *get(std::string skill);
};

#endif
