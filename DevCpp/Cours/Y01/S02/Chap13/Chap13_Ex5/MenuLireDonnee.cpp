#include "MenuLireDonnee.h"
#include "ErreurDonnee.h"

void CMenuLireDonnee::operator ()()
{
  bool bError = true;
  while (bError)
  {
    try
    {
      //Demande le nom de fichier � l'utilisateur via la classe m�re
      CMenuFichierDonnee::operator ()();
      //A ce niveau, le nom du fichier est dans la donn�e membre m_strNomFichier
      m_Donnee.LireDonnee(m_strNomFichier);
      bError = false;
    }
    catch (CErreurFichierDonnee& e)
    {
      e.AfficherQuoiFaire();
    }
  }
}