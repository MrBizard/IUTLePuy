#pragma once
#include "objetgraphique.h"

class CSegment :
  public CObjetGraphique
{
public:
  CSegment(const CPoint& pt1 = CPoint{ 0, 0 },
           const CPoint& pt2 = CPoint{ 0, 0 },
           const CCouleur& coul = CCouleur{ 0, 0, 0 });

private:
  CPoint m_pt2;

public:
  void Afficher();
};


