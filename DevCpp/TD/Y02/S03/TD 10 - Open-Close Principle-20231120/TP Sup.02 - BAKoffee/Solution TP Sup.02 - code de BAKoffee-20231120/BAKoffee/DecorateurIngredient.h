#pragma once
//Solution
#include "boisson.h"
#include <memory>
class CDecorateurIngredient :
  public CBoisson
{
protected:
  std::shared_ptr<CBoisson> m_pBoisson;
public:
  CDecorateurIngredient(std::shared_ptr<CBoisson> pBoisson, const description::value_type& Description)
    : CBoisson(Description)
    , m_pBoisson(pBoisson)
  {}

  description getDescription() const override;
};

//Fin Solution