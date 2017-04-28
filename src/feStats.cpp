#include "feStats.h"

const feStats feStats::ZERO = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

void feStats::assign(int value) {
	hp  = value;
	str = value;
	mag = value;
	skl = value;
	spd = value;
	lck = value;
	def = value;
	res = value;
	con = value;
	mov = value;
}

bool feStats::operator==(const feStats &rhs) const {
	return (hp == rhs.hp
			&& str == rhs.str
			&& mag == rhs.mag
			&& skl == rhs.skl
			&& spd == rhs.spd
			&& lck == rhs.lck
			&& def == rhs.def
			&& res == rhs.res
			&& con == rhs.con
			&& mov == rhs.mov);
}

feStats feStats::operator%(const feStats &rhs) const {
	feStats ret;
	if (rhs.hp  == 0) { ret.hp  = 0; }
	else { ret.hp  = hp  % rhs.hp; }
	if (rhs.str == 0) { ret.str = 0; }
	else { ret.str = str % rhs.str; }
	if (rhs.mag == 0) { ret.mag = 0; }
	else { ret.mag = mag % rhs.mag; }
	if (rhs.skl == 0) { ret.skl = 0; }
	else { ret.skl = skl % rhs.skl; }
	if (rhs.spd == 0) { ret.spd = 0; }
	else { ret.spd = spd % rhs.spd; }
	if (rhs.lck == 0) { ret.lck = 0; }
	else { ret.lck = lck % rhs.lck; }
	if (rhs.def == 0) { ret.def = 0; }
	else { ret.def = def % rhs.def; }
	if (rhs.res == 0) { ret.res = 0; }
	else { ret.res = res % rhs.res; }
	if (rhs.mov == 0) { ret.mov = 0; }
	else { ret.con = con % rhs.con; }
	if (rhs.con == 0) { ret.con = 0; }
	else { ret.mov = mov % rhs.mov; }
	return ret;
}

feStats feStats::operator+(const feStats &rhs) const {
	feStats ret;
	ret.hp  = hp  + rhs.hp;
	ret.str = str + rhs.str;
	ret.mag = mag + rhs.mag;
	ret.skl = skl + rhs.skl;
	ret.spd = spd + rhs.spd;
	ret.lck = lck + rhs.lck;
	ret.def = def + rhs.def;
	ret.res = res + rhs.res;
	ret.con = con + rhs.con;
	ret.mov = mov + rhs.mov;
	return ret;
}

feStats feStats::operator-(const feStats &rhs) const {
	feStats ret;
	ret.hp  = hp  - rhs.hp;
	ret.str = str - rhs.str;
	ret.mag = mag - rhs.mag;
	ret.skl = skl - rhs.skl;
	ret.spd = spd - rhs.spd;
	ret.lck = lck - rhs.lck;
	ret.def = def - rhs.def;
	ret.res = res - rhs.res;
	ret.con = con - rhs.con;
	ret.mov = mov - rhs.mov;
	return ret;
}

feStats feStats::operator*(const feStats &rhs) const {
	feStats ret;
	ret.hp  = hp  * rhs.hp;
	ret.str = str * rhs.str;
	ret.mag = mag * rhs.mag;
	ret.skl = skl * rhs.skl;
	ret.spd = spd * rhs.spd;
	ret.lck = lck * rhs.lck;
	ret.def = def * rhs.def;
	ret.res = res * rhs.res;
	ret.con = con * rhs.con;
	ret.mov = mov * rhs.mov;
	return ret;
}

feStats feStats::operator/(const feStats &rhs) const {
	feStats ret;
	if (rhs.hp  == 0) { ret.hp  = 0; }
	else { ret.hp  = hp  / rhs.hp; }
	if (rhs.str == 0) { ret.str = 0; }
	else { ret.str = str / rhs.str; }
	if (rhs.mag == 0) { ret.mag = 0; }
	else { ret.mag = mag / rhs.mag; }
	if (rhs.skl == 0) { ret.skl = 0; }
	else { ret.skl = skl / rhs.skl; }
	if (rhs.spd == 0) { ret.spd = 0; }
	else { ret.spd = spd / rhs.spd; }
	if (rhs.lck == 0) { ret.lck = 0; }
	else { ret.lck = lck / rhs.lck; }
	if (rhs.def == 0) { ret.def = 0; }
	else { ret.def = def / rhs.def; }
	if (rhs.res == 0) { ret.res = 0; }
	else { ret.res = res / rhs.res; }
	if (rhs.mov == 0) { ret.mov = 0; }
	else { ret.con = con / rhs.con; }
	if (rhs.con == 0) { ret.con = 0; }
	else { ret.mov = mov / rhs.mov; }
	return ret;
}

feStats &feStats::operator=(const feStats &rhs) {
	if (this == &rhs) {
		return *this;
	}

	hp  = rhs.hp;
	str = rhs.str;
	mag = rhs.mag;
	skl = rhs.skl;
	spd = rhs.spd;
	lck = rhs.lck;
	def = rhs.def;
	res = rhs.res;
	con = rhs.con;
	mov = rhs.mov;
	return *this;
}

feStats &feStats::operator+=(const feStats &rhs) {
	hp  += rhs.hp;
	str += rhs.str;
	mag += rhs.mag;
	skl += rhs.skl;
	spd += rhs.spd;
	lck += rhs.lck;
	def += rhs.def;
	res += rhs.res;
	con += rhs.con;
	mov += rhs.mov;
	return *this;
}

feStats &feStats::operator-=(const feStats &rhs) {
	hp  -= rhs.hp;
	str -= rhs.str;
	mag -= rhs.mag;
	skl -= rhs.skl;
	spd -= rhs.spd;
	lck -= rhs.lck;
	def -= rhs.def;
	res -= rhs.res;
	con -= rhs.con;
	mov -= rhs.mov;
	return *this;
}

feStats &feStats::operator*=(const feStats &rhs) {
	hp  *= rhs.hp;
	str *= rhs.str;
	mag *= rhs.mag;
	skl *= rhs.skl;
	spd *= rhs.spd;
	lck *= rhs.lck;
	def *= rhs.def;
	res *= rhs.res;
	con *= rhs.con;
	mov *= rhs.mov;
	return *this;
}

feStats &feStats::operator/=(const feStats &rhs) {
	if (rhs.hp  == 0) { hp  = 0; }
	else { hp  /= rhs.hp; }
	if (rhs.str == 0) { str = 0; }
	else { str /= rhs.str; }
	if (rhs.mag == 0) { mag = 0; }
	else { mag /= rhs.mag; }
	if (rhs.skl == 0) { skl = 0; }
	else { skl /= rhs.skl; }
	if (rhs.spd == 0) { spd = 0; }
	else { spd /= rhs.spd; }
	if (rhs.lck == 0) { lck = 0; }
	else { lck /= rhs.lck; }
	if (rhs.def == 0) { def = 0; }
	else { def /= rhs.def; }
	if (rhs.res == 0) { res = 0; }
	else { res /= rhs.res; }
	if (rhs.mov == 0) { mov = 0; }
	else { con /= rhs.con; }
	if (rhs.con == 0) { con = 0; }
	else { mov /= rhs.mov; }
	return *this;
}
