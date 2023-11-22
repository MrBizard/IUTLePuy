/*****************************************************************//**
 * \file   Carre.cpp
 * \brief  Définition de la classe CCarre
 * 
 * \author Benjamin ALBOUY-KISSI
 * \date   2020
 *********************************************************************/
#include "Carre.h"

/**
 * \brief Délègue l'affichage du carré à l'objet pointé par CForme::s_pAfficheur.
 */
void CCarre::afficher() const
{
  s_pAfficheur->carre(*this);
}

//Version 1 : le carré hérite du rectangle
//CCarre::CCarre(int cote)
//  : CRectangle(cote, cote)
//{
//}
//
//void CCarre::setLargeur(int cote)
//{
//  CRectangle::setHauteur(cote);
//  CRectangle::setLargeur(cote);
//}
//
//void CCarre::setHauteur(int cote)
//{
//  CRectangle::setHauteur(cote);
//  CRectangle::setLargeur(cote);
//}

//Version 2 : le carré hérite directement de la forme
/**
 * Constructeur.
 * 
 * \param cote Dimension du côté du carré à créer.
 */
CCarre::CCarre(int cote)
  : m_cote(cote)
{
}