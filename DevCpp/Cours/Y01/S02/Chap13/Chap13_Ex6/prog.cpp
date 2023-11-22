#include <Windows.h>
#include <conio.h>
#include "MaClasse.h"
#include "MonMenu.h"
#include <MenuElmtFunctor.h>
#include <iostream>
#include <list>
#include <memory>


//Programme principal
void main()
{
#ifdef WIN32
  SetConsoleOutputCP(CP_UTF8);
#endif
  //Exemple play school
  std::cout << "{\n";
  {
    std::cout << "  cout << CMaClasse::GetNbInstances() << \"\\n\"; --> ";
    std::cout << CMaClasse::GetNbInstances() << "\n";
    waitchar();
    std::cout << "  CMaClasse A;\n";
    CMaClasse A;
    std::cout << "  cout << CMaClasse::GetNbInstances() << \"\\n\"; --> ";
    std::cout << CMaClasse::GetNbInstances() << "\n";
    waitchar();
    std::cout << "  {\n";
    {
      std::cout << "    cout << CMaClasse::GetNbInstances() << \"\\n\"; --> ";
      std::cout << CMaClasse::GetNbInstances() << "\n";
      waitchar();
      std::cout << "    CMaClasse B;\n";
      CMaClasse B;
      std::cout << "    cout << CMaClasse::GetNbInstances() << \"\\n\"; --> ";
      std::cout << CMaClasse::GetNbInstances() << "\n";
      waitchar();
      std::cout << "  }\n";
    }
    std::cout << "  cout << CMaClasse::GetNbInstances() << \"\\n\"; --> ";
    std::cout << CMaClasse::GetNbInstances() << "\n";
    waitchar();
    std::cout << "}\n";
  }

  std::cout << "Appuyez sur une touche pour passer à l'exemple suivant...\n";
  waitchar();

  //Exemple play school 2 :
  std::list<std::shared_ptr<CMaClasse>> sacDInstances;

  CMonMenu monmenu("Exemple de compteur d'instances");
  monmenu << std::make_shared<CMenuElmtFunctor>(
    'a', "Ajouter une instance", [&sacDInstances]() {
      sacDInstances.push_back(std::make_shared<CMaClasse>());
    });
  monmenu << std::make_shared<CMenuElmtFunctor>(
    's', "Supprimer une instance", [&sacDInstances]() {
      bool bFound = false;
      for (auto it = sacDInstances.begin(); !bFound && it != sacDInstances.end(); it++)
        if (*it != nullptr)
        {
          *it = nullptr;
          bFound = true;
        }
    });
  monmenu.MenuLoop();
}