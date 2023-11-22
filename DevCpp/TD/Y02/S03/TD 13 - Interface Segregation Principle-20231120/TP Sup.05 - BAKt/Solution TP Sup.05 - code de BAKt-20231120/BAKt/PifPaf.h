#pragma once
#include "ieventlistener.h"
class CPifPaf
  //Solution
  : public IKeyboardListener
  , public IMouseListener
  //Fin Solution
{
  int m_nMousePosX;
  int m_nMousePosY;
  int m_nPosX;
  int m_nPosY;
  int m_nWidth;
  int m_nHeight;
  double m_dLeftEyeCenterX;
  double m_dRightEyeCenterX;
  double m_dEyeCenterY;
  double m_dLeftEyeDirX;
  double m_dLeftEyeDirY;
  double m_dRightEyeDirX;
  double m_dRightEyeDirY;
  const double cm_dLeftEyeXRatio;
  const double cm_dRightEyeXRatio;
  const double cm_dEyeYRatio;
  const double cm_dEyeYRadiusRatio;

  bool m_bLeftDirection;

  void computeLook();
public:
  CPifPaf(void);

  void setPos(int x, int y);
  void setSize(int width, int height);

  int getPosX() const {return m_nPosX;}
  int getPosY() const {return m_nPosY;}
  int getWidth() const {return m_nWidth;}
  int getHeight() const {return m_nHeight;}

  bool isTurningLeft(){return m_bLeftDirection;}
  int getLeftEyeX();
  int getRightEyeX();
  int getLeftEyeY();
  int getRightEyeY();

  void MouseMove(int x, int y);
  void KeyDown(int keyCode);
};

