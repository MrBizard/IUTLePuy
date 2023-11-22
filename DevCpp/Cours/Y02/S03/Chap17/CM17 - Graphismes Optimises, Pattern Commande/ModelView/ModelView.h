#ifndef MODELVIEW_H
#define MODELVIEW_H

#include <QtWidgets/QWidget>
#include <QStandardItemModel>
#include "ui_modelview.h"

class ModelView : public QWidget
{
    Q_OBJECT

public:
    ModelView(QWidget *parent = 0);
    ~ModelView();

private:
    Ui::ModelViewClass ui;
    QStandardItemModel m_model;
};

#endif // MODELVIEW_H
