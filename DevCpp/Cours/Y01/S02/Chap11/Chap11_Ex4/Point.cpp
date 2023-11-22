#include "point.h"

std::ostream& operator<<(std::ostream& o, const CPoint& pt)
{
  return o << "(" << pt.m_x << ", " << pt.m_y << ")";
}

std::istream& operator>>(std::istream& in, CPoint& pt)
{
  return in >> pt.m_x >> pt.m_y;
}
