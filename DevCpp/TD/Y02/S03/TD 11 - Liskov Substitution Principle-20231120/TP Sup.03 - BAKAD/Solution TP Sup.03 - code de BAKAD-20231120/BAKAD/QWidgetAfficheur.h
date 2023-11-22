/*****************************************************************//**
 * \file   QWidgetAfficheur.h
 * \brief  Déclaration de la classe Qt QWidgetAfficheur
 * 
 * \author Benjamin ALBOUY-KISSI
 * \date   2020
 *********************************************************************/
#pragma once
#include <QWidget>
#include "Afficheur.h"

class CAfficheurQPicture;

/**
 * \brief Classe de QWidget personnalisé pour afficher les formes décrites dans un
 * objet de type CAfficheurQPicture.
 * 
 * Pour utiliser cette classe, il faut associer son instance à un objet 
 * CAfficheurQPicture. Cela peut être fait en utilisant la méthode setAfficheur 
 * ou en passant en paramètre du constructeur de l'objet CAfficheurQPicture 
 * l'adresse de cette instance.
 * 
 * \see CAfficheurQPicture | CAfficheurQPicture::CAfficheurQPicture(QWidgetAfficheur*)
 */
class QWidgetAfficheur : public QWidget
{
  Q_OBJECT

  CAfficheurQPicture* m_pAfficheur = nullptr;///< Pointeur vers l'objet CAfficheurQPicture qui contient le dessin à afficher

public:
  QWidgetAfficheur(QWidget *parent = nullptr);

  /**
   * \brief Accesseur en écriture vers m_pAfficheur.
   * 
   * \param pAfficheur Nouvelle valeur de m_pAfficheur.
   */
  void setAfficheur(CAfficheurQPicture* pAfficheur) {
    m_pAfficheur = pAfficheur;
  }

protected:
  void paintEvent(QPaintEvent* evt) override;
};
