#include "feSecondaryStats.h"

const feSecondaryStats feSecondaryStats::ZERO = { 0, 0, 0, 0 };

void feSecondaryStats::assign(int value) {
	attack   = value;
	avoid    = value;
	critical = value;
	hitrate  = value;
}

bool feSecondaryStats::operator==(const feSecondaryStats &rhs) const {
	return (attack  == rhs.attack
      && avoid    == rhs.avoid
      && critical == rhs.critical
      && hitrate  == rhs.hitrate);
}

feSecondaryStats feSecondaryStats::operator%(const feSecondaryStats &rhs) const {
	feSecondaryStats ret;
	if (rhs.attack  == 0) { ret.attack  = 0; }
	else { ret.attack  = attack  % rhs.attack; }
	if (rhs.avoid == 0) { ret.avoid = 0; }
	else { ret.avoid = avoid % rhs.avoid; }
	if (rhs.critical == 0) { ret.critical = 0; }
	else { ret.critical = critical % rhs.critical; }
	if (rhs.hitrate == 0) { ret.hitrate = 0; }
	else { ret.hitrate = hitrate % rhs.hitrate; }
	return ret;
}

feSecondaryStats feSecondaryStats::operator+(const feSecondaryStats &rhs) const {
	feSecondaryStats ret;
	ret.attack  = attack  + rhs.attack;
	ret.avoid = avoid + rhs.avoid;
	ret.critical = critical + rhs.critical;
	ret.hitrate = hitrate + rhs.hitrate;
	return ret;
}

feSecondaryStats feSecondaryStats::operator-(const feSecondaryStats &rhs) const {
	feSecondaryStats ret;
	ret.attack  = attack  - rhs.attack;
	ret.avoid = avoid - rhs.avoid;
	ret.critical = critical - rhs.critical;
	ret.hitrate = hitrate - rhs.hitrate;
	return ret;
}

feSecondaryStats feSecondaryStats::operator*(const feSecondaryStats &rhs) const {
	feSecondaryStats ret;
	ret.attack  = attack  * rhs.attack;
	ret.avoid = avoid * rhs.avoid;
	ret.critical = critical * rhs.critical;
	ret.hitrate = hitrate * rhs.hitrate;
	return ret;
}

feSecondaryStats feSecondaryStats::operator/(const feSecondaryStats &rhs) const {
	feSecondaryStats ret;
	if (rhs.attack  == 0) { ret.attack  = 0; }
	else { ret.attack  = attack  / rhs.attack; }
	if (rhs.avoid == 0) { ret.avoid = 0; }
	else { ret.avoid = avoid / rhs.avoid; }
	if (rhs.critical == 0) { ret.critical = 0; }
	else { ret.critical = critical / rhs.critical; }
	if (rhs.hitrate == 0) { ret.hitrate = 0; }
	else { ret.hitrate = hitrate / rhs.hitrate; }
	return ret;
}

feSecondaryStats &feSecondaryStats::operator=(const feSecondaryStats &rhs) {
	if (this == &rhs) {
		return *this;
	}

	attack  = rhs.attack;
	avoid = rhs.avoid;
	critical = rhs.critical;
	hitrate = rhs.hitrate;
	return *this;
}

feSecondaryStats &feSecondaryStats::operator+=(const feSecondaryStats &rhs) {
	attack  += rhs.attack;
	avoid += rhs.avoid;
	critical += rhs.critical;
	hitrate += rhs.hitrate;
	return *this;
}

feSecondaryStats &feSecondaryStats::operator-=(const feSecondaryStats &rhs) {
	attack  -= rhs.attack;
	avoid -= rhs.avoid;
	critical -= rhs.critical;
	hitrate -= rhs.hitrate;
	return *this;
}

feSecondaryStats &feSecondaryStats::operator*=(const feSecondaryStats &rhs) {
	attack  *= rhs.attack;
	avoid *= rhs.avoid;
	critical *= rhs.critical;
	hitrate *= rhs.hitrate;
	return *this;
}

feSecondaryStats &feSecondaryStats::operator/=(const feSecondaryStats &rhs) {
	if (rhs.attack  == 0) { attack  = 0; }
	else { attack  /= rhs.attack; }
	if (rhs.avoid == 0) { avoid = 0; }
	else { avoid /= rhs.avoid; }
	if (rhs.critical == 0) { critical = 0; }
	else { critical /= rhs.critical; }
	if (rhs.hitrate == 0) { hitrate = 0; }
	else { hitrate /= rhs.hitrate; }
	return *this;
}
