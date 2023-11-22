#pragma once
#include "decorateuringredient.h"
//Solution
class CCaramel :
  public CDecorateurIngredient
{
public:
  CCaramel(std::shared_ptr<CBoisson> pBoisson)
    : CDecorateurIngredient(pBoisson, description::value_type(2,"Caramel"))
  {}

  double getCout() const override
  {
    if (!m_pBoisson)
      return 0.2;
    return m_pBoisson->getCout() + 0.2;
  }
};
//Fin Solution
