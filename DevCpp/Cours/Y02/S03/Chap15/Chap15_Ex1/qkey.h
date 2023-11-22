#ifndef QKEY_H
#define QKEY_H

#include <QPushButton>
#include <QChar>
#include <QSignalMapper>
class QKey : public QPushButton
{
  Q_OBJECT
public:
  QKey(const QChar& code, QWidget *parent=nullptr);

signals:
  void keyStroke(const QString&);

private:
  QChar m_code;
  QSignalMapper* m_signalMapper;
};

#endif // QKEY_H
