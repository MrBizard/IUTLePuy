#ifdef WIN32
#include <Windows.h>
#endif // WIN32
#include <iostream>
#include <string>

class CSpectacle
{
  std::string m_strDateRepresentation;
public:
  CSpectacle() { 
    m_strDateRepresentation = "17/02/2027";
    std::cout << "Création d'un spectacle pour le " << m_strDateRepresentation << "\n";
  }
};

class CConcert : public CSpectacle
{
  std::string m_strGroupe;
public:
  CConcert() {
    m_strGroupe = "Tonton David";
    std::cout << "Création d'un concert de " << m_strGroupe << "\n";
  }
};

class CPieceDeTheatre : public CSpectacle
{
  std::string m_strTitre;
  std::string m_strTroupe;
public:
  CPieceDeTheatre() {
    m_strTitre = "Cas de Farce Majeure";
    m_strTroupe = "Les Tréteaux de Peynastre";
    std::cout << "Création de la pièce de théâtre " << m_strTitre << " par " << m_strTroupe<<"\n";
  }
};

int main(void)
{
#ifdef WIN32
  SetConsoleOutputCP(65001);
#endif // WIN32

  CConcert concert;
  std::cout << "\n";
  CPieceDeTheatre piece;
  return 0;
}

