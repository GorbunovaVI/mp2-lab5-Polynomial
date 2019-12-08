#include <gtest.h>
#include <string>
#include "exponent.h"
#include "monom.h"
#include "polynomial.h"
#include "parser.h"

TEST(polynomial, can_create_pol)
{
	parser p;
	std::string pol1 = "-14.88x^2y^5";
	polynomial x1;

	ASSERT_NO_THROW(p.try_parse(pol1, x1));
}

TEST(polynomial, can_add_pol)
{
	parser p;
	std::string pol1 = "-14.88x^2y^5";
	std::string pol2 = "-14.88x^2y^5+2";
	polynomial x1, x2;

	p.try_parse(pol1, x1);
	p.try_parse(pol2, x2);

	ASSERT_NO_THROW(x1 + x2);
}

TEST(polynomial, can_sub_pol)
{
	parser p;
	std::string pol1 = "-14.88x^2y^5";
	std::string pol2 = "-14.88x^2y^5+2";
	polynomial x1, x2;

	p.try_parse(pol1, x1);
	p.try_parse(pol2, x2);

	ASSERT_NO_THROW(x1 - x2);
}

TEST(polynomial, can_myltiply_pol)
{
	parser p;
	std::string pol1 = "-14.88x^2y^5";
	std::string pol2 = "-14.88x^2y^5+2";
	polynomial x1, x2;

	p.try_parse(pol1, x1);
	p.try_parse(pol2, x2);

	ASSERT_NO_THROW(x1 * x2);
}

TEST(polynomial, can_multiply_pol_on_const)
{
	parser p;
	std::string pol1 = "-14.88x^2y^5";
	polynomial x1;

	p.try_parse(pol1, x1);

	ASSERT_NO_THROW(x1 * 2);
}