//#include "gmock/gmock.h"
#include "gtest/gtest.h"

extern "C" {
#include "mylib.h"
}

#include <stdint.h>

TEST(BitlibTest, Transform) {
    byte b = 1;
    transform(&b);

    EXPECT_EQ(b, 2);
}
