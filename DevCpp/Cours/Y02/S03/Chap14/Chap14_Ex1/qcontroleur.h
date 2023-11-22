#ifndef QCONTROLEUR_H
#define QCONTROLEUR_H

#include <QObject>
#include <QtDebug>

class QControleur : public QObject
{
  Q_OBJECT

private:
  bool m_bStop = false;

public:
  QControleur(QObject *parent=nullptr) : QObject(parent) {};
  bool peutRemplir() {return !m_bStop;}

public slots:
  void ArreterRemplir() {
    qDebug()<<"Appel du slot QControleur::ArreterRemplir() ";
    m_bStop = true;
  }

    
};

#endif // QCONTROLEUR_H
