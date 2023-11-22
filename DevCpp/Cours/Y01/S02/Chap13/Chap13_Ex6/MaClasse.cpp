#include "MaClasse.h"

//Initialisation du membre statique
size_t CMaClasse::s_nNbInstances = 0;

CMaClasse::CMaClasse()
{
  ++s_nNbInstances;
}

CMaClasse::~CMaClasse()
{
  --s_nNbInstances;
}

size_t CMaClasse::GetNbInstances()
{
  return s_nNbInstances;
}
