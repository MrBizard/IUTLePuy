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
    "1 : Réaliser un calcul\n"
    "q : Quitter\n"
    "\n"
    "Votre choix : ";
  std::cin >> choix;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return choix;
}

/**
 *  Demande la saisie d'une chaine de caractères à la console après avoir affiché un message d'invite.
 *
 * \param message Le message à afficher
 * \return La chaine de caractères saisie
 */
std::string SaisirTexte(const std::string& message)
{
  std::string str;
  std::cout << message << " : ";
  std::getline(std::cin, str);
  return str;
}

/**
 *  Affiche un résultat numérique à la suite d'un message..
 * 
 * \param message Le message à afficher
 * \param val La valeur numérique à afficher
 */
void AfficheResultat(const std::string& message, double val)
{
  std::cout << message << " : " << val;
}


