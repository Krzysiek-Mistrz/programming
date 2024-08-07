#include "catalogue.hpp"
#include <sstream>
#include <iomanip>
#include <algorithm>

std::string to_string(const Product& product) {
    std::ostringstream inscription;
    //tak samo jak z matlab3
    inscription << product.get_name() << " [" << product.get_id() << "] : "
        << std::setprecision(2) << std::fixed << "$" << product.get_price();
    return inscription.str();
}

std::vector<Product> Catalogue::get_products_with_appropriate_price(std::function<bool(double)> critFunction) const {
    std::vector<Product> products;
    for (const auto& elem : inventory_) {
        //odwolujemy sie do drugiego membera naszego inventory czyli mapy
        const auto& product = elem.second;
        //sprawdzamy wywolujac funkcje sprawdzajaca czy mozna dodac do wektora produktow
        if (critFunction(product.get_price())) {
            products.push_back(product);
        }
    }
    return products;
}

std::vector<Product> Catalogue::get_products_by_name_part(std::string substr, bool is_case_sensitive) const {
    std::vector<Product> products;
    for (const auto& elem : inventory_) {
        //drugi member naszej pary = nasz produkt
        const auto& product = elem.second;
        std::string name = product.get_name();
        std::string name_transformed = name;
        std::string chunk_transformed = substr;
        //jezeli nie uwzgledniamy wielkosci liter to dajemy wszystkie na male
        if (!is_case_sensitive) {
            std::transform(name.begin(), name.end(), name_transformed.begin(), ::tolower);
            std::transform(substr.begin(), substr.end(), chunk_transformed.begin(), ::tolower);
        }
        //sprawdzamy czy znaleziono podciag porownujac do wartosci zwroconej gdy nie odnaleziono (npos)
        bool contains_substr = (name_transformed.find(chunk_transformed) != std::string::npos);
        if (contains_substr) {
            products.push_back(product);
        }
    }
    return products;
}
