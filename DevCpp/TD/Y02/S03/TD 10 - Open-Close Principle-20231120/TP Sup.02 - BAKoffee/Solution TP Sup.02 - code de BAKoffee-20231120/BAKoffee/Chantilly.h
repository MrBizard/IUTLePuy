#pragma once
#include "decorateuringredient.h"
//Solution
class CChantilly :
  public CDecorateurIngredient
{
public:
  CChantilly(std::shared_ptr<CBoisson> pBoisson)
    : CDecorateurIngredient(pBoisson, description::value_type(10,"Chantilly"))
  {}

  double getCout() const override
  {
    if (!m_pBoisson)
      return 0.25;
    return m_pBoisson->getCout() + 0.25;
  }
};

//Fin Solution