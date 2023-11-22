#include "bakt.h"
#include <QPainter>
#include <QKeyEvent>

CBAKt::CBAKt(QWidget *parent)
    : QWidget(parent)
{
  setMouseTracking(true);

  m_pixBall = QPixmap(":/Images/ball.png");
  m_pixBall = m_pixBall.scaled(50,50,Qt::KeepAspectRatio, Qt::SmoothTransformation);

  m_pixPifPafLeft = QPixmap(":/Images/dog_left.png");
  m_pixPifPafLeft = m_pixPifPafLeft.scaled(200,200,Qt::KeepAspectRatio, Qt::SmoothTransformation);
  m_pixPifPafRight = QPixmap(":/Images/dog_right.png");
  m_pixPifPafRight = m_pixPifPafRight.scaled(200,200,Qt::KeepAspectRatio, Qt::SmoothTransformation);
  m_pixPifPafEye = QPixmap(":/Images/dog_eye.png");
  m_pixPifPafEye = m_pixPifPafEye.scaled(24,24,Qt::KeepAspectRatio, Qt::SmoothTransformation);

  m_pMagicBall = std::make_shared<CMagicBall>(50);
  m_pVeryMagicBall = std::make_shared<CVeryMagicBall>(50);
  m_pPifPaf = std::make_shared<CPifPaf>();

  m_pPifPaf->setSize(m_pixPifPafLeft.width(), m_pixPifPafLeft.height());

  //Solution
  m_MouseMgr.registerListener(m_pMagicBall);
  m_MouseMgr.registerListener(m_pVeryMagicBall);
  m_TickMgr.registerListener(m_pVeryMagicBall);
  m_MouseMgr.registerListener(m_pPifPaf);
  m_KeyboardMgr.registerListener(m_pPifPaf);
  //Fin Solution

  m_nTimerId = startTimer(20);
}

CBAKt::~CBAKt()
{
}

void CBAKt::timerEvent(QTimerEvent * evt)
{
  if(evt->timerId() == m_nTimerId)
  {
    CTickEvent tick;
    //Solution
    m_TickMgr.notifyEvent(tick);
    //Fin Solution
    update();
  }
}

void CBAKt::paintEvent(QPaintEvent* evt)
{
  QPainter painter(this);

  painter.setRenderHints(QPainter::Antialiasing|QPainter::SmoothPixmapTransform);

  painter.save();
  painter.translate(m_pMagicBall->x(), m_pMagicBall->y());
  painter.rotate(m_pMagicBall->angle());
  painter.translate(m_pMagicBall->radius(), 0);
  painter.drawPixmap(-25, -25, m_pixBall);
  painter.restore();

  painter.save();
  painter.translate(m_pVeryMagicBall->x(), m_pVeryMagicBall->y());
  painter.rotate(m_pVeryMagicBall->angle());
  painter.translate(m_pVeryMagicBall->radius(), 0);
  painter.drawPixmap(-25,-25, m_pixBall);
  painter.restore();

  if(m_pPifPaf->isTurningLeft())
    painter.drawPixmap(m_pPifPaf->getPosX(), m_pPifPaf->getPosY(), m_pixPifPafLeft);
  else
    painter.drawPixmap(m_pPifPaf->getPosX(), m_pPifPaf->getPosY(), m_pixPifPafRight);
  painter.drawPixmap(m_pPifPaf->getLeftEyeX()-m_pixPifPafEye.width()/2, m_pPifPaf->getLeftEyeY()-m_pixPifPafEye.width()/2, m_pixPifPafEye);
  painter.drawPixmap(m_pPifPaf->getRightEyeX()-m_pixPifPafEye.width()/2, m_pPifPaf->getRightEyeY()-m_pixPifPafEye.width()/2, m_pixPifPafEye);

  QWidget::paintEvent(evt);
}

void CBAKt::resizeEvent(QResizeEvent * evt)
{
  m_pPifPaf->setPos(width()-m_pPifPaf->getWidth(), height()-m_pPifPaf->getHeight());
}

void CBAKt::keyPressEvent(QKeyEvent* evt)
{
  if(!evt->isAutoRepeat())
  {
    CKeyboardEvent kbdEvt(true, evt->key());
    //Solution
    m_KeyboardMgr.notifyEvent(kbdEvt);
    //Fin Solution
    update();
  }
  else
    QWidget::keyPressEvent(evt);
}

void CBAKt::keyReleaseEvent(QKeyEvent* evt)
{
  CKeyboardEvent kbdEvt(false, evt->key());
  //Solution
  m_KeyboardMgr.notifyEvent(kbdEvt);
  //Fin Solution
  update();
}

void CBAKt::mouseMoveEvent(QMouseEvent * evt)
{
  CMouseEvent mouseEvt(evt->x(), evt->y());
  //Solution
  m_MouseMgr.notifyEvent(mouseEvt);
  //Fin Solution
  update();
}

void CBAKt::mousePressEvent(QMouseEvent * evt)
{
  CMouseEvent::Button button;
  if(evt->button() == Qt::LeftButton)
    button = CMouseEvent::Button::Left;
  else if(evt->button() == Qt::MiddleButton)
    button = CMouseEvent::Button::Middle;
  else if(evt->button() == Qt::RightButton)
    button = CMouseEvent::Button::Right;
  else
  {
    QWidget::mousePressEvent(evt);
    return;
  }
  CMouseEvent mouseEvt(true, button);
  //Solution
  m_MouseMgr.notifyEvent(mouseEvt);
  //Fin Solution
  update();
}

void CBAKt::mouseReleaseEvent(QMouseEvent * evt)
{
  CMouseEvent::Button button;
  if (evt->button() == Qt::LeftButton)
    button = CMouseEvent::Button::Left;
  else if (evt->button() == Qt::MiddleButton)
    button = CMouseEvent::Button::Middle;
  else if (evt->button() == Qt::RightButton)
    button = CMouseEvent::Button::Right;
  else
  {
    QWidget::mouseReleaseEvent(evt);
    return;
  }
  CMouseEvent mouseEvt(false, (CMouseEvent::Button)button);
  //Solution
  m_MouseMgr.notifyEvent(mouseEvt);
  //Fin Solution
  update();
}

