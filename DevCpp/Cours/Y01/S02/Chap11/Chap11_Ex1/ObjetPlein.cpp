#include "ObjetPlein.h"
#include <iostream>
using namespace std;

CObjetPlein::CObjetPlein(const CPoint &pos/* = CPoint{ 0, 0 }*/,
                         const CCouleur &coulTrait/* = CCouleur{ 0, 0, 0 }*/,
                         const CCouleur &coulRemplissage/* = CCouleur{ 255, 255, 255 }*/)
  : CObjetGraphique{ pos, coulTrait }
  , m_coulRemplis{ coulRemplissage }
{
  //cout << "Construction d'un objet plein" << endl;
}

void CObjetPlein::Afficher()
{
  CObjetGraphique::Afficher();
  cout << "Je suis un objet plein de couleur " << m_couleur << endl;
}
