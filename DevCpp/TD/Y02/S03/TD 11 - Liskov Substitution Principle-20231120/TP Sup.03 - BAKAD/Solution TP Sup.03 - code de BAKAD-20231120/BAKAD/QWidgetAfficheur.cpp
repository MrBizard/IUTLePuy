/*****************************************************************//**
 * \file   QWidgetAfficheur.cpp
 * \brief  Définition de la classe QWidgetAfficheur
 * 
 * \author Benjamin ALBOUY-KISSI
 * \date   2020
 *********************************************************************/
#include "QWidgetAfficheur.h"
#include "AfficheurQPicture.h"
#include <QPainter>

/**
 * Constructeur.
 * 
 * \param parent Pointeur vers le QWidget parent ou nullptr si aucun.
 */
QWidgetAfficheur::QWidgetAfficheur(QWidget *parent)
    : QWidget(parent)
{
}

/**
 * \brief Surcharge de l'événement paintEvent.
 * 
 * Affiche les formes enregistrées dans l'objet CAfficheurQPicture m_pAfficheur 
 * dans un repère de 100 x 100 dont l'origine est centrée.
 * 
 * \param evt Description de l'événement - ignoré
 */
void QWidgetAfficheur::paintEvent(QPaintEvent*)
{
  QPainter painter(this);

  painter.setWindow(-50, -50, 100, 100);
  if (m_pAfficheur)
  {
    m_pAfficheur->drawIt(&painter);
  }
}
