#include "gtest/gtest.h"
#include "matlab.hpp"

TEST(MatlabVectorTest, createWithSize) {
    Matlab::Vector v(2U);
    ASSERT_EQ(v.size(), 2U);
    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(v[1], 0);
}

TEST(MatlabVectorTest, createFromVector) {
    Matlab::Vector v(std::vector<int>{1, 2});
    ASSERT_EQ(v.size(), 2U);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
}

TEST(MatlabVectorTest, createFromString) {
    Matlab::Vector v("[1, 2, 3]");
    ASSERT_EQ(v.size(), 3U);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 3);
}

TEST(MatlabVectorTest, norm) {
    std::vector<int> vs{3, 4, 0};
    Matlab::Vector v(vs);
    EXPECT_EQ(v.norm(), 5);
}

//troszke zmieniony :)
TEST(MatlabVectorTest, addVectorsOfSameSize) {
    Matlab::Vector v1(std::vector<int>{1, 2});
    Matlab::Vector v2(std::vector<int>{4, 5});
    //kiedy nie ma wyjatku
    ASSERT_NO_THROW({
        Matlab::Vector v_sum = Matlab::add_vectors(v1, v2);
        ASSERT_EQ(v_sum.size(), 2U);
        EXPECT_EQ(v_sum[0], 5);
        EXPECT_EQ(v_sum[1], 7);
    });
}

TEST(MatlabVectorTest, toString) {
    Matlab::Vector v(std::vector<int>{1, 2});
    std::string str = Matlab::to_string(v);
    ASSERT_EQ(str, "[ 1, 2 ]");
}

TEST(MatlabVectorTest, sumElements) {
    Matlab::Vector v(std::vector<int>{1, 2});
    ASSERT_EQ(v.sum(), 3);
}

//sprawdzenie add vectors :)
TEST(MatlabVectorAuxTest, exceptionCatchingWhenAddingVectorsOfSameSizes) {
    Matlab::Vector v1(std::vector<int> {1});
    Matlab::Vector v2(std::vector<int> {1});
    EXPECT_EQ(Matlab::was_exception_raised_when_adding_vectors(v1, v2), "");
}

TEST(MatlabVectorAuxTest, exceptionCatchingWhenAddingVectorsOfDifferentSizes) {
    Matlab::Vector v1(std::vector<int> {1});
    Matlab::Vector v2(std::vector<int> {1, 2});
    EXPECT_EQ(Matlab::was_exception_raised_when_adding_vectors(v1, v2), "Vectors have unequal size (1 and 2)");
}