#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:
    double x, y;

public:
    Point() : x(0.0), y(0.0) {}

    Point(double xVal, double yVal) : x(xVal), y(yVal) {}

    void setValues(double xVal, double yVal)
    {
        x = xVal;
        y = yVal;
    }

    void info() const
    {
        cout << "x: " << x << " y: " << y;
    }
};


class Circle
{
private:
    Point center;
    double radius;

public:
    Circle() : center(), radius(0.0) {}

    Circle(const Point &p, double r) : center(p), radius(r) {}

    Circle(double x, double y, double r) : center(x, y), radius(r) {}

    ~Circle()
    {
        cout << "Destruction of a class instance " << endl;
        info();
        cout << endl;
    }

    void info() const
    {
        cout << "Center: ";
        center.info();
        cout << ", Radius: " << radius;
    }
};

int main()
{
    Circle c1;
    Circle c2{};
    Point p{10.5, 20.5};
    Circle c3{p, 20.0};
    Circle c4{20.5, 10.5, 10.0};

    cout << "c1.info:";
    c1.info();
    cout << endl;
    cout << "c2.info:";
    c2.info();
    cout << endl;
    cout << "c3.info:";
    c3.info();
    cout << endl;
    cout << "c4.info:";
    c4.info();
    cout << endl;

    return 0;
}
