#ifdef _WIN32
#include <Windows.h>
#endif
#include "objetgraphique.h"
#include <iostream>

int main()
{
#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8); //Passe la console en UTF-8
#endif

  std::cout << "\nProgramme principal : Création de l'objet \"position\"...\n";
  CPoint position(1, 2);
  std::cout << "\nProgramme principal : Création de l'objet \"couleur\"...\n";
  CCouleur couleur(0x27, 0xFF, 0x12);
  std::cout << "\nProgramme principal : Création de l'objet \"objGraph\"...\n";
  CObjetGraphique objGraph(position, couleur);
  std::cout << "\nProgramme principal : Affichage de l'objet \"objGraph\"...\n";
  std::cout << objGraph << '\n';

  return 0;
}

