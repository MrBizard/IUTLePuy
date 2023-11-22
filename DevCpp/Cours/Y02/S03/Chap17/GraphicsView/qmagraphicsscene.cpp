#include "qmagraphicsscene.h"
#include <QGraphicsSceneMouseEvent>

QMaGraphicsScene::QMaGraphicsScene(QUndoStack* undoStack, QObject *parent)
  : QGraphicsScene(parent)
  , m_undoStack(undoStack)
{

}

QMaGraphicsScene::~QMaGraphicsScene()
{

}

void QMaGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
  if(mouseEvent->buttons() == Qt::LeftButton && m_curCommand != nullptr)
  {
    m_curCommand->m_Pos = mouseEvent->scenePos();
    m_undoStack->push(m_curCommand->clone());
  }
  else
  {
    QGraphicsScene::mousePressEvent(mouseEvent);
  }
}
