#pragma once

#include "vecteur2D.h"

class CCarre
{
private:
  CPoint2D m_points[4];

public:
  //Constructeurs de CCarre
  CCarre();
  CCarre(const CPoint2D& depart, const CVecteur2D& direction)
  {
    Creer(depart, direction);
  }

  //Affichage en texte des positions des 4 coins du carré
  void AfficherTexte() const;

  //Créer le carré à l'aide d'un point et d'un vecteur
  void Creer(const CPoint2D& depart, const CVecteur2D& direction);
  //Calculer la longueur de son côté
  double Cote() const;
  //Calculer son périmètre
  double Perimetre() const;

  const CPoint2D& operator[](size_t i) const;

};
