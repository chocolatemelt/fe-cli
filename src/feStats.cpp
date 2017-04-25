#include "feStats.h"

const feStats feStats::ZERO = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

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
	feStats ret = {
		hp  += rhs.hp,
		str += rhs.str,
		mag += rhs.mag,
		skl += rhs.skl,
		lck += rhs.lck,
		def += rhs.def,
		res += rhs.res,
		con += rhs.con,
		mov += rhs.mov};
	return ret;
}

feStats feStats::operator-(const feStats &rhs) const {
	feStats ret = {
		hp  -= rhs.hp,
		str -= rhs.str,
		mag -= rhs.mag,
		skl -= rhs.skl,
		lck -= rhs.lck,
		def -= rhs.def,
		res -= rhs.res,
		con -= rhs.con,
		mov -= rhs.mov};
	return ret;
}

feStats feStats::operator*(const feStats &rhs) const {
	feStats ret = {
		hp  *= rhs.hp,
		str *= rhs.str,
		mag *= rhs.mag,
		skl *= rhs.skl,
		lck *= rhs.lck,
		def *= rhs.def,
		res *= rhs.res,
		con *= rhs.con,
		mov *= rhs.mov};
	return ret;
}

feStats feStats::operator/(const feStats &rhs) const {
	feStats ret = {
		hp  /= rhs.hp,
		str /= rhs.str,
		mag /= rhs.mag,
		skl /= rhs.skl,
		lck /= rhs.lck,
		def /= rhs.def,
		res /= rhs.res,
		con /= rhs.con,
		mov /= rhs.mov};
	return ret;
}

feStats &feStats::operator=(const feStats &rhs) {
	this->hp  = rhs.hp;
	this->str = rhs.str;
	this->mag = rhs.mag;
	this->skl = rhs.skl;
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
	this->lck /= rhs.lck;
	this->def /= rhs.def;
	this->res /= rhs.res;
	this->con /= rhs.con;
	this->mov /= rhs.mov;
	return *this;
}
