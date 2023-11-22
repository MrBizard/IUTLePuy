#pragma once
#include "Point.h"
#include "Couleur.h"

#include <iostream>

class CObjetGraphique
{
public:
  CObjetGraphique(const CPoint& pos = CPoint{ 0, 0 },
                  const CCouleur& coul = CCouleur{ 0, 0, 0 });

private:
  CPoint m_position;
  CCouleur m_couleur;

public:
  void BougeVers(const CPoint& pos);
  void ChangeCouleur(const CCouleur& coul);

  const CPoint& getPos() const { return m_position; }
  const CCouleur& getCoul() const { return m_couleur; }
};

std::ostream& operator<<(std::ostream& out, const CObjetGraphique& obj);