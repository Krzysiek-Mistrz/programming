#include "matlab.hpp"
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <numeric>

MatVect::MatVect(std::string str) {
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

double MatVect::norm() const {
    return sqrt(
            std::accumulate(std::begin(v_), std::end(v_), 0.0,
                    [](auto acc, auto elem) { return acc + elem * elem; }));
}

int MatVect::sum() const {
    return std::accumulate(std::begin(v_), std::end(v_), 0);
}

MatVect add_vectors(const MatVect& v1, const MatVect& v2) {
    MatVect v_sum(v1.size());
    std::transform(v1.cbegin(), v1.cend(), v2.cbegin(), v_sum.begin(), std::plus<>());
    return v_sum;
}

std::string to_string(const MatVect& v) {
    std::ostringstream oss;
    oss << "[";
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        oss << " " << *it << ((it != v.cend() - 1) ? "," : " ");
    }
    oss << "]";
    return oss.str();
}

Matrix::Matrix(const std::vector<std::vector<int>>& m) {
    std::copy(m.begin(), m.end(), std::back_inserter(matrix_));
}

int Matrix::sum() const {
    return std::accumulate(matrix_.begin(), matrix_.end(), 0,
                           [](int acc, const auto& v) {
                               return acc + v.sum();
                           });
}

Matrix add_matrices(const Matrix& m1, const Matrix& m2) {
    //tworzymy kopie jednego z obiektow i zapisujemy do niego sume
    Matrix m_sum(m1);
    std::transform(m1.begin(), m1.end(), m2.begin(), m_sum.begin(), add_vectors);
    return m_sum;
}

std::string to_string(const Matrix& m) {
    std::ostringstream oss;
    oss << "[" << "\n";
    for (auto it = m.cbegin(); it != m.cend(); ++it) {
        oss << "  " << to_string(*it) << ((it != m.cend() - 1) ? "," : "") << "\n";
    }
    oss << "]";
    return oss.str();
}
