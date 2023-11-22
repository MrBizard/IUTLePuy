#include <Windows.h>
#include "donnee.h"

#include <Menu.h>
#include <MenuElmtFunctor.h>

#include "MenuLireDonnee.h"
#include "MenuEcrireDonnee.h"

#include <iostream>


std::shared_ptr<CMenu> InitMenu(CDonnee& d)
{
  std::shared_ptr<CMenu> m = std::make_shared<CMenu>();
  auto ad = std::make_shared<CMenuElmtFunctor>('a', "Afficher la donnée", [&d]() { std::cout << "La valeur de la donnée est " << d << '\n'; });
  auto ed = std::make_shared<CMenuElmtFunctor>('e', "Etablir la donnée", [&d]() { std::cout << "Veuiller entrer la nouvelle valeur de la donnée : "; std::cin >> d; });
  auto rd = std::make_shared<CMenuLireDonnee>('r', "Lire la donnée", d);
  auto sd = std::make_shared<CMenuEcrireDonnee>('s', "Ecrire la donnée", d);
  *m << ad << ed << rd << sd;

  return m;
}

int main()
{
#ifdef WIN32
  SetConsoleOutputCP(65001);
#endif
  CDonnee MaDonnee;

  std::shared_ptr<CMenu> m = InitMenu(MaDonnee);
  m->MenuLoop();
}