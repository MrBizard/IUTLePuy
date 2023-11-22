#include "Position2D.h"
//Solution
#include <cassert>
#include <cmath>
using namespace std;

CPosition::ptr CPosition2D::normer()
{
  double dNorme = norme();
  m_dX /= dNorme;
  m_dY /= dNorme;
  return CPosition::shared_from_this();
}

double CPosition2D::norme() const
{
  return sqrt(m_dX*m_dX + m_dY*m_dY);
}

double CPosition2D::distance(CPosition::const_ptr pos2) const
{
  auto pos2D2 = dynamic_pointer_cast<const CPosition2D>(pos2);
  assert(pos2D2);
  return sqrt((m_dX-pos2D2->m_dX)*(m_dX-pos2D2->m_dX) + (m_dY-pos2D2->m_dY)*(m_dY-pos2D2->m_dY));
}

CPosition::ptr CPosition2D::deplacer(std::shared_ptr<const CPosition> dir, double dDist)
{
  auto dir2D = dynamic_pointer_cast<const CPosition2D>(dir);
  assert(dir2D);
  m_dX += dir2D->m_dX * dDist;
  m_dY += dir2D->m_dY * dDist;
  return CPosition::shared_from_this();
}

CPosition::ptr CPosition2D::operator-(const CPosition& pos2) const
{
  auto pos2D2 = dynamic_pointer_cast<const CPosition2D>(&pos2);
  assert(&pos2D2);

  return create(m_dX - pos2D2->m_dX, m_dY - pos2D2->m_dY);
}

//std::shared_ptr<CPosition> CPosition2D::operator-() const
//{
//  return std::make_shared<CPosition2D>(-m_dX, -m_dY);
//}
//
//std::shared_ptr<CPosition> CPosition2D::operator+(const CPosition& pos2) const
//{
//  const CPosition2D& pos2D2 = dynamic_cast<const CPosition2D&>(pos2);
//  assert(&pos2D2);
//
//  return std::make_shared<CPosition2D>(m_dX + pos2D2.m_dX, m_dY + pos2D2.m_dY);
//}
//
//std::shared_ptr<CPosition> CPosition2D::operator+() const
//{
//  return std::make_shared<CPosition2D>(*this);
//}
//
//CPosition& CPosition2D::operator-=(const CPosition& pos2)
//{
//  const CPosition2D& pos2D2 = dynamic_cast<const CPosition2D&>(pos2);
//  assert(&pos2D2);
//
//  m_dX -= pos2D2.m_dX;
//  m_dY -= pos2D2.m_dY;
//
//  return *this;
//}
//
//CPosition& CPosition2D::operator+=(const CPosition& pos2)
//{
//  const CPosition2D& pos2D2 = dynamic_cast<const CPosition2D&>(pos2);
//  assert(&pos2D2);
//
//  m_dX += pos2D2.m_dX;
//  m_dY += pos2D2.m_dY;
//
//  return *this;
//}
//
//std::shared_ptr<CPosition> CPosition2D::operator*(double scalar) const
//{
//  return std::make_shared<CPosition2D>(m_dX*scalar, m_dY*scalar);
//}
//
//CPosition& CPosition2D::operator*=(double scalar)
//{
//  m_dX*=scalar;
//  m_dY*=scalar;
//  return *this;
//}

CPosition::ptr CPosition2D::operator/(double scalar) const
{
  return create(m_dX / scalar, m_dY / scalar);
}

//CPosition& CPosition2D::operator/=(double scalar)
//{
//  m_dX/=scalar;
//  m_dY/=scalar;
//  return *this;
//}
//Fin Solution