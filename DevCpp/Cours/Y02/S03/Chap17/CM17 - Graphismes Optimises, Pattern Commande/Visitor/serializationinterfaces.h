#pragma once

class ISerializer;

class ISerializable
{
public:
  virtual void acceptSerializer(ISerializer& serializer) = 0;
};

class CData;
class CSubData;
class ISerializer
{
public:
  virtual void serialize(CData& data) = 0;
  virtual void serialize(CSubData& data) = 0;
};

