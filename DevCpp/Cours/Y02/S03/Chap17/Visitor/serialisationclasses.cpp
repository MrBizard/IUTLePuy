#include "serializationclasses.h"
#include <QFile>

CJsonWriter::CJsonWriter(QString strFileName)
  : m_strFileName(strFileName)
{
}

void CJsonWriter::serialize(CData& data)
{
  m_mainJsonObject["a"] = data.getA();
}

void CJsonWriter::serialize(CSubData& data)
{
  QJsonObject subDataJson;
  subDataJson["c"] = data.getC();
  m_mainJsonObject["subData"] = subDataJson;
}

CJsonWriter::~CJsonWriter()
{
  QFile file(m_strFileName);
  file.open(QIODevice::WriteOnly);

  QJsonDocument jsonDoc(m_mainJsonObject);
  file.write(jsonDoc.toJson());
}





CJsonReader::CJsonReader(QString strFileName)
  : m_strFileName(strFileName)
{
  QFile file(m_strFileName);
  file.open(QIODevice::ReadOnly);

  m_mainJsonObject = QJsonDocument::fromJson(file.readAll()).object();
}

void CJsonReader::serialize(CData& data)
{
  data.setA(m_mainJsonObject["a"].toInt());
}

void CJsonReader::serialize(CSubData& data)
{
  data.setC(m_mainJsonObject["subData"].toObject()["c"].toDouble());
}
