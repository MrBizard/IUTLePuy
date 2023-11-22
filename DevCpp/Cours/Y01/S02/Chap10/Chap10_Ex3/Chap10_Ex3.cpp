#ifdef WIN32
#include <Windows.h>
#endif // WIN32
#include <iostream>
#include <string>

class CSportif
{
public:
  void Jouer() {
    std::cout << "Je fais du sport ";
  }
};

class CBallon {};
class CFootballer : public CSportif
{
public:
  void Jouer(const CBallon& b) {
    CSportif::Jouer();
    std::cout << "avec un ballon !\n";
  }
};

class CRaquette {};
class CBalle {};
class CTennisWoman : public CSportif
{
public:
  void Jouer(const CRaquette& r, const CBalle& b) {
    CSportif::Jouer();
    std::cout << "avec une raquette et une balle !\n";
  }
};

int main(void)
{
#ifdef WIN32
  SetConsoleOutputCP(65001);
#endif // WIN32

  CFootballer MBappe;

  //MBappe.Jouer(); //Erreur C2660 - 'CFootballer::Jouer' : la fonction ne prend pas 0 arguments
  MBappe.Jouer(CBallon{});
  //Transtypage du CFootballer MBappe en CSportif pour accéder à la fonction Jouer() de la classe CSportif
  static_cast<CSportif>(MBappe).Jouer();
  std::cout << "et c'est cool !\n";

  std::cout << "\n\n";

  CTennisWoman Mauresmo;
  //Mauresmo.Jouer(); //Erreur C2660 - 'CTennisWoman::Jouer' : la fonction ne prend pas 0 arguments
  Mauresmo.Jouer(CRaquette{}, CBalle{});
  //Transtypage de la CTennisWoman Mauresmo en CSportif pour accéder à la fonction Jouer() de la classe CSportif
  static_cast<CSportif>(Mauresmo).Jouer();
  std::cout << "et c'est cool !\n";

  std::cout << "\n\n";

  return 0;
}

