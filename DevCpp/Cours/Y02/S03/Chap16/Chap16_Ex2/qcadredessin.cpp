#include "qcadredessin.h"
#include <QDebug>
#include <QFontDatabase>

QCadreDessin::QCadreDessin(QWidget *parent)
  : QFrame(parent)
  , m_rRotation(0)
  , m_rEchelleX(1)
  , m_rEchelleY(1)
  , m_rCisaillementH(0)
  , m_rCisaillementV(0)
  , m_rTransX(0)
  , m_rTransY(0)
  , m_fRenderHints(0)
{
  m_pixLapin = QPixmap(":/Images/lapin.png");
  m_pixFondFullRes = QPixmap(":/Images/fond.png");

  QFontDatabase fntDatabase;
  const QStringList families = fntDatabase.families();
  if (families.contains("Segoe UI"))
  {
    m_fntTitle.setFamily("Segoe UI");
    m_fntSubTitle.setFamily("Segoe UI");
  }
  else if (families.contains("Calibri"))
  {
    m_fntTitle.setFamily("Calibri");
    m_fntSubTitle.setFamily("Calibri");
  }
  else if (families.contains("Arial"))
  {
    m_fntTitle.setFamily("Arial");
    m_fntSubTitle.setFamily("Arial");
  }
  else if (families.contains("Helvetica"))
  {
    m_fntTitle.setFamily("Helvetica");
    m_fntSubTitle.setFamily("Helvetica");
  }
  else
  {
    m_fntTitle.setFamily("sans-serif");
    m_fntSubTitle.setFamily("sans-serif");
  }
  m_fntTitle.setPointSize(18);
  m_fntTitle.setBold(true);
  m_fntSubTitle.setPointSize(6);
  m_fntSubTitle.setBold(true);
}

void QCadreDessin::refreshBackground()
{
  m_pixFond = m_pixFondFullRes.scaled(this->size(), Qt::KeepAspectRatio,
    m_fRenderHints.testFlag(QPainter::SmoothPixmapTransform) ? Qt::SmoothTransformation : Qt::FastTransformation);
}

QCadreDessin::~QCadreDessin()
{

}

void QCadreDessin::setRotation(int nDegree)
{
  m_rRotation = nDegree;
  this->update();
}

void QCadreDessin::setEchelleX(int nPourcent)
{
  m_rEchelleX = nPourcent / 100.0;
  this->update();
}

void QCadreDessin::setEchelleY(int nPourcent)
{
  m_rEchelleY = nPourcent / 100.0;
  this->update();
}

void QCadreDessin::setCisaillementH(int nVal)
{
  m_rCisaillementH = nVal / 10.0;
  this->update();
}

void QCadreDessin::setCisaillementV(int nVal)
{
  m_rCisaillementV = nVal / 10.0;
  this->update();
}

void QCadreDessin::setTransX(int nVal)
{
  m_rTransX = nVal;
  this->update();
}

void QCadreDessin::setTransY(int nVal)
{
  m_rTransY = nVal;
  this->update();
}

void QCadreDessin::setAntialiasPrim(bool bEnable)
{
  m_fRenderHints.setFlag(QPainter::Antialiasing, bEnable);
  this->update();
}

void QCadreDessin::setAntialiasText(bool bEnable)
{
  m_fRenderHints.setFlag(QPainter::TextAntialiasing, bEnable);
  this->update();
}

void QCadreDessin::setAntialiasImg(bool bEnable)
{
  m_fRenderHints.setFlag(QPainter::SmoothPixmapTransform, bEnable);
  refreshBackground();
  this->update();
}

void QCadreDessin::resizeEvent(QResizeEvent * evt)
{
  refreshBackground();
  QFrame::resizeEvent(evt);
}

void QCadreDessin::paintEvent(QPaintEvent * evt)
{
  //Dessiner dans le widget
  QPainter painter(this);

  painter.setRenderHints(m_fRenderHints);

  painter.drawPixmap((this->width() - m_pixFond.width()) / 2.0, (this->height() - m_pixFond.height()) / 2.0, m_pixFond);

  painter.setFont(m_fntTitle);
  painter.drawText(QRect(0,0,this->width(),this->height()/10), Qt::AlignCenter, "Happy Rabbit");

  painter.setPen(QColor(255,0,0));
  QRadialGradient degrade(15,15,15);
  degrade.setColorAt(0, QColor(255,0,0));
  degrade.setColorAt(1, QColor(255,255,0));
  painter.setBrush(QBrush(degrade));
  painter.setBrushOrigin(8,this->height()/20-15);
  painter.drawEllipse(8,this->height()/20-15,30,30);
  painter.setBrushOrigin(this->width()-8-30,this->height()/20-15);
  painter.drawEllipse(this->width()-8-30,this->height()/20-15,30,30);



  int side =qMin(this->width(), this->height());
  int x = (this->width() - side) /2;
  int y = (this->height() - side) /2;
  painter.setViewport(x, y, side, side);

  painter.setWindow(-100,-100,200,200);

  painter.translate(m_rTransX, m_rTransY);
  painter.rotate(m_rRotation);
  painter.shear(m_rCisaillementH, m_rCisaillementV);
  painter.scale(m_rEchelleX, m_rEchelleY);


  painter.drawPixmap(QRect(-50,-50,100,100), m_pixLapin);
  painter.setPen(QColor(255,0,0));
  painter.drawLine(0,0,50,0);
  painter.setPen(QColor(0,255,0));
  painter.drawLine(0,0,0,50);
  painter.setPen(QColor(0,0,255));
  painter.setBrush(Qt::NoBrush);
  painter.drawRect(QRect(-50,-50,100,100));

  painter.setFont(m_fntSubTitle);
  painter.drawText(QRect(-50,-70,100,20), Qt::AlignCenter, "J'aime les carottes");


  QFrame::paintEvent(evt);
}
