/*****************************************************************//**
 * \file   AfficheurConsole.cpp
 * \brief  Définition de la classe CAfficheurConsole
 * 
 * \author Benjamin ALBOUY-KISSI
 * \date   2020
 *********************************************************************/
#include "AfficheurConsole.h"
#include <iostream>
#include "Rectangle.h"
#include "Ellipse.h"
#include "Carre.h"
#include "Cercle.h"

/**
 * \brief Affiche les informations d'un rectangle dans la console.
 * 
 * L'affichage consiste à afficher un message de la forme
 * <tt>Rectangle de largeur x hauteur = w x h</tt>
 * 
 * \param rect Rectangle à afficher
 */
void CAfficheurConsole::rectangle(const CRectangle& rect)
{
  std::cout << "Rectangle de largeur x hauteur = " << rect.getLargeur() << " x " << rect.getHauteur() << "\n";
}

/**
 * \brief Affiche les informations d'une ellipse dans la console.
 *
 * L'affichage consiste à afficher un message de la forme
 * <tt>Ellipse d'axes horizontal x vertical = w x h</tt>
 *
 * \param ellipse Ellipse à afficher
 */
void CAfficheurConsole::ellipse(const CEllipse& ellipse)
{
  std::cout << "Ellipse d'axes horizontal x vertical = " << ellipse.getAxeHorizontal() << " x " << ellipse.getAxeVertical() << "\n";
}

/**
 * \brief Affiche les informations d'un carré dans la console.
 *
 * L'affichage consiste à afficher un message de la forme
 * <tt>Carré de côté = c</tt>
 *
 * \param carre Carré à afficher
 */
void CAfficheurConsole::carre(const CCarre& carre)
{
  std::cout << "Carré de côté = " << carre.getCote() << "\n";
}

/**
 * \brief Affiche les informations d'un cercle dans la console.
 *
 * L'affichage consiste à afficher un message de la forme
 * <tt>Cercle de rayon = r</tt>
 *
 * \param cercle Cercle à afficher
 */
void CAfficheurConsole::cercle(const CCercle& cercle)
{
  std::cout << "Cercle de rayon " << cercle.getRayon() << "\n";
}
