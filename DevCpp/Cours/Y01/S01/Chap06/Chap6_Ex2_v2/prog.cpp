#include "vecteur2D.h"

#include <iostream>

int main(void)
{
  //Création du vecteur A = (3, 4)
  SVecteur2D A;
  A.m_dX = 3;
  A.m_dY = 4;

  //Affiche A ainsi que sa norme et son argument
  A.AffichageDetail("A");

  //Création du vecteur B = (1, 2)
  SVecteur2D B;
  B.m_dX = 1;
  B.m_dY = 2;

  //Calcul du vecteur C = A+B
  SVecteur2D C;
  C = A.Ajouter(B);
  //Affichage du calcul
  A.Afficher();
  std::cout << " + ";
  B.Afficher();
  std::cout << " = ";
  C.Afficher();

  std::cout << '\n';

  return 0;
}