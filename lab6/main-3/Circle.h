#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"

class Circle
{
private:
    Point center;
    double radius;

public:
    Circle();
    Circle(const Point &p, double r);
    Circle(double x, double y, double r);
    ~Circle();
    void info() const;
    double area();
    const Point &centerPoint() const;
    double getRadius() const;
    bool isInside(const Point &p) const;
};

#endif // CIRCLE_H
