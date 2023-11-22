#pragma once
class CMaClasse
{
  static size_t s_nNbInstances;

public:
  CMaClasse();
  ~CMaClasse();

  static size_t GetNbInstances();
};

