#pragma once
#include "objetgraphique.h"

class CObjetPlein :
  public CObjetGraphique
{
private:
  CCouleur m_coulRemplis;
public:
  CObjetPlein(const CPoint& pos = CPoint{ 0, 0 },
              const CCouleur& coulTrait = CCouleur{ 0, 0, 0 },
              const CCouleur& coulRemplissage = CCouleur{ 255, 255, 255 });

public:
  void Afficher() override;
};
