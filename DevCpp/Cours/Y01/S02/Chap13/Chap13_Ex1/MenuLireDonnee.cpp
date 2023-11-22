#include "MenuLireDonnee.h"

void CMenuLireDonnee::operator ()()
{
  //Demande le nom de fichier à l'utilisateur via la classe mère
  CMenuFichierDonnee::operator ()();
  //A ce niveau, le nom du fichier est dans la donnée membre m_strNomFichier
  m_Donnee.LireDonnee(m_strNomFichier);
}