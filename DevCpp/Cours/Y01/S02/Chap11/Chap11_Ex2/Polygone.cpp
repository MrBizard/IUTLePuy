#include "Polygone.h"
#include <assert.h>
#include <iostream>
using namespace std;

CPolygone::CPolygone(const CPoint& offset/*=CPoint{ 0, 0 }*/,
                     const CCouleur& coulTrait/* = CCouleur{ 0, 0, 0 }*/,
                     const CCouleur& coulRemplissage/* = CCouleur{ 255, 255, 255 }*/)
  : CObjetPlein{ offset, coulTrait, coulRemplissage }
{
  //cout << "Construction d'un polygone" << endl;
}

CPolygone& CPolygone::operator <<(const CPoint &p)
{
  m_vPoints.push_back(p);
  return *this;
}

void CPolygone::Afficher()
{
  CObjetPlein::Afficher();
  cout << "Je suis un polygone de " << m_vPoints.size() << " points : ";
  for (const CPoint& pt : m_vPoints)
    cout << pt << " ";
  cout << endl;
}

