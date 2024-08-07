#ifndef SHAPES_HPP_
#define SHAPES_HPP_

#include <vector>

class Shape {
public:
    Shape(double x, double y) : x_(x), y_(y) {}

    virtual double area() const = 0;

    virtual ~Shape() = default;

private:
    double x_;
    double y_;
};

class Square : public Shape {
public:
    Square(double x, double y, double side) : Shape(x, y), side_(side) {}

    double area() const override { return side_ * side_; }

    ~Square() override = default;

private:
    double side_;
};

const double PI = 3.141592;

class Circle : public Shape {
public:
    Circle(double x, double y, double radius) : Shape(x, y), radius_(radius) {}

    double area() const override { return PI * radius_ * radius_; }

    ~Circle() override = default;

private:
    double radius_;
};

//prototyp funkcji zwracajcej sume pol w kolekcji shapes ze wskaznikami do odpowiednich ksztaltow
double calculate_total_area(const std::vector<Shape*>& shapes);

#endif /* SHAPES_HPP_ */
