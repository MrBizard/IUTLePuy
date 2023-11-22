#pragma once
#include <QUndoStack>
#include <QGraphicsScene>
#include <QGraphicsItem>

class QUndoCommandCreate :
  public QUndoCommand
{
protected:
  QGraphicsScene* m_scene;
  QGraphicsItem* m_item;
public:
  QPointF m_Pos;

  virtual QUndoCommandCreate* clone()=0;
  QUndoCommandCreate* copieTo(QUndoCommandCreate* ptr)
  {
    ptr->m_Pos = m_Pos;
    ptr->m_item = m_item;
    return ptr;
  }
  QUndoCommandCreate(QGraphicsScene* scene);
  ~QUndoCommandCreate();
};

class QUndoCommandEllipse :
  public QUndoCommandCreate
{
public:
  QUndoCommandEllipse(QGraphicsScene* scene)
    : QUndoCommandCreate(scene)
  {
    setText("Ajout d'une ellipse");
  }

  virtual QUndoCommandCreate* clone()
  {
    QUndoCommandEllipse* ptr = new QUndoCommandEllipse{ m_scene };
    return copieTo(ptr);
  }

  void redo()
  {
    m_item = m_scene->addEllipse(m_Pos.rx() - 50, m_Pos.ry() - 25, 100, 50);
    m_item->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
  }

  void undo()
  {
    m_scene->removeItem(m_item);
  }
};

class QUndoCommandRectangle :
  public QUndoCommandCreate
{
public:
  QUndoCommandRectangle(QGraphicsScene* scene)
    : QUndoCommandCreate(scene)
  {
    setText("Ajout d'un rectangle");
  }

  virtual QUndoCommandCreate* clone()
  {
    QUndoCommandRectangle* ptr = new QUndoCommandRectangle{ m_scene };
    return copieTo(ptr);
  }

  void redo()
  {
    m_item = m_scene->addRect(m_Pos.rx() - 50, m_Pos.ry() - 25, 100, 50);
    m_item->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
  }

  void undo()
  {
    m_scene->removeItem(m_item);
  }
};