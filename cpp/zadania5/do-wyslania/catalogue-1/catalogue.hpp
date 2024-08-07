#ifndef CATALOGUE_HPP_
#define CATALOGUE_HPP_

#include <string>
#include <map>
#include <vector>
#include <functional>

class Product {
public:
    Product(std::string id, std::string name, double price) : id_(id), name_(name), price_(price) {}
    std::string get_id() const { return id_; }
    std::string get_name() const { return name_; }
    double get_price() const { return price_; }
private:
    std::string id_;
    std::string name_;
    double price_;
};

class Catalogue {
public:
    //alias typu map<>
    using inventory_t = std::map<std::string, Product>;
    //param konstrukora domyslnie pusta map<> ew przypisujemy do pola wartosc
    Catalogue(const inventory_t& inventory = inventory_t{}) : inventory_(inventory) {}
    //dodaje id i odpowiadajacy produkt
    void add_product(const Product& product) { inventory_.emplace(product.get_id(), product); }
    //zwraca iterator na map::end gdy nie znajdzie z doku
    bool contains(std::string id) const { return (inventory_.find(id) != inventory_.end()); }
    //przekazujemy funkcje do funkcji jako funktor
    std::vector<Product> get_products_with_appropriate_price(std::function<bool(double)> critFunction) const;
    std::vector<Product> get_products_by_name_part(std::string substr, bool is_case_sensitive = false) const;
private:
    inventory_t inventory_;
};

std::string to_string(const Product& product);

#endif //CATALOGUE_HPP_