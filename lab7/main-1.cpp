#include <iostream>
using namespace std;

class Rectangle
{
public:
    int width, height;
    Rectangle() : width(0), height(0) {}
    void Display()
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                cout << " * ";
            }
            cout << endl;
        }
    }
    Rectangle &setWidth(int nwidth)
    {
        width = nwidth;
        return *this;
    }
    Rectangle &setHight(int nhight)
    {
        height = nhight;
        return *this;
    }
};
int main()
{
    Rectangle rect;
    rect.Display();
    rect.setWidth(5).setHight(5).Display();
    return 0;
}