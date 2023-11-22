#include "vecteur2D.h"

#include <cmath>
#include <iostream>

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
  std::cout << "Orientation de " << strNom << " = " << Orientation() * 180 / 3.1415 << " deg\n\n";
}

double CVecteur2D::Norme() const
{
  return sqrt(m_dX*m_dX + m_dY*m_dY);
}

double CVecteur2D::Orientation() const
{
  return atan2(m_dY, m_dX);
}


CVecteur2D CVecteur2D::Ajouter(const CVecteur2D& v) const
{
  CVecteur2D retour;
  retour.m_dX = m_dX + v.m_dX;
  retour.m_dY = m_dY + v.m_dY;
  return retour;
}

CVecteur2D CVecteur2D::Soustraire(const CVecteur2D& v) const
{
  CVecteur2D retour;
  retour.m_dX = m_dX - v.m_dX;
  retour.m_dY = m_dY - v.m_dY;
  return retour;
}

CVecteur2D CVecteur2D::Multiplier(double dScal) const
{
  CVecteur2D retour;
  retour.m_dX = dScal * m_dX;
  retour.m_dY = dScal * m_dY;
  return retour;
}

CVecteur2D CVecteur2D::Diviser(double dScal) const
{
  return Multiplier(1.0 / dScal);
}

bool CVecteur2D::PlusGrandQue(const CVecteur2D& v) const
{
  if (Norme() > v.Norme())
    return true;
  return false;
}
