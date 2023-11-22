#include "chap16_ex1.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMessagebox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Chap16_Ex1 w;
    w.adjustSize();
    w.setFixedSize(w.size());
    switch(w.exec())
    {
    case QDialog::Accepted:
      QMessageBox::information(nullptr, "Sélection d'avatar", "Merci d'avoir choisi un avatar");
      break;
    case QDialog::Rejected:
      QMessageBox::information(nullptr, "Sélection d'avatar", "Revenez quand vous voulez !");
      break;
    }
    return 0;
}
