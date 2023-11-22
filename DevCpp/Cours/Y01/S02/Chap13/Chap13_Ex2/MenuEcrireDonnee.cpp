#include "MenuEcrireDonnee.h"
#include <iostream>

void CMenuEcrireDonnee::operator ()()
{
  //Demande le nom de fichier à l'utilisateur via la classe mère
  CMenuFichierDonnee::operator ()();
  //A ce niveau, le nom du fichier est dans la donnée membre m_strNomFichier

  int nError;
  while ((nError = m_Donnee.EcrireDonnee(m_strNomFichier)) != 0)
  {
    switch (nError)
    {
    case 1: // Erreur d'ouverture de fichier
      //Affiche un message à l'utilisateur pour qu'il puisse corriger le problème
      std::cout << "Le fichier \"" << m_strNomFichier << "\" n'a pas pu être ouvert en écriture.\n"
        "Vérifiez le chemin d'accès, vos droits d'accès au fichier et si le fichier n'est pas en lecture seule.\n";
      //Redemande le nom de fichier
      CMenuFichierDonnee::operator ()();
      break;

    case 2: // L'écriture s'est mal déroulée
      //Affiche un message à l'utilisateur pour qu'il puisse corriger le problème
      std::cout << "L'écriture ne s'est pas déroulée correctement dans le fichier \"" << m_strNomFichier << "\".\n"
        "Vérifiez que vous disposez de suffisamment d'espace disque et entrez à nouveau le nom du fichier.\n";
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