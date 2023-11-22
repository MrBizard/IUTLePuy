#include "Personnage.h"

//Solution
CPersonnage::CPersonnage(CPosition::const_ptr pos, CModeleGraphique::const_ptr modele)
  : m_pPos(pos->clone())
  , m_modeleGraphique(modele)
{
}

void CPersonnage::deplacer(CPosition::const_ptr dir, double dDist)
{
  m_pPos->deplacer(dir, dDist);
}

/*
//Fin Solution
CPersonnage::CPersonnage(CModeleGraphique::const_ptr modele)
  : m_modeleGraphique(modele)
{
}
//Solution
*/
//Fin Solution