#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "vehicles.hpp"

using ::testing::Property;

TEST(CarTest, getMaxSpeed) {
    Car car("", "", 100.0);

    EXPECT_EQ(car.get_max_speed(), 100.0);
}

TEST(BicycleTest, getMaxSpeed) {
    Bicycle bike("", "", 8);

    EXPECT_EQ(bike.get_max_speed(), 24);
}

TEST(VehicleTest, toString) {
    Car car("KR 00001", "Toyota", 100.0);

    std::string str = to_string(car);

    ASSERT_EQ(str, "KR 00001 :  Toyota");
}

TEST(VehicleTest, VIN) {
    Vehicle::reset_vin_counter();

    Car car1("", "", 100.0);
    Car car2("", "", 100.0);

    EXPECT_EQ(car1.get_vin(), 1);
    EXPECT_EQ(car2.get_vin(), 2);
}

TEST(VehicleAuxTest, computeMinTravelDuration) {
    Car car("", "", 100.0);
    Bicycle bike("", "", 8);

    double distance = 50;
    double result_car = compute_min_travel_duration(distance, car);
    double result_bicycle = compute_min_travel_duration(distance, bike);

    EXPECT_DOUBLE_EQ(result_car, distance / car.get_max_speed());
    EXPECT_DOUBLE_EQ(result_bicycle, distance / bike.get_max_speed());
}

TEST(VehicleAuxTest, computeMinTravelDurationAsString) {
    Car car("", "", 100.0);
    Bicycle bike("", "", 8);

    double distance = 50;
    std::string result_car = compute_min_travel_duration_as_string(distance, car);
    std::string result_bicycle = compute_min_travel_duration_as_string(distance, bike);

    EXPECT_EQ(result_car, "0.500 h");
    EXPECT_EQ(result_bicycle, "2.083 h");
}

TEST(VehicleAuxTest, filter) {
    Car car1("C1", "", 100.0);
    Car car2("C2", "", 200.0);
    Bicycle bicycle("B1", "", 1);

    std::vector<Vehicle*> vehicles = {&car1, &bicycle, &car2};
    std::function<bool(const Vehicle&)> faster_than_50kph = [](const Vehicle& vehicle) {
        return vehicle.get_max_speed() > 50;
    };
    auto filtered_vehicles = filter_vehicles(std::begin(vehicles), std::end(vehicles), faster_than_50kph);

    ASSERT_EQ(filtered_vehicles.size(), 2U);
    EXPECT_THAT(filtered_vehicles, Contains(Property(&Vehicle::get_id, car1.get_id())));
    EXPECT_THAT(filtered_vehicles, Contains(Property(&Vehicle::get_id, car2.get_id())));
}
