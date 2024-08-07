#include "gtest/gtest.h"
#include "matlab.hpp"

TEST(MatlabMatrixTest, createWithSize) {
    Matrix m(2U, 1U);
    ASSERT_EQ(m.size(), 2U);
    EXPECT_EQ(m[0].size(), 1U);
    EXPECT_EQ(m[0][0], 0);
    EXPECT_EQ(m[1].size(), 1U);
    EXPECT_EQ(m[1][0], 0);
}

TEST(MatlabMatrixTest, createFromVectorOfStdVectors) {
    Matrix m(std::vector<std::vector<int>>{
            std::vector<int>{11, 12},
            std::vector<int>{21, 22}
    });
    ASSERT_EQ(m.size(), 2U);
    EXPECT_EQ(m[0].size(), 2U);
    EXPECT_EQ(m[0][0], 11);
    EXPECT_EQ(m[0][1], 12);
    EXPECT_EQ(m[1].size(), 2U);
    EXPECT_EQ(m[1][0], 21);
    EXPECT_EQ(m[1][1], 22);
}

TEST(MatlabMatrixTest, add) {
    Matrix m1(std::vector<std::vector<int>>{
            std::vector<int>{1, 2},
            std::vector<int>{4, 5}
    });
    Matrix m2(std::vector<std::vector<int>>{
            std::vector<int>({0, 1}),
            std::vector<int>({2, 3})
    });
    auto m_sum = add_matrices(m1, m2);
    ASSERT_EQ(m_sum.size(), 2U);
    ASSERT_EQ(m_sum[0].size(), 2U);
    EXPECT_EQ(m_sum[0][0], 1);
    EXPECT_EQ(m_sum[0][1], 3);
    ASSERT_EQ(m_sum[1].size(), 2U);
    EXPECT_EQ(m_sum[1][0], 6);
    EXPECT_EQ(m_sum[1][1], 8);
}

TEST(MatlabMatrixTest, toString) {
    Matrix m(std::vector<std::vector<int>>{
            std::vector<int>{1, 2},
            std::vector<int>{3, 4}
    });
    auto m_str = to_string(m);
    auto r1_str = to_string(m[0]);
    auto r2_str = to_string(m[1]);
    std::string m_str_expect = std::string("")
                               + "[\n"
                               + "  " + r1_str + ",\n"
                               + "  " + r2_str + "\n"
                               + "]";

    ASSERT_EQ(m_str, m_str_expect);
}

TEST(MatlabMatrixTest, sumElements) {
    Matrix m(std::vector<std::vector<int>>{
            std::vector<int>{1, 2},
            std::vector<int>{3, 4}
    });
    ASSERT_EQ(m.sum(), 10);
}
