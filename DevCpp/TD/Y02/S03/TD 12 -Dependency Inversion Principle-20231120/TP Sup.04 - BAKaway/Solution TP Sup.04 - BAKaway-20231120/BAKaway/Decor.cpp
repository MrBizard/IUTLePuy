#include "Decor.h"


//Solution
CDecor::CDecor(CPosition::const_ptr taille, CPosition::const_ptr objectif, CModeleGraphique::const_ptr modele)
  : m_pTaille(taille->clone())
  , m_pPosObjectif(objectif->clone())
  , m_modele(modele)
{
}
std::shared_ptr<CDecor> CDecor::create(CPosition::const_ptr taille, CPosition::const_ptr objectif, CModeleGraphique::const_ptr pModele)
{
    return std::shared_ptr<CDecor>(new CDecor(taille, objectif, pModele));
}
/*
//Fin Solution
CDecor::CDecor(CModeleGraphique::const_ptr modele)
  : m_modele(modele)
{
}
std::shared_ptr<CDecor> CDecor::create(CModeleGraphique::const_ptr pModele)
{
    return std::shared_ptr<CDecor>(new CDecor(pModele));
}
//Solution
*/
//Fin Solution