#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <array>
#include "qkey.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  QWidget window;
  window.setWindowTitle("Ma fenêtre");

  QLineEdit* lineEdit =new QLineEdit();

  QVBoxLayout* mainlayout =new QVBoxLayout();
  mainlayout->addWidget(lineEdit);

  std::array<const wchar_t*,5> clavier = {L"²1234567890°+", L"AZERTYUIOP^$", L"QSDFGHJKLMù*", L"WXCVBN,;:!", L" "};
  for(auto& line : clavier)
  {
    QHBoxLayout*layout =new QHBoxLayout();
    auto pChar = line;
    for(; *pChar!=L'\0'; pChar++)
    {
      QKey* key = new QKey(QChar(*pChar));
      layout->addWidget(key);
      QObject::connect(key, &QKey::keyStroke, lineEdit, &QLineEdit::setText);
    }
    mainlayout->addLayout(layout);
  }

  window.setLayout(mainlayout);
  window.resize(300, 150);
  window.show();
  return app.exec();
}
