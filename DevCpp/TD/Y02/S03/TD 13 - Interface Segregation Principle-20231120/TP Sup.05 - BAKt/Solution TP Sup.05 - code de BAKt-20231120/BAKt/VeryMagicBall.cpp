#include "VeryMagicBall.h"
#define _USE_MATH_DEFINES
#include <math.h>

CVeryMagicBall::CVeryMagicBall(int nRadius)
  : CMagicBall(nRadius)
{
}

void CVeryMagicBall::MouseDown(CMouseEvent::Button button)
{
  if(button == CMouseEvent::Button::Left)
    m_nRadius += 10;
  if(button == CMouseEvent::Button::Right)
    m_nRadius -= 10;
}

void CVeryMagicBall::Tick()
{
  m_nAngle = (m_nAngle + 1) % 360;
}