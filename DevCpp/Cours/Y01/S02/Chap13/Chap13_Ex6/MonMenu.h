#pragma once
#include <menu.h>
#include <iostream>
#include "MaClasse.h"

class CMonMenu :
  public CMenu
{
public:
  CMonMenu(std::string strTitre = std::string{}) : CMenu(strTitre){}

  virtual void AvantAfficher()
  {
    const size_t nNb = CMaClasse::GetNbInstances();
    std::cout << "Il y a actuellement " << nNb << " instance" << (nNb > 1 ? "s" : "") << " de la classe CMaClasse" << std::endl;
  }
  
};

