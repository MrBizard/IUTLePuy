#ifdef _WIN32
#include <Windows.h>
#endif
#include <iostream>
#include "fonctions.h"
#include "console.h"

/**
 *  Fonction principale du programme.
 * 
 * \return 0
 */
int main()
{
#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
#endif // _WIN32

  char choix = 0;
  while (choix != 'q' && choix != 'Q')
  {
    switch (choix = ChoisirMenu())
    {
    case '1':
    {
      std::string calcul = SaisirTexte("Veuillez entrer le calcul à effectuer (sans espaces)");
      std::vector<double> operandes;
      std::vector<OperatorFunc> operateurs;
      decodeCalcul(calcul, operandes, operateurs);
      double resultat = calcule(operandes, operateurs);
      AfficheResultat("Le résultat du calcul est", resultat);
    }
    break;
    case 'q':
    case 'Q':
      break;
    default:
      std::cout << "Choix non valide !\n";
    }
  }

  return 0;
}