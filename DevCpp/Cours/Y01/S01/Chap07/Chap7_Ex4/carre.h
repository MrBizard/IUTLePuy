#pragma once

#include "vecteur2D.h"

using CPoint2D = CVecteur2D;

class CCarre
{
private:
  CPoint2D m_points[4];

public:
  //Constructeur de CCarre
  CCarre();

  //Affichage du carré
  void Afficher() const;
  //Affichage en texte des positions des 4 coins du carré
  void AfficherTexte() const;

  //Créer le carré à l'aide d'un point et d'un vecteur
  void Creer(const CPoint2D& depart, const CVecteur2D& direction);
  //Calculer la longueur de son côté
  double Cote() const;
  //Calculer son périmètre
  double Perimetre() const;
  //Copie un carré
  void Copier(const CCarre& carre);
};
