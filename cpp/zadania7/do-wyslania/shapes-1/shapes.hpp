#ifndef SHAPES_HPP_
#define SHAPES_HPP_

const double PI = 3.141592;

class Shape {
    double x_;
    double y_;
public:
    Shape(double x, double y) : x_(x), y_(y) {}
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Square : public Shape {
    double side_;
public:
    Square(double x, double y, double side) : Shape(x, y), side_(side) {}
    double area() const override { return side_ * side_; }
    ~Square() override = default;
};

class Circle : public Shape {
    double radius_;
public:
    Circle(double x, double y, double radius) : Shape(x, y), radius_(radius) {}
    double area() const override { return PI * radius_ * radius_; }
    ~Circle() override = default;
};

#endif /* SHAPES_HPP_ */
