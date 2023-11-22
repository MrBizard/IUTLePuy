#include "Donnee.h"
#include "ErreurDonnee.h"
#include <fstream>

void CDonnee::EcrireDonnee(const std::string& strNomFichier)
{
  //Ouvre le fichier
  std::ofstream ofs(strNomFichier, std::ios_base::out | std::ios_base::trunc);
  //Teste si le fichier a �t� correctement ouvert
  if (ofs.fail())
    throw CErreurEcritureDonnee(1, strNomFichier);
  //Ecrit les donn�es
  ofs << m_strSignature << '\n';
  ofs << m_nValeur;

  //Teste si l'�criture s'est bien d�roul�e
  if (ofs.fail())
    throw CErreurEcritureDonnee(2, strNomFichier);

}

void CDonnee::LireDonnee(const std::string& strNomFichier)
{
  std::string strSignature;

  //Ouvre le fichier
  std::ifstream ifs(strNomFichier);
  //Teste si le fichier a �t� correctement ouvert
  if (ifs.fail())
  {
    throw CErreurLectureDonnee(1, strNomFichier);
  }
  //Lit la premi�re ligne
  std::getline(ifs, strSignature);

  //V�rifie la signature de la donn�e
  if (strSignature == m_strSignature)
    ifs >> m_nValeur;//Lit la valeur
  else
  {
    throw CErreurLectureDonnee(2, strNomFichier);
  }

  //Teste si la lecture s'est correctement d�roul�e
  if (ifs.fail())
    throw CErreurLectureDonnee(3, strNomFichier);
}

std::ostream& operator<<(std::ostream& out, const CDonnee& d)
{
  return out << d.GetValeur();
}

std::istream& operator>>(std::istream& in, CDonnee& d)
{
  int nValeur;
  in >> nValeur;
  d.SetValeur(nValeur);
  return in;
}