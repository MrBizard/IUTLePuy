#pragma once
#include <memory>
#include "joueur.h"

class CJoueurNormal :
  public CJoueur
{
  //Solution
  CJoueurNormal(CPosition::const_ptr pos, CModeleGraphique::const_ptr modele, int nVie=10)
    : CJoueur(pos, modele, nVie)
  {}
  /*
  //Fin Solution
  CJoueurNormal(CModeleGraphique::const_ptr modele, int nVie = 10)
    : CJoueur(modele, nVie)
  {}
  //Solution
  */
  //Fin Solution
public:
  using ptr = std::shared_ptr<CJoueurNormal>;
  using const_ptr = std::shared_ptr<const CJoueurNormal>;
  //Solution
  static ptr create(CPosition::const_ptr pos, CModeleGraphique::const_ptr modele, int nVie = 10)
  {
    return ptr(new CJoueurNormal(pos, modele, nVie));
  }
  /*
  //Fin Solution
  static ptr create(CModeleGraphique::const_ptr modele, int nVie = 10)
  {
    return ptr(new CJoueurNormal(modele, nVie));
  }
  //Solution
  */
  //Fin Solution

  int getVie() const override {return m_nVie;}
  void diminuerVie(int niveau) override {m_nVie-=niveau; if(m_nVie<0) m_nVie=0;}

};

