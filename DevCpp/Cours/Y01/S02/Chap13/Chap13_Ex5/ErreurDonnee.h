#pragma once
#include <string>

class CErreurFichierDonnee
{
protected:
  int m_nCause;
  std::string m_strNomFichier;
public:
  CErreurFichierDonnee(int nCause, const std::string& strNomFichier) : m_nCause(nCause), m_strNomFichier( strNomFichier ){}
  int GetCause() const {return m_nCause;}
  virtual void AfficherQuoiFaire()=0;
};

class CErreurLectureDonnee
  : public CErreurFichierDonnee
{
public:
  CErreurLectureDonnee(int nCause, const std::string& strNomFichier) : CErreurFichierDonnee(nCause, strNomFichier){}
  virtual void AfficherQuoiFaire();
};

class CErreurEcritureDonnee
  : public CErreurFichierDonnee
{
public:
  CErreurEcritureDonnee(int nCause, const std::string& strNomFichier) : CErreurFichierDonnee(nCause, strNomFichier){}
  virtual void AfficherQuoiFaire();
};
