/*****************************************************************//**
 * \file   Forme.cpp
 * \brief  Définition de la classe CForme
 * 
 * \author Benjamin ALBOUY-KISSI
 * \date   2020
 *********************************************************************/
#include "Forme.h"

/** Pointeur vers l'afficheur à utiliser pour afficher les formes */
std::unique_ptr<IAfficheur> CForme::s_pAfficheur;

/**
 * \brief Définit l'afficheur à utiliser pour afficher les formes.
 * 
 * \param pAfficheur Nouvel afficheur à utiliser
 */
void CForme::setAfficheur(std::unique_ptr<IAfficheur>& pAfficheur)
{
  s_pAfficheur = std::move(pAfficheur);
}
