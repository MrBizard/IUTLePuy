#include <Windows.h>
#include "inc_libgraph2.h"
#include "vecteur2D.h"
#include "carre.h"
#include <iostream>

int main(void)
{
  CPoint2D pt;              //Cr�ation d'un point par son constructeur par d�faut (0, 0)
  CVecteur2D vt{ 1, 0 };    //Cr�ation d'un vecteur par son constructeur avec param�tres (1, 0)

  CCarre carre1;            //Construction d'un carr� "vide"
  carre1.Creer(pt, vt);     //Initialisation du carr�
  std::cout << "\nCarre 1 : \n";
  carre1.AfficherTexte();

  CCarre carre2{ pt, vt };  //Construction d'un carr� initialis�
  std::cout << "\nCarre 2 : \n";
  carre2.AfficherTexte();

  std::cout << "\nCarre temporaire : \n";
  CCarre{}.AfficherTexte();  //Construction d'un carr� temporaire (aucune utilit� car d�truit imm�diatement)

  //Construction d'un carr� initialis� par des param�tres temporaires
  CCarre carre3{ CPoint2D{}, CVecteur2D{ 1, 0 } };
  std::cout << "\nCarre 3 : \n";
  carre3.AfficherTexte();

  //Construction d'un carr� initialis� par des param�tres temporaires d�duits par le compilateur
  CCarre carre4{ {}, { 1, 0 } };
  std::cout << "\nCarre 4 : \n";
  carre4.AfficherTexte();

  return 0;
}

