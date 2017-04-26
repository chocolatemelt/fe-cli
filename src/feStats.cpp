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
	feStats ret;
	if (rhs.hp  == 0) { ret.hp  = 0; }
	else { ret.hp  = this->hp  % rhs.hp; }
	if (rhs.str == 0) { ret.str = 0; }
	else { ret.str = this->str % rhs.str; }
	if (rhs.mag == 0) { ret.mag = 0; }
	else { ret.mag = this->mag % rhs.mag; }
	if (rhs.skl == 0) { ret.skl = 0; }
	else { ret.skl = this->skl % rhs.skl; }
	if (rhs.spd == 0) { ret.spd = 0; }
	else { ret.spd = this->spd % rhs.spd; }
	if (rhs.lck == 0) { ret.lck = 0; }
	else { ret.lck = this->lck % rhs.lck; }
	if (rhs.def == 0) { ret.def = 0; }
	else { ret.def = this->def % rhs.def; }
	if (rhs.res == 0) { ret.res = 0; }
	else { ret.res = this->res % rhs.res; }
	if (rhs.mov == 0) { ret.mov = 0; }
	else { ret.con = this->con % rhs.con; }
	if (rhs.con == 0) { ret.con = 0; }
	else { ret.mov = this->mov % rhs.mov; }
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
	if (rhs.hp  == 0) { ret.hp  = 0; }
	else { ret.hp  = this->hp  / rhs.hp; }
	if (rhs.str == 0) { ret.str = 0; }
	else { ret.str = this->str / rhs.str; }
	if (rhs.mag == 0) { ret.mag = 0; }
	else { ret.mag = this->mag / rhs.mag; }
	if (rhs.skl == 0) { ret.skl = 0; }
	else { ret.skl = this->skl / rhs.skl; }
	if (rhs.spd == 0) { ret.spd = 0; }
	else { ret.spd = this->spd / rhs.spd; }
	if (rhs.lck == 0) { ret.lck = 0; }
	else { ret.lck = this->lck / rhs.lck; }
	if (rhs.def == 0) { ret.def = 0; }
	else { ret.def = this->def / rhs.def; }
	if (rhs.res == 0) { ret.res = 0; }
	else { ret.res = this->res / rhs.res; }
	if (rhs.mov == 0) { ret.mov = 0; }
	else { ret.con = this->con / rhs.con; }
	if (rhs.con == 0) { ret.con = 0; }
	else { ret.mov = this->mov / rhs.mov; }
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
	if (rhs.hp  == 0) { this->hp  = 0; }
	else { this->hp  /= rhs.hp; }
	if (rhs.str == 0) { this->str = 0; }
	else { this->str /= rhs.str; }
	if (rhs.mag == 0) { this->mag = 0; }
	else { this->mag /= rhs.mag; }
	if (rhs.skl == 0) { this->skl = 0; }
	else { this->skl /= rhs.skl; }
	if (rhs.spd == 0) { this->spd = 0; }
	else { this->spd /= rhs.spd; }
	if (rhs.lck == 0) { this->lck = 0; }
	else { this->lck /= rhs.lck; }
	if (rhs.def == 0) { this->def = 0; }
	else { this->def /= rhs.def; }
	if (rhs.res == 0) { this->res = 0; }
	else { this->res /= rhs.res; }
	if (rhs.mov == 0) { this->mov = 0; }
	else { this->con /= rhs.con; }
	if (rhs.con == 0) { this->con = 0; }
	else { this->mov /= rhs.mov; }
	return *this;
}
