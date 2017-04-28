#ifndef SECONDARYSTATS_H
#define SECONDARYSTATS_H

struct feSecondaryStats {
	static const feSecondaryStats ZERO;
	int attack;
	int avoid;
	int critical;
	int hitrate;

	void assign(int value);

	bool operator==(const feSecondaryStats &) const;

	feSecondaryStats operator%(const feSecondaryStats &) const;
	feSecondaryStats operator+(const feSecondaryStats &) const;
	feSecondaryStats operator-(const feSecondaryStats &) const;
	feSecondaryStats operator*(const feSecondaryStats &) const;
	feSecondaryStats operator/(const feSecondaryStats &) const;

	feSecondaryStats &operator=(const feSecondaryStats &);
	feSecondaryStats &operator+=(const feSecondaryStats &);
	feSecondaryStats &operator-=(const feSecondaryStats &);
	feSecondaryStats &operator*=(const feSecondaryStats &);
	feSecondaryStats &operator/=(const feSecondaryStats &);
};


#endif
