#include "playscreen.h"
#include "Position2D.h"
#include <QPainter>
#include <QKeyEvent>
#include <QMessageBox>
#include <array>

CPlayScreen::CPlayScreen(QWidget *parent)
  : QWidget(parent)
  , m_mdlDecor(CMdlQPainter2D::create(m_painter, m_pixDecor, QSize(50,50)))
  , m_mdlJoueur(CMdlQPainter2D::create(m_painter, m_pixJoueur, QSize(9,9)))
  , m_mdlMonstre(CMdlQPainter2D::create(m_painter, m_pixMonstre, QSize(9,9)))
  //Solution
  , m_pJoueur(CJoueurNormal::create(CPosition2D::create(25,25), m_mdlJoueur))
  , m_pMonstre1(CMonstreGluant::create(CPosition2D::create(10, 10), m_mdlMonstre))
  , m_pMonstre2(CMonstreGluant::create(CPosition2D::create(10, 40), m_mdlMonstre))
  , m_pMonstre3(CMonstreGluant::create(CPosition2D::create(40, 10), m_mdlMonstre))
  , m_pMonstre4(CMonstreGluant::create(CPosition2D::create(40, 40), m_mdlMonstre))
  /*
  //Fin Solution
  , m_pJoueur(CJoueurNormal::create(m_mdlJoueur))
  , m_pMonstre1(CMonstreGluant::create(m_mdlMonstre))
  , m_pMonstre2(CMonstreGluant::create(m_mdlMonstre))
  , m_pMonstre3(CMonstreGluant::create(m_mdlMonstre))
  , m_pMonstre4(CMonstreGluant::create(m_mdlMonstre))
  //Solution
  */
  //Fin Solution
    , m_ia1(m_pMonstre1, m_pJoueur, 8, 20.0)
    , m_ia2(m_pMonstre2, m_pJoueur, 8, 20.0)
    , m_ia3(m_pMonstre3, m_pJoueur, 8, 20.0)
    , m_ia4(m_pMonstre4, m_pJoueur, 8, 20.0)
{
  ui.setupUi(this);
  m_pixDecor = QPixmap(":/Images/Decor.png");
  m_pixMonstre = QPixmap(":/Images/Monstre.png");
  m_pixJoueur = QPixmap(":/Images/Joueur.png");

  //Solution
  CDecor::ptr decor = CDecor::create(CPosition2D::create(50,50), CPosition2D::create(10,10), m_mdlDecor); 
  /*
  //Fin Solution
  CDecor::ptr decor = CDecor::create(m_mdlDecor);
  //Solution
  */
  //Fin Solution
  m_pMonde = new CMonde(decor, this);
  m_pMonde->addJoueur (m_pJoueur);
  m_pMonde->addMonstre(m_pMonstre1);
  m_pMonde->addMonstre(m_pMonstre2);
  m_pMonde->addMonstre(m_pMonstre3);
  m_pMonde->addMonstre(m_pMonstre4);

  connect(m_pMonde, &CMonde::JoueurMort, this, &CPlayScreen::JoueurMort);
  connect(m_pMonde, &CMonde::JoueurGagne, this, &CPlayScreen::JoueurGagne);
  connect(m_pMonde, &CMonde::MonstreMort, this, &CPlayScreen::MonstreMort);
}

CPlayScreen::~CPlayScreen()
{
}

void CPlayScreen::paintEvent(QPaintEvent* evt)
{
  m_painter.begin(this);

  m_painter.setWindow(0,0,50,50);

  m_pMonde->afficher();

  m_painter.end();
}

void CPlayScreen::keyPressEvent(QKeyEvent* evt)
{
  switch(evt->key())
  {
    //Solution
  case Qt::Key_Up:
    m_pJoueur->deplacer(CPosition2D::create(0, -1), m_pJoueur->getVie()/10.0);
    break;
  case Qt::Key_Down:
    m_pJoueur->deplacer(CPosition2D::create(0, 1), m_pJoueur->getVie()/10.0);
    break;
  case Qt::Key_Left:
    m_pJoueur->deplacer(CPosition2D::create(-1, 0), m_pJoueur->getVie()/10.0);
    break;
  case Qt::Key_Right:
    m_pJoueur->deplacer(CPosition2D::create(1, 0), m_pJoueur->getVie()/10.0);
    break;
    //Fin Solution
  default:
    QWidget::keyPressEvent(evt);
    return;
  }
  m_ia1.agir();
  m_ia2.agir();
  m_ia3.agir();
  m_ia4.agir();

  //Solution
  std::array<std::shared_ptr<CPersonnage>, 5> persos = { m_pJoueur, m_pMonstre1, m_pMonstre2, m_pMonstre3, m_pMonstre4 };

  for (auto& perso : persos)
  {
    auto pos = static_pointer_cast<CPosition2D>(perso->getPos()->clone());
    auto taille = static_pointer_cast<const CPosition2D>(m_pMonde->getDecor()->getTaille());
    if (pos->getX() > taille->getX()) pos->setX(taille->getX());
    if (pos->getY() > taille->getY()) pos->setY(taille->getY());
    if (pos->getX() < 0) pos->setX(0);
    if (pos->getY() < 0) pos->setY(0);
    perso->setPos(pos);
  }
  //Fin Solution
  m_pMonde->interactions();
  update();
}

void CPlayScreen::JoueurMort(CJoueur::const_ptr joueur)
{
  QMessageBox::information(this, "Game Over", "Vous avez perdu ! Mouahahaha !");
}

void CPlayScreen::JoueurGagne(CJoueur::const_ptr joueur)
{
  QMessageBox::information(this, "Game Over", "Vous avez gagné ! Félicitation !");
}

void CPlayScreen::MonstreMort(CMonstre::const_ptr monstre)
{
  QMessageBox::information(this, "BAKaway", "Vous venez de tuer un monstre, mais perdez un point de vie...");
}
