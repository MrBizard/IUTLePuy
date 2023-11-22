#pragma once
#include "boisson.h"
class CDeca :
  public CBoisson
{
public:
  CDeca(void)
    //Solution
    : CBoisson(description::value_type(5, "Café Décaféiné"))
    /*
    //Fin Solution
    : CBoisson(description("Café Décaféiné"))
    //Solution
    */
    //Fin Solution
  {}

  double getCout() const override {return 0.3;}
};

