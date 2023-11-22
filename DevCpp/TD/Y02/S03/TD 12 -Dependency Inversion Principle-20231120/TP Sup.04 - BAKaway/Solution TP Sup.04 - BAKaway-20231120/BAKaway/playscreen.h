#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H

#include <QtWidgets/QWidget>
#include "ui_playscreen.h"
#include "Monde.h"
#include "MdlQPainter2D.h"
#include "JoueurNormal.h"
#include "MonstreGluant.h"
#include "IA.h"

class CPlayScreen : public QWidget
{
  Q_OBJECT
  CMonde* m_pMonde;
  QPixmap m_pixMonstre;
  QPixmap m_pixJoueur;
  QPixmap m_pixDecor;
  QPainter m_painter;
  CMdlQPainter2D::ptr m_mdlDecor;
  CMdlQPainter2D::ptr m_mdlMonstre;
  CMdlQPainter2D::ptr m_mdlJoueur;
  CJoueurNormal::ptr m_pJoueur;
  CMonstreGluant::ptr m_pMonstre1;
  CMonstreGluant::ptr m_pMonstre2;
  CMonstreGluant::ptr m_pMonstre3;
  CMonstreGluant::ptr m_pMonstre4;
  CIA m_ia1;
  CIA m_ia2;
  CIA m_ia3;
  CIA m_ia4;

public:
  CPlayScreen(QWidget *parent = 0);
  ~CPlayScreen();

private:
  Ui::CPlayScreenClass ui;

protected:
  virtual void paintEvent(QPaintEvent* evt);
  virtual void keyPressEvent(QKeyEvent* evt);

public slots:
  void JoueurMort(CJoueur::const_ptr joueur);
  void JoueurGagne(CJoueur::const_ptr joueur);
  void MonstreMort(CMonstre::const_ptr monstre);

};

#endif // PLAYSCREEN_H
