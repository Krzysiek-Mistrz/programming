#include "gtest/gtest.h"
#include "catalogue.hpp"

TEST(ProductTest, create) {
    Product product("RB01", "Robot", 10.2);

    EXPECT_EQ(product.get_id(), "RB01");
    EXPECT_EQ(product.get_name(), "Robot");
    EXPECT_EQ(product.get_price(), 10.2);
}

TEST(ProductTest, toString) {
    Product product("RB01", "Robot", 10.2);

    std::string str = to_string(product);

    ASSERT_EQ(str, "Robot [RB01] : $10.20");
}
