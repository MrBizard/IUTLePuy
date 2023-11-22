/*****************************************************************//**
 * \file   AfficheurQPicture.h
 * \brief  Déclaration de la classe CAfficheurQPicture
 * 
 * \author Benjamin ALBOUY-KISSI
 * \date   2020
 *********************************************************************/
#pragma once
#include "Afficheur.h"
#include <QPicture>
#include <QPainter>
#include "QWidgetAfficheur.h"

/**
 * \brief Classe d'affichage des formes en utilisant Qt.
 * 
 * Le principe de cette classe est de faire le rendu en mémoire dans un QPicture.
 * Ce QPicture peut ensuite être affiché dans un QPaintDevice (par exemple un QWidget
 * au moment de son paintEvent) en appelant la fonction drawIt.
 */
class CAfficheurQPicture :
    public IAfficheur
{
  QPicture m_picture; ///< Objet QPicture utilisé pour enregistrer le dessin
  QPainter m_painter; ///< Objet QPainter utilisé pour dessiner dans le QPicture m_picture
  void rectangle(const CRectangle& rect) override;
  void ellipse(const CEllipse& ellipse) override;
  void carre(const CCarre& carre) override;
  void cercle(const CCercle& cercle) override;

public:
  /**
   * \brief Constructeur par défaut.
   */
  CAfficheurQPicture() = default;
  /**
   * \brief Constructeur permettant d'associer cette instance avec un objet
   * QWidgetAfficheur.
   * 
   * \param waf Pointeur vers l'objet QWidgetAfficheur à associer
   */
  CAfficheurQPicture(QWidgetAfficheur* waf) {
    waf->setAfficheur(this);
  }

  /**
   * \brief Affiche le dessin enregistré en mémoire en utilisant un QPainter particulier.
   */
  void drawIt(QPainter* painter);
};

