#pragma once
#include "decorateuringredient.h"
//Solution
class CSucre :
  public CDecorateurIngredient
{
public:
  CSucre(std::shared_ptr<CBoisson> pBoisson)
    : CDecorateurIngredient(pBoisson, description::value_type(3,"Sucre"))
  {}

  double getCout() const override
  {
    if (!m_pBoisson)
      return 0.05;
    return m_pBoisson->getCout() + 0.05;
  }
};
//Fin Solution
