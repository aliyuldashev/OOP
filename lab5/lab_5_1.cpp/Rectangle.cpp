#include <iostream>
#include "Rectangle.h"
#include "Point.h"
using namespace std;

bool Rectangle::InitMembers()
{
    Point pos1, pos2;
    pos1.InitMembers(2, 4);
    pos2.InitMembers(5, 9);
    m_upLeft = pos1;
    m_lowRight = pos2;
    return true;
}

void Rectangle::ShowRecInfo() const
{
    cout << "LeftTop:" << '[' << m_upLeft.GetX() << ",";
    cout << m_upLeft.GetY() << ']' << endl;
    cout << "RightBottom:" << '[' << m_lowRight.GetX() << ",";
    cout << m_lowRight.GetY() << ']' << endl
         << endl;
}
bool Rectangle::IsInside(Point pos3)
{
    int x = pos3.GetX();
    int y = pos3.GetY();
    if (x > m_upLeft.GetX() & x<m_lowRight.GetX() & y> m_upLeft.GetY() & y < m_lowRight.GetY())
    {
        return true;
    }
    return false;
}