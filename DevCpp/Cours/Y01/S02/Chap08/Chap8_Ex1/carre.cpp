#include "carre.h"

#include <iostream>

CCarre::CCarre()
{
  for (CPoint2D& pt : m_points)
  {
    pt.SetX(0);
    pt.SetY(0);
  }
}

void CCarre::Creer(const CPoint2D& depart, const CVecteur2D& direction)
{
  CVecteur2D directionsuiv = direction;
  m_points[0] = depart;
  for (int i = 1; i < 3; ++i)
  {
    m_points[i] = m_points[i-1] + directionsuiv;

    //Fait tourner la direction de 90°
    double temp = directionsuiv.GetX();
    directionsuiv.SetX(-directionsuiv.GetY());
    directionsuiv.SetY(temp);
  }
  m_points[3] = m_points[2] + directionsuiv;
}

void CCarre::AfficherTexte() const
{
  for (const CPoint2D& pt : m_points)
  {
    pt.Afficher();
    std::cout << " ";
  }
}

double CCarre::Cote() const
{
  return (m_points[0] - m_points[1]).Norme();
}

double CCarre::Perimetre() const
{
  return 4 * Cote();
}

const CPoint2D& CCarre::operator [](size_t i) const
{
  if (i < 4)
    return m_points[i];
  else //Accès impossible
  {
    std::cerr << "Impossible d'accéder à l'élément " << i << '\n';
    exit(1);
  }
}