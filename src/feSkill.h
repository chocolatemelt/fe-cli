#ifndef SKILL_H
#define SKILL_H

#include <string>

class feSkill {
	private:
		std::string name;
	public:
		static feSkill *get(std::string skill);
};

#endif
