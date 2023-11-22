#ifndef QCADREDESSIN_H
#define QCADREDESSIN_H

#include <QFrame>
#include <QPainter>

class QCadreDessin : public QFrame
{
  Q_OBJECT

  qreal m_rRotation;
  qreal m_rEchelleX;
  qreal m_rEchelleY;
  qreal m_rCisaillementH;
  qreal m_rCisaillementV;
  qreal m_rTransX;
  qreal m_rTransY;
  QPainter::RenderHints m_fRenderHints;
  QPixmap m_pixLapin;
  QPixmap m_pixFond;
  QPixmap m_pixFondFullRes;
  QFont m_fntTitle;
  QFont m_fntSubTitle;

  void refreshBackground();

public:
    QCadreDessin(QWidget *parent);
    ~QCadreDessin();

protected:
  virtual void paintEvent(QPaintEvent * ) ;
  virtual void resizeEvent(QResizeEvent * );

public slots:
  void setRotation(int nDegree);
  void setEchelleX(int nPourcent);
  void setEchelleY(int nPourcent);
  void setCisaillementH(int nVal);
  void setCisaillementV(int nVal);
  void setTransX(int nVal);
  void setTransY(int nVal);
  void setAntialiasPrim(bool bEnable);
  void setAntialiasText(bool bEnable);
  void setAntialiasImg(bool bEnable);
private:
    
};

#endif // QCADREDESSIN_H
