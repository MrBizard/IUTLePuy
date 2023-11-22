#include "QUndoCommandCreate.h"


QUndoCommandCreate::QUndoCommandCreate(QGraphicsScene* scene)
  : m_scene(scene)
{
}


QUndoCommandCreate::~QUndoCommandCreate()
{
}
