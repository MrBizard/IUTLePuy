#include <Windows.h>
#include "inc_libgraph2.h"
#include "vecteur2D.h"
#include "carre.h"
#include <iostream>

int main(void)
{
  CPoint2D pt;              //Création d'un point par son constructeur par défaut (0, 0)
  CVecteur2D vt{ 1, 0 };    //Création d'un vecteur par son constructeur avec paramètres (1, 0)

  CCarre carre1;            //Construction d'un carré "vide"
  carre1.Creer(pt, vt);     //Initialisation du carré
  std::cout << "\nCarre 1 : \n";
  carre1.AfficherTexte();

  CCarre carre2{ pt, vt };  //Construction d'un carré initialisé
  std::cout << "\nCarre 2 : \n";
  carre2.AfficherTexte();

  std::cout << "\nCarre temporaire : \n";
  CCarre{}.AfficherTexte();  //Construction d'un carré temporaire (aucune utilité car détruit immédiatement)

  //Construction d'un carré initialisé par des paramètres temporaires
  CCarre carre3{ CPoint2D{}, CVecteur2D{ 1, 0 } };
  std::cout << "\nCarre 3 : \n";
  carre3.AfficherTexte();

  //Construction d'un carré initialisé par des paramètres temporaires déduits par le compilateur
  CCarre carre4{ {}, { 1, 0 } };
  std::cout << "\nCarre 4 : \n";
  carre4.AfficherTexte();

  return 0;
}

