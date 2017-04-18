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

feStats feStats::operator+(const feStats &rhs) const {
}

feStats feStats::operator-(const feStats &rhs) const {
}

feStats &feStats::operator=(const feStats &rhs) {
}

feStats &feStats::operator+=(const feStats &rhs) {
}

feStats &feStats::operator-=(const feStats &rhs) {
}
