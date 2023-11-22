#include "qkey.h"

QKey::QKey(const QChar& code, QWidget *parent)
  : QPushButton(parent)
  , m_code(code)
{
  m_signalMapper = new QSignalMapper(this);
  
  QObject::connect(this, &QPushButton::clicked, m_signalMapper, static_cast<void(QSignalMapper::*)()>(&QSignalMapper::map));
  m_signalMapper->setMapping(this, m_code);
  QObject::connect(m_signalMapper, static_cast<void(QSignalMapper::*)(const QString&)>(&QSignalMapper::mappedString), this, &QKey::keyStroke);

  setText(m_code);
  setMinimumSize(25, 25);
}
