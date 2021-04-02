
#include <gtest.h>
#include "TPolinomial.h"

TEST(Polinom, can_create_polinomial) {
    ASSERT_NO_THROW(TPolinomial a);
}

TEST(Polinom, can_copy_polinomial) {
    TMonom a(new double[3]{1.1,2.2,3.3}, 3, 1);
    TMonom b(new double[3]{3,2,1}, 3, 1);
    TPolinomial aa;
    aa+=a;
    aa+=b;
    ASSERT_NO_THROW(TPolinomial bb(aa););
}

TEST(Polinom, operator_add) {
    TMonom a(new double[3]{1, 2, 3}, 3, 1);
    TPolinomial b;
    ASSERT_NO_THROW(b += a);
}

TEST(Polinom, operator_multiplication) {
    TMonom a(new double[3]{1, 2, 3}, 3, 1);
    TMonom b(new double[3]{3, 2, 1}, 3, 1);
    TPolinomial P1, P2;
    P1 += a;
    P2 += b;

    ASSERT_NO_THROW(P1 * P2);
}

TEST(Polinom, operator_plus) {
    TMonom a(new double[3]{1, 2, 3}, 3, 1);
    TMonom b(new double[3]{3, 2, 1}, 3, 1);
    TPolinomial P1, P2, P3;
    P1 += a;
    P2 += b;

    ASSERT_NO_THROW(P2 + P1);
}

TEST(Polinom, operator_minus) {
    TMonom a(new double[3]{1, 2, 3}, 3, 1);
    TMonom b(new double[3]{3, 2, 1}, 3, 1);
    TPolinomial P1, P2;
    P1 += a;
    P2 += b;

    ASSERT_NO_THROW(P2 - P1);
}

TEST(Polinom, monom_can_have_fractional_powers)
{
    TMonom a(new double[3]{1.55, 2.75, 3.95}, 3, 1);
    TPolinomial P1;
    ASSERT_NO_THROW(P1 += a);
}

TEST(Polinom, monoms_have_settable_dimensions)
{
    ASSERT_NO_THROW(TMonom a(new double[5]{1, 2, 3, 4, 5}, 5, 1));
    ASSERT_NO_THROW(TMonom b(new double[6]{1, 2, 3, 4, 5, 6}, 10, 1));
}
