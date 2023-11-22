#ifndef POINT_H
#define POINT_H

#include <iostream>

class CPoint
{
public:
  int m_x;
  int m_y;

  CPoint(int x=0, int y=0)
    : m_x{ x }, m_y{ y }{}
};

std::ostream& operator<<(std::ostream& o, const CPoint& pt);
std::istream& operator>>(std::istream& in, CPoint& pt);

#endif //POINT_H