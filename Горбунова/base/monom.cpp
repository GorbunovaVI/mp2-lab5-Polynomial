#include <string>
#include "exponent.h"
#include "monom.h"

double monom::get_const() const
{
	return a;
}

power monom::get_exponents() const
{
	return exp.get_exponents();
}

monom& monom::operator+=(const monom &rhs)
{
	if (rhs.exp != exp) throw "Exponents not equal";
	a += rhs.a;
	return *this;
}

monom& monom::operator-=(const monom &rhs)
{
	if (rhs.exp != exp) throw "Exponents not equal";
	a -= rhs.a;
	return *this;
}

monom& monom::operator*=(double rhs)
{
	a *= rhs;
	return *this;
}

monom& monom::operator*=(const monom &rhs)
{
	a *= rhs.a;
	exp += rhs.exp;
	return *this;
}

std::string monom::get_monom() const
{
	char s[100];
	std::sprintf(s, "%.2lf", a);

	return std::string(s) + exp.get_exp();
}

monom operator+(const monom &lhs, const monom &rhs)
{
	monom temp(lhs);
	return temp += rhs;
}

monom operator-(const monom &lhs, const monom &rhs)
{
	monom temp(lhs);
	return temp -= rhs;
}

monom operator*(const monom &lhs, const monom &rhs)
{
	monom temp(lhs);
	return temp *= rhs;
}

monom operator*(const monom &lhs, double rhs)
{
	monom temp(lhs);
	return temp *= rhs;
}
monom operator*(double lhs, const monom &rhs)
{
	return rhs * lhs;
}