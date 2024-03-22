#include "Point.h"
#include <iostream>
#include <cmath>

Point::Point() : x(0.0), y(0.0) {}

Point::Point(double xVal, double yVal) : x(xVal), y(yVal) {}

void Point::setValues(double xVal, double yVal)
{
    x = xVal;
    y = yVal;
}

void Point::info() const
{
    std::cout << "x: " << x << " y: " << y;
}

void Point::getX(double &number) const
{
    number = x;
}

void Point::getY(double &number) const
{
    number = y;
}
double Point::getx() const
{
    return x;
}

double Point::gety() const
{
    return y;
}
