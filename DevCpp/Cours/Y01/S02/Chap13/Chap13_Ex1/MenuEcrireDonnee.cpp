#include "MenuEcrireDonnee.h"

void CMenuEcrireDonnee::operator ()()
{
  //Demande le nom de fichier � l'utilisateur via la classe m�re
  CMenuFichierDonnee::operator ()();
  //A ce niveau, le nom du fichier est dans la donn�e membre m_strNomFichier
  m_Donnee.EcrireDonnee(m_strNomFichier);
}