#pragma once
#include "monstre.h"
#include <QPixmap>
class CMonstreGluant :
  public CMonstre
{
protected:
  //Solution
  CMonstreGluant(CPosition::const_ptr pos, CModeleGraphique::const_ptr modele)
    : CMonstre(pos, modele)
  {}
  /*
  //Fin Solution
  CMonstreGluant(CModeleGraphique::const_ptr modele)
    : CMonstre(modele)
  {}
  //Solution
  */
  //Fin Solution
public:
  using ptr = std::shared_ptr<CMonstreGluant>;
  using const_ptr = std::shared_ptr<const CMonstreGluant>;
  //Solution
  static ptr create(CPosition::const_ptr pos, CModeleGraphique::const_ptr modele)
  {
    return ptr(new CMonstreGluant(pos, modele));
  }
  /*
  //Fin Solution
  static ptr create(CModeleGraphique::const_ptr modele)
  {
    return ptr(new CMonstreGluant(modele));
  }
  //Solution
  */
  //Fin Solution

  void attaquer(CJoueur::ptr joueur) const override;
};

