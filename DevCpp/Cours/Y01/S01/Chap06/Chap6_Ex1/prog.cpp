#include "Heros.h"

#include <iostream>

int main(void)
{
  // Création du héros
  SHeros LeJoueur;
  SHeros LeJoueur2;

  // Initialisation du joueur
  LeJoueur.Init("heros1.png");
  LeJoueur2.Init("heros2.png");

  // Affichage du joueur
  std::cout << "LeJoueur : \n";
  LeJoueur.Afficher();
  std::cout << "LeJoueur2 : \n";
  LeJoueur2.Afficher();

  // Déplacement du joueur
  LeJoueur.Deplacer(10, 4);
  LeJoueur.Deplacer(2, 6);
  LeJoueur2.Deplacer(3,8);

  // Affichage du joueur
  std::cout<<"LeJoueur = \n";
  LeJoueur.Afficher();
  std::cout<<"LeJoueur2 = \n";
  LeJoueur2.Afficher();

  //Fin du programme
  return 0;
}