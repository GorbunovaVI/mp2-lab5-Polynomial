#pragma once
#include <string>

struct power
{
	int x_pow, y_pow, z_pow;
	power& operator=(const power&) = default;
};

class exponent
{
	int p;
	int conv;

	power involution(int _conv) const; 
	int convolution(const power & _e) const; 
public:
	exponent(int _p, const power & _e);
	exponent(const exponent&) = default;

	int get_max_power() const;
	power get_exponents() const;

	bool operator==(const exponent &rhs) const;
	bool operator!=(const exponent &rhs) const;
	bool operator>(const exponent &rhs) const;
	bool operator>=(const exponent &rhs) const;
	bool operator<(const exponent &rhs) const;
	bool operator<=(const exponent &rhs) const;

	exponent& operator+=(const exponent &rhs);
	exponent& operator-=(const exponent &rhs);

	exponent& operator=(const exponent&) = default;

	std::string get_exp() const;
};

exponent operator+(const exponent &lhs, const exponent &rhs);
exponent operator-(const exponent &lhs, const exponent &rhs);

