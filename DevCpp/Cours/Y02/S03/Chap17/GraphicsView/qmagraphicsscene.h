#ifndef QMAGRAPHICSSCENE_H
#define QMAGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QUndoStack>
#include "QUndoCommandCreate.h"

class QMaGraphicsScene : public QGraphicsScene
{
  Q_OBJECT

public:
    QMaGraphicsScene(QUndoStack* undoStack, QObject *parent=nullptr);
    ~QMaGraphicsScene();
    void setCommand(QUndoCommandCreate* command) { m_curCommand = command; }

private:
  QUndoStack* m_undoStack;
  QUndoCommandCreate* m_curCommand;
protected:
  virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);

};

#endif // QMAGRAPHICSSCENE_H
