/*****************************************************************//**
 * \file   AfficheurConsole.h
 * \brief  Déclaration de la classe CAfficheurConsole
 * 
 * \author Benjamin ALBOUY-KISSI
 * \date   2020
 *********************************************************************/
#pragma once
#include "Afficheur.h"

/**
 * \brief Classe d'affichage des formes en mode console.
 */
class CAfficheurConsole : public IAfficheur
{
  void rectangle(const CRectangle& rect) override;
  void ellipse(const CEllipse& ellipse) override;
  void carre(const CCarre& carre) override;
  void cercle(const CCercle& cercle) override;
};
