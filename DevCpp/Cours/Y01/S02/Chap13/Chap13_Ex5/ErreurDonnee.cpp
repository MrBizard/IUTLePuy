#include "ErreurDonnee.h"
#include <iostream>

void CErreurEcritureDonnee::AfficherQuoiFaire()
{
  switch (m_nCause)
  {
  case 1: // Erreur d'ouverture de fichier
    //Affiche un message à l'utilisateur pour qu'il puisse corriger le problème
    std::cout << "Le fichier \"" << m_strNomFichier << "\" n'a pas pu être ouvert en écriture.\n"
      "Vérifiez le chemin d'accès, vos droits d'accès au fichier et si le fichier n'est pas en lecture seule.\n";
    break;

  case 2: // L'écriture s'est mal déroulée
    //Affiche un message à l'utilisateur pour qu'il puisse corriger le problème
    std::cout << "L'écriture ne s'est pas déroulée correctement dans le fichier \"" << m_strNomFichier << "\".\n"
      "Vérifiez que vous disposez de suffisamment d'espace disque et entrez à nouveau le nom du fichier.\n";
    break;

  default: //Erreur non gérée
    std::cerr << "Une erreur non gérée est survenue !\n";
    exit(EXIT_FAILURE);
    break;
  }
}

void CErreurLectureDonnee::AfficherQuoiFaire()
{
  switch (m_nCause)
  {
  case 1: // Erreur d'ouverture du fichier
    //Affiche un message à l'utilisateur pour qu'il puisse corriger le problème
    std::cout << "Le fichier \"" << m_strNomFichier << "\" n'a pas pu être ouvert en lecture.\n"
      "Vérifiez le chemin d'accès et vos droits d'accès au fichier.\n";
    //Redemande le nom de fichier
    break;

  case 2: // Mauvais format
    //Affiche un message à l'utilisateur pour qu'il puisse corriger le problème
    std::cout << "Le fichier \"" << m_strNomFichier << "\" n'est pas du bon format.\n"
      "Entrez un nom de fichier précédemment créé par ce programme.\n";
    //Redemande le nom de fichier
    break;

  case 3: // Echec en cours de lecture
    //Affiche un message à l'utilisateur pour qu'il puisse corriger le problème
    std::cout << "Les données ne peuvent pas être lues depuis le fichier \"" << m_strNomFichier << "\".\n"
      "Peut-être que ce fichier a été corrompu.\n"
      "Essayez avec un autre fichier.\n";
    //Redemande le nom de fichier
    break;

  default: //Erreur non gérée
    std::cerr << "Une erreur non gérée est survenue !\n";
    exit(EXIT_FAILURE);
    break;
  }
}