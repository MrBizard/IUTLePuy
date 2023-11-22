#include "MenuFichierDonnee.h"

CMenuFichierDonnee::CMenuFichierDonnee(char c, const std::string& texte, CDonnee& d)
  : CMenuElmt(c, texte)
  , m_Donnee(d)
{
}

void CMenuFichierDonnee::operator ()()
{
  std::string strNomFichier;
  std::cout << "Veuiller entrer le nom du fichier (par défaut : " << m_strNomFichier << ") : ";
  std::cin.sync();
  std::getline(std::cin, strNomFichier);
  if (!strNomFichier.empty())
  {
    m_strNomFichier = strNomFichier;
  }
}