/*****************************************************************//**
 * \file   AfficheurQPicture.cpp
 * \brief  Définition de la classe CAfficheurQPicture
 * 
 * \author Benjamin ALBOUY-KISSI
 * \date   2020
 *********************************************************************/
#include "AfficheurQPicture.h"
#include <QPainter>
#include "Rectangle.h"
#include "Ellipse.h"
#include "Carre.h"
#include "Cercle.h"

 /**
  * \brief Affiche les informations d'un rectangle en utilisant Qt.
  *
  * L'affichage consiste à afficher un rectangle centré sur l'origine
  * en utilisant les attributs d'affichage (pinceau et brosse) courrants.
  *
  * \param rect Rectangle à afficher
  */
void CAfficheurQPicture::rectangle(const CRectangle& rect)
{
  if (!m_painter.isActive())
    m_painter.begin(&m_picture);
  m_painter.drawRect(
    QRectF(
      -rect.getLargeur() / 2.0,
      -rect.getHauteur() / 2.0,
      rect.getLargeur(),
      rect.getHauteur()
    )
  );
}

/**
 * \brief Affiche les informations d'une ellipse en utilisant Qt.
 *
 * L'affichage consiste à afficher une ellipse centrée sur l'origine
 * en utilisant les attributs d'affichage (pinceau et brosse) courrants.
 *
 * \param ellipse Ellipse à afficher
 */
void CAfficheurQPicture::ellipse(const CEllipse& ellipse)
{
  if (!m_painter.isActive())
    m_painter.begin(&m_picture);
  m_painter.drawEllipse(
    QRectF(
      -ellipse.getAxeHorizontal() / 2.0, 
      -ellipse.getAxeVertical() / 2.0, 
      ellipse.getAxeHorizontal(), 
      ellipse.getAxeVertical()
    )
  );
}

/**
 * \brief Affiche les informations d'un carré en utilisant Qt.
 *
 * L'affichage consiste à afficher un carré centré sur l'origine
 * en utilisant les attributs d'affichage (pinceau et brosse) courrants.
 *
 * \param carre Carré à afficher
 */
void CAfficheurQPicture::carre(const CCarre& carre)
{
  if (!m_painter.isActive())
    m_painter.begin(&m_picture);
  m_painter.drawRect(
    QRectF(
      -carre.getCote() / 2.0,
      -carre.getCote() / 2.0,
      carre.getCote(),
      carre.getCote()
    )
  );
}

/**
 * \brief Affiche les informations d'un cercle en utilisant Qt.
 *
 * L'affichage consiste à afficher un cercle centré sur l'origine
 * en utilisant les attributs d'affichage (pinceau et brosse) courrants.
 *
 * \param cercle Cercle à afficher
 */
void CAfficheurQPicture::cercle(const CCercle& cercle)
{
  if (!m_painter.isActive())
    m_painter.begin(&m_picture);
  m_painter.drawEllipse(
    QRectF(
      -cercle.getRayon(),
      -cercle.getRayon(),
      cercle.getRayon() * 2.0,
      cercle.getRayon() * 2.0
    )
  );
}

/**
 * \pre painter doit être actif, c'est-à-dire associé à un QPaintDevice
 * 
 * \param painter
 */
void CAfficheurQPicture::drawIt(QPainter* painter)
{
  if (m_painter.isActive())
    m_painter.end();
  m_picture.play(painter);
}
