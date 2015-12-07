#include "feClass.h"

feClass::feClass(std::string baseClassData)
{
	initializeNameStats(baseClassData);
}

void feClass::initializeNameStats(std::string baseClassData)
{
	
}

std::string feClass::getClassName() {
	return class_name;
}
