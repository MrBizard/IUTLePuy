#ifdef _WIN32
#include <Windows.h>
#endif
#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <vector>

/**
 *  Affiche le menu et retourne le choix de l'utilisateur.
 * 
 * \return Le caractère choisi par l'utilisateur   
 */
char ChoisirMenu()
{
  char choix;
  std::cout << "\n\n\n"
    "Menu de notre application\n"
    "=========================\n"
    "1 : Une simple boucle\n"
    "2 : Un triangle\n"
    "3 : Un peu de maths\n"
    "4 : La suite de Fibonacci\n"
    "5 : Inverser un nombre\n"
    "6 : Nombres premiers\n"
    "7 : Nombres parfaits\n"
    "q : Quitter\n"
    "\n"
    "Votre choix : ";
  std::cin >> choix;
  return choix;
}

/**
 *  Demande la saisie d'un nombre entier positif à la console après avoir affiché un message d'invite.
 * 
 * \param message Le message à afficher
 * \return La valeur de l'entier
 */
unsigned int SaisirEntierPositif(std::string message)
{
  unsigned int n;
  std::cout << message << " : ";
  std::cin >> n;
  return n;
}

/**
 *  Demande la saisie d'un nombre entier à la console après avoir affiché un message d'invite.
 *
 * \param message Le message à afficher
 * \return La valeur de l'entier
 */
int SaisirEntier(std::string message)
{
  int n;
  std::cout << message << " : ";
  std::cin >> n;
  return n;
}

/**
 *  Affiche dans la console toutes les puissances de 2 inférieures à une limite.
 *
 * \param limite La valeur limite de recherche
 */
void AfficherPuissance2(unsigned int limite)
{
  std::cout << "Les puissances de 2 sont : ";
  for (unsigned int i = 1; i < limite; i *= 2)
  {
    std::cout << i << " ";
  }
  std::cout << '\n';
}

/**
 *  Affiche un triangle composer de 'o' dans la console.
 * 
 * \param h La hauteur du triangle
 * \param b La dimension de la base du triangle
 */
void AfficherTriangle(size_t h, size_t b)
{
  for (size_t ligne = 0; ligne < h; ligne++)
  {
    for (size_t colonne = 0; colonne < b; colonne++)
    {
      if (b / 2 >= ligne && (colonne < b / 2 - ligne || colonne>b / 2 + ligne))
      {
        std::cout << "-";
      }
      else
      {
        std::cout << "o";
      }
    }
    std::cout << "\n";
  }
}

/**
 *  Calcule la division entière de deux nombres.
 * 
 * \param dividende
 * \param diviseur
 * \return un tableau de deux entiers contenant dans cet ordre le quotient et le reste
 */
std::array<int, 2> DivisionEntiere(unsigned int dividende, int diviseur)
{
  int signe = 1;
  if (diviseur < 0)
  {
    signe = -1;
    diviseur = -diviseur;
  }
  int quotient = 0;
  int reste = dividende;
  while (reste >= diviseur)
  {
    reste -= diviseur;
    quotient += signe;
  }
  std::array res= { quotient, reste };
  return res;
}

/**
 *  Calcule un nombre de la suite de Fibonacci.
 * 
 * \param n Valeur de l'indice de la suite de Fibonacci
 * \return La valeur du nombre de la suite de Fibonacci à l'indice n.
 */
unsigned long long Fibonacci(unsigned int n)
{
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;

  unsigned long long Fn_2 = 0, Fn_1 = 1, Fn;

  for (unsigned int i = 2; i <= n; ++i)
  {
    //Calcul de Fn
    Fn = Fn_2 + Fn_1;
    //Calcul de Fn_1 et Fn_2 pour l'itération suivante
    Fn_2 = Fn_1;
    Fn_1 = Fn;
  }
  return Fn;
}

/**
 *  Fonction qui inverse l'ordre des chiffres d'un nombre.
 * 
 * \param n Nombre dont les chiffres doivent être inversés.
 * \return Le nombre dont les chiffres ont été inversés.
 */
unsigned int InverserNombre(unsigned int n)
{
  unsigned int ret = 0;
  while (n != 0)
  {
    ret *= 10;
    unsigned int chiffre = n - (n / 10) * 10;
    ret += chiffre;
    n /= 10;
  }
  return ret;
}

/**
 *  Trouve tous les nombres premiers inférieurs à une limite.
 * 
 * \param max Limite max de la recherche
 * \return Un tableau d'entier contenant tous les nombres premiers inférieurs à la limite max.
 */
std::vector<unsigned int> TrouverNombrePremier(unsigned int max)
{
  std::vector<unsigned int> premiers;
  for (unsigned int n = 2; n <= max; n++)
  {
    bool bPremier = true;
    for (unsigned int diviseur = 2; diviseur <= std::sqrt(n); ++diviseur)
    {
      if (n % diviseur == 0)
      {
        bPremier = false;
        break;
      }
    }
    if (bPremier)
      premiers.push_back(n);
  }
  return premiers;
}

/**
 *  Trouve tous les nombres parfaits inférieurs à une limite.
 *
 * \param max Limite max de la recherche
 * \return Un tableau d'entier contenant tous les nombres parfaits inférieurs à la limite max.
 */
std::vector<unsigned int> TrouverNombreParfait(unsigned int max)
{
  std::vector<unsigned int> parfaits;
  for (unsigned int n = 2; n <= max; n++)
  {
    unsigned int somme = 0;
    for (unsigned int diviseur = 1; diviseur <= n / 2; ++diviseur)
    {
      if (n % diviseur == 0)
        somme += diviseur;
    }
    if (somme == n)
      parfaits.push_back(n);
  }
  return parfaits;
}

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