#include "vecteur2D.h"

#include <cmath>
#include <iostream>

void SVecteur2D::Afficher() const
{
  std::cout << "(" << m_dX << ", " << m_dY << ")";
}

void SVecteur2D::AffichageDetail(const std::string& strNom) const
{
  std::cout << strNom << " = ";
  Afficher();
  std::cout << '\n';
  std::cout << "Norme de " << strNom << " = " << Norme() << '\n';
  std::cout << "Orientation de " << strNom << " = " << Orientation() * 180 / 3.1415 << " deg\n\n";
}

double SVecteur2D::Norme() const
{
  return sqrt(m_dX * m_dX + m_dY * m_dY);
}

double SVecteur2D::Orientation() const
{
  return atan2(m_dY, m_dX);
}


SVecteur2D SVecteur2D::Ajouter(const SVecteur2D& v) const
{
  SVecteur2D retour;
  retour.m_dX = m_dX + v.m_dX;
  retour.m_dY = m_dY + v.m_dY;
  return retour;
}

SVecteur2D SVecteur2D::Soustraire(const SVecteur2D& v) const
{
  SVecteur2D retour;
  retour.m_dX = m_dX - v.m_dX;
  retour.m_dY = m_dY - v.m_dY;
  return retour;
}

SVecteur2D SVecteur2D::Multiplier(double dScal) const
{
  SVecteur2D retour;
  retour.m_dX = dScal * m_dX;
  retour.m_dY = dScal * m_dY;
  return retour;
}

SVecteur2D SVecteur2D::Diviser(double dScal) const
{
  return Multiplier(1.0 / dScal);
}

bool SVecteur2D::PlusGrandQue(const SVecteur2D& v) const
{
  if (Norme() > v.Norme())
    return true;
  return false;
}
