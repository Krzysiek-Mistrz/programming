#include "gtest/gtest.h"
#include "matlab.hpp"

TEST(MatlabVectorTest, createWithSize) {
    MatVect v(2U);
    ASSERT_EQ(v.size(), 2U);
    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(v[1], 0);
}

TEST(MatlabVectorTest, createFromVector) {
    MatVect v(std::vector<int>{1, 2});
    ASSERT_EQ(v.size(), 2U);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
}

TEST(MatlabVectorTest, norm) {
    std::vector<int> vs{3, 4, 0};
    MatVect v(vs);
    EXPECT_EQ(v.norm(), 5);
}

TEST(MatlabVectorTest, add) {
    MatVect v1(std::vector<int>{1, 2});
    MatVect v2(std::vector<int>{4, 5}); //list initialization
    MatVect v_sum = add_vectors(v1, v2);
    ASSERT_EQ(v_sum.size(), 2U);
    EXPECT_EQ(v_sum[0], 5);
    EXPECT_EQ(v_sum[1], 7);
}

TEST(MatlabVectorTest, toString) {
    MatVect v(std::vector<int>{1, 2});
    std::string str = to_string(v);
    ASSERT_EQ(str, "[ 1, 2 ]");
}