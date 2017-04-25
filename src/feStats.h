#ifndef STATS_H
#define STATS_H

struct feStats {
	static const feStats ZERO;
	int hp;
	int str;
	int mag;
	int skl;
	int spd;
	int lck;
	int def;
	int res;
	int con;
	int mov;

	feStats(const feStats &);
	~feStats() {}

	bool operator==(const feStats &) const;

	feStats operator%(const feStats &) const;
	feStats operator+(const feStats &) const;
	feStats operator-(const feStats &) const;
	feStats operator*(const feStats &) const;
	feStats operator/(const feStats &) const;

	feStats &operator=(const feStats &);
	feStats &operator+=(const feStats &);
	feStats &operator-=(const feStats &);
	feStats &operator*=(const feStats &);
	feStats &operator/=(const feStats &);
};

#endif
