//#include <list>
#include "list.h"
#include <string>
#include "exponent.h"
#include "monom.h"
#include "polynomial.h"

void polynomial::add_monom(const monom &obj)
{
	pol.push_back(obj);
}

polynomial& polynomial::operator+=(const polynomial &rhs)
{
	list<monom>::iterator iter_lhs;
	list<monom>::const_iterator iter_rhs;
	iter_lhs = pol.begin();
	iter_rhs = rhs.pol.begin();
	while ((iter_lhs != pol.end()) && (iter_rhs != rhs.pol.end()))
	{
		if (iter_lhs->get_exp() > iter_rhs->get_exp())
		{
			++iter_rhs;
			continue;
		}
		if ((iter_lhs->get_exp() == iter_rhs->get_exp()))
		{
			if ((iter_lhs->get_const() + iter_rhs->get_const()) != 0)
			{
				*iter_lhs += *iter_rhs;
				++iter_rhs;
				++iter_lhs;
				continue;
			}
			else
			{
				iter_lhs = pol.erase(iter_lhs);
				++iter_rhs;
				continue;
			}
		}
		if ((iter_lhs->get_exp() < iter_rhs->get_exp()))
		{
			iter_lhs = pol.insert(iter_lhs, *iter_rhs);
			++iter_rhs;
			++iter_lhs;
			continue;
		}
	}
	while (iter_rhs != rhs.pol.end())
	{
		pol.push_back(*iter_rhs);
		++iter_rhs;
	}
	return *this;
}

polynomial& polynomial::operator-=(const polynomial &rhs)
{
	list<monom>::iterator iter_lhs;
	list<monom>::const_iterator iter_rhs;
	iter_lhs = pol.begin();
	iter_rhs = rhs.pol.begin();
	while ((iter_lhs != pol.end()) && (iter_rhs != rhs.pol.end()))
	{
		if (iter_lhs->get_exp() > iter_rhs->get_exp())
		{
			++iter_rhs;
			continue;
		}
		if ((iter_lhs->get_exp() == iter_rhs->get_exp()))
		{
			if (iter_lhs->get_const() != iter_rhs->get_const())
			{
				*iter_lhs -= *iter_rhs;
				++iter_rhs;
				++iter_lhs;
				continue;
			}
			else
			{
				iter_lhs = pol.erase(iter_lhs);
				++iter_rhs;
				continue;
			}
		}
		if ((iter_lhs->get_exp() < iter_rhs->get_exp()))
		{
			iter_lhs = pol.insert(iter_lhs, (*iter_rhs * (-1)));
			++iter_rhs;
			++iter_lhs;
			continue;
		}
	}
	while (iter_rhs != rhs.pol.end())
	{
		pol.push_back((*iter_rhs * (-1)));
		++iter_rhs;
	}
	return *this;
}

polynomial& polynomial::operator*=(const double rhs)
{
	list<monom>::iterator iter;
	for (iter = pol.begin(); iter != pol.end(); ++iter)
	{
		*iter *= rhs;
	}
	return *this;
}

polynomial& polynomial::operator*=(const polynomial &rhs)
{
	list<monom>::iterator iter_lhs;
	list<monom>::const_iterator iter_rhs;
	iter_lhs = pol.begin();
	iter_rhs = rhs.pol.begin();
	polynomial result;
	while (iter_rhs != rhs.pol.end())
	{
		iter_lhs = pol.begin();
		while (iter_lhs != pol.end())
		{
			result.pol.push_back((*iter_lhs) * (*iter_rhs));
			++iter_lhs;
		}
		++iter_rhs;
	}
	std::swap(*this, result);
	return *this;
}

std::string polynomial::get_polinomial() const
{
	std::string result = "";
	list<monom>::const_iterator iter;
	for (iter = pol.begin(); iter != pol.end(); ++iter)
	{
		if (iter != pol.begin())
		{
			if (iter->get_const() >= 0)
			{
				result += "+";
			}
		}
		result += iter->get_monom();
	}
	if (result == "")
	{
		result = "0";
	}
	return result;
}

polynomial operator+(const polynomial &lhs, const polynomial &rhs)
{
	polynomial temp(lhs);
	return temp += rhs;
}

polynomial operator-(const polynomial &lhs, const polynomial &rhs)
{
	polynomial temp(lhs);
	return temp -= rhs;
}

polynomial operator*(const polynomial &lhs, const polynomial &rhs)
{
	polynomial temp(lhs);
	return temp *= rhs;
}

polynomial operator*(const polynomial &lhs, double rhs)
{
	polynomial temp(lhs);
	return temp *= rhs;
}

polynomial operator*(double lhs, const polynomial &rhs)
{
	return rhs * lhs;
}
