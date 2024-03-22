#include "Circle.h"
#include <iostream>
#include <cmath>

Circle::Circle() : center(), radius(0.0) {}

Circle::Circle(const Point &p, double r) : center(p), radius(r) {}

Circle::Circle(double x, double y, double r) : center(x, y), radius(r) {}

Circle::~Circle()
{
    std::cout << "Destruction of a class instance " << std::endl;
    info();
    std::cout << std::endl;
}

void Circle::info() const
{
    std::cout << "Center: ";
    center.info();
    std::cout << ", Radius: " << radius;
}

double Circle::area()
{
    return M_PI * radius * radius;
}

const Point &Circle::centerPoint() const
{
    return center;
}

double Circle::getRadius() const
{
    return radius;
}

bool Circle::isInside(const Point &p) const
{

    double dx = p.getx() - center.getx();
    double dy = p.gety() - center.gety();
    double distance = sqrt(dx * dx + dy * dy);
    return distance <= radius;
}
