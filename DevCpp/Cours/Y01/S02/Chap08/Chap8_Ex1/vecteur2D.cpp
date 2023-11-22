#include "vecteur2D.h"

#include <math.h>
#include <iostream>

CVecteur2D::CVecteur2D(double x, double y)
{
  m_dX = x;
  m_dY = y;
}

double CVecteur2D::GetX() const
{
  return m_dX;
}

double CVecteur2D::GetY() const
{
  return m_dY;
}

void CVecteur2D::SetX(double x)
{
  m_dX = x;
}

void CVecteur2D::SetY(double y)
{
  m_dY = y;
}

void CVecteur2D::Afficher() const
{
  std::cout << "(" << m_dX << ", " << m_dY << ")";
}

void CVecteur2D::AffichageDetail(const std::string& strNom) const
{
  std::cout << strNom << " = ";
  Afficher();
  std::cout << '\n';
  std::cout << "Norme de " << strNom << " = " << Norme() << '\n';
  std::cout << "Orientation de " << strNom << " = " << Orientation() * 180 / 3.1415 << " deg" << "\n\n";
}

double CVecteur2D::Norme() const
{
  return sqrt(m_dX*m_dX + m_dY*m_dY);
}

double CVecteur2D::Orientation() const
{
  return atan2(m_dY, m_dX);
}


//Opérateurs unaires
CVecteur2D CVecteur2D::operator -() const
{
  CVecteur2D ret;
  ret.m_dX = -m_dX;
  ret.m_dY = -m_dY;
  return ret;
}



//Opérateurs de comparaison
#if __cpp_impl_three_way_comparison >= 201907L

std::partial_ordering CVecteur2D::operator<=>(const CVecteur2D& v) const
{
  return Norme() <=> v.Norme();
}

#else

bool CVecteur2D::operator==(const CVecteur2D& v) const
{
  if (m_dX == v.m_dX && m_dY == v.m_dY)
    return true;
  else
    return false;
}

bool CVecteur2D::operator!=(const CVecteur2D& c) const
{
  return !(*this == c);
}

bool CVecteur2D::operator>(const CVecteur2D& v) const
{
  if (Norme() > v.Norme())
    return true;
  return false;
}

bool CVecteur2D::operator<(const CVecteur2D& v) const
{
  if (Norme() < v.Norme())
    return true;
  return false;
}

bool CVecteur2D::operator>=(const CVecteur2D& v) const
{
  return !((*this) < v);
}

bool CVecteur2D::operator<=(const CVecteur2D& v) const
{
  return !((*this) > v);
}

#endif


//Opérateurs arithmétiques avec affectation
CVecteur2D & CVecteur2D::operator+=(const CVecteur2D & v)
{
  m_dX += v.m_dX;  m_dY += v.m_dY;
  return *this;
}

CVecteur2D & CVecteur2D::operator-=(const CVecteur2D & v)
{
  m_dX -= v.m_dX;  m_dY -= v.m_dY;
  return *this;
}

CVecteur2D & CVecteur2D::operator*=(double dScal)
{
  m_dX *= dScal;  m_dY *= dScal;
  return *this;
}

CVecteur2D & CVecteur2D::operator/=(double dScal)
{
  m_dX /= dScal;  m_dY /= dScal;
  return *this;
}



//Opérateurs arithmétiques
CVecteur2D CVecteur2D::operator+(const CVecteur2D & v) const
{
  CVecteur2D retour = *this;
  retour += v;
  return retour;
}


CVecteur2D CVecteur2D::operator-(const CVecteur2D& v) const
{
  CVecteur2D retour = *this;
  retour -= v;
  return retour;
}

CVecteur2D CVecteur2D::operator*(double dScal) const
{
  CVecteur2D retour = *this;
  retour *= dScal;
  return retour;
}

CVecteur2D CVecteur2D::operator/(double dScal) const
{
  CVecteur2D retour = *this;
  retour /= dScal;
  return retour;
}


//Opérateur de sortie vers flux
std::ostream& operator<<(std::ostream& out, const CVecteur2D& v)
{
  out << "(" << v.GetX() << ", " << v.GetY() << ")";
  return out;
}
