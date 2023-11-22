#include "PifPaf.h"
#define _USE_MATH_DEFINES
#include <math.h>

CPifPaf::CPifPaf(void)
  : m_nMousePosX(0)
  , m_nMousePosY(0)
  , m_nPosX(0)
  , m_nPosY(0)
  , m_nWidth(0)
  , m_nHeight(0)
  , m_bLeftDirection(true)
  , cm_dLeftEyeXRatio(0.373)
  , cm_dRightEyeXRatio(0.628)
  , cm_dEyeYRatio(0.384)
  , cm_dEyeYRadiusRatio(0.04)
{
}


void CPifPaf::setPos(int x, int y)
{
  m_nPosX = x;
  m_nPosY = y;
  computeLook();
}

void CPifPaf::setSize(int width, int height)
{
  m_nWidth = width;
  m_nHeight = height;
  computeLook();
}

void CPifPaf::computeLook()
{
  double dNorme;

  m_dLeftEyeCenterX = m_nPosX + cm_dLeftEyeXRatio*m_nWidth;
  m_dEyeCenterY = m_nPosY + cm_dEyeYRatio*m_nHeight;
  m_dLeftEyeDirX = m_nMousePosX - m_dLeftEyeCenterX;
  m_dLeftEyeDirY = m_nMousePosY - m_dEyeCenterY;
  dNorme = sqrt(m_dLeftEyeDirX*m_dLeftEyeDirX+m_dLeftEyeDirY*m_dLeftEyeDirY);
  m_dLeftEyeDirX /= dNorme;
  m_dLeftEyeDirY /= dNorme;

  m_dRightEyeCenterX = m_nPosX + cm_dRightEyeXRatio*m_nWidth;
  m_dRightEyeDirX = m_nMousePosX - m_dRightEyeCenterX;
  m_dRightEyeDirY = m_nMousePosY - m_dEyeCenterY;
  dNorme = sqrt(m_dRightEyeDirX*m_dRightEyeDirX+m_dRightEyeDirY*m_dRightEyeDirY);
  m_dRightEyeDirX /= dNorme;
  m_dRightEyeDirY /= dNorme;
}

int CPifPaf::getLeftEyeX()
{
  return m_dLeftEyeCenterX+m_dLeftEyeDirX*cm_dEyeYRadiusRatio*m_nHeight;
}

int CPifPaf::getRightEyeX()
{
  return m_dRightEyeCenterX+m_dRightEyeDirX*cm_dEyeYRadiusRatio*m_nHeight;
}

int CPifPaf::getLeftEyeY()
{
  return m_dEyeCenterY+m_dLeftEyeDirY*cm_dEyeYRadiusRatio*m_nHeight;
}

int CPifPaf::getRightEyeY()
{
  return m_dEyeCenterY+m_dRightEyeDirY*cm_dEyeYRadiusRatio*m_nHeight;
}

void CPifPaf::MouseMove(int x, int y)
{
  m_nMousePosX = x;
  m_nMousePosY = y;
  computeLook();
}

void CPifPaf::KeyDown(int keyCode)
{
  if(keyCode == 0x01000012)
    m_bLeftDirection = true;
  if(keyCode == 0x01000014)
    m_bLeftDirection = false;
}

