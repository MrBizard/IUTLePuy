#ifdef _WIN32
#define NOMINMAX
#include <Windows.h>
#endif // _WIN32

#include <iostream>
#include "fonctions_cui.h"
#include "fonctions.h"

int main()
{
#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
#endif // _WIN32
  std::srand(std::time(nullptr));

  /*

  bool style = false;

  //Créer un tableau de fonctions ici

  char choix;
  while ((choix = menu()) != 'q')
  {
    std::cout<<"\x1B[2J\x1B[0;0H";
    switch (choix)
    {
    case 's':
      //Basculer le booléen style ici
      std::cout << "Le style est " << (style ? "activé" : "désactivé") << '\n';
      break;

    default:
      if (choix >= '0' && choix <= '2')
      {
        size_t indice = choix - '0';
        //Appeler la bonne fonction du tableau de fonction ici et afficher son résultat
      }
      else
        std::cout << "Choix invalide !\n";
      break;
    }
  }

  */
}

