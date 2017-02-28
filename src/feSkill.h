#ifndef SKILL_H
#define SKILL_H

#include <string>

class feSkill {
  private:
		std::string name;
	public:
		virtual char getType() = 0;
};

#endif
