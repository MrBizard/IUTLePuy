#include "bakoffee.h"
#include "qcooker.h"
#include <QtWidgets/QApplication>
#include <memory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BAKoffee w;
    QCooker cook;
    QObject::connect(&w, &BAKoffee::prepare, &cook, &QCooker::prepare);
    w.show();
    return a.exec();
}
