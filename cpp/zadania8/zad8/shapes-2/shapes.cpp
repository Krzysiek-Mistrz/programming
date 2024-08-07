#include "shapes.hpp"

#include <numeric>

//funkcja wykorzystujaca accumulate do do zsumowania pol pnw mamy kontener wskaznikow to odwolujemy sie do metod poprzez ->
double calculate_total_area(const std::vector<Shape*>& shapes) {
    return std::accumulate(std::begin(shapes), std::end(shapes), 0.0, [](double acc, const auto& shape_ptr) { return acc + shape_ptr -> area(); });
}
