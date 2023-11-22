#pragma once

#include "vecteur2D.h"

using SPoint2D = SVecteur2D;

struct SCarre
{
private:
  SPoint2D m_points[4];

public:
  //Affichage du carré
  void Afficher() const;
  //Affichage en texte des positions des 4 coins du carré
  void AfficherTexte() const;

  //Créer le carré à l'aide d'un point et d'un vecteur
  void Creer(const SPoint2D& depart, const SVecteur2D& direction);
  //Calculer la longueur de son côté
  double Cote() const;
  //Calculer son périmètre
  double Perimetre() const;
};
