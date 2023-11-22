#include "bakt.h"
#include <cstdlib>
#include <ctime>
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
  std::srand(std::time(nullptr));
  QApplication a(argc, argv);
  CBAKt w;
  w.show();

  return a.exec();
}
