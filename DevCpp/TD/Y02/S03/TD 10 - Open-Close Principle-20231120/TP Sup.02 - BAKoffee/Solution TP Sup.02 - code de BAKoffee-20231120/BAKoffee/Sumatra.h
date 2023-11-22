#pragma once
#include "boisson.h"
class CSumatra :
  public CBoisson
{
public:
  CSumatra(void)
    //Solution
    : CBoisson(description::value_type(5, "Café Sumatra"))
    /*
    //Fin Solution
    : CBoisson(description("Café Sumatra"))
    //Solution
    */
    //Fin Solution
  {}

  double getCout() const override {return 0.5;}
};

