#ifndef COMPLEX_HPP_
#define COMPLEX_HPP_

class Complex {
    double re_;
    double im_;
public:
    Complex(double re, double im) : re_(re), im_(im) {}
    Complex(double* data) : Complex(*data, *(data + 1)) {}
    double re() const { return re_; }
    double im() const { return im_; }
};

#endif //COMPLEX_HPP_