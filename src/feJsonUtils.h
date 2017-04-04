#ifndef JSONUTILS_H
#define JSONUTILS_H

#include <string>

#include "feCharacter.h"
#include "feClass.h"

#include "lib/json.hpp"

using json = nlohmann::json;

public class feJsonUtils {
	public:
		static feCharacter *importCharacter(std::string characterJson);
		static feClass *importClass(std::string classJson);
};

#endif
