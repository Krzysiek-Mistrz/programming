#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "catalogue.hpp"

using ::testing::Property;

TEST(CatalogueTest, containsKeyIsNotPresent) {
    Product p("P", "", 0.0);
    Catalogue catalogue;

    EXPECT_FALSE(catalogue.contains(p.get_id()));
}

TEST(CatalogueTest, containsKeyIsPresent) {
    Product p("P", "", 0.0);
    Catalogue catalogue;
    catalogue.add_product(p);

    EXPECT_TRUE(catalogue.contains(p.get_id()));
}

TEST(CatalogueTest, getProductsWithAppropriatePrice) {
    Product p1("X1", "Toy X1", 10.3);
    Product p2("X2", "Toy X2", 8.3);

    Catalogue catalogue(Catalogue::inventory_t{
            {p1.get_id(), p1},
            {p2.get_id(), p2},
    });

    std::function<bool(double)> critFunction = [](double price) {
        return (price < 10.0);
    };
    auto filtered_products = catalogue.get_products_with_appropriate_price(critFunction);

    ASSERT_EQ(filtered_products.size(), 1U);
    EXPECT_EQ(filtered_products[0].get_id(), p2.get_id());
}

TEST(CatalogueTest, get_products_by_name_part_case_sensitive) {
    Product p1("X1", "TOY uppercase", 10);
    Product p2("X2", "toy lowercase", 10);

    Catalogue catalogue(Catalogue::inventory_t{
        {p1.get_id(), p1},
        {p2.get_id(), p2},
    });

    auto filtered_products = catalogue.get_products_by_name_part("toy", true);

    ASSERT_EQ(filtered_products.size(), 1U);
    EXPECT_EQ(filtered_products[0].get_id(), p2.get_id());
}

TEST(CatalogueTest, get_products_by_name_part_case_insensitive) {
    Product p1("X1", "TOY uppercase", 10);
    Product p2("X2", "toy lowercase", 10);

    Catalogue catalogue(Catalogue::inventory_t{
        {p1.get_id(), p1},
        {p2.get_id(), p2},
    });

    auto filtered_products = catalogue.get_products_by_name_part("toy");

    ASSERT_EQ(filtered_products.size(), 2U);

    EXPECT_THAT(filtered_products, Contains(Property(&Product::get_id, p1.get_id())));

    EXPECT_THAT(filtered_products, Contains(Property(&Product::get_id, p2.get_id())));
}