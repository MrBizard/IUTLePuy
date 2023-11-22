// RepriseEnMainCPP.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#define NOMINMAX
#include <Windows.h>
#include <iostream>
#include "directory.h"
#include "person.h"
#include "date.h"
#include "test.h"
#include <sstream>

int menu()
{
  std::cout <<
    R"menu(
==================================================
              Menu de l'application
==================================================
0 : Quitter
1 : Afficher le répertoire
2 : Ajouter une personne
3 : Supprimer une personne précise
4 : Rechercher des personnes par nom et prénom
5 : Rechercher des personnes par date de naissance
==================================================
Entrez votre choix : )menu";
  int choix;
  std::cin >> choix;
  std::cin.ignore();
  return choix;
}

CPerson getPersonFromStdIn()
{
  std::string strLastName, strFirstName;
  CDate birthday;
  std::cout << "Entrez le nom de la personne : ";
  std::getline(std::cin, strLastName);
  std::cout << "Entrez le prénom de la personne : ";
  std::getline(std::cin, strFirstName);
  std::cout << "Entrez sa date de naissance au format j/mm/aaaa : ";
  std::cin >> birthday;
  return { strLastName, strFirstName, birthday };
}

int main()
{
  SetConsoleOutputCP(65001);
  BEGIN_TESTS;
  NOTICE("Quick tests for CDate");

  TEST_EXCEPTION("Incorrect date #1 00/00/0000", CDate(0, 0, 0), std::range_error&);
  TEST_EXCEPTION("Incorrect date #2 29/02/1900", CDate(29, 2, 1900), std::range_error&);
  TEST_EXCEPTION("Incorrect date #3 29/02/1999", CDate(29, 2, 1999), std::range_error&);

  CDate _5fev2001(5, 2, 2001);
  std::ostringstream ostr;
  ostr << _5fev2001;
  TEST("Teste la sortie vers flux d'un objet CDate", ostr.str(), "5/02/2001");

  CDate date(1, 1, 1);
  std::istringstream istr("5/02/2001");
  istr >> date;
  TEST("Teste l'entrée depuis un flux d'un objet CDate", date, _5fev2001);

  CDate _5fev2001_2(5, 2, 2001);
  CDate _4fev2001(4, 2, 2001);
  CDate _5jan2001(5, 1, 2001);
  CDate _5fev2000(5, 2, 2000);
  TEST("Teste l'opérateur ==", _5fev2001 == _5fev2001_2, true);
  TEST("Teste l'opérateur ==", _4fev2001 == _5fev2001_2, false);
  TEST("Teste l'opérateur !=", _5fev2001 != _5fev2001_2, false);
  TEST("Teste l'opérateur !=", _4fev2001 != _5fev2001_2, true);

  TEST("Teste l'opérateur <", _5fev2001 < _5fev2001_2, false);
  TEST("Teste l'opérateur <", _4fev2001 < _5fev2001, true);
  TEST("Teste l'opérateur <", _5jan2001 < _5fev2001, true);
  TEST("Teste l'opérateur <", _5fev2000 < _5fev2001, true);

  TEST("Teste l'opérateur >", _5fev2001_2 > _5fev2001, false);
  TEST("Teste l'opérateur >", _5fev2001 > _4fev2001, true);
  TEST("Teste l'opérateur >", _5fev2001 > _5jan2001, true);
  TEST("Teste l'opérateur >", _5fev2001 > _5fev2000, true);

  TEST("Teste l'opérateur <=", _5fev2001 <= _5fev2001_2, true);
  TEST("Teste l'opérateur <=", _4fev2001 <= _5fev2001, true);
  TEST("Teste l'opérateur <=", _5jan2001 <= _5fev2001, true);
  TEST("Teste l'opérateur <=", _5fev2000 <= _5fev2001, true);

  TEST("Teste l'opérateur >=", _5fev2001_2 >= _5fev2001, true);
  TEST("Teste l'opérateur >=", _5fev2001 >= _4fev2001, true);
  TEST("Teste l'opérateur >=", _5fev2001 >= _5jan2001, true);
  TEST("Teste l'opérateur >=", _5fev2001 >= _5fev2000, true);

  TEST("Test l'opérateur \"\"_date", "5/02/2001"_date, _5fev2001);


  NOTICE("Quick tests for CPerson");

  CPerson bak("ALBOUY-KISSI", "Benjamin", "28/05/1980"_date);
  CPerson aak("ALBOUY-KISSI", "Adélaïde", "29/05/1980"_date);
  CPerson ba("ALBOUY", "Benjamin", "28/05/1980"_date);
  CPerson aa("ALBOUY", "Adélaïde", "29/05/1980"_date);
  CPerson bk("KISSI", "Benjamin", "28/05/1980"_date);
  CPerson ak("KISSI", "Adélaïde", "29/05/1980"_date);

  TEST("Teste l'opérateur <", aak < bak, true);
  TEST("Teste l'opérateur <", bak < aak, false);
  TEST("Teste l'opérateur <", bak < bak, false);
  TEST("Teste l'opérateur <", ba < bak, true);
  TEST("Teste l'opérateur <", ba < ak, true);

  TEST("Teste l'opérateur >", aak > bak, false);
  TEST("Teste l'opérateur >", bak > aak, true);
  TEST("Teste l'opérateur >", bak > bak, false);
  TEST("Teste l'opérateur >", ba > bak, false);
  TEST("Teste l'opérateur >", ba > ak, false);

  TEST("Teste l'opérateur <=", aak <= bak, true);
  TEST("Teste l'opérateur <=", bak <= aak, false);
  TEST("Teste l'opérateur <=", bak <= bak, true);
  TEST("Teste l'opérateur <=", ba <= bak, true);
  TEST("Teste l'opérateur <=", ba <= ak, true);

  TEST("Teste l'opérateur >=", aak >= bak, false);
  TEST("Teste l'opérateur >=", bak >= aak, true);
  TEST("Teste l'opérateur >=", bak >= bak, true);
  TEST("Teste l'opérateur >=", ba >= bak, false);
  TEST("Teste l'opérateur >=", ba >= ak, false);

  END_TESTS;

  std::cout << "Appuyez sur Entrée pour passer à la suite.\n";
  std::string strTemp;
  std::getline(std::cin, strTemp);

  CDirectory dir;
  int choix;
  while ((choix = menu()) != 0)
  {
    switch (choix)
    {
    case 1: // Afficher le répertoire
      std::cout << dir;
      break;
    case 2: // Ajouter une personne
      dir.addPerson(getPersonFromStdIn());
      break;
    case 3: // Supprimer une personne précise
      dir.removePerson(getPersonFromStdIn());
      break;
    case 4: // Rechercher des personnes par nom et prénom
    {
      std::string partFirstName;
      std::string partLastName;
      std::cout << "Entrez une partie du nom de la personne : ";
      std::getline(std::cin, partLastName);
      std::cout << "Entrez une partie du prénom de la personne : ";
      std::getline(std::cin, partFirstName);
      std::set<CPerson> subSet = dir.getPersons(std::regex(".*" + partLastName + ".*"), std::regex(".*" + partFirstName + ".*"));
      std::cout << "Voici la liste des personnes trouvées : \n" << subSet << "Fin de la liste !\n";
      break;
    }
    case 5: // Rechercher des personnes par date de naissance
    {
      CDate dateMin;
      CDate dateMax;
      std::cout << "Entrez la date inférieur de la recherche au format j/mm/aaaa : ";
      std::cin >> dateMin;
      std::cout << "Entrez la date supérieure de la recherche au format j/mm/aaaa : ";
      std::cin >> dateMax;
      std::set<CPerson> subSet = dir.getPersons(dateMin, dateMax);
      std::cout << "Voici la liste des personnes trouvées : \n" << subSet << "Fin de la liste !\n";
      break;
    }
    default:
      break;
    }
  }

  return 0;
}

