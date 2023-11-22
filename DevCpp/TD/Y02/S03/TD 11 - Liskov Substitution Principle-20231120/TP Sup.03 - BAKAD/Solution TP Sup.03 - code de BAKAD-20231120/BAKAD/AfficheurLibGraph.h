/*****************************************************************//**
 * \file   AfficheurLibGraph.h
 * \brief  Déclaration de la classe CAfficheurLibGraph
 * 
 * \author Benjamin ALBOUY-KISSI
 * \date   2020
 *********************************************************************/
#pragma once
#include "Afficheur.h"
#include <LibGraph2.h>

/**
 * \brief Classe d'affichage en utilisant l'excellentissime bibliothèque LibGraph2.
 * 
 * \see https://gitlab-lepuy.iut-clermont.uca.fr/bealbouy/libGraph
 */
class CAfficheurLibGraph :
    public IAfficheur
{
  LibGraph2::ILibGraph2* m_pLibGraph = nullptr; ///< Pointeur vers l'objet principal de LibGraph
public:
  /**
   * \brief Constructeur.
   * 
   * \param pLibGraph Doit pointer vers l'objet principal de LibGraph2
   */
  CAfficheurLibGraph(LibGraph2::ILibGraph2* pLibGraph)
    : m_pLibGraph{ pLibGraph }
  {}

private:
  void rectangle(const CRectangle& rect) override;
  void ellipse(const CEllipse& ellipse) override;
  void carre(const CCarre& carre) override;
  void cercle(const CCercle& cercle) override;
};

