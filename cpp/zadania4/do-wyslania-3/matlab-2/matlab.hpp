#ifndef MATLAB_HPP_
#define MATLAB_HPP_

#include <cstddef>
#include <vector>

class MatVect {
private:
    std::vector<int> v_;
public:
    MatVect(std::size_t n);
    //tak krotkie ze mozna dac do naglowkowego
    void set_elem(std::size_t pos, int val) {
        v_[pos] = val;
    }
    std::size_t size() {
        return v_.size();
    }
    float norm();
    int get_elem(std::size_t pos) {
        return v_[pos];
    }
};

void print_vector(MatVect v);

MatVect add_vectors(MatVect v1, MatVect v2);

#endif
