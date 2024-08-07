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

double compute_min_travel_duration(double distance, const Vehicle& vehicle) {
    return distance / vehicle.get_max_speed();
}

std::string compute_min_travel_duration_as_string(double distance, const Vehicle& vehicle) {
    //funkcje z poprzednich cwiczen
    std::ostringstream stream;
    stream << std::setprecision(3) << std::fixed
        << compute_min_travel_duration(distance, vehicle) << " h";
    return stream.str();
}

std::vector<Vehicle*> filter_vehicles(std::vector<Vehicle*>::const_iterator vehicles_begin, std::vector<Vehicle*>::const_iterator vehicles_end, std::function<bool(const Vehicle&)> predicate) {
    std::vector<Vehicle*> filtered;
    //zastosowanie funckji copy_if dla naszego kontenera vehicles, uzywajac wyrazenia lambda
    std::copy_if(vehicles_begin, vehicles_end, std::back_inserter(filtered), [&predicate](const Vehicle* vehicle_ptr){ return predicate(*vehicle_ptr); });
    return filtered;
}

std::string to_string(std::vector<Vehicle*>::const_iterator vehicles_begin, std::vector<Vehicle*>::const_iterator vehicles_end) {
    std::string vehicle_string;
    //poniewaz przesylamy kontener ze wskaznikami to musimy 2x wyciagnac spod adresu
    for(auto it = vehicles_begin; it != vehicles_end; ++it) {
        const auto& vehicle = *(*it);
        //wykorzystanie poprzedniej funkcji to string zgodnie z pol.
        vehicle_string += to_string(vehicle);
        vehicle_string += "\n";
    }
    return vehicle_string;
}