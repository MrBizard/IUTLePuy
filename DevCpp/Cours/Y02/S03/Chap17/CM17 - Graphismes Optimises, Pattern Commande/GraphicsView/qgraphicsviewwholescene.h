#ifndef QGRAPHICSVIEWWHOLESCENE_H
#define QGRAPHICSVIEWWHOLESCENE_H

#include <QGraphicsView>

class QGraphicsViewWholeScene : public QGraphicsView
{
  Q_OBJECT

public:
  QGraphicsViewWholeScene(QGraphicsScene * scene, QWidget *parent = nullptr)
    : QGraphicsView(scene, parent)
  {
  }
  QGraphicsViewWholeScene(QWidget *parent = nullptr)
    : QGraphicsView(parent)
  {
  }
  ~QGraphicsViewWholeScene();

protected:
  virtual void resizeEvent(QResizeEvent * event);

};

#endif // QGRAPHICSVIEWWHOLESCENE_H
