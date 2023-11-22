#ifdef WIN32
#include <Windows.h>
#endif // WIN32
#include <iostream>
#include <string>

class CSpectacle
{
  std::string m_strDateRepresentation;
public:
  CSpectacle(const std::string& strDateRepresentation) 
    : m_strDateRepresentation{ strDateRepresentation }
  { 
    std::cout << "Création d'un spectacle pour le " << m_strDateRepresentation << "\n";
  }
};

class CConcert : public CSpectacle
{
  std::string m_strGroupe;
public:
  CConcert(const std::string& strDateRepresentation, const std::string& strGroupe)
    : CSpectacle{ strDateRepresentation }
    , m_strGroupe{ strGroupe }
  {
    std::cout << "Création d'un concert de " << m_strGroupe << "\n";
  }
};

class CPieceDeTheatre : public CSpectacle
{
  std::string m_strTitre;
  std::string m_strTroupe;
public:
  CPieceDeTheatre(const std::string& strDateRepresentation, const std::string& strTitre, const std::string& strTroupe)
    : CSpectacle{ strDateRepresentation }
    , m_strTitre{ strTitre }
    , m_strTroupe{ strTroupe }
  {
    std::cout << "Création de la pièce de théâtre " << m_strTitre << " par " << m_strTroupe<<"\n";
  }
};

int main(void)
{
#ifdef WIN32
  SetConsoleOutputCP(65001);
#endif // WIN32

  CConcert concert{ "17/02/2027", "Tonton David" };
  std::cout << "\n";
  CPieceDeTheatre piece{ "28/02/2034", "Cas de Farce Majeure", "Les Tréteaux de Peynastre" };
  return 0;
}

