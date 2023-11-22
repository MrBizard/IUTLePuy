#include "IA.h"
#include <numeric>
using namespace std;
void CIA::agir()
{
  if(m_lstObserved.empty())
    return;

  double dMinDist = std::numeric_limits<double>::max();
  CJoueur::const_ptr pPlusProche;
  
  for(auto& pObserved : m_lstObserved)
  {
    //Solution
    double dDist = pObserved->getPos()->distance(m_pControled->getPos());
    /*
    //Fin Solution
    double dDist = std::numeric_limits<double>::max();
    //Solution
    */
    //Fin Solution
    if(dDist < dMinDist)
    {
      pPlusProche = pObserved;
      dMinDist = dDist;
    }
  }

  if(dMinDist > m_dDistanceIgnore)
    return;

  //Solution
  if(pPlusProche && pPlusProche->getVie() < m_nSeuilVieAttaque)
    m_pControled->deplacer((*pPlusProche->getPos() - *m_pControled->getPos())->normer(), 1);
  else 
    m_pControled->deplacer((*pPlusProche->getPos() - *m_pControled->getPos())->normer(), -1);
  /*
  //Fin Solution
  if(pPlusProche && pPlusProche->getVie() < m_nSeuilVieAttaque)
    m_pControled;
  else
    m_pControled;
  //Solution
  */
  //Fin Solution
}