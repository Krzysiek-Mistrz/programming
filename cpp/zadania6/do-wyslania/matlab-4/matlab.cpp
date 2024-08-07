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
    inscription << "[";
    std::size_t counter = 1;
    for (const auto& elem : v1) {
        inscription << " " << elem;
        if (counter < v1.size()) {
            inscription << ",";
        }
        counter++;
    }
    inscription << " ]";
    return inscription.str();
}

double MatVect::norm() {
    // double sum_of_squares = 0.0;
    // for (auto elem : v_)   //zastosowanie cbegin i cend -> iteratory
    //     sum_of_squares += elem * elem;
    // return sqrt(sum_of_squares);
    //zrefaktoryzowany kod:
    double sum = std::accumulate(std::begin(v_), std::end(v_), 0.0, [](auto acc, auto elem){ return acc + pow(elem, 2); });
    double norm = sqrt(sum);
    return norm;
}

MatVect add_vectors(const MatVect& v1, const MatVect& v2) {
    MatVect v_sum(v1.size());
    std::transform(v1.cbegin(), v1.cend(), v2.cbegin(), v_sum.begin(), std::plus<>());
    // for (std::size_t i = 0; i < v1.size(); i++) {
    //     v_sum.set_elem(i, v1.get_elem(i) + v2.get_elem(i));
    // }
    return v_sum;
}

//kopiujemy wektor od poczatku do konca i wstawiamy przez push back do matrix_
Matrix::Matrix(const std::vector<std::vector<int>>& m) {
    std::copy(m.begin(), m.end(), std::back_inserter(matrix_));
}

//ilosc wierszy = size macierzy i ilosc kolumn = size wektorow wewnatrz
Matrix add_matrices(const Matrix& m1, const Matrix m2) {
    std::size_t rows = m1.size();
    std::size_t cols = m1[0].size();
    Matrix sum(rows, cols);
    //zamiast tego mozna by tez std::transform uzyc :)
    for(std::size_t i = 0; i < m2.size(); i++) {
        sum[i] = add_vectors(m1[i], m2[i]);
    }
    return sum;
}

std::string to_string(const Matrix& m) {
    std::ostringstream oss;
    oss << "[" << "/n";
    std::size_t counter = 1;
    for(const auto& row : m) {
        oss << "  " << to_string(row);
        if(counter != m.size())
            oss << ",";
        else
            oss << "\n";
    }
    oss << "]";
    return oss.str();
}

int MatVect::sum() const {
    //uzywamy zgodnie z dokumentacja z offsetem / initem 0.
    return std::accumulate(std::begin(v_), std::end(v_), 0);
}

int Matrix::sum() const {
    return std::accumulate(matrix_.begin(), matrix_.end(), 0, [](int acc, const auto& v){ return acc + v.sum(); });
}

// void print_vector(const MatVect& v) {
//     for(const auto& elem : v) {    //zastosowanie cbegin i cend -> iteratory
//         std::cout << elem << " ";
//     }
//     std::cout << std::endl;
// }

