#include "Donnee.h"
#include <fstream>

int CDonnee::EcrireDonnee(const std::string& strNomFichier)
{
  //Ouvre le fichier
  std::ofstream ofs(strNomFichier, std::ios_base::out | std::ios_base::trunc);
  //Teste si le fichier a été correctement ouvert
  if (ofs.fail())
  {
    std::cerr << "Erreur d'ouverture du fichier \"" << strNomFichier << "\" en écriture \n";
    return 1;
  }
  //Ecrit les données
  ofs << m_strSignature << '\n';
  ofs << m_nValeur;

  //Teste si l'écriture s'est bien déroulée
  if (ofs.fail())
  {
    std::cerr << "Erreur d'écriture dans le fichier \"" << strNomFichier << "\"\n";
    return 2;
  }
  return 0;
}

int CDonnee::LireDonnee(const std::string& strNomFichier)
{
  std::string strSignature;

  //Ouvre le fichier
  std::ifstream ifs(strNomFichier);
  //Teste si le fichier a été correctement ouvert
  if (ifs.fail())
  {
    std::cerr << "Erreur d'ouverture du fichier \"" << strNomFichier << "\" en lecture \n";
    return 1;
  }
  //Lit la première ligne
  std::getline(ifs, strSignature);

  //Vérifie la signature de la donnée
  if (strSignature == m_strSignature)
    ifs >> m_nValeur;//Lit la valeur
  else
  {
    std::cerr << "Le fichier \"" << strNomFichier << "\" n'est pas du bon format\n";
    return 2;
  }

  //Teste si la lecture s'est correctement déroulée
  if (ifs.fail())
  {
    std::cerr << "Erreur de lecture dans le fichier \"" << strNomFichier << "\"\n";
    return 3;
  }
  return 0;
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