#ifndef JSONUTILS_H
#define JSONUTILS_H

#include <string>

#include "feCharacter.h"
#include "feClass.h"

#include "lib/json.hpp"

using json = nlohmann::json;

public class feJsonUtils {
	public:
		static json exportCharacter(feCharacter chr);
		static json exportClass(feClass cls);
		static json exportItem(feItem itm);

		static feCharacter *importCharacter(json characterJson);
		static feClass *importClass(json classJson);
		static feItem *importItem(json itemJson);

		static feCharacter *importCharacterFromString(std::string characterJsonStr);
		static feClass *importClassFromString(std::string classJsonStr);
		static feItem *importItemFromString(std::string itemJsonStr);
};

#endif
