/*****************************************************************//**
 * \file   Carre.h
 * \brief  Déclaration de la classe CCarre
 * 
 * \author Benjamin ALBOUY-KISSI
 * \date   2020
 *********************************************************************/
#pragma once
#include "Forme.h"

//Version 1 : le carré hérite du rectangle
//#include "Rectangle.h"
//
//class CCarre : public CRectangle
//{
//public:
//  CCarre(int cote);
//
//  void setLargeur(int cote) override;
//  void setHauteur(int cote) override;
//
//  int getCote() const { return getHauteur(); }
//
//  void afficher() const override;
//};

//Version 2 : le carré hérite directement de la forme

/**
 * \brief Gestion d'un carré.
 */
class CCarre : public CForme
{
  int m_cote; ///< Dimension du côté du carré
public:
  CCarre(int cote);

  /**
   * Accesseur en lecture vers la dimension du côté du carré.
   * 
   * \return La dimension du côté du carré.
   */
  int getCote() const { return m_cote; }

  /**
   * Accesseur en écriture vers la dimension du côté du carré.
   * 
   * \param nCote La nouvelle dimension du côté du carré.
   */
  void setCote(int nCote) { m_cote = nCote; }

  void afficher() const override;
};