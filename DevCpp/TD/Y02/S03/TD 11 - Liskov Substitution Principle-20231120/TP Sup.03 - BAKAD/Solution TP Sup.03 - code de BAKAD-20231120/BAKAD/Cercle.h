/*****************************************************************//**
 * \file   Cercle.h
 * \brief  Déclaration de la classe CCercle
 * 
 * \author Benjamin ALBOUY-KISSI
 * \date   2020
 *********************************************************************/
#pragma once
#include "Forme.h"

//Version 1 : le cercle hérite de l'ellipse
//#include "Ellipse.h"
//
//class CCercle : public CEllipse
//{
//public:
//  CCercle(int rayon);
//
//  int getRayon() const { return getAxeHorizontal(); }
//
//  void afficher() const override;
//};

//Version 2 : le cercle hérite directement de la forme
/**
 * \brief Classe de gestion d'un cercle.
 */
class CCercle : public CForme
{
  int m_rayon; ///< Dimension du rayon du cercle
public:
  CCercle(int rayon);

  /**
   * \brief Accesseur en lecture vers la dimension du rayon du cercle.
   * 
   * \return La dimension du rayon du cercle
   */
  int getRayon() const { return m_rayon; }

  void afficher() const override;
};