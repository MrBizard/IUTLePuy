#include "command.h"
#include "QUndoCommandUser.h"

Command::Command(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.undoView->setStack(&m_undoStack);
    m_model.insertColumn(0);
    ui.listView->setModel(&m_model);

    connect(&m_undoStack, &QUndoStack::canRedoChanged, ui.actionR_tablir, &QAction::setEnabled);
    connect(&m_undoStack, &QUndoStack::canUndoChanged, ui.actionAnnuler, &QAction::setEnabled);
}

Command::~Command()
{

}

void Command::addRed()
{
  m_undoStack.push(new QUndoCommandAddRed{ &m_model });
}
void Command::addGreen() 
{
  m_undoStack.push(new QUndoCommandAddGreen{ &m_model });
}
void Command::addBlue()
{
  m_undoStack.push(new QUndoCommandAddBlue{ &m_model });
}
void Command::undo()
{
  m_undoStack.undo();
}
void Command::redo()
{
  m_undoStack.redo();
}
