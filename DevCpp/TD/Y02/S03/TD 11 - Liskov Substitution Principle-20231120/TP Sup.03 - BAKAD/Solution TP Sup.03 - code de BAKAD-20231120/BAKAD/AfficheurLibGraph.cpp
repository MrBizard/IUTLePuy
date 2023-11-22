/*****************************************************************//**
 * \file   AfficheurLibGraph.cpp
 * \brief  Définition de la classe CAfficheurLibGraph
 * 
 * \author Benjamin ALBOUY-KISSI
 * \date   2020
 *********************************************************************/
#include "AfficheurLibGraph.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Carre.h"
#include "Cercle.h"

/**
 * \brief Affiche les informations d'un rectangle en utilisant libGraph.
 *
 * L'affichage consiste à afficher un rectangle centré au milieu de la fenêtre 
 * en utilisant les attributs d'affichage (pinceau et brosse) courrants.
 *
 * \param rect Rectangle à afficher
 */
void CAfficheurLibGraph::rectangle(const CRectangle& rect)
{
  LibGraph2::CPoint ptCenter{
    m_pLibGraph->getSize().m_fWidth / 2.0f,
    m_pLibGraph->getSize().m_fHeight / 2.0f
  };
  m_pLibGraph->drawRectangle(
    LibGraph2::CRectangle(
      { ptCenter - LibGraph2::CPoint(rect.getLargeur() / 2.0f, rect.getHauteur() / 2.0f) },
      LibGraph2::CSize(rect.getLargeur(), rect.getHauteur())
    )
  );
}

/**
 * \brief Affiche les informations d'une ellipse en utilisant libGraph.
 *
 * L'affichage consiste à afficher une ellipse centrée au milieu de la fenêtre
 * en utilisant les attributs d'affichage (pinceau et brosse) courrants.
 *
 * \param ellipse Ellipse à afficher
 */
void CAfficheurLibGraph::ellipse(const CEllipse& ellipse)
{
  LibGraph2::CPoint ptCenter{
    m_pLibGraph->getSize().m_fWidth / 2.0f,
    m_pLibGraph->getSize().m_fHeight / 2.0f
  };
  m_pLibGraph->drawEllipse(
    LibGraph2::CRectangle(
      { ptCenter - LibGraph2::CPoint(ellipse.getAxeHorizontal() / 2.0f, ellipse.getAxeVertical() / 2.0f) },
      LibGraph2::CSize(ellipse.getAxeHorizontal(), ellipse.getAxeVertical())
    )
  );
}

/**
 * \brief Affiche les informations d'un carré en utilisant libGraph.
 *
 * L'affichage consiste à afficher un carré centré au milieu de la fenêtre
 * en utilisant les attributs d'affichage (pinceau et brosse) courrants.
 *
 * \param carre Carré à afficher
 */
void CAfficheurLibGraph::carre(const CCarre& carre)
{
  LibGraph2::CPoint ptCenter{
    m_pLibGraph->getSize().m_fWidth / 2.0f,
    m_pLibGraph->getSize().m_fHeight / 2.0f
  };
  m_pLibGraph->drawRectangle(
    LibGraph2::CRectangle(
      { ptCenter - LibGraph2::CPoint(carre.getCote() / 2.0f, carre.getCote() / 2.0f) },
      LibGraph2::CSize(carre.getCote(), carre.getCote())
    )
  );
}

/**
 * \brief Affiche les informations d'un cercle en utilisant libGraph.
 *
 * L'affichage consiste à afficher un cercle centré au milieu de la fenêtre
 * en utilisant les attributs d'affichage (pinceau et brosse) courrants.
 *
 * \param cercle Cercle à afficher
 */
void CAfficheurLibGraph::cercle(const CCercle& cercle)
{
  LibGraph2::CPoint ptCenter{
    m_pLibGraph->getSize().m_fWidth / 2.0f,
    m_pLibGraph->getSize().m_fHeight / 2.0f
  };
  m_pLibGraph->drawEllipse(
    LibGraph2::CRectangle(
      { ptCenter - LibGraph2::CPoint(cercle.getRayon(), cercle.getRayon()) },
      LibGraph2::CSize(cercle.getRayon()*2.0f, cercle.getRayon()*2.0f)
    )
  );
}
