#pragma once
#include "menufichierdonnee.h"

class CMenuLireDonnee :
  public CMenuFichierDonnee
{ 
public:
  CMenuLireDonnee(char c, const std::string& texte, CDonnee& d) : CMenuFichierDonnee(c, texte, d) {}

  virtual void operator()();
};
