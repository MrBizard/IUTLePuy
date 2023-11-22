#ifndef CHAP16_EX2_H
#define CHAP16_EX2_H

#include <QtWidgets/QMainWindow>
#include "ui_chap16_ex2.h"

class Chap16_Ex2 : public QMainWindow
{
    Q_OBJECT

public:
    Chap16_Ex2(QWidget *parent = 0);
    ~Chap16_Ex2();

private:
    Ui::Chap16_Ex2Class ui;
};

#endif // CHAP16_EX2_H
