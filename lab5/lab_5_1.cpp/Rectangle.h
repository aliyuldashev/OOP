#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "Point.h"

class Rectangle
{
public:
    Point m_upLeft;
    Point m_lowRight;

public:
    bool InitMembers();
    void ShowRecInfo() const;
    bool IsInside(Point pos3);
};

#endif // __RECTANGLE_H__
