#include "gtest/gtest.h"
#include "vehicles.hpp"

TEST(DriverTest, toStringNoVehicle) {
    Driver owner("Krzysztof Koznierski", Gender::Male);
    std::string str = to_string(owner);
    ASSERT_EQ(str, "Krzysztof Koznierski : [no vehicle]");
}

TEST(DriverTest, toStringWithVehicle) {
    Driver owner("Krzysztof Koznierski", std::make_unique<Car>("A1", "Mercedes", 500.0), Gender::Male);
    std::string str = to_string(owner);
    std::string vehicle_str = to_string(*(owner.get_vehicle()));
    ASSERT_EQ(str, "Krzysztof Koznierski : [" + vehicle_str + "]");
}

TEST(DriverAuxTest, assignVehicleToDriver) {
    std::vector<std::unique_ptr<Vehicle>> vehicles;
    vehicles.push_back(std::make_unique<Car>("A1", "Mercedes", 300));
    vehicles.push_back(std::make_unique<Bicycle>("A2", "Kross", 8));
    vehicles.push_back(std::make_unique<Car>("A3", "Honda", 200));
    Driver owner("", Gender::Male);
    assign_vehicle_to_driver(vehicles, owner);
    ASSERT_EQ(vehicles.size(), 2U);
    EXPECT_EQ(vehicles[0]->get_id(), "A1");
    EXPECT_EQ(vehicles[1]->get_id(), "A2");
    EXPECT_EQ((owner.get_vehicle())->get_id(), "A3");
}

TEST(DriverAuxTest, copying) {
    Driver driver1("Krzysztof Koznierski", std::make_unique<Car>("A1", "Mercedes", 500.0), Gender::Male);
    Driver driver2(std::move(driver1));
    EXPECT_EQ(driver1.get_vehicle(), nullptr);
    EXPECT_EQ((driver2.get_vehicle())->get_id(), "A1");
}

TEST(DriverAuxTest, assignment) {
    Driver driver1("Krzysztof Koznierski", std::make_unique<Car>("A1", "Mercedes", 500.0), Gender::Male);
    Driver driver2("Bogdan Babacki", Gender::Male);
    driver2 = std::move(driver1);
    EXPECT_EQ(driver1.get_vehicle(), nullptr);
    EXPECT_EQ((driver2.get_vehicle())->get_id(), "A1");
}
