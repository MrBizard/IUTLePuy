#include "carre.h"
#include "inc_libgraph2.h"
#include <iostream>

void SCarre::Creer(const SPoint2D& depart, const SVecteur2D& direction)
{
  SVecteur2D directionsuiv = direction;
  m_points[0] = depart;
  for (int i = 1; i < 3; ++i)
  {
    m_points[i] = m_points[i - 1].Ajouter(directionsuiv);

    //Fait tourner la direction de 90°
    double temp = directionsuiv.m_dX;
    directionsuiv.m_dX = -directionsuiv.m_dY;
    directionsuiv.m_dY = temp;
  }
  m_points[3] = m_points[2].Ajouter(directionsuiv);
}

void SCarre::Afficher() const
{
  for (int i = 0; i < 3; ++i)
  {
    LibGraph2::drawLine((float)m_points[i].m_dX, (float)m_points[i].m_dY, (float)m_points[i + 1].m_dX, (float)m_points[i + 1].m_dY);
  }
  LibGraph2::drawLine((float)m_points[3].m_dX, (float)m_points[3].m_dY, (float)m_points[0].m_dX, (float)m_points[0].m_dY);
}

void SCarre::AfficherTexte() const
{
  for (const SPoint2D& pt : m_points)
  {
    pt.Afficher();
    std::cout << " ";
  }
}

double SCarre::Cote() const
{
  return m_points[0].Soustraire(m_points[1]).Norme();
}

double SCarre::Perimetre() const
{
  return 4 * Cote();
}
