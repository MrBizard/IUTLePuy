#ifndef COMMAND_H
#define COMMAND_H

#include <QtWidgets/QMainWindow>
#include "ui_command.h"
#include <QUndoStack>
#include <QStandardItemModel>

class Command : public QMainWindow
{
    Q_OBJECT

public:
    Command(QWidget *parent = 0);
    ~Command();

private:
    Ui::CommandClass ui;
    QUndoStack m_undoStack;
    QStandardItemModel m_model;

public slots:
    void addRed();
    void addGreen();
    void addBlue();
    void undo();
    void redo();
};

#endif // COMMAND_H
