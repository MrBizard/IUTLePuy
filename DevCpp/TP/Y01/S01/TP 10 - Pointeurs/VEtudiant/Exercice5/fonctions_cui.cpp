#include "fonctions_cui.h"
#include <iostream>

char menu()
{
  std::cout << "\n\n"
    "         Super Generator 3000         \n"
    "======================================\n"
    "s : Active/désactive les styles\n"
    "0 : Génère une phrase de management\n"
    "1 : Génère une phrase de pédagogie\n"
    "2 : Génère une phrase de programmation\n"
    "q : Quitter\n"
    "\n"
    "Veuillez entrer votre choix : ";

  char c;
  std::cin >> c;
  std::cin.ignore(-1);

  return std::tolower(c);
}
