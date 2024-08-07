#include <cstdlib>
#include <cmath>
#include <iostream>
#include "matlab.hpp"

float MatVect::norm() {
    float sum = 0;
    for (std::size_t i = 0; i < v_.size(); i++)
        sum += (float)pow(v_[i], 2);
    return (float)sqrt(sum);
}

MatVect::MatVect(std::size_t n) {
    for (std::size_t i = 0; i < n; i++)
        v_.push_back(0);
}

void print_vector(MatVect v) {
    for (std::size_t i = 0; i < v.size(); i++) {
        //musze za pomoca get_elem bo pole prywatne heh
        std::cout << v.get_elem(i) << std::endl;
    }
}

MatVect add_vectors(MatVect v1, MatVect v2) {
    std::size_t vectSize = v1.size();
    MatVect vFinal(vectSize);
    for (std::size_t i = 0; i < vectSize; i++) {
        //ustawiam przez set_elem publiczna metode odwolujaca sie do priv pola
        vFinal.set_elem(i, v1.get_elem(i) + v2.get_elem(i)); 
    }
    return vFinal;
}