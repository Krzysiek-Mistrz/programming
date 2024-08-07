#ifndef VEHICLES_HPP_
#define VEHICLES_HPP_

#include <string>
#include <vector>
#include <functional>

//klasa abstrakcyjna Vehicle
class Vehicle {
    std::string id_;
    std::string brand_;
public:
    //konstruktor z lista inicj.
    Vehicle(std::string id, std::string brand) : id_(id), brand_(brand) {}
    //gettery
    std::string get_id() const { return id_; }
    std::string get_brand() const { return brand_; }
    virtual double get_max_speed() const = 0;
    //zgodnie z norma definiujemy wirtualny destruktor dla klasy abstrakcyjnej
    virtual ~Vehicle() {};
};

class Car : public Vehicle {
    double engine_hp_;
public:
    //konstruktor
    Car(std::string id, std::string brand, double engine_hp) : Vehicle(id, brand), engine_hp_(engine_hp) {}
    //override metody wirtualnej get max speed
    double get_max_speed() const override { return engine_hp_; }
};

class Bicycle : public Vehicle {
    int n_gears_;
public:
    //konstruktor
    Bicycle(std::string id, std::string brand, int n_gears) : Vehicle(id, brand), n_gears_(n_gears) {}
    //tez override metody wirtulanej wdg polecenia cwiczenia
    double get_max_speed() const override { return n_gears_ * 3; }
};

//funkcje do napisania ;) (w pliku zrodlowym implem.)
std::string to_string(const Vehicle& vehicle);
double compute_min_travel_duration(double distance, const Vehicle& vehicle);
std::string compute_min_travel_duration_as_string(double distance, const Vehicle& vehicle);

//funkcja do filtrowania
std::vector<Vehicle*> filter_vehicles(
        std::vector<Vehicle*>::const_iterator vehicles_begin,
        std::vector<Vehicle*>::const_iterator vehicles_end,
        std::function<bool(const Vehicle&)> predicate);
//funkcja do zwracania reprezentacji zakresu elem
std::string to_string(std::vector<Vehicle*>::const_iterator vehicles_begin,
                      std::vector<Vehicle*>::const_iterator vehicles_end);
#endif /* VEHICLES_HPP_ */
