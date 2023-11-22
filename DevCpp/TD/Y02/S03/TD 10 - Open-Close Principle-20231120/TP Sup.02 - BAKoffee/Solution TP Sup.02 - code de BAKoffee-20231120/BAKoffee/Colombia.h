#pragma once
#include "boisson.h"
class CColombia :
  public CBoisson
{
public:
  CColombia()
    //Solution
    : CBoisson(description::value_type(5,"Café Colombia"))
    /*
    //Fin Solution
    : CBoisson(description("Café Colombia"))
    //Solution
    */
    //Fin Solution
  {}

  double getCout() const override {return 0.4;}
};
