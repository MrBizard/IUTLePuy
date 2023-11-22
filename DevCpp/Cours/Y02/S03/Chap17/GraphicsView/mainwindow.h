#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "qmagraphicsscene.h"
#include <QUndoStack>
#include "QUndoCommandCreate.h"

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = 0);
    ~mainwindow();

private:
    Ui::mainwindow ui;
    QMaGraphicsScene m_scene;
    QUndoStack m_undoStack;
    QUndoCommandEllipse m_toolEllipse{ &m_scene };
    QUndoCommandRectangle m_toolRectangle{ &m_scene };
    public slots:
    void onToolSelection(QAction*);
    void toolSelect();
    void toolRectangle();
    void toolEllipse();
    void onUndo();
    void onRedo();
};

#endif // MAINWINDOW_H
