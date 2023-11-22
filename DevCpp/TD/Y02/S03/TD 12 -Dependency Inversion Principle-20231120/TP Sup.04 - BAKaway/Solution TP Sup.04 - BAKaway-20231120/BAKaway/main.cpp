#include "position2D.h"
#include "playscreen.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CPlayScreen w;
    w.show();

    return a.exec();
}
