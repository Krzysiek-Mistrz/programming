#ifndef INCLUDE_MATLAB_HPP_
#define INCLUDE_MATLAB_HPP_

// Biblioteka <cstddef> zawiera definicję typu `std::size_t`.
#include <cstddef>

int* add_vectors(int* v1, int* v2, std::size_t n);

void print_vector(int* v, std::size_t n);

#endif /* INCLUDE_MATLAB_HPP_ */
