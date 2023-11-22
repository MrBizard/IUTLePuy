#include "qgraphicsviewwholescene.h"

QGraphicsViewWholeScene::~QGraphicsViewWholeScene()
{

}
void QGraphicsViewWholeScene::resizeEvent(QResizeEvent * event)
{
  QGraphicsView::resizeEvent(event);
  fitInView(scene()->sceneRect(), Qt::KeepAspectRatio);
}
