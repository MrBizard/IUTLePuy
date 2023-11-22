#include "vecteur2D.h"
#include "carre.h"

#include <iostream>
#include "test.h"

#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32

int main(void)
{
#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
#endif // _WIN32

  CVecteur2D v1{ 1, 2 };  //Vecteur (1, 2)
  CVecteur2D v2{ 3, 4 };  //Vecteur (3, 4)
  CVecteur2D v3{ 5, 6 };  //Vecteur (5, 6)

  //Utilisation de l'opérateur = par défaut et de l'opérateur binaire +
  v1 = v2 + v3;
  //Utilisation de l'opérateur += 
  v2 += v3;
  //Utilisation de l'opérateur *= 
  v3 *= 2;

  //Utilisation de l'opérateur << entre des objets ostream et CVecteur2D
  std::cout << "v1 = " << v1 << '\n';
  std::cout << "v2 = " << v2 << '\n';
  std::cout << "v3 = " << v3 << '\n';

  CCarre carre{ CPoint2D{}, CVecteur2D{ 0, 1 } };
  for (size_t i = 0; i < 4; ++i)
    std::cout << "Coin " << i << " = " << carre[i] << '\n';


  BEGIN_TESTS
    NOTICE("Début des tests")

    TEST("v1 == v2 ?", v1 == v2, true)
    TEST("v1 != v3 ?", v1 != v3, true)
    TEST("v1 < v3 ?", v1 < v3, true)
    TEST("v1 <= v3 ?", v1 <= v3, true)
    TEST("v1 <= v2 ?", v1 <= v2, true)
    TEST("v3 > v1 ?", v3 > v1, true)
    TEST("v3 >= v1 ?", v3 >= v1, true)
    TEST("v2 >= v1 ?", v2 >= v1, true)

  END_TESTS

  return 0;
}

