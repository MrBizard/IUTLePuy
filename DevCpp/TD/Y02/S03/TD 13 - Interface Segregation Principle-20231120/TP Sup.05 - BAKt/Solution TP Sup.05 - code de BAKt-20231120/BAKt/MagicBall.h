#pragma once
#include "ieventlistener.h"
class CMagicBall
  //Solution
  : public IMouseListener
  //Fin Solution
{
protected:
  int m_nRadius;
  int m_nAngle;
  int m_nPosX = 100;
  int m_nPosY = 100;
public:
  CMagicBall(int nRadius);
  void MouseMove(int nPosX, int nPosY);
  int x() const { return m_nPosX; }
  int y() const { return m_nPosY; }
  int radius() const { return m_nRadius; }
  int angle() const { return m_nAngle; }
};

