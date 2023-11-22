#include "Segment.h"
#include <iostream>
using namespace std;

CSegment::CSegment(const CPoint &pt1/* = CPoint{ 0, 0 }*/,
                   const CPoint &pt2/* = CPoint{ 0, 0 }*/,
                   const CCouleur &coul/* = CCouleur{ 0, 0, 0 }*/)
  : CObjetGraphique{ pt1, coul }
  , m_pt2{ pt2 }
{
  //cout << "Construction d'un segment" << endl;
}

void CSegment::Afficher()
{
  CObjetGraphique::Afficher();
  cout << "Je suis plus exactement un segment entre les points "
    << m_position << " et " << m_pt2 << endl;
}