#include "gtest/gtest.h"

#include "matlab.hpp"

TEST(MatlabVectorTest, add) {
    const std::size_t v_size = 3;
    int v1[] = {1, 2, 3};
    int v2[] = {4, 5, 6};

    int* v_sum = add_vectors(v1, v2, v_size);
    ASSERT_NE((int*) NULL, v_sum);

    EXPECT_EQ(v_sum[0], 5);
    EXPECT_EQ(v_sum[1], 7);
    EXPECT_EQ(v_sum[2], 9);
}
