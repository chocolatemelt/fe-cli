#ifndef MECHANICS_H
#define MECHANICS_H

#include <map>
#include <string>
#include <vector>

#include "feStats.h"
#include "feWeapon.h"

class feMechanics {
	public:
		// a static enumeration of weapon types, which allows us to switch on strings
		enum class WeaponType {
			Sword, Tome,
			Axe, Bow,
			Lance, Dagger,
			None
		};

		// a static mapping from strings to their enumerations, for the same reason as above
		static std::map<std::string, WeaponType> mapStringToWeaponType;

		// a static mapping from enumerations to their strings
		static std::map<WeaponType, std::string> mapWeaponTypeToString;

		static int getBaseAttack(const feStats &, const feWeapon &);
		static int getBaseAvoid(const feStats &);
		static int getBaseCritical(const feStats &, const feWeapon &);
		static int getBaseHitRate(const feStats &, const feWeapon &);
		static int getBaseRating(const feStats &, const feWeapon &);
		static char getWeaponColor(const feWeapon &);

		//static void calculateWeaponTriangle(const feWeapon &, const feWeapon &, int &, int &); TODO: finish
		static int weaponTriangle(const feWeapon &, const feWeapon &);
		//static void weaponRankBonus(const feWeapon &); TODO: finish
};

#endif