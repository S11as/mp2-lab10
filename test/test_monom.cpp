#include "TMonom.h"
#include <gtest.h>

TEST(TMonom, can_create_monom)
{
    ASSERT_NO_THROW(TMonom a(new double[3]{ 1, 2, 3 }, 3, 1));
}

TEST(TMonom, can_copy_monom)
{
    TMonom a(new double[3]{ 1, 2, 3 }, 3, 1);
    ASSERT_NO_THROW(TMonom b(a));
}

TEST(TMonom, can_assign_monom)
{
    TMonom a(new double[3]{ 1, 2, 3 }, 3, 1);
    ASSERT_NO_THROW(TMonom b = a);
}

TEST(TMonom, can_compare_monom_operator_equally)
{
    TMonom a(new double[3]{ 1, 2, 3 }, 3, 1);
    TMonom b(new double[3]{ 1, 2, 3 }, 3, 1);
    EXPECT_EQ(a == b, true);
}

TEST(TMonom, can_compare_monom_operator_not_equally)
{
    TMonom a(new double[3]{ 1, 2, 3 }, 3, 1);
    TMonom b(new double[3]{ 1, 2, 3 }, 3, 1);
    EXPECT_EQ(a != b, false);
}

TEST(TMonom, can_get_K)
{
    TMonom a(new double[3]{ 1, 2, 3 }, 3, 1);
    EXPECT_EQ(a.get_k(), 1);
}

TEST(TMonom, can_set_K)
{
    TMonom a(new double[3]{ 1, 2, 3 }, 3, 1);
    a.set_k(4);
    EXPECT_EQ(a.get_k(), 4);
}

TEST(TMonom, can_get_dim)
{
    TMonom a(new double[3]{ 1, 2, 3 }, 3, 1);
    EXPECT_EQ(a.get_dim(), 3);
}

TEST(TMonom, can_set_dim)
{
    TMonom a(new double[3]{ 1, 2, 3 }, 3, 1);
    a.set_dim(10);
    EXPECT_EQ(a.get_dim(), 10);
}

TEST(TMonom, can_get_elem_data)
{
    TMonom a(new double[3]{ 1, 2, 3 }, 3, 1);
    EXPECT_EQ(a[0], 1);
}

TEST(TMonom, operator_multiplication)
{
    TMonom a(new double[3]{ 1, 2, 3 }, 3, 1);
    TMonom b(new double[3]{ 3, 2, 1 }, 3, 1);
    TMonom c;
    ASSERT_NO_THROW(b * a);
}

TEST(TMonom, operator_division)
{
    TMonom a(new double[3]{ 1, 2, 3 }, 3, 1);
    TMonom b(new double[3]{ 3, 2, 1 }, 3, 1);
    ASSERT_NO_THROW(a / b);
}

TEST(TMonom, operator_plus)
{
    TMonom a(new double[1]{ 3 }, 1, 1);
    TMonom b(new double[1]{ 1 }, 1, 1);
    ASSERT_NO_THROW(a + b);
}

TEST(TMonom, operator_minus)
{
    TMonom a(new double[3]{ 1, 2, 3 }, 3, 1);
    TMonom b(new double[3]{ 3, 2, 1 }, 3, 1);
    ASSERT_NO_THROW(b - a);
}

TEST(TMonom, operator_greater)
{
    TMonom a(new double[3]{ 1, 2, 3 }, 3, 1);
    TMonom b(new double[3]{ 3, 2, 1 }, 3, 1);

    EXPECT_EQ(a > b, false);
}

TEST(TMonom, operator_less)
{
    TMonom a(new double[3]{ 1, 2, 3 }, 3, 1);
    TMonom b(new double[3]{ 3, 2, 1 }, 3, 1);

    EXPECT_EQ(a < b, true);
}
