#pragma once
#include "menufichierdonnee.h"

class CMenuEcrireDonnee :
  public CMenuFichierDonnee
{
public:
  CMenuEcrireDonnee(char c, const std::string& texte, CDonnee& d) : CMenuFichierDonnee(c, texte, d) {}

  virtual void operator()();
};
