#ifndef OBJETGRAPHIQUE_H
#define OBJETGRAPHIQUE_H

#include "Point.h"
#include "Couleur.h"

class CObjetGraphique
{
public:
  CObjetGraphique(const CPoint& pos = CPoint{ 0, 0 },
                  const CCouleur& coul = CCouleur{ 0, 0, 0 });

protected:
  CPoint m_position;
  CCouleur m_couleur;

public:
  void BougeVers(const CPoint& pos);
  void ChangeCouleur(const CCouleur& coul);
  virtual void Afficher();
};

#endif //OBJETGRAPHIQUE_H
