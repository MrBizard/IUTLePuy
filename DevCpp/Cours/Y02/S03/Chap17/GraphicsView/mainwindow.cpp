#include "mainwindow.h"

mainwindow::mainwindow(QWidget *parent)
    : QMainWindow(parent)
    , m_scene(&m_undoStack)
{
  ui.setupUi(this);
  ui.graphicsView->setScene(&m_scene);
  ui.graphicsView->setRenderHint(QPainter::Antialiasing, true);
  m_scene.setSceneRect(0, 0, 500, 500);

  ui.undoView->setStack(&m_undoStack);

  connect(&m_undoStack, &QUndoStack::canRedoChanged, ui.actionRetablir, &QAction::setEnabled);
  connect(&m_undoStack, &QUndoStack::canUndoChanged, ui.actionAnnuler, &QAction::setEnabled);
}

mainwindow::~mainwindow()
{

}

void mainwindow::onToolSelection(QAction* action)
{
  for(QAction* a : ui.mainToolBar->actions())
    a->setChecked(false);
  action->setChecked(true);
}
void mainwindow::toolSelect()
{
  m_scene.setCommand(nullptr);
}
void mainwindow::toolRectangle()
{
  m_scene.setCommand(&m_toolRectangle);
}
void mainwindow::toolEllipse()
{
  m_scene.setCommand(&m_toolEllipse);
}
void mainwindow::onUndo()
{
  m_undoStack.undo();
}
void mainwindow::onRedo()
{
  m_undoStack.redo();
}
