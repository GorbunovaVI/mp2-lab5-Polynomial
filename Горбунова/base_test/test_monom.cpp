#include <gtest.h>
#include <string>
#include "exponent.h"
#include "monom.h"

TEST(monom, can_create_monom)
{
	ASSERT_NO_THROW(monom(10, 30, { 1,2,4 }));
}

TEST(monom, can_get_const)
{
	monom m(10, 30, { 1,2,4 });

	ASSERT_EQ(10, m.get_const());
}

TEST(monom, can_get_x_power)
{
	monom m(10, 30, { 1,2,4 });

	ASSERT_EQ(1, m.get_exponents().x_pow);
}

TEST(monom, can_get_y_power)
{
	monom m(10, 30, { 1,2,4 });

	ASSERT_EQ(2, m.get_exponents().y_pow);
}

TEST(monom, can_get_z_power)
{
	monom m(10, 30, { 1,2,4 });

	ASSERT_EQ(4, m.get_exponents().z_pow);
}

TEST(monom, can_add_monoms)
{
	monom m1(10, 30, { 1,2,4 });
	monom m2(10, 30, { 1,2,4 });

	monom res = m1 + m2;

	ASSERT_EQ(20, res.get_const());
}

TEST(monom, can_sub_monoms)
{
	monom m1(10, 30, { 1,2,4 });
	monom m2(9, 30, { 1,2,4 });

	monom res = m1 - m2;

	ASSERT_EQ(1, res.get_const());
}

TEST(monom, can_multiply_monoms)
{
	monom m1(10, 30, { 1,2,4 });
	monom m2(10, 30, { 1,2,4 });

	monom res = m1 * m2;

	ASSERT_EQ(100, res.get_const());
}

TEST(monom, can_multiply_monom_on_const)
{
	monom m1(10, 30, { 1,2,4 });

	monom res = m1 * 2;

	ASSERT_EQ(20, res.get_const());
}