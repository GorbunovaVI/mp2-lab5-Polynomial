#include <string>
#include <regex>
#include "parser.h"
#include "polynomial.h"
#include "exponent.h"
#include "monom.h"

bool parser::try_parse(std::string str, polynomial &_result)
{
	std::smatch result;
	std::regex regular("([+-]?[0-9]+)""(\\.[0-9]+)?""([xX]?\\^[0-9]+){0,1}""([yY]?\\^[0-9]+){0,1}""([zZ]?\\^[0-9]+){0,1}");
	str += '+';
	int i = 0, j = 1, size = str.size();
	polynomial r;
	while (j < size)
	{
		if ((str[j] == '+') || (str[j] == '-'))
		{
			std::string temp = str.substr(i, j - i);

			if (!regex_search(temp, result, regular)) return false;
			power exp;
			std::string res = result.str();
			double a = 0;
			a = std::stod(result[1].str() + result[2].str());
			if (a != 0.0)
			{
				std::string x, y, z;

				x = result[3].str();
				if (x != "") x = x.substr(2);
				y = result[4].str();
				if (y != "") y = y.substr(2);
				z = result[5].str();
				if (z != "") z = z.substr(2);

				exp.x_pow = std::stoi("0" + x);
				exp.y_pow = std::stoi("0" + y);
				exp.z_pow = std::stoi("0" + z);

				monom m(a, 30, exp);
				r.add_monom(m);
			}
			i = j;
		}
		j++;
	}
	_result.pol = r.pol;
	return true;
}
