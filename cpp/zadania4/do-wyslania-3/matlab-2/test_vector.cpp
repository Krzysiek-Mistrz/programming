#include "gtest/gtest.h"

#include "matlab.hpp"

TEST(MatlabVectorTest, createWithSize) {
    MatVect v(2U);

    // Użyto ASSERT_XXX, gdyż dalsze warunki testowe mają sens tylko wówczas,
    //   gdy wektor zawiera (co najmniej) dwie składowe. Jeśli warunek nie jest
    //   spełniony, należy bezwzględnie przerwać dalsze wykonywanie testów
    //   (inaczej np. wywołanie `v.get_elem(0)` może rzucić wyjątek, jeśli
    //   kontener jest pusty.
    // EXPECT_XXX jedynie oznacza test jako "nie powiódł się", jednak pozwala na
    //   wykonywanie dalszych instrukcji w ramach tego testu, co często umożlwia
    //   uzyskanie dalszych informacji diagnostycznych (np. tu - informację
    //   o faktycznej wartości obu (!) składowych, niezależnie od tego, czy są
    //   to wartości poprawne, czy też nie.
    ASSERT_EQ(v.size(), 2U);
    EXPECT_EQ(v.get_elem(0), 0);
    EXPECT_EQ(v.get_elem(1), 0);
}

TEST(MatlabVectorTest, norm) {
    MatVect v(3U);
    v.set_elem(0, 3);
    v.set_elem(1, 4);

    EXPECT_EQ(v.norm(), 5);
}

TEST(MatlabVectorTest, add) {
    MatVect v1(2U);
    v1.set_elem(0, 1);
    v1.set_elem(1, 2);

    MatVect v2(2U);
    v2.set_elem(0, 4);
    v2.set_elem(1, 5);

    MatVect v_sum = add_vectors(v1, v2);

    ASSERT_EQ(v_sum.size(), 2U);
    EXPECT_EQ(v_sum.get_elem(0), 5);
    EXPECT_EQ(v_sum.get_elem(1), 7);
}

