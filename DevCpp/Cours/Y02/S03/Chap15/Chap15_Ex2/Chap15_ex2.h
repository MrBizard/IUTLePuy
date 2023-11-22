#ifndef CHAP15_EX2_H
#define CHAP15_EX2_H

#include <QtWidgets/QMessageBox>
#include <QtWidgets/QMainWindow>
#include "ui_chap15_ex2.h"

class Chap15_Ex2 : public QMainWindow
{
    Q_OBJECT

public:
    Chap15_Ex2(QWidget *parent = 0);
    ~Chap15_Ex2();

public slots:
  void click1() {QMessageBox::aboutQt(this);}
  void on_btnHello_pressed() {QMessageBox::information(this, "Hey", "Bonjour toi !");}

private:
    Ui::Chap10_Ex2Class ui;
};

#endif // CHAP15_EX2_H
