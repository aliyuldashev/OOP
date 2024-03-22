#include <iostream>
#include "Circle.h"

using namespace std;

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

    cout << "Area of c3: " << c3.area() << endl;
    const Point &cent = c3.centerPoint();
    cout << "Center of c3: [" << cent.getx() << "," << cent.gety() << "]" << endl;
    cout << "Radius of c3: " << c3.getRadius() << endl;
    cout << "Is Inside: " << c4.isInside(Point{25.0, 8.0}) << endl
         << endl;

    return 0;
}
