#include "MenuLireDonnee.h"
#include <iostream>

void CMenuLireDonnee::operator ()()
{
  //Demande le nom de fichier à l'utilisateur via la classe mère
  CMenuFichierDonnee::operator ()();
  //A ce niveau, le nom du fichier est dans la donnée membre m_strNomFichier

  int nError;
  while ((nError = m_Donnee.LireDonnee(m_strNomFichier)) != 0)
  {
    switch (nError)
    {
    case 1: // Erreur d'ouverture du fichier
      //Affiche un message à l'utilisateur pour qu'il puisse corriger le problème
      std::cout << "Le fichier \"" << m_strNomFichier << "\" n'a pas pu être ouvert en lecture.\n"
        "Vérifiez le chemin d'accès et vos droits d'accès au fichier.\n";
      //Redemande le nom de fichier
      CMenuFichierDonnee::operator ()();
      break;
    case 2: // Mauvais format
      //Affiche un message à l'utilisateur pour qu'il puisse corriger le problème
      std::cout << "Le fichier \"" << m_strNomFichier << "\" n'est pas du bon format.\n"
        "Entrez un nom de fichier précédemment créé par ce programme.\n";
      //Redemande le nom de fichier
      CMenuFichierDonnee::operator ()();
      break;
    case 3: // Echec en cours de lecture
      //Affiche un message à l'utilisateur pour qu'il puisse corriger le problème
      std::cout << "Les données ne peuvent pas être lues depuis le fichier \"" << m_strNomFichier << "\".\n"
        "Peut-être que ce fichier a été corrompu.\n"
        "Essayez avec un autre fichier.\n";
      //Redemande le nom de fichier
      CMenuFichierDonnee::operator ()();
      break;
    default: //Erreur non gérée
      std::cerr << "Une erreur non gérée est survenue !\n";
      exit(EXIT_FAILURE);
      break;
    }
  }
}