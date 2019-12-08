#pragma once
//#include <list>
#include "list.h"
#include <string>
#include "monom.h"
#include "exponent.h"

class parser;

class polynomial
{
	list<monom> pol;

	void add_monom(const monom &obj);
public:
	polynomial& operator+=(const polynomial &rhs);
	polynomial& operator-=(const polynomial &rhs);
	polynomial& operator*=(const double rhs);
	polynomial& operator*=(const polynomial &rhs);

	std::string get_polinomial() const;

	friend parser;
};

polynomial operator+(const polynomial &lhs, const polynomial &rhs);
polynomial operator-(const polynomial &lhs, const polynomial &rhs);
polynomial operator*(const polynomial &lhs, const polynomial &rhs);
polynomial operator*(const polynomial &lhs, double rhs);
polynomial operator*(double lhs, const polynomial &rhs);

