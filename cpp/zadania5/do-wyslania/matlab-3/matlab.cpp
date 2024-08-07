#include "matlab.hpp"
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>

std::string to_string(const MatVect& v1) {
    std::ostringstream inscription;
    for(const auto& elem : v1) {    //zastosowanie cbegin i cend -> iteratory
        inscription << elem << " ";
    }
    return inscription.str();
}

double MatVect::norm() {
    double sum_of_squares = 0.0;
    for (auto elem : v_)   //zastosowanie cbegin i cend -> iteratory
        sum_of_squares += elem * elem;
    return sqrt(sum_of_squares);
}

MatVect add_vectors(const MatVect& v1, const MatVect& v2) {
    MatVect v_sum(v1.size());
    std::transform(v1.cbegin(), v1.cend(), v2.cbegin(), v_sum.begin(), std::plus<>());
    // for (std::size_t i = 0; i < v1.size(); i++) {
    //     v_sum.set_elem(i, v1.get_elem(i) + v2.get_elem(i));
    // }
    return v_sum;
}

//w sumie tez nie potrzebne ale zostawilem bo w poleceniu nie bylo zeby usuwac :)
void print_vector(const MatVect& v) {
    for(const auto& elem : v) {    //zastosowanie cbegin i cend -> iteratory
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

