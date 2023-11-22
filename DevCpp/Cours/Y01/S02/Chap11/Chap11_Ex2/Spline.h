#pragma once
#include "objetgraphique.h"
#include <vector>

class CSpline :
  public CObjetGraphique
{
private:
  std::vector<CPoint> m_vPoints;

public:
  CSpline(const CPoint& offset = CPoint{ 0, 0 },
          const CCouleur& coul = CCouleur{ 0, 0, 0 });

public:
  //Ajoute un point de contrôle
  CSpline& operator<<(const CPoint &p);

  void Afficher() override;

};
