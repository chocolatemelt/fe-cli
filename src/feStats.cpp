#include "feStats.h"

const feStats feStats::ZERO = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

void feStats::flatassign(int value) {
	this->hp  = value;
	this->str = value;
	this->mag = value;
	this->skl = value;
	this->spd = value;
	this->lck = value;
	this->def = value;
	this->res = value;
	this->con = value;
	this->mov = value;
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
	feStats ret = {
		hp % rhs.hp,
	  str % rhs.str,
	  mag % rhs.mag,
	  skl % rhs.skl,
	  spd % rhs.spd,
	  lck % rhs.lck,
	  def % rhs.def,
	  res % rhs.res,
	  con % rhs.con,
	  mov % rhs.mov
	};
	return ret;
}

feStats feStats::operator+(const feStats &rhs) const {
	feStats ret;
	ret.hp  = this->hp  + rhs.hp;
	ret.str = this->str + rhs.str;
	ret.mag = this->mag + rhs.mag;
	ret.skl = this->skl + rhs.skl;
	ret.spd = this->spd + rhs.spd;
	ret.lck = this->lck + rhs.lck;
	ret.def = this->def + rhs.def;
	ret.res = this->res + rhs.res;
	ret.con = this->con + rhs.con;
	ret.mov = this->mov + rhs.mov;
	return ret;
}

feStats feStats::operator-(const feStats &rhs) const {
	feStats ret;
	ret.hp  = this->hp  - rhs.hp;
	ret.str = this->str - rhs.str;
	ret.mag = this->mag - rhs.mag;
	ret.skl = this->skl - rhs.skl;
	ret.spd = this->spd - rhs.spd;
	ret.lck = this->lck - rhs.lck;
	ret.def = this->def - rhs.def;
	ret.res = this->res - rhs.res;
	ret.con = this->con - rhs.con;
	ret.mov = this->mov - rhs.mov;
	return ret;
}

feStats feStats::operator*(const feStats &rhs) const {
	feStats ret;
	ret.hp  = this->hp  * rhs.hp;
	ret.str = this->str * rhs.str;
	ret.mag = this->mag * rhs.mag;
	ret.skl = this->skl * rhs.skl;
	ret.spd = this->spd * rhs.spd;
	ret.lck = this->lck * rhs.lck;
	ret.def = this->def * rhs.def;
	ret.res = this->res * rhs.res;
	ret.con = this->con * rhs.con;
	ret.mov = this->mov * rhs.mov;
	return ret;
}

feStats feStats::operator/(const feStats &rhs) const {
	feStats ret;
	ret.hp  = this->hp  / rhs.hp;
	ret.str = this->str / rhs.str;
	ret.mag = this->mag / rhs.mag;
	ret.skl = this->skl / rhs.skl;
	ret.spd = this->spd / rhs.spd;
	ret.lck = this->lck / rhs.lck;
	ret.def = this->def / rhs.def;
	ret.res = this->res / rhs.res;
	ret.con = this->con / rhs.con;
	ret.mov = this->mov / rhs.mov;
	return ret;
}

feStats &feStats::operator=(const feStats &rhs) {
	if (this == &rhs) {
		return *this;
	}

	this->hp  = rhs.hp;
	this->str = rhs.str;
	this->mag = rhs.mag;
	this->skl = rhs.skl;
	this->spd = rhs.spd;
	this->lck = rhs.lck;
	this->def = rhs.def;
	this->res = rhs.res;
	this->con = rhs.con;
	this->mov = rhs.mov;
	return *this;
}

feStats &feStats::operator+=(const feStats &rhs) {
	this->hp  += rhs.hp;
	this->str += rhs.str;
	this->mag += rhs.mag;
	this->skl += rhs.skl;
	this->spd += rhs.spd;
	this->lck += rhs.lck;
	this->def += rhs.def;
	this->res += rhs.res;
	this->con += rhs.con;
	this->mov += rhs.mov;
	return *this;
}

feStats &feStats::operator-=(const feStats &rhs) {
	this->hp  -= rhs.hp;
	this->str -= rhs.str;
	this->mag -= rhs.mag;
	this->skl -= rhs.skl;
	this->spd -= rhs.spd;
	this->lck -= rhs.lck;
	this->def -= rhs.def;
	this->res -= rhs.res;
	this->con -= rhs.con;
	this->mov -= rhs.mov;
	return *this;
}

feStats &feStats::operator*=(const feStats &rhs) {
	this->hp  *= rhs.hp;
	this->str *= rhs.str;
	this->mag *= rhs.mag;
	this->skl *= rhs.skl;
	this->spd *= rhs.spd;
	this->lck *= rhs.lck;
	this->def *= rhs.def;
	this->res *= rhs.res;
	this->con *= rhs.con;
	this->mov *= rhs.mov;
	return *this;
}

feStats &feStats::operator/=(const feStats &rhs) {
	this->hp  /= rhs.hp;
	this->str /= rhs.str;
	this->mag /= rhs.mag;
	this->skl /= rhs.skl;
	this->spd /= rhs.spd;
	this->lck /= rhs.lck;
	this->def /= rhs.def;
	this->res /= rhs.res;
	this->con /= rhs.con;
	this->mov /= rhs.mov;
	return *this;
}
