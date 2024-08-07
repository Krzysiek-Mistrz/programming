#include "vehicles.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>

std::string to_string(const Vehicle& vehicle) {
    std::ostringstream oss;
    oss << vehicle.get_id() << " :  " << vehicle.get_brand();
    return oss.str();
}

std::string to_string(std::vector<Vehicle*>::const_iterator vehicles_begin,
                      std::vector<Vehicle*>::const_iterator vehicles_end) {

    std::string s;
    for (auto it = vehicles_begin; it != vehicles_end; ++it) {
        const auto& vehicle = *(*it);
        s += to_string(vehicle);
        s += "\n";
    }
    return s;
}

double compute_min_travel_duration(double distance, const Vehicle& vehicle) {
    return distance / vehicle.get_max_speed();
}

std::string compute_min_travel_duration_as_string(double distance, const Vehicle& vehicle) {
    std::ostringstream oss;
    oss << std::setprecision(3) << std::fixed
        << compute_min_travel_duration(distance, vehicle) << " h";
    return oss.str();
}

std::vector<Vehicle*> filter_vehicles(
        std::vector<Vehicle*>::const_iterator vehicles_begin,
        std::vector<Vehicle*>::const_iterator vehicles_end,
        std::function<bool(const Vehicle&)> predicate) {

    std::vector<Vehicle*> vehicles_filtered;
    std::copy_if(vehicles_begin, vehicles_end, std::back_inserter(vehicles_filtered),
                 [&predicate](const Vehicle* vehicle_ptr) { return predicate(*vehicle_ptr); });
    return vehicles_filtered;
}

//definiujemy sb nasz operator przeniesienia :)
Driver& Driver::operator=(Driver&& other) {
    name_ = other.name_;
    //bo unique ptr
    vehicle_ptr_ = std::move(other.vehicle_ptr_);
    return (*this);
}

//tak jak poprzednio (juz bylo w jednym cwiczeniu)
std::string to_string(const Driver& owner) {
    std::ostringstream oss;
    oss << owner.get_name() << " : [";
    if(owner.get_vehicle() != nullptr)
        oss << to_string(*owner.get_vehicle());
    else
        oss << "no vehicle";
    oss << "]";
    return oss.str();
}

//przypisujemy odpowiedni pojazd z puli do kierowcy
void assign_vehicle_to_driver(std::vector<std::unique_ptr<Vehicle>>& vehicles, Driver& owner) {
    if(vehicles.size() > 0) {
        auto it_lastVehicle = (vehicles.end() - 1);
        //obiektem wskazywanym przez iterator jest unique ptr
        owner.assign_vehicle(std::move(*it_lastVehicle));
        //i usuwamy ostatni pojazd po przypisaniu
        vehicles.erase(it_lastVehicle);
    } else {
        owner.assign_vehicle(nullptr);
    }
}
