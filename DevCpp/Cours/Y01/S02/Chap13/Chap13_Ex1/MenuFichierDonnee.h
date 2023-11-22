#pragma once
#include <menuelmt.h>
#include "donnee.h"

class CMenuFichierDonnee :
  public CMenuElmt
{
protected:
  CDonnee& m_Donnee;
  std::string m_strNomFichier;
  
public:
  CMenuFichierDonnee(char c, const std::string& texte, CDonnee& d);

  virtual void operator ()();
};
