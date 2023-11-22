/*****************************************************************//**
 * \file   Ellipse.cpp
 * \brief  Définition de la classe CEllipse
 * 
 * \author Benjamin ALBOUY-KISSI
 * \date   2020
 *********************************************************************/
#include "Ellipse.h"

/**
 * \brief Délègue l'affichage de l'ellipse à l'objet pointé par CForme::s_pAfficheur.
 */
void CEllipse::afficher() const
{
  s_pAfficheur->ellipse(*this);
}
