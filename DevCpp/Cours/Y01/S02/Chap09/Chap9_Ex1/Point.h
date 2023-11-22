#pragma once
#include <iostream>

class CPoint
{
public:
  int m_x;
  int m_y;

  CPoint(int x, int y);
};

std::ostream& operator<<(std::ostream& o, const CPoint& pt);

