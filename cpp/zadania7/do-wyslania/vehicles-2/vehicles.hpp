#ifndef VEHICLES_HPP_
#define VEHICLES_HPP_

#include <string>
#include <vector>
#include <functional>
#include <cstdint>

class Vehicle {
    std::string id_;
    std::string brand_;
    inline static std::int64_t next_vin_ = 1;
    std::int64_t vin_;
public:
    Vehicle(std::string id, std::string brand) : id_(id), brand_(brand), vin_(next_vin_++) {}
    Vehicle(const Vehicle&) = default;
    std::string get_id() const { return id_; }
    std::string get_brand() const { return brand_; }
    virtual double get_max_speed() const = 0;
    std::int64_t get_vin() const { return vin_; };
    static void reset_vin_counter() { next_vin_ = 1; };
    virtual ~Vehicle() = default;
};

std::string to_string(const Vehicle& vehicle);

std::string to_string(std::vector<Vehicle*>::const_iterator vehicles_begin,
                      std::vector<Vehicle*>::const_iterator vehicles_end);

class Car : public Vehicle {
    double engine_hp_;
public:
    Car(std::string id, std::string brand, double engine_hp) : Vehicle(id, brand), engine_hp_(engine_hp) {}
    Car(const Car&) = default;
    double get_max_speed() const override { return engine_hp_; }
};

class Bicycle : public Vehicle {
    int n_gears_;
public:
    Bicycle(std::string id, std::string brand, int n_gears) : Vehicle(id, brand), n_gears_(n_gears) {}
    Bicycle(const Bicycle&) = default;
    double get_max_speed() const override { return n_gears_ * 3; }
};

double compute_min_travel_duration(double distance, const Vehicle& vehicle);

std::string compute_min_travel_duration_as_string(double distance, const Vehicle& vehicle);

std::vector<Vehicle*> filter_vehicles(
        std::vector<Vehicle*>::const_iterator vehicles_begin,
        std::vector<Vehicle*>::const_iterator vehicles_end,
        std::function<bool(const Vehicle&)> predicate);

#endif /* VEHICLES_HPP_ */
