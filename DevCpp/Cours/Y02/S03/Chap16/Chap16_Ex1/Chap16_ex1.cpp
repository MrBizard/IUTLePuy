#include "chap16_ex1.h"

Chap16_Ex1::Chap16_Ex1(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
}

Chap16_Ex1::~Chap16_Ex1()
{

}

void Chap16_Ex1::refreshPicture()
{
  if(ui.btnCowboy1->isChecked())
    ui.lblPicture->setPixmap(QPixmap(":/Images/cowboy1.png"));
  else if(ui.btnCowboy2->isChecked())
    ui.lblPicture->setPixmap(QPixmap(":/Images/cowboy2.png"));
  else if(ui.btnCowgirl->isChecked())
    ui.lblPicture->setPixmap(QPixmap(":/Images/cowgirl.png"));
  else if(ui.btnReligieuse->isChecked())
    ui.lblPicture->setPixmap(QPixmap(":/Images/religieuse.png"));
  else if (ui.btnReligieux->isChecked())
    ui.lblPicture->setPixmap(QPixmap(":/Images/religieux.png"));
}