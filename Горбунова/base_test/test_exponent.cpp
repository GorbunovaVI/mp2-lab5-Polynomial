#include <gtest.h>
#include <string>
#include "exponent.h"

TEST(exponent, can_create_obj)
{
	ASSERT_NO_THROW(exponent(30, { 1,2,4 }));
}

TEST(exponent, can_get_max_power)
{
	exponent e(30, { 1,2,4 });

	ASSERT_EQ(30, e.get_max_power());
}

TEST(exponent, can_get_exponents)
{
	exponent e(30, { 1,2,4 });

	ASSERT_EQ(1, e.get_exponents().x_pow);
}

TEST(exponent, can_compare_exp_not_equal)
{
	exponent e1(30, { 1,2,4 });
	exponent e2(30, { 1,2,5 });

	ASSERT_NE(e1, e2);
}

TEST(exponent, can_compare_exp_equal)
{
	exponent e1(30, { 1,2,4 });
	exponent e2(30, { 1,2,4 });

	ASSERT_EQ(e1, e2);
}

TEST(exponent, can_compare_exp_less)
{
	exponent e1(30, { 1,2,4 });
	exponent e2(30, { 1,2,5 });

	ASSERT_LT(e1, e2);
}

TEST(exponent, can_compare_exp_greater)
{
	exponent e1(30, { 1,2,4 });
	exponent e2(30, { 1,2,5 });

	ASSERT_GT(e2, e1);
}

TEST(exponent, can_add_exp)
{
	exponent e1(30, { 1,2,4 });
	exponent e2(30, { 1,2,5 });

	ASSERT_NO_THROW(e2 + e1);
}

TEST(exponent, can_sub_exp)
{
	exponent e1(30, { 1,2,4 });
	exponent e2(30, { 1,2,5 });

	ASSERT_NO_THROW(e2 - e1);
}