#include "ObjetGraphique.h"
#include <iostream>

//Version 1 : Création sans utilisation de la liste d'innitialisation du constructeur
//CObjetGraphique::CObjetGraphique(const CPoint &pos/* = CPoint{0,0}*/,
//                                 const CCouleur &coul/* = CCouleur{0,0,0}*/)
//{
//  std::cout << "Construction d'un objet graphique\n";
//  m_position = pos;
//  m_couleur = coul;
//}

//Version 2 : Création avec utilisation de la liste d'innitialisation du constructeur
CObjetGraphique::CObjetGraphique(const CPoint& pos/* = CPoint{0,0}*/,
                                 const CCouleur& coul/* = CCouleur{0,0,0}*/)
  : m_position{ pos }
  , m_couleur{ coul }
{
  std::cout << "Construction d'un objet graphique\n";
}

void CObjetGraphique::BougeVers(const CPoint& pos)
{
  m_position = pos;
}
void CObjetGraphique::ChangeCouleur(const CCouleur& coul)
{
  m_couleur = coul;
}

std::ostream& operator<<(std::ostream& out, const CObjetGraphique& obj)
{
  out << "Je suis un objet graphique de couleur "
    << obj.getCoul() << " à la position "
    << obj.getPos() << ".\n";
  return out;
}
