#ifdef _WIN32
#include <Windows.h>
#endif
#include <iostream>
#include <string>
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
    "1 : Initialiser le tableau\n"
    "2 : Déterminer le min et le max\n"
    "q : Quitter\n"
    "\n"
    "Votre choix : ";
  std::cin >> choix;
  system("cls");
  return choix;
}

/**
 *  Demande la saisie d'un nombre entier positif à la console après avoir affiché un message d'invite.
 *
 * \param[in] message Le message à afficher
 * \return La valeur de l'entier
 */
unsigned int SaisirEntierPositif(const std::string& message)
{
  unsigned int n;
  std::cout << message << " : ";
  std::cin >> n;
  return n;
}

/**
 *  Crée un tableau de taille spécifiée en paramètre, initialisé avec des nombres réels compris entre 0 et 1.
 * 
 * \param[in] taille La taille du tableau créé
 * \return Le tableau initialisé
 */
std::vector<double> initTab(size_t taille)
{
  std::vector<double> tab(taille);
  for (double& val : tab)
    val = static_cast<double>(rand()) / RAND_MAX;
  return tab;
}

/**
 *  Détermine le minimum et le maximum d'un tableau.
 * 
 * \param[in] tab Le tableau
 * \param[out] min Une référence vers laquelle stocker le minimum
 * \param[out] max Une référence vers laquelle stocker le maximum
 */
void getMinMax(const std::vector<double>& tab, double& min, double& max)
{
  if (tab.empty())
    return;
  min = max = tab[0];
  for (const double& val : tab)
  {
    if (val < min) min = val;
    if (val > max) max = val;
  }
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

  std::srand(static_cast<unsigned int>(std::time(0)));

  char choix = 0;
  std::vector<double> LeTableau;
  while (choix != 'q' && choix != 'Q')
  {
    switch (choix = ChoisirMenu())
    {
    case '1':
    {
      size_t nbValeurs = SaisirEntierPositif("Veuillez entrer la taille du tableau désiré");
      LeTableau = initTab(nbValeurs);
    }
    break;
    case '2':
    {
      double minimum = -1, maximum = -1;
      getMinMax(LeTableau, minimum, maximum);
      if (minimum == -1)
        std::cerr << "Le tableau n'a pas encore été initialisé\n";
      else
        std::cout << "Toutes les valeurs du tableau sont comprises entre " << minimum << " et " << maximum << ".\n";
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