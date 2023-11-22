#pragma once

#include "serializationinterfaces.h"

class CSubData : public ISerializable
{
private:
  double m_c;
public:
  void acceptSerializer(ISerializer& serializer) override { serializer.serialize(*this); }
  void setC(double c) { m_c = c; }
  double getC() const { return m_c; }
};

class CData : public ISerializable
{
private:
  int m_a;
  CSubData m_subData;
public:
  void acceptSerializer(ISerializer& serializer) override 
  { 
    serializer.serialize(*this);
    m_subData.acceptSerializer(serializer); 
  }
  void setA(int a) { m_a = a; }
  void setSubData(CSubData sub) { m_subData = sub; }
  int getA() const { return m_a; }
  CSubData getSubData() const { return m_subData; }
};

