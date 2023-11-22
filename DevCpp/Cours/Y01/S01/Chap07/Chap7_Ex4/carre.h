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

  //Affichage du carr�
  void Afficher() const;
  //Affichage en texte des positions des 4 coins du carr�
  void AfficherTexte() const;

  //Cr�er le carr� � l'aide d'un point et d'un vecteur
  void Creer(const CPoint2D& depart, const CVecteur2D& direction);
  //Calculer la longueur de son c�t�
  double Cote() const;
  //Calculer son p�rim�tre
  double Perimetre() const;
  //Copie un carr�
  void Copier(const CCarre& carre);
};
