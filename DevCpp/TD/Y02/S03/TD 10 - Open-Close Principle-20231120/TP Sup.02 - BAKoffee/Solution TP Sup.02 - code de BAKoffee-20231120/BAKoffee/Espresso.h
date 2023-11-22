#pragma once
#include "boisson.h"
class CEspresso :
  public CBoisson
{
public:
  CEspresso(void)
    //Solution
    : CBoisson(description::value_type(5, "Café Espresso"))
    /*
    //Fin Solution
    : CBoisson(description("Café Espresso"))
    //Solution
    */
    //Fin Solution
  {}

  double getCout() const override {return 0.3;}
};

