#include "matlab.hpp"
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <numeric>

Matlab::Vector::Vector(std::string str) {
    std::istringstream iss(str);
    std::vector<int> elements;
    int elem;
    while (iss) {
        if (!isdigit(iss.peek())) {
            iss.get();
        } else {
            iss >> elem;
            elements.push_back(elem);
        }
    }
    v_ = elements;
}

double Matlab::Vector::norm() const {
    return sqrt(
            std::accumulate(std::begin(v_), std::end(v_), 0.0,
                            [](auto acc, auto elem) { return acc + elem * elem; }));
}

int Matlab::Vector::sum() const {
    return std::accumulate(std::begin(v_), std::end(v_), 0);
}

Matlab::Vector Matlab::add_vectors(const Matlab::Vector& v1, const Matlab::Vector& v2) {
    //jezeli rozmiary sa rozne rzyuc wyjatkiem
    if(v1.size() != v2.size()) {
        throw std::invalid_argument("Vectors have unequal size (" + std::to_string(v1.size()) + " and " + std::to_string(v2.size()) + ")");
    }
    Matlab::Vector v_sum(v1.size());
    std::transform(v1.cbegin(), v1.cend(), v2.cbegin(), v_sum.begin(), std::plus<>());
    return v_sum;
}

std::string Matlab::to_string(const Matlab::Vector& v) {
    std::ostringstream oss;
    oss << "[";
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        oss << " " << *it << ((it != v.cend() - 1) ? "," : " ");
    }
    oss << "]";
    return oss.str();
}

Matlab::Matrix::Matrix(const std::vector<std::vector<int>>& m) {
    std::copy(m.begin(), m.end(), std::back_inserter(matrix_));
}

int Matlab::Matrix::sum() const {
    return std::accumulate(matrix_.begin(), matrix_.end(), 0,
                           [](int acc, const auto& v) {
                               return acc + v.sum();
                           });
}

Matlab::Matrix Matlab::add_matrices(const Matlab::Matrix& m1, const Matlab::Matrix& m2) {
    Matlab::Matrix m_sum(m1);
    std::transform(m1.begin(), m1.end(), m2.begin(), m_sum.begin(), add_vectors);
    return m_sum;
}

std::string Matlab::to_string(const Matlab::Matrix& m) {
    std::ostringstream oss;
    oss << "[" << "\n";
    for (auto it = m.cbegin(); it != m.cend(); ++it) {
        oss << "  " << Matlab::to_string(*it) << ((it != m.cend() - 1) ? "," : "") << "\n";
    }
    oss << "]";
    return oss.str();
}

std::string Matlab::was_exception_raised_when_adding_vectors(const Matlab::Vector& v1, const Matlab::Vector& v2) {
    //jezeli wyjatek rzuci to zlap go w catch i wypisz 'opis
    try {
        auto v_sum = Matlab::add_vectors(v1, v2);
    } catch (const std::invalid_argument& error) {
        return error.what();
    }
    return "";
}