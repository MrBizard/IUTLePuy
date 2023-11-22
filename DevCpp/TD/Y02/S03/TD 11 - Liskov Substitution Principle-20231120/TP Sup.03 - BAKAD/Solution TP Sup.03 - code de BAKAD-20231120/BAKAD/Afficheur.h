/*****************************************************************//**
 * \file   Afficheur.h
 * \brief  Déclaration de la classe d'interface IAfficheur
 * 
 * \author Benjamin ALBOUY-KISSI
 * \date   2020
 *********************************************************************/
#pragma once

class CForme;
class CRectangle;
class CEllipse;
class CCarre;
class CCercle;

/**
 * \brief Interface de tous les afficheurs.
 * 
 * Cette interface décrit tous les afficheurs. 
 * Les afficheurs doivent implémenter l'ensemble des fonctions de l'interface.
 */
class IAfficheur
{
public:
  /**
   * \brief Affiche un rectangle.
   * 
   * \param rect Rectangle à afficher.
   */
  virtual void rectangle(const CRectangle& rect) = 0;

  /**
   * \brief Affiche une ellipse.
   *
   * \param ellipse Ellipse à afficher.
   */
  virtual void ellipse(const CEllipse& ellipse) = 0;

  /**
   * \brief Affiche un carré.
   *
   * \param carre Carré à afficher.
   */
  virtual void carre(const CCarre & carre) = 0;

  /**
   * \brief Affiche un cercle.
   *
   * \param cercle Cercle à afficher.
   */
  virtual void cercle(const CCercle & cercle) = 0;
};

