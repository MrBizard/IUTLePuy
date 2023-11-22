#include <Windows.h>
#include "inc_libgraph2.h"
#include "vecteur2D.h"
#include "carre.h"
#include <iostream>

int main(void)
{
  CVecteur2D v1;          //Vecteur constructeur par d�faut (0, 0)
  CVecteur2D v2{ 1 };     //Vecteur constructeur avec 1 param�tre (1, 0)
  CVecteur2D v3{ 2, 3 };  //Vecteur constructeur avec 2 param�tres (2, 3)

  v1.AffichageDetail("v1");
  v2.AffichageDetail("v2");
  v3.AffichageDetail("v3");

  return 0;
}

