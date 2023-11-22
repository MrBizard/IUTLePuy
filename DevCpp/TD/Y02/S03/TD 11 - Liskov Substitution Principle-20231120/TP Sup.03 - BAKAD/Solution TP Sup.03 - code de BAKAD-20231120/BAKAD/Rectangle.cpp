/*****************************************************************//**
 * \file   Rectangle.cpp
 * \brief  Définition de la classe CRectangle
 * 
 * \author Benjamin ALBOUY-KISSI
 * \date   2020
 *********************************************************************/
#include "Rectangle.h"

/**
 * \brief Délègue l'affichage du rectangle à l'objet pointé par CForme::s_pAfficheur.
 */
void CRectangle::afficher() const
{
  s_pAfficheur->rectangle(*this);
}
