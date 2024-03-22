#include <iostream>
using namespace std;

class Point
{
public:
    double x, y;
    void info()
    {
        cout << "x: " << x << "y: " << y << endl;
    }
    void getX(double &number)
    {
        number = x;
    }
    void getY(double &number)
    {
        number = y;
    }
    void get(double &numberX, double &numberY)
    {
        numberY = y;
        numberX = x;
    }
};

int main()
{
    double x, y;
    Point p{10.5, 20.99};
    p.info();
    p.get(x, y);
    cout << x << "," << y << endl;
    return 0;
}