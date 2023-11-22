#include "Cercle.h"
#include <iostream>
using namespace std;

CCercle::CCercle(const CPoint &centre/* = CPoint{ 0, 0 }*/,
                 unsigned int rayon/* = 1*/,
                 const CCouleur &coulTrait/* = CCouleur{ 0, 0, 0 }*/,
                 const CCouleur &coulRemplissage/* = CCouleur{ 255, 255, 255 }*/)
  : CObjetPlein{ centre, coulTrait, coulRemplissage }
  , m_unRayon{ rayon }
{
  //cout<<"Construction d'un cercle"<<endl;
}

void CCercle::Afficher()
{
  CObjetPlein::Afficher();
  cout << "Je suis un cercle de rayon " << m_unRayon << endl;
}
