#ifndef INCLUDE_MATLAB_HPP_
#define INCLUDE_MATLAB_HPP_

#include <cstddef>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <numeric>

namespace Matlab {
    template<typename T>
    class Vector {
    public:
        Vector(std::size_t n = 3) : v_(n, 0) {}
        Vector(const Vector<T>&) = default;
        Vector(const std::vector<T>& v) : v_(v) {}
        Vector(std::string str);  // EXT
        const int& operator[](std::size_t pos) const { return v_[pos]; }
        int& operator[](std::size_t pos) { return v_[pos]; }
        typename std::vector<T>::const_iterator cbegin() const { return v_.cbegin(); }
        typename std::vector<T>::const_iterator cend() const { return v_.cend(); }
        typename std::vector<T>::iterator begin() { return v_.begin(); }
        typename std::vector<T>::const_iterator begin() const { return v_.cbegin(); }
        typename std::vector<T>::iterator end() { return v_.end(); }
        typename std::vector<T>::const_iterator end() const { return v_.cend(); }
        std::size_t size() const { return v_.size(); }
        double norm() const;
        int sum() const;
    private:
        std::vector<T> v_;
    };

    template<typename T>
    Vector<T> add_vectors(const Vector<T>& v1, const Vector<T>& v2);

    template<typename T>
    std::string to_string(const Vector<T>& v);

    template<typename T>
    class Matrix {
    public:
        Matrix(std::size_t n_rows, std::size_t n_cols) :
                matrix_(n_rows, Vector<T>(n_cols)) {}
        Matrix(const Matrix<T>&) = default;
        Matrix(const std::vector<std::vector<int>>& m);
        std::size_t size() const { return matrix_.size(); }
        int sum() const;
        const Vector<T>& operator[](std::size_t pos) const { return matrix_[pos]; }
        Vector<T>& operator[](std::size_t pos) { return matrix_[pos]; }
        typename std::vector<Vector<T>>::const_iterator cbegin() const { return matrix_.cbegin(); }
        typename std::vector<Vector<T>>::const_iterator cend() const { return matrix_.cend(); }
        typename std::vector<Vector<T>>::iterator begin() { return matrix_.begin(); }
        typename std::vector<Vector<T>>::const_iterator begin() const { return matrix_.cbegin(); }
        typename std::vector<Vector<T>>::iterator end() { return matrix_.end(); }
        typename std::vector<Vector<T>>::const_iterator end() const { return matrix_.cend(); }
    private:
        typename std::vector<Vector<T>> matrix_;
    };

    template<typename T>
    Matrix<T> add_matrices(const Matrix<T>& m1, const Matrix<T>& m2);

    template<typename T>
    std::string to_string(const Matrix<T>& m);

    template<typename T>
    std::string was_exception_raised_when_adding_vectors(const Vector<T>& v1, const Vector<T>& v2);
}

template<typename T>
Matlab::Vector<T>::Vector(std::string str) {
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

template<typename T>
double Matlab::Vector<T>::norm() const {
    return sqrt( std::accumulate(std::begin(v_), std::end(v_), 0.0, [](auto acc, auto elem) { return acc + elem * elem; }));
}

template<typename T>
int Matlab::Vector<T>::sum() const {
    return std::accumulate(std::begin(v_), std::end(v_), 0);
}

template<typename T>
Matlab::Vector<T> Matlab::add_vectors(const Matlab::Vector<T>& v1, const Matlab::Vector<T>& v2) {
    if (v1.size() != v2.size()) {
        throw std::invalid_argument("Vectors have unequal size (" + std::to_string(v1.size()) + " and " + std::to_string(v2.size()) + ")");
    }
    Matlab::Vector<T> v_sum(v1.size());
    std::transform(v1.cbegin(), v1.cend(), v2.cbegin(), v_sum.begin(), std::plus<>());
    return v_sum;
}

template<typename T>
std::string Matlab::to_string(const Matlab::Vector<T>& v) {
    std::ostringstream oss;
    oss << "[";
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        oss << " " << *it << ((it != v.cend() - 1) ? "," : " ");
    }
    oss << "]";
    return oss.str();
}

template<typename T>
Matlab::Matrix<T>::Matrix(const std::vector<std::vector<int>>& m) {
    std::copy(m.begin(), m.end(), std::back_inserter(matrix_));
}

template<typename T>
int Matlab::Matrix<T>::sum() const {
    return std::accumulate(matrix_.begin(), matrix_.end(), 0, [](int acc, const auto& v) { return acc + v.sum(); });
}

template<typename T>
Matlab::Matrix<T> Matlab::add_matrices(const Matlab::Matrix<T>& m1, const Matlab::Matrix<T>& m2) {
    Matlab::Matrix<T> m_sum(m1);
    std::transform(m1.begin(), m1.end(), m2.begin(), m_sum.begin(), add_vectors<T>);
    return m_sum;
}

template<typename T>
std::string Matlab::to_string(const Matlab::Matrix<T>& m) {
    std::ostringstream oss;
    oss << "[" << "\n";
    for (auto it = m.cbegin(); it != m.cend(); ++it) {
        oss << "  " << Matlab::to_string(*it) << ((it != m.cend() - 1) ? "," : "") << "\n";
    }
    oss << "]";
    return oss.str();
}

template<typename T>
std::string Matlab::was_exception_raised_when_adding_vectors(const Matlab::Vector<T>& v1, const Matlab::Vector<T>& v2) {
    try {
        auto v_sum = Matlab::add_vectors(v1, v2);
    } catch (const std::invalid_argument& ia) {
        return ia.what();
    }
    return "";
}

#endif /* INCLUDE_MATLAB_HPP_ */
