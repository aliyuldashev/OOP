#include <iostream>
using namespace std;

class Triangle
{
private:
    double base, height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    ~Triangle()
    {
        cout << "Base: " << base << ", Height: " << height << endl;
    }

    double getBase()
    {
        return base;
    }

    double getHeight()
    {
        return height;
    }

    double area()
    {
        return 0.5 * base * height;
    }
};

int main()
{
    Triangle t1{10.5, 4.5};
    Triangle t2{7.0, 3.0};

    cout << "Triangle t1 {10.5, 4.5}" << endl;
    cout << "base: " << t1.getBase() << endl;
    cout << "height: " << t1.getHeight() << endl;
    cout << "area: " << t1.area() << endl
         << endl;

    cout << "Triangle t2 {7.0, 3.0}" << endl;
    cout << "base: " << t2.getBase() << endl;
    cout << "height: " << t2.getHeight() << endl;
    cout << "area: " << t2.area() << endl
         << endl;

    return 0;
}
