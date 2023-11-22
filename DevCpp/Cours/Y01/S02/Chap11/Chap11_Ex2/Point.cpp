#include "point.h"

std::ostream& operator<<(std::ostream& o, const CPoint& pt)
{
  return o << "(" << pt.m_x << ", " << pt.m_y << ")";
}
