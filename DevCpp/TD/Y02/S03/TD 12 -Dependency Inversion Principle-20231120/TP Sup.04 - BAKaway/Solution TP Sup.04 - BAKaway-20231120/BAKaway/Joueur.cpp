#include "Joueur.h"

//Solution
CJoueur::CJoueur(CPosition::const_ptr pos, CModeleGraphique::const_ptr modele, int nVie)
  : CPersonnage(pos, modele)
  , m_nVie(nVie)
{
}
/*
//Fin Solution
CJoueur::CJoueur(CModeleGraphique::const_ptr modele, int nVie)
  : CPersonnage(modele)
  , m_nVie(nVie)
{
}
//Solution
*/
//Fin Solution