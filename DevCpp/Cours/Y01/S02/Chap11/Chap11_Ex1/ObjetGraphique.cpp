#include "ObjetGraphique.h"
#include <iostream>
using namespace std;

CObjetGraphique::CObjetGraphique(const CPoint &pos/* = CPoint{ 0, 0 }*/,
                                 const CCouleur &coul/* = CCouleur{ 0, 0, 0 }*/)
  : m_position{ pos }
  , m_couleur{ coul }
{
  //cout << "Construction d'un objet graphique" << endl;
}

void CObjetGraphique::BougeVers(const CPoint& pos)
{
  m_position = pos;
}
void CObjetGraphique::ChangeCouleur(const CCouleur& coul)
{
  m_couleur = coul;
}

void CObjetGraphique::Afficher()
{
  cout << "Je suis un objet graphique de couleur "
    << m_couleur << " … la position "
    << m_position << "." << endl;
}
