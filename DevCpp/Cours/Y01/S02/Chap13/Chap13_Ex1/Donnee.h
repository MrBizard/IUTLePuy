#pragma once
#include <iostream>
#include <string>

class CDonnee
{
private:
  std::string m_strSignature;
  int m_nValeur;
public:
  CDonnee(void) : m_nValeur(0), m_strSignature("C'est une de mes données"){}

  //Récupère la valeur
  int GetValeur() const {return m_nValeur;}
  //Etalbit la valeur
  void SetValeur(int nValeur) {m_nValeur = nValeur;}

  //Lit une donnée depuis un fichier texte
  void LireDonnee(const std::string& strNomFichier);
  //Ecrit une donnée dans un fichier texte
  void EcrireDonnee(const std::string& strNomFichier);
};

std::ostream& operator<<(std::ostream& out, const CDonnee& d);
std::istream& operator>>(std::istream& in, CDonnee& d);
