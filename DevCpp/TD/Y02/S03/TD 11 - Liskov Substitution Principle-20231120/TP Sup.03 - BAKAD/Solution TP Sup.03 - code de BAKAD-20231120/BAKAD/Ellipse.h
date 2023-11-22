/*****************************************************************//**
 * \file   Ellipse.h
 * \brief  Déclaration de la classe CEllipse
 * 
 * \author Benjamin ALBOUY-KISSI
 * \date   2020
 *********************************************************************/
#pragma once
#include "Forme.h"

/**
 * \brief Classe de gestion d'une ellipse.
 */
class CEllipse :
  public CForme
{
  int m_nAxeHorizontal; ///< Dimension de l'axe horizontal de l'ellipse
  int m_nAxeVertical;   ///< Dimension de l'axe vertical de l'ellipse
public:
  /**
   * \brief Constructeur.
   * 
   * \param nAxeHorizontal Dimension de l'axe horizontal de l'ellipse
   * \param nAxeVertical Dimension de l'axe vertical de l'ellipse
   */
  CEllipse(int nAxeHorizontal, int nAxeVertical)
    : m_nAxeHorizontal(nAxeHorizontal)
    , m_nAxeVertical(nAxeVertical)
  {}

  void afficher() const override;

  /**
   * \brief Accesseur en lecture vers la dimension de l'axe horizontal de l'ellipse.
   * 
   * \return la dimension de l'axe horizontal de l'ellipse.
   */
  virtual int getAxeHorizontal() const { return m_nAxeHorizontal; }

  /**
   * \brief Accesseur en lecture vers la dimension de l'axe vertical de l'ellipse.
   *
   * \return la dimension de l'axe vertical de l'ellipse.
   */
  virtual int getAxeVertical() const { return m_nAxeVertical; }
};

