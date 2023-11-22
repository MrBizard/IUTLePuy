#pragma once

#include "vecteur2D.h"

using SPoint2D = SVecteur2D;

struct SCarre
{
private:
  SPoint2D m_points[4];

public:
  //Affichage du carr�
  void Afficher() const;
  //Affichage en texte des positions des 4 coins du carr�
  void AfficherTexte() const;

  //Cr�er le carr� � l'aide d'un point et d'un vecteur
  void Creer(const SPoint2D& depart, const SVecteur2D& direction);
  //Calculer la longueur de son c�t�
  double Cote() const;
  //Calculer son p�rim�tre
  double Perimetre() const;
};
