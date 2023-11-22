#ifndef QMACLASSE_H
#define QMACLASSE_H

#include <QObject>
#include <QtDebug>

class QVase : public QObject
{
  Q_OBJECT
  int m_nVal = 0;
public:
  QVase(QObject* parent = nullptr): QObject(parent) {}
  void Remplir() 
  {
    if(m_nVal == 5) 
    {
      qDebug()<<"Niveau max atteint, emission du signal QVase::plein() ";
      emit plein();
    }
    else 
    {
      m_nVal++;
      qDebug()<<"Incrementation du niveau a "<<m_nVal;
    }
  }

signals:
  void plein();
};

#endif // QMACLASSE_H
