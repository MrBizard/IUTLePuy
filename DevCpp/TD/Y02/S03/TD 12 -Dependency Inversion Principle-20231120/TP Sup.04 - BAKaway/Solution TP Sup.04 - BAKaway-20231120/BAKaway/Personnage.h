#pragma once
#include "Position.h"
#include "ModeleGraphique.h"
#include <QPainter>

class CPersonnage
  : std::enable_shared_from_this<CPersonnage>
{
  //Solution
  std::shared_ptr<CPosition> m_pPos;
  //Fin Solution
  CModeleGraphique::const_ptr m_modeleGraphique;

//Interdit la copie des objets de type personnage en déclarant supprimés contructeur par recopie et opérateur =.
  CPersonnage(const CPersonnage&) = delete;
  CPersonnage& operator=(const CPersonnage&) = delete;

protected:
  //Solution
  CPersonnage(CPosition::const_ptr pos, CModeleGraphique::const_ptr modele);
  /*
  //Fin Solution
  CPersonnage(CModeleGraphique::const_ptr modele);
  //Solution
  */
  //Fin Solution

public:
  using ptr = std::shared_ptr<CPersonnage>;
  using const_ptr = std::shared_ptr<const CPersonnage>;
  //Solution
  void deplacer(CPosition::const_ptr dir, double dDist);
  void setPos(CPosition::const_ptr pos) { m_pPos = pos->clone(); }
  CPosition::const_ptr getPos() const { return m_pPos; }
  void afficher() const { m_modeleGraphique->afficher(m_pPos); }
  /*
  //Fin Solution
  void afficher() const { m_modeleGraphique->afficher(); }
  //Solution
  */
  //Fin Solution
};

