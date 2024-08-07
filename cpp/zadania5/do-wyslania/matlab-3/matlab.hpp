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
private:
    std::vector<int> v_;
};

std::string to_string(const MatVect& v1);
MatVect add_vectors(const MatVect& v1, const MatVect& v2);
void print_vector(const MatVect& v);

#endif /* INCLUDE_MATLAB_HPP_ */
