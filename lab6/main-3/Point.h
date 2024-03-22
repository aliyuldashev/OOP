#ifndef POINT_H
#define POINT_H

class Point
{
private:
    double x, y;

public:
    Point();
    Point(double xVal, double yVal);
    void setValues(double xVal, double yVal);
    void info() const;
    void getX(double &number) const;
    void getY(double &number) const;
    double getx() const;
    double gety() const;
};

#endif // POINT_H
