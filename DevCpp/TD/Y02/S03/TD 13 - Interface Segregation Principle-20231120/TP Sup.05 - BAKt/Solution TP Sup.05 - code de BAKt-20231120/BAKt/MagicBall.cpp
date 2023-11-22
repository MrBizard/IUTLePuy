#include "MagicBall.h"
#include <cstdlib>

CMagicBall::CMagicBall(int nRadius)
  : m_nRadius(nRadius)
  , m_nAngle(std::rand() % 360)
{
}

void CMagicBall::MouseMove(int nPosX, int nPosY)
{
  m_nAngle++;
  if(m_nAngle==360)
    m_nAngle = 0;

  m_nPosX = nPosX;
  m_nPosY = nPosY;
}