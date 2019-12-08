#include <string>
#include "exponent.h"

int exponent::convolution(const power & _e) const
{
	int temp = 0;
	temp = _e.x_pow * p * p + _e.y_pow * p + _e.z_pow;
	return temp;
}

power exponent::involution(int _conv) const
{
	power result;
	result.x_pow = _conv / (p * p);
	result.y_pow = (_conv - result.x_pow * (p * p)) / p;
	result.z_pow = _conv - result.x_pow * (p * p) - result.y_pow * p;
	return result;
}

exponent::exponent(int _p, const power & _e) : p(_p)
{
	conv = convolution(_e);
}

int exponent::get_max_power() const
{
	return p;
}

power exponent::get_exponents() const
{
	return involution(conv);
}

bool exponent::operator==(const exponent &rhs) const
{
	if (p != rhs.p) throw "Bases of number systems not equal";
	return conv == rhs.conv;
}

bool exponent::operator!=(const exponent &rhs) const
{
	return !(*this == rhs);
}

bool exponent::operator>(const exponent &rhs) const
{
	if (p != rhs.p) throw "Bases of number systems not equal";
	return conv > rhs.conv;
}

bool exponent::operator>=(const exponent &rhs) const
{
	return !(*this < rhs);
}

bool exponent::operator<(const exponent &rhs) const
{
	if (p != rhs.p) throw "Bases of number systems not equal";
	return conv < rhs.conv;
}

bool exponent::operator<=(const exponent &rhs) const
{
	return !(*this > rhs);
}

exponent& exponent::operator+=(const exponent &rhs)
{
	if (p != rhs.p) throw "Bases of number systems not equal";
	conv += rhs.conv;
	return *this;
}

exponent& exponent::operator-=(const exponent &rhs)
{
	if (p != rhs.p) throw "Bases of number systems not equal";
	conv -= rhs.conv;
	return *this;
}

std::string exponent::get_exp() const
{
	std::string result = "";
	power temp = involution(conv);
	result += "x^" + std::to_string(temp.x_pow) + "y^" + std::to_string(temp.y_pow) + "z^" + std::to_string(temp.z_pow);
	return result;
}

exponent operator+(const exponent &lhs, const exponent &rhs)
{
	exponent temp(lhs);
	return temp += rhs;
}

exponent operator-(const exponent &lhs, const exponent &rhs)
{
	exponent temp(lhs);
	return temp -= rhs;
}