#pragma once
#include "Position.h"
#include "ModeleGraphique.h"
#include <memory>

class CDecor
  : std::enable_shared_from_this<CDecor>
{
  //Solution
  std::shared_ptr<const CPosition> m_pTaille;
  std::shared_ptr<const CPosition> m_pPosObjectif;
  //Fin Solution
  CModeleGraphique::const_ptr m_modele;
  //Solution
  CDecor(CPosition::const_ptr taille, CPosition::const_ptr objectif, CModeleGraphique::const_ptr pModele);
  /*
  //Fin Solution
  CDecor(CModeleGraphique::const_ptr pModele);
  //Solution
  */
  //Fin Solution
  CDecor() = delete;
  CDecor(const CDecor&) = default;

public:
  using ptr = std::shared_ptr<CDecor>;
  using const_ptr = std::shared_ptr<const CDecor>;

  //Solution
  static std::shared_ptr<CDecor> create(CPosition::const_ptr taille, CPosition::const_ptr objectif, CModeleGraphique::const_ptr pModele);
  /*
  //Fin Solution
  static std::shared_ptr<CDecor> create(CModeleGraphique::const_ptr pModele);
  //Solution
  */
  //Fin Solution

  //Solution
  CPosition::const_ptr getTaille() const { return m_pTaille; }
  CPosition::const_ptr getObjectif() const { return m_pPosObjectif; }
  //Fin Solution
  //Solution
  void afficher() const { m_modele->afficher((*m_pTaille) / 2.0); }
  /*
  //Fin Solution
  void afficher() const { m_modele->afficher(); }
  //Solution
  */
  //Fin Solution
};

