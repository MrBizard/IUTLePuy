#pragma once
#include "objetplein.h"

class CCercle :
  public CObjetPlein
{
private:
  unsigned int m_unRayon;
public:
  CCercle(const CPoint& centre = CPoint{ 0, 0 },
          unsigned int rayon = 1,
          const CCouleur& coulTrait = CCouleur{ 0, 0, 0 },
          const CCouleur& coulRemplissage = CCouleur{ 255, 255, 255 });

public:
  void Afficher();
};
