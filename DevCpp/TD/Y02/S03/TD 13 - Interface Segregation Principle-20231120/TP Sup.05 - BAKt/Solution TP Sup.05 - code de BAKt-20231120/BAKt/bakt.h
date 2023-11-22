#ifndef INOUT_H
#define INOUT_H

#include <QtWidgets/QWidget>
#include <QPixmap>
#include <memory>
#include "EventManager.h"
#include "MagicBall.h"
#include "VeryMagicBall.h"
#include "PifPaf.h"

class CBAKt : public QWidget
{
  Q_OBJECT

  //Solution
  CMouseManager m_MouseMgr;
  CTickManager m_TickMgr;
  CKeyboardManager m_KeyboardMgr;
  //Fin Solution
  std::shared_ptr<CMagicBall> m_pMagicBall;
  std::shared_ptr<CVeryMagicBall> m_pVeryMagicBall;
  std::shared_ptr<CPifPaf> m_pPifPaf;

  QPixmap m_pixBall;
  QPixmap m_pixPifPafLeft;
  QPixmap m_pixPifPafRight;
  QPixmap m_pixPifPafEye;
  int m_nTimerId;

public:
  CBAKt(QWidget *parent = 0);
  ~CBAKt();

protected:
  void paintEvent(QPaintEvent* evt) override;
  void keyPressEvent(QKeyEvent* evt) override;
  void keyReleaseEvent(QKeyEvent* evt) override;
  void mouseMoveEvent(QMouseEvent * evt) override;
  void mousePressEvent(QMouseEvent * evt) override;
  void mouseReleaseEvent(QMouseEvent * evt) override;
  void timerEvent(QTimerEvent * evt) override;
  void resizeEvent(QResizeEvent * evt) override;
public slots:

};

#endif // INOUT_H
