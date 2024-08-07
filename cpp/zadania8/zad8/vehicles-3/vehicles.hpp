#ifndef VEHICLES_HPP_
#define VEHICLES_HPP_

#include <string>
#include <vector>
#include <functional>
#include <cstdint>
#include <memory>

class Vehicle {
public:
    Vehicle(std::string id, std::string brand) : id_(id), brand_(brand), vin_(next_vin_++) {}

    Vehicle(const Vehicle&) = default;

    static void reset_vin_counter() { next_vin_ = 1; }

    std::int64_t get_vin() const { return vin_; }

    std::string get_id() const { return id_; }

    std::string get_brand() const { return brand_; }

    virtual double get_max_speed() const = 0;

    virtual ~Vehicle() = default;

private:
    std::string id_;
    std::string brand_;
    inline static std::int64_t next_vin_ = 1;
    std::int64_t vin_;
};

std::string to_string(const Vehicle& vehicle);

std::string to_string(std::vector<Vehicle*>::const_iterator vehicles_begin,
                      std::vector<Vehicle*>::const_iterator vehicles_end);

class Car : public Vehicle {
public:
    Car(std::string id, std::string brand, double engine_hp) : Vehicle(id, brand), engine_hp_(engine_hp) {}
    Car(const Car&) = default;

    double get_max_speed() const override { return engine_hp_; }

private:
    double engine_hp_;
};

class Bicycle : public Vehicle {
public:
    Bicycle(std::string id, std::string brand, int n_gears) : Vehicle(id, brand), n_gears_(n_gears) {}
    Bicycle(const Bicycle&) = default;

    double get_max_speed() const override { return n_gears_ * 3; }

private:
    int n_gears_;
};

double compute_min_travel_duration(double distance, const Vehicle& vehicle);

std::string compute_min_travel_duration_as_string(double distance, const Vehicle& vehicle);

std::vector<Vehicle*> filter_vehicles(
        std::vector<Vehicle*>::const_iterator vehicles_begin,
        std::vector<Vehicle*>::const_iterator vehicles_end,
        std::function<bool(const Vehicle&)> predicate);

//typ wyliczeniowy dla plci
enum class Gender {
    Male, Female
};

class Driver {
public:
    //konstruktory zgodnie z diagramem uml (delegujace)
    Driver(std::string name, Gender gender) : Driver(name, nullptr, gender) {}
    Driver(std::string name, std::unique_ptr<Vehicle> vehicle_ptr, Gender gender) : name_(name), vehicle_ptr_(std::move(vehicle_ptr)), gender_(gender) {}
    //usuwamy kontsruktor kopiujacy
    Driver(Driver& other) = delete;
    //konstruktor przenoszacy
    Driver(Driver&& other) : name_(other.name_), vehicle_ptr_(std::move(other.vehicle_ptr_)), gender_(other.gender_) {}
    //usiniecie operatora przypisania
    Driver& operator=(Driver& other) = delete;
    //zamiast przypisania mamy zato operator przeniesienia :)
    Driver& operator=(Driver&& other);
    //przekazujemy inteligenty wskaznik unique i przypisujemy go do prywatnego vehicle_ptr_
    void assign_vehicle(std::unique_ptr<Vehicle> vehicle_ptr) {
        vehicle_ptr_ = std::move(vehicle_ptr);
    }
    std::string get_name() const { return name_; }
    const Vehicle* get_vehicle() const { return vehicle_ptr_.get(); }
    Gender get_gender() { return gender_; }
private:
    std::string name_;
    std::unique_ptr<Vehicle> vehicle_ptr_;
    Gender gender_;
};

std::string to_string(const Driver& owner);

//przydzielamy kierowcy ostatni pojazd z puli nowych pojazdow (przekazanej jako argument)
void assign_vehicle_to_driver(std::vector<std::unique_ptr<Vehicle>>& vehicles, Driver& owner);

#endif /* VEHICLES_HPP_ */
