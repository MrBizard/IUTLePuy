#pragma once
#include "Personnage.h"
#include "Joueur.h"

class CMonstre : public CPersonnage 
{
protected:
  //Solution
  CMonstre(CPosition::const_ptr pos, CModeleGraphique::const_ptr modele) : CPersonnage(pos, modele) {}
  /*
  //Fin Solution
  CMonstre(CModeleGraphique::const_ptr modele) : CPersonnage(modele) {}
  //Solution
  */
  //Fin Solution
public:
  using ptr = std::shared_ptr<CMonstre>;
  using const_ptr = std::shared_ptr<const CMonstre>;

  virtual void attaquer(CJoueur::ptr joueur) const =0;
};