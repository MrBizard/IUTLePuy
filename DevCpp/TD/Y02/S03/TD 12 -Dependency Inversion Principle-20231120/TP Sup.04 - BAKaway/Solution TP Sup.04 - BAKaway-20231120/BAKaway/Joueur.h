#pragma once
#include "Personnage.h"

class CJoueur :
  public CPersonnage
{
protected:
  int m_nVie = 10;

  //Solution
  CJoueur(CPosition::const_ptr pos, CModeleGraphique::const_ptr modele, int nVie=10);
  /*
  //Fin Solution
  CJoueur(CModeleGraphique::const_ptr modele, int nVie = 10);
  //Solution
  */
  //Fin Solution
public:
  using ptr = std::shared_ptr<CJoueur>;
  using const_ptr = std::shared_ptr<const CJoueur>;
  virtual int getVie() const =0;
  virtual void diminuerVie(int niveau) =0;
};

