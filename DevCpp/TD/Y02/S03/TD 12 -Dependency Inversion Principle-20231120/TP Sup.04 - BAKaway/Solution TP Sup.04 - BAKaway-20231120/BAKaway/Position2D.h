#pragma once
//Solution

#include "position.h"
class CPosition2D :
  public CPosition
{
  double m_dX;
  double m_dY;
  CPosition2D(double x=0, double y=0) : m_dX(x), m_dY(y) {}
  CPosition2D(const CPosition2D&) = default;

public:
  using ptr = std::shared_ptr<CPosition2D>;
  using const_ptr = std::shared_ptr<const CPosition2D>;

  static ptr create(double x = 0, double y = 0) 
  { 
    return ptr(new CPosition2D(x, y)); 
  }
  CPosition::ptr clone() const override
  {
    return CPosition::ptr(new CPosition2D(*this));
  }


  double getX() const {return m_dX;}
  double getY() const {return m_dY;}

  void setX(double d) {m_dX = d;}
  void setY(double d) {m_dY = d;}

  CPosition::ptr normer() override;
  double norme() const override;
  double distance(CPosition::const_ptr pos2) const override;
  CPosition::ptr deplacer(std::shared_ptr<const CPosition> dir, double dDist) override;

  CPosition::ptr operator-(const CPosition& pos2) const override;
  CPosition::ptr operator/(double scalar) const override;
};


//Fin Solution