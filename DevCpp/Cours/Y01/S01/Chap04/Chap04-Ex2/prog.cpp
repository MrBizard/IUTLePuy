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
      unsigned int max = SaisirEntierPositif("Veuillez entrer la limite");
      AfficherPuissance2(max);
    }
    break;
    case '2':
    {
      size_t hauteur = SaisirEntierPositif("Veuillez entrer la hauteur du triangle");
      size_t base = SaisirEntierPositif("Veuillez entrer la base du triangle");
      AfficherTriangle(hauteur, base);
    }
      break;
    case '3':
    {
      unsigned int M = SaisirEntierPositif("Veuillez entrer la valeur du dividende");
      int N = SaisirEntier("Veuillez entrer la valeur du diviseur");
      auto resultat = DivisionEntiere(M, N);
      std::cout << "Le quotient et le reste de la division entière de " << M << " par " << N << " sont respectivement " << resultat[0] << " et " << resultat[1] << '\n';
    }
      break;
    case '4':
    {
      unsigned int n = SaisirEntierPositif("Veuillez entrer la valeur pour laquelle calculer la suite de Fibonacci");
      std::cout << "La suite de Fibonacci pour n = " << n << " vaut " << Fibonacci(n) << '\n';
    }
      break;
    case '5':
    {
      unsigned int n = SaisirEntierPositif("Veuillez entrer le nombre à \"inverser\"");
      std::cout << "L'\"inverse\" de " << n << " est " << InverserNombre(n) << '\n';
    }
      break;
    case '6':
    {
      unsigned int limite = SaisirEntierPositif("Veuillez entrer la limite de la recherche");
      auto resultats = TrouverNombrePremier(limite);
      std::cout << "Les nombres premiers inférieurs à " << limite << " sont : ";
      for (auto p : resultats)
        std::cout << p << ' ';
      std::cout << '\n';
    }
      break;
    case '7':
    {
      unsigned int limite = SaisirEntierPositif("Veuillez entrer la limite de la recherche");
      auto resultats = TrouverNombreParfait(limite);
      std::cout << "Les nombres parfaits inférieurs à " << limite << " sont : ";
      for (auto p : resultats)
        std::cout << p << ' ';
      std::cout << '\n';
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