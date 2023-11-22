#include "Spline.h"
#include <assert.h>
#include <iostream>
using namespace std;

CSpline::CSpline(const CPoint& offset/*=CPoint{ 0, 0 }*/,
                 const CCouleur& coul/*=CCouleur{ 0, 0, 0 }*/)
  : CObjetGraphique{ offset, coul }
{
  //cout << "Construction d'une spline" << endl;
}

CSpline& CSpline::operator <<(const CPoint &p)
{
  m_vPoints.push_back(p);
  return *this;
}

void CSpline::Afficher()
{
  CObjetGraphique::Afficher();
  cout << "Je suis une spline de " << m_vPoints.size() << " points : ";
  for (const CPoint& pt : m_vPoints)
    cout << pt << " ";
  cout << endl;
}

