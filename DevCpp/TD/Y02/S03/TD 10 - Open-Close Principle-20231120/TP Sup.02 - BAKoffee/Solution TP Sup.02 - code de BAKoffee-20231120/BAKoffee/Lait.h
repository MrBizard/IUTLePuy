#pragma once
#include "decorateuringredient.h"
//Solution
class CLait :
  public CDecorateurIngredient
{

public:
  CLait(std::shared_ptr<CBoisson> pBoisson)
    : CDecorateurIngredient(pBoisson, description::value_type(6,"Lait"))
  {}

  double getCout() const override
  {
    if (!m_pBoisson)
      return 0.1;
    return m_pBoisson->getCout() + 0.1;
  }
};
//Fin Solution
