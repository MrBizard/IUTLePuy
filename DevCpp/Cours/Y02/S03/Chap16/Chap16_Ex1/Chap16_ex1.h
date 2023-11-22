#ifndef CHAP16_EX1_H
#define CHAP16_EX1_H

#include <QtWidgets/QDialog>
#include "ui_chap16_ex1.h"

class Chap16_Ex1 : public QDialog
{
    Q_OBJECT

public:
    Chap16_Ex1(QWidget *parent = 0);
    ~Chap16_Ex1();

public slots:
  void refreshPicture();

private:
    Ui::Chap16_Ex1Class ui;
};

#endif // CHAP16_EX1_H
