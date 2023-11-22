#include "point.h"
#include <iostream>

CPoint::CPoint(int x, int y)
  : m_x(x)
  , m_y(y)
{
  std::cout << "Construction d'un point de coordonnées " << *this << '\n';
}

std::ostream& operator<<(std::ostream& o, const CPoint& pt)
{
  return o << "(" << pt.m_x << ", " << pt.m_y << ")";
}
