#include "MonstreGluant.h"
#include <cassert>
using namespace std;

void CMonstreGluant::attaquer(CJoueur::ptr joueur) const
{
  joueur->diminuerVie(1);
}
