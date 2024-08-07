#ifndef INCLUDE_MATLAB_HPP_
#define INCLUDE_MATLAB_HPP_

#include <cstddef>
#include <vector>
#include <string>

class MatVect {
public:
    //inicjalizujemy kontenerem
    MatVect(const std::vector<int>& v) : v_(v) {}
    //fill constructor
    MatVect(std::size_t n) : v_(n, 0) {}
    //przeciazenie operatorow kolejno inspector i mutator
    const int& operator[](std::size_t pos) const { return v_[pos]; }
    int& operator[](std::size_t pos) { return v_[pos]; }
    //const iteratory
    std::vector<int>::const_iterator cbegin() const { return v_.cbegin(); }
    std::vector<int>::const_iterator cend() const { return v_.cend(); }
    //normalne iteratory
    std::vector<int>::iterator begin() { return v_.begin(); }
    std::vector<int>::const_iterator begin() const { return v_.cbegin(); }
    std::vector<int>::iterator end() { return v_.end(); }
    std::vector<int>::const_iterator end() const { return v_.cend(); }
    //w sumie to niepotrzebne funkcje za wyjatkiem norm() :P
    // int get_elem(std::size_t pos) const { return v_[pos]; }
    // void set_elem(std::size_t pos, int val) { v_[pos] = val; }
    std::size_t size() const { return v_.size(); }
    double norm();
    //funkcja sumujaca dla wektora
    int sum() const;
private:
    std::vector<int> v_;
};

class Matrix {
    std::vector<MatVect> matrix_;
public:
    Matrix(std::size_t n_rows, std::size_t n_cols) : matrix_(n_rows, MatVect(n_cols)) {}
    Matrix(const std::vector<std::vector<int>>& m);
    //poniewaz matrix tak naprawde jest wektorem skladajacym sie z innych wektorow to normalnie metoda size() tu wchodzi ;)
    std::size_t size() const { return matrix_.size(); }
    //przeciazenie operatorow dla MatVect w sumie analogicznie do poprz. bo tez jest zasadniczo "wektorem" (nieformalnnie matematycznie, tak jak pisalem wczesniej) i zwracamy obiekt klasy MatVect :)
    const MatVect& operator[] (std::size_t pos) const  { return matrix_[pos]; }
    MatVect& operator[] (std::size_t pos) { return matrix_[pos]; }
    //zwracamy iteratory zwykle lub na stale obiekty w zaleznosci od tego co mamy w danej chwili
    //najpierw przeciazamy cbegin i cend
    std::vector<MatVect>::const_iterator cbegin() const { return matrix_.cbegin(); }
    std::vector<MatVect>::const_iterator cend() const { return matrix_.cend(); }
    //pozniej zarowno dla begin zwracajacej zwykly iterator jak i const iterator
    std::vector<MatVect>::iterator begin() { return matrix_.begin(); }
    std::vector<MatVect>::const_iterator begin() const { return matrix_.cbegin(); }
    //podobnie dla end zwracamy const iterator i zwyczajy iterator tez
    std::vector<MatVect>::const_iterator end() { return matrix_.end(); }
    std::vector<MatVect>::const_iterator end() const { return matrix_.cend(); }
    //funkcja sumujaca dla macierzy
    int sum() const;
};
//dodawanie macierzy i zamiana na postac lancucha
Matrix add_matrices(const Matrix& m1, const Matrix& m2);
std::string to_string(const Matrix& m1);
//dodawanie wektorow i zamiana na postac lancucha
MatVect add_vectors(const MatVect& v1, const MatVect& v2);
std::string to_string(const MatVect& v1);

//void print_vector(const MatVect& v);

#endif /* INCLUDE_MATLAB_HPP_ */
