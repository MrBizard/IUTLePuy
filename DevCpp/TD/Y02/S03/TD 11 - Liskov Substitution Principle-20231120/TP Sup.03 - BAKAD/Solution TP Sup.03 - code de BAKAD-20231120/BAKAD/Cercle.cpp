/*****************************************************************//**
 * \file   Cercle.cpp
 * \brief  Définition de la classe CCercle
 * 
 * \author Benjamin ALBOUY-KISSI
 * \date   2020
 *********************************************************************/
#include "Cercle.h"

/**
 * \brief Délègue l'affichage du cercle à l'objet pointé par CForme::s_pAfficheur.
 */
void CCercle::afficher() const
{
  s_pAfficheur->cercle(*this);
}

//Version 1 : le cercle hérite de l'ellipse
//CCercle::CCercle(int rayon)
//  : CEllipse(rayon, rayon)
//{
//}

//Version 2 : le cercle hérite directement de la forme
/**
 * Constructeur.
 *
 * \param rayon Dimension du rayon du cercle à créer.
 */
CCercle::CCercle(int rayon)
  : m_rayon(rayon)
{
}
