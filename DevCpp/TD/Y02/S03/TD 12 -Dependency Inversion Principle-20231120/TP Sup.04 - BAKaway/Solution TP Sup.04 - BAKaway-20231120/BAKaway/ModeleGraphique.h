#pragma once
#include "Position.h"
#include <memory>

class CModeleGraphique
  : std::enable_shared_from_this<CModeleGraphique>
{
public:
  using ptr = std::shared_ptr<CModeleGraphique>;
  using const_ptr = std::shared_ptr<const CModeleGraphique>;

  //Solution
  virtual void afficher(CPosition::const_ptr pos = nullptr) const =0;
  /*
  //Fin Solution
  virtual void afficher() const =0;
  //Solution
  */
  //Fin Solution
};
