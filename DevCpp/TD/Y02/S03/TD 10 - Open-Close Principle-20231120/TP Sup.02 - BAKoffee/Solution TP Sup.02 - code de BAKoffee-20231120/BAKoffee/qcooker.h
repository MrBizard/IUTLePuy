#ifndef QCOOKER_H
#define QCOOKER_H

#include <QObject>
#include "Boisson.h"
#include <memory>
class QCooker : public QObject
{
  Q_OBJECT

public:
    QCooker(QObject *parent = nullptr);

private:

public slots:
  void prepare(std::shared_ptr<const CBoisson> pBoisson);

};

#endif // QCOOKER_H
