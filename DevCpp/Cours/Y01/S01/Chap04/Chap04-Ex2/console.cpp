#include "console.h"
#include <iostream>

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

