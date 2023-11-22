#pragma once
#include "objetplein.h"
#include <vector>

class CPolygone :
  public CObjetPlein
{
private:
  std::vector<CPoint> m_vPoints;

public:
  CPolygone(const CPoint& offset = CPoint{ 0, 0 },
            const CCouleur& coulTrait = CCouleur{ 0, 0, 0 },
            const CCouleur& coulRemplissage = CCouleur{ 255, 255, 255 });

public:
  //Ajoute un point de contr�le
  CPolygone& operator<<(const CPoint &p);

  void Afficher();
};
