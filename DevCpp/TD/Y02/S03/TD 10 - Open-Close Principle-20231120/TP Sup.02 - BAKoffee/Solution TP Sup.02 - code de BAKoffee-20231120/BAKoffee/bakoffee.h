#ifndef BAKOFFEE_H
#define BAKOFFEE_H

#include <QtWidgets/QWidget>
#include "ui_bakoffee.h"
#include "Boisson.h"
#include <memory>

class BAKoffee : public QWidget
{
    Q_OBJECT

private:
  std::shared_ptr<CBoisson> m_pBoisson;

public:
    BAKoffee(QWidget *parent = 0);
    ~BAKoffee();

signals:
  void prepare(std::shared_ptr<const CBoisson> pBoisson);
public slots:
  void go();
  void enableGo();

private:
    Ui::BAKoffeeClass ui;
};

#endif // BAKOFFEE_H
