#include "qcooker.h"
#include <QtWidgets>
using namespace std;

QCooker::QCooker(QObject *parent)
  : QObject(parent)
{

}

void QCooker::prepare(std::shared_ptr<const CBoisson> pBoisson)
{
  //Solution
  class int0 {public: int val = 0;};

  CBoisson::description lstDesc = pBoisson->getDescription();

  std::map<CBoisson::description::value_type, int0> mapDescription;

  for(const auto& elm : lstDesc)
    mapDescription[elm].val++;

  QString str;
  for(const auto& key_val : mapDescription)
    str.append(QString::number(key_val.second.val)).append(" dose(s) de ").append(key_val.first.second.c_str()).append("\n");

  QMessageBox::information(nullptr, "Préparation...", "Préparation en versant dans l'ordre : \n" + str);
  /*
  //Fin Solution
  QMessageBox::information(nullptr, "Préparation...", pBoisson->getDescription().c_str());
  //Solution
  */
  //Fin Solution
}
