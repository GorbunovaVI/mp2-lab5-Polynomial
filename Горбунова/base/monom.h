#pragma once
#include <string>
#include "exponent.h"

class monom
{
	double a;
	exponent exp;

public:
	monom() : a(0.0), exp(0, { 0,0,0 }) {}
	monom(double _a, int _max_pow, const power &_e) : a(_a), exp(_max_pow, _e) {};
	monom(const monom&) = default;

	double get_const() const;
	power get_exponents() const;
	exponent get_exp() const { return exp; }

	monom& operator+=(const monom &rhs);
	monom& operator-=(const monom &rhs);
	monom& operator*=(double rhs);
	monom& operator*=(const monom &rhs);

	monom& operator=(const monom&) = default;

	std::string get_monom() const;
};

monom operator+(const monom &lhs, const monom &rhs);
monom operator-(const monom &lhs, const monom &rhs);
monom operator*(const monom &lhs, const monom &rhs);
monom operator*(const monom &lhs, double rhs);
monom operator*(double lhs, const monom &rhs);