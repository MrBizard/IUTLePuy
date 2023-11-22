#pragma once
#include <iostream>
#include "serializationinterfaces.h"
#include "data.h"
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>

class CStdOutWriter : public ISerializer
{
public:
  void serialize(CData& data) override{ std::cout << "a = " << data.getA() << std::endl; }
  void serialize(CSubData& data) override{ std::cout << "c = " << data.getC() << std::endl; }
};

class CStdInReader : public ISerializer
{
public:
  void serialize(CData& data) override
  {
    int a; std::cin >> a;
    data.setA(a);
  }
  void serialize(CSubData& data) override
  {
    double c;
    std::cin >> c;
    data.setC(c);
  }
};

class CJsonWriter : public ISerializer
{
  QString m_strFileName;
  QJsonObject m_mainJsonObject;
public:
  CJsonWriter(QString strFileName);
  ~CJsonWriter();
  void serialize(CData& data) override;
  void serialize(CSubData& data) override;
};

class CJsonReader : public ISerializer
{
  QString m_strFileName;
  QJsonObject m_mainJsonObject;
public:
  CJsonReader(QString strFileName);
  void serialize(CData& data) override;
  void serialize(CSubData& data) override;
};