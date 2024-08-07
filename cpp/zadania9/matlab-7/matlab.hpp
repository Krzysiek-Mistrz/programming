#ifndef INCLUDE_MATLAB_HPP_
#define INCLUDE_MATLAB_HPP_

#include <cstddef>
#include <vector>
#include <string>

namespace Matlab {
    class Vector {
    public:
        Vector(std::size_t n = 3) : v_(n, 0) {}
        Vector(const Vector&) = default;
        Vector(const std::vector<int>& v) : v_(v) {}
        Vector(std::string str);
        const int& operator[](std::size_t pos) const { return v_[pos]; }
        int& operator[](std::size_t pos) { return v_[pos]; }
        std::vector<int>::const_iterator cbegin() const { return v_.cbegin(); }
        std::vector<int>::const_iterator cend() const { return v_.cend(); }
        std::vector<int>::iterator begin() { return v_.begin(); }
        std::vector<int>::const_iterator begin() const { return v_.cbegin(); }
        std::vector<int>::iterator end() { return v_.end(); }
        std::vector<int>::const_iterator end() const { return v_.cend(); }
        std::size_t size() const { return v_.size(); }
        double norm() const;
        int sum() const;
    private:
        std::vector<int> v_;
    };

    Vector add_vectors(const Vector& v1, const Vector& v2);

    std::string to_string(const Vector& v);

    class Matrix {
    public:
        Matrix(std::size_t n_rows, std::size_t n_cols) :
                matrix_(n_rows, Vector(n_cols)) {}
        Matrix(const Matrix&) = default;
        Matrix(const std::vector<std::vector<int>>& m);
        std::size_t size() const { return matrix_.size(); }
        int sum() const;
        const Vector& operator[](std::size_t pos) const { return matrix_[pos]; }
        Vector& operator[](std::size_t pos) { return matrix_[pos]; }
        std::vector<Vector>::const_iterator cbegin() const { return matrix_.cbegin(); }
        std::vector<Vector>::const_iterator cend() const { return matrix_.cend(); }
        std::vector<Vector>::iterator begin() { return matrix_.begin(); }
        std::vector<Vector>::const_iterator begin() const { return matrix_.cbegin(); }
        std::vector<Vector>::iterator end() { return matrix_.end(); }
        std::vector<Vector>::const_iterator end() const { return matrix_.cend(); }
    private:
        std::vector<Vector> matrix_;
    };

    Matrix add_matrices(const Matrix& m1, const Matrix& m2);

    std::string to_string(const Matrix& m);

    //wdg tresci z zadania
    std::string was_exception_raised_when_adding_vectors(const Vector& v1, const Vector& v2);
}
#endif /* INCLUDE_MATLAB_HPP_ */
