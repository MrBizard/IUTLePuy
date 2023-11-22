#include "carre.h"
#include "inc_libgraph2.h"
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
    m_points[i] = m_points[i - 1].Ajouter(directionsuiv);

    //Fait tourner la direction de 90°
    double temp = directionsuiv.GetX();
    directionsuiv.SetX(-directionsuiv.GetY());
    directionsuiv.SetY(temp);
  }
  m_points[3] = m_points[2].Ajouter(directionsuiv);
}

void CCarre::Afficher() const
{
  for (int i = 0; i < 3; ++i)
  {
    LibGraph2::drawLine((float)m_points[i].GetX(), (float)m_points[i].GetY(), (float)m_points[i + 1].GetX(), (float)m_points[i + 1].GetY());
  }
  LibGraph2::drawLine((float)m_points[3].GetX(), (float)m_points[3].GetY(), (float)m_points[0].GetX(), (float)m_points[0].GetY());
}

void CCarre::AfficherTexte() const
{
  for (const CPoint2D& pt : m_points)
  {
    pt.Afficher();
    std::cout << " \n";
  }
}

double CCarre::Cote() const
{
  return m_points[0].Soustraire(m_points[1]).Norme();
}

double CCarre::Perimetre() const
{
  return 4 * Cote();
}

void CCarre::Copier(const CCarre& carre)
{
  for (int i = 0; i < 4; ++i)
    m_points[i] = carre.m_points[i];
}
