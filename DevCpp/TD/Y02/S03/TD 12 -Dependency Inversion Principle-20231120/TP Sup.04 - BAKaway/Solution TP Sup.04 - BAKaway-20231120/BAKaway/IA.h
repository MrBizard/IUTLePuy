#pragma once
#include <list>
#include <memory>
#include "Joueur.h"
#include "Monstre.h"

class CIA
{
public:
  using ObservedSet = std::list<CJoueur::const_ptr>;
private:
  ObservedSet m_lstObserved;
  CMonstre::ptr m_pControled;
  int m_nSeuilVieAttaque;
  double m_dDistanceIgnore;
public:
  CIA(std::shared_ptr<CMonstre> pControled, const ObservedSet& lstObserved, int nSeuilVieAttaque, double dDistanceIgnore)
    : m_pControled(pControled)
    , m_lstObserved(lstObserved)
    , m_nSeuilVieAttaque(nSeuilVieAttaque)
    , m_dDistanceIgnore(dDistanceIgnore)
  {}

  CIA(std::shared_ptr<CMonstre> pControled, std::shared_ptr<CJoueur> pObserved, int nSeuilVieAttaque, double dDistanceIgnore)
    : m_pControled(pControled)
    , m_nSeuilVieAttaque(nSeuilVieAttaque)
    , m_dDistanceIgnore(dDistanceIgnore)
  {
    m_lstObserved.push_back(pObserved);
  }

  virtual void agir();
};

