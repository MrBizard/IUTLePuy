#pragma once
#include <QUndoCommand>
#include <QAbstractItemModel>
#include <QIcon>

class QUndoCommandAddRed :
  public QUndoCommand
{
private:
  QAbstractItemModel* m_model;
public:
  QUndoCommandAddRed(QAbstractItemModel* model)
    : m_model{ model }
  {
    setText("Ajout d'un élément rouge");
  }
  virtual void undo()
  {
    m_model->removeRow(m_model->rowCount() - 1);
  }
  virtual void redo()
  {
    m_model->insertRow(m_model->rowCount());
    QModelIndex index = m_model->index(m_model->rowCount() - 1, 0);
    m_model->setData(index, "Rouge");
    m_model->setData(index, QIcon{ ":/Icones/Red.png" }, Qt::DecorationRole);
  }
};

class QUndoCommandAddGreen :
  public QUndoCommand
{
private:
  QAbstractItemModel* m_model;
public:
  QUndoCommandAddGreen(QAbstractItemModel* model)
    : m_model{ model }
  {
    setText("Ajout d'un élément vert");
  }
  virtual void undo()
  {
    m_model->removeRow(m_model->rowCount() - 1);
  }
  virtual void redo()
  {
    m_model->insertRow(m_model->rowCount());
    QModelIndex index = m_model->index(m_model->rowCount() - 1, 0);
    m_model->setData(index, "Vert");
    m_model->setData(index, QIcon{ ":/Icones/Green.png" }, Qt::DecorationRole);
  }
};

class QUndoCommandAddBlue :
  public QUndoCommand
{
private:
  QAbstractItemModel* m_model;
public:
  QUndoCommandAddBlue(QAbstractItemModel* model)
    : m_model{ model }
  {
    setText("Ajout d'un élément bleu");
  }
  virtual void undo()
  {
    m_model->removeRow(m_model->rowCount() - 1);
  }
  virtual void redo()
  {
    m_model->insertRow(m_model->rowCount());
    QModelIndex index = m_model->index(m_model->rowCount() - 1, 0);
    m_model->setData(index, "Bleu");
    m_model->setData(index, QIcon{ ":/Icones/Blue.png" }, Qt::DecorationRole);
  }
};

